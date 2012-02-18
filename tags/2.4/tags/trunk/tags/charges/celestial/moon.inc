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

// moon

$charge = array (

  'patterns' => array (
  '?full moons?',
  'increscents?',
  'decrescents?',
  'crescents?'
  ),
  
  'proper' => rgb('argent'),

  'modifiers' => array (
    array ( null, 'in her complement', 'ignore'  ),
    array ( null, 'in plenitude', 'ignore'  ),
    array ( 'tochief', 'crescent', 'mod', 'direction' ),
    array ( 'todexter', 'increscent', 'mod', 'direction' ),
    array ( 'todexter', 'in increment', 'mod', 'direction' ),
    array ( 'tosinister', 'decrescent', 'mod', 'direction' ),
    array ( 'tobase', 'pendent', 'mod', 'direction' ),
  ), 
  
  'doc' => 'Stuff...',
);

if ( $node == null ) {
  $charge['width'] = 400;
  $charge['height'] = 360;
  $body = '<g>
    <path stroke="inherit" stroke-width="4"
       d="M 337,704 C 249,608 20,639 2,851 24,1080 270,1080 337,997 48,1080 44,633 337,704 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 337,705 C -51,552 -27,1150 338,999" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="m 161,688 c 64,-23 172,12 172,12 C 229,606 169,678 161,688 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="m 324,999 c -1,11 -102,51 -192,-1 -5,-11 -14,-28 -3,-84 67,136 195,85 195,85 z" />
  </g>';
} else {
  $data = array ( 
  'todexter' => array ( 360, 400, '<g>
    <path stroke="inherit" stroke-width="4"
       d="M 0.99,350 C 88.9,446 318,414 336,202 314,-31 67.7,-31 0.99,56 290,-26 294,420 0.99,350 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 0.99,349 C 389,501 365,-100 -0.02,54" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="M 177,365 C 113,388 4.61,353 4.61,353 109,447 169,375 177,365 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="M 14.3,54 C 15.3,43 116,6 206,55 c 5,11 14,28 3,84 C 142,3 14.3,54 14.3,54 z" />
  </g>'),
  
  'tosinister' => array ( 360, 400, '<g>
    <path stroke="inherit" stroke-width="4"
       d="M 335,52.6 C 247,-43.4 18,-12.1 0,200 22,433 268,433 335,346 46,428 42,-17.6 335,52.6 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 335,53.6 C -53,-98.9 -29,502 336,348" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="M 159,37.5 C 223,13.9 331,49.1 331,49.1 227,-45.1 167,27.5 159,37.5 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="m 322,348 c -1,11 -102,48 -192,-1 -5,-11 -14,-28 -3,-84 67,136 195,85 195,85 z" />
  </g>' ),
  
  'tochief' => array ( 400, 360,  '<g>
    <path stroke="inherit" stroke-width="4"
       d="M 51.5,0.99 C -44.5,88.9 -13.2,318 199,336 432,314 432,67.7 345,0.99 427,290 -18.7,294 51.5,0.99 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 52.5,0.99 C -100,389 501,365 347,-0.02" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="M 36.4,177 C 12.8,113 48,4.61 48,4.61 -46.2,109 26.4,169 36.4,177 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="m 347,14.3 c 11,1 48,101.7 -1,191.7 -11,5 -28,14 -84,3 136,-67 85,-194.7 85,-194.7 z" />
  </g>'),

    'tobase' => array ( 400, 360,  '<g>
    <path stroke="inherit" stroke-width="4"
       d="M 51.5,335 C -44.5,247 -13.2,18 199,0 432,22 432,268 345,335 427,46 -18.7,42 51.5,335 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 52.5,335 C -100,-53 501,-29 347,336" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="M 36.4,159 C 12.8,223 48,331 48,331 -46.2,227 26.4,167 36.4,159 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="none"
       d="m 347,322 c 11,-1 48,-102 -1,-192 -11,-5 -28,-14 -84,-3 136,67 85,195 85,195 z" />
  </g>'),
    'fullmoon' => array ( 400, 400, '<g>
    <path stroke="inherit" stroke-width="4"
       d="m 398,200 a 199,200 0 1 1 -398,0 199,200 0 1 1 398,0 z" />
    <path fill="#000000" fill-opacity="0.413" stroke="inherit"  stroke-width="2"
       d="m 381,282 c -13,18 -199,136 -261,45 4,-15 30,-7 30,-22 -11,-14 -41,17 -65.7,-15 -25,-32 15.7,-17 30.7,-23 15,-5 -1,-21 -1,-31 0,-9 30,8 37,-18 C 158,191 98.6,161 99.3,149 100,137 128,117 129,100 131,82.9 133,25 259,12.9 208,-15 35,-6 -2.86,189 -0.714,218 3.86,358 163,397 320,419 381,282 381,282 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="m 135,317 c -21,9 -29,13 -54.2,-2" />
    <path fill="#000000" stroke="inherit" stroke-width="4"
       d="m 76.5,267 c 41.5,2 43.5,0 33.5,9 -38.6,19 -33.5,-9 -33.5,-9 z" />
    <path fill="#000000" stroke="inherit" stroke-width="4"
       d="m 123,229 a 5.36,3.93 0 1 1 -10,0 5.36,3.93 0 1 1 10,0 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="M 116,224 C 90,236 97.9,238 87.9,237 77.9,236 58.6,209 71.4,199" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="m 50,114 c 30.7,-13 35,-15.4 40.7,-8 5.7,8 -40.7,8 -40.7,8 z" />
    <path fill="none" stroke="inherit" stroke-width="4"
       d="m 38.6,155 c 30,-15 30,-15 30,-15 l -10.7,6 c 0,0 11.4,-1 7.1,8 -4.3,10 8.6,7 8.6,7 z"/>
    <path fill="none" stroke="inherit" stroke-width="4"
       d="m 61.4,154 a 1.79,2.5 0 1 1 -3.6,0 1.79,2.5 0 1 1 3.6,0 z" />
  </g>')
  );
  
  // Are we given an explicit direction?
  if ( ($direction = get_mod($node, 'direction')) == null ) {
    // Can we work it out from the actual charge used?
    $tokens = $node->getAttribute('tokens');
    //Careful of order, 'crescent' is in 'decrescent'!
    if ( strpos($tokens,'moon') !== false  ) $direction = 'fullmoon';
    elseif ( strpos($tokens,'increment') !== false ) $direction = 'todexter';
    elseif ( strpos($tokens,'increscent') !== false ) $direction = 'todexter';
    elseif ( strpos($tokens,'decrescent') !== false ) $direction = 'tosinister';
    else $direction = 'tochief';
  }
  $charge['width'] = $data[$direction][0];
  $charge['height'] = $data[$direction][1];
  $charge['body'] = $data[$direction][2];
  
}

?>