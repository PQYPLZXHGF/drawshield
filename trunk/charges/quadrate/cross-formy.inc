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

// cross-formy

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? (formee|pattee)',
  'cross(let|lets|es)? (formy|patt?y)',
  ),
  
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'body' => '<path d="M 310,-1.2 80,3.2 C 80,3.2 170,130 150,150 130,170 57,130 1.5,80 c 0,90 1.1,170 -3,240 C 30,300 120,220 150,250 c 40,40 -74,140 -70,150 90,0 150,0 250,0 0,0 -120,-120 -80,-150 40,-30 120,50 150,70 0,0 0,-180 0,-240 -30,40 -130,90 -150,70 C 230,130 310,0.29 310,-1.2 z" />',
  'width' => 400,
  'height' => 400,

)

?>
