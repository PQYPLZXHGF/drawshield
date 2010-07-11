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


function treatment() {
  global $dom;

  $treatments = array(
    // Field treatments
    // 'plumetty', how to draw this one?
    // array ( 'lozengy',      'lozengy',  ), made this back into a division
    array ( 'checky',       '(checky|chequy)' ),
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
    array ( 'vairy',        'vair(e|y)',     ),
  );

  $node = null;
  if ( ($match = search_match($treatments)) != null ) {
    $node = $dom->create_element('treatment');
    $node->set_attribute('name', $match[0]);
  }
  return $node;
}

function object_treatment( $base = null) {
  global $dom;

  $objects = array (
    array ( 'annuletty',    'annuletty',    'geometric/annulet', ),
    array ( 'billetty',     'billetty',     'geometric/billet', ),
    array ( 'estoilly',     'estoilly',     'mullet/mullet', 'points/6' ),
    array ( 'fleury',       'fleury|floretty/sem(e|y) de l(i|y)s', 'symbol/fleurdelys' ),
    array ( 'goutty',       'go?utty',      'geometric/goutte', ),
    array ( 'bezanty',      'bezant(y|e)',  'geometric/bezant' ),
    array ( 'platy',        'platy',  'geometric/plate' ),
    array ( 'hurty',        'hurty',        'geometric/roundel' ),
    array ( 'mullety',      'mullett?y',    'mullet/mullet', 'points/5' ),
  );

  $node = null;
  if ( ($match = search_match($objects)) != null ) {
    $node = $dom->create_element('semyde');
    $node->set_attribute('name', $match[0]);
    if ( $base == null ) {
      $base = tincture(false);
    } else {
      $newNode = $dom->create_element('tincture');
      $newNode->append_child($base);
      $base = $newNode;
    }
    $node->append_child($base);
    $charge = $dom->create_element('charge');
    $types = explode('/',$match[2]);
    $charge->set_attribute('type',$types[0]);
    $charge->set_attribute('subtype',$types[1]);
    if ( $match[0] == 'bezanty' or $match[0] == 'platy' ) {
      $tinc = $dom->create_element('tincture');
      $tinc->append_child($dom->create_element('implied'));
      $charge->append_child($tinc);
    } else {
      $charge->append_child(tincture(false));
    }
    if ( isset($match[3]) ) {
      $mods = explode('/', $match[3]);
      $mod = make_mod($mods[0], $mods[1]);
      $charge->append_child($mod);
    }
    $mod = make_mod('hflex','1');
    $charge->append_child($mod);
    $mod = make_mod('wflex','1');
    $charge->append_child($mod);
    $node->append_child($charge);
  }
  return $node;
}
?>
