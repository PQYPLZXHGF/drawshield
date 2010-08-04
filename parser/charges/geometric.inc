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


function charge_geometric( &$node, &$mods ) {
 
  $charge_data = array (
   'fountain' => array (
      array ( null, 'barry wavy of six argent ?and azure', 'ignore' ),
      ),
    'triangle' => array (
      array ( 'triangle-voided', 'voided', 'subtype' ),
      ),
    'chevron' => array ( 
        array ( 'chevron-sinister', 'couched sinister', 'subtype' ),
        array ( 'chevron-dexter', 'couched dexter', 'subtype' ),
       ),
    'crescent' => array (
         array ( null, 'pendent', 'mod', 'inverted' ),
       ),
    'annulet' => array (
         array ( null, 'one (within|inside) ?the other', 'mod', 'concentric' ),
       ),
  );
  $subtype = $node->get_attribute('subtype');

  if ( array_key_exists($subtype, $charge_data) ) {
    return $charge_data[$subtype];
  } else {
    return null;
  }
}
?>