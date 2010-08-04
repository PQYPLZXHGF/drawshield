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


function makeChg_misc ( $node ) {
  $misc_data = array (
    'flames' => array ( 'width' => 121, 'height' => 70, 'proper' => '#e21313',
        'body' => '<path stroke="black" stroke-width="2" d="m 42.8,66.8 46.8,0.4 C 89.6,67.2 106,49.8 107,40.1 109,30.8 95.3,33.3 98.1,17 90.5,11.1 93.2,46.9 92.7,50.5 91.6,58.4 81.4,18.4 82.8,6.79 73.3,14.4 79.1,41.5 73.6,31.8 68.2,22 57.7,11.9 61.5,4.52 50.4,7.05 66.2,25.9 60,31 53.8,36.1 41.3,9.2 37.4,9.2 c -2.7,5 2.3,22.6 -1.2,28 -3.5,5.5 -7,-8.2 -13.6,-9.3 -0.8,5.1 19.5,38.6 20.2,38.9 z" />
                <path stroke="black" stroke-width="2" fill="none" d="m 37.5,38.6 c 5.1,13.3 15.8,25.8 15.8,25.8" />
                <path stroke="black" stroke-width="2" fill="#efd807" d="m 56.3,65 31.8,0.2 c 0,0 0.6,-9.7 0.9,-11.9 0.4,-2.2 -6.3,-4.2 -6.2,-10.7 2.5,-10.9 -7,14.7 -8.6,3.6 -1.6,-11.1 -10.8,-18 -10.8,-18 0,0 4,10.5 2.5,14.9 C 64.4,47.4 46.6,26 48.6,36.5 50,33.1 60.5,48.8 61.9,53.9 63.4,59.1 56.5,65.2 56.3,65 z" />
                <path stroke="black" stroke-width="2" fill="none" d="m 72.3,57 c -1.4,0.4 -8.3,2.6 -8.3,2.6 0,0 -1.4,2.8 -1.1,2.7 0.4,0 21.4,0 21.4,0" />',
        'orient_to_ordinary' => false, 'hflex' => 2.0, 'wflex' => 2.0, ),
    'rainbow' => array ( 'width' => 500, 'height' => 200, 'turn_on_fesswise' => false, 'turn_on_palewise' => false, 'orient_to_ordinary' => false,
        'body' => '<path fill="#efd807" d="M 0.732,200 C 0.732,200 88.6,-0.741 250,0.732 411,2.2 503,200 503,200 l -52,0 C 451,200 340,27.8 250,27.8 158,27.8 52.4,200 52.4,200 l -51.668,0 z" />
                   <path fill="#e21313" d="M 51,200 C 51,200 127,27.8 250,27.1 372,26.3 453,200 453,200 l -52,0 C 401,200 330,56.3 250,57.8 169,59.3 103,200 103,200 l -52,0 z" />
                   <path fill="#149414" d="M 101,200 C 101,200 165,57.9 250,57.1 334,56.3 402,200 402,200 l -52,0 C 350,200 305,87 250,87.8 194,88.6 153,200 153,200 l -52,0 z" />
                   <path fill="#fofofo" d="M 152,200 C 152,200 182,87.9 250,87.1 317,86.3 352,200 352,200 l -52,0 c 0,0 -3,-82 -50,-82 -46,0 -46,82 -46,82 l -52,0 z" />',
        'hflex' => 999, 'wflex' => 999, ),
  );
  $type = $node->get_attribute('subtype');
  $retval = null;
  if ( array_key_exists($type,$misc_data) ) $retval = $misc_data[$type];
  return $retval;
}
?>
