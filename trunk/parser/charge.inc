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

function simple_charge( $assume_num = false, $allow_arr_pos = false ) {
  global $dom;
  
  static $charges = array (
    // Debugging
    array ( 'bbox', '?bounding box(es)?' ,'geometric' ),
    // Humans (or parts thereof)
    array ( 'heart', '?human hearts?', 'heart' ),
    array ( 'arm', 'arms?', 'human' ),
    array ( 'hand', '?dexter hands?','human' ),
    // Animals
    array ( 'lion', 'lion(cel)?s?', 'lion' ),
    array ( 'scallop', 'e?scallops?', 'animal' ),
    array ( 'tiger', 't(i|y)gers?', 'animal' ),
    array ( 'unicorn', 'unicorns?', 'animal' ),
    array ( 'bee', 'bees?', 'animal' ),
    array ( 'chough', '?cornish choughs?' ,'bird' ),
    array ( 'martlett', 'martletts?', 'bird' ),
    array ( 'boars-head', 'boars? heads? ?couped' ,'animal' ),
    array ( 'bears-head', 'bears? heads? ?couped' ,'animal' ),
    array ( 'stags-head', 'stags? heads? ?couped' ,'animal' ),
    array ( 'dove', 'doves?', 'bird' ),
    array ( 'crow', '(crow|daw|rook|raven)s?', 'crow' ),
    // Plants
    array ( 'rose', 'roses?', 'plant' ),
    array ( 'thistle', 'thistles?', 'plant' ),
    array ( 'trefoil', 'trefoils?', 'plant' ),
    array ( 'cinquefoil', '(cinquefoil|fraise)s?', 'plant' ),
    array ( 'reed', 'reeds?', 'plant' ),
    array ( 'columbine', 'columbines? ?pendent ?slips ?crossed ?and ?drooping', 'plant' ),
    // Long crosses
    array ( 'crosslet', '?plain crosslets?',           'cross' ),
    array ( 'long', '(latin|long|passion) cross(es)?', 'cross' ),
    array ( 'calvary', 'calvary cross' ,               'cross' ),
    array ( 'patriarchal', 'patriarchal cross' ,       'cross' ),
    // Geometric
    array ( 'lozenge', 'lozenges?' ,'geometric' ),
    array ( 'escutcheon', 'escut?cheons?' ,'geometric' ),
    array ( 'billet', 'billets?' ,'geometric' ),
    array ( 'mascle', 'mascles?' ,'geometric' ),
    array ( 'roundel', 'roundels?|roundles?' ,'geometric' ),
    array ( 'annulet', 'annulets?' ,'geometric' ),
    array ( 'crescent', 'crescents?' ,'geometric' ),
    array ( 'fusil', 'fusils?' ,'geometric' ),
    array ( 'rustre', 'rustres?' ,'geometric' ),
    array ( 'cartouche', 'cartouches?' ,'geometric' ),
    array ( 'delf', 'delfs?','geometric' ),
    array ( 'fountain', 'fountains?', 'geometric' ),
    array ( 'saltorel', 'saltorels?' ,'geometric' ),
    array ( 'goutte', 'go?uttes?' ,'geometric' ),
    array ( 'plate', 'plates?' ,'geometric' ),
    array ( 'hurt', 'hurts?' ,'geometric' ),
    array ( 'torteau', 'torteaux?'  ,'geometric' ),
    array ( 'bezant', 'bezants?' ,'geometric' ),
    array ( 'golpe', 'golpes?' ,'geometric' ),
    array ( 'pellet', 'pellets?/gunstones?/ogress(es)?' ,'geometric' ),
    array ( 'pomme', 'pommes?' ,'geometric' ),
    array ( 'triangle', 'triangles?', 'geometric' ),
    array ( 'mullet', 'm(o|u)ll?ets?', 'mullet' ),
    // Weapons  and armour
    array ( 'sword', 'swords?', 'weapon' ),
    array ( 'arrow', 'arrows?', 'weapon' ),
    array ( 'pheon', '(f|ph)eons? ?heads?','weapon' ),
    array ( 'pheon', 'arrow heads?','weapon' ),
    array ( 'broad-arrow', 'broad arrow ?heads?','weapon' ),
    array ( 'helm', 'helm(et)?s?', 'clothes' ),
    array ( 'gauntlet', 'gauntlets?', 'clothes' ),
    // Symbols
    array ( 'fleurdelys', 'fleurs? de l(y|i)s' ,'symbol' ),
    array ( 'orb', '?royal (orb|mound)', 'symbol' ),
    array ( 'ermine-spot', 'ermine spots?', 'symbol' ),
    // Tools
    array ( 'pick-axe', 'pick axes?/hews?/miners axes?', 'axe' ),
    array ( 'addice', 'addices?/carpenters? axes?', 'axe' ),
    array ( 'battle-axe', 'battle axes?/battleaxes?', 'axe' ),
    array ( 'turner-axe', 'turners? axes?', 'axe' ),
    array ( 'common-axe', '?common axes?/hatchets?', 'axe' ),
    array ( 'scythe', 'scythes?', 'tools' ),
    array ( 'water-bouget', '?water bougets?' ,'tools' ),
    // Crockery
    array ( 'cauldron', 'cauldrons?', 'crockery' ),
    array ( 'chalice', '?standing (chalice|cup)s?', 'crockery' ),
    array ( 'covered-cup', '?standing (chalice|cup)s? covered', 'crockery' ),
    array ( 'covered-cup', 'covered (chalice|cup)s?', 'crockery' ),
    array ( 'mug', 'mugs?', 'crockery' ),
    // Musical Instruments
    array ( 'clarion', 'clarions?', 'music' ),
    array ( 'harp', 'harps?', 'music' ),
    array ( 'horn', '?hunting horns?', 'music' ),
    // Clothing
    array ( 'maunche', 'maunches?', 'clothes' ),
    array ( 'buckle', 'buckles?', 'clothes' ),
    // Furniture
    array ( 'table', 'tables?', 'furniture' ),
    // Crowns
    array ( 'antique', '?antique crowns?' ,'crown' ),
    // Architecture
    array ( 'tower', 'towers?', 'architecture' ),
    array ( 'arch', 'arch(es)?', 'architecture' ),
    array ( 'altar', 'altars?', 'architecture' ),
    // Text
    array ( 'letter', 'letters?', 'letter' ),
    array ( 'digit', 'digits?', 'letter' ),
    array ( 'digit', 'numerals?', 'letter' ),
    array ( 'word', 'numbers?', 'letter' ),
    array ( 'word', 'words?', 'letter' ),
    // Misc
    array ( 'flames', 'flames ?of ?fire', 'misc' ),
    array ( 'rainbow', 'rainbows?', 'misc' ),
    // Collective nouns
    array ( 'dummy', '(sheaf|sheave|bundle|tuft)s? ?of', 'collect' ),
  );
  $features = null;
  $mods = array();

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
  $node = $dom->create_element('charge');
  $node->set_attribute('type', $match[2]);
  $node->set_attribute('subtype', $match[0]);
  $node->set_attribute('tokNum',$tokNum);
  $node->set_attribute('number',"$num");
  // Prepare the charge function (if it exists)
  if ( file_exists('parser/charges/' . $match[2] . '.inc') ) {
    $chg_func = 'charge_' . $match[2];
    if ( ! function_exists($chg_func) ) {
      require_once ( 'parser/charges/' . $match[2] . '.inc' );
    }
    $features = $chg_func($node, $mods);
  }
  comma();
  postfix($mods);
  orientation($mods);
  conjoined($mods);
  if ( $allow_arr_pos ) arr_pos($mods);

  // The tincture may have been set in the charge function, if it was set
  // 'implied' (i.e. a fixed colour) the we only allow (optionally) "proper"
  $tinc = $node->first_child();
  if ( $tinc and $tinc->tagname() == 'tincture' ) {
    $child = $tinc->first_child();
    $tagname = $child->tagname();
    if ($tagname == 'default') {
      if ( $given_tinc = tincture(false) ) {
       $node->replace_child($given_tinc,$node->first_child());
      } 
    }
    if (($tagname == 'implied') and  !proper() and tincture(false)) raise_error ( $match[0] . ' has a fixed colour' );
  } else { // if not set in the charge function, allow any tincture
    if ( $tinc ) // existing node, but not tincture
      $node->insert_before(tincture(true),$node->first_child());
    else
      $node->append_child(tincture(true));
  }
  comma();

  // Get any feature colours
  while ( $features and ($match2 = search_match($features)) != null ) {
    $feature = $dom->create_element('feature');
    $feature->set_attribute('name', $match2[0]);
    $feature->append_child(tincture(true));
    $node->append_child($feature);
    comma();
    andd();
  }
  
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
  }

  foreach( $mods as $mod) $node->append_child($mod);

  return $node;
}
?>
