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


function ordinary_cadency($node, &$mods) {
  global $dom;

  $of_de = array ( array ( true, '(of|de)' ) );
  $points = array ( array ( true, 'points' ) );

  switch ($node->get_attribute('subtype')) {
    case 'label':
      $num = 3;
      if ( search_match($of_de) != null) {
        $num = number();
        search_match($points);
        if ( $num < 1 ) $num = 1;
      }
      $mods[] = make_mod('points', "$num" );
      break;
    }

    return $node;
}
?>
