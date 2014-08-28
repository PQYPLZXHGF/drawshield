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

function is_descendant( $item, $parent ) {
  if ( $parent->isSameNode($item) ) return true;
  foreach ( $parent->childNodes as $child )
    if ( is_descendant( $item, $child ) )
      return true;
  return false;
}

function replace_pending( $tinc ) {
  global $pending_items;

  $temp_items = array();

  foreach ( $pending_items as $item ) {
    if ( !is_descendant ( $item, $tinc ) )
      $item->appendChild(deep_copy($tinc->firstChild));
    else
      $temp_items[] = $item; // don't replace, leave for later
  }
  $pending_items = $temp_items;
}

// Look for a tincture, return a pending tincture if not found
function tincture($required=false)  {
  global $dom;
  global $pending_items;

  $tinc = tincture2();
  if ( $tinc != null ) {
    replace_pending($tinc);
  }
  if ( $tinc == null and $required ) {
    $tinc = $dom->createElement('tincture');
    $tinc->setAttribute('index', 1); // Default value, overwritten later if required.
    $tinc->setAttribute('origin', 'pending'); // Default value, overwritten later if required.
    $pending_items[] = $tinc;
  }
  return $tinc;
}

function tincture2() {
  global $dom, $p_globals;
  global $pending_items;

  static $backrefs = array (
    array ( 'ofsame', '(like|of|as) the same' ,),
    array ( 'oflast', '(like|of|as) the last' ,),
    array ( 'offield', '(like|of|as) the field' ,),
    array ( 'offirst', '(like|of|as) the (first|1st)' ,),
    array ( 'ofsecond', '(like|of|as) the (second|2nd)' ,),
    array ( 'ofthird', '(like|of|as) the (third|3rd)' ,),
    array ( 'offourth', '(like|of|as) the (fourth|4th)' ,),
  );

  static $treatments = array(
    // Field treatments
    // array ( 'lozengy',      'lozengy',  ), made this back into a division
	array ( 'plumetty',     'plumetty' ),
    array ( 'annuletty',    'annuletty',    ),
    array ( 'bezanty',      'bezant(y|e)', true ),
    array ( 'billetty',     'billetty',     ),
    array ( 'checky',       '(checky|cheque?y)' ),
    array ( 'checky9',      '(checky|cheque?y) of (nine|9)' ),
    array ( 'checky9',      'equipoll?es?' ),
    array ( 'counter-billetty',     '?billetty counter billetty', ),
    array ( 'crusilly',     'crusilly',     ),
    array ( 'estoilly',     'estoilly',    ),
	array ( 'ermined',      'ermined' ),
    array ( 'fretty',       'fretty',       ),
    array ( 'goutty',       'go?utty',     ),
    array ( 'grillage',     'grillage',     ),
    array ( 'honeycombed',  'honeycombed',  ),
    array ( 'hurty',        'hurty',       true ),
    array ( 'maily',        'maily',        ),
    array ( 'masoned',      'masoned',      ),
    array ( 'mullety',      'mullett?y',   ),
    array ( 'papelonny',    'pap(e|i)l?lonn(y|e)',    ),
    array ( 'platy',        'platy',       true ),
    array ( 'scaly',        'scaly',        ),
    array ( 'seme-de-lys',       'sem(e|y) de l(i|y)s',  ),
    array ( 'vairy',        'vair(e|y)',    ),
   // array ( 'estoile',      'estoil(e|y)', ), TODO Different from mullet of six?
//    array ( 'compony',      '(compony|gobone|gobonated)',        ),
//    array ( 'counter-compony',      'counter (compony|gobone|gobonated)',  ),
//    array ( 'fleury',       '(fleury|floretty)',  ), // This is not a treatment!!
   );

   $groupings = array (
     array ( true, 'both'),
     array ( true, 'all'),
   );

   $semyde = array (
    array ( true, 'sem(e|y)|strewn de|with|of' ),
  );

  $node = $dom->createElement('tincture');
  $node->setAttribute('index', 1);
	$node->setAttribute('origin','given');
  $child = null;

  // zeroth, discard grouping words
  search_match($groupings);

  // First look for a back reference
  if ( ($match = search_match($backrefs)) != null ) {
    if ( $p_globals[$match[0]] == null ) {
      $node->setAttribute('origin', 'missing');
      parser_message('blazon', 'No previous tincture');
    } else {
      $child = deep_copy($p_globals[$match[0]]);
			$node->setAttribute('origin','backref');
    }
  } elseif ( proper() ) {
    $child = $dom->createElement('proper');
  // Look for a colour or a fur
  } elseif ( ($child = colour_or_fur()) != null ) {
    // This could be [colour] [treatment] [colour],
    // unless it is followed by a comma
    comma();
    if ( !semicolon() ) {
      if (($match = search_match($treatments)) != null ) {
        $treat = $dom->createElement('treatment');
        $treat->setAttribute( 'name', $match[0]);
        $treat->setAttribute( 'tokens',tokens());
        $tinc1 = $dom->createElement('tincture');
        $tinc1->setAttribute('index', '1');
        $tinc1->appendChild($child);
        $treat->appendChild($tinc1);
        if ( !isset($match[2]) ) {
          $tinc2 = tincture(true);
          $tinc2->setAttribute('index', '2');
          $treat->appendChild($tinc2);
        }
        $child = $treat;
      // Could also be [colour] [semyde] [charge]
      } elseif ( search_match($semyde) != null ) {
        $semyde = $dom->createElement('semyde');
        $newNode = $dom->createElement('tincture');
        $newNode->setAttribute('index', 1);
        $newNode->appendChild($child);
        $semyde->appendChild($newNode); // TODO Handle error if no charge found
        $charge = simple_charge( true ); // Do not worry if no number given
		if ( $charge != null ) {
        $charge->appendChild( make_mod('hflex','1') );  //TODO are flex modifiers used?
        $charge->appendChild( make_mod('wflex','1') );
        $semyde->appendChild($charge);
		}
        $child = $semyde;
      }
    }
  // Look for [treatment] [colour] [colour]
  } elseif (($match = search_match($treatments)) != null ) {
    $treat = $dom->createElement('treatment');
    $treat->setAttribute( 'name', $match[0]);
    $treat->setAttribute( 'tokens',tokens());
    comma();
    $treat->appendChild(tincture(true));
    comma();
    andd();
    $tinc2 = tincture(true);
    $tinc2->setAttribute('index',2);
    $treat->appendChild($tinc2);
    $child = $treat;
  // Look for counterchange
  } elseif ( ($child = counterchange()) != null ) {
    // Do nothing
  // Look for division
  } elseif ( ($child = division()) != null ) {
    // Look for a second (normally counterchanged) division
    if ( ( $div2 = division(2) ) != null ) $child->appendChild($div2);
  } else {
    return null;
  }
  if ( $child != null ) {
    $node->appendChild($child);
    $p_globals['ofsame'] = $child;
  }
  return $node;
}
