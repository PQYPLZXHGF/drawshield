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

// sun

$charge = array (

  'patterns' => array (
  'suns?',
  ),

  'modifiers' => array (
    array ( null, '?in ?his glory', 'ignore'  ),
    array ( null, 'in ?his splendou?r', 'ignore'  ),
  ),

  'doc' => 'Stuff...',

  'proper' => rgb('or'),

  'width' => 400,
  'height' => 400,

  'body' => '<g onmouseover="window.sunwink(\'visible\')" onmouseout="window.sunwink(\'hidden\')" >
      <path stroke="inherit" stroke-width="4" d="m 203,2 16,116 C 252,89.3 266,45.4 265,12.1 303,45.4 253,111 239,129 236,134 340,64.6 340,64.6 L 274,158 c 23,-13 69,-11 102,-47 -8,61 -78,41 -88,80 l 112,14 -116,19 c 48,15 61,47 102,46 -27,30 -88,-27 -108,-23 l 63,96 -84,-70 c -5,20 -2,58 37,107 -81,-28 -46,-85 -71,-88 -1,12 -19,109 -19,109 L 187,293 c -29,29 -37,44 -44,97 -26,-69 20,-95 7,-112 L 60.6,346 123,259 C 70.7,273 68.7,253 21.2,290 42.5,243 90.4,240 107,223 L -4.04,207 112,182 C 61.5,165 60.6,137 8.08,140 38.4,111 72.6,136 121,162 134,169 58.6,58.6 58.6,58.6 L 149,128 C 150,65.7 141,37.9 112,23.2 155,2.03 178,84.1 182,116 188,117 203,2 203,2 z" />
      <path stroke="inherit" stroke-width="3" d="m 288,205 c 0,50 -40,90 -90,90 -50,0 -90,-40 -90,-90 0,-50 40,-90 90,-90 50,0 90,40 90,90 z" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 131,167 c 20,-9 37,-13 52,-5 15,9 10,41 3,41 -7,0 -16,-4 -17,5 0,10 10,10 20,12 4,1 21,-1 21,-1 0,0 22,0 21,-8 -3,-19 -14,2 -19,-16 -1,-6 -4,-26 -1,-28 4,-2 39,-23 67,5" />
      <path fill="#ffffff" stroke="inherit" stroke-width="3" d="m 130,183 c 16,-4 9,-14 27,-14 18,0 24,14 24,14 0,0 -16,3 -22,3 -14,0 11,0 -29,-3 z" />
      <path fill="#ffffff" stroke="inherit" stroke-width="3" d="m 269,183 c -16,-4 -9,-14 -27,-14 -18,0 -24,14 -24,14 0,0 16,3 22,3 14,0 -11,0 29,-3 z" />
      <path fill="#000000" stroke="inherit" stroke-width="3" d="m 161,178 c 0,2 -2,4 -4,4 -2,0 -4,-2 -4,-4 0,-2 2,-4 4,-4 2,0 4,2 4,4 z" />
      <path fill="#000000" stroke="inherit" stroke-width="3" d="m 243,178 c 0,2 -2,4 -4,4 -2,0 -4,-2 -4,-4 0,-2 2,-4 4,-4 2,0 4,2 4,4 z" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 161,238 c 19,-1 19,0 19,0 3,-6 39,-8 48,-1 5,1 15,1 15,1 l -19,3 -39,1 -10,-1 c 0,0 11,15 25,14 11,-1 28,2 28,-15" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 103,205 -60.9,0" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 133,274 -32,30" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 205,300 -1,55" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 272,267 30,33" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 293,208 43,-3" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 265,134 30,-28" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 203,62.8 0,39.2" />
      <path fill="none" stroke="inherit" stroke-width="3" d="M 98.9,100 130,130" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 140,39 c 17,20.8 24,43.8 27,72" />
      <path fill="none" stroke="inherit" stroke-width="3" d="M 267,53.6 C 258,96.9 236,112 236,112 l 0,0" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 290,166 c 14,-20 57,-19 59,-21 1,-2 1,-4 1,-4" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 289,236 c 13,4 45,25 45,25" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 244,295 c 3,18 4,48 13,51 8,4 8,4 8,4 l 0,0" />
      <path fill="none" stroke="inherit" stroke-width="3" d="m 107,244 c -15,-2 -39.6,6 -44.2,10" />
      <path fill="none" stroke="inherit" stroke-width="3" d="M 103,166 C 87.4,150 59.8,139 53.6,136" />
      <path class="sun-wink" visibility="hidden" stroke="inherit" stroke-width="3" d="m 130,183 c 16,-4 9,-14 27,-14 18,0 24,14 24,14 0,0 -16,3 -22,3 -14,0 11,0 -29,-3 z" />
      </g>',

);

if ( $node != null ) {
  scripts('add','window.sunwink = function(arg) {
    var suns = document.getElementsByClassName("sun-wink");
    for (var i = 0; i < suns.length; i++) suns[i].setAttribute("visibility", arg);
    }', 'sunwink'  );
  if ( get_mod($node, 'on')) {
  $charge['body'] = '<path
       d="m 203,2 15,121 C 251,94.7 266,45.4 265,12.1 303,45.4 253,111 239,129 236,134 340,64.6 340,64.6 L 274,158 c 23,-13 69,-11 102,-47 -8,61 -78,41 -88,80 l 112,14 -116,19 c 48,15 61,47 102,46 -27,30 -88,-27 -108,-23 l 63,96 -89,-71 c -5,20 3,59 42,108 -81,-28 -44,-91 -69,-94 -1,12 -21,115 -21,115 L 186,286 c -29,29 -36,51 -43,104 -26,-69 25,-102 12,-119 L 60.6,346 127,257 C 74.5,271 68.7,253 21.2,290 42.5,243 95.8,249 112,232 L -4.04,207 112,182 C 61.5,165 60.6,137 8.08,140 38.4,111 72.6,136 121,162 134,169 58.6,58.6 58.6,58.6 L 154,130 C 155,68 141,37.9 112,23.2 155,2.03 177,88.7 181,121 187,122 203,2 203,2 z"
       stroke="inherit" stroke-width="4" />';
  }
}

?>