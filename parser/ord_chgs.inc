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

function assign_layer ( $node ) {
  // Sorts the ordinaries and charges out so that if drawn in the order give, layering is correct
  $layerNums = array (
    // If not specified, use layer 0
    array ( 'type', 'chief', 1 ),
    // all charges are layer 2
    array ( 'subtype', 'canton', 3 ),
    array ( 'subtype', 'gyron', 4 ),
    array ( 'type', 'cadency', 5 ),
    array ( 'subtype', 'grid', 6 ), // Ensure highest number matches line CHANGE HERE below
  ); 

  $layer = 0;
  foreach ( $layerNums as $layerNum ) 
    if ( $node->get_attribute($layerNum[0]) == $layerNum[1] ) $layer = $layerNum[2];
  return $layer;
}

function ord_chgs(){
  global $dom;

  $mirror_if_2 = array ( 'canton', 'gyron', 'gusset', 'graft', 'flaunch', 'square-flaunch' );

  $node = null;
  $items = array();
  $itemLayer = array();
  $numItems = 0;

  while (( ($item = ordinary()) != null ) or ( ($item = charge()) != null )) {
    if ( $item->tagname() == 'charge' ) {
      $items[] = $item;
      $itemLayer[] = 2;
    } else { // item is an ordinary
      if ( $item->get_attribute('number') == 2
                   and in_array($item->get_attribute('subtype'), $mirror_if_2) ) {
        $item2 = deep_copy($item);
        $item2->append_child(make_mod('sinister'));
        $items[] = $item2; 
        $itemLayer = assign_layer($item2);
      }
      $items[] = $item; 
      $itemLayer[] = assign_layer($item);
    }
    comma();
    andd();
  }
  if ( ($numItems = count($items)) ) {
    $node = $dom->create_element('ord_chgs');
    for ( $i = 0; $i <= 6; $i++ ) { // count through layers CHANGE HERE
      for ( $j = 0; $j < $numItems; $j++ ) // match items on that layer
        if ( $itemLayer[$j] == $i ) $node->append_child($items[$j]); // append in order
    }
  }
  return $node;
}
?>
