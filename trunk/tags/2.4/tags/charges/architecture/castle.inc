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

// castle

$charge = array (
 'patterns' => array (
    'castles?',
  ),
  
  'modifiers' => array (
//    array ( 'triple', 'triple towered', 'feature' ), 
    array ( 'triple', 'triple towered', 'ignore' ), 
    ),
 'height' => 400, 'width' => 400,
    'body' => '
      <path stroke="inherit" stroke-width="4" d="m 112,400 58,0 c -1,-74 -1,-76 25,-92 23,10 25,18 26,93 l 70,-1 11,-320.2 -201,0 z" />
      <path stroke="inherit" stroke-width="4" d="M -0.714,400 3.57,295 32.1,53 26.4,35.7 26.4,1.43 111,0.714 111,37.1 104,53 l 22,242 4,106 z" />
      <path stroke="inherit" stroke-width="4" d="m 2.86,295 123.14,0 0,16 -123.14,0 z" />
      <path stroke="inherit" stroke-width="2" d="M 9.29,296 10,311" />
      <path stroke="inherit" stroke-width="2" d="m 17.1,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 24.6,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 32.1,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 39.6,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 46.8,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 53.6,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 61.8,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 70,297 0,13" />
      <path stroke="inherit" stroke-width="2" d="m 77.9,296 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 85.4,296 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 93.2,296 0,16" />
      <path stroke="inherit" stroke-width="2" d="m 101,295 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 109,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 116,296 0,14" />
      <path stroke="inherit" stroke-width="4" d="m 26.4,36.1 83.6,0" />
      <path stroke="inherit" stroke-width="4" d="M 33.6,52.9 104,53.6" />
      <path stroke="inherit" stroke-width="4" d="m 42.1,1.79 0,11.11" />
      <path stroke="inherit" stroke-width="4" d="m 67.1,1.07 0,11.43" />
      <path stroke="inherit" stroke-width="4" d="M 91,1.07 91,11.8" />
      <path stroke="inherit" stroke-width="2" d="M 35.4,37.9 40,52.1" />
      <path stroke="inherit" stroke-width="2" d="m 44.6,36.8 3.3,15.3" />
      <path stroke="inherit" stroke-width="2" d="m 53.3,36.8 2.1,15.3" />
      <path stroke="inherit" stroke-width="2" d="m 62.1,36.4 2.5,16.5" />
      <path stroke="inherit" stroke-width="2" d="M 75.7,35 73.2,52.5" />
      <path stroke="inherit" stroke-width="2" d="M 84.3,37.1 81.1,52.5" />
      <path stroke="inherit" stroke-width="2" d="m 91.8,37.1 -3.6,15" />
      <path stroke="inherit" stroke-width="2" d="m 101,37.5 -6,15" />
      <path fill="#000000" fill-opacity="0.694" stroke="inherit" stroke-width="4" d="m 66.4,106 c 2.8,0 5,2 5,5 l 0,40 c 0,3 -2.2,5 -5,5 -2.8,0 -5,-2 -5,-5 l 0,-40 c 0,-3 2.2,-5 5,-5 z" />
      <path stroke="inherit" stroke-width="4" d="m 271,400 5,-105 28,-242 -6,-17.3 0,-34.27 85,-0.716 0,36.386 -7,15.9 22,242 4,106 z" />
      <path stroke="inherit" stroke-width="4" d="m 275,295 123,0 0,16 -123,0 z" />
      <path stroke="inherit" stroke-width="2" d="m 281,296 1,15" />
      <path stroke="inherit" stroke-width="2" d="m 289,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 297,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 304,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 312,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 319,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 326,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 334,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 342,297 0,13" />
      <path stroke="inherit" stroke-width="2" d="m 350,296 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 357,296 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 365,296 0,16" />
      <path stroke="inherit" stroke-width="2" d="m 373,295 0,15" />
      <path stroke="inherit" stroke-width="2" d="m 381,296 0,14" />
      <path stroke="inherit" stroke-width="2" d="m 388,296 0,14" />
      <path stroke="inherit" stroke-width="4" d="m 298,36.1 84,0" />
      <path stroke="inherit" stroke-width="4" d="m 306,52.9 70,0.7" />
      <path stroke="inherit" stroke-width="4" d="m 314,1.79 0,11.11" />
      <path stroke="inherit" stroke-width="4" d="m 339,1.07 0,11.43" />
      <path stroke="inherit" stroke-width="4" d="m 363,1.07 0,10.73" />
      <path stroke="inherit" stroke-width="2" d="m 307,37.9 5,14.2" />
      <path stroke="inherit" stroke-width="2" d="m 317,36.8 3,15.3" />
      <path stroke="inherit" stroke-width="2" d="m 325,36.8 2,15.3" />
      <path stroke="inherit" stroke-width="2" d="m 334,36.4 3,16.5" />
      <path stroke="inherit" stroke-width="2" d="m 348,35 -3,17.5" />
      <path stroke="inherit" stroke-width="2" d="m 356,37.1 -3,15.4" />
      <path stroke="inherit" stroke-width="2" d="m 364,37.1 -4,15" />
      <path stroke="inherit" stroke-width="2" d="m 373,37.5 -6,15" />
      <path fill="#000000" fill-opacity="0.694" stroke="inherit" stroke-width="4" d="m 338,106 c 3,0 5,2 5,5 l 0,40 c 0,3 -2,5 -5,5 -2,0 -5,-2 -5,-5 l 0,-40 c 0,-3 3,-5 5,-5 z" />
      <path stroke="inherit" stroke-width="4" d="m 110,120 184,0" />
      <path stroke="inherit" stroke-width="4" d="m 110,132 183,0" />
      <path stroke="inherit" stroke-width="4" d="M 145,81.8 145,98" />
      <path stroke="inherit" stroke-width="4" d="M 176,81.8 176,98" />
      <path stroke="inherit" stroke-width="4" d="m 204,81 0,16.5" />
      <path stroke="inherit" stroke-width="4" d="M 233,80.5 233,97" />
      <path stroke="inherit" stroke-width="4" d="m 262,80.5 0,15.9" />
      <path fill="#000000" fill-opacity="0.694" stroke="inherit" stroke-width="4" d="m 240,150 c 3,0 5,2 5,5 l 0,40 c 0,3 -2,5 -5,5 -2,0 -5,-2 -5,-5 l 0,-40 c 0,-3 3,-5 5,-5 z" />
      <path fill="#000000" fill-opacity="0.693" stroke="inherit" stroke-width="4" d="m 160,150 c 3,0 5,2 5,5 l 0,40 c 0,3 -2,5 -5,5 -2,0 -5,-2 -5,-5 l 0,-40 c 0,-3 3,-5 5,-5 z" />
      ',
    );
?>
