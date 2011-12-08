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

   
   function makeCharge($charge) {
     $placements = array(0 => 'x/x/x/x/x/x');
     $placements = get_mod($charge,'placement');
     $retval = '';
     foreach ( explode('*',$placements) as $placement ) {
       $retval .= place_charges ( $charge, $placement );
     }
     return $retval;
   }
   
function includeCharge( $node, $charge_key ) {
   $charge = array ();
   include ( $charge_key . '.inc' );
   return $charge;
}

function getCharge( $node ) {
   static $charge_cache = array();

  if ( $node->nodeName == 'missing' ) {
    $title = 'missing';
    $chg_data = array ( 'width' => 100, 'height' => 100,
        'body' => '<g stroke="none"><path fill-rule="evenodd" d="M0,0h100v100h-100zM15,15h70v70h-70z" />
              <text x="50" y="65" font-size="30" text-anchor="middle">Msng</text></g>', 'wflex' => 2, 'hflex' => 2 );
  } else {
    if ( ($title = $node->getAttribute('tokens')) == null ) $title = $node->getAttribute('subtype');
    $charge_key =  'charges/' . $node->getAttribute('type') . '/' . $node->getAttribute('subtype');
    if ( array_key_exists($charge_key, $charge_cache) ) {
      $chg_data = $charge_cache[$charge_key];
    } else {
      $chg_data = includeCharge( $node, $charge_key );
      if ( array_key_exists('file', $chg_data )) { // Need to extract body and features from inkscape file
        $chg_data = array_merge_recursive($chg_data, ink2chg('charges/' . $node->getAttribute('type') . '/' . $chg_data['file']));
        $charge_cache[$charge_key] = $chg_data;
      }
    }
  }
  if ( $chg_data == null or !array_key_exists('body', $chg_data) ) {
      draw_message('internal',"Cannot draw $title");
      $chg_data = array ( 'width' => 100, 'height' => 100,
        'body' => '<g stroke="none"><path fill-rule="evenodd" d="M0,0h100v100h-100zM10,10h80v80h-80z" />' .
               '<text x="50" y="55" font-size="15" text-anchor="middle">' . $title . '</text></g>',
               'wflex' => 2, 'hflex' => 2 );
  }
  if ( array_key_exists('licence', $chg_data) ) {
    $title .= ': ' . $chg_data['licence'];
    draw_message('licence', $title);
  }
  $chg_data['title'] = $title;
  $body = $chg_data['body'];

  // Process charge features and modifiers
  $charges_on = null;
  $feat_cols = array();
  $charge_col = null;
  $demi = null;
  $charge_is_proper = false;
  foreach ( $node->childNodes as $child ) {
    switch ( $child->nodeName ) {
      case 'feature':
        $feat_cols[$child->getAttribute('name')] = $child->firstChild;
        break;
      case 'tincture':
        $charge_col = $child;
        break;
      case 'modifier':
        switch ($child->getAttribute('name')) {
          case 'demi':
            $demi = true;
            break;
          case 'charged-with':
            $charges_on = $child->firstChild;
            break;
        }
        break;
    }
  }
  $col_type = $charge_col->firstChild;
  if ( $col_type->nodeName == 'default' and array_key_exists('default', $chg_data) ) {
    $col_type->setAttribute('spec', $chg_data['default']);
  }
  // Apply proper colour (if there is one)
  if ( $col_type->nodeName == 'proper' and array_key_exists('proper', $chg_data) )
  {
    $col_type->setAttribute('spec', $chg_data['proper']);
    $charge_is_proper = true;
  }

  // Apply colours to features and append to the body
  if ( array_key_exists('features',$chg_data) and count($chg_data['features']) > 0 ) {
    foreach ( $chg_data['features'] as $key => $data ) {
      // Find if there is a proper colour
      if ( array_key_exists('proper', $data) )
        $proper_spec = $data['proper'];
      elseif ( array_key_exists('proper', $chg_data) )
        $proper_spec = $chg_data['proper'];
      // if ( ! array_key_exists('body', $data) ) continue; // No body, so no colour to apply
      if ( array_key_exists($key, $feat_cols) and ($feat_col = $feat_cols[$key]) != null ) { // we have an explicitly coloured feature
        $col_type = $feat_col->firstChild;
        if ( $col_type->nodeName == 'proper' ) $col_type->setAttribute('spec', $proper_spec);
        $feature = apply_tincture( $feat_col, $data['body'] );
      } else { // colour not given in blazon
        if ( array_key_exists('notpresent', $data) and !array_key_exists($key,$feat_cols) ) {
          $feature= $data['notpresent']; // Use the notpresent data
        } elseif ( array_key_exists('colour', $data )) {
          // if given, use a default colour
          $feature= '<g fill="' . $data['colour'] . '">' . $data['body'] . '</g>';
        } elseif ( $charge_is_proper and array_key_exists('proper', $data )) {
          // if given, use a proper colour
          $feature= '<g fill="' . $data['proper'] . '">' . $data['body'] . '</g>';
        } else {
          // else just add the feature to the main body
          $feature= $data['body'];
        }
      }
      if ( array_key_exists('behind', $data ))
        $body = $feature . $body;
      else
        $body .= $feature;
    }
  }
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
    $scale = min ( $chg_data['width']/1000, $chg_data['height']/1000);
    $charges = makeCharge($charges_on);
    // scale to fit onto charge - then move so charges are central
    $charges = sprintf('<g transform="translate(%2f,%2f) scale(%4f)">%s</g>', (($chg_data['width']/2)-(1000*$scale)/2), (($chg_data['height']/2)-(1000*$scale)/2),
                        $scale, $charges);
    $body .= $charges;
  }
  // Set the stroke colour for all charges
  $chg_data['body'] = '<g stroke="#696969">' . $body . '</g>';
  return $chg_data;
}
?>