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

// cross-formy

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? (flory|fleuronny) of (one|1) lozenge',
  ),
  
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

);

$main = 'c5,0 5.1986022,9.128465 5.0040496,14.84831 0,0 13.8459214,-14.57455382 22.0887234,-3.317465 c-19.4022209,-0.180137 -15.113051,12.769767 -12.092773,13.469155 l30,30';
$fitch = 'h-35v35l-10,30';
$void = 'x';
include ('charges/quadrate/_quadrate8.inc');
  

?>
