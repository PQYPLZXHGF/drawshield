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


function charge_geometric( &$node, &$mods ) {
  global $dom;

  $fixed = array ( 'pomme', 'plate', 'hurt', 'torteau', 'bezant', 'golpe', 'pellet' );

  $type = $node->get_attribute('subtype');
  if ( in_array( $type, $fixed ) ) {
    $tinc = $dom->create_element('tincture');
    $tinc->append_child($dom->create_element('implied'));
    $node->append_child($tinc);
  }
  if ( $type == 'fountain' ) {
//    $node->set_attribute('subtype','roundel');
    proper();
    search_match( array ( array ( true, 'barry wavy of six argent ?and azure' ) ) );
    $tinc = $dom->create_element('tincture');
    $imp = $dom->create_element('implied');
    $tinc->append_child($imp);
    $node->append_child($tinc);
  } 
  if ( $type == 'triangle' )
    return array ( array ( 'voided', 'voided' ) );
  else
    return null;
}
?>
