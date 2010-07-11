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


function makeOrd_tierce($node) {

  $tierce_data = array (
    'tierce' => array ( 'shape_spec' => array ( 'NC' => 'X333.33Y-200C1600e500g1600a500', 'CH' => 'X333.33Y100C1300e500g1300a500' ), ),
    'tierce-compony' =>  array ( 'shape_spec' => 'X333.33Y-200C1600e500g1600a500', 
        'body2' => '<path d="M0,0h333v300h-333z M0,600h333v300h-333z M0,600h333v300h-333z " />',),
    'tierce-counter-compony' =>  array ('shape_spec' => 'X333.33Y-200C1600e500g1600a500', 
        'body2' => '<path d="M0,0h167v150h-167z M167,150h167v150h-167z M0,300h167v150h-167z M167,450h167v150h-167z M0,600h167v150h-167z M167,750h167v150h-167z M0,900h167v150h-167z M167,1050h167v150h-167z " />',),
  );

  $retval = array( 'bounding_box' => '333,1200', );

  $name = $node->get_attribute('subtype');

  if ( !array_key_exists($name, $tierce_data )) {
    my_trigger_error ( "No tierce $name", E_USER_WARNING, __FILE__, __LINE__ );
    $name = 'tierce';
  }
  return array_merge( $retval, $tierce_data[$name] );
}
?>
