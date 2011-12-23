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

   function get_positions ( &$node, $found_so_far = null ) { // micro-parser for positions
   // we have already found the word "in" (& maybe "the")
   static $specifiers = array (
     array ( 'first', '(first|1st)' ),
     array ( 'second', '(second|2nd)' ),
     array ( 'third', '(third|3rd)' ),
     array ( 'fourth', '(fourth|4th)' ),
     array ( 'dexter', '?each dexter' ),
     array ( 'sinister', '?each sinister' ),
     array ( 'each', '(each|every|all|both) ?of ?the' ),
     array ( 'middle', 'middle' ),
     );
   static $locations = array (
     array ( 'chief', 'chief' ),
     array ( 'base', 'base' ),
     array ( 'honpoint', 'honou?r point' ),
     array ( 'fesspoint', 'fesse? point' ),
     array ( 'nombril', 'navel point' ),
     array ( 'nombril', 'nombril' ),
     array ( 'flank', '(flanks?|flaunche?s?)' ),
     );
   static $quantifiers = array (
     array ( 'quarter', 'quarters?' ),
     array ( 'all', '(half|section|part)' ),
     );
   static $in_the = array (
     array ( null, '(in|the)' ),
     );
   
   $positions = array();
   if ( $found_so_far ) $positions[] = $found_so_far;
   while ( true ) {
     $state = save();
     $locs = array();
     $specs = array();
     $quant = null;
     search_match($in_the); // look for "in", "the", both or neither
     search_match($in_the); 
     // look for parts
     while ( ($match = search_match($specifiers)) != null ) {
       $specs[] = $match[0];
       comma();
       andd();
       search_match($in_the); // look for "in", "the", both or neither
       search_match($in_the);
     }
     while ( ($match = search_match($locations)) != null ) {
       $locs[] = $match[0];
       comma();
       andd();
     }
     if ( ($match = search_match($quantifiers)) != null ) {
       $quant = $match[0];
       comma();
       andd();
     }
     // Did we find anything?
     if ( count($locs) == 0 and count($specs) == 0 and $quant ==null ) {
       restore($state);
       break;
     }
     // Now try to combine them into positions
     if ($quant == 'quarter' ) { // one or more specific quarters
       $found_pos = false;
       foreach ( $specs as $spec ) {
         $new_position = null;
         switch ( $spec ) {
         case 'first': $new_position = 'inQ1'; break;
         case 'second': $new_position = 'inQ2'; break;
         case 'third': $new_position = 'inQ3'; break;
         case 'fourth': $new_position = 'inQ4'; break;
         case 'each': if (count($locs)==0) $new_position = 'ineachQ'; break;
         case 'dexter': $new_position = 'ineachQ13'; break;
         case 'sinister': $new_position = 'ineachQ24'; break;
         default:
         }
         if ( $new_position != null ) {
           $positions[] = $new_position;
           $found_pos = true;
         }
       }
       if ( !$found_pos ) { // do we also have a chief or base location?
         if ( in_array ( 'chief', $locs ) ) 
           $positions[] = 'ineachQ12';
         elseif ( in_array ( 'base', $locs) )
           $positions[] = 'ineachQ34';
         else
           draw_message('warning','in which quarter?');
       }
     } elseif ( count($locs) > 0 ){ // no quantifier found (or it was "all"), but we have a location
       foreach ( $locs as $location ) {
         switch ( $location ) {
         case 'flank': $positions[] = 'inflank'; break;
         case 'fesspoint': $positions[] = 'infesspoint'; break;
         case 'nombril': $positions[] = 'innombril'; break;
         case 'honpoint': $positions[] = 'inhonpoint'; break;
         case 'chief':
         case 'base':
           $count = count($positions);
           if ( in_array ('dexter',$specs) ) $positions[] = 'in' . 'dex' . $location;
           if ( in_array ('sinister',$specs) ) $positions[] = 'in' . 'sin' . $location;
           if ( in_array ('middle',$specs) ) $positions[] = 'in' . 'mid' . $location;
           if ( $count == count($positions) ) // didn't find any specs
             $positions[] = 'in' . $location;
           break;
         }
       }
     } else { // no quantifier or location, need to have "each"
       if ( in_array( 'each', $specs) ) {
         if ( in_array( 'first', $specs ) )
           $positions[] = 'ineach1st';
         elseif ( in_array( 'second', $specs) )
           $positions[] = 'ineach2nd';
         else
           $positions[] = 'ineach';
       } else {
         parser_message('warning','Do not understand position');
       }
     }
   }
   if ( count($positions)> 0 ) {
     foreach ( $positions as $position )
       $node->appendChild(make_mod('position',$position));
     return true;
   } else
     return false;
  }
           
function get_features ( $feature_sets, &$node ) {
  global $dom;
  global $pending_items;

    static $ordinary_mods = array ( // only used for ordinaries
    array ( null, 'sinister', 'mod', 'sinister' ),
    array ( null, 'reversed', 'mod', 'reversed' ),
    array ( null, 'dexter', 'mod', 'dexter', ),
    array ( null, 'inverted', 'mod', 'inverted', ),
    array ( null, 'enhanced', 'mod', 'enhanced', ),
    array ( null, '(abased|abaisse)', 'mod', 'abased', ),
  );

  static $shape_mods = array (
    array ( null, 'voided', 'shape', 'voided' ),
    array ( null, '(fimbriated|edged)', 'mod+1tinc', 'fimbriated',  ),
    array ( '1', '(cotised|cotticed|endorsed)', 'shape', 'cotised',  ),
    array ( '1', 'between # cott?ices', 'shape', 'cotised',  ),
    array ( '2', 'double (cotised|cotticed)', 'shape', 'cotised',  ),
    array ( '3', '(triple|treble) (cotised|cotticed)', 'shape', 'cotised',  ),
    array ( null, '(rompu|fracted)', 'mod', 'fracted' ),
    array ( null, 'double dancetty', 'mod', 'fracted' ), 
  );

  static $position_mods = array (
    array ( null, 'in ?the', 'in' ),
    );
  

  static $charge_mods = array ( // only used for charges
    array ( null, 'con?joined', 'mod', 'conjoin' ),
    array ( null, 'inverted', 'mod',  'inverted' ),
    array ( null, 'reversed', 'mod',  'reversed' ),
    array ( null, '(entire|firme)', 'mod',  'entire' ),
    array ( null, 'en soleil', 'mod',  'ensoleil'),
    array ( 'in', 'respecting each other', 'mod', 'facing'  ),
    array ( 'in', 'counter rampant', 'mod', 'facing'  ),
    array ( 'in', '(confronting|affrontant|combatant)', 'mod', 'facing'  ),
    array ( 'out','addorsed', 'mod', 'facing' ),
    array ( 'bendsinwise',   'bendw(ise|ays) sinister' , 'mod', 'orientation' ),
    array ( 'bendwise',      'bendw(ise|ays)', 'mod', 'orientation' ),
    array ( 'fesswise',      'fessw(ise|ays)', 'mod', 'orientation' ),
    array ( 'palewise',      'palew(ise|ays)', 'mod', 'orientation' ),
    array ( 'palewise',      'erect in pale', 'mod', 'orientation' ),
    array ( null,            'arranged', 'ignore' ),
    array ( null,            '(lying|laying)', 'ignore' ),
    array ( null, 'for difference', 'mod', 'cadency' ),
  );

  static $linetype_mods = array (
    array ( 'battled-embattled', '(battled|double) (e?m?battled|crenn?ell?e?y?)', 'mod', 'linetype',),  // two levels of battlements, on upper surface only
    array ( 'battled-embattled', '(em)?battled grady', 'mod', 'linetype',  ),
    array ( 'battled-brettesse', '(em)?battled brett?ess?e?y?', 'mod', 'linetype',  ),                // both sides, same pattern
    array ( 'battled-counter', '(e?m?battled|crenn?ell?e?y?) counter (e?m?battled|crenn?ell?e?y?)',  'mod', 'linetype', ), // both sides, opposite pattern
    array ( 'embattled', '?super (e?m?battled|crenn?ell?e?y?)',     'mod', 'linetype',   ),        // top only
    array ( 'embattled-arrondi', '(e?m?battled|crenn?ell?e?y?) arrondi',     'mod', 'linetype', ),           // top only, round crenelles
    array ( 'angled',    'angled', 'mod', 'linetype',                                ),
    array ( 'arched',    '(en)?arched',  'mod', 'linetype',                            ),
    array ( 'bevilled',    'bevill?ed',     'mod', 'linetype',                         ),
    array ( 'bevilled',    'bevill?y',     'mod', 'linetype',                         ),
    array ( 'dancetty-floretty', 'dau?ncett(e|y) flor(y|etty)' , 'mod', 'linetype',),
    array ( 'dancetty',  'dau?ncetty',         'mod', 'linetype',                       ),
    array ( 'double-arched', 'double (en)?arched',  'mod', 'linetype',      ),
    array ( 'double-arched', '(en)?arched double',  'mod', 'linetype',      ),
    array ( 'dovetailed','dovetailed',   'mod', 'linetype',                           ),
    array ( 'engrailed', 'engrailed',        'mod', 'linetype',                       ),
    array ( 'escartelly',    'escartelly',    'mod', 'linetype',                      ),
    array ( 'indented',  'indented',    'mod', 'linetype',                            ),
    array ( 'invected',  'invected',     'mod', 'linetype',                           ),
    array ( 'nebuly',    'nebuly',      'mod', 'linetype',                            ),
    array ( 'nowy' ,     'nowy',        'mod', 'linetype',                            ),
    array ( 'none',   'plain',    'mod', 'linetype',                             ),
    array ( 'potenty',   'potenty',    'mod', 'linetype',                             ),
    array ( 'raguly',    'raguly',       'mod', 'linetype',                           ),
    array ( 'rayonny',   '(rayonny|radiant)',        'mod', 'linetype',               ),
    array ( 'wavy',      '(wavy|undy)',      'mod', 'linetype',                      ),
    array ( 'urdy' ,     '(urdy|urde|champaine|champion)',   'mod', 'linetype',       ),
  );

  // these can appear before and after the charge (but only once)  
  static $arrangement_mods = array (
    array ( 'inpale',        'in ?the pale' , 'mod', 'arrangement'    ,3              ),
    array ( 'inpalethrough', 'in ?the pale throughout' , 'mod', 'arrangement' ,3        ),
    array ( 'inpall',        'in ?the pall' , 'mod', 'arrangement'   ,3                 ),
    array ( 'infess',        'in ?the fesse? !point' , 'mod', 'arrangement',3                    ),
    array ( 'infessthrough', 'in ?the fesse? throughout' , 'mod', 'arrangement'  ,3       ),
    array ( 'inbendsin',     'in ?the bend sinister' , 'mod', 'arrangement',3 ),
    array ( 'inbend',        'in ?the bend ?dexter' , 'mod', 'arrangement',3 ),
    array ( 'inchevron',     'in ?the chevron', 'mod', 'arrangement',3  ),
    array ( 'inpile',        'in ?the pile' , 'mod', 'arrangement',3 ),
    array ( 'inorle',        'in ?an orle' , 'mod', 'arrangement', 12 ),
    array ( 'inorle',        'in ?the orle' , 'mod', 'arrangement', 12 ),
    array ( 'insaltire',     'in ?the saltire' , 'mod', 'arrangement',3 ),
    array ( 'incross',       'in ?the cross' , 'mod', 'arrangement', 5),
    array ( 'counter-passant', '?in counter passant' , 'mod', 'arrangement', 4),
    array ( 'pilewise',      'pilewise', 'mod', 'arrangement', 3),
    array ( 'inbar',         '?in (bar|barwise)', 'mod',  'arrangement'),
    array ( 'inchiefthrough','in ?the chief throughout' , 'mod', 'arrangement',3   ),
    array ( 'quadrangle',    'in ?a quadrangle', 'mod', 'arrangement', 4 ),
  );

  $retval = array();
  $look_for_rows = false;
	$look_for_tinc = true;
	$pos_is_error = false;
	$arr_is_error = false;
	$max_tinc = 99;

  $features = array(
    array(null, '(and|&)', 'ignore' ), // ignore, unless part of a longer feature
  );
  foreach ( $feature_sets as $feature_set ) {
    if (is_array($feature_set)) $features = array_merge($features, $feature_set);
    elseif (is_string($feature_set)) {
      switch ( $feature_set ) {
      case 'rows':
         $look_for_rows = true;
         break;
			case 'no_tinc':
				$look_for_tinc = false;
		   	break;
		  case 'pos_is_error':
		    $pos_is_error = true;
		   // $features = array_merge($features,$position_mods);
		    break;
		  case 'need2tinc':
		    $max_tinc = 2;
		    break;
		  case 'need3tinc':
		    $max_tinc = 3;
		    break;
		  case 'need1tinc':
		    $max_tinc = 1;
		    break;
		  case 'arr_is_error':
		    $arr_is_error = true;
		   // $features = array_merge($features,$arrangment_mods);
		    break;
		  default:
		    $feature_set .= '_mods';
		    if ( isset($$feature_set) )
		      $features = array_merge($features, $$feature_set);
		    else
  		    parser_message('internal', "Unknown feature group - $feature_set");
  		  break;
  		}
    }
  }

  $tinc_index = 1;
	comma();
  andd();
  
  // Get any additional features
  while ( true ) {
    $state = save();
    if ( $features and ($match = search_match($features)) != null) {
      switch ( $match[2] ) {
      case 'in': // looks like we have a position
        if (!get_positions($node) ) {
          restore($state);
          return $retval;
        }
        $retval['found_position'] = true;
        break;
        case 'shape':
          $shape_mod = make_mod($match[3], $match[0], tokens());
          get_features(array('linetype','no_tinc'), $shape_mod);
          if ( ($tinc = tincture()) != null ) $shape_mod->appendChild($tinc);
          $node->appendChild($shape_mod);
          break;
        case 'addlinetype':
          $linemod = make_mod( $match[3], $match[0], tokens() );
          get_features(array('linetype'), $linemod);
          $node->appendChild($linemod);
          break;
        case 'feature':
          $feature = $dom->createElement('feature');
          $feature->setAttribute( 'name', $match[0]);
          $feature->setAttribute('tokens',tokens());
          $feature->appendChild(tincture(true));
          $node->appendChild($feature);
          break;
        case 'mod':
          $node->appendChild(make_mod ( $match[3], $match[0], tokens() ));
          if ( isset ( $match[4] ) ) $retval['default_number'] = $match[4];
          if ( $match[3] == 'arrangement' ) $retval['found_arrangement'] = true;
          break;
        case 'mod+1tinc':
          $mod = make_mod ( $match[3], $match[0], tokens() );
					$mod->appendChild(tincture(true));
					$node->appendChild($mod);
					break;
				case 'mod+tinc':
          $mod = make_mod ( $match[3], $match[0], tokens() );
					$tinc = tincture(true);
					$tinc->setAttribute('index','2'); // don't know of any ords that need 3 tincs...
					$node->appendChild($tinc);
					$node->appendChild($mod);
					break;
        case 'mod+charge':
          $mod = make_mod ( $match[3], $match[0], tokens() );
          if ( ($charge = charge(true)) == null ) {
            $charge = $dom->createElement('missing');
            parser_message('blazon', 'expected charge in modifier');
          } else {
            if ( $match[0] )
              $charge->setAttribute('number', $match[0] );
          }
          $mod->appendChild($charge);
          $node->appendChild($mod);
          break;
        case 'warn':
          parser_message('warning', 'Can\'t draw feature - ' . tokens());
          $node->appendChild(make_mod ( $match[3], $match[0], tokens() ));
          break;
        case 'ignore':
          break;
      }
    } elseif ( $look_for_tinc and ($max_tinc > 0) and (($tinc = tincture(false)) != null) ) {
      $tinc->setAttribute('index',"$tinc_index" );
      $tinc_index++;
      $node->appendChild($tinc);
      $max_tinc--;
    } elseif ( $look_for_rows and (($num = number( true )) != null ) ) {
      comma();
      andd();
      $rows = array($num);
      $count = 1;
      while ( ($num = number( true )) != null ) {
      	$count += 1;
        $rows[] = $num;
        if ( semicolon()) break;
        comma();
        andd();
      }
      if ( $count == 1 ) {
        restore($state);
        break;
      } elseif ( $count > 1 ) {
        $node->appendChild(make_mod ( 'rows', implode(',',$rows) ));
      }
    } else {
      break;
    }
    comma();
    //andd();
  }
  return $retval; // usually ignored, but see mod above
}


?>
