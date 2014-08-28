<?php /* Copyright 2011 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

// moon

$charge = array (

  'link' => 'http://karlwilcox.com/parker/m/moon',
  'patterns' => array (
  '?full moons?',
  'increscents?',
  'decrescents?',
  'crescents?'
  ),
  
  'proper' => rgb('argent'),

  'modifiers' => array (
    array ( null, 'in her complement', 'ignore'  ),
    array ( null, 'in plenitude', 'ignore'  ),
    array ( 'tochief', 'crescent', 'mod', 'direction' ),
    array ( 'todexter', 'increscent', 'mod', 'direction' ),
    array ( 'todexter', 'in increment', 'mod', 'direction' ),
    array ( 'tosinister', 'decrescent', 'mod', 'direction' ),
    array ( 'tobase', 'pendent', 'mod', 'direction' ),
  ), 
  
  'file' => 'inkscape/moon-full.svg',
);

if ( $node != null ) {
  // Are we given an explicit direction?
  if ( ($direction = get_mod($node, 'direction')) == null ) {
    // Can we work it out from the actual charge used?
    $tokens = $node->getAttribute('tokens');
    //Careful of order, 'crescent' is in 'decrescent'!
    if ( strpos($tokens,'moon') !== false  ) $direction = 'full';
    elseif ( strpos($tokens,'increment') !== false ) $direction = 'todexter';
    elseif ( strpos($tokens,'increscent') !== false ) $direction = 'todexter';
    elseif ( strpos($tokens,'decrescent') !== false ) $direction = 'tosinister';
    else $direction = 'tochief';
  }
  $charge['file'] = "inkscape/moon-$direction.svg";
}

