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


function makeVoid ( $shapeSpec, $lineType = 'none', $featureSize = 50, $offsetSize = 30 ) {

  $retval = '';
  // Create the outer edge as normal
  $retval .= makePath ( $shapeSpec, $lineType, $featureSize );
  $innerSpec = parallelSpec ( $shapeSpec, 'i', $offsetSize );
  $retval .= ' ' . makePath ( $innerSpec, 'none', 0 );
  return $retval;
}

function makeCotise ( $shapeSpec, $cotnum, $line_type, $cotiseSize = 40 ) {
  $retval = '';
  $outerSize = $cotiseSize*($cotnum*2);
  $innerSize = $cotiseSize*(($cotnum*2)-1);
  $outerSpec = parallelSpec ( $shapeSpec, 'o', $outerSize );
  $innerSpec = parallelSpec ( $shapeSpec, 'o', $innerSize );
  $innerSpec = reverseSpec ( $innerSpec );
  $retval .= makePath ( $outerSpec, $line_type, 18 );
  $retval .= ' ' . makePath ( $innerSpec, $line_type, 18 );

  return $retval;
}


function createVoid($spec, $pathLine, $feature_size) {
  $retval = '<path fill-rule="evenodd" d="' . makeVoid ( $spec, $pathLine, $feature_size ) . '" />';
  return $retval;
}

function createCotise($spec, $num, $line_type) {
  $retval = '<path fill-rule="evenodd" d="' . makeCotise ( choose_fit($spec), $num, $line_type ) . '" />';
  return $retval;
}

function makeOrdinary( $node ) {

  $prev_ord_map = '';
  $retval = '';

  // Some default values (may be overwritten by the ord_func data...)
  $feature_size = 50;    // Size of edge mod features
  $bb = '1000,1200';     // Default bounding box for scaling divisions & furs
  $shape_spec = null;    // If null, just use raw SVG
  $rev = false; $inv = false; $rot = 0;
  $fim_col = null;      // No fimbriation
  $voided = null;       // Not voided
  $void_col = null;     // If voided, show background
  $ord_body_col = null;
  $body2_col = '';        // Colour of extra bits (e.g. for compony)
  $on_ord = null;
  $ord_between = null;

  $cot_linetype = 'none'; // Set to the type of cotice (same as bars)
  $cot_col = '';      // Set to a colour if cotice present
  $cot_num = 0;       // Number of cottices
  $mods = array();

  // Get information about this ordinary
  $type = $node->get_attribute('type');
  $subtype = $node->get_attribute('subtype');
  $ord_linetype = $node->get_attribute('linetype');
  // Process sub-elements
  foreach ( $node->child_nodes() as $child ) {
    switch ( $child->node_name() ) {
      case 'modifier':
        $mods[] = $child->get_attribute('name');
        switch ( $child->get_attribute('name') ) {
          case 'sinister':
            $rev = !$rev;
            break;
          case 'inverted':
            $inv = !$inv;
            break;
          case 'voided':
            $voided = true;
            $void_col = $child->first_child(); // May be null
            break;
          case 'triple-cotised': $cot_num++;
          case 'double-cotised': $cot_num++;
          case 'cotised': $cot_num++;
            $cot_col = $child->first_child(); // May be null
            $cot_linetype = $child->get_attribute('param');
            if ( $cot_linetype == null ) $cot_linetype = 'none';
            break;
          case 'fimbriated':
            if ( $fim_col = $child->first_child() ) { ; // May be null
              $fim_col = $fim_col->first_child();
              if ( $fim_col->node_name() == 'colour' ) {
                $fim_col = $fim_col->get_attribute('name');
              } else {
                $fim_col = null;
              }
            }
            break;
           case 'on':
            $on_ord = $child;
            break; 
          case 'between':
            $ord_between = $child->first_child();
            break;
        }
        break;
      case 'tincture':
        if ( $ord_body_col == null ) {
          $ord_body_col = $child;
        } else {
          $body2_col = $child;
        }
        break;
    }
  }
  if ( $type == 'bend') $rot = 45;
  
  // Get the svg data of the shapes to be drawn
  $ord_func = 'makeOrd_' . $type;
  if ( ! function_exists($ord_func) ) {
    require_once ( 'svg/ordinaries/' . $type . '.inc' );
  }
  if ( ! function_exists($ord_func) ) {
    my_trigger_error("cannot draw ordinary $type", E_SVG);
    return '';
  }
  $ord_data = $ord_func($node);

  // Check out what we have found about drawing...
  if ( array_key_exists('shape_spec', $ord_data) ) $shape_spec = choose_fit($ord_data['shape_spec']);
  if ( array_key_exists('bounding_box', $ord_data)) $bb = $ord_data['bounding_box'];
  if ( array_key_exists('feature_size', $ord_data) ) $feature_size = $ord_data['feature_size'];

  $cotise = '';
  $body = '';
  // Create ordinary, if shape_spec provided
  if ( $shape_spec ) {
    if ( $voided ) {
      if ( $void_col ) $body .= apply_tincture ( $void_col, createBody($shape_spec, 'none', 0 ), $bb, $rot, $rev, $inv );
      $body .= createVoid($shape_spec, $ord_linetype, $feature_size);
    } else {
      $body .= createBody($shape_spec, $ord_linetype, $feature_size);
    }
    for ( $i = 1; $i <= $cot_num; $i++ ) $cotise .= createCotise( $shape_spec, $i, $cot_linetype );
  } else { // Create ordinary, if raw SVG given
    if ( $voided and array_key_exists('voided', $ord_data) ) {
      if ( $void_col ) $body .= apply_tincture ( $void_col, choose_fit($ord_data['body']), $bb, $rot, $rev, $inv );
      $body .= choose_fit($ord_data['voided']);
    } else {
      $body .= choose_fit($ord_data['body']);
    }
    if ( $cot_num >= 3 and array_key_exists('cotise3',$ord_data) ) $cotise .= choose_fit($ord_data['cotise3']);
    if ( $cot_num >= 2 and array_key_exists('cotise2',$ord_data) ) $cotise .= choose_fit($ord_data['cotise2']);
    if ( $cot_num >= 1 and array_key_exists('cotise1',$ord_data) ) $cotise .= choose_fit($ord_data['cotise1']);
  }
  // reverse or invert if required
  if ( count($mods) > 0 ) {
    $body = ImagePosition ( $body, 1200, 1000, $mods );
    $cotise = ImagePosition ( $cotise, 1200, 1000, $mods );
  } 
  
  // Create a mask, in case there is another ordinary "on" this one
  $prev_ord_map = $body . $cotise;
  
    // If we don't already have a counterchange, and only two colours create one
/*    if ( ! array_key_exists('shape', $counterchange) and $ord_body_col == $ord_cot_col ) {
      $shape = ImagePosition ( $body . $cotise, 1200, 1000, $pos_mod );
      $counterchange['background'] = $ord_body_col;
      $counterchange['shape'] = $shape;
    } */
  if ( $cot_col ) $cotise = apply_tincture ( $cot_col, $cotise, $bb, $rot, $rev, $inv );

  // Apply tinctures
  $body .= $cotise;
  $retval .= apply_tincture ( $ord_body_col, $body, $bb, $rot, $rev, $inv );
  if ( $fim_col != '' ) $retval = '<g stroke="' . rgb($fim_col) . '" stroke-width="15">' . "$retval</g>";
  if ( $body2_col != '' ) {
    $retval .= apply_tincture ( $body2_col, choose_fit($ord_data['body2']), $bb, $rot, $rev, $inv);
  }
  // Does this ordinary go "between" some charges?
  if ( $ord_between ) $retval .= makeCharge($ord_between);
  // If there is something "ON" this ordinary, go find it
  if ( $on_ord ) {
    $what_on = $on_ord->first_child();
    switch ( $what_on->node_name() ) {
      case 'ordinary':
        $new_ord = makeOrdinary($what_on);
        switch ( $subtype ) {
          // For canton and chief, the whole ordinary is scaled to fit within the canton or chief
          case 'canton':
            $clip = add_def('clipPath', '<path d="M0,0L300,0 300,300 0,300Z" />');
            $temp = '<g clip-path="url(#' . $clip . ')" ><g transform="scale(0.30,0.25)">' . $new_ord . "</g></g>";
            if ( $rev ) $temp = '<g transform="translate(300,0) scale(-1,1)">' . $temp . '</g>';
            break;
          case 'chief':
          case 'chief-couped':
          case 'chief-compony':
          case 'chief-counter-compony':
            $clip = add_def('clipPath', '<path d="M0,0L1000,0 1000,300 0,300Z" />');
            $temp = '<g clip-path="url(#' . $clip . ')" ><g transform="scale(1,0.25)">' . $new_ord . "</g></g>";
            break;
          // for all other ordinaries the ordinary is superimposed onto the existing one
          default:
            $fill = add_def( 'pattern patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" ' .
                                'y="0" width="1000" height="1200"', $new_ord );
            $temp = '<g fill="url(#' . $fill . ')">' . $prev_ord_map . '</g>';
            break;
        }
        $retval .= $temp . add_def();
        break;
      case 'charge':
        $retval .= makeCharge( $what_on );
        break;
    }
  } 

  return $retval;
}
?>
