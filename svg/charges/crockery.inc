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


function makeChg_crockery ( $node ) {
  $charge_data = array (
  'cauldron' => array (
    'height' => 315, 'width' => 333,
    'body' => '<g stroke="#000000" stroke-width="4" >
<path d="M 26.3,41.6 C 41,68.7 46.5,51.6 38.7,67.1 31,82.6 -0.35,112 6.97,163 c -2.33,65 43.33,72 40.23,83 -1.5,44 -12.4,53 -10,64 14.7,3 3.8,0 14.7,0 10.1,3 3.9,-45 16.3,-40 68.8,40 139.8,4 160.8,1 12,9 6,34 14,40 16,1 7,2 21,-1 5,-8 -23,-61 -8,-72 26,-28 25,-40 34,-63 8,-40 2,-60 -5,-72 C 275,81.1 254,53.2 260,50.1 266,47 266,40 271,36.1 208,5.95 193,12.1 158,15.2 145,-1.79 125,5.95 115,20.7 72.7,15 61.7,26.2 68.2,24.5 80.5,20.7 44.1,23.8 26.3,41.6 z" />
        <path d="m 167,43.1 c 0,0 62,97.9 130,126.9 21,9 35,16 31,2 -4,-13 -35,-38 -35,-38" stroke-width="12" fill="none" />
        <path d="m 34.8,41.6 c 33.1,15.5 96.2,7.9 111.2,4.6 -6,-21 40,-27.1 49,-4.6 41,24.8 68,-2.4 68,-2.4 l -1,0" stroke-width="12" fill="none" />
        <path d="m 135,21.4 c 7,8.6 3,4.7 3,4.7" stroke-width="12" fill="none" />
        <path d="m 265,172 c -16,59 -69,77 -69,77" fill="none" />
        <path d="m 246,167 c -16,59 -69,77 -69,77" fill="none" />
        <path d="m 248,226 c -34,12 -67,-25 -67,-25" fill="none" />
        <path d="m 261,209 c -34,12 -67,-25 -67,-25" fill="none" /></g>'  ),
'chalice' => array ( 'width' => 356, 'height' => 528,  'body' => '<path stroke="#000000" stroke-width="4" d="M 20.19,54.59 C 8.22,124.14 82.26,225.85 148.82,228.10 C 151.81,281.94 143.59,294.66 116.66,319.34 C 136.86,347.76 148.82,344.02 150.32,366.45 C 138.35,430.02 62.07,424.04 44.87,482.37 C 100.94,514.56 247.78,503.70 284.94,479.38 C 283.44,448.72 189.21,436.01 189.21,367.95 C 199.68,352.24 220.62,342.52 231.09,320.83 C 215.38,296.90 192.95,302.14 212.39,231.09 C 306.62,194.44 295.41,144.33 316.35,59.08 C 299.89,39.63 222.11,20.94 173.50,26.17 C 160.79,25.42 13.46,22.43 20.19,54.59 z" /><g fill="none" stroke-width="4" stroke="#000000" >
        <path  d="M 21.68,53.84 C 62.07,80.02 310.36,77.77 316.35,58.33" />
        <path  d="M 20.19,68.05 C 50.85,88.99 281.20,94.98 313.35,74.78" />
        <path  d="M 23.18,88.99 C 29.91,111.43 264.74,137.60 305.13,99.46" />
        <path  d="M 111.43,216.13 C 183.22,234.08 237.82,218.37 237.82,218.37" />
        <path  d="M 142.09,293.91 C 177.24,303.63 213.89,297.65 210.15,296.15" />
        <path  d="M 118.91,318.59 C 149.57,329.81 230.34,324.57 232.58,320.83" />
        <path  d="M 52.35,467.42 C 127.13,501.82 266.99,478.64 275.96,463.68" />
        <path  d="M 284.19,136.86 C 266.24,180.23 210.90,207.90 210.90,207.90" /></g>', ),
'mug' => array ( 'width' => 140, 'height' => 132,  'body' => '<g stroke-width="2" stroke="#000000" > 
        <path d="m 104,25.2 c 7,-5.6 10,-12.4 21,-4 9,6.5 22,24.8 9,62.1 -4,12.1 -13,11.1 -24,4.1 -3,-3.6 -3,-20.8 -3,-20.8 0,0 7,-0.5 12,7.6 7,4.3 5,-23.5 5,-28.8 -1,-5.3 -6,-16.4 -10,-17.2 -3,-0.7 -1,4.6 -1,8.1 2,8.3 -7,2.3 -8,2 -2,-0.2 0,-13.1 -1,-13.1 z" />
        <path d="M 21.9,1 105,1 c 6,-0.3 8,3.2 -2,7.3 -1,3.3 9,110.7 9,110.7 0,0 1,0 0,0 12,3 10,10 0,10 -5,4 -105.7,1 -105.7,1 0,0 -11.89,-2 -0.3,-9 9.6,1 16.2,-111.7 16.2,-111.7 0,0 -8.6,0.2 -6.6,-5.8 1.3,-3.6 6.3,-1.8 6.3,-2.5 z" />
        <path d="M 21.5,9.53 102,8.52" />
        <path d="M 8.33,120 C 17.4,124 106,122 112,119" /><g fill="none" stroke-width="1">
        <path d="M 27.9,17.1 17.9,113" />
        <path d="M 30.3,21.1 C 30.6,23.2 21.2,109 21.2,109" />
        <path d="m 32.9,25.4 -8,78.6" />
        <path d="M 36.1,32.3 28.3,103" /></g></g>', )
    );
  $type = $node->get_attribute('subtype');
  if ( isset($charge_data[$type]) ) {
      return $charge_data[$type];
  } else {
    my_trigger_error ( "No crockery $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
