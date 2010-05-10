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


function makeChg_furniture ( $node ) {
  $charge_data = array (
'table' => array ( 'width' => 291, 'height' => 179,  'body' => '<g stroke="#000000" stroke-width="2" >
<path d="M 58.2,3.1 38.5,56.6 c 0,0 -3,23.2 0,22.7 3.1,-0.5 208.5,3 208.5,3 L 253,59.6 229,1.5 58.2,3.1 z" />
  <path d="m 39,58.6 213,0.5"  />
  <path d="m 134,80.8 -2,69.2 c 0,0 12,10 23,0 -1,0 0,-69.2 0,-69.2 l -21,0 z"  />
  <path d="M 55.2,79.8 1.1,167 c 0,0 -3,16 15.7,5 1.5,0 58.6,-92.7 58.6,-92.7 l -20.2,0.5 z" />
  <path d="m 237,82.4 54,87.6 c 0,0 3,15 -16,4 -1,1 -58,-92.1 -58,-92.1 l 20,0.5 z" /><g fill="none">
  <path d="M 71.6,80.9 18.3,165" />
  <path d="M 221,83.4 274,168" />
  <path d="M 136,83.9 135,147" />
  <path d="m 140,83.3 0,65.7" />
  <path d="M 145,84.9 144,148" />
  <path d="m 150,85.4 0,60.6" /></g></g>', )


);
  $type = $node->get_attribute('subtype');
  if ( isset($charge_data[$type]) ) {
      return $charge_data[$type];
  } else {
    my_trigger_error ( "No furniture $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
