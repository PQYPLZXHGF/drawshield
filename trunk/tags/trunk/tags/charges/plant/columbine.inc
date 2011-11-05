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

// columbine

$charge = array (

  'patterns' => array (
  'columbines?',
  ),
  'modifiers' => array (
    array ( 'slipped', '(slipped|stalked|leaved)', 'feature',    ),
    array ( 'barbed', 'barbed', 'feature',    ),
    array ( 'flowers', '(flowered|flowers|buds)', 'feature',    ),
    array ( NULL, 'pendent', 'ignore',    ),
    array ( NULL, 'slips crossed', 'ignore',    ),
    array ( NULL, 'drooping', 'ignore',    ),
  ),

  'doc' => 'Stuff...',

  'height' => '400',
  'width' => '300',
  'proper' => '#006DFF',
  'body' => '<g/>',
  'features' => 
  array (
    'flowers' => 
    array (
      'proper' => '#006DFF',
      'body' => '
      <path stroke="#000000" stroke-width="4" d="m 150,120 c -10,-10 -50,-10 -40,30 10,30 10,80 0,170 0,10 -41,40 -34,40 7,10 64,0 64,-20 10,-20 10,-170 0,-180 -10,-10 -20,-20 -10,-30 0,0 20,-10 20,-10 z" />
      <path stroke="#000000" stroke-width="4" d="m 150,120 c 20,-10 40,-10 40,10 0,20 -10,130 0,150 10,30 10,100 30,100 10,0 -60,10 -70,-70 0,-70 0,-140 10,-140 20,-10 0,-50 -10,-50 z" />
      <path fill="none" stroke="#000000" stroke-width="2" d="m 110,140 c 10,10 20,80 10,110 0,40 0,100 -10,100" />
      <path fill="none" stroke="#000000" stroke-width="2" d="m 180,140 c 0,0 0,60 0,100 0,40 10,120 20,130" />
      ',
    ),
    'slipped' => 
    array (
      'proper' => '00FB00',
      'body' => '
        <path stroke="#000000" stroke-width="2" d="m 76,19 -9,6 c 0,0 63,53 73,53 10,0 0,-11 0,-11 L 76,19 z" />
        <path stroke="#000000" stroke-width="2" d="M 86,40 C 75,78 80,79 86,80 93,81 100,53 98,49 94,45 87,40 86,40 z" />
        <path stroke="#000000" stroke-width="2" d="m 110,63 c -10,3 -15,26 -10,28 10,2 30,-14 20,-25 -10,-11 0,-1 -10,-3 z" />
        <path stroke="#000000" stroke-width="2" d="m 130,72 c 0,0 10,38 10,38 10,10 20,0 20,-10 C 150,89 140,79 140,76 130,74 130,73 130,72 z" />
        <path stroke="#000000" stroke-width="2" d="m 96,36 c 24,-12 64,-7 64,1 0,9 -50,10 -50,7 0,-3 -14,-7 -14,-8 z" />
        <path stroke="#000000" stroke-width="2" d="m 140,67 c 20,5 50,14 50,26 0,17 -50,-11 -50,-14 10,-3 10,-5 0,-12 z" />
      ',
    ),
    'barbed' => 
    array (
      'proper' => '#006DFF',
      'body' => '
        <path stroke="#000000" stroke-width="4" d="m 100,110 c -27,10 -39,50 -25,100 -1,50 -2,90 -19,140 64,-10 54,-70 54,-110 0,-20 -10,-60 -17,-90 6,-10 7,-30 7,-40 z" />
        <path stroke="#000000" stroke-width="4" d="m 200,110 c 10,0 20,10 30,80 0,30 20,110 40,160 -30,0 -60,0 -70,-80 -10,-60 -20,-50 -10,-80 10,-50 10,-80 10,-80 z" />
        <path fill="none" stroke="#000000" stroke-width="2" d="m 89,160 c 5,30 21,120 11,140 0,10 -12,30 -12,30" />
        <path fill="none" stroke="#000000" stroke-width="2" d="m 210,140 c -10,40 -20,60 -20,70 0,10 20,60 30,100 0,10 10,20 20,30" />
      ',
    ),
  ),

)

?>
