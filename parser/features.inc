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

    static $position_mods = array (
    array ( null, 'sinister', 'mod', 'sinister' ),
    array ( null, 'dexter', 'mod', 'dexter', ),
    array ( null, 'inverted', 'mod', 'inverted', ),
    array ( null, 'enhanced', 'mod', 'enhanced', ),
    array ( null, '(abased|abaisse)', 'mod', 'abased', ),
  );

  static $shape_mods = array (
    array ( null, 'voided', 'shape', 'voided' ),
    array ( null, '(fimbriated|edged)', 'shape', 'fimbriated',  ),
    array ( null, '(cotised|cotticed|endorsed)', 'shape', 'cotised',  ),
    array ( null, 'between # cott?ices', 'shape', 'cotised',  ),
    array ( null, 'double (cotised|cotticed)', 'shape', 'double-cotised',  ),
    array ( null, '(triple|treble) (cotised|cotticed)', 'shape', 'triple_cotised',  ),
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

  $features = array();
  foreach ( $feature_sets as $feature_set ) {
    if (is_array($feature_set)) $features = array_merge($features, $feature_set);
    elseif (is_string($feature_set)) {
      switch ($feature_set) {
        case 'position':
          $features = array_merge($features, $position_mods);
          break;
        case 'shape':
          $features = array_merge($features, $shape_mods);
          break;
        case 'linetype':
          $features = array_merge($features, $linetype_mods);
          break;
        default:
          raise_error("Unknown feature group - $feature_set");
          break;
      }
    }
  }

  // Get any additional features
  while ( $features ) {
    if ( ($match = search_match($features)) == null ) break;
    switch ( $match[2] ) {
      case 'shape':
        $shape_mod = make_mod($match[3], $match[0]);
        get_features(array('linetype'), $shape_mod);
        if ( ($tinc = tincture()) != null ) $shape_mod->appendChild($tinc);
        $node->appencChild($shape_mod);
        break;
      case 'feature':
        $feature = $dom->createElement('feature');
        $feature->setAttribute( 'name', $match[0]);
        $feature->setAttribute('tokens',tokens());
        $feature->appendChild(tincture(true));
        $node->appendChild($feature);
        break;
      case 'mod':
        $node->appendChild(make_mod ( $match[3], $match[0] ));
        break;
      case 'ignore':
        break;
    }
    comma();
    andd();
  }
}


?>
