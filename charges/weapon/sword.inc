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

// sword

$charge = array (

  'link' => 'http://karlwilcox.com/parker/s/sword',
  'patterns' => array (
  '?arming swords?',
  '(2|two) handed swords?',
  ),

  'doc' => 'Stuff...',

  'file' => 'inkscape/sword.svg',

);

include 'charges/weapon/_swords.inc';

$charge['modifiers'][] = array ( 'stpaul', 'of (st|saint) paul', 'mod', 'swordtype' );

if ( $node != null ) {
  if ( ($type = get_mod($node,'swordtype')) != null )
    $charge['file'] = 'inkscape/sword' . $type . '.svg';
}

?>
