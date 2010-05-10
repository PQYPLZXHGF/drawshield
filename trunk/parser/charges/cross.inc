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


function charge_cross ( &$node, &$mods ) {
  global $dom;
 
  $mounted = array (
    array ( true, '?mounted on' ),
  );
  $degrees = array (
    array ( true, '(degree|ascent)s?' )
  );

  $mountable = array ( 'calvary', 'patriarchal' );

  $state = save();
  if ( (in_array( $node->get_attribute('subtype'), $mountable )) and (search_match( $mounted ) != null) ) {
    if ( (($num = number()) != null ) and ( search_match( $degrees ) != null)) {
      $mods[] = make_mod('mounted', "$num");
    } else {
      restore($state);
      return null;
    }
  }
  return null;
}
?>
