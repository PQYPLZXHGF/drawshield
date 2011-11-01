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

// cross-fourche

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? fourche',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  );

$main = 'c21.361868,-25.3307393 32.470817,-18.5019455 42.081712,-19.08560311 l5.389105,18.69649811 c-15.278858,-0.700389 -27.470817,2.889105 -27.470817,15.389105 l0,45';
$start = 80;
$fitch = 'v40l-20,40';
$void = 'h10v65';
$voidStart = 75;

include ('charges/quadrate/_quadrate8.inc');
  
?>
