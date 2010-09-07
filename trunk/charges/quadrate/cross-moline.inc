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

// cross-moline

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? (molines?|ancre|anchory)',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,
  
  'body' =>  '<path d="m 250,200 0,100 a 55,45 60 0 0 90,50 80,100 0 0 1 -140,-10 80,100 0 0 1 -140,10 45,55 30 0 0 90,-50 l 0,-100 z m -50,50 -100,0 A 45,55 60 0 0 50,340 100,80 0 0 1 60,200 100,80 0 0 1 50,60 a 55,45 30 0 0 50,90 l 100,0 z m 0,-100 100,0 a 45,55 60 0 0 50,-90 100,80 0 0 1 -10,140 100,80 0 0 1 10,140 55,45 30 0 0 -50,-90 l -100,0 z m -50,50 0,-100 A 55,45 60 0 0 60,50 80,100 0 0 1 200,60 80,100 0 0 1 340,50 45,55 30 0 0 250,100 l 0,100 z" />',
  
  'fitchy' =>  '<path d="m 230,200 0,230 -30,70 -20,-70 0,-230 z m -30,50 -100,0 A 45,55 60 0 0 50,340 100,80 0 0 1 60,200 100,80 0 0 1 50,60 a 55,45 30 0 0 50,90 l 100,0 z m 0,-100 100,0 a 45,55 60 0 0 50,-90 100,80 0 0 1 -10,140 100,80 0 0 1 10,140 55,45 30 0 0 -50,-90 l -100,0 z m -50,50 0,-100 A 55,45 60 0 0 60,50 80,100 0 0 1 200,60 80,100 0 0 1 340,50 45,55 30 0 0 250,100 l 0,100 z" />',
  );

include ('charges/quadrate/_quadrate.inc');
  

?>
