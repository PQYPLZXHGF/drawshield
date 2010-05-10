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


function fur() {
  global $dom;

$furs = array (
  array ( 'ermine',          'ermine',  ), 
  array ( 'erminois',        'erminois/or ermined sa(ble)?',   ),
  array ( 'pean',            'pean/sa(ble)? ermined or', ),
  array ( 'potent',          'potent',  ),
  array ( 'vair-in-pale',    'vair in pale', ),
  array ( 'vair-en-point',   'vair en point', ),
  array ( 'vair',            'vair',  ),
  array ( 'counter-ermine',  'ermines/counter ermine/sa(ble)? ermined arg(ent)?', ),
  array ( 'counter-vair',    'counter vair', ),
  array ( 'counter-potent',  'counter potent', ),
  array ( 'potent-counter-potent', 'potent counter potent' , ),
  array ( 'potent',          'potent',  ),
);

  $node = null;
  if ( ($match = search_match($furs)) != null ) {
    $node = $dom->create_element('fur');
    $dummy = $node->set_attribute('name', $match[0] );
  }
  return $node;
}

?>
