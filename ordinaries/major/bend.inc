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
    $ordinary['shape_spec'] =  array ( "NC" => 'X288Y146B800d200F800h200', 'CH' => 'X288Y346B800d200F800h200' );
  elseif ( get_mod($node,'lozengy'))
    $ordinary['body'] = array ( 'NC' => '<path d="M0,0l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 
                                      l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53z " />',
                             'CH' => '<path d="M0,300l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 
                                      l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53 l106,-106 -53,159 -159,53z m53,53 l159,-53 -212.1,212.1 53,-159z m53,53z " /> ' );
  else
	  $ordinary['shape_spec'] = array ( 'NC' => 'X-212Y0h300B1772d300F1772', 'CH' => 'X-212Y300h300B1572d300F1572' );
		
	if ( $compony == 'single' )
    $ordinary['body2'] = array ( 'NC' => '<path d="M 186,-186 398,26 26,398 -186,186 z M 610,238 822,450 450,822 238,610 z m 420,424 220,213 -376,375 -212,-220 z" />',
                            'CH' => '<path d="M 186,114 398,326 26,698 -186,486 z M 610,538 822,750 450,1120 238,910 z m 420,422 220,220 -376,370 -212,-210 z" />' );
  elseif ( $compony == 'double' )
    $ordinary['body2'] = array ( 'NC' => '<path d="M 0,0 186,-186 292,-80 106,106 212,212 26,398 -80,292 106,106 z M 212,212 398,26 504,132 318,318 424,424 238,610 132,504 318,318 z M 424,424 610,238 716,344 530,530 636,636 450,822 344,716 530,530 z M 636,636 822,450 928,556 742,742 848,848 662,1030 556,928 742,742 z m 212,212 182,-186 110,106 -186,186 106,106 -186,190 -106,-110 186,-186 z" />',
                            'CH' => '<path d="M 0,300 186,114 292,220 106,406 212,512 26,698 -80,592 106,406 z M 212,512 398,326 504,432 318,618 424,724 238,910 132,804 318,618 z M 424,724 610,538 716,644 530,830 636,936 450,1120 344,1020 530,830 z M 636,936 822,750 928,856 742,1040 848,1150 662,1330 556,1230 742,1040 z m 212,214 182,-190 110,110 -186,180 106,110 -186,190 -106,-110 186,-190 z" />' );
	
	$ordinary['rotate_pattern'] = 45;
}

?>
