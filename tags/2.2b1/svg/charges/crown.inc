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


function makeChg_crown ( $node ) {
  $charge_data = array (
'antique' => array ( 'width' => 125, 'height' => 115, 'wflex' => 2, 'hflex' => 1.5,
'body' => '<g stroke="#000000" stroke-width="2" ><path d="M 20.5,100 0.3,27.1 27.5,76.6 28.5,8.2 54.7,71.7 66.1,0.7 82,71.4 97,10 106,76.1 125,18.8 114,98 c 1,22 -90.9,23 -93.5,2 z"   />
          <path d="M 15.3,79.7 C 29.6,73.7 88,65.2 116,80.2" fill="none"   />
          <path d="m 17,83.1 c 14,-6 71,-14.5 99,0.5" fill="none"   />
          <path d="m 21,98.4 c 13,-6 67,-14.6 93,0.5" fill="none"   />
          <path d="m 112,101 c -23,17 -82,12 -89,-1 25,-7.6 69,-11.6 89,1 z" fill="#333333"   />
</g>
', )
);
  $type = $node->get_attribute('subtype');
  if ( isset($charge_data[$type]) ) {
      return $charge_data[$type];
  } else {
    my_trigger_error ( "No crown $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
