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


function ordinary_bar($node, &$mods) {
  global $dom;

  $bar_ids = array (
    array ( 'first',    'the (dexter|first|1st|upper|higher) ?(one|1)' ),
    array ( 'last',     'the (sinister|last|lower|lowest) ?(one|1)'  ),
    array ( 'inner',    'the (inner|inside) ?ones?'  ),
    array ( 'outer',    'the (outer|outside) ?ones?'  ),
  );
  if ( (substr($node->get_attribute('subtype'),-1) == 's') and ($node->get_attribute('number') == '1') ) {
    $node->set_attribute('number','4');
  }
 
  while ( ($match = search_match($bar_ids)) != null ) $mods[] = make_mod($match[0], linetype());

  return $node;
}
?>
