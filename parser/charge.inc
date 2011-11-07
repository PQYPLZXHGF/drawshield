<?php 

  /* Copyright 2010 Karl R. Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

function adjacent(&$node, $found_between = false) {
  global $dom;

  static $adjacent_charge = array (
    array ( true, 'between', 'between' ),
    array ( true, 'within', 'within' ),
    array ( true, 'above', 'above' ),
    array ( true, 'below', 'below' ),
    array ( true, 'with', 'below' ),
  );
  // Does this charge go "between/above/below" some others?
  if ( $found_between )
    $position = 'between';
  elseif (( $match = search_match($adjacent_charge)) != null )
    $position = $match[2];
  else
    return;

  $adj_mod = make_mod($position);
  if ( $position == 'within' ) { // could be charge or ordinary
    if ( (($adj_charge = charge()) == null) and (($adj_charge = ordinary()) == null) ){
      $adj_charge = $dom->createElement('missing');
      parser_message('blazon', 'Nothing to go within');
    }
  } else { // 'between' can only be a charge
    if ( ($adj_charge =  charge()) == null ) {
      $adj_charge = $dom->createElement('missing');
      parser_message('blazon', 'Nothing to go between');
    }
  }
  $adj_mod->appendChild ( $adj_charge);
  $node->appendChild($adj_mod);
  // keep looking for more of the same
  while ( !semicolon() and andd() and (($adj_charge = charge()) != null ) ) {
    $adj_mod = make_mod($position);
    $adj_mod->appendChild($adj_charge);
    $node->appendChild($adj_mod);
  }
}

function bundle ( &$node ) {
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
    $node->appendChild( make_mod ( $match[0], "$num" ));
  }
}

function get_feature_tinc($node) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'feature' ) {
      if ( ($tinc = get_child($child, 'tincture')) != null )
        return deep_copy($tinc);
    }
  }
  return null;
}

function get_modifier_array($type, $subtype, &$features, &$flags) {
  $node = null;
  $charge = array ();
  include ( 'charges/' . $type . '/' . $subtype . '.inc' );
  if ( array_key_exists('modifiers', $charge) )
    $features = $charge['modifiers'];
  if ( array_key_exists('flags', $charge) )
    $flags = $charge['flags'];
}


function simple_charge( $assume_num = false, $allow_arr = false, $allow_pos = false ) {
  global $dom;
  global $charge_list;
  global $pending_items;

  static $prefix_features = array (
    array ( null, '(demi|half)', 'mod', 'demi' ),
    array ( null, 'like', 'mod', 'like' ), // not sure whether this has any real meaning, but added as mod just in case
  );
  $specific_features = null;
  $flags = array();
  $state = save();

  // Look for a number
  if ( ($num = number()) == null) {
    if ( $assume_num ) {
      if ( is_int($assume_num) )
        $num = $assume_num;
      else
        $num = 1;
    } else {
      restore($state);
      return null;
    }
  }

  $node = $dom->createElement('charge');

  // Look for grouping words (bundle of etc.)
  bundle( $node );
  get_features(array($prefix_features, 'no_tinc'), $node);

  if ( (($match = either('charge')) == null) and (($match = search_match($charge_list)) == null ) ) {
    restore($state);
    return null;
  }
  // We have a charge
  $type = $match[2];
  $subtype = $match[0];
  $node->setAttribute('type', $type);
  $node->setAttribute('subtype', $subtype);
  $node->setAttribute('tokens',tokens());
  $node->setAttribute('number',"$num");
  $a_key = 'c:' . $subtype;
  // Get the set of features and flags, (if any)
  get_modifier_array($type,$subtype,$specific_features,$flags);

  // Sometimes we want to just get the next word as a string
  if ( array_key_exists('get_item', $flags))
    $node->appendChild( make_mod('item',get_tokens($flags['get_item'])));

  // Look for grouping words again
  bundle( $node );

  $mod_set = array ('charge', 'rows', $specific_features);
  $mod_set[] = ($allow_arr) ? 'arrangement' : 'arr_is_error';
  $mod_set[] = ($allow_pos) ? 'position' : 'pos_is_error';

  get_features ( $mod_set, $node );

  // Have we found a tincture yet?
  if ( ($tinc = get_child($node, 'tincture')) == null ) {
    if ( array_key_exists('always_proper', $flags) ) {
      $tinc = $dom->createElement('tincture');
      $proper = $dom->createElement('proper');
      $tinc->setAttribute('index','1');
      $tinc->setAttribute('origin','proper');
      $tinc->appendChild($proper);
    } elseif ( array_key_exists('default_colour', $flags)) {
        $tinc = make_colour($flags['default_colour']);
        $tinc->setAttribute('index','1');
        $tinc->setAttribute('origin','default');
    } elseif ( ($tinc = get_feature_tinc($node)) != null ) { // or it could be because the tincture was consumed by a feature
    // Don't need to do anything else
    } else { // Not proper, and no default
      $tinc = $dom->createElement('tincture');
      $tinc->setAttribute('origin','pending');
      $tinc->setAttribute('index','1');
      $pending_items[] = $tinc;
    }
    $node->appendChild($tinc);
  } else {
    $tinc->setAttribute('origin','given');
  }

  return $node;
}

function charge( $assume_num = false, $allow_arr = true, $allow_pos = true ) {
  global $dom;

  $on_charge = array (
    array ( 'charged-with', 'charged with' ),
    array ( 'charged-with', 'on each' ),
    array ( 'charged-with', 'surmounted by' ),
  );

  $on_prefix = array (
    array ( true, 'on' ),
  );

  $state = save();

  // In case of "in chief, three whatever...
  $temp = $dom->createElement('charge'); 
  $found = get_features( array ( 'arrangement', 'position', 'no_tinc' ), $temp );
  foreach ( $found as $key => $value ) {
    switch ( $key ) {
    case 'default_number': 
        $assume_num = $value;
        break;
      case 'found_position':
        $allow_pos = false;
        break;
      case 'found_arrangement':
        $allow_arr = false;
        break;
    }
	}

  $found_on = search_match($on_prefix);

  // Look for the charge itself
  if ( ($node = simple_charge( $assume_num, $allow_arr, $allow_pos )) == null ) {
    restore($state);
    return null;
  }
  // Copy over anything found earlier
  copy_children($temp,$node);

  // Is there anything else "on" this charge?
  if ( $found_on or ($match = search_match($on_charge)) != null ) {
    $on_mod = make_mod($match[0]);
    if ( ($on_charge = simple_charge( true, true, false )) == null ) {
      $on_charge = $dom->createElement('missing');
      parser_message('blazon', 'Nothing for charge to go on');
    }
    $on_mod->appendChild($on_charge);
    $node->appendChild($on_mod);
  }
  // look for charge "on" charge (but can also be end of charge, with "on" belonging to next item)
  $state = save();
  if ( search_match($on_prefix) ) {
    if ( ($on_charge = simple_charge( true, true, false )) == null ) {
      restore($state);
    } else { // swap chargeA on chargeB to become chargeB charged with chargeA
      $on_mod = make_mod('charged-with');
      $on_mod->appendChild($node);
      $on_charge->appendChild($on_mod);
      $node = $on_charge;
    }
  }
  if ( !semicolon() ) {

    adjacent($node);

    // If there is an explicit position, a following "between" is redundant (e.g. issue 173)
    search_match( array ( array ( null, 'between' )));
  }

  return $node;
}
?>
