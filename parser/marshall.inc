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

  $node = $dom->createElement('plain');

  if ( ($field = tincture() ) != null ) {
    comma();
    $p_globals['offield'] = deep_copy($field->firstChild);
    $node->appendChild ( $field );
    // Check for a second division
    if ( ($div2 = division(2)) != null ) {
      $tinc2 = $dom->createElement('tincture');
      $tinc2->appendChild($div2);
      $node->appendChild($tinc2);
    }
    if ( ($ord_chgs = ord_chgs()) != null ) {
      $node->appendChild($ord_chgs);
    }
  } else {
    $node->appendChild($dom->createElement('missing'));
    parser_message('blazon', 'Expected another shield description');
  }
  return $node;
}

function overall() {
  global $dom;

  $overall = array (
    array ( true, 'overall' ),
    array ( true, 'over all' ),
    array ( true, 'over ?all ?the (four|4) quarterings' ),
    array ( true, 'over ?all ?the (two|2) (halves|parts|sections)' ),
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
  );
  $subshields = array(0,null,null,null,null);

  $state = save();
  $node = null;

  if ( ($marshall = search_match($quartered))  != null ) {
    $node = $dom->createElement('quartered');
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
        $temp = shield(false); // Look for the description of this quarter
        if ( count($indices) > 1 ) $temp->setAttribute( 'ID',($ID=unique('shield')));
        if ( $subshields[$indices[0]] != null )
          parser_message('error','Duplicate quarter' );
        else
          $subshields[$indices[0]] = $temp; // Set the first quarter to this description
        for ( $i = 1; $i < count($indices); $i++ ) {
          $temp = $dom->createElement('shield');
          $temp->setAttribute('IDREF',$ID); // Set other quarters to point to this one
          if ( $subshields[$indices[$i]] != null )
            parser_message('error','Duplicate quarter' );
          else
            $subshields[$indices[$i]] = $temp;
        }
      } // Keep going as long as we find quarters
    } while ( $found and ! semicolon() );
    if ( $marshall[0] == 'ly' and !$foundQuarter ) {
      restore($state); // backtrack, assume this is quarterly division
      return null;
    }
    for ( $i = 1; $i <= 4; $i++ ) {
      if ( $subshields[$i] == null ) {
        $subshields[$i] = $dom->createElement('missing');
        parser_message('blazon','Missing quarter (' . $i . ')');
      }
      $subshields[$i]->setAttribute('index',"$i");
      $node->appendChild($subshields[$i]);
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
    $node = $dom->createElement($match[0]);
  }
  return $node;
}

function parse() {
  global $dom;
  global $pending_items;
  $impaled = array (
    array ( 'impaled', 'impaled ?with' ),
    );

  $node = $dom->createElement('shield');
  $node->setAttribute('index','0');
  
  $child = shield();
  
  if ( search_match($impaled) != null ) {
    $child->setAttribute('index','1');
    $child2 = shield();
    $child2->setAttribute('index','2');
    $imp = $dom->createElement('impaled');
    $imp->appendChild($child);
    $imp->appendChild($child2);
    $node->appendChild($imp);
  } else {
    $node->appendChild($child);
  } 
  
  if ( ($over = overall()) != null )
    $node->appendChild($over);
  
  foreach ( $pending_items as $item ) {
    $item->setAttribute('origin','missing');
    parser_message('blazon', 'Tincture missing');
  }
  
  return $node;
}

function shield($ignore_semi = true) { // look for overall, even if a ";" is present
  global $dom;

  $overall = null;

  if ( ( $child = quartered() ) == null ) {
    $child = plain();
    $overall = overall();
    if ( !(!$ignore_semi and semicolon()) and ($split = halved()) != null ) {
      $node2 = $dom->createElement('shield');
      $node2->setAttribute('index','1');
      $node2->appendChild($child);
      if ( $overall ) $node2->appendChild($overall);
      $split->appendChild($node2);
      $node3 = $dom->createElement('shield');
      if ( ($subshield = quartered() ) == null ) /* these 3 lines added to allow halved then quartered */
        $subshield = plain();
      $node3->setAttribute('index','2');
      $node3->appendChild($subshield);
      // $node3->appendChild(plain());
      $overall = semicolon() ? null : overall();
      if ( $overall ) $node3->appendChild($overall);
      $split->appendChild($node3);
      $child = $split;
      $overall = null;
    }
  }
 // $node->appendChild($child);
/*  if ( $ignore_semi and ($overall ==null) ) {
    semicolon();
    $overall = overall();
  }
  if ($overall)
    $node->appendChild($overall); */

  return $child;
}
?>
