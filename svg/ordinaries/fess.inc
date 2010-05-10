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


function makeOrd_fess($node) {

  $fess_data = array(
    'fess' => array ( 'shape_spec' => 'X-100Y350A1200c300E1200g300' ),
    'fess-couped' => array ( 'shape_spec' => 'X100Y350A800c300E800g300', 'bounding_box' => '800,300,100,350' ),
    'fess-couped-dexter' => array ( 'shape_spec' => 'X-100Y350A1000c300E1000g300', 'bounding_box' => '900,300,0,350'  ),
    'fess-couped-sinister' => array ( 'shape_spec' => 'X100Y350A1000c300E1000g300', 'bounding_box' => '900,300,100,350'  ),
    'fess-lozengy' => array ( 'body' => '<path d="M0,350l83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 v300 l-83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 " />' ),
    'fess-compony' => array ( 'shape_spec' => 'X-100Y350A1200c300E1200g300',
          'body2' => '<path d="M0,350h250v300h-250z M500,350h250v300h-250z" />',),
    'fess-counter-compony' => array ( 'shape_spec' => 'X-100Y350A1200c300E1200g300',
        'body2' => '<path d="M0,350h250v150h-250z M250,500h250v150h-250z M500,350h250v150h-250z M750,500h250v150h-250z" />',),
  );

  $retval = array ( 'bounding_box' => '1000,300,0,350' );

  $name = $node->get_attribute('subtype');
  if ( !array_key_exists($name, $fess_data )) {
    my_trigger_error ( "No fess $name", E_USER_WARNING, __FILE__, __LINE__ );
    $name = 'fess';
  }
  return array_merge( $retval, $fess_data[$name] );
}


?>
