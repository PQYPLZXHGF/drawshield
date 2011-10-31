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
  'cross(let|lets|es)? (formee|pattee)',
  'cross(let|lets|es)? (formy|patt?y)',
  ),
  
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

);

$main = 'l60,0 c-35,10 -50,70 -40,80';
$fitch = 'v40l-20,40';

include ('charges/quadrate/_quadrate8.inc');
  

?>
