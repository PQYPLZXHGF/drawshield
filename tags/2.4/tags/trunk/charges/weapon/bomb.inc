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

// bomb

$charge = array (
 'patterns' => array (
    '(bomb|grenade)s?',
  ),
  'modifiers' => array (
    array ( 'fired', 'fired', 'feature' ),
   ),

  'height' => 400, 'width' => 300,
   'proper' => rgb('sable'),
 'body' => '
        <path stroke="#2F2F2F" stroke-width="4" d="m 298,251 a 148,148 0 1 1 -296,0 148,148 0 1 1 296,0 z" />
        <path stroke="#2F2F2F" stroke-width="4" d="m 111,107 c 7,-1 72,-6 75,-1 3,5 8,-36.7 0,-36 -7,0.7 -77,-3.6 -78,2.9 -1,6.4 -1,33.1 -1,33.1" />
      ',
      'features' => array (
            'fired' => array ( 'proper' => rgb('gules'),
        'body' => '
        <path stroke="#2F2F2F" stroke-width="4" d="M 121,68.6 C 89.3,37.9 90.7,32.1 81.4,38.6 72.1,45 84.3,50.7 98.6,62.1 113,73.6 121,68.6 121,68.6 z" />
        <path stroke="#2F2F2F" stroke-width="4" d="m 126,69.3 c 15,-19.3 23,-52.2 1,-62.16 -22,-10 2,14.96 -1,26.46 -3,11.4 0,35.7 0,35.7 z" />
        <path stroke="#2F2F2F" stroke-width="4" d="M 136,67.1 C 145,57.9 169,35.7 155,16.4 141,-2.86 164,-5 169,2.14 174,9.29 160,78.6 136,67.1 z" />
        <path stroke="#2F2F2F" stroke-width="4" d="M 163,66.4 C 201,42.9 209,17.1 208,14.3 207,11.4 206,0 193,-0.714 180,-1.43 178,12.9 174,23.6 171,34.3 163,66.4 163,66.4 z" />
        <path stroke="#2F2F2F" stroke-width="4" d="m 175,68.6 c 55,-12.9 69,-35 68,-47.9 -2,-12.84 -17,-22.13 -22,-9.3 -4,12.9 -8,32.2 -20,37.9 -11,5.7 -26,19.3 -26,19.3 z" />
      '),
      ),);
?>
