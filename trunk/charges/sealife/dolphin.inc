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

// dolphin

$charge = array (
  'link' => 'http://karlwilcox.com/parker/d/dolphin',
 'patterns' => array (
    'dolphins?',
  ),

  'file' => 'inkscape/dolphin.svg',

  'modifiers' => array (
    array ( 'crowned', '?ducally crown(s|ed)?', 'feature' ),
    array ( 'finned', 'fin(s|ned)', 'feature' ),
    array ( null, 'hauriant', 'ignore' ),
    array ( null, 'naiant', 'ignore' ),
    array ( null, 'embowed', 'ignore' ),
  ),

);

if ( $node != null ) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'feature' and $child-getAttribute('name' == 'stoned')) {
      $charge['file'] = 'inkscape/dolphin-crowned.svg';
      break;
    }
  }
}
