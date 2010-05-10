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


function makeOrd_chief($node) {

  $chief_data = array(
    'chief' => array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400',  'put_in_chief' => true, ),
    'chief-couped' => array ( 'shape_spec' => 'X100Y-100a800c400E800g400', 'bounding_box' => '800,300,100,0' ),
    'chief-couped-sinister' => array ( 'shape_spec' => 'X100Y-100a900c400E900g400', 'bounding_box' => '900,300,100,0' ),
    'chief-couped-dexter' => array ( 'shape_spec' => 'X0Y-100a900c400E900g400', 'bounding_box' => '900,300,0,0' ),
    'chief-lozengy' => array ( 'body' => '<path d="M0,0l83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 v300 l-83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 " />' ),
    'chief-triangular' => array ( 'shape_spec' => 'X-100Y-100a1200D848F848', 'bounding_box' => '1000,500', ),
    'chief-compony' => array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400', 
        'body2' => '<path d="M0,0h250v300h-250z M500,0h250v300h-250z" />', 'put_in_chief' => true, ),
    'chief-counter-compony' => array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400', 
        'body2' => '<path d="M0,0h250v150h-250z M250,150h250v150h-250z M500,0h250v150h-250z M750,150h250v150h-250z" />',
        'put_in_chief' => true, ),
  );
 
  $retval = array (
       'bounding_box' => '1000,300',);

  $name = $node->get_attribute('subtype');
  if ( !array_key_exists($name, $chief_data )) {
    my_trigger_error ( "No chief $name", E_USER_WARNING, __FILE__, __LINE__ );
    $name = 'chief';
  }
  return array_merge( $retval, $chief_data[$name] );
}


?>
