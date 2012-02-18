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

  // Apply heraldic knowledge!
  rewrite();

  // Calculate all charge placements
  placements ();

  $header = '<?xml version="1.0" encoding="utf-8" ?>
  <svg version="1.1"
       baseProfile="full"
       xmlns="http://www.w3.org/2000/svg"
       xmlns:xlink="http://www.w3.org/1999/xlink" ' .
       'preserveAspectRatio="xMidYMid meet" height="' . (int)($size * 1.2) . '" width="' . $size . '" viewBox="0 0 1000 1200" >';

  $trailer =  "</svg>\n";

  $blazonNode = $dom->documentElement;
//  $body = '<desc>' . htmlentities($blazonNode->getAttribute('blazonText')) . '</desc>';
  $body = '<desc>' . $blazonNode->getAttribute('blazonText') . '</desc>';
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
  $body .= '<text x="10" y="1160" font-size="30" >' . $tagline1 . '</text><text x="10" y="1190" font-size="30" >' . $tagline2 . '</text>';
  $body .= get_error_messages();

  return $header . $body . $trailer;
}

function makeshield( &$node ) {
  global $dom;

  static $id_nodes = array();

  if ( $node->hasAttribute('ID') ) $id_nodes[$node->getAttribute('ID')] = $node;
  if ( $node->hasAttribute('IDREF') ) $node = $id_nodes[$node->getAttribute('IDREF')];


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
        $clip1 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1200 0,1200Z" />' );
        region('push','I1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="scale(0.5,1)" >' . makeshield( $children->item(0) )  . "</g>\n";
        region('swap','I2');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,0) scale(0.5,1)" >' . makeshield( $children->item(1) ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'quartered':
        $clip1 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1200 0,1200Z" />' );
        region('push','Q1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="scale(0.5)" >' . makeshield( $children->item(0) ) . "</g>\n";
        region('swap','Q2');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,0) scale(0.5)" >' . makeshield( $children->item(1) ) . "</g>\n";
        region('swap','Q3');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(0,600) scale(0.5)" >' . makeshield( $children->item(2) ) . "</g>\n";
        region('swap','Q4');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,600) scale(0.5)" >' . makeshield( $children->item(3) ) . "</g>\n";
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