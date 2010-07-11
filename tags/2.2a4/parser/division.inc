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

  static $divisions = array (
    //       filename           regexs
    array ( 'pily',               'pily', 'common', ),
    array ( 'quarterly',          'quarterly/?party per cross', 'quarterly',  ),
    array ( 'quarterly-per-fess', 'quarterly per fess', 'quarterly',  ),
    array ( 'quarterly-per-pale', 'quarterly per pale', 'quarterly',  ),
    array ( 'paly-bendy',         'paly bendy', 'common', ),
    array ( 'pily-bendy',         'pily bendy', 'common', ),
    array ( 'pily-bendy-sinister','pily bendy sinister' , 'common', ),
    array ( 'barry',              '(barry|barruly)', 'bar',  ),
    array ( 'paly',               'paly', 'bar',  ),
    array ( 'chape',              'chape', 'common',  ),
    array ( 'chevronny',          'chevronn?(ell)?y', 'chevronny',  ),
    array ( 'chausse',            'chausse', 'common',  ),
    array ( 'quarterly-quartered','quarterly quartered', 'gyronny',  ),
    array ( 'gyronny',            'gyronny', 'gyronny',  ),
    array ( 'bendy',              'bendy', 'bar',  ),
    array ( 'bendy-sinister',     'bendy sinister' , 'bar',  ),
    array ( 'per-fess',           '?party per fesse?' , 'common', ),
    array ( 'per-fess',           'parted fesswise' , 'common', ),
    array ( 'per-pale',           '?party per pale' , 'common', ),
    array ( 'per-pale',           'parted palewise' , 'common', ),
    array ( 'per-pile',           '?party per pile' , 'common', ),
    array ( 'per-pile',           'parted pilewise' , 'common', ),
    array ( 'per-pall',           '?party per pall' , 'common', ),
    array ( 'per-pall',           'tierced in pairle' , 'common', ),
    array ( 'per-pall-reversed',  '?party per pall reversed' , 'common', ),
    array ( 'per-pall-reversed',  'tierced in pairle reversed' , 'common', ),
    array ( 'per-chevron',        '?party per chevron' , 'common', ),
    array ( 'per-chevron',        'parted chevronwise' , 'common', ),
    array ( 'per-bend',           '?party per bend', 'common', ),
    array ( 'per-bend',           'parted bendwise', 'common', ),
    array ( 'per-bend-sinister',  '?party per bend sinister'   , 'common', ),
    array ( 'per-bend-sinister',  'parted bendwise sinister'  , 'common', ),
    array ( 'per-saltire',        '?party per saltire/parted saltirewise' , 'common',),
    array ( 'tierced-in-pale',    'tierced in pale' , 'common',),
    array ( 'tierced-in-fess',    'tierced in fess' , 'common',),
    array ( 'fusily',             'fusill?y', 'pattern', ),
    array ( 'fusily-bendy',       'fusill?y bendy ?dexter/fusill?y in bend', 'pattern', ),
    array ( 'fusily-bendy-sinister',    'fusill?y bendy sinister/fusill?y in bend sinister', 'pattern', ),
    array ( 'lozengy',            '(lozengy|masculy)', 'pattern' ),
    array ( 'barry-bendy',        'barry bendy ?lozengy' , 'pattern' ),
    array ( 'barry-pily',         'barry pily' , 'bar' ),
    array ( 'barry-pily-sinister','barry pily sinister' , 'bar' ),
    array ( 'barry-bendy-sinister','barry bendy sinister ?lozengy' , 'pattern' ),
    array ( 'barry-indented-oio', 'barry indented ?the (one|1) in the other', 'pattern' ),
  );

  $node = null;
  $tokNum = toknum();
  if ( ($match = search_match ( $divisions )) != null ) {
    $node = $dom->create_element('division');
    $node->set_attribute('tokNum',$tokNum);
    $node->set_attribute('type', $match[2]);
    $node->set_attribute('subtype', $match[0]);
    $node->set_attribute('linetype', 'none');
    $node->append_child($dom->create_element('tincture'));
    $node->append_child($dom->create_element('tincture'));
    comma();
    // Prepare the division function
    if ( file_exists('parser/divisions/' . $match[2] . '.inc' )) {
      $div_func = 'division_' . $match[2];
      if ( ! function_exists($div_func) ) {
        require_once ( 'parser/divisions/' . $match[2] . '.inc' );
      }
      // See if this division has a third colour or any type-specific modifiers
      $node = $div_func($node);
    }
    // generic modifiers
    if ( $node->get_attribute('linetype') == 'none' ) {
      $node->set_attribute('linetype', linetype());
    }
    comma();
    if ( $depth == 1 ) { // look for all tinctures
      foreach ( $node->child_nodes() as $child ) {
        if ( $child->tagname() == 'tincture' ) {
          $node->replace_child( tincture(true), $child );
          andd();
          comma();
        }
      }
    } else { // look for only 1 tincture
      $count = 0;
      foreach ( $node->child_nodes() as $child ) {
        if ( $child->tagname() == 'tincture' ) {
          if ( $count == 0 ) {
            $node->replace_child( tincture(true), $child );
            comma();
            $count = 1;
          } else {
            $child->append_child( $dom->create_element('implied') );
          }
        }
      }
    }
    // See if there is a second division
    //if ( ($depth == 1) and (($div2 = division(2)) != null) ) $node->append_child($div2);
  }
  return $node;
}

?>
