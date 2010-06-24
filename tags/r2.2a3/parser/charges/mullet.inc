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


function charge_mullet( &$node, &$mods ) {
  global $dom;

  $of_array = array (
    array ( 0, 'of|de' ),
  );
  $points_array = array (
    array ( 0, 'points' ),
  );
  $voided_array = array (
    array ( 0, 'voided)' ),
  );
  $pierced_array = array (
    array ( 0, '(pierced|voided)' ),
  );

  $pierced = false;
  $n = 5; // default
  $state = save();
  if ( search_match ( $of_array ) != null ) {
    if ( ($n = number()) == null ) {
      restore($state);
      return null;
    } else {
      search_match ( $points_array );
      if ( search_match( $pierced_array) != null ) $pierced = true; 
    }
  }
  if ( search_match( $pierced_array) != null ) $pierced = true; 
  if ( $n < 3 ) $n = 5;

  $mods[] = make_mod('points', "$n");
  if ( $pierced ) $mods[] = make_mod('pierced');

  return null;
}
?>
