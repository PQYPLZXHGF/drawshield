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
      array ('hilt', 'hilts?|hilted', 'feature' ),
      array ('pommell', 'pom?mell?s?|pomm?ell?ed', 'feature' ),
    ),
    'sheaf-arrows' => array (
      array ( 'barbed', 'barbed|armed', 'feature' ),
      array ( 'feathered', '(flighted|feathered)', 'feature' ),
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'arrow' => array (
      array ( 'barbed', 'barbed|armed', 'feature' ),
      array ( 'feathered', '(flighted|feathered)', 'feature' ),
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'pheon' => array (
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'broad-arrow' => array (
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
  );

  if ( array_key_exists($node->get_attribute('subtype'), $charge_data )) {
    return $charge_data[$node->get_attribute('subtype')];
  } else {
    return null;
  }
}
?>
