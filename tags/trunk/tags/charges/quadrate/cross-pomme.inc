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

// cross-pomme

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? pommes?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,

  'body' =>  '<path d="m 220,200 0,120 a 40,40 0 1 1 -40,0 l 0,-120 40,0 m -20,20 -124,0 a 40,40 0 1 1 0,-40 l 124,0 0,40 m 0,-40 120,0 a 40,40 0 1 1 0,40 l -120,0 0,-40 m -20,20 0,-124 a 40,40 0 1 1 40,0 l 0,124 -40,0" />',
  'fitchy' =>  '<path d="m 230,200 0,230 -30,70 -20,-70 0,-230 z m -30,20 -124,0 a 40,40 0 1 1 0,-40 l 124,0 0,40 m 0,-40 120,0 a 40,40 0 1 1 0,40 l -120,0 0,-40 m -20,20 0,-124 a 40,40 0 1 1 40,0 l 0,124 -40,0" />',
  
  );

include ('charges/quadrate/_quadrate.inc');
  

?>
