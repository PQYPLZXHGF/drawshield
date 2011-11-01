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
  'cross(let|lets|es)? (flory|fleuronny) of (nine|9) fusils?',
  ),
  
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

);

$main = 'c5,0 5.1986022,9.128465 5.0040496,14.84831 0,0 13.8459214,-14.57455382 22.0887234,-3.317465 c-12.092773,-1.530845 -10.113051,7.769767 -7.092773,8.469155 l-20,20 20,20 -20,20 10,10';
$void = 'x';

include ('charges/quadrate/_quadrate8.inc');
  

?>
