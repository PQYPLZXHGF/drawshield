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

$charge = array ( 
  'patterns' => array (
  'griffin',
  'gryphon',
  ),

  'modifiers' => array (
    array ( 'beaked', 'beaked', 'feature' ),
    array ( 'legged', 'legged', 'feature' ),
    array ( 'tailed', 'tailed', 'feature' ),
    array ( 'winged', 'winged', 'feature' ),
	array ( 'tongued', '(tongued|langued)', 'feature' ),
	array ( null, 'sans wings', 'mod', 'wingless' ),
	array ( null, 'rampant', 'ignore' ),
	array ( null, 'segreant', 'ignore' ),
   ),

  'height' => "400", 'width' => "320",
    'body' => '
      <path stroke="#000000" stroke-width="4" d="m 130,67 0,8 -20,5 -18,16 -9,14 -9,20 -9,0 -5,-20 3,0 -6,0 1,20 -7,0 -9,10 12,0 12,10 3,10 10,10 11,-10 -5,10 -16,20 -8,0 13,0 -14,10 6,0 -5,10 8,-10 8,20 9,-20 6,0 -6,10 9,0 2,-10 2,10 -3,10 4,-10 c 0,0 0,0 0,0 10,0 10,0 10,0 0,0 0,0 0,10 0,0 0,0 0,0 l 0,10 0,-10 10,10 0,10 10,0 0,-10 0,10 10,-10 10,10 0,0 10,10 10,0 0,10 10,20 0,0 0,10 10,10 10,20 10,0 10,10 10,10 0,30 0,10 -10,10 -10,0 -10,0 0,10 0,0 10,-10 0,10 0,0 10,-10 0,10 0,0 10,0 10,0 0,-10 0,-10 10,0 -10,-10 0,-10 0,-10 10,-10 -10,-10 -10,-20 0,-10 0,-10 0,-30 0,-10 -10,-10 -20,-20 -10,-10 -10,-10 -20,-20 -10,-20 -10,-10 0,-20 0,-10 10,10 0,-20 0,0 10,-16 0,-9 0,-13 -10,-6 20,5 -10,-10 10,-5 -10,-11 0,-4 0,-5 0,-5 -10,1 10,-3 10,-12 -10,-1 -10,5 -10,8 0,-3 10,-8 -10,-7 -10,-6 0,11 0,7 -10,0 -10,2 0,3 10,18 0,0 0,5 0,4 10,8 0,4" />
      <path stroke="#000000" stroke-width="4" d="m 120,29 10,2 10,1 -10,8 0,0 -10,-2 0,-9" />
      <path stroke="#000000" stroke-width="4" d="m 150,250 -10,10 -10,0 -10,0 -10,10 0,20 0,20 0,20 -10,10 -8,10 -13,0 -10,0 -6,0 -4,10 7,0 8,-10 -9,10 3,10 3,0 12,-10 -9,10 6,0 8,0 9,0 13,-20 0,0 10,-10 c 0,0 0,0 10,-10 0,0 10,-10 10,-10 l -10,0 -10,-10 c 0,0 0,-10 10,-10 0,0 0,-10 0,-10 l 0,-10 20,0 20,0 10,0 -10,-20 0,-10 -10,0 0,10 -10,-10 z" />
      <path stroke="#000000" stroke-width="4" d="m 160,23 -10,4" />
      <path stroke="#000000" stroke-width="4" d="m 140,15 0,4 0,1" />
      <path stroke="#000000" stroke-width="4" d="m 150,41 10,14" />
      <path stroke="#000000" stroke-width="4" d="m 140,46 20,10" />
      <path stroke="#000000" stroke-width="4" d="m 140,53 10,8" />
      <path stroke="#000000" stroke-width="4" d="m 150,74 0,14" />
      <path stroke="#000000" stroke-width="4" d="m 150,88 0,22" />
      <path stroke="#000000" stroke-width="4" d="m 140,87 10,23" />
      <path stroke="#000000" stroke-width="4" d="m 140,94 0,16" />
      <path stroke="#000000" stroke-width="4" d="m 130,120 0,20" />
      <path stroke="#000000" stroke-width="4" d="m 140,160 10,10" />
      <path stroke="#000000" stroke-width="4" d="m 200,220 -10,20" />
      <path stroke="#000000" stroke-width="4" d="m 210,230 -10,10" />
      <path stroke="#000000" stroke-width="4" d="m 220,240 -10,10 0,10" />
      <path stroke="#000000" stroke-width="4" d="m 220,250 0,20" />
      <path stroke="#000000" stroke-width="4" d="m 130,260 -20,20" />
      <path stroke="#000000" stroke-width="4" d="m 140,270 -30,20" />
      <path stroke="#000000" stroke-width="4" d="m 150,260 -10,20" />
      <path stroke="#000000" stroke-width="4" d="m 160,260 -10,20" />
      <path stroke="#000000" stroke-width="4" d="m 170,260 -10,20" />
      <path stroke="#000000" stroke-width="4" d="m 130,290 -20,10" />
      <path stroke="#000000" stroke-width="4" d="m 120,310 -10,0" />
      <path stroke="#000000" stroke-width="4" d="m 120,320 -10,10" />
      <path stroke="#000000" stroke-width="4" d="M 130,320 93,360" />
      <path stroke="#000000" stroke-width="4" d="m 140,260 -20,20" />
      <path stroke="#000000" stroke-width="4" d="m 94,100 -7,20" />
      <path stroke="#000000" stroke-width="4" d="M 110,100 96,120" />
      <path stroke="#000000" stroke-width="4" d="m 120,100 -10,20" />
      <path stroke="#000000" stroke-width="4" d="m 130,94 0,26" />
      ',
    'features' => array (
      'beaked' => array ( 'body' => '
        <path stroke="#000000" stroke-width="4" d="m 110,30 -13,2 -7,6 1,6 8,-4 1,0 10,4 10,2 -10,-20 0,4 z" />
        <path stroke="#000000" stroke-width="4" d="m 120,56 -20,5 10,3 c 0,0 0,0 10,-1 0,-1 10,1 10,1 l -10,-8 z" />
        <path stroke="#000000" stroke-width="4" d="m 110,35 0,4" /> 
      '),
      'legged' => array ( 'body' =>  '
        <path stroke="#000000" stroke-width="4" d="M 56,120 52,110 41,100 39,89 38,79 l 7,-13 -4,-5 -10,1 5,6 -2,7 -1,11 -4,-9 1,-11 -11,-3 -2,7 7,3 -1,7 9,15 -12,-9 -6,-9 -6.9,5 1.5,5 5.4,-3 2,8 13,7 0,11 0,10 -4,0 1,10 8,-10 0,-10 1,-10 7,10 2,10 8,10 4,-10 z" />
        <path stroke="#000000" stroke-width="4" d="m 61,210 -15,10 5,0 12,10 2,0 -4,10 -6,-10 -10,0 -4,0 -6,0 -1,10 -8,0 5,0 -7,10 -3,-10 18,-20 -18,10 -4,0 -1,0 -6.7,0 0,0 15.7,-10 6,0 -10,0 -7,0 -6.1,0 -4.4,-10 10.5,0 14,0 12,10 16,-20 7,0 -2,10 z" />
      '),
      'tailed' => array ( 'body' =>  '
        <path stroke="#000000" stroke-width="4" d="m 230,260 20,10 10,0 10,-10 10,-20 -10,-10 0,-20 -10,-10 -10,-30 10,-10 10,-10 10,-10 10,0 10,10 10,10 10,0 -20,0 -10,0 -10,0 0,-10 0,0 -10,0 0,0 0,10 -10,10 0,20 10,10 0,10 10,20 0,20 -10,20 -10,10 -10,0 -10,0 -10,0 0,-20" />
        <path stroke="#000000" stroke-width="4" d="m 280,150 20,10" />
        <path stroke="#000000" stroke-width="4" d="m 290,150 10,10" />
      '),
      'langued' => array ( 'body' =>  '
        <path stroke="#000000" stroke-width="4" d="m 120,51 -21,-6 -10,9 11,-1 20,-2 z" />
      '),
      'winged' => array ( 'body' =>  '
        <path stroke="#000000" stroke-width="4" d="m 230,1.4 -10,33.6 -20,26 -10,20 -20,18 -10,21 0,20 10,10 -10,0 -10,10 0,10 -20,0 -10,20 0,30 10,-20 0,20 10,-20 0,20 10,-20 10,30 0,-20 20,10 -10,-10 20,10 c 0,0 -20,-20 -10,-20 0,0 20,10 20,10 l -30,-30 40,20 -20,-10 30,0 -40,-20 50,10 -30,-10 30,0 -20,-10 30,-10 -30,-10 40,0 -40,-10 40,-10 -20,0 30,-20 -30,0 40,-14 -30,5 30,-25 0,-9 -10,9 -10,13 10,-26 20,-22 0,-7 -10,17 -20,25 10,-35 10,-26.7 0,-2.9 0,9.6 -20,33 -10,18 -10,5 -10,18 10,-26 -20,15 20,-30 10,-22 -20,20 -10,24 10,-30 10,-22 0,-12.6 z" />
        <path fill="none" stroke="#000000" stroke-width="4" d="m 170,150 0,-20 10,-20 40,-30" />
        <path stroke="#000000" stroke-width="4" d="m 160,120 10,20" />
        <path stroke="#000000" stroke-width="4" d="m 170,110 0,20" />
        <path stroke="#000000" stroke-width="4" d="m 170,97 0,13" />
        <path stroke="#000000" stroke-width="4" d="m 180,94 0,16" />
        <path stroke="#000000" stroke-width="4" d="m 190,86 0,14" />
        <path stroke="#000000" stroke-width="4" d="m 200,72 0,20" />
        <path stroke="#000000" stroke-width="4" d="m 210,61 0,23" />
        <path fill="none" stroke="#000000" stroke-width="4" d="m 120,190 20,-10 -10,20 10,0 10,-10 0,10 0,-10 10,-10 0,30 0,-20 20,20 -20,-30 20,10 -20,-10 30,0 -10,-10 20,0 -20,-10 30,0 -20,0 30,0 -40,-10 30,-10 10,0 -30,0 20,-10 10,-10 -30,10 20,-10 20,-10 -20,0 20,-12 10,-11 -10,1 10,-14 10,-9 -20,6 -10,23 0,-3 -20,19 -20,10 20,0 -20,10 0,10 0,10 0,10 0,10 0,0 -20,10 -10,0 0,0 -10,0 -20,10 z" />
        <path fill="none" stroke="#000000" stroke-width="4" d="m 160,160 0,10" />
        <path fill="none" stroke="#000000" stroke-width="4" d="m 170,150 0,20" />
        <path fill="none" stroke="#000000" stroke-width="4" d="m 160,160 10,10" />
      '),
      ),
  );
  
if ( $node != null ) {
  if (get_mod ( $node, 'wingless' ) )
    $charge['features']['winged']['body'] = '<g />';
}
?>
