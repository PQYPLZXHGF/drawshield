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

// maltese-cross

$charge = array (

  'patterns' => array (
  'maltese cross(let|lets|es)?',
  'cross(let|lets|es)? of (8|eight|huit) points',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'body' => '<path d="m 130,400 70,-200 70,200 -70,-50 -70,50 z M 0,130 200,200 0,270 50,200 0,130 z m 400,140 -200,-70 200,-70 -50,70 50,70 z M 270,0 200,200 130,0 200,50 270,0 z M 3.7,130 200,200 3.7,270 50,200 3.7,130 z M 270,0 200,200 130,0 200,50 270,0 z m -140,400 70,-200 70,200 -70,-50 -70,50 z m 270,-130 -200,-70 200,-70 -50,70 50,70 z m 0,0 -200,-70 200,-70 -50,70 50,70 z m -270,130 70,-200 70,200 -70,-50 -70,50 z M 270,0.68 200,200 130,0.68 200,51 270,0.68 z M 0,130 200,200 0,270 50,200 0,130 z M 270,3.7 200,200 130,3.7 200,50 270,3.7 z M 400,270 200,200 l 200,-70 -50,70 50,70 z M 0.68,130 200,200 0.68,270 51,200 0.68,130 z M 130,400 l 70,-200 70,200 -70,-50 -70,50 z" />',
  'width' => 400,
  'height' => 400,
  'fitchy' =>  '<path d="m 230,280 0,170 -30,50 -20,-50 0,-170 z M 3.7,130 200,200 3.7,270 50,200 3.7,130 z M 270,0 200,200 130,0 200,50 270,0 z m -140,400 70,-200 70,200 -70,-50 -70,50 z m 270,-130 -200,-70 200,-70 -50,70 50,70 z m 0,0 -200,-70 200,-70 -50,70 50,70 z m -270,130 70,-200 70,200 -70,-50 -70,50 z M 270,0.68 200,200 130,0.68 200,51 270,0.68 z M 0,130 200,200 0,270 50,200 0,130 z M 270,3.7 200,200 130,3.7 200,50 270,3.7 z M 400,270 200,200 l 200,-70 -50,70 50,70 z M 0.68,130 200,200 0.68,270 51,200 0.68,130 z M 130,400 l 70,-200 70,200 -70,-50 -70,50 z" />',
  
);
include ('charges/quadrate/_quadrate.inc');

?>
