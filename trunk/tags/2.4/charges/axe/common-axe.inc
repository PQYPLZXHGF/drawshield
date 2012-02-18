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

// common-axe

$charge = array (

  'patterns' => array (
  '?common axes?',
  'hatchets?',
  ),
  
  'modifiers' => array (
    array ( 'handle', 'handled?s?', 'feature' ),
    array ( 'blade', 'bladed?s?', 'feature' ),
    ),

  'doc' => 'Stuff...',

  'height' => 80,
  'width' => 46,
  'orient_to_ordinary' => true,
  'hflex' => 1.4,
  'wflex' => 1.2,
  'body' => '<g />',
  'features' => 
  array (
    'handle' => 
    array (
      'body' => '<path  stroke="#000000" stroke-width="1" d="M 35.54,9.643 C 33.4,31.61 36.07,50.36 35.54,61.61 30.36,67.5 26.43,75.53 30,79.11 33.57,82.68 44.11,76.07 45.18,70.54 46.07,42.86 43.03,29.29 44.65,10.35 40.71,4.286 38.57,7.143 35.54,9.643 z" />
    <g stroke="#000000" stroke-width="1" fill="none" >
    <path  d="m 42.5,10.71 c 0.18,7.68 1.79,57.5 0.72,59.64 -1.07,2.15 -5.72,5.54 -5.72,5.54"  />
    </g>',
    ),
    'blade' => 
    array (
      'body' => '<path stroke="#000000" stroke-width="1" d="M 45.71,11.61 35.18,11.25 c 0,0 -25.08,0.87 -26.787,-10.7142 C 1.429,1.607 -0.8929,26.61 6.964,36.43 22.32,27.5 17.68,26.43 34.82,23.57 c 0,0 10.72,-0.89 10.72,-0.89 l 0.17,-11.07 z" /> 
           <path stroke="#000000" stroke-width="1" d="m 33.93,11.43 0,12.32" />',
    ),
  ),

)

?>
