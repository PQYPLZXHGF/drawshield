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

// arrow

$charge = array (

  'link' => 'http://karlwilcox.com/parker/a/arrow',
  'patterns' => array (
  'arrows?',
  ),
  'modifiers' => array (
    array ( 'barbed', '(barbed|armed)', 'feature',    ),
    array ( 'feathered', '(flighted|feathered)', 'feature',    ),
    array ( 'up', 'points? upwards?', 'mod', 'pointing',    ),
    array ( 'down', 'points? downwards?', 'mod', 'pointing',    ),
  ),

  'file' => 'inkscape/arrow.svg',
  'orient_to_ordinary' => true,

);

if ( $node != null ) {
  if ( get_mod($node,'pointing') == 'up' ) $node->appendChild(make_mod('inverted'));
  if ( ($num = get_mod( $node, 'bundle')) > 0 ) {
    $charge['file'] = 'inkscape/arrow-bundle.svg';
  }
}

