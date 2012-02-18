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
    $ordinary['shape_spec'] = array ( 'NC' => 'X350Y100a300C1000e300G1000', 'CH' => 'X350Y400a300C700e300G700' );
  elseif ( $couped == 'chief')
    $ordinary['shape_spec'] = array ( 'NC' => 'X350Y100a300C1108e300G1108', 'CH' => 'X350Y400a300C808e300G808' );
  elseif ( $couped == 'base')
    $ordinary['shape_spec'] = array ( 'NC' => 'X350Y-8a300C1108e300G1108', 'CH' => 'X350Y200a300C900e300G900' );
  elseif ( get_mod($node,'lozengy'))
    $ordinary['body'] = '<path d="M350,150l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,450l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150   M350,750l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150  M350,1050l75,-150 75,150 75,-150 75,150 -75,150 -75,-150 -75,150 -75,-150" />';
  elseif ( get_mod($node,'voided'))
    $ordinary['shape_spec'] = array ( 'NC' => 'X350Y-38a300C1272e300G1272', 'CH' => 'X350Y262a300C972e300G972' );
  else
    $ordinary['shape_spec'] = array ( 'NC' => 'X350Y-8a300C1216e300G1216', 'CH' => 'X350Y292a300C916e300G916' );
  
  if ( $compony == 'single' )
     $ordinary['body2'] = '<path d="M250,0h500v300h-500z M250,600h500v300h-500z M250,600h500v300h-500z " />';
    elseif ( $compony == 'double' )
      $ordinary['body2'] = '<path d="M250,0h250v150h-250z M500,150h250v150h-250z M250,300h250v150h-250z M500,450h250v150h-250z M250,600h250v150h-250z M500,750h250v150h-250z M250,900h250v150h-250z M500,1050h250v150h-250z " />';
    
}

?>
