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

$charge['modifiers'] = array (
    array ( null, 'voided', 'mod', 'voided' ),
    array ( null, 'pierced', 'mod', 'pierced' ),
    array ( null, '(fimbriated|edged)', 'mod+1tinc', 'fimbriated' ),
    array ( 'all', 'fitch(y|ee)', 'mod', 'fitchy' ),
    array ( 'foot', 'fitch(y|ee) at ?the foot', 'mod', 'fitchy' ),
    array ( null, '?on ?the (upper|lower|side) ?limbs?', 'warn', 'limbs' ),
    array ( null, '(at|on) each (corner|limb)', 'mod+charge', 'oneach' ),
    array ( null, 'ringed', 'warn', 'ringed' ),
);

$charge['file'] = 'inkscape/compass-rose.svg'; // Overridden by code

if ( $node != null ) {
  $cross = $node->getAttribute('subtype');
  $path = 'charges/' . $node->getAttribute('type');
  // Careful of the order here, first match wins!
  $filename = "inkscape/$cross.svg";
  if (get_mod($node,'fitchy') == 'foot' and file_exists($path . "/inkscape/$cross-fitchy-foot.svg"))
    $filename = "inkscape/$cross-fitchy-foot.svg";
  elseif (get_mod($node,'fitchy') and file_exists($path . "/inkscape/$cross-fitchy.svg"))
  $filename = "inkscape/$cross-fitchy.svg";
  elseif (get_mod($node,'voided') and file_exists($path . "/inkscape/$cross-voided.svg"))
    $filename = "inkscape/$cross-voided.svg";
  elseif (get_mod($node,'pierced') and file_exists($path . "/inkscape/$cross-pierced.svg"))
    $filename = "inkscape/$cross-pierced.svg";
  $charge['file'] = $filename;
}
