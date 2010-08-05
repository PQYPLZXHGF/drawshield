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


function makeChg_tools ( $node ) {
  $tool_data = array (
'scythe' => array ( 'width' => 340, 'height' => 264,  'orient_to_ordinary' => true,  'hflex' => 1.2, 'wflex' => 1.2, 'turn_on_fesswise' => true,
   'body' => '<path stroke="#000000" stroke-width="4" d="M 289,13 C 252,43.7 196,65.6 157,86.4 62.3,137 20.7,179 18.4,185 14,197 21.9,201 28.7,204 35.3,207 51.3,159 144,115 184,90.2 267,57.7 303,26.7 306,9 291,11 289,13 z" />
    <path stroke="#000000" stroke-width="4" d="m 49.1,193 18.6,-8 c 0,0 128.3,69 239.3,31 8,-6 -38,54 -154,28 -48,-11 -113.6,-42 -118.7,-38 -5,5 15.1,-12 14.8,-13 z" />
    <path stroke="#000000" stroke-width="4" fill="#0F0F0F" d="m 28.1,173 c 9.1,0 16.3,13 18.3,15 2.1,3 3.6,5 4.4,7 0.8,3 4.6,17 -3.9,16 -8.5,-1 -14.1,-4 -13.4,-6 0.7,-2 4,-15 1.8,-19 -1,-2 -5.4,-5 -16.1,-2 6.4,-9 9.3,-10 8.9,-11 z" />', ),
'water-bouget' => array ( 'width' => 332, 'height' => 243,  'body' => '<path stroke="#000000" stroke-width="4" d="M 51.2,94 C 71.9,84 158,85 170,85 c 13,0 110,7 117,12 10,8 25,22 -30,48 -9,-11 -51,-36 -89,-36 -38,1 -33,-11 -86.5,32 C 42.1,111 51.2,94 51.2,94 z" />
     <path stroke="#000000" stroke-width="4" d="m 166,47 c 26,5 30,-25 53,-17 4,34 -27,31 -34,120 -1,22 38,115 110,88 71,-27 17,-115 7,-91 -27,64 -72,43 -81,12 C 202,94.7 242,44 260,23 260,23 187,-4 166,2 145,-4 72.1,23 72.1,23 91.1,44 130,94.7 112,159 103,190 57.1,211 30.1,147 20.3,123 -34,211 37.1,238 110,265 149,172 147,150 141,61 110,64 113,30 c 23,-8 27,22 53,17 z" />', ),
  'anvil' => array ( 'height' => "400", 'width' => "400",
    'body' => '
      <path stroke="#000000" stroke-width="2" d="m 390,21 0,63 -150,76 0,-60 150,-79 z" />
      <path stroke="#000000" stroke-width="2" d="m 9.1,100 -3,70 233.9,0 0,-72" />
      <path fill="#4d4d4d" stroke="none" d="m 390,21 0,63 -150,76 0,-60 150,-79 z" />
      <path stroke="#000000" stroke-width="2" d="M 8.1,100 140,18 390,20 c 0,0 -30,17 -60,33 10,22 70,24 70,24 l -120,4 -40,19 -231.9,0 z" />
      <path stroke="#000000" stroke-width="2" d="m 160,390 20,-20 c 0,0 10,-190 220,-291 0,0 -230,111 -230,111" />
      <path stroke="#000000" stroke-width="2" d="M 6.1,170 C 100,200 120,300 120,390 c 20,0 40,0 40,0 10,-100 20,-170 70,-230" />
      <path stroke="#000000" stroke-width="2" d="m 110,280 70,0" />
      <path fill="#333333" stroke="none" d="m 160,390 20,-20 c 0,0 10,-180 190,-274 -100,44 -140,64 -140,64 0,0 -60,60 -70,230" />
      ',
  ),
  );
  $type = $node->get_attribute('subtype');
  if ( isset($tool_data[$type]) ) {
      return $tool_data[$type];
  } else {
    my_trigger_error ( "No tool $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
