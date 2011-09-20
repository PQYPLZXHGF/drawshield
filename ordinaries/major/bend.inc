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
    'bend',
  ), 

  'doc' => '',

);

if ( $node == null ) {
  include 'ordinaries/common/_couped.inc';
  include 'ordinaries/common/_compony.inc';
} else {
  $couped = get_mod($node,'couped');
  $compony = get_mod($node,'compony');
  
  if ( $couped == 'both' )
    $body_data =  array ( 'shape_spec' => array ( "NC" => 'X288Y146B800d200F800h200', 'CH' => 'X288Y346B800d200F800h200' ),
        'bounding_box' => array ( 'NC' => '900,900', 'CH' => '900,900,100,100' ));
  elseif ( get_mod($node,'lozengy'))
    $body_data = array ( 'body' => array ( 'NC' => '<path d="M0,0l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 
                                      l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53z " />',
                             'CH' => '<path d="M0,300l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 
                                      l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53z " /> ' ));
  elseif ( $compony == 'single' )
    $body_data = array ('shape_spec' => array ( 'NC' => 'X-212Y0h300B1572d300F1572', 'CH' => 'X-212Y300h300B1572d300F1572' ),
                'body2' => array ( 'NC' => '<path d="M106,-106l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2 l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2 l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2" />',
                            'CH' => '<path d="M106,194l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2 l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2 l212.1,212.1 -212.1,212.1 -212.1,-212.1z m424.2,424.2" />' ));
  elseif ( $compony == 'double' )
    $body_data =  array ('shape_spec' => array ( 'NC' => 'X-212Y0h300B1572d300F1572', 'CH' => 'X-212Y300h300B1572d300F1572' ),
                'body2' => array ( 'NC' => '<path d="M0,0 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z" />',
                            'CH' => '<path d="M0,300 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z m212.1,212.1 l106,-106 106,106 -106,106, 106,106 -106,106 -106,-106 106,-106z" />' ));
  else
    $body_data = array ('shape_spec' => array ( 'NC' => 'X-212Y0h300B1772d300F1772', 'CH' => 'X-212Y300h300B1572d300F1572' ));
    
  $ordinary = array_merge($ordinary, $body_data);
}

?>
