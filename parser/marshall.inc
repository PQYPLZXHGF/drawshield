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

function plain() {
  global $dom, $p_globals;

  $node = $dom->create_element('plain');

  if ( ($field = tincture() ) != null ) {
    comma();
    $p_globals['offield'] = deep_copy($field->first_child());
    $node->append_child($field);
    // Check for a second division
    if ( ($div2 = division(2)) != null ) {
      $tinc2 = $dom->create_element('tincture');
      $tinc2->append_child($div2);
      $node->append_child($tinc2);
    }
    if ( ($ord_chgs = ord_chgs()) != null ) {
      $node->append_child($ord_chgs);
    }
  } else {
    $node->append_child($dom->create_element('missing'));
    raise_error('Expected another shield description');
  }
  return $node;
}

function overall() {
  global $dom;

  $overall = array (
    array ( true, 'overall' ),
    array ( true, 'over all' ),
    array ( true, 'all with(in)?' ),
  );

  $node = null;

  if ( search_match($overall) != null ) {
    $node = $dom->create_element('overall');
    $node->append_child(ord_chgs());
  }
  return $node;
}

function quartered() {
  global $dom;

  $quartered = array (
    array ( 'ed', 'quartered' ), // Always a marshalling
    array ( 'ly', 'quarterly' ), // Could be a marshalling or a division
  );

  $quarters = array (
    array ( 1, 'first|1st|i' ),
    array ( 2, 'second|2nd|ii' ),
    array ( 3, 'third|3rd|iii' ),
    array ( 4, 'fourth|4th|iv|iiii' ),
  );
  $subshields = array(0,null,null,null,null);

  $state = save();
  $node = null;

  if ( ($marshall = search_match($quartered))  != null ) {
    $node = $dom->create_element('quartered');
    $foundQuarter = false;
    do { // Look for quarters
      $found = false;
      $indices = array();
      while ( ($match = search_match($quarters)) != null ) {
        $indices[] = $match[0]; // make a list of quarter numbers
        comma();
        andd();
        $found = $foundQuarter = true;
      }
      if ( $found ) {
        $temp = shield(); // Look for the description of this quarter
        if ( count($indices) > 1 ) $temp->set_attribute('ID',($ID=unique('shield')));
        $subshields[$indices[0]] = $temp; // Set the first quarter to this description
        for ( $i = 1; $i < count($indices); $i++ ) {
          $temp = $dom->create_element('shield');
          $temp->set_attribute('IDREF',$ID); // Set other quarters to point to this one
          $subshields[$indices[$i]] = $temp;
        }
      } // Keep going as long as we find quarters
    } while ( $found );
    if ( $marshall[0] == 'ly' and !$foundQuarter ) {
      restore($state); // backtrack, assume this is quarterly division
      return null; 
    }
    for ( $i = 1; $i <= 4; $i++ ) {
      if ( $subshields[$i] == null ) {
        $subshields[$i] = $dom->create_element('missing');
        raise_error('Missing quarter (' . $i . ')');
      }
      $node->append_child($subshields[$i]);
    }
  }

  return $node;
}

function halved() {
  global $dom;

  $splits = array ( 
    array ( 'impaled', 'impaled ?with' ),
    array ( 'dimidiated', 'dimidiated ?with' ),
  );

  $node = null;
  if ( ($match = search_match($splits)) != null ) {
    $node = $dom->create_element($match[0]);
  }
  return $node;
}

function shield() {
  global $dom;
  
  $quartered = false;

  $node = $dom->create_element('shield');

  if ( ( $child = quartered() ) == null ) {
    $child = plain();
    if ( ($split = halved()) != null ) {
      $node2 = $dom->create_element('shield');
      $node2->append_child($child);
      $split->append_child($node2);
      $node2 = $dom->create_element('shield');
      $node2->append_child(plain());
      $split->append_child($node2);
      $child = $split;
    }
  } else { // Shield was quartered
    $quartered = true;
  }
  $node->append_child($child);
  if ( ($quartered or !semicolon()) and ($overall = overall() ) != null ) {
    $node->append_child($overall);
  }
  return $node;
}
?>
