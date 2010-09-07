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

// cross-pointed

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? pointeds?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,
  
  'body' =>  '<path d="m 200,0 50,50 0,100 100,0 50,50 -50,50 -100,0 0,100 -50,50 -50,-50 0,-100 -100,0 -50,-50 50,-50 100,0 0,-100 z m 200,200 -50,50 -100,0 0,100 -50,50 -50,-50 0,-100 -100,0 -50,-50 50,-50 100,0 0,-100 50,-50 50,50 0,100 100,0 z m -400,0 50,-50 100,0 0,-100 50,-50 50,50 0,100 100,0 50,50 -50,50 -100,0 0,100 -50,50 -50,-50 0,-100 -100,0 z m 200,200 -50,-50 0,-100 -100,0 -50,-50 50,-50 100,0 0,-100 50,-50 50,50 0,100 100,0 50,50 -50,50 -100,0 0,100 z" />',
  'fitchy' =>  '<path d="m 220,210 0,230 -30,70 -20,-70 0,-230 z m -70,-60 0,-100 50,-50 50,50 0,100 100,0 50,50 -50,50 -100,0 0,100 -50,50 -50,-50 0,-100 -100,0 -50,-50 50,-50 z m 100,100 0,100 -50,50 -50,-50 0,-100 -100,0 -50,-50 50,-50 100,0 0,-100 50,-50 50,50 0,100 100,0 50,50 -50,50 z M 200,0 l 50,50 0,100 100,0 50,50 -50,50 -100,0 0,100 -50,50 -50,-50 0,-100 -100,0 -50,-50 50,-50 100,0 0,-100 z" />',
  
  );

include ('charges/quadrate/_quadrate.inc');
  
?>
