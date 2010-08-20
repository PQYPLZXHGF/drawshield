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

function get_features ( &$features, &$node, &$mods ) {
  global $dom;
  
/*  if ( $features != null and !is_array($features) ) {
    raise_error ( $features );
    return null;
  } */
  
  // Get any feature colours
  while ( $features ) {
    if ( ($match = search_match($features)) == null ) break;
    switch ( $match[2] ) {
      case 'feature':
        $feature = $dom->create_element('feature');
        $feature->set_attribute('name', $match[0]);
        $feature->append_child(tincture(true));
        $node->append_child($feature);
        break;
      case 'mod':
        $mods[] = make_mod ( $match[3], $match[0] );
        break;
      case 'ignore':
        break;
    }
    comma();
    andd();
    if ($match[1] == '*') break; // Only match wildcard once
  }
}

function bundle ( &$mods ) {
  static $bundle_words = array (
    array ( 'bundle', '(sheaf|sheave|bundle|tuft)s?', 3 ),
    array ( 'bundle', 'pair', 2), // just to demonstrate different defaults really....
  );
  static $of_words = array (
    array ( true, 'of', ),
  );
  
  if ( ($match = search_match($bundle_words)) != null ) {
    $num = 0;
    if ( search_match($of_words) != null ) $num = number();
    if ( $num < 1) $num = $match[2];
    $mods[] = make_mod ( $match[0], "$num" );
  }
}

function simple_charge( $assume_num = false, $allow_arr_pos = false ) {
  global $dom;
  
  static $charge_list = null;
  static $modifier_list = null;
  
  $mods = array();
  
  if ( $charge_list == null ) {
    $charge_list = unserialize(file_get_contents('parser/charge_list.dat'));
  }
  if ( $modifier_list == null ) {
    $modifier_list = unserialize(file_get_contents('parser/modifier_list.dat'));
  }
  
  $features = array();
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
  
  // Look for grouping words (bundle of etc.)
  bundle( $mods );
  
  $tokNum = tokNum();
  if ( (($match = either('charge')) == null) and (($match = search_match($charge_list)) == null ) ) {
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
  // Look for grouping words again
  bundle( $mods );
  // Get the set of features, (if any)
  if ( array_key_exists($subtype, $modifier_list ))
    $features = $modifier_list[$subtype];
  
  comma();
  get_features ( $features, $node, $mods );
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

  get_features ( $features, $node, $mods );
  
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
