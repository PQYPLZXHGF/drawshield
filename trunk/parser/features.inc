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


function get_features ( $feature_sets, &$node ) {
  global $dom;
  global $pending_items;

    static $position_mods = array (
    array ( null, 'sinister', 'mod', 'sinister' ),
    array ( null, 'reversed', 'mod', 'reversed' ),
    array ( null, 'fracted', 'mod', 'fracted' ), // Not really a position, but syntactically it fits in here
    array ( null, 'dexter', 'mod', 'dexter', ),
    array ( null, 'inverted', 'mod', 'inverted', ),
    array ( null, 'enhanced', 'mod', 'enhanced', ),
    array ( null, '(abased|abaisse)', 'mod', 'abased', ),
  );

  static $shape_mods = array (
    array ( null, 'voided', 'shape', 'voided' ),
    array ( null, '(fimbriated|edged)', 'shape', 'fimbriated',  ),
    array ( '1', '(cotised|cotticed|endorsed)', 'shape', 'cotised',  ),
    array ( '1', 'between # cott?ices', 'shape', 'cotised',  ),
    array ( '2', 'double (cotised|cotticed)', 'shape', 'cotised',  ),
    array ( '3', '(triple|treble) (cotised|cotticed)', 'shape', 'cotised',  ),
  );

  static $charge_prefix = array (
    array ( 'inquarter1',    'in ?the (first|1st|i) ?quarter', 'mod', 'position' ),
    array ( 'inquarter2',    'in ?the (second|2nd|ii) ?quarter', 'mod', 'position' ),
    array ( 'inquarter3',    'in ?the (third|3rd|iii) ?quarter', 'mod', 'position' ),
    array ( 'inquarter4',    'in ?the (fourth|4th|iv) ?quarter', 'mod', 'position' ),
    array ( null, 'demi|half', 'mod', 'demi' ),
  );

  static $simple_charge = array (
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
    array ( null,            'arranged', 'ignore' ),
    array ( null,            '(lying|laying)', 'ignore' ),
  );

  static $linetype_mods = array (
    //
     array ( 'angled',    'angled', 'mod', 'linetype',                                ),
     array ( 'arched',    '(en)?arched',  'mod', 'linetype',                            ),
     array ( 'battled-embattled', 'battled embattled', 'mod', 'linetype',),
     array ( 'battled-embattled', '(em)?battled grady', 'mod', 'linetype',  ),
     array ( 'battled-counter', '(em)?battled counter embattled',  'mod', 'linetype', ),
     array ( 'bevilled',    'bevilled',     'mod', 'linetype',                         ),
    // array ( 'dancetty-floretty', 'dancetty floretty' , 'mod', 'linetype',),
     array ( 'dancetty',  'dau?ncetty',         'mod', 'linetype',                       ),
     array ( 'double-arched', 'double arched',  'mod', 'linetype',      ),
     array ( 'dovetailed','dovetailed',   'mod', 'linetype',                           ),
     array ( 'embattled', 'embattled',     'mod', 'linetype',                          ),
     array ( 'engrailed', 'engrailed',        'mod', 'linetype',                       ),
     array ( 'escartelly',    'escartelly',    'mod', 'linetype',                      ),
     array ( 'indented',  'indented',    'mod', 'linetype',                            ),
     array ( 'invected',  'invected',     'mod', 'linetype',                           ),
     array ( 'nebuly',    'nebuly',      'mod', 'linetype',                            ),
     array ( 'nowy' ,     'nowy',        'mod', 'linetype',                            ),
     array ( 'potenty',   'potenty',    'mod', 'linetype',                             ),
     array ( 'raguly',    'raguly',       'mod', 'linetype',                           ),
     array ( 'rayonny',   '(rayonny|radiant)',        'mod', 'linetype',               ),
     array ( 'urdy' ,     '(urdy|urde|champaine|champion)',   'mod', 'linetype',       ),
     array ( 'wavy',      '(wavy|undy)',      'mod', 'linetype',                      ),
  );

  static $arr_pos_mods = array (
    array ( 'inpale',        'in ?the pale' , 'mod', 'arrangement'    ,3              ),
    array ( 'inpalethrough', 'in ?the pale throughout' , 'mod', 'arrangement' ,3        ),
    array ( 'inpall',        'in ?the pall' , 'mod', 'arrangement'   ,3                 ),
    array ( 'infess',        'in ?the fesse?' , 'mod', 'arrangement',3                    ),
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
    array ( 'inflank',       'in ?the (flanks?|flaunche?s?)', 'mod', 'arrangement position',3   ),
    array ( 'inchief',       'in ?the chief' , 'mod', 'arrangement position',3   ),
    array ( 'inchiefthrough','in ?the chief throughout' , 'mod', 'arrangement position',3   ),
    array ( 'inbase',        'in ?the base' , 'mod', 'arrangement position',3  ),
    array ( 'indexside',     'in ?the dexter side' , 'mod', 'position', 1 ),
    array ( 'insinside',     'in ?the sinister side' , 'mod', 'position', 1  ),
    array ( 'indexchief',    'in ?the dexter chief' , 'mod', 'position', 1  ),
    array ( 'insinchief',    'in ?the sinister chief' , 'mod', 'position', 1  ),
    array ( 'inmidchief',    'in ?the middle chief' , 'mod', 'position', 1  ),
    array ( 'inhonpoint',    'in ?the honour point' , 'mod', 'position', 1  ),
    array ( 'infesspoint',   'in ?the fesse? point' , 'mod', 'position', 1  ),
    array ( 'indexbase',     'in ?the dexter base' , 'mod', 'position', 1  ),
    array ( 'insinbase',     'in ?the sinister base' , 'mod', 'position', 1  ),
    array ( 'inmidbase',     'in ?the middle base' , 'mod', 'position', 1  ),
    array ( 'innombril',     'in ?the nombril' , 'mod', 'position', 1  ),
    array ( 'innombril',     'in ?the navel point' , 'mod', 'position', 1  ),
    array ( 'quadrangle',    'in ?a quadrangle', 'mod', 'arrangement', 4 ),
  );

  $retval = null;
  $look_for_rows = false;

  $features = array();
  foreach ( $feature_sets as $feature_set ) {
    if (is_array($feature_set)) $features = array_merge($features, $feature_set);
    elseif (is_string($feature_set)) {
      switch ($feature_set) { // replace this with string -> varname conversion
        case 'position':
          $features = array_merge($features, $position_mods);
          break;
        case 'shape':
          $features = array_merge($features, $shape_mods);
          break;
        case 'linetype':
          $features = array_merge($features, $linetype_mods);
          break;
        case 'simple_charge':
          $features = array_merge($features, $simple_charge);
          break;
        case 'charge_prefix':
          $features = array_merge($features, $charge_prefix);
          break;
        case 'arr_pos':
          $features = array_merge($features, $arr_pos_mods);
          break;
        case 'rows':
          $look_for_rows = true;
          break;
        default:
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
    if ( $features and ($match = search_match($features)) != null) {
      $state = save();
      switch ( $match[2] ) {
        case 'shape':
          $shape_mod = make_mod($match[3], $match[0], tokens());
          get_features(array('linetype'), $shape_mod);
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
          foreach ( explode ( ' ', $match[3] ) as $match3 )
            $node->appendChild(make_mod ( $match3, $match[0], tokens() ));
          if ( isset ( $match[4] ) ) $retval = $match[4];
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
    } elseif (($tinc = tincture(false)) != null ) {
      $tinc->setAttribute('index',"$tinc_index" );
      $tinc_index++;
      $node->appendChild($tinc);
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
    andd();
  }
  return $retval; // usually ignored, but see arr_pos above
}


?>
