<?php /* Copyright 2011 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

// cross-avellane

$charge = array (
 'patterns' => array (
    'cross(es)? avellane',
  ),
 'either' => array ( 'quadrate', ),
);


$main = 'c5,0 2.8599222,4.8638132 2.6653696,10.583658 0,0 0.9143969,-10.44747123 23.3268484,-10.05836617 c-15,10.00000017 -5.758331,30.98136517 -7.140274,45.85040217 -1.656809,17.826453 0.545343,31.788402 -18.851944,38.624306 c6.566197,1.090779 4.6860489,-0.355725 10,5';
$void = 'x';

include ('charges/quadrate/_quadrate8.inc');

?>
