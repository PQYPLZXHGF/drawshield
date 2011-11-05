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

// calvary

$charge = array (

  'patterns' => array (
  'cross(es)? calvary',
  'calvary cross(es)?'
  ),
  
  'either' => array ( 'cross', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 200,
  'body' => '<path d="M{START},0h25v100h75v50h-75v250h-50v-250h-75v-50h75v-100z" stroke="#000000" stroke-width="4" />',

);
include ('charges/cross/_addsteps.inc');

?>
