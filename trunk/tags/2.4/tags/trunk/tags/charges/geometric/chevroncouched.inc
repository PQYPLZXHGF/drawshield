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

// chevron

$charge = array (

  'patterns' => array (
  'chevron(el)?s? couched',
  ),
  
  'modifiers' => array (
    array ( 'sinister', 'sinister', 'mod', 'direction' ),
    array ( 'dexter', 'dexter', 'mod', 'direction' ),
  ),
  
  'either' => array ( 'chevron', ),

  'doc' => 'Stuff...',
  
  'wflex' => 2, 'hflex' => 2,
);

switch ( get_mod ( $node, 'direction' ) ) {
  case 'dexter':
    $charge['width'] = 200;
    $charge['height'] = 400;
    $charge['body'] = '<polygon points="0,200 120,0 200,0 80,200 200,400 120,400" />';
    break;
  case 'sinister':
    $charge['width'] = 200;
    $charge['height'] = 400;
    $charge['body'] = '<polygon points="0,0 80,0 200,200 80,400 0,400 120,200" />';
    break;
  default: // Just looks like an ordinary chevron charge
    $charge['width'] = 400;
    $charge['height'] = 200;
    $charge['body'] = '<polygon points="0,200 200,0 400,200 320,200 200,80 80,200" />';
    break;
}

?>
