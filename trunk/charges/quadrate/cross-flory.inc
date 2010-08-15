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

// cross-flory

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? florys?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'body' => '<path d="m 200,320 c 0,10 10,30 20,40 0,10 -20,30 -20,30 -10,0 -20,-20 -20,-30 10,-20 20,-30 20,-40 0,0 0,0 0,0 z m -20,0 c 0,10 -10,30 -10,10 -30,0 -10,30 0,30 20,-10 20,-30 20,-40 -10,0 0,0 -10,0 z m 40,0 c 0,10 10,30 10,10 30,0 10,30 0,30 -20,-10 -20,-30 -20,-40 10,0 0,0 10,0 z m 0,-120 0,120 -40,0 0,-120 m -98,0 c -6,0 -30,10 -40,20 -11,0 -27,-20 -28,-20 0,-10 19,-20 28,-20 17,10 27,20 40,20 0,0 -1,0 0,0 z m 0,-20 c -9,0 -27,-10 -5,-10 -9,-30 -34,-10 -30,0 5,20 24,20 34,20 0,-10 0,0 1,-10 z m 0,40 c -9,0 -27,10 -5,10 -9,30 -34,10 -30,0 5,-20 24,-20 34,-20 0,10 0,0 1,10 z m 118,0 -120,0 0,-40 120,0 m 120,20 c 10,0 30,-10 40,-20 10,10 30,20 30,20 0,10 -20,20 -30,20 -20,-10 -30,-20 -40,-10 0,-10 0,-10 0,-10 z m 0,20 c 10,0 30,10 10,10 0,30 30,20 30,0 -10,-20 -30,-20 -40,-20 0,10 0,0 0,10 z m 0,-30 c 10,-10 30,-20 10,-20 0,-30 30,-10 30,0 -10,20 -30,20 -40,20 0,-10 0,0 0,0 z m -120,-10 120,0 0,40 -120,0 m 0,-138 c 0,-6 -10,-30 -20,-40 10,-11 20,-27 20,-28 10,0 20,19 20,28 -10,17 -20,27 -10,40 -10,0 -10,-1 -10,0 z m 20,0 c 0,-9 10,-27 10,-5 30,-9 20,-34 0,-30 -20,5 -20,24 -20,34 10,0 0,0 10,1 z m -30,0 c -10,-9 -20,-27 -20,-5 -30,-9 -10,-34 0,-30 20,5 20,24 20,34 -10,0 0,0 0,1 z m -10,118 0,-120 40,0 0,120" />',
  'width' => 400,
  'height' => 400,

)

?>
