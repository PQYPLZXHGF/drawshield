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


function makeChg_human ( $node ) {
  $charge_data = array (
'arm' => array ( 'width' => 107, 'height' => 118,  'body' => '<g stroke="#000000" stroke-width="1" >
<path d="m 75.4,111 -34.9,1 C 40.5,112 5.94,86.2 1.77,62.1 16.7,40.3 64.3,11.5 69.4,11.4 75.6,11.3 75,1.28 93.2,2.78 c 7.8,2.98 7.8,2.78 6.6,7.72 4.2,-2.83 6.2,2.9 4.2,5.1 3,1.8 3,3.6 2,5.7 2,1.4 1,7.5 -3,6.5 -3,-0.1 -2,4.3 -7.4,6 C 92.3,34.7 78.7,33.5 74.8,29.9 67.6,32.3 52.3,51.3 36.9,69.5 54.1,79.1 76.6,112 75.4,111 z" />
<path d="M 96.8,4.57 C 91,11.1 84.8,7.89 87,14 c 0.9,2.4 13,-3.8 13,-3.8" />
<path d="m 99,9.9 c -6,6.6 -11,2.6 -9,8.7 1,2.4 15,-2.7 15,-2.7" />
<path d="m 104,16 c -10,4.3 -12,0.6 -10,6.7 1,2.5 12,-1.5 12,-1.5 -2,-0.4 -11,6.6 -13,6.1" />
<path d="m 92,2.8 c -6,6.5 -9,1.8 -7,7.8 1,2.5 11,-4.9 11,-4.9" />
</g>', ),
'hand' => array ( 'width' => 57, 'height' => 122,  'body' => '<path stroke="#000000" stroke-width="1" d="m 8.8,116 c -2.5,5 30,6 33.7,2 1,-5 -2.5,-13 -0.6,-18.4 C 46.3,99.7 54,86 55,78.2 57,67.3 55,40 53,38.5 48.1,37.3 47,39.7 44.6,52 42.2,64.2 47,21 44,16.2 39.5,-1.9 33,14.7 33,12 35.3,-6.3 25,0.7 23.1,9.64 20,0.4 13.3,15 15.4,21.3 11.6,14.1 3.9,11.7 3.4,55.6 2.9,58.4 -4.4,93.5 7.9,103 c 2.6,6 -1.7,8 0.9,13 z"   />
        <g stroke="#000000" stroke-width="1" fill="none" ><path d="m 15.1,20.7 0,0 -0.3,30.4"   />
        <path d="M 22.9,10.4 23.1,49"   />
        <path d="M 33.2,12.1 33,48.1"   />
        <path d="m 12.3,33.6 0,0 c -6.5,1.9 -5.9,2.7 -5.9,2.7"   />
        <path d="m 13,42.6 0,0 c -7,1.9 -6,2.8 -6,2.8"   />
        <path d="m 22,20 0,0 c -7,0 -6,1 -6,1"   />
        <path d="m 22,35 0,0 c -7,1 -7,2 -7,2"   />
        <path d="m 31,32 0,0 c -8,0 -7,1 -7,1"   />
        <path d="m 31,16 0,0 c -8,0 -8,1 -8,1"   />
        <path d="m 43,20 0,0 c -9,0 -8,1 -8,1"   />
        <path d="m 43,36 0,0 c -8,0 -8,1 -8,1"   />
        <path d="m 43.7,54.7 c 0,0 -5,-9.7 -37.5,0.4"   />
        <path d="m 43,54.7 c 0,0 -21,-1.3 -36,7.7"   />
        <path d="M 43,60.1 C 42,58.6 17,53.5 10,81"   />
        <path d="m 44.3,54.5 -1,17.7"   />
        <path d="M 43,61.8 C 42,60.5 23,63.9 24,92.3"   />
        <path d="m 7.3,103 c 0.4,1 29.5,3 33,-2"   /></g>', ),
);
  $type = $node->get_attribute('subtype');
  if ( isset($charge_data[$type]) ) {
      return $charge_data[$type];
  } else {
    my_trigger_error ( "No human $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}


?>
