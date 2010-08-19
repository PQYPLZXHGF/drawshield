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

);

if ( $node != null ) {
  if ( get_mod($node,'pointing') == 'up' ) $node->append_child(make_mod('inverted'));
  if ( ($num = get_mod( $node, 'bundle')) > 0 ) {
    // At present, we ignore the number and just draw 3 of them...
    $charge ['width'] = 293;
    $charge ['height'] = 404;
    $charge ['body'] =
     '<path d="M 9.7,23.2 227,240 221,246 2.6,28.3 9.7,23.2 z" stroke="#000000" stroke-width="2" />
      <path d="m 9.6,27 213.4,213 2,-2" fill="none" stroke="#000000" stroke-width="2" />
      <path d="M 293,32.5 73.7,244 67.9,238 288,25.4 l 5,7.1 z" stroke="#000000" stroke-width="2" />
      <path d="M 289,32.3 73.8,240 l 1.9,2" fill="none" stroke="#000000" stroke-width="2" />
      <path d="m 153,2.84 -1,306.16 -9,0 2,-307.63 8,1.47 z" stroke="#000000" stroke-width="2" />
      <path d="m 151,5.43 -2,300.57 3,0" fill="none" stroke="#000000" stroke-width="2" />';
  $charge ['features'] = array (
    'barbed' => array ( 'body' =>
     '<g stroke="#000000" stroke-width="2"><path d="m 254,214 c 6,36 31,90 36,95 6,5 -56,-34 -86,-33 6,-12 31,-11 39,-7 7,4 -18,-18 -19,-20 5,-5 7,-6 7,-6 l 20,19 3,-48 z" />
      <path d="M 283,302 C 251,254 257,240 257,240" />
      <path d="m 98.9,271 c -35.7,5 -89.71,29 -94.76,34 -5.07,5 34.76,-55 34.36,-85 11.8,6 10.3,31 6.2,39 -4.1,7 18.2,-18 20.2,-19 4.8,5 5.8,7 5.8,7 l -19.2,20 47.4,4 z" />
      <path d="M 11.2,298 C 59.4,267 73.1,273 73.1,273" />
      <path d="m 189,310 c -21,30 -42,85 -42,92 1,8 -15,-63 -37,-84 13,-4 30,14 32,23 2,8 1,-26 1,-28 7,0 9,1 9,1 l 1,28 36,-32 z" />
      <path d="m 147,392 c 12,-56 26,-62 26,-62" /></g>' ),
    'feathered' => array ( 'body' =>
     '<g stroke="#000000" stroke-width="2"><path d="m 37.7,50.7 c 0,0 6.1,-21.9 -0.7,-27.1 -6.8,-5.3 62.7,42.2 41.6,69 C 52.2,67.7 38.2,51.2 37.7,50.7 z"  />
      <path d="m 45.7,33.1 c 1.4,2.3 3.9,11.1 -0.7,18.8"  /> 
      <path d="m 45.7,33.1 c 1.4,2.3 4.8,10.3 -0.7,18.8"  /> 
      <path d="M 51.1,39.2 C 52.6,41.5 56,49.5 50.5,58"  /> 
      <path d="m 57.7,44.1 c 1.4,2.2 4.8,10.1 -0.6,18.7"  /> 
      <path d="m 64.3,51.8 c 1.4,2.3 4.8,10.2 -0.6,18.7"  /> 
      <path d="M 32.7,57.2 C 32.7,57.2 10.5,63 5.3,56.1 0,49.2 47.1,120 74.4,99 49.6,72 33.2,57.7 32.7,57.2 z"  /> 
      <path d="m 14.8,65 c 2.3,1.5 11.1,4.1 19,-0.4"  />
      <path d="m 14.8,65 c 2.3,1.5 10.3,5 19,-0.4"  /> 
      <path d="m 20.9,70.6 c 2.3,1.5 10.3,5 19,-0.4"  /> 
      <path d="m 25.7,77.3 c 2.2,1.4 10.2,5 18.9,-0.4"  /> 
      <path d="m 33.4,84.1 c 2.3,1.4 10.3,4.9 18.9,-0.4"  /> 
      <path d="m 265,59.7 c 0,0 22,6.4 27,-0.2 6,-6.6 -43,61.5 -69,39.8 25,-25.7 42,-39.1 42,-39.6 z"  /> 
      <path d="m 283,67.9 c -3,1.4 -11,3.7 -19,-1"  /> 
      <path d="m 283,67.9 c -3,1.4 -11,4.6 -19,-1"  /> 
      <path d="m 276,73.2 c -2,1.4 -10,4.6 -18,-1"  /> 
      <path d="m 271,79.6 c -2,1.3 -10,4.6 -18,-1"  /> 
      <path d="m 264,86 c -3,1.3 -11,4.5 -19,-1"  /> 
      <path d="m 259,54.6 c 0,0 -6,-22.1 1,-27.1 7,-5.1 -64,40.1 -44,67.5 28,-24 42,-39.9 43,-40.4 z"  /> 
      <path d="m 251,36.7 c -1,2.3 -4,10.9 0,18.8"  /> 
      <path d="m 251,36.7 c -1,2.3 -5,10.1 0,18.8"  /> 
      <path d="m 246,42.6 c -2,2.3 -6,10.1 0,18.9"  /> 
      <path d="m 239,47.2 c -2,2.2 -5,10 0,18.8"  /> 
      <path d="m 232,54.7 c -2,2.3 -5,10.1 0,18.8"  /> 
      <path d="m 153,42 c 0,0 20,-11 19,-19.5 -1,-8.6 14,74.1 -20,77.5 -1,-35.9 1,-57.3 1,-58 z"  /> 
      <path d="M 171,35.3 C 171,38 166,45.8 158,48"  /> 
      <path d="M 171,35.3 C 171,38 167,45.9 158,48"  /> 
      <path d="m 171,43.5 c -1,2.6 -4,10.6 -14,12.7"  /> 
      <path d="m 172,51.5 c -1,2.5 -4,10.6 -14,12.7"  /> 
      <path d="m 171,61.6 c 0,2.6 -4,10.6 -14,12.7"  /> 
      <path d="m 145,43 c 0,0 -19,-11.7 -18,-20.3 1,-8.5 -16,74.5 18,79.3 2,-36.7 0,-58.3 0,-59 z"  /> 
      <path d="m 127,35.7 c 1,2.7 5,10.8 14,13.2"  /> 
      <path d="m 127,35.7 c 1,2.7 4,10.8 14,13.2"  /> 
      <path d="m 128,44 c 0,2.7 3,10.8 13,13.2"  /> 
      <path d="m 126,52.1 c 1,2.5 4,10.7 14,13.1"  /> 
      <path d="m 127,62.3 c 0,2.6 3,10.7 13,13.1"  /> </g>' ),
    );
  }
}

?>
