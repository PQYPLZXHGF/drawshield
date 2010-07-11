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

function charge_symbol ( &$node, &$mods ) {
  global $dom;
  
  $charge_data = array (
   'orb' => array (
      array ( 'banded', 'banded|encircled' ),
      array ( 'crossed', 'crossed/ensigned with a cross' ),
    ),
  );
  $subtype = $node->get_attribute('subtype');

  if ( $subtype == 'ermine-spot' ) {
    $tinc = $dom->create_element('tincture');
    $imp = $dom->create_element('default');
    $tinc->append_child($imp);
    $node->append_child($tinc);
  }
  if ( array_key_exists($subtype, $charge_data) ) {
    return $charge_data[$subtype];
  } else {
    return null;
  }
}
?>
