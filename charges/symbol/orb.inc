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

// orb

$charge = array (

  'patterns' => array (
  '?royal (orb|mound)',
  ),
  'modifiers' => array (
    array ( 'banded', 'banded|encircled', 'feature',    ),
    array ( 'crossed', 'crossed/ensigned with a cross', 'feature',    ),
  ),

  'doc' => 'Stuff...',

  'height' => 180,
  'width' => 100,
  'body' => '<circle cx="50" cy="130" r="50" />',
  'features' => 
  array (
    'banded' => 
    array (
      'body' => '<path stroke-width="1" stroke="black" d="M40,130 h20 v-50 h-20 z" />
                                <path stroke-width="1" stroke="black" d="M0,130a50,50 0,0,1 1,-10 h98 a50,50 0,0,1 0,20 h-98 a50,50 0,0,1 -1,-10z" /> ',
    ),
    'crossed' => 
    array (
      'body' => '<path stroke-width="2" stroke="black" d="m40,80h20v-40h20v-20h-20v-20h-20v20h-20v20h20z" />',
    ),
  ),
  'orient_to_ordinary' => true,

)

?>
