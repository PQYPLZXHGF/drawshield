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
  'link' => 'http://karlwilcox.com/parker/c/chief',
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
    $ordinary['shape_spec'] = 'X100Y-8U1a800c408E800g408';
  elseif ( $couped == 'dexter')
    $ordinary['shape_spec'] =  'X-8Y-8U1a908c408E908g408';
  elseif ( $couped == 'sinister')
    $ordinary['shape_spec'] =  'X100Y-8U1a908c408E908g408';
  elseif ( get_mod($node,'triangular'))
    $ordinary['shape_spec'] =  'V1X-8Y-8U1a1016D719F719';
  elseif ( get_mod($node,'lozengy'))
    $ordinary['body'] = '<path d="M0,0l83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 v300 l-83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 " />';
  elseif ( get_mod($node, 'voided'))
    $ordinary['shape_spec'] = 'X-40Y-8U1a1080c308E1080g308';
  else
    $ordinary['shape_spec'] = 'X-8Y-8U1a1016c308E1016g308';
  
   if ( $compony == 'single' )
    $ordinary['body2'] = '<path d="M0,0h250v450h-250z M500,0h250v450h-250z" />';
  elseif ( $compony == 'double' )
    $ordinary['body2'] =  '<path d="M0,0h250v150h-250z M250,150h250v300h-250z M500,0h250v150h-250z M750,150h250v300h-250z" />';
		
}

?>
