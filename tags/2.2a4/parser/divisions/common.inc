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

function division_common( $node ) {
  global $dom;

  $div3 = array ( 'per-pall', 'per-pall-reversed', 'per-pile', 'tierced-in-fess',
    'tierced-in-pale', );

  if ( in_array($node->get_attribute('subtype'),$div3) ) {
    $node->append_child($dom->create_element('tincture'));
  }
  return $node;
}


?>
