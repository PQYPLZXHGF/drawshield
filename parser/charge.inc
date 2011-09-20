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

function adjacent(&$mods, $found_between = false) {
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
  $mods[] = $adj_mod;
  // keep looking for more of the same
  while ( !semicolon() and andd() and (($adj_charge = charge()) != null ) ) {
    $adj_mod = make_mod($position);
    $adj_mod->appendChild($adj_charge);
    $mods[] = $adj_mod;
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
  global $flag_list;
  global $charge_list;
  global $modifier_list;

  $mods = array();
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

  // Look for grouping words (bundle of etc.)
  bundle( $mods );

  if ( (($match = either('charge')) == null) and (($match = search_match($charge_list)) == null ) ) {
    restore($state);
    return null;
  }
  // We have a charge
  $type = $match[2];
  $subtype = $match[0];
  $node = $dom->createElement('charge');
  $node->setAttribute('type', $type);
  $node->setAttribute('subtype', $subtype);
  $node->setAttribute('tokens',tokens());
  $node->setAttribute('number',"$num");
  $a_key = 'c:' . $subtype;
  // Get the set of features and flags, (if any)
  if ( array_key_exists($a_key, $modifier_list ))
    $specific_features = $modifier_list[$a_key];
  if ( array_key_exists($a_key, $flag_list ))
    $flags = $flag_list[$a_key];

  // Sometimes we want to just get the next word as a string
  if ( array_key_exists('get_item', $flags))
    $mods[] = make_mod('item',get_tokens($flags['get_item']));

  // Look for grouping words again
  bundle( $mods );

  comma();
  $tinc = tincture(true, false); // Look for a tincture immediately following charge
  get_features ( array($specific_features), $node );
  comma();
  postfix($mods);
  orientation($mods);
  conjoined($mods);
  if ( $allow_arr_pos ) arr_pos($mods);


  if ( array_key_exists('always_proper', $flags) ) {
    $tinc = $dom->createElement('tincture');
    $proper = $dom->createElement('proper');
    $tinc->appendChild($proper);
    proper();
  } elseif ( array_key_exists('default_colour', $flags)) {
      if ( ($tinc = tincture(false)) == null )
        $tinc = make_colour($flags['default_colour']);
  } elseif ( $tinc == null ) { // if not found a tincture yet, go get one
    $tinc = tincture(true, true);
  }
  $node->appendChild($tinc);

  comma();

  get_features ( array($specific_features), $node );

  foreach($mods as $mod) $node->appendChild($mod);

  return $node;
}

function charge( $assume_num = false ) {
  global $dom;

  $on_charge = array (
    array ( true, 'charged with' ),
    array ( true, 'on each' ),
    array ( true, 'surmounted by' ),
  );

  $on_prefix = array (
    array ( true, 'on' ),
  );

  $mods = array();
  $features = false;

  $state = save();

  // In case of "in chief, three whatever...
  $arr_pos = arr_pos($mods);
  if ( is_int($arr_pos) ) $assume_num = $arr_pos;
  inquarter($mods);
  comma();
  prefix($mods);
  comma();

  $found_on = search_match($on_prefix);

  // Look for the charge itself
  if ( ($node = simple_charge( $assume_num, true )) == null ) {
    restore($state);
    return null;
  }
  // Is there anything else "on" this charge?
  if ( $found_on or search_match($on_charge) != null ) {
    $on_mod = make_mod('on');
    if ( ($on_charge = simple_charge( true )) == null ) {
      $on_charge = $dom->createElement('missing');
      parser_message('blazon', 'Nothing for charge to go on');
    }
    $on_mod->appendChild($on_charge);
    $mods[] = $on_mod;
  }
  if ( !semicolon() ) {

    adjacent($mods);

    // In case of three whatever in chief...
    postfix($mods);
    laying($mods);
    conjoined($mods);
    rows($mods);
    orientation($mods);
    if ( !$arr_pos ) arr_pos($mods);
    // If there is an explicit position, a following "between" is redundant (e.g. issue 173)
    search_match( array ( array ( null, 'between' )));
  }

  foreach( $mods as $mod) $node->appendChild($mod);
  return $node;
}
?>
