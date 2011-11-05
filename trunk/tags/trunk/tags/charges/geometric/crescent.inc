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

// crescent

$charge = array (

  'patterns' => array (
  'crescents?',
  ),
  'modifiers' => array (
    array ( NULL, 'pendent', 'mod', 'inverted',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 400,
  'height' => 400,
  'wflex' => 2,
  'hflex' => 2,
  'body' => '<path stroke="#000000" stroke-width="6" d="M 400,200 C 400,310 310,400 200,400 90,400 0,310 0,200 0,150 71,9.9 130,8.8 46,110 150,150 200,150 260,150 350,94 270,8.8 340,11 400,140 400,200" />
                   <path stroke="#000000" stroke-width="6" fill="none" d="M 130,8.8 C 71,9.9 28,130 50,200 c 18,60 90,90 150,90 60,0 130,-40 150,-90 C 370,130 340,11 270,8.8" />',
  'orient_to_ordinary' => true,

)

?>
