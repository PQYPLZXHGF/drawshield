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

function get_cotise_tinc($node) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'modifier' and $child->getAttribute('name') == 'cotised' ) {
      if ( ($tinc = get_child($child, 'tincture')) != null )
        return deep_copy($tinc);
    }
  }
  return null;
}

function get_ordmod_array($type, $subtype, &$features, &$flags) {
  $node = null;
  $ordinary = array ();
  include ( 'ordinaries/' . $type . '/' . $subtype . '.inc' );
  if ( array_key_exists('modifiers', $ordinary) )
    $features = $ordinary['modifiers'];
  if ( array_key_exists('flags', $ordinary) )
    $flags = $ordinary['flags'];
}


function ordinary() {
  global $dom;
  global $ordinary_list;
	global $pending_items;

  // TODO Allow escutcheon to be followed by whole shield if overall?
  static $between = array ( array ( true, '(between|inter)' ),);
  static $on_word = array ( array ( true, 'on'), );
  static $charge_with = array (
    array ( 'on', 'charged with'  ),
    array ( 'on', 'thereon'  ),
  );
  static $within = array ( array ( true, '(within|inside)' ), );
  static $dep_with = array ( array ( 'depressed', '(debruised|depressed) (with|by|of)', ), );

  $node = $dom->createElement('ordinary');

  $state = save();

  // Look for "prefixes" to ordinary, then a number
  $found_on = (search_match($on_word) != null);
  $inside = (search_match($within) != null);
  $depressed = (search_match($dep_with) != null);
  if ( ($ord_num = number()) == null ) $ord_num = 1;

  get_features ( array('position'), $node ); // Sometimes you get "sinister bend ...."

  if ( ($match = either('ordinary')) != null) {
    if ($match[3] == 'either' and $ord_num > 1) {
      restore($state);
      return null;
    }
  } elseif ( ($match = search_match($ordinary_list)) == null) {
    restore($state); // Not found anything, backtrack and exit
    return null;
  } // else
  $ord_name = $match[2];
  $ord_type = $match[0];
  $ord_type = preg_replace ( '/\.inc/', '', $ord_type );
  $node->setAttribute('type',$ord_name);
  $node->setAttribute('subtype',$ord_type);
  $node->setAttribute('number',$ord_num);
  $node->setAttribute('tokens',tokens());
  if ( $depressed ) $node->appendChild( make_mod('depressed'));
  $a_key = 'o:' . $ord_type;
  // get features for this ordinary
  $specific_features = null;
  $flags = array();
  get_ordmod_array($ord_name,$ord_type,$specific_features,$flags);

  get_features ( array('shape', 'position', 'linetype', $specific_features), $node ); // for "bend sinister (angled).."

  // Have we found a tincture yet?
  if ( ($tinc = get_child($node, 'tincture')) == null ) {
    // It could be becuase this ordinary is always proper
    if ( array_key_exists('always_proper', $flags) ) {
      $tinc = $dom->createElement('tincture');
      $tinc->setAttribute('index','1');
      $proper = $dom->createElement('proper');
      $tinc->appendChild($proper);
    } elseif ( ($tinc = get_cotise_tinc($node)) != null ) { // or it could be because the tincture was concsumed by a cotised modifier
    // Don't need to do anything else
    } else { // otherwise, wait for another tincture to come along
      $tinc = $dom->createElement('tincture');
      $tinc->setAttribute('origin','pending');
      $tinc->setAttribute('index','1');
      $pending_items[] = $tinc;
    }
    $node->appendChild($tinc);
  } else {
    $tinc->setAttribute('origin','given');
  }

  // Does this ordinary go "between" some charges?
  if ( $inside or search_match($between) != null ) {
    $btwn_mod = make_mod('between');
    if ( ($btwn_charge = charge()) == null ) {
      $btwn_charge = $dom->createElement('missing');
      parser_message('blazon', 'Nothing to go between');
    }
    $btwn_mod->appendChild ( $btwn_charge);
    $node->appendChild($btwn_mod);
  }
    
  // Now look for extras
  if ( $found_on or search_match($charge_with) != null ) {
    $on_ord = make_mod('on');
    if ( $ord_type == 'chief' or $ord_type == 'canton' ) {
      $items = ordinary();
      if ( $items == null ) $items = charge(false);
      if ( $items == null ) {
        $items = $dom->createElement('missing');
        parser_message('blazon', 'Nothing to go "on" the ordinary (' . $ord_type .')' );
      }
    } else {
      $items = charge(false);
      if ( $items == null ) $items = ordinary();
      if ( $items == null ) {
        $items = $dom->createElement('missing');
        parser_message('blazon', 'Nothing to go "on" the ordinary (' . $ord_type .')' );
      }
    }
    $on_ord->appendChild($items);
    $node->appendChild($on_ord);
  }

  return $node;
}

?>
