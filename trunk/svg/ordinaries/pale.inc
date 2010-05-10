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


function makeOrd_pale($node) {
  $pale_data = array(
    'pale' => array ( 'shape_spec' => array ( 'NC' => 'X350Y-200a300C1600e300G1600', 'CH' => 'X350Y100a300C1300e300G1300' )),
    'pale-couped' => array ( 'shape_spec' => array ( 'NC' => 'X350Y100a300C1000e300G1000', 'CH' => 'X350Y400a300C700e300G700' ),
                  'bounding_box' => array ( 'NC' => '300,1000,350,100', 'CH' => '300,700,350,400' )),
    'pale-couped-chief' => array ( 'shape_spec' => array ( 'NC' => 'X350Y100a300C1200e300G2000', 'CH' => 'X350Y400a300C900e300G900' ),
                  'bounding_box' => array ( 'NC' => '300,1100,350,100', 'CH' => '300,800,350,400' )),
    'pale-couped-base' => array ( 'shape_spec' => array ( 'NC' => 'X350Y-100a300C1200e300G1200', 'CH' => 'X350Y200a300C900e300G900' ),
                  'bounding_box' => array ( 'NC' => '300,1100,350,0', 'CH' => '300,800,350,300' )),
    'pale-lozengy' => array ( 'body' => '<path d="M350,150l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,450l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150   M350,750l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,1050l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150" />' ),
    'pale-compony' => array ( 'shape_spec' => 'X350Y-200a300C1600e300G1600',
        'body2' => '<path d="M350,0h300v300h-300z M350,600h300v300h-300z M350,600h300v300h-300z " />',),
    'pale-counter-compony' => array ( 'shape_spec' => 'X350Y-200a300C1600e300G1600',
        'body2' => '<path d="M350,0h150v150h-150z M500,150h150v150h-150z M350,300h150v150h-150z M500,450h150v150h-150z M350,600h150v150h-150z M500,750h150v150h-150z M350,900h150v150h-150z M500,1050h150v150h-150z " />',),
  );
  $retval = array (
        'bounding_box' => array ( 'NC' => '300,1200,350,0', 'CH' => '300,900,350,300' ),
  );
  
  $name = $node->get_attribute('subtype');
  if ( !array_key_exists($name, $pale_data )) {
    my_trigger_error ( "No pale $name", E_USER_WARNING, __FILE__, __LINE__ );
    $name = 'pale';
  }
  return array_merge( $retval, $pale_data[$name] );
}


?>
