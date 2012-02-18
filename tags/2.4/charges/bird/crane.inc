<?php /* Copyright 2011 Karl R. Wilcox

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
  'cranes?',
  ),
   'licence' => 'commons.wikimedia.org by rinaldum',

    'modifiers' => array (
	array ( null, 'without ?the head', 'warn', 'headless' ),
	array ( null, 'holding a stone ?in ?the ?dexter ?foot', 'ignore' ),
	array ( null, 'thrust through with a sword', 'warn', 'stabbed' ),
   ),

  'height' => 768, 'width' => 505,
    'body' => '
      <path fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 31,202 c -13,-15 75,-75 138,-128 20,-1 26,20 22,31 -3,9 -2,14 0,19 -31,25 -55,50 -97,76 -14,4 -15,-6 -10,-12 L 189,105 C 139,135 40,211 31,202 z" />
      <path fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 167,72 c -7,-102 137,-79 129,-2 -3,74 -31,165 -71,221 -5,14 4,37 36,31 11,-3 15,-18 23,-27 20,-13 38,-1 52,7 48,32 84,81 98,120 l -20,-7 c 17,8 32,23 42,58 l -62,-38 c 32,26 76,37 83,95 L 345,439 c 60,47 170,96 152,158 l -17,-20 c -23,20 -85,17 -89,12 -10,-16 -18,-14 -24,-13 2,-4 9,-65 6,-59 2,4 -7,59 -7,61 0,78 -3,56 -1,122 25,0 37,11 50,23 -6,1 -11,5 -7,12 -18,2 -33,-6 -48,-13 -19,9 -55,23 -57,28 2,4 -2,6 -5,8 -16,-1 -11,-20 -24,-16 -1,-6 0,-12 8,-14 18,1 34,-8 50,-17 -14,7 -26,18 -43,14 -8,-1 -9,1 -14,-2 -7,-17 1,-21 9,-20 l 51,2 -3,-97 c -27,-90 -43,-80 -63,-106 -9,-10 -15,-21 -25,-26 -53,-10 -84,-41 -100,-87 -11,-35 -19,-118 40,-188 9,-13 32,-38 34,-76 l 13,-3 -40,1 0,-18 c 3,-23 -8,-30 -24,-33 z" />
      <path fill="#ffffff" fill-rule="evenodd" stroke="inherit" stroke-width="3" d="m 211,65 c -4,-14 12,-17 22,-20 13,5 -5,39 -22,20 z" />
      <path fill="#000000" stroke="inherit" stroke-width="3" d="m 225,55 c 0,3 -2,5 -4,5 -2,0 -4,-2 -4,-5 0,-3 2,-5 4,-5 2,0 4,2 4,5 z" />
      <path fill="#ffffff" stroke="inherit" stroke-width="5" d="m 133,528 c 0,37 -29,68 -64,68 -35,0 -64,-31 -64,-68 0,-37 29,-67 64,-67 35,0 64,30 64,67 z" />
      <path fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 161,425 6,47 c 3,9 -21,12 -30,9 -49,-26 -44,-50 -106,-35 -6,3 -17,2 -12,11 9,2 13,7 14,14 13,1 9,-5 12,-7 22,-11 39,4 58,23 17,17 17,38 8,68 6,-3 8,2 10,5 8,-13 19,-23 12,-58 29,-3 54,3 78,9 l 9,-41 z" />
      <path fill="#000000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 164,430 45,50 1,30 10,-42 z" />
      <path fill="none" stroke="inherit" stroke-width="5" d="m 239,357 c 1,24 -1,62 23,73 87,40 201,109 227,160" />
      <path fill="#eb0000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 272,710 c -11,2 -18,6 -21,14 8,-4 16,-6 24,-1 z" />
      <path fill="#eb0000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 274,741 c -13,2 -16,10 -21,26 12,-11 23,-20 42,-11 -3,-8 -3,-17 -21,-15 z" />
      <path fill="#eb0000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 408,735 c 12,-2 23,7 35,12 -4,-9 -16,-22 -28,-23 -6,-2 -10,3 -7,11 z" />
      <path fill="none" stroke="inherit" stroke-width="5" d="m 360,694 c -3,8 10,10 7,19 -2,2 -5,4 -6,7" />
      <path fill="#eb0000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="m 111,556 c -6,10 -19,12 -27,11 10,1 20,4 35,-4 6,-9 -3,-10 -8,-7 z" />
      <path fill="#eb0000" fill-rule="evenodd" stroke="inherit" stroke-width="5" d="M 17,457 C 9,466 9,476 7,486 14,475 23,473 32,470 31,455 23,459 17,457 z" />
      ',
  );



/*
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
*/

?>
