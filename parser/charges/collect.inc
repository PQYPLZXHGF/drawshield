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

// TODO can say e.g. reed bundles. How this handled?
// TODO should generate bundles of n, not be fixed

function charge_collect ( &$node, &$mods ) {

  $collect_words = array (
    // subtype, tokens, type, default subnum
    array ( 'sheaf-arrows', 'arrows?', 'weapon', 3 ),
    array ( 'bundle-reeds', 'reeds?', 'plant', 3 ),
  );
  $features = null;
  
  $subnum = number();

  if ( ($match = search_match($collect_words)) != null ) {
    if ($subnum == null) $subnum = $match[3];
    $node->set_attribute('subtype', $match[0]);
    $node->set_attribute('type', $match[2]);
    $mods[] = make_mod('subnum',$subnum);  
    // Prepare the charge function (if it exists)
    if ( file_exists('parser/charges/' . $match[2] . '.inc') ) {
      $chg_func = 'charge_' . $match[2];
      if ( ! function_exists($chg_func) ) {
        require_once ( 'parser/charges/' . $match[2] . '.inc' );
      }
      $features = $chg_func($node, $mods);
  }
    
  } else {
    raise_error ( 'unknown bundle item' );
  }

  return $features;
}
?>
