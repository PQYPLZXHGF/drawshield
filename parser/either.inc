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

  static $either = null;

  if ( $either == null ) {
    $either = array (
      // Long crosses
      array ( 'cross-formy',        'cross formy throughout',           'cross2', 'ordinary' ),
      array ( 'fillet-cross',       'cross fillet',                       'cross2', 'ordinary' ),
      array ( 'fillet-cross',       'fillet cross',                       'cross2', 'ordinary' ),
      array ( 'cross-pierced',      'cross quarter pierced',            'cross2', 'ordinary' ),
      array ( 'cross-2fretty',      'cross ?double parted ?and fretty', 'cross2', 'ordinary' ),
      array ( 'cross-3fretty',      'cross tripartite ?and fretty',  'cross2', 'ordinary' ),
      // Subordinaries
      array ( 'fret-couped',        'frets? couped' , 'common', 'ordinary' ),
    );
    $either = array_merge ( $either, unserialize(file_get_contents('parser/either_list.dat')));
  }
  
  if ( ($match = search_match($either)) == null ) return null;
  if ( $match[3] == 'either' ) { // we have a match
    list($ordinary,$charge) = explode(':',$match[2]);
    if ( $type == 'ordinary' ) {
      $match[2] = $ordinary;
    } else {
      $match[2] = $charge;
    }
  } elseif ( $match[3] != $type ) { // no match
    return null;
  }
  unset ($match[3]);
  return $match; 
}
?>