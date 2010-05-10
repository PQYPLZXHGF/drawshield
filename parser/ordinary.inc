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


function position_mods() {
  global $dom;

  $position_mods = array (
    array ( 'sinister', 'sinister', ),
    array ( 'dexter', 'dexter', ),
    array ( 'inverted', '(inverted|pendent)', ),
    array ( 'enhanced', 'enhanced', ),
    array ( 'abased', '(abased|abaisse)', ),
  );

  $nodes = array();
  $tokNum = tokNum();
  while( ($match = search_match($position_mods)) != null ) {
    $node = make_mod($match[0]);
    $node->set_attribute('tokNum',$tokNum);
    $nodes[] = $node;
    $tokNum = tokNum();
  }
  return $nodes;

}

function shape_mods() {
  global $dom;

  $shape_mods = array (
  //       modifier,     regexes
  array ( 'fimbriated', 'fimbriated',  ),
  array ( 'voided', 'voided',  ),
  array ( 'cotised', '(cotised|cotticed|endorsed)',  ),
  array ( 'cotised', 'between (2|two) cott?ices',  ),
  array ( 'double-cotised', 'double (cotised|cotticed)',  ),
  array ( 'triple-cotised', '(triple|treble) (cotised|cotticed)',  ),
  );

  $nodes = array();
  $tokNum = tokNum();
  while( ($match = search_match($shape_mods)) != null ) {
    $node = make_mod($match[0]);
    $node->set_attribute('tokNum',$tokNum);
    if ( ($linetype = linetype()) != 'none' ) $node->set_attribute('parameter1',$linetype);
    if (($tinc = tincture()) != null ) {
      $node->append_child($tinc);
    }
    $nodes[] = $node;
  }
  $tokNum = tokNum();
  return $nodes;
}

function ordinary() {
  global $dom;

  static $ordinaries = array (
    // Common
    array ( 'grid',         'grid',                         'common' ),
    array ( 'diamond',      'diamond',                      'common' ),
  //  array ( 'square',       'square',                      'common' ),
  //  array ( 'octogon',      'octogon',                      'common' ),
    array ( 'another',		'another',                      'common' ),
    array ( 'saltire',      'saltire',                      'common' ),
    array ( 'base',         'base',                         'base' ),
    array ( 'ford',         'ford',                         'base' ),
    array ( 'pale',         'pale',                         'pale' ),
    array ( 'fess',         'fesse?',                       'fess' ),
  //  array ( 'pile',         'pile',                         'common' ),
    array ( 'quarter',      'quarter',                      'common'  ),
    array ( 'gore',         'gore',                         'common'  ),
    array ( 'bend',         'bend',                         'bend' ),
    array ( 'bend',         'bar sinister',                 'bend', 'sinister' ),
    array ( 'tierce',       'tierce',                       'tierce' ),
    array ( 'label',        'label',                        'cadency' ),
    array ( 'chief',        'chief',                         'chief' ),
    array ( 'chief-triangular', 'chief-triangular',          'chief' ),
    // Diminutives
    array ( 'bar',          'humets?',                        'bar', 'couped' ),
    array ( 'palet',        'pall?et',                        'bar' ),
    array ( 'palets',        'pall?ets',                        'bar' ),
    array ( 'bendlet',      'bendlet',                      'bar' ),
    array ( 'bendlet',      'e?scarpe',                     'bar' ),
    array ( 'bendlets',      'bendlets',                      'bar' ),
    array ( 'bendlets',      'e?scarpes',                     'bar' ),
    array ( 'chevronel-braced', 'chevronel (braced|interlaced)' ,    'diminutive' ),
    array ( 'chevronel-braceds', 'chevronels (braced|interlaced)' ,    'diminutive' ),
    array ( 'bar',          '(bar|barrulet)',                          'bar' ),
    array ( 'bars',         '(bars|barrulets)',                          'bar' ),
    array ( 'bar-gemel',    '(bar|barrulet) (gemm?ell?(s|ed)?|voided)' ,  'bar' ),
    array ( 'bar-gemels',    '(bars|barrulets) (gemm?ell?(s|ed)?|voided)' ,  'bar' ),
    array ( 'chevronel',    'chevronel',                    'diminutive' ),
    array ( 'chevronels',    'chevronels?',                    'diminutive' ),
    array ( 'pile',        'pile',                          'diminutive' ),
    array ( 'piles',        'piles',                          'diminutive' ),
    // Sub-ordinaries
    array ( 'orle',         'orle',                         'subordinary'  ),
    array ( 'inescutcheon', 'inescut?cheon',                 'subordinary'  ),
    array ( 'bordure',      'bordure',                      'subordinary'  ),
    array ( 'canton',       'cantons?',                     'subordinary'  ),
    array ( 'gyron',        'gyrons?',                      'subordinary' ),
    array ( 'gusset',       'gussets?',                     'subordinary' ),
    array ( 'graft',        'grafts?',                      'subordinary' ),
    array ( 'graft',         'gussets? in base' , 'subordinary' ),
    array ( 'baton',        '(bas?ton|battoon|batune) ?sinister ?couped' ,    'subordinary' ),
    array ( 'baton-dexter', 'dexter (bas?ton|battoon|batune) ?couped' ,    'subordinary' ),
    array ( 'baton-dexter', '(bas?ton|battoon|batune) dexter ?couped',    'subordinary' ),
    array ( 'shakefork',    'shakefork',                    'subordinary' ),
    array ( 'pall',         'pall',                         'subordinary' ),
    array ( 'tressure',     'trea?s?sure',                       'subordinary' ),
    array ( 'tressure2', 'double trea?s?sure','subordinary' ),
    array ( 'flaunch',      'flau?nche?s?',                'subordinary' ),
    array ( 'flaunch',      '(flanks?|flanques?|flasques?)',  'subordinary' ),
    array ( 'square-flaunch', 'square flau?nche?s?',                'subordinary' ),
    array ( 'square-flaunch', 'square (flanks?|flanques?|flasques?)',  'subordinary' ),
  );
  // TODO Allow escutcheon to be followed by whole shield if overall?
  static $common_variants = array (
  array ( 'couped', '(couped|humetty)' ),
  array ( 'couped-base', 'couped ?in base'  ),
  array ( 'couped-chief', 'couped ?in chief' ),
  array ( 'couped-dexter', 'couped ?in dexter' ),
  array ( 'couped-sinister', 'couped ?in sinister' ),
  array ( 'lozengy', 'lozengy' ),
  array ( 'compony', '(compony|gobone|gobonated)' ),
  array ( 'counter-compony', 'counter (compony|gobone|gobonated)'),
  );
  static $between = array ( array ( true, '(between|inter)' ),);
  static $on_word = array ( array ( true, 'on'), );
  static $charge_with = array ( array ( true, 'charged with'  ), );
  static $within = array ( array ( true, '(within|inside)' ), );
  
  $state = save();

  // Look for "prefixes" to ordinary, then a number
  $found_on = (search_match($on_word) != null);
  $inside = (search_match($within) != null);
  if ( ($ord_num = number()) == null ) $ord_num = 1;
  $tokNum = tokNum();
  
  $mods = position_mods();     // Sometimes you get "sinister bend ...."

  if ( (($match = search_match($ordinaries)) == null) and (($match = either('ordinary')) == null) ) {
    restore($state); // Not found anything, backtrack and exit
    return null;
  } // else
  $ord_type = $match[0];
  $node = $dom->create_element('ordinary');
  $node->set_attribute('type',$match[2]);
  $node->set_attribute('subtype',$match[0]);
  $node->set_attribute('number',$ord_num);
  $node->set_attribute('tokNum',$tokNum);
  $node->append_child($dom->create_element('tincture'));
  if ( isset($match[3]) ) $node->append_child(make_mod($match[3]));

  $mods = array_merge($mods, position_mods()); // for "bend sinister (angled).."
  if ( ($variant = search_match($common_variants)) != null ) {
    if ( substr( $variant[0], -7) == 'compony') $node->append_child($dom->create_element('tincture'));
    $node->set_attribute('subtype', $node->get_attribute('subtype') . '-' . $variant[0] );
  }

  // Prepare the ordinary function (if it exists)
  if ( file_exists('parser/ordinaries/' . $match[2] . '.inc') ) {
    $ord_func = 'ordinary_' . $match[2];
    if ( ! function_exists($ord_func) ) {
      require_once ( 'parser/ordinaries/' . $match[2] . '.inc' );
    }
    $node = $ord_func($node, $mods);
  }

  $ord_linetype = linetype();
  $mods = array_merge($mods, position_mods()); // for "bend (angled) sinister.."
  
  // Now look for colours, linetype and shape modifiers
  if ( $ord_linetype == 'none' ) $ord_linetype = linetype();
  // Get as many tinctures as there are empty tincture elements
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->tagname() == 'tincture' and !$child->has_child_nodes() ) {
      $node->replace_child(tincture(true),$child);
    }
  }

  $mods = array_merge($mods,shape_mods());

  // Add things to the node so far
  $node->set_attribute('linetype', $ord_linetype);

  // Does this ordinary go "between" some charges?
  if ( $inside or search_match($between) != null )
    between($mods,true); // have already found between word
      
  // Now look for extras
  if ( $found_on or search_match($charge_with) != null ) {
    $on_ord = make_mod('on');
    if ( $ord_type == 'chief' or $ord_type == 'canton' ) {
      $items = ordinary();
      if ( $items == null ) $items = charge(false);
      if ( $items == null ) {
        $items = $dom->create_element('missing');
        raise_error('Nothing to go "on" the ordinary (' . $ord_type .')' );
      }
    } else {
      $items = charge(false);
      if ( $items == null ) $items = ordinary();
      if ( $items == null ) {
        $items = $dom->create_element('missing');
        raise_error('Nothing to go "on" the ordinary (' . $ord_type .')' );
      }
    }
    $on_ord->append_child($items);
    $mods[] = $on_ord;
  }
  
  foreach ( $mods as $mod ) $node->append_child($mod);
  
  return $node;
}

?>
