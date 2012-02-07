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

// Global variables for parsing
$svg_region = 'PL';
$svg_chief = 'NC';
$error_list = array();
// These are for scaling into quarters & dimidiations
$aspect_ratio = '10:12';
$scale_factor = 1.0;

function region ( $action, $region = null ) {
  global $svg_region;
  static $stack = array();

  switch ( $action ) {
    case 'push':
      array_push( $stack, $svg_region );
      $svg_region = $region;
      break;
    case 'swap':
      $svg_region = $region;
      break;
    case 'pop':
      $svg_region = array_pop( $stack );
      break;
  }
}

function chief ( $action, $chief = null ) {
  global $svg_chief;
  static $stack = array();

  switch ( $action ) {
    case 'push':
      array_push( $stack, $svg_chief );
      $svg_chief = $chief;
      break;
    case 'swap':
      $svg_chief = $chief;
      break;
    case 'pop':
      $svg_chief = array_pop( $stack );
      break;
  }
}

function find_chief ( $ord_chgs ) {
  foreach ( $ord_chgs->childNodes as $child ) {
    if ( $child->nodeName == 'ordinary' and $child->getAttribute('subtype') == 'chief' ) return true;
  }
  return false;
}

function makeOrdChgs( &$node ) {
  $retval = '';
  foreach ( $node->childNodes as $child ) {
    switch ( $child->nodeName ) {
      case 'ordinary':
        $retval .= makeOrdinary( $child );
        break;
      case 'charge':
        $retval .= makeCharge( $child );
        break;
    }
  }
  return $retval;
}


function draw() {
  global $dom;
  global $size, $tagline1, $tagline2;
  global $asFile;

  // Apply heraldic knowledge!
  rewrite();

  // Get all the charge data
  get_chg_data();

  $header = '<?xml version="1.0" encoding="utf-8" ?>
  <svg version="1.1"
       baseProfile="full"
       xmlns="http://www.w3.org/2000/svg"
       xmlns:xlink="http://www.w3.org/1999/xlink" ' .
       'preserveAspectRatio="xMidYMid meet" height="' . (int)($size * 1.2) . '" width="' . $size . '" viewBox="0 0 1000 1200" >';

  $trailer =  "</svg>\n";

  $blazonNode = $dom->documentElement;
  $body = '';
  //$body = '<desc>' . htmlentities($blazonNode->getAttribute('blazonText')) . '</desc>';
  foreach ( $blazonNode->childNodes as $node ) {
    switch ( $node->nodeName ) {
    case 'shield':
      $body .= makeshield($node);
      break;
      // other elements for future expansion
    }
  }
  $clipShield = add_def('clipPath', '<path d="M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" />' );
  $body .= add_def();
  $body = '<g clip-path="url(#' . $clipShield . ')">' . $body . '</g>';
  if ( !$asFile ) {
    $body .= '<text x="10" y="1160" font-size="30" >' . $tagline1 . '</text><text x="10" y="1190" font-size="30" >' . $tagline2 . '</text>';
    $body .= get_error_messages();
  } else {
    $header .= '<title>' . htmlentities($blazonNode->getAttribute('blazonText')) . '</title>';
    $header .= '<desc>'  . htmlentities(get_error_text()) . '</desc>'; 
  }
  return $header . $body . $trailer;
}

function set_aspect_ratio ( $hierarchy ) {
  global $aspect_ratio, $scale_factor;
  
  $aspect_ratio = '10:12';
  
  static $data = array (
    '10:12' => array ( 'Q1' => '10:10', 'Q2' => '10:10', 'Q3' => '10:14', 'Q4' => '10:14', 'I1' => '10:24', 'I2' => '10:24', 'D1' => '10:12', 'D2' => '10:12', 'scale' => 1.0 ),
    '10:10' => array ( 'Q1' => '10:10', 'Q2' => '10:10', 'Q3' => '10:14', 'Q4' => '10:14', 'I1' => '10:20', 'I2' => '10:20', 'D1' => '10:10', 'D2' => '10:10', 'scale' => 0.5 ),
    '10:14' => array ( 'Q1' => '10:14', 'Q2' => '10:14', 'Q3' => '10:14', 'Q4' => '10:14', 'I1' => '10:28', 'I2' => '10:28', 'D1' => '10:14', 'D2' => '10:14', 'scale' => 0.5833 ),
    '10:24' => array ( 'Q1' => '10:24', 'Q2' => '10:24', 'Q3' => '10:24', 'Q4' => '10:24', 'I1' => null, 'I2' => null, 'D1' => null, 'D2' => null, 'scale' => 1.0 ),
    '10:28' => array ( 'Q1' => '10:28', 'Q2' => '10:28', 'Q3' => '10:28', 'Q4' => '10:28', 'I1' => null, 'I2' => null, 'D1' => null, 'D2' => null, 'scale' => 0.5 ),
    '10:20' => array ( 'Q1' => '10:20', 'Q2' => '10:20', 'Q3' => '10:20', 'Q4' => '10:20', 'I1' => null, 'I2' => null, 'D1' => null, 'D2' => null, 'scale' => 0.5833 ),
    );
  
  foreach ( str_split($hierarchy, 2) as $level )
    if ( $level and $aspect_ratio )
      $aspect_ratio = $data[$aspect_ratio][$level];
    if ( $aspect_ratio == null ) {
      draw_message('warning', "Halved shield too narrow" );
      $aspect_ratio = '10:28';
    }
    $scale_factor = $data[$aspect_ratio]['scale'];
    // draw_message('warning', "$hierarchy $aspect_ratio" );
}

function get_hierarchy( &$item ) {
  $hierarchy = '';
  
  do {
    if ( $item->nodeName == 'shield') {
      $index = $item->getAttribute('index');
      switch ( $item->parentNode->nodeName ) {
      case 'blazon':
        // $hierarchy = 'PL' . $hierarchy;
        break;
      case 'quartered':
        $hierarchy = 'Q' . $index . $hierarchy;
        break;
      case 'impaled':
        $hierarchy = 'I' . $index . $hierarchy;
        break;
      case 'dimidiated':
        $hierarchy = 'D' . $index . $hierarchy;
        break;
      }
    }
    $item = $item->parentNode;
  } while ($item->nodeName != 'blazon');
  
  return $hierarchy;
}

function makeshield( &$node ) {
  global $dom;
  global $aspect_ratio;

  static $id_nodes = array();

  if ( $node->hasAttribute('ID') ) $id_nodes[$node->getAttribute('ID')] = $node;
  if ( $node->hasAttribute('IDREF') ) {
    $index = $node->getAttribute('index'); // save our current index
    $node = $id_nodes[$node->getAttribute('IDREF')]; // copy in previously defined node
    $node->setAttribute('index', "$index"); // Restore current index
  }


  $retval = '<g><title>Shield</title>';
  foreach ( $node->childNodes as $child ) {
    $children = $child->childNodes;
    switch ( $child->nodeName ) {
      case 'plain':
        // Does this shield contain a chief?
        $found = false;
        foreach ( $children as $kid ) {
          if ( !$found and $kid->nodeName == 'ord_chgs' ) $found = find_chief ( $kid );
        }
        set_aspect_ratio ( get_hierarchy($child->parentNode) );
        chief('push', $found ? 'CH' : 'NC');
        // Process the shield parts
        foreach ( $children as $kid ) {
          switch ( $kid->nodeName ) {
            case 'tincture':
              // Paint the field
              $retval .= apply_tincture ( $kid, '<rect x="0" y="0" width="1000" height="1200" ><title>Field</title></rect>' , '1000,1200' );
              break;
            case 'ord_chgs':
              // process ordinaries and charges
              $retval .= makeOrdChgs($kid);
              break;
          }
        }
        chief('pop');
        break;
      case 'dimidiated':
        $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1200 0,1200Z" />' );
        $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1200 500,1200Z" />' );
        region('push','D1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" >' . makeshield( $children->item(0) ) . "</g>\n";
        region('swap','D2');
        $retval .= '<g clip-path="url(#' . $clip2 . ')" >' . makeshield( $children->item(1) ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'impaled':
        $I1 = makeshield( $children->item(0)); // sets aspect_ratio (must be same for both sub-shields)
        switch ( $aspect_ratio ) {
        case '10:24':
          $clipI = add_def( 'clipPath', '<path d="M250,0h500v1200h-500v-1200z" />' );
          $xOffset = 250;
          break;
        case '10:20':
          $clipI = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1000z" />' );
          $xOffset = 250;
          break;
        case '10:28':
          $clipI = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
          $xOffset = 285;
          break;
        default:
          draw_message ( 'internal', 'Wrong aspect ratio for impaled ' . $aspect_ratio );
        }
        draw_message ( 'internal', "$aspect_ratio $xOffset" );
        region('push','I1');
        $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(-' . (500 - $xOffset) . ',0)" >' . $I1  . "</g>\n";
        region('swap','I2');
        $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(' . (500 - $xOffset) . ',0)" >' . makeshield( $children->item(1) ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'quartered':
        $clipQ12 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1000 0,1000Z" />' );
        $clipQ34 = add_def( 'clipPath', '<path d="m70,0L930,0 930,1200 70,1200Z" />' );
        region('push','Q1');
        $retval .= '<g clip-path="url(#' . $clipQ12 . ')" transform="scale(0.5,0.5)" >' . makeshield( $children->item(0) ) . "</g>\n";
        region('swap','Q2');
        $retval .= '<g clip-path="url(#' . $clipQ12 . ')" transform="translate(500,0) scale(0.5,0.5)" >' . makeshield( $children->item(1) ) . "</g>\n";
        region('swap','Q3');
        $retval .= '<g clip-path="url(#' . $clipQ34 . ')" transform="translate(0,500) scale(0.58333) translate(-70,0)" >' . makeshield( $children->item(2) ) . "</g>\n";
        region('swap','Q4');
        $retval .= '<g clip-path="url(#' . $clipQ34 . ')" transform="translate(500,500) scale(0.58333)  translate(-70,0)" >' . makeshield( $children->item(3) ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'missing':
        break;
      case 'overall':
        $retval .= makeOrdChgs($child->firstChild);
        break;
    }
  }
  return $retval . '</g>';
}
?>