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

// pick-axe

$charge = array (

  'patterns' => array (
  'pick axes?',
  'hews?',
  'miners axes?',
  ),

  'modifiers' => array (
    array ( 'handle', 'handled?s?', 'feature' ),
    array ( 'blade', 'bladed?s?', 'feature' ),
    ),

  'doc' => 'Stuff...',

  'height' => 150,
  'width' => 200,
  'orient_to_ordinary' => true,
  'hflex' => 1.4,
  'wflex' => 1.2,
  'body' => '<g />',
  'features' => 
  array (
    'handle' => 
    array (
      'body' => '<path  stroke="#000000" stroke-width="3" d="m 156.3,3.4 c 7.2,-4.25 2.8,-5.5 14.2,-0.75 2.6,18.2 4.8,142.15 0.9,143.05 -4,0.9 -16.4,4.8 -15.9,-1.8 0.4,-6.5 0.8,-140.5 0.8,-140.5 z" />
    <g stroke="#000000" stroke-width="3" fill="none" >
    <path  d="M 167,4.35 m 0,0 c 5,76.9 4.7,148.75 3,137.05"  />
    </g>',
    ),
    'blade' => 
    array (
      'body' => '<path stroke="#000000" stroke-width="3" d="M 2.1,90.45 c 51.3,-44.35 172.7,-74.8 194.5,-77.8 2.1,13 -1.8,32.15 0.8,29.55 0,0 -128.35,14.75 -195.3,48.25 z" />    <g stroke="#000000" stroke-width="3" fill="none" >
    		<path  d="m 1.3,90 m 0,0 C 76.4,50.7 185.6,37.9 196.1,37"  />
    		</g>',
    ),
  ),

)

?>
