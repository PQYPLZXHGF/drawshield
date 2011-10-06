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
    'chief',
  ), 

  'doc' => '',

);

if ( $node == null ) {
  include 'ordinaries/common/_couped.inc';
  include 'ordinaries/common/_compony.inc';
  include 'ordinaries/common/_lozengy.inc';
  $ordinary['modifiers'][] = array ( null, 'triangular', 'mod', 'triangular');
} else {
  $couped = get_mod($node,'couped');
  $compony = get_mod($node,'compony');
  
  if ( $couped == 'both' )
    $body_data = array ( 'shape_spec' => 'X100Y-100a800c400E800g400', 'bounding_box' => '800,300,100,0' );
  elseif ( $couped == 'dexter')
    $body_data = array ( 'shape_spec' => 'X0Y-100a900c400E900g400', 'bounding_box' => '900,300,0,0' );
  elseif ( $couped == 'sinister')
    $body_data = array ( 'shape_spec' => 'X100Y-100a900c400E900g400', 'bounding_box' => '900,300,100,0' );
  elseif ( get_mod($node,'triangular'))
    $body_data = array ( 'shape_spec' => 'X-100Y-100a1200D848F848', 'bounding_box' => '1000,500', );
  elseif ( get_mod($node,'lozengy'))
    $body_data = array ( 'body' => '<path d="M0,0l83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 v300 l-83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 " />',
          'bounding_box' => '1000,300' );
  elseif ( $compony == 'single' )
    $body_data =  array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400', 'bounding_box' => '1000,300',
        'body2' => '<path d="M0,0h250v300h-250z M500,0h250v300h-250z" />', );
  elseif ( $compony == 'double' )
    $body_data = array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400', 'bounding_box' => '1000,300',
        'body2' => '<path d="M0,0h250v150h-250z M250,150h250v150h-250z M500,0h250v150h-250z M750,150h250v150h-250z" />', );
  else
    $body_data = array ( 'shape_spec' => 'X-100Y-100a1200c400E1200g400', 'bounding_box' => '1000,300', );
		
	$ordinary['if_ord_on'] = 'scale';
    
  $ordinary = array_merge($ordinary, $body_data);
}

?>
