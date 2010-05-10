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


function charge_weapon ( &$node, &$mods ) {

  $charge_data = array (
    'sword' => array ( 
      array ('hilt', 'hilts?|hilted' ),
      array ('pommell', 'pom?mell?s?|pomm?ell?ed' ),
      //array ('handle', 'handle(ds)?'),
      //array ('jewel', '(be)?jewel(s|led)?' ),
    ),
    'sheaf-arrows' => array (
      array ( 'barbed', 'barbed|armed' ),
      array ( 'feathered', '(flighted|feathered)' ),
    ),
    'arrow' => array (
      array ( 'barbed', 'barbed|armed' ),
      array ( 'feathered', '(flighted|feathered)' ),
    ),
  );

  $updown = array ( 
    array ( 'up',  'points? upwards?' ),
    array ( 'down',  'points? downwards?' ),
  );

  $pointing = array ( 'pheon', 'arrow', 'broad-arrow','sheaf-arrows' );
  comma();

  if (( in_array($node->get_attribute('subtype'), $pointing ) ) and ( ($match = search_match($updown)) != null )) {
    $node->append_child(make_mod('pointing',$match[0]));
  }

  if ( array_key_exists($node->get_attribute('subtype'), $charge_data )) {
    return $charge_data[$node->get_attribute('subtype')];
  } else {
    return null;
  }
}
?>
