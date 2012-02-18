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

// heart

$charge = array (

  'patterns' => array (
  '?human hearts?',
  ),
  'modifiers' => array (
    array ( 'flammant', 'flammant', 'feature',    ),
    array ( 'flammant', 'emitting flames of fire', 'feature',    ),
    array ( 'crowned', '?imperially crowned', 'feature',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 121,
  'height' => 125,
  'proper' => '#e21313',
  'body' => '<path d="M 63,14.6 C 63,14.6 29.9,-14.5 8.77,8.79 -19.9,40.3 47.6,123 59.3,124 71,124 135,48.9 118,13.9 112,0.555 80.6,-5.85 63,14.6 z" />',
  'orient_to_ordinary' => true,
  'hflex' => 1.2,
  'wflex' => 1.6,

)

?>
