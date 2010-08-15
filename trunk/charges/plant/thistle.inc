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

// thistle

$charge = array (

  'patterns' => array (
  'thistles?',
  ),
  'modifiers' => array (
    array ( 'slipped', 'slipped', 'feature',    ),
    array ( 'leaved', 'leaved', 'feature',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 392,
  'height' => 448,
  'proper' => '#965578',
  'orient_to_ordinary' => true,
  'hflex' => 1.4,
  'wflex' => 1.2,
  'body' => '<path stroke="#000000" stroke-width="4" d="m 221,142 c -14,-9 47,-43.8 50,-60 4,-16.2 -47,-19.1 -72,-17.7 -24,-1.4 -75,1.5 -72,17.7 4,16.2 65,51 51,60 -8,6 43,13 43,0 z"/>
    <g fill="none" stroke="#000000" stroke-width="4" >
    <path d="M 151.05,79.57 L 165.78,101.68" />
    <path d="M 172.42,77.36 L 176.10,101.68" />
    <path d="M 189.36,76.63 L 188.63,100.21" />
    <path d="M 206.31,76.63 L 199.68,100.94" />
    <path d="M 224.73,78.84 L 215.15,102.42" />
    <path d="M 238,79.57 L 226.21,103.15" />
    <path d="M 257.15,198.94 C 259.36,219.57 252.73,249.78 232.10,252" />
    <path d="M 247.02,200.23 C 249.26,216.99 242.53,241.54 221.60,243.34" />
    <path d="M 237.07,204.27 C 239.38,214.45 232.45,229.36 210.90,230.45" /></g>',
  'features' => 
  array (
    'slipped' => 
    array (
      'proper' => '#149414',
      'body' => '<path stroke="#000000" stroke-width="4"  d="M 202.63,278.52 L 187.89,299.89 L 182.73,326.42 L 190.84,339.68 L 181.26,364.73 L 184.94,387.57 L 179.78,432.52 L 195.26,442.84 L 224,431.05 L 227.68,397.15 L 227.68,381.68 L 214.42,357.36 L 227.68,338.94 L 221.05,321.26 L 226.21,296.21 L 229.89,282.21 L 202.63,278.52 z" />
      <path  stroke="#000000" stroke-width="4"  d="m 199,270 c 7,-2 64,2 68,-58 7,-37 -33,-61 -46,-70 28,-11 -63,-10 -43,0 -13,9 -53,33 -46,70 4,60 61,56 67,58 z" />
      <g fill="none" stroke="#000000" stroke-width="4" >
      <path  d="M 213.68,294.73 C 212.21,299.15 198.21,327.89 198.21,327.89" />
      <path  d="M 210.73,341.15 L 198.21,377.26" />
      <path  d="M 257,199 c 2,21 -4,51 -25,53" />
      <path  d="M 247,200 c 2,17 -4,42 -25,43" />
      <path  d="M 237,204 c 2,10 -5,25 -26,26" />
      <path  d="M 207.78,389.05 L 209.26,420.73" /></g>',
    ),
    'leaved' => 
    array (
      'proper' => '#149414',
      'body' => '<g stroke="#000000" stroke-width="4" >
  <path d="m 177,369 -8,-27 -16,3 -6,-12 -16,-23 -16,9 -48.7,-17 -0.7,19 -17,-6 5.9,43 20.7,10 -14.8,34 25.8,-23 21.8,17 -3,24 33,-25 23,13 21,-23"   />
  <path d="m 232,365 8,-27 16,3 6,-12 16,-23 16,9 49,-17 0,19 17,-6 -5,43 -21,10 15,34 -26,-23 -22,17 3,24 -33,-25 -23,13 -21,-23"   />
  <path d="m 61.9,294 17.7,-15 33.4,9 0,-35 L 92.8,239 111,217 97.3,192 c 0,0 5.7,-8 8.7,-11 3,-3 -10.2,-28 -10.2,-28 L 122,141 92.8,121 c 0,0 -6.6,-34.8 -6.6,-37.7 0,-3 11.8,-17 11.8,-17 L 66.3,22.1 56.7,43.5 65.6,83.3 38.3,100 l 19.9,37 -39.1,3 0.8,74 27.2,25 -34.6,10 -2.93,42 52.33,3 z"   />
  <path d="m 343,296 -18,-15 -33,9 0,-35 20,-14 -18,-22 14,-25 c 0,0 -6,-8 -9,-11 -3,-3 10,-28 10,-28 l -26,-12 29,-20 c 0,0 7,-34.6 7,-37.5 0,-3 -12,-17 -12,-17 l 32,-44.2 9,21.4 -9,39.8 28,16.5 -20,37 39,3 -1,74 -27,25 35,10 2,42 -52,3 z"   />
  </g><g stroke="#000000" stroke-width="4" fill="none" >
  <path d="M 178,382 133,372 102,351 68.5,326"   />
  <path d="m 87.7,323 5.9,20"   />
  <path d="m 124,328 -1,36"   />
  <path d="m 166,354 -19,17"   />
  <path d="M 81.8,372 104,356"   />
  <path d="m 118,391 9,-20"   />
  <path d="m 231,378 45,-10 31,-21 34,-25"   />
  <path d="m 321,319 -6,20"   />
  <path d="m 285,324 1,36"   />
  <path d="m 243,350 19,17"   />
  <path d="M 327,368 305,352"   />
  <path d="m 291,387 -9,-20"   />
  <path d="M 63.4,290 67,219 66.3,170 74.4,113 75.2,59.7"   />
  <path d="m 35.4,149 32.4,22"   />
  <path d="M 27.3,194 67,219"   />
  <path d="M 23.6,279 64.8,248"   />
  <path d="M 103,273 67.8,241"   />
  <path d="m 66.3,230 28,-16"   />
  <path d="M 67.8,195 94.3,175"   />
  <path d="m 74.4,133 24.3,6"   />
  <path d="M 72.9,115 50.1,102"   />
  <path d="m 65.6,39 9.6,19.9 17.6,7.4"   />
  <path d="m 342,292 -4,-71 1,-49 -8,-57 -1,-53.1"   />
  <path d="m 370,151 -33,22"   />
  <path d="m 378,196 -40,25"   />
  <path d="M 381,281 340,250"   />
  <path d="m 302,275 35,-32"   />
  <path d="M 339,232 311,216"   />
  <path d="M 337,197 311,177"   />
  <path d="m 331,135 -25,6"   />
  <path d="m 332,117 23,-13"   />
  <path d="m 339,41.2 -9,19.9 -18,7.4"   /></g>',
    ),
  ),

)

?>
