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
  'cross(let|lets|es)? recercell?e?(e|y)',
  'cross(let|lets|es)? moline voided',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  );

$main = 'M100,100 m15,-15 l0,-60 c0,-25 20,-15 20,-25 0,-5 -10,-5 -15,0 -7.0710678,7.071068 -10,10 -10,25 l0,65';
$start = 0;
$separate = true;
$void = 'x';
$pierce = 'x';
$fitch = 'x';

include ('charges/quadrate/_quadrate8.inc');

?>
