<?php /* Copyright 2014 Karl R. Wilcox

     Licensed under the Apache License, Version 2.0 (the "License");
     you may not use this file except in compliance with the License.
     You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

     Unless required by applicable law or agreed to in writing, software
     distributed under the License is distributed on an "AS IS" BASIS,
     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
     See the License for the specific language governing permissions and
     limitations under the License. */

$charge = array (
  'link' => 'http://karlwilcox.com/parker/c/crane',
  'patterns' => array (
  'cranes?',
    'herons?', 'hernshaws?', 'bitterns?', 'fencocks?',
    'storks?',

  ),

    'modifiers' => array (
	array ( null, 'without ?the head', 'warn', 'headless' ),
	array ( 'stoned', 'holding a stone ?in ?the ?dexter ?foot', 'feature' ),
	array ( null, 'thrust through with a sword', 'warn', 'stabbed' ),
      array ( 'beaked', 'beaked', 'feature' ),
      array ( 'legged', 'legged', 'feature' ),
   ),

   'proper' => array ( 'body' => rgb('argent'), 'legged' => rgb('gules'), 'beaked' =>  rgb('gules'), 'stoned' => rgb('gray') ),

  'file' => 'inkscape/crane.svg',

  'behind' => true,
);

if ( $node != null ) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'feature' and $child-getAttribute('name' == 'stoned')) {
    $charge['file'] = 'inkscape/crane-stone.svg';
    break;
    }
  }
}
