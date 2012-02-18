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

// fret

$charge = array (

  'patterns' => array (
  'frets?',
  ),
  'either' => array ( 'subordinary', 'geometric', ),

  'doc' => 'Stuff...',

  'width' => 370,
  'height' => 370,
  'body' => '<path d="m 212,248 -18,19 -9,9 -91,-91 28,-27 18,18 -9,9 54,54 9,-9 18,18 z m -36,-108 -18,-18 27,-28 91,91 -28,27 -18,-18 9,-9 -54,-54 -9,9 z M 19.7,2 176,158 158,176 1.6,20 19.7,2 z M 212,194 371,351 351,371 194,212 212,194 z m -18,-36 18,18 -36,36 -18,-18 36,-36 z m -72,72 18,18 L 19.6,367 1.5,351 122,230 z M 351,1 367,20 248,140 230,122 351,1 z" />',
  'orient_to_ordinary' => true,

)

?>
