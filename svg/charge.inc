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


function makeCharge($charge, $mods = array() ) {
  $placements = array(0 => 'x/x/x/x/x/x');
  $locations = array(0 => 'default');
  $counts = array(0 => $charge->get_attribute('number'));
  $pcount = $lcount = $ccount = 0;
  $retval = '';
  foreach ( $charge->child_nodes() as $child ){
    if ( $child->node_name() == 'modifier' ) {
      switch ( $child->get_attribute('name')) { 
        case 'location':
          $locations[$lcount++] = $child->get_attribute('param');
          break;
        case 'placement':
          $placements[$pcount++] = $child->get_attribute('param');
          break;
        case 'count':
          $counts[$ccount++] = $child->get_attribute('param');
          break;
      }
    }
  }
  for ( $i = 0; $i < count($placements); $i++ ) {
    // If more than one location, use location counts, otherwise use given number
    if ( $lcount > 1 ) $charge->set_attribute('number', $counts[$i]);
    $retval .= place_charges ( $charge, $placements[$i], $mods );
    if ( $locations[$i] != 'default' ) {
      $in_data = explode(',',$locations[$i]);
      $transform = 'transform="' . sprintf("translate(%.2f,%.2f) scale(%.2f,%.2f)", $in_data[0], $in_data[1], $in_data[2]/1000, $in_data[3]/1000) . '" ';
      $retval = "<g $transform >\n$retval\n</g>";
    }
  }
  return $retval;
}

function includeCharge( &$node ) {
  $charge = array ();
  include ( 'charges/' . $node->get_attribute('type') . '/' . $node->get_attribute('subtype') );
  return $charge;
}

function getCharge( $node ) {

  $chg_data = null;
  if ( $node->node_name() == 'missing' ) {
    $subtype = 'missing';
    $chg_data = array ( 'width' => 100, 'height' => 100,
        'body' => '<path fill-rule="evenodd" d="M0,0h100v100h-100zM15,15h70v70h-70z" />
              <text x="50" y="65" font-size="30" text-anchor="middle">Msng</text>', 'wflex' => 2, 'hflex' => 2 );
  } else {
    $subtype = $node->get_attribute('subtype');
    $charge = includeCharge( $node );
    if ( count($charge) < 1 ) {
      my_trigger_error("Cannot draw $sub_type", E_SVG, __FILE__, __LINE__);
    } else {
      $chg_data = $charge;
    }
  }
  if ( $chg_data == null ) {
    $subtype = 'missing';
    $chg_data = array ( 'width' => 100, 'height' => 100,
        'body' => '<path fill-rule="evenodd" d="M0,0h100v100h-100zM15,15h70v70h-70z" />
              <text x="50" y="65" font-size="30" text-anchor="middle">Sorry</text>', 'wflex' => 2, 'hflex' => 2 );
  }
  $features = (array_key_exists('features', $chg_data)) ? $chg_data['features'] : null;
  if ( !array_key_exists('title', $chg_data)) $chg_data['title'] = 'Charge';
  if ( !array_key_exists('desc', $chg_data)) $chg_data['desc'] = $subtype;
  $body = $chg_data['body'];

  // Process charge features and modifiers
  $charges_on = null;
  $feat_cols = array();
  $charge_col = null;
  $demi = null;
  $charge_is_proper = false;
  foreach ( $node->child_nodes() as $child ) {
    switch ( $child->node_name() ) {
      case 'feature':
        $feat_cols[$child->get_attribute('name')] = $child->first_child();
        break;
      case 'tincture': 
        $charge_col = $child;
        break;
      case 'modifier':
        switch ($child->get_attribute('name')) {
          case 'demi':
            $demi = true;
            break;
          case 'on':
            $charges_on = $child->first_child();
            break;
        }
        break;
    }
  }
  $col_type = $charge_col->first_child();
  if ( $col_type->node_name() == 'default' and array_key_exists('default', $chg_data) ) {
    $col_type->set_attribute('spec', $chg_data['default']);
  }
  // Apply proper colour (if there is one)
  if ( $col_type->node_name() == 'proper' and array_key_exists('proper', $chg_data) ) 
  {
    $col_type->set_attribute('spec', $chg_data['proper']);
    $charge_is_proper = true;
  }

  // Apply colours to features and append to the body
  if ( $features ) {
    foreach ( $features as $key => $data ) {
      // Find if there is a proper colour
      if ( array_key_exists('proper', $data) ) 
        $proper_spec = $data['proper'];
      elseif ( array_key_exists('proper', $chg_data) )
        $proper_spec = $chg_data['proper'];
      // if ( ! array_key_exists('body', $data) ) continue; // No body, so no colour to apply
      if ( array_key_exists($key, $feat_cols) and ($feat_col = $feat_cols[$key]) != null ) { // we have an explicitly coloured feature
        $col_type = $feat_col->first_child();
        if ( $col_type->node_name() == 'proper' ) $col_type->set_attribute('spec', $proper_spec);
        $body .= apply_tincture( $feat_col, $data['body'] );
      } else { // colour not given in blazon
        if ( array_key_exists('notpresent', $data) and !array_key_exists($key,$feat_cols) ) {
          $body .= $data['notpresent']; // Use the notpresent data
        } elseif ( array_key_exists('colour', $data )) {
          // if given, use a default colour
          $body .= '<g fill="' . $data['colour'] . '">' . $data['body'] . '</g>';
        } elseif ( $charge_is_proper and array_key_exists('proper', $data )) {
          // if given, use a proper colour
          $body .= '<g fill="' . $data['proper'] . '">' . $data['body'] . '</g>';
        } else {
          // else just add the feature to the main body
          $body .= $data['body'];
        }
      } 
    }
  }
  if ( array_key_exists('tail', $chg_data) ) $body .= $chg_data['tail'];
  if ( $demi!= null ) {
    if ( array_key_exists('demi', $chg_data) and $chg_data['demi'] == 'top' ) {
      $half = $chg_data['height'] / 2;
      $clip = add_def ( 'clipPath', '<rect x="0" y="0" width="' . $chg_data['height'] . '" height="' . $half . '" />' );
      $body = '<g clip-path="url(#' . $clip . ')">' . $body . '</g>';
      $chg_data['height'] = $half;
    } else {
      $half = $chg_data['width'] / 2;
      $clip = add_def ( 'clipPath', '<rect x="0" y="0" width="' . $half . '" height="' . $chg_data['height'] . '" />' );
      $body = '<g clip-path="url(#' . $clip . ')">' . $body . '</g>';
      $chg_data['width'] = $half;
    }
  }
  if ( $charges_on ) {
    // Turn off flexible scaling (as on charges could be distorted by flexing) ???
    // $chg_data['hflex'] = $chg_data['wflex'] = 1;
    $scale = min ( $chg_data['width']/1000, $chg_data['height']/1200);
    $charges = makeCharge($charges_on);
    // scale to fit onto charge - then move so charges are central
    $charges = sprintf('<g transform="translate(%2f,%2f) scale(%4f)">%s</g>', (($chg_data['width']/2)-(1000*$scale)/2), (($chg_data['height']/2)-(1200*$scale)/2),
                        $scale, $charges);
    $body .= $charges;
  }
  $chg_data['body'] = $body;
  return $chg_data;
}
?>
