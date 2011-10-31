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

);

$main = 'c0,-20 13.2,-24.348 25,-25 10.7,-0.59 23.7,9.41 25,20 1,8.3 0,15 -15,20 10,-15 3.5,-24.2 -5,-25 -8.9,-0.8 -10,15.3 -10,25 l0,40';
$start = 75;
$fitch = 'v40l-20,40';

include ('charges/quadrate/_quadrate8.inc');

?>
