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

// fylfot

$charge = array (

  'patterns' => array (
  'cross(es)? potent rebated',
  'cross(es)? gammadions?',
  'fylfots?',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,
  'body' => '<path d="M175,0v175h-125v-50h-50v100h175v125h-50v50h100v-175h125v50h50v-100h-175v-125h50v-50z" />',
  
  'fitchy' => '<path d="M175,0v175h-125v-50h-50v100h175v175l25,100l25,-100v-175h125v50h50v-100h-175v-125h50v-50z" />',
  );

include ('charges/quadrate/_quadrate.inc');
  
?>
