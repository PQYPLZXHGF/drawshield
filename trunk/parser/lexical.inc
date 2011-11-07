<?php /* Copyright 2010 Karl R. Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

$matched_number = null;
$matched_word = null;

//
// LEXICAL FUNCTIONS
//

// Fill the words array with words from the blazon
// Punctuation and spaces ignored
function fill_words($blazon_in) {
  global $words;
  $ignore_words = array ( 'also',  );
  $blazon = iconv("UTF-8", "ASCII//TRANSLIT", $blazon_in);

  $i = 0;
  $comment = false;
  $this_word = '';
  $end = strlen($blazon);
  while ( $i < $end ) {
    switch ( $blazon[$i] ) {
      case ' ':
      case "\t":
      case "\n":
      case "\r":
      case '"':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        } // else ignore it
        break;
      case '{':
      case '(':
      case '[':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        }
        $comment = true;
        break;
      case ')':
      case '}':
      case ']':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        }
        $comment = false;
        break;
      case '#':
      case '/':
      case ':':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        }
        $i = $end;
        break;
      case '-':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        }
        if ( $i > 0 and strstr(  " \t\n\r'\",.", $blazon[$i-1])) {
          $i = $end;
        }
        if ( $i < $end and $blazon[$i+1] == '-' ) {
          $i = $end;
        }
        break;
      case ';':
      case ',':
      case '.':
        if ( $this_word != '' ) {
          if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
          $this_word = '';
        }
        if ( !$comment) $words[] = $blazon[$i];
        break;
      case "'":
      case '\\':
      case '`':
      case '~':
      case '^':
        break;
      default:
        $this_word .= $blazon[$i];
    }
    $i++;
  }
  if ( $this_word != '' ) {
    if ( !$comment and !in_array($this_word, $ignore_words)) { $words[] = $this_word; }
  }
}

function match_number ( &$count, $t_word ) {
  global $p_globals;
  global $words, $cur_word;

  $numbers = array (
  array (0, '(0|zero)' ) ,// just for completeness...
  array (1, '(1|one)' ),
  array (2, '(2|two)' ),
  array (3, '(3|three)' ),
  array (4, '(4|four)' ),
  array (5, '(5|five)' ),
  array (6, '(6|six)'  ),
  array (7, '(7|seven)' ),
  array (8, '(8|eight)' ),
  array (9, '(9|nine)' ),
  array (10, '(10|ten)' ),
  array (11, '(11|eleven)' ),
  array (12, '(12|twelve)' ),
  array (13, '(13|thirteen)' ),
  array (14, '(14|fourteen)' ),
  array (15, '(15|fifteen)' ),
  array (16, '(16|sixteen)' ),
  array (17, '(17|seventeen)' ),
  array (18, '(18|eighteen)' ),
  array (19, '(19|nineteen)' ),
  array (20, '(20|twenty)' ),
  );
  $number = null;
  if ( preg_match ( '/^(as|so)$/i',  $words[$t_word] ) and ($tword+1 < sizeof($words)) and preg_match ( '/^many$/i',  $words[$t_word+1] ) ) {
    $count = 2;
    if ($p_globals['asmany'] == null ) {
      parser_message('blazon', 'No previous number');
      $number = 2;
    } else {
      $number = $p_globals['asmany'];
    }
  } else {
    foreach ( $numbers as $number_word ) {
      if (preg_match ( '/^' . $number_word[1] . '$/i',  $words[$t_word] )) {
        $number = $number_word[0];
        $p_globals['asmany'] = $number;
        break;
      }
    }
  }
  return $number;
}

function check_match ( $match_string ) {

  if ( !$match_string ) {
    parser_message('internal','null match string');
    return false;
  }
  $phrases = explode('/', $match_string);
  foreach ( $phrases as $phrase ) {
    if ( ($retval = check_match2($phrase)) != 0 ) break;
  }
  return ( $retval );
}

// Try to match each of the regular expressions in the array
// with words in the input. Return 0 on fail, number of input
// words matched on success
// An initial '?' indicates match is optional
function check_match2 ( $match_string ) {
  global $words, $cur_word, $matched_number, $matched_word;

  $regexs = explode(' ', $match_string);
  $matched_number = null;
  $matched_word = null;

  $t_word = $cur_word;
  foreach ( $regexs as $regex ) {
    if ( $regex == '' ) continue;
    // Check for optionality
    $optional = false;
    if ( $regex{0} == '?' ) {
      $optional = true;
      $regex = substr($regex, 1);
    }
    if ( $t_word >= sizeof(($words) ) ) { // no more input
      if ( $optional ) {
        continue;
      } else {
        return 0;
      }
    }
    $number = null;
    $count = 1;
    if ( $regex == '*' ) {
      $matched_word = $words[$t_word];
      $t_word += 1;
    // Note search is case insensitive
    } elseif ( ( $regex == '#' and (($number = match_number( $count, $t_word )) != null) ) or ($res = preg_match ( '/^' . $regex . '$/i',  $words[$t_word] ))) {
      $t_word += $count; // Got a match, move on
      if ( $number ) $matched_number = $number;
    } elseif ( ! ($optional)) {
      if ( $res === false ) parser_message( 'internal', 'Bad regex - ' . $regex );
      return 0;
    }
  }
  // should only get here on a full match
  return $t_word;
}


function search_match ( $terms ) {
  global $words, $cur_word, $matched_number, $matched_word, $matched_tokens;

  $first_token = $cur_word;
  $max_match = 0;
  $match = null;
  $max_number = null;
  $max_word = null;
  foreach ($terms as $term) {
     if ( !is_array($term) or count($term) < 2 ) {
       parser_message ( 'internal', 'Bad search term ' . $term[0] );
       return null;
     }
     if ( ( $count = check_match($term[1])) ) {
       if ( $count > $max_match ) {
         $max_match = $count;
         $match = $term;
         $max_number = $matched_number;
         $max_word = $matched_word;
       }
    }
  }
  if ( $match != null ) {
    $cur_word = $max_match;
    if ( $max_number != null ) $match[0] = $max_number;
    if ( $max_word != null ) $match[0] = $max_word;
    $num_tokens = $cur_word - $first_token;
    $matched_tokens = implode(' ', array_slice($words, $first_token, $num_tokens));
  }
  return $match;
}
?>
