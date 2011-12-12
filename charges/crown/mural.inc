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
  'mural (crown|coronet)s?',
  ),
  
  'modifiers' => array (
    array ( 'masoned', 'masoned', 'feature', ),
   ),

  'wflex' => 1.2,
  'hflex' => 1.2,
  'proper' => rgb('gold'),
  'file' => 'inkscape/mural.svg',
  
  'features' => array ( 'masoned' => array ( 'proper' => rgb('sable'), 'colour' => rgb('sable'))),

);

// Special form of masoned treatment
global $dom;

if ( $node != null ) {
  $tinc = get_tincture($node);
  $col = $tinc->firstChild;
  if ($col->nodeName == 'treatment' and $col->getAttribute('name') == 'masoned') {
    $col1 = get_tincture($col,1);
    $col2 = get_tincture($col,2);
    $node->replaceChild($col1,$tinc);
    $feature = $dom->createElement('feature');
    $feature->setAttribute('name','masoned');
    $feature->appendChild($col2);
    $node->appendChild($feature);
  }
}
?>
