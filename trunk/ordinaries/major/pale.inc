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

$ordinary = array (
  'patterns' => array (
    'pale',
  ), 

  'doc' => '',

);

if ( $node == null ) {
  include 'ordinaries/common/_couped.inc';
  include 'ordinaries/common/_compony.inc';
  include 'ordinaries/common/_lozengy.inc';
} else {
  $couped = get_mod($node,'couped');
  $compony = get_mod($node,'compony');
  
  if ( $couped == 'both' )
    $body_data = array ( 'shape_spec' => array ( 'NC' => 'X350Y100a300C1000e300G1000', 'CH' => 'X350Y400a300C700e300G700' ),
                  'bounding_box' => array ( 'NC' => '300,1000,350,100', 'CH' => '300,700,350,400' ));
  elseif ( $couped == 'chief')
    $body_data = array ( 'shape_spec' => array ( 'NC' => 'X350Y100a300C1200e300G2000', 'CH' => 'X350Y400a300C900e300G900' ),
                  'bounding_box' => array ( 'NC' => '300,1100,350,100', 'CH' => '300,800,350,400' ));
  elseif ( $couped == 'base')
    $body_data = array ( 'shape_spec' => array ( 'NC' => 'X350Y-100a300C1200e300G1200', 'CH' => 'X350Y200a300C900e300G900' ),
                  'bounding_box' => array ( 'NC' => '300,1100,350,0', 'CH' => '300,800,350,300' ));
  elseif ( get_mod($node,'lozengy'))
    $body_data = array ( 'body' => '<path d="M350,150l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,450l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150   M350,750l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,1050l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150" />' );
  elseif ( $compony == 'single' )
    $body_data = array ( 'shape_spec' => 'X350Y-200a300C1600e300G1600',
        'body2' => '<path d="M350,0h300v300h-300z M350,600h300v300h-300z M350,600h300v300h-300z " />',);
  elseif ( $compony == 'double' )
    $body_data = array ( 'shape_spec' => 'X350Y-200a300C1600e300G1600',
        'body2' => '<path d="M350,0h150v150h-150z M500,150h150v150h-150z M350,300h150v150h-150z M500,450h150v150h-150z M350,600h150v150h-150z M500,750h150v150h-150z M350,900h150v150h-150z M500,1050h150v150h-150z " />',);
  else
    $body_data = array ( 'shape_spec' => array ( 'NC' => 'X350Y-200a300C1600e300G1600', 'CH' => 'X350Y100a300C1300e300G1300' ));
    
  if ( ! array_key_exists('bounding_box', $body_data)) $body_data['bounding_box'] = array ( 'NC' => '300,1200,350,0', 'CH' => '300,900,350,300' );
  $ordinary = array_merge($ordinary, $body_data);
}

?>
