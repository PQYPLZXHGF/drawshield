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

// cross-paty-floretty

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? pat?t(y|e) floretty',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',
  );

$main = 'c15,5 2,9.95 3.69,25 l1.4,0 c0,0 0.68,-11.9 4.91,-15 3.4,-2.47 10,-3.56 12.5,-0.2 3,4.1 5.5,12.1 -2.7,14.5 0.5,-5.4 -5.7,-6.5 -8.6,-6 c-2.54,0.4 -3.84,6.7 -3.84,6.7 l8.64,0 c-6,15 -6,65 -6,65';

include ('charges/quadrate/_quadrate8.inc');
  
?>
