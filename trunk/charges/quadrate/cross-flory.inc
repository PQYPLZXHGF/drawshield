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
  'cross(let|lets|es)? fleuronny?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  );

$main = 'c9.59,5.09 5,14 5,19 5.6,-8.1 8.6,-12.1 13.6,-9.72 6,2.82 11.4,4.72 1.4,19.72 3,-16 -9.9,-13.4 -10,-5 l0,56';

include ('charges/quadrate/_quadrate8.inc');

?>
