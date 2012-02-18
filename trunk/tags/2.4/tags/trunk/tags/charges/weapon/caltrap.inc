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

// caltrap

$charge = array (

  'patterns' => array (
    '(g|c)altraps?',
    'cheval traps?',  ),

  'doc' => 'Stuff...',

  'width' => 272,
  'height' => 335,
  'body' => '<g stroke-width="4" stroke="inherit">
    <path d="M 126,2 81.8,145 4.04,239 93.9,211 128,334 177,219 269,241 179,141 z"/>
    <path d="M 127,5.03 129,171 177,141 z" fill="#000000" fill-opacity="0.651" />
    <path d="m 179,143 87,96 -136,-68 0,161 48,-111 -48,-50" fill="#000000"  fill-opacity="0.757" />
    <path d="M 5.05,237 127,170 93.9,212 z" fill="#000000" fill-opacity="0.365" />
    <path d="M 127,171 127,334 95,213 z" fill="#000000" fill-opacity="0.365" />
    <path d="m 138,176 130,63 -90,-21 z" fill="#000000" fill-opacity="0.566" />
    <path d="M 125,169 81.8,144" />
  </g>',
  'orient_to_ordinary' => true,

);

if ( $node != null ) {
  if ( get_mod($node,'pointing') == 'up' ) $node->appendChild(make_mod('inverted'));
}

?>
