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


function makeChg_heart ( $node ) {
  $heart_data = array (
    'heart' => array ( 'width' => 121, 'height' => 125, 'proper' => '#e21313',
      'body' => '<path d="M 63,14.6 C 63,14.6 29.9,-14.5 8.77,8.79 -19.9,40.3 47.6,123 59.3,124 71,124 135,48.9 118,13.9 112,0.555 80.6,-5.85 63,14.6 z" />', 
      'orient_to_ordinary' => true, 'hflex' => 1.2, 'wflex' => 1.6, ),
    'heart-crowned' => array ( 'width' => 121, 'height' => 206, 'proper' => '#e21313',
        'body' => '<path d="M 63,14.6 C 63,14.6 29.9,-14.5 8.77,8.79 -19.9,40.3 47.6,123 59.3,124 71,124 135,48.9 118,13.9 112,0.555 80.6,-5.85 63,14.6 z" />
                <path stroke="black" stroke-width="2" fill="#efd807" d="M 13.5,81.1 100,81.7 121,58.8 C 115,49.9 94.3,33 64.2,25.5 c -0.1,-0.3 0,-13.8 0,-13.8 l 7,0.1 0.2,-5.75 -6.4,-0.16 0,-4.3 -5.7,0 0,4.14 -7.2,0 0,5.77 7.3,0 0,14.3 C 54.3,24.8 7.8,43.5 4.94,54.3 8.12,61.6 13.4,81.5 13.5,81.1 z" />
                <path stroke="black" stroke-width="2" fill="#e21313" d="m 106,55.9 -6,19.4 -14.5,0.4 0,-7.1 6.2,0 0,-4.3 -6.3,0 0,-6.6 -6.3,0 0,7 -6.2,0 0,4.4 6.9,0 0,6.9 -15,0 0,-41.1 c 0,0 39.2,16.1 41.2,21 z" />
                <path stroke="black" stroke-width="2" fill="#e21313" d="m 14.8,55.9 6.5,19.4 14.4,0.4 0,-7.1 -6.2,0 0,-4.3 6.3,0 0,-6.6 6.3,0 0,7 6.2,0 0,4.4 -6.9,0 0,6.9 15,0 0,-41.1 c 0,0 -39.5,16.1 -41.6,21 z" />',
        'orient_to_ordinary' => true, 'hflex' => 1.2, 'wflex' => 1.6, ),
    'heart-flammant' => array ( 'width' => 121, 'height' => 206, 'proper' => '#e21313',
        'body' => '<path d="M 63,34.6 C 63,34.6 29.9,5.5 8.77,28.8 -19.9,60.3 47.6,143 59.3,144 71,144 135,68.9 118,33.9 112,20.6 80.6,14.1 63,34.6 z" />
                <path stroke="black" stroke-width="2" fill="#ff0000" d="m 42.8,66.8 46.8,0.4 C 89.6,67.2 106,49.8 107,40.1 109,30.8 95.3,33.3 98.1,17 90.5,11.1 93.2,46.9 92.7,50.5 91.6,58.4 81.4,18.4 82.8,6.79 73.3,14.4 79.1,41.5 73.6,31.8 68.2,22 57.7,11.9 61.5,4.52 50.4,7.05 66.2,25.9 60,31 53.8,36.1 41.3,9.2 37.4,9.2 c -2.7,5 2.3,22.6 -1.2,28 -3.5,5.5 -7,-8.2 -13.6,-9.3 -0.8,5.1 19.5,38.6 20.2,38.9 z" />
                <path stroke="black" stroke-width="2" fill="none" d="m 37.5,38.6 c 5.1,13.3 15.8,25.8 15.8,25.8" />
                <path stroke="black" stroke-width="2" fill="#efd807" d="m 56.3,65 31.8,0.2 c 0,0 0.6,-9.7 0.9,-11.9 0.4,-2.2 -6.3,-4.2 -6.2,-10.7 2.5,-10.9 -7,14.7 -8.6,3.6 -1.6,-11.1 -10.8,-18 -10.8,-18 0,0 4,10.5 2.5,14.9 C 64.4,47.4 46.6,26 48.6,36.5 50,33.1 60.5,48.8 61.9,53.9 63.4,59.1 56.5,65.2 56.3,65 z" />
                <path stroke="black" stroke-width="2" fill="none" d="m 72.3,57 c -1.4,0.4 -8.3,2.6 -8.3,2.6 0,0 -1.4,2.8 -1.1,2.7 0.4,0 21.4,0 21.4,0" />',
        'orient_to_ordinary' => true, 'hflex' => 1.2, 'wflex' => 1.6, ),
  );
  $type = $node->get_attribute('subtype');
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->node_name() == 'modifier' ) {
      switch ($child->get_attribute('name')) {
        case 'flammant': 
          $type .= '_flammant';
          break;
        case 'crowned':
          $type .= '_flammant';
          break;
      }
    }
  }
  if ( isset($heart_data[$type]) ) {
    return $heart_data[$type]; 
  } else {
    my_trigger_error ( "No heart $type", E_USER_WARNING, __FILE__, __LINE__ );
    return array( 'body' => '<g/>', 'width' => 10, 'height' => 10 );
  }
}
?>
