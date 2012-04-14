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

  search_match( array ( array( null, 'on a field ?of' )) );
  
  $node = null;
  
  if ( ($field = tincture() ) != null ) {
    $plain = $dom->createElement('plain');
    comma();
    $p_globals['offield'] = deep_copy($field->firstChild);
    $plain->appendChild ( $field );
    // Check for a second division
    if ( ($div2 = division(2)) != null ) {
      $tinc2 = $dom->createElement('tincture');
      $tinc2->appendChild($div2);
      $plain->appendChild($tinc2);
    }
    if ( ($ord_chgs = ord_chgs()) != null ) {
      $plain->appendChild($ord_chgs);
    }
    $node = $dom->createElement('shield');
    $node->setAttribute('index','0');
    $node->appendChild($plain);
/*    if ( !semicolon() and ($overall = overall()) != null )
      $node->appendChild($overall); */
  }
  return $node;
}

function overall() {
  global $dom;

  $overall = array (
    array ( true, 'overall' ),
    array ( true, 'over all' ),
    array ( true, 'over ?all ?the ?# (quarters|quarterings|halves|parts|sections)' ),
    array ( true, 'all with(in)?' ),
  );

  $node = null;

  if ( search_match($overall) != null ) {
    $node = $dom->createElement('overall');
		if ( ($over = ord_chgs()) == null ) {
			parser_message('blazon','Nothing to go "overall"');
			return null;
		}
    $node->appendChild($over);
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
    array ( 1, '(first|1st|i|1|one)' ),
    array ( 2, '(second|2nd|ii|2|two)' ),
    array ( 3, '(third|3rd|iii|3|three)' ),
    array ( 4, '(fourth|4th|iv|iiii|4|four)' ),
    array ( 5, '(fifth|5th|v|5|five)' ),
    array ( 6, '(sixth|6th|vi|6|six)' ),
    array ( 7, '(seventh|7th|vii|7|seven)' ),
    array ( 8, '(eigth|8th|viii|8|eight)' ),
  );
  $subshields = array(0,null,null,null,null,null,null,null,null);

  $state = save();
  $node = null;

  if ( ($marshall = search_match($quartered))  != null ) {
    $quartered = $dom->createElement('quartered');
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
        $quarter = shield(); // Look for the description of this quarter
        if ( $quarter != null and count($indices) > 1 ) { 
          $quarter->setAttribute( 'ID',($ID=unique('shield')));
          $quarter->setIdAttribute('ID',true);
        }
        if ( $subshields[$indices[0]] != null )
          parser_message('error','Duplicate quarter' );
        else
          $subshields[$indices[0]] = $quarter; // Set the first quarter to this description
        for ( $i = 1; $i < count($indices); $i++ ) {
          $reference = $dom->createElement('shield');
          $reference->setAttribute('IDREF',$ID); // Set other quarters to point to this one
          if ( $subshields[$indices[$i]] != null )
            parser_message('error','Duplicate quarter' );
          else
            $subshields[$indices[$i]] = $reference;
        }
      } // Keep going as long as we find quarters
    } while ( $found );
    if ( $marshall[0] == 'ly' and !$foundQuarter ) {
      restore($state); // backtrack, assume this is quarterly division
      return null;
    }
    $highest = false;
    for ( $i = 8; $i > 0; $i-- ) {
      if ( $subshields[$i] == null ) {
        if ( !$highest )
          continue;
        else { // highest already been found
          $subshields[$i] = $dom->createElement('missing');
          parser_message('blazon','Missing quarter (' . $i . ')');
        }
      } else { // NOT null
        if ( !$highest )
          $highest = $i;
        $subshields[$i]->setAttribute('index',"$i");
      }
    }
    $quartered->setAttribute('order',$highest);
    for ( $i = 1; $i <= $highest; $i++ )
      $quartered->appendChild($subshields[$i]);
    $node = $dom->createElement('shield');
    $node->setAttribute('index','0');
    $node->appendChild($quartered);
  }

  return $node;
}

function halved() {
  global $dom;

  $splits = array (
    array ( 'impaled', 'impaled !with' ),
    array ( 'dimidiated', 'dimidiated !with' ),
  );
  
  $with = array (
    array ( true, '(with|upon)' ),
  );

  $node = null;
  if ( ($match = search_match($splits)) != null ) {
    $half = $dom->createElement($match[0]);
    if ( ($shield1 = shield()) == null ) {
      parser_error('warning', 'Expected 1st shield description');
      $shield1 = $dom->createElement('missing');
    }
    $shield1->setAttribute('index','1');
    if ( ! search_match($with) ) {
      // uncomment to require "impaled A with B"
      //      parser_error('warning','expected "with"');
      //      return $shield1;
    }
    if ( ($shield2 = shield()) == null ) {
      parser_error('warning', 'Expected 2nd shield description');
      $shield2 = $dom->createElement('missing');
    }
    $shield2->setAttribute('index','2');
    $half = $dom->createElement($match[0]);
    $half->appendChild($shield1);
    $half->appendChild($shield2);
    $node = $dom->createElement('shield');
    $node->setAttribute('index','0');
    $node->appendChild($half);
  }
  return $node;
}

function parse() {
  global $pending_items;

  $node = shield();
  semicolon();
  if ( ($overall = overall()) != null )
    $node->appendChild($overall);
  
  foreach ( $pending_items as $item ) {
    $item->setAttribute('origin','missing');
    parser_message('blazon', 'Tincture missing');
  }
  
  return $node;
}

function builtin() {
  global $cur_word;
  $theshieldof = array (
    array ( true, '?the (shield|arms) of' ),
  );
  
  $state = save();
  $retval = null;
  
  search_match($theshieldof);
  
  if ( ($named_blazon = checkDB()) != null ) {
    context('push');
    fill_words($named_blazon);
    $retval = shield();
    context('pop');
    $cur_word += 1;
  } else
    restore($state);
    
  return $retval;
}

function shield() {
  global $dom;

  $splits = array (
    array ( 'impaled', 'impaled with' ),
    array ( 'dimidiated', 'dimidiated with' ),
  );
  
  $node1 = builtin();
  if ( $node1 == null ) $node1 = quartered();
  if ( $node1 == null ) $node1 = halved();
  if ( $node1 == null ) $node1 = plain();
  if ( $node1 == null ) {
    $node1 = $dom->createElement('shield');
    $node1->appendChild($dom->createElement('missing'));
    parser_message('blazon', 'Expected a shield description');
  }
  if ( !semicolon() and ($overall = overall()) != null )
    $node1->appendChild($overall);
  $retval = $node1;
  
  // Now do it all again, in case of "A impaled with B"
  if ( ($match = search_match($splits)) != null ) {
    $node2 = builtin();
    if ( $node2 == null ) $node2 = quartered();
    if ( $node2 == null ) $node2 = halved();
    if ( $node2 == null ) $node2 = plain();
    if ( $node2 == null ) {
      $node2 = $dom->createElement('shield');
      $node2->appendChild($dom->createElement('missing'));
      parser_message('blazon', 'Expected a shield description');
    }
    if ( !semicolon() and ($overall = overall()) != null )
      $node2->appendChild($overall);
    // Got two nodes, now create a mother node
    $motherNode = $dom->createElement('shield');
    $motherNode->setAttribute('index','0');
    $daughterNode = $dom->createElement($match[0]);
    $node1->setAttribute('index','1');
    $node2->setAttribute('index','2');
    $daughterNode->appendChild($node1);
    $daughterNode->appendChild($node2);
    $motherNode->appendChild($daughterNode);
    $retval = $motherNode;
  } 

  return $retval;
}

?>
