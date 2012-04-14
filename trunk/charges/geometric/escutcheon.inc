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

// escutcheon

$charge = array (

  'patterns' => array (
  'escut?cheons?',
  ),
  'modifiers' => array (
    array ( null, 'of pretence', 'ignore',    ),
    array ('subshield', 'of !pretence', 'shieldmod', ),
  ),

  'doc' => 'Stuff...',

  'width' => 600,
  'height' => 800,
  'body' => '<path d="m 0,0 600,0 0,600 c 1,22 -5,45 -18,67 -14,21 -35,41 -62,59 -27,18 -60,34 -97,47 -38,12 -79,21 -123,27 C 256,794 215,785 177,773 140,760 107,744 79.8,726 52.8,708 31.9,688 18.4,667 4.82,645 -1.42,622 0,600 L 0,0 z" />',
  'orient_to_ordinary' => true,

)

?>
