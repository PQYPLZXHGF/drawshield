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

function proper() {
  $proper = array (
    array ( true, 'proper|ppr' ),
  );

  return (search_match($proper) != null);
}

function colour_or_fur() {
  global $dom, $p_globals;
  $plain_of = array (
    array ( true, 'of'),
  );

  $state = save();
  $dummy = search_match($plain_of);
  if ( (($temp = colour()) != null) or (($temp = fur()) != null) ) {
    $p_globals['oflast'] = deep_copy($temp);
    if ( $p_globals['offirst'] == null ) {
      $p_globals['offirst'] = deep_copy($temp);
    } elseif ( $p_globals['ofsecond'] == null ) {
      $p_globals['ofsecond'] = deep_copy($temp);
    } elseif ( $p_globals['ofthird'] == null ) {
      $p_globals['ofthird'] = deep_copy($temp);
    } elseif ( $p_globals['offourth'] == null ) {
      $p_globals['offourth'] = deep_copy($temp);
    }
  }
  if ( $temp == null )
    restore($state);
  return $temp;
}

function tincture( $lookahead = false ) {
  global $dom;

  $tinc = tincture2();
  if ( $tinc == null and $lookahead ) {
    $state = save();
    while($tinc == null and lookahead(1)) {
      $tinc = tincture2();
    }
    restore($state);
  }
  if ($tinc == null and $lookahead ) {
    $tinc = $dom->create_element('tincture');
    $tinc->append_child($dom->create_element('missing'));
    raise_error('Tincture missing');
  }
  return $tinc;
}

function tincture2() {
  global $dom, $p_globals;
  
  $backrefs = array (
    array ( 'ofsame', '(like|of|as) the same' ,),
    array ( 'oflast', '(like|of|as) the last' ,),
    array ( 'offield', '(like|of|as) the field' ,),
    array ( 'offirst', '(like|of|as) the (first|1st)' ,),
    array ( 'ofsecond', '(like|of|as) the (second|2nd)' ,),
    array ( 'ofthird', '(like|of|as) the (third|3rd)' ,),
    array ( 'offourth', '(like|of|as) the (fourth|4th)' ,),
  );

  $semyde = array (
    array ( true, 'sem(e|y)|strewn de|with|of' ),
  );
  
  $node = $dom->create_element('tincture');
  $node->set_attribute('tokNum',tokNum());

  // First look for a back reference
  if ( ($match = search_match($backrefs)) != null ) {
    if ( $p_globals[$match[0]] == null ) {
      raise_error("No previous tincture");
      $child = $dom->create_element('missing');
    } else {
      $child = deep_copy($p_globals[$match[0]]);
    }
  } elseif ( proper() ) {
    $child = $dom->create_element('proper');  
  // Look for a colour or a fur
  } elseif ( ($child = colour_or_fur()) != null ) {
    // This could be [colour] [treatment] [colour],
    // unless it is followed by a comma
    comma();
    if ( !semicolon() ) {
      if (($treat = treatment()) != null ) {
        $newNode = $dom->create_element('tincture');
        $newNode->append_child($child);
        $treat->append_child($newNode);
        $treat->append_child(tincture());
        $child = $treat;
      // could be annuletty or friends
      } elseif ( ($object = object_treatment($child)) != null ) {
        $child = $object;
      // Could also be [colour] [semyde] [charge]
      } elseif ( search_match($semyde) != null ) {
        $mods = array();
        $semyde = $dom->create_element('semyde');
        $semyde->set_attribute('name','semyde');
        $newNode = $dom->create_element('tincture');
        $newNode->append_child($child);
        $semyde->append_child($newNode);
        $charge = simple_charge( true ); // Do not worry if no number given
        $charge->append_child( make_mod('hflex','1') );  //TODO are flex modifiers used?
        $charge->append_child( make_mod('wflex','1') );
        $semyde->append_child($charge);
        $child = $semyde;
      }
    }
  // Look for annulletty and friends
  } elseif ( ($child = object_treatment()) != null ) {
    comma();
  // Look for [treatment] [colour] [colour]
  } elseif ( ($child = treatment()) != null ) {
    comma();
    $child->append_child(tincture());
    comma();
    andd();
    $child->append_child(tincture());
  // Look for counterchange
  } elseif ( ($child = counterchange()) != null ) {
    // Do nothing
  // Look for division
  } elseif ( ($child = division()) != null ) {
    // Look for a second (normally counterchanged) division
  //  if ( ( $div2 = division() ) != null ) $child->append_child($div2);
  } else {
    // Not found any, backtrack and exit
    return null;
  }
  $node->append_child($child);
  $p_globals['ofsame'] = $child;
  return $node;
}
?>
