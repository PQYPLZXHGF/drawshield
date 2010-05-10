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

  static $either = array (
    // Long crosses
    array ( 'tau',                'tau ?cross(es)?',               'cross', 'charge' ),
    array ( 'tau',                'cross(es)? ?of (saint|st) anthony', 'cross', 'charge' ),
    array ( 'cross-formy',        'cross formy throughout',           'cross2', 'ordinary' ),
    array ( 'fillet-cross',       'cross fillet',                       'cross2', 'ordinary' ),
    array ( 'fillet-cross',       'fillet cross',                       'cross2', 'ordinary' ),
    array ( 'cross-pierced',      'cross quarter pierced',            'cross2', 'ordinary' ),
    array ( 'cross-2fretty',      'cross ?double parted ?and fretty', 'cross2', 'ordinary' ),
    array ( 'cross-3fretty',      'cross tripartite ?and fretty',  'cross2', 'ordinary' ),
    array ( 'cross',              '?plain cross(es)? ?passant',                    'cross/cross', 'either' ),
    // Quadrate crosses
    array ( 'cross-botonny',      'cross(es)? (botonny|trefle)',  'quadrate', 'charge' ),
    array ( 'cross-pointed',      'cross(let|lets|es)? pointeds?',  'quadrate', 'charge' ),
    array ( 'cross-flory',        'cross(let|lets|es)? florys?',      'quadrate', 'charge' ),
    array ( 'cross-pomme',        'cross(let|lets|es)? pommes?',      'quadrate', 'charge' ),
    array ( 'cross-potent',       'cross(es)? potent',             'quadrate', 'charge' ),
    array ( 'cross-floretty',     'cross(let|lets|es)? florettys?', 'quadrate', 'charge' ),
    array ( 'cross-paty-floretty','cross(let|lets|es)? paty florettys?', 'quadrate', 'charge' ),
    array ( 'cross-fourche',      'cross(let|lets|es)? fourche', 'quadrate', 'charge' ),
    array ( 'cross-moline',       'cross(let|lets|es)? (molines?|ancre|anchory)','quadrate', 'charge' ),
    array ( 'maltese-cross',      'maltese cross(let|lets|es)?',   'quadrate', 'charge' ),
    array ( 'maltese-cross',      'cross(let|lets|es)? of (8|eight|huit) points','quadrate', 'charge' ),
    array ( 'cross-cercele',      'cross(let|lets|es)? (re)?cerceles?','quadrate', 'charge' ),
    array ( 'cross-patonce',      'cross(let|lets|es)? patonces?', 'quadrate', 'charge' ),
    array ( 'cross-formy',        'cross(let|lets|es)? (formy|patt?y)', 'quadrate',   'charge' ),
    array ( 'cross-formy',        'cross(let|lets|es)? (formee|pattee)', 'quadrate',   'charge' ),
    array ( 'cross-cleche',       'cross(let|lets|es)? (cleche|urde)', 'quadrate',   'charge' ),
    array ( 'cross-crosslet',     'cross(es)? crosslets?',         'quadrate', 'charge' ),
    array ( 'fylfot',             'cross(es)? potent rebated',        'quadrate', 'charge' ),
    array ( 'fylfot',             'cross(es)? gammadions?',                'quadrate', 'charge' ),
    array ( 'fylfot',             'fylfots?',                                         'quadrate', 'charge' ),
    // Chevrons
    array ( 'chevron',            'chevrons?', 'chevron/geometric', 'either' ),
    // Subordinaries
    array ( 'fret', 'frets?',     'subordinary/geometric', 'either' ),
    array ( 'fret-couped',        'frets? couped' , 'common', 'ordinary' ),
  );

  $state = save();
  if ( ($match = search_match($either)) == null ) return null;
  if ( $match[3] == 'either' ) { // we have a match
    list($ordinary,$charge) = explode('/',$match[2]);
    if ( $type == 'ordinary' ) {
      $match[2] = $ordinary;
    } else {
      $match[2] = $charge;
    }
  } elseif ( $match[3] != $type ) { // no match
    return null;
  }
  return $match; 
}
?>
