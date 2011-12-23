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


function division( $depth = 1 ) {
  global $dom;
  global $pending_items;

  static $divisions = array (
    //       filename           regexs         needs 3 colours?
    array ( 'pily',               'pily', 'common', ),
    array ( 'quarterly',          'quarterly/?party per cross', 'quarterly',  ),
    array ( 'quarterly-per-fess', 'quarterly per fess', 'quarterly',  ),
    array ( 'quarterly-per-pale', 'quarterly per pale', 'quarterly',  ),
    array ( 'paly-bendy',         'paly bendy', 'common', ),
    array ( 'paly-bendy',         'bendy paly', 'common', ),
    array ( 'pily-bendy',         'pily bendy', 'common', ),
    array ( 'pily-bendy',         'bendy pily', 'common', ),
    array ( 'barry',              '(barry|barruly)', 'bar',  ),
    array ( 'paly',               'paly', 'bar',  ),
    array ( 'chape',              'chape', 'common',  ),
    array ( 'chevronny',          'chevronn?(ell)?y', 'chevronny',  ),
    array ( 'chausse',            'chausse', 'common',  ),
    array ( 'gyronny',			'quarterly quartered', 'gyronny',  ),
    array ( 'gyronny',            'g(i|y)ronny', 'gyronny',  ),
    array ( 'bendy',              'bendy', 'bar',  ),
    array ( 'per-fess',           '?party per fesse?' , 'common', ),
    array ( 'per-fess',           'parted fesswise' , 'common', ),
    array ( 'per-pale',           '?party per pale' , 'common', ),
    array ( 'per-pale',           'parted palewise' , 'common', ),
    array ( 'per-pile',           '?party per pile' , 'common', true, ),
    array ( 'per-pile',           'parted pilewise' , 'common', true, ),
    array ( 'per-pall',           '?party per pall' , 'common',  true,),
    array ( 'per-pall',           'tierced in pairle' , 'common', true, ),
    array ( 'per-chevron',        '?party per chevron' , 'common', ),
    array ( 'per-chevron',        'parted chevronwise' , 'common', ),
    array ( 'per-bend',           '?party per bend', 'common', ),
    array ( 'per-bend',           'parted bendwise', 'common', ),
    array ( 'per-saltire',        '?party per saltire/parted saltirewise' , 'common',),
    array ( 'tierced-in-pale',    'tierced in pale' , 'common', true,),
    array ( 'tierced-in-fess',    'tierced in fess' , 'common', true,),
    array ( 'tierced-in-bend',    'tierced in bend' , 'common', true,),
    array ( 'tierced-in-chevron',    'tierced in chevron' , 'common', true,),
    array ( 'fusily',             'fusill?y', 'pattern', ),
    array ( 'fusily-bendy',       'fusill?y bendy ?dexter/fusill?y in bend', 'pattern', ),
    array ( 'lozengy',            '(lozengy|masculy)', 'pattern' ),
    array ( 'barry-bendy',        'barry bendy ?lozengy' , 'pattern' ),
    array ( 'barry-pily',         'barry pily' , 'bar' ),
    array ( 'barry-indented-oio', 'barry indented ?the (one|1) in the other', 'pattern' ),
  );

  static $of_pieces = array (
     array ( null, 'of # ?pieces', 'mod', 'ofnum' ),
   );

  $node = null;
  $tinc_count = 0;
  if ( ($match = search_match ( $divisions )) != null ) {
    $node = $dom->createElement('division');
    $node->setAttribute( 'tokens',tokens());
    $node->setAttribute( 'type', $match[2]);
    $node->setAttribute( 'subtype', $match[0]);
    comma();
    // generic modifiers, including tinctures
    $max_tinc = (isset($match[3]) and $match[3] === true) ? 'need3tinc' : 'need2tinc';
    get_features(array('linetype', 'ordinary', $max_tinc, $of_pieces), $node);
    // How many tinctures did we find?
    foreach ($node->childNodes as $child )
      if ( $child->nodeName == 'tincture' ) $tinc_count++;
    if ( $tinc_count < 1 ) {
      $tinc = $dom->createElement('tincture');
      $tinc->setAttribute('index', 1);
      $tinc->setAttribute('origin', 'missing');
      $node->appendChild($tinc);
    }
    if ( $depth == 1 ) {
      // Always need second tincture
      if ( $tinc_count < 2 ) {
        $tinc = $dom->createElement('tincture');
        $tinc->setAttribute('index', 2);
        $tinc->setAttribute('origin', 'missing');
        $node->appendChild($tinc);
      }
      // Do we need a third also?
      if ( isset($match[3]) and $match[3] === true and $tinc_count < 3) {
        $tinc = $dom->createElement('tincture');
        $tinc->setAttribute('index', 3);
        $tinc->setAttribute('origin', 'missing');
        $node->appendChild($tinc);
      }
    } else { // second tincture is implied
      $tinc = $dom->createElement('tincture');
      $tinc->setAttribute('origin', 'implied');
      $tinc->setAttribute('index', 2);
      $node->appendChild($tinc);
    }
  }
  return $node;
}

?>
