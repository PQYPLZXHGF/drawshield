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

// broad-arrow

$charge = array (

  'patterns' => array (
  'broad arrow ?heads?',
  ),
  'modifiers' => array (
    array ( 'up', 'points? upwards?', 'mod', 'pointing',    ),
    array ( 'down', 'points? downwards?', 'mod', 'pointing',    ),
  ),

  'doc' => 'Stuff...',

  'width' => 222,
  'height' => 182,
  'body' => '<path d="M 117,180 106,180 2.93,47.6 61.5,48.3 103,159 81.3,24.9 149,24.2 118,158 165,46.1 218,45.4 117,180 z" stroke="#000000" stroke-width="4" />
          <path d="m 149,20.9 c 0,10.3 -16,18.7 -35,18.7 -19.5,0 -35.2,-8.4 -35.2,-18.7 0,-10.3 15.7,-18.7 35.2,-18.7 19,0 35,8.4 35,18.7 z" stroke="#000000" stroke-width="4" />
          <path d="m 202,52 -68,94" fill="none" stroke="#000000" stroke-width="2" />
          <path d="M 22,57.8 94.4,152" fill="none" stroke="#000000" stroke-width="2" />',
  'orient_to_ordinary' => true,

);

if ( $node != null ) {
  if ( get_mod($node,'pointing') == 'up' ) $node->append_child(make_mod('inverted'));
}
?>
