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
  'cross(let|lets|es)? sarcell(ee|y)',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  );

$main = 'c10,-10 25,-5 25,10 0,10 -5,20 -15,15 l0,60';

include ('charges/quadrate/_quadrate8.inc');

?>
