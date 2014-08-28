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

   $chg_data_cache = array();
   
   function get_chg_data() {
     global $dom;
     global $chg_data_cache;
     
     $xpath = new DOMXPath($dom);
     
     foreach ( $xpath->query("//charge") as $chg ) {
       $chg_ref = unique('chg');
       $chg_data_cache[$chg_ref] = read_chg_file($chg);
       // Add a modifier to link to the cached charge data
       $chg->appendChild(make_mod('chg_data', $chg_ref ));
     }
   }
   
   function read_chg_file($node) {
     
     if ( is_null($node) or $node->nodeName == 'missing' ) {
       $title = 'missing';
       $chg_data = array();
     } else {
       $charge_key =  'charges/' . $node->getAttribute('type') . '/' . $node->getAttribute('subtype');
       if ( ($title = $node->getAttribute('tokens')) == null ) $title = $node->getAttribute('subtype');
       $chg_data = includeCharge( $node, $charge_key );
       if ( array_key_exists('file', $chg_data ) and ($chg_data['file'] != null)) { // Need to read from inkscape file
         $target = 'charges/' . $node->getAttribute('type') . '/' . $chg_data['file'];
         if ( file_exists($target) )
           $chg_data['svgCode'] = file_get_contents($target);
         else
           draw_message('internal',"Missing SVG file $target");
       }
     }
    if ( !array_key_exists('svgCode', $chg_data) ) {
      draw_message('internal',"Cannot draw $title");
      $chg_data['svgCode'] = '<svg height="100" width="100"><g stroke="none"><path fill-rule="evenodd" d="M0,0h100v100h-100zM10,10h80v80h-80z" />' .
               '<text x="50" y="55" font-size="15" text-anchor="middle">' . $title . '</text></g></svg>';
    }
    $chg_data['title'] = $title;
    return $chg_data;
  }
     
   
   function makeCharge($charge) {
     $placements = get_placement($charge);
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
  global $chg_data_cache;
  
  $chg_ref = get_mod($node, 'chg_data');
  if ( !array_key_exists($chg_ref, $chg_data_cache) )
    $chg_data = read_chg_file($node);
  else
    $chg_data = $chg_data_cache[$chg_ref];

  // Process charge features and modifiers
  $charges_on = null;
  $feat_cols = array();
  $bodyTincture = null;
  $demi = null;
  $proper = null;
  if ( array_key_exists('proper',$chg_data)) $proper = $chg_data['proper'];
  foreach ( $node->childNodes as $child ) {
    switch ( $child->nodeName ) {
      case 'feature':
        $featureTinc = $child->firstChild;
        $featureName = $child->getAttribute('name');
        $tinctureType = $featureTinc->firstChild;
        switch ($tinctureType->nodeName) {
          case 'colour':
            $feat_cols[$featureName] = rgb($tinctureType->getAttribute('name'));
            break;
          case 'proper':
            if ( is_array($proper) ) {
              if ( array_key_exists($featureName,$proper))
                $feat_cols[$featureName] = $proper[$featureName];
              else
                $feat_cols[$featureName] = $proper['body'];
            } elseif ( $proper != null ) // not an array, everything is same colour
              $feat_cols[$featureName] = $proper;
            else { // no proper colour given
              $feat_cols[$featureName] = '#696969';
              draw_message('blazon',"No proper colour for $featureName");
            }
            break;
          default: // treatment or something
            draw_message('Warning',"Features can only be plain colours");
            break;
        }
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
  if (is_array($proper)) $proper = $proper['body'];
  // By this point, $proper contains the proper colour code for the body (if given).
  // $feat_cols contains a array of named features => colour codes
  // We will now work out the actual colours to be used for the body and any unnamed features
  $col_type = $charge_col->firstChild;
  if ( $col_type->nodeName == 'proper' ) {
    if ( $proper != null ) {
      $col_type->setAttribute('spec', $proper);
    } else {
      $col_type->setAttribute('spec', '#696969');
      draw_message('warning','No proper colour for ' . $node->getAttribute('subtype'));
    }
  }
  // So we now have $charge_col set to a valid tincture node and the feat_cols array set, apply this to the svg Data
  // dummy assignments
  $body = $height = $width = $licence = null;
  extract(getSvgFragment($chg_data['svgCode'], $feat_cols ));
  // $body now contains a valid fragment of SVG, ready for use
  // Also, $licence, $height and $width are set
  if ( $demi != null ) {
    if ( array_key_exists('demi', $chg_data) and $chg_data['demi'] == 'horizontal' ) {
      $half = $height / 2;
      $clip = add_def ( 'clipPath', '<rect x="0" y="0" width="' . $width . '" height="' . $half . '" />' );
      $body = '<g clip-path="url(#' . $clip . ')">' . $body . '</g>';
      $height = $half;
    } else {
      $half = $chg_data['width'] / 2;
      $clip = add_def ( 'clipPath', '<rect x="0" y="0" width="' . $half . '" height="' . $height . '" />' );
      $body = '<g clip-path="url(#' . $clip . ')">' . $body . '</g>';
      $width = $half;
    }
  }
  if ( $charges_on ) {
    // Turn off flexible scaling (as on charges could be distorted by flexing) ???
    // $chg_data['hflex'] = $chg_data['wflex'] = 1;
    $scale = min ( $width/1000, $height/1000);
    $charges = makeCharge($charges_on);
    // scale to fit onto charge - then move so charges are central
    $charges = sprintf('<g transform="translate(%2f,%2f) scale(%4f)">%s</g>', (($width/2)-(1000*$scale)/2), (($height/2)-(1000*$scale)/2),
                        $scale, $charges);
    $body .= $charges;
  }

  if (isset($chg_data['link']))
    draw_message('link',$node->getAttribute('subtype') . ' ' . $chg_data['link'] );

  draw_message('licence',$node->getAttribute('subtype') . " $licence");
  $chg_data['licence'] = $licence;
  $chg_data['body'] = $body;
  $chg_data['height'] = $height;
  $chg_data['width'] = $width;
  return $chg_data;
}
