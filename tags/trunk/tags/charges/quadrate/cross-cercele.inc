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

// cross-cercele

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? (re)?cercelee?s?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'body' => '<path d="m 240,200 0,100 a 21,36 0 1 0 30,-10 51,54 0 1 1 -70,30 51,54 0 1 1 -70,-30 21,36 0 1 0 30,10 l 0,-100 z m -40,40 -102,0 a 36,21 0 1 0 12,30 54,51 0 1 1 -29,-70 54,51 0 1 1 29,-70 36,21 0 1 0 -12,30 l 102,0 z m 0,-80 100,0 a 36,21 0 1 0 -10,-30 54,51 0 1 1 30,70 54,51 0 1 1 -30,70 36,21 0 1 0 10,-30 l -100,0 z m -40,40 0,-102 a 21,36 0 1 0 -30,12 51,54 0 1 1 70,-29 51,54 0 1 1 70,29 21,36 0 1 0 -30,-12 l 0,102 z"/>',
  'width' => 400,
  'height' => 400,
  'fitchy' => '<path d="m 230,200 0,230 -30,70 -20,-70 0,-230 z m -30,40 -102,0 a 36,21 0 1 0 12,30 54,51 0 1 1 -29,-70 54,51 0 1 1 29,-70 36,21 0 1 0 -12,30 l 102,0 z m 0,-80 100,0 a 36,21 0 1 0 -10,-30 54,51 0 1 1 30,70 54,51 0 1 1 -30,70 36,21 0 1 0 10,-30 l -100,0 z m -40,40 0,-102 a 21,36 0 1 0 -30,12 51,54 0 1 1 70,-29 51,54 0 1 1 70,29 21,36 0 1 0 -30,-12 l 0,102 z"/>',
  
);
include ('charges/quadrate/_quadrate.inc');

?>
