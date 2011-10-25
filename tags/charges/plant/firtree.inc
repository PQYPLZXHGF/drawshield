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

$charge = array ( 
  'patterns' => array (
  '(pine|fir) trees?',
  ),
  
  'modifiers' => array (
    array ( null, 'fructed', 'ignore' ), // TODO add fructed
    array ( null, 'erased', 'ignore' ),
  ),

  'licence' => 'by commons.wikimedia.org/wiki/User:Henrysalome',
  'height' => 408, 'width' => 318,
    'body' => '
      <path fill-rule="evenodd" stroke="inherit" stroke-width="3" d="m 157,5.73 c -2,10.97 2,25.37 -19,24.17 6,8.2 15,12.9 -19,5.8 10,14.4 25,10.4 31,19.3 -14,12 -32,-1.6 -42,14.5 19,-4.6 31,-0.8 42,4.8 l 0,8.7 C 133,77.7 116,71.2 96.4,85.9 110,86.1 155,82 117,89.2 l 33,5.4 -1,11.4 c -24,22 -43,-15.9 -67.1,8 l 27.1,3 -20.4,6 31.4,4 c -19,2 -32.3,4 -38.1,8 l 29.1,1 -30.1,7 35.1,2 -13,3 43,2 c -21,21 -54.3,1 -108.6,24 32.5,-4 67.6,3 80.6,0 -4,12 -26.6,5 -44.9,15 l 17.5,2 c -21,16 -36.3,1 -52.3,2 l 8.7,10 -23.2,4 92.2,-3 C 79.9,228 45.1,217 8.33,236 l 77.37,-7 c -10.6,6 -32.7,9 -53.2,12 16.8,7 59.6,-2 60.1,-9 7.4,1 -16.3,14 -11.7,14 16.9,-2 71.1,-48 51.1,-19 l 19,-14 0,24 c -15,21 -30,14 -42,16 l 8,5 c -13,0 -25.9,-1 -41,-6 l 11.7,10 c -31.9,-6 -66.2,-12 -83.24,2 13.04,-1 24.24,-1 27.04,1 l -25.11,16 29.01,-8 -8.7,11 c 16.8,-9 39.7,-13 66.8,-12 l 34.5,3 c -4,18 -65,15 -94.5,21 l 22.2,2 c -7.2,3 -17.3,6 -27.1,8 24.6,2 49.1,-3 73.4,-7 -32.7,8 -56.8,20 -97.54,20 25.44,11 48.64,6 71.54,0 23.7,6 95,-32 78,-28 l -1,69 c 3,15 -15,9 -27,24 l 20,-5 -9,12 23,-14 c 6,8 9,17 13,26 l 0,-20 12,8 -6,-13 20,7 c -8,-6 -16,-11 -26,-22 l -3,-64 c 102,42 97,15 135,16 -56,1 -95,-12 -134,-26 l -1,-10 c 51,23 99,32 134,21 -17,-3 -46,0 -47,-12 l 33,-5 c -53,8 -85,-6 -120,-16 l -1,-9 c 20,8 45,18 63,13 0,0 -31,-14 -21,-9 27,12 76,19 104,4 -26,2 -42,6 -56,-3 l 46,-20 c -22,10 -104,25 -135,-2 l 0,-9 c 70,30 70,11 91,11 -29,2 -44,-2 -54,-10 50,13 64,-10 78,-24 -35,29 -71,7 -116,-2 l 1,-11 c 64,4 82,-7 101,-18 l -32,4 c 6,-6 13,-8 20,-21 -28,25 -61,21 -90,-3 l -1,-8 c 42,6 44,-9 85,-6 l -32,-7 c 0,0 13,-8 10,-6 -5,4 -39,11 -38,7 l 18,-12 c 0,0 -38,13 -42,13 -4,0 -1,-11 -1,-11 16,-13 44,-10 66,-15 l -70,1 0,-6 c 28,2 27,-11.3 51,-13.4 -23,-8.9 -28,8.4 -51,0 l 1,-15.5 37,-4.8 -38,-8.7 -1,-8.7 34,-6.7 -34,-2.9 c 0,0 -11,-6.8 1,-6.8 13,0 21,-9.7 21,-9.7 l -23,4.9 10,-13.5 C 162,32.1 160,18.4 157,5.73 z" />
      ',
  );
?>
