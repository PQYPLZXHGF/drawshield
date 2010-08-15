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

// bears-head

$charge = array (

  'patterns' => array (
  'bears? heads? ?couped',
  ),
  'modifiers' => array (
    array ( 'tongued', 'tongued', 'feature',    ),
    array ( 'muzzled', 'muzzled', 'feature',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 500,
  'height' => 420,
  'body' => '<path d="M 303,98.6 C 294,57.1 325,40 347,20 c 17,7.1 42,24.3 39,35.7 -3,11.4 -3,41.4 -22,50.3 -18,8 -61,-6 -61,-7.4 z" stroke="#000000" stroke-width="5" />
    <path d="M 303,97.1 C 270,124 204,106 181,124 c -22,19 10,49 -21,57 -31,9 -140,33 -142.9,58 -2.8,24 -1.4,75 54.3,80 55.6,4 199.6,-2 197.6,22 -3,25 -153,10 -168,33 -13.9,23 382,76 382,19 0,-57 -79,-212 -66,-230 13,-19 55,-110.1 27,-140.1 -40,-7.1 -75,83.1 -93,81.1 -17,-1 -50,-6.9 -48,-6.9 z" stroke="#000000" stroke-width="5" />
    <path d="m 184,166 c 39,7 57,15 79,18 21,3 -32,37 -46,27 -14,-10 -31,-45 -33,-45 z" fill="#4d4d4d" />
    <path d="m 326,48.6 c 23,35.7 40,52.4 8,51.4 -31,-1.4 -34,-40 -25,-40 8,0 14,-11.4 17,-11.4 z" fill="#808080"  />
    <path d="m 383,94.3 c 23,0 48,-14.3 47,9.7 -1,25 -11,52 -37,30 -26,-21 -12,-38.3 -10,-39.7 z" fill="#808080" />',
  'features' => 
  array (
    'tongued' => 
    array (
      'body' => '<path d="M 239,333 C 91.5,323 84.3,325 42.9,359 15.8,383 50,402 84.3,370 103,357 234,359 253,351 c 18,-7 -9,-15 -14,-18 z" stroke="#000000" stroke-width="5" />',
    ),
    'muzzled' => 
    array (
      'notpresent' => '',
      'body' => '<path d="m 64.3,214 c 34.3,52 79.7,96 81.7,177 2,0 53,15 53,15 0,0 -20,-96 -20,-96 -3,-12 132,-38 158,-46 14,1 33,56 17,153 23,0 7,1 40,0 32,-64 -23,-142 -7,-167 14,-21 26,-20 49,-24 -9,-10 -17,-39 -17,-39 0,0 -36,17 -49,19 -12,-10 -61,-105 -77,-103 -16,1 -27,3 -36,11 -8,9 97,103 70,117 -27,15 -112,50 -153,43 -34,-6 -57,-60 -67,-68 -9.9,-9 -37,10 -42.7,8 z" stroke="#000000" stroke-width="2" />',
    ),
  ),
  'demi' => 'horizontal',

)

?>
