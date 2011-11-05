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
	 

function createBody($spec, $lineType, $feature_size) {
  return '<path fill-rule="evenodd" d="' . makePath ( $spec, $lineType, $feature_size ) . '" />';
} 

function makeVoid ( $shapeSpec, $lineType = 'none', $featureSize = 50, $offsetSize = 30 ) {

  $retval = '';
  // Create the outer edge as normal
  $retval .= makePath ( $shapeSpec, $lineType, $featureSize );
  $innerSpec = parallelSpec ( $shapeSpec, 'i', $offsetSize );
  $retval .= ' ' . makePath ( $innerSpec, 'none', 0 );
  return $retval;
}

function makeCotise ( $shapeSpec, $cotnum, $lineType, $cotiseSize = 40 ) {
  $retval = '';
  $outerSize = $cotiseSize*($cotnum*2);
  $innerSize = $cotiseSize*(($cotnum*2)-1);
  $outerSpec = parallelSpec ( $shapeSpec, 'o', $outerSize );
  $innerSpec = parallelSpec ( $shapeSpec, 'o', $innerSize );
  $innerSpec = reverseSpec ( $innerSpec );
  $retval .= makePath ( $outerSpec, $lineType, 18 );
  $retval .= ' ' . makePath ( $innerSpec, $lineType, 18 );

  return $retval;
}


function createVoid($spec, $lineType, $feature_size) {
  $retval = '<path fill-rule="evenodd" d="' . makeVoid ( $spec, $lineType, $feature_size ) . '" />';
  return $retval;
}

function createCotise($spec, $num, $lineType) {
  $retval = '<path fill-rule="evenodd" d="' . makeCotise ( choose_fit($spec), $num, $lineType ) . '" />';
  return $retval;
}

function division_to_modifier(&$node, $type) {
	// check for tincture being a quarterly division, if so handle separately & rewrite modifiers
	$item = null;
	// See if there is a division of the required type
	foreach ( $node->childNodes as $child ) {
		if ( $child->nodeName == 'tincture' and $child->firstChild->nodeName == 'division' and $child->firstChild->getAttribute('type') == $type ) {
		  $item = $child;
			break;
		}
	}
	if ( $item == null ) return false; // not found
	
	// We cannot just iterate through childNodes as we want to make changes, so put in an array
	foreach ( $item->firstChild->childNodes as $child ) {
	  $children[] = $child;
	}
	// We can now remove the original tincture
	$node->removeChild($item);
	// Create a new modifier node
	$mod = make_mod('div2ord',$type);
	// Now copy any tinctures back into the original node, and save any other modifiers
	for ( $i = 0; $i < count($children); $i++ )
	  if ( $children[$i]->nodeName == 'tincture' ) {
			// We swap the colours over, as body2 draws the first one (other way round for normal divisions)
			if ( $children[$i]->getAttribute('index') == '1')			
			  $children[$i]->setAttribute('index','2');
			else
			  $children[$i]->setAttribute('index','1');
		  $node->appendChild($children[$i]);
		}
		else
		  $mod->appendChild($children[$i]);
	// Create a modifier to show which division we replaced
	$node->appendChild($mod);

  return true;
}

function includeOrdinary( &$node ) {
  $ordinary = array ();
  include ( 'ordinaries/' . $node->getAttribute('type') . '/' . $node->getAttribute('subtype') . '.inc' );
  return $ordinary;
}

function makeOrdinary( &$node ) {

	// Get information about the shapes to be drawn
	// We do this first in case the ordinary code changes any of the modifiers, e.g. a bend quarterly
  $ord_data = includeOrdinary( $node );
	
	// Some defaults (either from the ordinary data or from modifiers)
  if ( array_key_exists('feature_size', $ord_data) ) 
	  $feature_size = $ord_data['feature_size'];
	else
	  $feature_size = 50;
	$voided = get_mod_node($node, 'voided');
	$tinc1 = get_tincture($node,'1');
	$cotise = '';
	
	// Create the basic shape
	$body = '';
	if ( array_key_exists('shape_spec', $ord_data) ) { //  we are given a path specification to convert to SVG
	  $shape_spec = choose_fit($ord_data['shape_spec']);
    if ( $voided != null ) {
      if ( ($void_col = $voided->firstChild ) != null ) 
			  $body .= apply_tincture ( $void_col, createBody($shape_spec, 'none', 0 ) );
      $body .= createVoid($shape_spec, get_mod($node,'linetype'), $feature_size);
    } else {
      $body .= createBody($shape_spec, get_mod($node,'linetype'), $feature_size);
    }
		// Now do the cotises
		if ( ($cot_node = get_mod_node($node,'cotised')) != null ) {
			$cot_linetype= get_mod($cot_node,'linetype');
			$cot_tinc = get_tincture($cot_node);
			if ( !$cot_tinc )
			  $cot_tinc = $tinc1;
      for ( $i = 1; $i <= $cot_node->getAttribute('param'); $i++ ) 
			  $cotise .= createCotise( $shape_spec, $i, $cot_linetype );
		  $cotise = apply_tincture ( $cot_tinc, $cotise );
		}
  } else { // we are given direct SVG data
    if ( $voided != null ) {
		  if ( !array_key_exists('voided', $ord_data) ) {
		    draw_message('warning','cannot draw ' . $node->getAttribute('subtype') . 'as voided');
        $body .= choose_fit($ord_data['body']);
		  } else {
        if ( ($void_col = $voided->firstChild ) != null ) 
			    $body .= apply_tincture ( $void_col, choose_fit($ord_data['body']) );
			  $body .= choose_fit($ord_data['voided']);
			}
    } else {
      $body .= choose_fit($ord_data['body']);
    }
	} // We now have $body and $cotise set.
	
	// Find out how we are arranged
  if ( array_key_exists('rotate_pattern', $ord_data) )
	  $rot = $ord_data['rotate_pattern'];
	else 
	  $rot = 0;
	$mirrored = get_mod($node, 'sinister');
	$inverted = get_mod($node, 'inverted');

	// Start to build return string
  $retval = apply_tincture ( $tinc1, $body, '', $rot, $mirrored, $inverted );

	// Do we need to add a second tincture as an overlay
  if ( ($body2_col = get_tincture($node,'2')) != null ) {
		if ( !array_key_exists('body2', $ord_data) )
		  draw_message('warning','Unable to tincture ordinary as requested');
		else {
		  $body2_spec = choose_fit($ord_data['body2']);
		  if ( $body2_spec{0} != '<' ) {
			  // Is there a linetype here also
				if ( ($div2ord = get_mod_node($node,'div2ord')) != null )
				  $linetype = get_mod($div2ord,'linetype');
			  $body2_spec = '<path d="' . makePath($body2_spec, $linetype, 30) . '" />';
			}
	    $body2 = apply_tincture ( $body2_col, $body2_spec, '', $rot, $mirrored, $inverted );
      $body2_fill = add_def( 'pattern patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" ' .
                             'y="0" width="1000" height="1200"', $body2 );
      $retval .= add_def() . '<g fill="url(#' . $body2_fill . ')">' . $body . '</g>';					
		}
	}
	
	// Fimbriation goes on top of everything else
	if ( ($fimbriated = get_mod_node($node,'fimbriated')) != null ) {
		$fim_rgb = get_rgb( get_tincture($fimbriated) );
	  $retval .= '<g stroke="' . $fim_rgb . '" stroke-width="15" fill="none">' . "$body</g>";
	}
  if ( get_mod($node,'depressed') ) 
	  $retval .= '<g stroke="#000000" stroke-width="7">' . "$body</g>";
		

  // Now add anything that is "on" the ordinary
	$on_object = '';
  if ( ($on_ord = get_mod_node($node,'on')) != null ) {
    $what_on = $on_ord->firstChild;
    switch ( $what_on->nodeName ) {
      case 'ordinary':
			  // If the underlying ordinary is mirrored, we need to mirror the "on" item so it ends up back the right way
				if ( $mirrored ) {
  				if ( ($sin = get_mod_node($what_on,'sinister')) != null )
					  $what_on->removeChild($sin);
					else
					  $what_on->appendChild(make_mod('sinister'));
				}
			  // Make a normal ordinary, ignore any chief present
        chief('push','NC');
        $new_ord = makeOrdinary($what_on);
        chief('pop');
				// Does the main ordinary want this handled specially (scaling and clipping to fit entirely)?
			if ( array_key_exists('if_ord_on',$ord_data) and $ord_data['if_ord_on'] == 'scale' ) {
        $type = $what_on->getAttribute('subtype'); // TODO can we find this out from a flag?
			  $height = ($type == 'per-bend' || $type == 'per-bend-sinister' || $type == 'quarterly') ? 1000 : 1200;
			  $patt_id = add_def ( 'pattern width="100%" height="100%" patternUnits="objectBoundingBox" preserveAspectRatio="none" viewBox="0 0 1000 ' .   $height . '"',
              $title . "<desc>Ordinary on ordinary</desc>" .
               $new_ord ); 
          $on_object = '<g fill="url(#' . $patt_id . ')"  >' . $body . '</g>';
			  } else {
          $fill = add_def( 'pattern patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" ' .
                             'y="0" width="1000" height="1200"', $new_ord );
					// TODO should this be a mask? Or a clip path?
          $on_object = '<g fill="url(#' . $fill . ')">' . $body . '</g>';					
			  } 
        break;
      case 'charge':
 			  // If the underlying ordinary is mirrored, we need to mirror the "on" item so it ends up back the right way
				if ( $mirrored ) {
  				if ( ($sin = get_mod_node($what_on,'reversed')) != null )
					  $what_on->removeChild($sin);
					else
					  $what_on->appendChild(make_mod('reversed'));
				}
        $on_object = makeCharge( $what_on );
        break;
    }
  }
  
  // Is this ordinary "between" anything?
  $between_object = '';
  if ( ($btwn_ord = get_mod_node($node,'between')) != null ) {
    $btwn_ord = $btwn_ord->firstChild;
 		// If the underlying ordinary is mirrored, we need to mirror the "on" item so it ends up back the right way
    if ( $mirrored ) {
      if ( ($sin = get_mod_node($btwn_ord,'reversed')) != null )
        $btwn_ord->removeChild($sin);
      else
        $btwn_ord->appendChild(make_mod('reversed'));
    }
    $between_object = makeCharge ( $btwn_ord );
  }
  	
	// Gather all the parts together
  $retval = add_def() . $retval . $cotise . $on_object . $between_object;
	
	// Are there any modifiers that affect over all position?
	$transform = '';
  if ( $mirrored ) {
    $transform .= 'translate(1000,0) scale(-1,1) ';
  }
  if ( $inverted ) {
    $transform .= 'translate(0,1200) scale(1,-1) ';
  }
  if ( get_mod($node,'enhanced') ) {
    $yshift = -200; // Adjust to change movement for enhanced (match in layout.inc)
    $transform .= 'translate(0,' . $yshift . ') ';
  }
  if ( get_mod($node,'abased' )) {
    $yshift = 200; // As above
    $transform .= 'translate(0, ' . $yshift . ') ';
  }
  if ( $transform != '' )
    $retval = '<g transform="' . $transform . '">' . $retval . "</g>\n";
	
	// And finally...
  $retval = '<g><title>' . $node->getAttribute('subtype') . '</title>' . $retval . '</g>';
	
	return $retval;
}

?>