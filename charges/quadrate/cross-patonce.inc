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

// cross-patonce

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? patonces?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,
  
  'body' =>  '<path d="m 250,200 0,100 a 72,58 60 0 0 60,90 80,100 0 0 1 -90,-50 20,58 0 0 1 -40,0 80,100 0 0 1 -90,50 58,72 30 0 0 60,-90 l 0,-100 z m -50,50 -100,0 a 58,72 60 0 0 -90,60 100,80 0 0 1 50,-90 58,20 0 1 1 0,-40 100,80 0 0 1 -50,-90 72,58 30 0 0 90,60 l 100,0 z m 0,-100 100,0 a 58,72 60 0 0 90,-60 100,80 0 0 1 -50,90 58,20 0 0 1 0,40 100,80 0 0 1 50,90 72,58 30 0 0 -90,-60 l -100,0 z m -50,50 0,-100 a 72,58 60 0 0 -60,-90 80,100 0 0 1 90,50 20,58 0 1 1 40,0 80,100 0 0 1 90,-50 58,72 30 0 0 -60,90 l 0,100 z" />',
  'fitchy' =>  '<path d="m 230,200 0,230 -30,70 -20,-70 0,-230 z m -30,50 -100,0 a 58,72 60 0 0 -90,60 100,80 0 0 1 50,-90 58,20 0 1 1 0,-40 100,80 0 0 1 -50,-90 72,58 30 0 0 90,60 l 100,0 z m 0,-100 100,0 a 58,72 60 0 0 90,-60 100,80 0 0 1 -50,90 58,20 0 0 1 0,40 100,80 0 0 1 50,90 72,58 30 0 0 -90,-60 l -100,0 z m -50,50 0,-100 a 72,58 60 0 0 -60,-90 80,100 0 0 1 90,50 20,58 0 1 1 40,0 80,100 0 0 1 90,-50 58,72 30 0 0 -60,90 l 0,100 z" />',
  );

include ('charges/quadrate/_quadrate.inc');
  
?>
