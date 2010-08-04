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


//
// LEXICAL FUNCTIONS
//

// Fill the words array with words from the blazon
// Punctuation and spaces ignored
function fill_words($blazon_in) {
  global $words;
  $ignore_words = array ( 'also',  );
  $blazon = iconv("UTF-8", "ASCII//TRANSLIT", $blazon_in);
  // raise_error('hello ' . $blazon);

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
      case '.':
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

function check_match ( $match_string ) {

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
	global $words, $cur_word;
	
  $regexs = explode(' ', $match_string);

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
    } // Note search is case insensitive
    if ( ($res = preg_match ( '/^' . $regex . '$/i',  $words[$t_word] ))) {
      $t_word += 1; // Got a match, move on
    } elseif ( ! ($optional)) {
      if ( $res === false ) raise_error('(INTERNAL) bad regex - ' . $regex );
      return 0;
    }
  }
  // should only get here on a full match
  return $t_word;
}


function search_match ( $terms ) {
  global $cur_word;

  $max_match = 0;
  $match = null;
  foreach ($terms as $term) {
     if ( !is_array($term) or count($term) < 2 ) {
       raise_error ( 'AARRGH! ' . $term[0] );
       return null;
     }
     if ( ( $count = check_match($term[1])) ) {
       if ( $count > $max_match ) {
         $max_match = $count;
         $match = $term;
       }
    }
  }
  if ( $match != null ) {
    $cur_word = $max_match;
  }
  return $match;
}
?>
