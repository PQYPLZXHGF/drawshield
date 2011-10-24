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


$ordinary = array(
      'patterns' => array (
        'pall',
      ),

      'doc' => 'Stuff...',

);

if ( $node != null ) {
  // This shape cannot be simply inverted, we actually need a different shaped to match per-pall inverted.
  if ( ($inv = get_mod_node($node,'inverted')) != null ) {
    $node->removeChild($inv);
    $ordinary['shape_spec'] = array ( 'NC' => 'X450Y-100a100C589B889d141F848D848f141H889G589', 'CH' => 'X450Y200a100C289B889d141F848D848f141H889G289' );
  } else {
    $ordinary['shape_spec'] = array ( 'NC' => 'X92Y-8B577H577a100c100D618C670e141G670F618g100a100', 'CH' => 'X92Y292B577H577a100c100D618C370e141G370F618g100a100' );
  }
}
?>
