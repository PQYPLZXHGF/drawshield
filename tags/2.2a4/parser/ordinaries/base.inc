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

function ordinary_base( $node ) {
  global $dom;

  $type = $node->get_attribute('subtype');
  if ( $type == 'ford' ) { // this is a special
    proper(); // Can (only) be proper
    $node->set_attribute('subtype','base');
    $tinc = $dom->create_element('tincture');
    $div = $dom->create_element('division');
    $div->set_attribute('type','bar');
    $div->set_attribute('subtype','barry');
    $div->set_attribute('linetype', 'wavy');
    $azure = $dom->create_element('tincture');
    $temp = $dom->create_element('colour');
    $temp->set_attribute('name','azure');
    $azure->append_child($temp);
    $argent = $dom->create_element('tincture');
    $temp = $dom->create_element('colour');
    $temp->set_attribute('name','argent');
    $argent->append_child($temp);
    $div->append_child($argent);
    $div->append_child($azure);
    $mod = make_mod('ofnum','4');
    $div->append_child($mod);
    $tinc->append_child($div);
    $node->replace_child($tinc, $node->first_child());
  }
  return $node;
}
?>
