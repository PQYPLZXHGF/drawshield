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


function between(&$mods, $found_between = false) {
  global $dom;
    
  $between_charge = array (
    array ( true, 'between|within' ),
  );
  // Does this charge go "between" some others?
  if ( $found_between or search_match($between_charge) != null ) {
    $btwn_mod = make_mod('between');
    if ( ($btwn_charge = charge()) == null ) $btwn_charge = $dom->create_element('missing');
    $btwn_mod->append_child($btwn_charge);
    $mods[] = $btwn_mod;
    while ( !semicolon() and andd() and (($btwn_charge = charge()) != null ) ) {
      $btwn_mod = make_mod('between');
      $btwn_mod->append_child($btwn_charge);
      $mods[] = $btwn_mod;
    }
  }
}


// TODO can say e.g. reed bundles. How this handled?
// TODO should generate bundles of n, not be fixed

function get_collection ( &$node, &$mods ) {

  $collect_words = array (
    // subtype, tokens, type, default subnum
    array ( 'sheaf-arrows', 'arrows?', 'weapon', 3 ),
    array ( 'bundle-reeds', 'reeds?', 'plant', 3 ),
  );
  
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
      $features = $chg_func($match[0]);
  }
    
  } else {
    raise_error ( 'unknown bundle item' );
  }
}

function get_next_word ( &$node, &$mods ) {
  global $words, $cur_word;
  
  if ($cur_word < sizeof($words)) {
    $mods[] = make_mod('item',$words[$cur_word]);
    $cur_word += 1;
  } else {
    raise_error ( 'Missing letter or digit' );
  }
}

  function get_features ( &$features, &$node, &$mods, &$subtype_features ) {
  global $dom;
  
/*  if ( $features != null and !is_array($features) ) {
    raise_error ( $features );
    return null;
  } */
  
  // Get any feature colours
  while ( $features ) {
    if ( ($match2 = search_match($features)) == null ) break;
    switch ( $match2[2] ) {
      case 'feature':
        $feature = $dom->create_element('feature');
        $feature->set_attribute('name', $match2[0]);
        $feature->append_child(tincture(true));
        $node->append_child($feature);
        break;
      case 'mod':
        $mods[] = make_mod ( $match2[3], $match2[0] );
        break;
      case 'subtype':
        $subtype = $match[0];
        $node->set_attribute('subtype',$subtype);
        if ( array_key_exists ($subtype, $subtype_features)) {
          // We allow one level of indirection
          if ( !is_array($subtype_features[$subtype])) $subtype = $subtype_features[$subtype];
          $features = array_merge($features,$subtype_features[$subtype]);
        }
        break;
      case 'ignore':
        break;
    }
    comma();
    andd();
  }
}

function simple_charge( $assume_num = false, $allow_arr_pos = false ) {
  global $dom;
  
  static $charges = null;
  static $subtype_features = null;
  static $type_features = null;
  
  $features = array();
  $mods = array();
  
  if ( $charges == null ) {
    $charges = unserialize(file_get_contents('parser/charge_data.dat'));
  }
  if ( $subtype_features == null ) {
    $subtype_features = unserialize(file_get_contents('parser/subtype_features.dat'));
  }
  if ( $type_features == null ) {
    $type_features = unserialize(file_get_contents('parser/type_features.dat'));
  }
  
  $state = save();
  
  // Look for a number
  if ( ($num = number()) == null) {
    if ( $assume_num ) {
      $num = 1;
    } else {
      restore($state);
      return null;
    }
  }
  
  $tokNum = tokNum();
  if ( (($match = either('charge')) == null) and (($match = search_match($charges)) == null ) ) {
    restore($state);
    return null;
  }
  // We have a charge
  $type = $match[2];
  $subtype = $match[0];
  $node = $dom->create_element('charge');
  $node->set_attribute('type', $type);
  $node->set_attribute('subtype', $subtype);
  $node->set_attribute('tokNum',$tokNum);
  $node->set_attribute('number',"$num");
  // Get the set of features, (if any)
  if ( array_key_exists($type, $type_features ))
    $features = $type_features[$type];
  if ( array_key_exists ($subtype, $subtype_features)) {
    // We allow one level of indirection
    if ( !is_array($subtype_features[$subtype])) $subtype = $subtype_features[$subtype];
    $features = array_merge($features,$subtype_features[$subtype]);
  }
  
  // Special (awkward!) cases
  switch ( $type ) {
    case 'collect': 
      get_collection($node, $mods);
      break;
    case 'letter':
    case 'digit':
    case 'word':
      get_next_word($node, $mods);
      break;
  }
  comma();
  get_features ( $features, $node, $mods, $subtype_features );
  comma();
  postfix($mods);
  orientation($mods);
  conjoined($mods);
  if ( $allow_arr_pos ) arr_pos($mods);

  $tinc = null;
  $need_tinc = (isset ($match[3])? $match[3] : 'find' );
  switch ( $need_tinc ) {
    case false: // only allow proper (& discard it)
      proper();
      break;
    case 'find': // Go and find one
      $tinc = tincture(true);
      break;
    default: // If you can't find one, use this colour
      if ( ($tinc = tincture(false)) == null ) {
        $tinc = $dom->create_element('tincture');
        $col = $dom->create_element('colour');
        $col->set_attribute('name',$need_tinc);
        $tinc->append_child($col);
      }
      break;
  }
  if ( $tinc ) $node->insert_before($tinc,$node->first_child());
  comma();

  get_features ( $features, $node, $mods, $subtype_features );
  
  foreach($mods as $mod) $node->append_child($mod);
  
  return $node; 
}

function charge( $assume_num = false ) {
  global $dom;

  $on_charge = array (
    array ( true, 'charged with' ),
    array ( true, 'on each' ),
  );

  $mods = array();
  $features = false;

  $state = save();

  // In case of "in chief, three whatever...
  $arr_pos = arr_pos($mods);
  inquarter($mods);
  comma();
  prefix($mods);
  comma();

  // Look for the charge itself
  if ( ($node = simple_charge( $assume_num, true )) == null ) {
    restore($state);
    return null;
  }
  // Is there anything else "on" this charge?
  if ( search_match($on_charge) != null ) {
    $on_mod = make_mod('on');
    if ( ($on_charge = simple_charge( true )) == null ) $on_charge = $dom->create_element('missing');
    $on_mod->append_child($on_charge);
    $mods[] = $on_mod;
  }
  if ( !semicolon() ) {
  
    between($mods);
  
    // In case of three whatever in chief...
    laying($mods);
    conjoined($mods);
    rows($mods);
    orientation($mods);
    if ( !$arr_pos ) arr_pos($mods);
    // If there is an explicit position, a following "between" is redundant (e.g. issue 173)
    search_match( array ( array ( null, 'between' )));
  }

  foreach( $mods as $mod) $node->append_child($mod);

  return $node;
}
?>
