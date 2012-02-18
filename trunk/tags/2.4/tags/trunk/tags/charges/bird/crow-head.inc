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

// crow head

$charge = array (

  'patterns' => array (
  '(crow|daw|rook|raven)s? heads?',
  ),
  'modifiers' => array (
    array ( 'beaked', 'beaked', 'feature' ),
  ),
  
  'doc' => 'Stuff...',

  'width' => 108,
  
  'height' => 75,

  'proper' => '#050505',

  'body' => 
       '<path stroke="#404040" stroke-width="2" d="m 37.317,12.097 c 0,0 -1,9 -1,12 3,5 14,1 11,8 23.361,37.667 -26.947,11.283 -2.489,24.911 12.136,6.763 16.949,-4.411 24.949,-2.271 8,2.15 22.56,16.983 12.38,-1.957 -10.177,-18.94 47.343,35.656 11.99,-6.585 5.74,-14.486 -6.82,-22.117 -6.83,-32.098 0,-4 -11,-10.2994 -23,-11.6994 -4,-0.8 -17,-1 -27,9.6994 z" />
       <path fill="#ff0000" stroke="#404040" stroke-width="1" d="m 56.829,17.24 a 5,4.878 0 1 1 -10,0 5,4.878 0 1 1 10,0 z"/>',
   'features' => array (
       'beaked' => array ( 'proper' => '#EC6C00', 'body' =>
   '<path stroke="#404040" stroke-width="1" d="m 37.024,12.098 c 0,0 -32.9996,1 -36.99961,6 -2.99999,5 31.99961,5 34.99961,5 3,-1 3,-11 2,-11 z" />
   <path stroke="#404040" stroke-width="1" fill="none" d="m 38.268,17.854 c 0,0 -31.9997,-1 -35.9997,1" />' ),
   ),
);

?>
