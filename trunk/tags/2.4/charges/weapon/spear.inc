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
    'spears?',
  ),
  'modifiers' => array (
    array ( 'hafted', 'hafted', 'feature' ),
    array ( 'point', '?the (point|head)s? ?steeled', 'feature' ),
    array ( 'point', '(pointed|headed)', 'feature' ),
   ),

   'orient_to_ordinary' => -1,
   
  'height' => 400, 'width' => 50,
   'body' => '<g />',
   'proper' => rgb('or'), // Not used
    'features' => array (
            'hafted' => array ( 'proper' => rgb('dark goldenrod'),
        'body' => '
        <path stroke="#696969" stroke-width="2" d="m 24.3,80.7 c -3.6,7.9 0,319.3 0,319.3 l 16.4,0 -4.3,-319.3 z" />
        <path stroke="#696969" stroke-width="2" d="m 27.1,85 1.5,309" />
      '),
           'point' => array ( 'proper' => rgb('light steel blue'),
    'body' => '
      <path stroke="#696969" stroke-width="2" d="M 30,0.714 12.9,52.9 l 7.8,27.8 18.6,0 7.1,-30.7 z" />
      <path stroke="#696969" stroke-width="2" d="m 30.7,4.29 0,73.61" />
      <path stroke="#696969" stroke-width="2" d="M 26.4,80 20.7,50.7 30,5.71" />
      <path stroke="#696969" stroke-width="2" d="M 35,80.7 37.9,51.4 30,9.29" />
      ',
      ),
     ),
     
);
?>
