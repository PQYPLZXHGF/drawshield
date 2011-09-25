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

/*
function arr_pos(&$mods) {

  // Look for a specific position or arrangement.
  // If NOT found, return false
  // If found, return a default number of charges

  $arr_pos = array (
    array ( 'inpale',        'pale' , 'arrangement'                  ),
    array ( 'inpalethrough', 'pale throughout' , 'arrangement'        ),
    array ( 'inpall',        'pall' , 'arrangement'                   ),
    array ( 'infess',        'fesse?' , 'arrangement'                   ),
    array ( 'infessthrough', 'fesse? throughout' , 'arrangement'        ),
    array ( 'inbendsin',     'bend sinister' , 'arrangement'),
    array ( 'inbend',        'bend ?dexter' , 'arrangement'),
    array ( 'inchevron',     'chevron', 'arrangement' ),
    array ( 'inpile',        'pile' , 'arrangement'),
    array ( 'inorle',        'orle' , 'arrangement', 12 ),
    array ( 'inorle',        'an orle' , 'arrangement', 12 ),
    array ( 'insaltire',     'saltire' , 'arrangement'),
    array ( 'incross',       'cross' , 'arrangement', 5),
    array ( 'counter-passant', 'counter passant' , 'arrangement', 4),
    array ( 'pilewise',      'pilewise', 'arrangement', 3),
    array ( 'inbar',         '(bar|barwise)',  'arrangement'),
    array ( 'inflank',       '(flanks?|flaunche?s?)', 'both'  ),
    array ( 'inchief',       'chief' , 'both'  ),
    array ( 'inchiefthrough','chief throughout' , 'both'  ),
    array ( 'inbase',        'base' , 'both' ),
    array ( 'indexside',     'dexter side' , 'position', 1 ),
    array ( 'insinside',     'sinister side' , 'position', 1  ),
    array ( 'indexchief',    'dexter chief' , 'position', 1  ),
    array ( 'insinchief',    'sinister chief' , 'position', 1  ),
    array ( 'inmidchief',    'middle chief' , 'position', 1  ),
    array ( 'inhonpoint',    'honour point' , 'position', 1  ),
    array ( 'infesspoint',   'fesse? point' , 'position', 1  ),
    array ( 'indexbase',     'dexter base' , 'position', 1  ),
    array ( 'insinbase',     'sinister base' , 'position', 1  ),
    array ( 'inmidbase',     'middle base' , 'position', 1  ),
    array ( 'innombril',     'nombril' , 'position', 1  ),
    array ( 'innombril',     'navel point' , 'position', 1  ),
    array ( 'quadrangle',    'quadrangle', 'arrangement', 4 ),
  );
  $in_words = array (
    array ( true, 'in'),
  );
  $the_words = array (
    array ( true, 'the'),
  );

  $retval = 3; // default assumed number, if we find a match

  $state = save();
  search_match($in_words);
  search_match($the_words);

  if ( ($match = search_match($arr_pos)) != null ) {
    if ( $match[2] == 'both' ) {
      $mods[] = make_mod ( 'arrangement', $match[0] );
      $mods[] = make_mod ( 'position', $match[0] );
    } else {
      $mods[] = make_mod ( $match[2], $match[0] );
    }
    if ( isset ( $match[3] )) $retval = $match[3];
    while ( true ) {
      $state = save();
      if ( semicolon() ) break;
      andd();
      search_match($in_words);
      search_match($the_words);
      if ( ($match = search_match($arr_pos)) != null ) {
        if ( $match[2] == 'both' ) {
          $mods[] = make_mod ( 'arrangement', $match[0] );
          $mods[] = make_mod ( 'position', $match[0] );
        } else {
          $mods[] = make_mod ( $match[2], $match[0] );
        }
        if ( isset ( $match[3] )) $retval = $match[3];
      } else {
        restore($state);
        break;
      }
    }
    return $retval;
  }
  restore($state);
  return false;
} */

function inquarter(&$mods) {

  $in_word = array (
    array ( true, 'in', ),
  );

  $quarters = array (
    array ( 'inquarter1',    '(first|1st|i)', ),
    array ( 'inquarter2',    '(second|2nd|ii)', ),
    array ( 'inquarter3',    '(third|3rd|iii)', ),
    array ( 'inquarter4',    '(fourth|4th|iv)', ),
    );

  $state = save();
  $found = false;
  if ( search_match($in_word) ) {
    while ( ($match = search_match($quarters)) != null ) {
      $found = true;
      $mods[] = make_mod( 'position', $match[0] );
      andd();
    }
    if (!$found) restore($state);
  }
  return $found;
}

/*
function postfix(&$mods) {
  $postfix_words = array (
    array ( 'inverted', 'inverted' ),
    array ( 'reversed', 'reversed' ),
    array ( 'entire', '(entire|firme)' ),
    array ( 'ensoleil', 'en soleil'),
  );
  if ( ($match = search_match($postfix_words)) != null ) {
    $mods[] = make_mod($match[0]);
  }
  return ($match != null);
} */

function prefix(&$mods) {
  $prefix_words = array (
    array ( 'demi', 'demi|half' ),
  );
  if ( ($match = search_match($prefix_words)) != null )
    $mods[] = make_mod($match[0]);
  return ($match != null);
}

/*
function orientation(&$mods) {
  $orient_words = array (
    array ( 'bendsinwise',   'bendw(ise|ays) sinister' , ),
    array ( 'bendwise',      'bendw(ise|ays)', ),
    array ( 'fesswise',      'fessw(ise|ays)', ),
    array ( 'palewise',      'palew(ise|ays)', ),
  );

  if ( ($match = search_match($orient_words) ) != null )
    $mods[] = make_mod ( 'orientation', $match[0] );
  return ($match != null);
}

function conjoined(&$mods) {
  $conjoin = array (
    array ( true, 'con?joined' ),
  );

  if (search_match($conjoin) ) {
    $mods[] = make_mod('conjoin');
    return true;
  }
  return false;
}

function laying(&$mods) {
  $lay_words = array (
    array ( true,            'arranged', '' ),
    array ( true,            '(lying|laying)', '' ),
  );
  return (search_match($lay_words) != null);
} */

function rows(&$mods) {

  $state = save();
  $rows = array();
  $count = 0;
  while ( ($num = number( true )) != null ) {
  	$count += 1;
    $rows[] = $num;
    if ( semicolon()) break;
    comma();
    andd();
  }
  if ( $count == 1 ) {
    restore($state);
  } elseif ( $count > 1 ) {
    $mods[] = make_mod ( 'rows', implode(',',$rows) );
  }
  return ($count > 1);
}

/* Have not used these (yet...?)
    array ( 'tonorth',       'to chief' , 'direction' ),
    array ( 'tonortheast',   'to sinister (chief|canton)', 'direction' ),
    array ( 'tosoutheast',   'to sinister base' , 'direction' ),
    array ( 'toeast',        'to sinister' , 'direction' ),
    array ( 'tosouthwest',   'to base' , 'direction' ),
    array ( 'tonorthwest',   'to dexter chief' , 'direction' ),
    array ( 'tossouthwest',  'to dexter base' , 'direction' ),
    array ( 'towest',        'to dexter' , 'direction' ),
    array ( 'tonorthwest',   'to canton' , 'direction' ),
*/
?>
