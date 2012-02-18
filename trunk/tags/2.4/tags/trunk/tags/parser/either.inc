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

function either( $type ) {
  global $dom;
  global $either_list;

  if ( ($match = search_match($either_list)) == null ) return null;
  if ( $match[3] == 'either' ) { // we have a match
    list($charge,$ordinary) = explode(':',$match[0]);
    if ( $type == 'ordinary' ) {
      $match[0] = $ordinary;
    } else {
      $match[0] = $charge;
    }
    list($charge,$ordinary) = explode(':',$match[2]);
    if ( $type == 'ordinary' ) {
      $match[2] = $ordinary;
    } else {
      $match[2] = $charge;
    }
  } elseif ( $match[3] != $type ) { // no match
    return null;
  }
//  unset ($match[3]);
  return $match; 
}
?>
