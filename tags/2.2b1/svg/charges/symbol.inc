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


function makeChg_symbol ( $node ) {
  $symbol_data = array (
    'fleurdelys' => array ( 'height' => 758, 'width' => 636,
'body' => '
<g stroke="#000000" stroke-width="8"  >
  <path d="m 373,495 45,-1 c 0,0 10,-85 89,-92 40,31 -2,56 3,74 37,-8 100,-50 119,-109 C 649,276 578,241 524,248 390,288 380,480 373,495 z" />
  <path d="m 183,502 278,1 1,35 -280,0 1,-36 z" />
  <path d="m 321,547 c 0,-1 -9,0 -63,-1 -20,50 -37,57 -76,98 102,-12 83,-49 94,-34 11,15 -5,44 8,93 4,12 35,53 38,53 2,0 34,-41 37,-53 13,-49 -2,-78 9,-93 11,-15 -9,22 93,34 -38,-41 -55,-48 -76,-98 -54,1 -65,0 -64,1 z" />
  <path d="m 268,495 -45,-1 c 0,0 -10,-85 -89,-92 -40,31 2,56 -3,74 C 94,468 31,426 8,367 -9,276 63,241 117,248 251,288 261,480 268,495 z" />
  <path d="m 316,4 c -104,100 -93,163 -94,209 -2,45 13,68 44,138 32,70 33,106 32,144 4,-1 13,-1 26,0 14,-1 21,-1 25,0 -1,-38 0,-74 31,-144 32,-70 46,-93 45,-138 C 423,167 420,104 316,4 z"/>
</g>', ),
   'orb' => array ( 'height' => 180, 'width' => 100,
        'body' => '<circle cx="50" cy="130" r="50" />',
        'features' => array (
              'banded' => array ( 'body' => '<path stroke-width="1" stroke="black" d="M40,130 h20 v-50 h-20 z" />
                                <path stroke-width="1" stroke="black" d="M0,130a50,50 0,0,1 1,-10 h98 a50,50 0,0,1 0,20 h-98 a50,50 0,0,1 -1,-10z" /> ' ),
              'crossed' => array ( 'body' => '<path stroke-width="2" stroke="black" d="m40,80h20v-40h20v-20h-20v-20h-20v20h-20v20h20z" />' ),
        ),
    ),
    'ermine-spot' => array ( 'height' => 200, 'width' => 111, 
      'body' => '<circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>',
      'default' => '0x050505',
     ),
  );
  $type = $node->get_attribute('subtype');
  if ( isset($symbol_data[$type]) ) {
    $retval = $symbol_data[$type];
    $retval['orient_to_ordinary'] = true;
    return $retval;
  } else {
    my_trigger_error ( "No symbol $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
