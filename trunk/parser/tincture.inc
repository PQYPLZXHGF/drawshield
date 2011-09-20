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

function tincture( $lookahead = false, $required = false ) {
  global $dom;

  $tinc = tincture2();
  if ( $tinc == null and $lookahead ) {
    $state = save();
    while($tinc == null and lookahead(1)) {
      $tinc = tincture2();
    }
    restore($state);
  }
  if ($tinc == null and $required ) {
    $tinc = $dom->createElement('tincture');
    $tinc->setAttribute('index', 1); // Default value, overwritten later if required.
    $tinc->appendChild ( $dom->createElement('missing'));
    parser_message('blazon', 'Tincture missing');
  }
  return $tinc;
}

function tincture2() {
  global $dom, $p_globals;

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
    // 'plumetty', how to draw this one?
    // array ( 'lozengy',      'lozengy',  ), made this back into a division
    array ( 'checky',       '(checky|cheque?y)' ),
    array ( 'papelonny',    'pap(e|i)l?lonn(y|e)',    ),
    array ( 'scaly',        'scaly',        ),
    array ( 'compony',      '(compony|gobone|gobonated)',        ),
    array ( 'compony',      'counter (compony|gobone|gobonated)',  ),
    array ( 'fretty',       'fretty',       ),
    array ( 'grillage',     'grillage',     ),
    array ( 'honeycombed',  'honeycombed',  ),
    array ( 'maily',        'maily',        ),
    array ( 'masoned',      'masoned',      ),
    array ( 'crusilly',     'crusilly',     ),
    array ( 'vairy',        'vair(e|y)',    ),
    array ( 'annuletty',    'annuletty',    ),
    array ( 'billetty',     'billetty',     ),
    array ( 'counter-billetty',     'billetty counter billetty', ),
    array ( 'estoilly',     'estoilly',    ),
    array ( 'fleury',       '(fleury|floretty)',  ),
    array ( 'fleury',       'sem(e|y) de l(i|y)s',  ),
    array ( 'goutty',       'go?utty',     ),
    array ( 'bezanty',      'bezant(y|e)', true ),
    array ( 'platy',        'platy',       true ),
    array ( 'hurty',        'hurty',       true ),
    array ( 'mullety',      'mullett?y',   ),
   // array ( 'estoile',      'estoil(e|y)', ), TODO Different from mullet of six?
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

  // zeroth, discard grouping words
  search_match($groupings);

  // First look for a back reference
  if ( ($match = search_match($backrefs)) != null ) {
    if ( $p_globals[$match[0]] == null ) {
      parser_message('blazon', 'No previous tincture');
      $child = $dom->createElement('missing');
    } else {
      $child = deep_copy($p_globals[$match[0]]);
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
          $tinc2 = tincture(false,true);
          $tinc2->setAttribute('index', '2');
          $treat->appendChild($tinc2);
        }
        $child = $treat;
      // Could also be [colour] [semyde] [charge]
      } elseif ( search_match($semyde) != null ) {
        $semyde = $dom->createElement('semyde');
//        $semyde->setAttribute('name','semyde');
        $newNode = $dom->createElement('tincture');
        $newNode->setAttribute('index', 1);
        $newNode->appendChild($child);
        $semyde->appendChild($newNode);
        $charge = simple_charge( true ); // Do not worry if no number given
        $charge->appendChild( make_mod('hflex','1') );  //TODO are flex modifiers used?
        $charge->appendChild( make_mod('wflex','1') );
        $semyde->appendChild($charge);
        $child = $semyde;
      }
    }
  // Look for [treatment] [colour] [colour]
  } elseif (($match = search_match($treatments)) != null ) {
    $treat = $dom->createElement('treatment');
    $treat->setAttribute( 'name', $match[0]);
    $treat->setAttribute( 'tokens',tokens());
    comma();
    $treat->appendChild(tincture(false,true));
    comma();
    andd();
    $tinc2 = tincture(false,true);
    $tinc2->setAttribute('index',2);
    $treat->appendChild($tinc2);
    $child = $treat;
  // Look for counterchange
  } elseif ( ($child = counterchange()) != null ) {
    // Do nothing
  // Look for division
  } elseif ( ($child = division()) != null ) {
    // Look for a second (normally counterchanged) division
  //  if ( ( $div2 = division() ) != null ) $child->appendChild($div2);
  } else {
    // Not found any, backtrack and exit
    return null;
  }
  $node->appendChild($child);
  $p_globals['ofsame'] = $child;
  return $node;
}
?>
