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

// arrow

$charge = array (

  'patterns' => array (
  'arrows?',
  ),
  'modifiers' => array (
    array ( 'barbed', 'barbed|armed', 'feature',    ),
    array ( 'feathered', '(flighted|feathered)', 'feature',    ),
    array ( 'up', 'points? upwards?', 'mod', 'pointing',    ),
    array ( 'down', 'points? downwards?', 'mod', 'pointing',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 80,
  'height' => 404,
  'body' => '<path d="M 43,2.84 42,309 33,309 35,1.37 43,2.84 z" stroke="#000000" stroke-width="2" />
      <path d="M 41,5.43 39,306 l 3,0"  fill="none" stroke="#000000" stroke-width="2" />',
  'features' => 
  array (
    'barbed' => 
    array (
      'body' => '<path d="m 79,310 c -21,30 -42,85 -42,92 1,8 -15,-63 -37,-84 13,-4 30,14 32,23 2,8 1,-26 1,-28 7,0 9,1 9,1 l 1,28 36,-32 z"  stroke="#000000" stroke-width="2" />
    <path d="M 37,392 C 49,336 63,330 63,330"  fill="none" stroke="#000000" stroke-width="2" />',
    ),
    'feathered' => 
    array (
      'body' => '<g stroke="#000000" stroke-width="2"><path d="M 43,42 C 43,42 63,31 62,22.5 61,13.9 76,96.6 42,100 41,64.1 43,42.7 43,42 z"   />
      <path d="M 61,35.3 C 61,38 56,45.8 48,48"   />
      <path d="M 61,35.3 C 61,38 57,45.9 48,48"   />
      <path d="M 61,43.5 C 60,46.1 57,54.1 47,56.2"   />
      <path d="M 62,51.5 C 61,54 58,62.1 48,64.2"   />
      <path d="m 61,61.6 c 0,2.6 -4,10.6 -14,12.7"   />
      <path d="M 35,43 C 35,43 16,31.3 17,22.7 18,14.2 1,97.2 35,102 37,65.3 35,43.7 35,43 z"   />
      <path d="m 17,35.7 c 1,2.7 5,10.8 14,13.2"   />
      <path d="m 17,35.7 c 1,2.7 4,10.8 14,13.2"   />
      <path d="m 18,44 c 0,2.7 3,10.8 13,13.2"   />
      <path d="m 16,52.1 c 1,2.5 4,10.7 14,13.1"   />
      <path d="m 17,62.3 c 0,2.6 3,10.7 13,13.1"   /></g>',
    ),
  ),
  'orient_to_ordinary' => true,

)

?>
