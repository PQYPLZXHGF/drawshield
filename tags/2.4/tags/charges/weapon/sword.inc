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

// sword

$charge = array (

  'patterns' => array (
  'swords?',
  ),
  'modifiers' => array (
    array ( 'hilt', '(hilts?|hilted)', 'feature',    ),
    array ( 'pommell', '(pom?mell?s?|pomm?ell?ed)', 'feature',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 146,
  'height' => 425.77347,
  'proper' => '#F0F0F0',
  'body' => '<path d="m 76.6,14 -11,24 0,232 20,0 -1,-229 -8,-27 z" stroke="#000000" stroke-width="2" /><path d="m 74.6,40 0,227" fill="none" stroke="#000000" stroke-width="2" />',
  'features' => 
  array (
    'pommell' => 
    array (
      'proper' => '#EFD807',
      'body' => '<path d="m 102,408 a 25.7,16.8 0 1 1 -51,0 25.7,16.8 0 1 1 51,0 z"  stroke="#000000" stroke-width="2" />
          <path d="m 91.3,399 c 8.2,3 7.5,17 -2,15" fill="none" stroke="#000000" stroke-width="2" />
          <path d="m 59.8,294 28.3,1 4.4,100 -35,2 2.3,-103 z" stroke="#000000" stroke-width="2" />
          <g fill="none" stroke="#000000" stroke-width="2"><path d="m 63.2,302 c 0,0 7.5,6 20.3,2"  />
          <path d="m 63.8,310 c 0,0 7.3,6 20.2,2"                     />
          <path d="m 64,319 c 0,0 7.3,6 20.1,2"                       />
          <path d="m 63.6,326 c 0,0 7.3,6 20.2,2"                     />
          <path d="m 63.1,336 c 0,0 7.4,6 20.1,2"                     />
          <path d="m 63.1,346 c 0,0 2.6,3 7.6,3 3.3,1 7.5,1 12.5,-1"  />
          <path d="m 63.4,356 c 0,0 2.7,2 7.6,3 3.3,0 7.5,0 12.6,-1"  />
          <path d="m 63.8,365 c 0,0 2.7,2 7.6,3 3.3,1 7.5,1 12.6,-1"  />
          <path d="m 63.8,377 c 0,0 2.7,2 7.6,3 3.3,0 7.5,0 12.6,-2"  /></g>',
    ),
    'hilt' => 
    array (
      'proper' => '#EFD807',
      'body' => '<path d="m 98.3,281 -3.1,9 c 0,0 20.8,4 30.8,-5 6,-5 4,-24 -4,-28 -7,-4 -17,0 -16,8 0,5 11,6 13,9 3,6 -19.7,7 -20.7,7 z"  stroke="#000000" stroke-width="2" />
          <path d="m 98.5,283 a 23.5,14.8 0 0 1 -47,0 23.5,14.8 0 1 1 47,0 z"  stroke="#000000" stroke-width="2" />
          <path d="m 51.3,280 3.1,10 c 0,0 -20.3,4 -29.8,-5 -6,-5 -4.3,-25 3.5,-29 7.2,-4 16.9,0 16.2,9 -0.4,5 -10.7,5 -13.2,9 -3.1,6 19.2,6 20.2,6 z"  stroke="#000000" stroke-width="2" />
          <path d="m 86,283 a 10,6.67 0 0 1 -20,0 10,6.67 0 1 1 20,0 z" stroke="#000000" stroke-width="2" />',
    ),
  ),
  'orient_to_ordinary' => true,

)

?>
