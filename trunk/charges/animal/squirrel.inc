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

// badger

$charge = array (
 'patterns' => array (
    'squirrels?',
  ),
 
  'modifiers' => array (
    array ( 'sejant', 'seje?ant', 'mod', 'stance' ),
    array ( null, 'cracking ?a nuts?', 'ignore' ),
    array ( 'courant', 'courant', 'mod', 'stance' ),
   ),
 
 'file' => 'inkscape/squirrel-sejant.svg',
 
 'hflex' => 1.2,
 'wflex' => 1.2,
);

if ( $node != null ) {
  if ( ($stance = get_mod($node, 'stance')) == null ) $stance = 'sejant'; 
  $charge['file'] = 'inkscape/squirrel' . '-' . $stance . '.svg';
}
  
?>
