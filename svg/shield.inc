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

// Global variables for SVG generation
$svg_region = 'PL';
$svg_chief = 'NC';
$error_list = array();
define( 'E_SVG',1088);
define( 'E_PARSER',1256);

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
  foreach ( $ord_chgs->child_nodes() as $child ) {
    if ( $child->node_name() == 'ordinary' and $child->get_attribute('type') == 'chief' ) return true;
  }
  return false;
}

function makeOrdChgs( $node ) {
  $retval = '';
  foreach ( $node->child_nodes() as $child ) {
    switch ( $child->node_name() ) {
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

  if ( $new = preprocess ( $dom ) ) {
    $dom->free();
    $dom = domxml_open_mem($new, DOMXML_LOAD_PARSING,$error);
  }
  $header = '<?xml version="1.0" encoding="utf-8" ?>
  <svg version="1.1"
       baseProfile="full"
       xmlns="http://www.w3.org/2000/svg"
       xmlns:xlink="http://www.w3.org/1999/xlink" ' .
       'preserveAspectRatio="xMidYMid meet" height="' . (int)($size * 1.2) . '" width="' . $size . '" viewBox="0 0 1000 1200" >
  ';

  $trailer = "</svg>\n";

  $blazonNode = $dom->document_element();
  $body = '<desc>' . htmlentities($blazonNode->get_attribute('blazonText')) . '</desc>';
  foreach ( $blazonNode->child_nodes() as $node ) {
    switch ( $node->node_name() ) {
      case 'shield':
        $body .= makeshield($node);
        break;
      // other elements for future expansion
    }
  }

  $body .= '<path  fill="#FFFFFF" fill-rule="evenodd" d="M-100,-100 h1200 v1400 h-1200 v-1400z M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" />
      <text x="10" y="1160" font-size="30" >' . $tagline1 . '</text><text x="10" y="1190" font-size="30" >' . $tagline2 . '</text>';
  $body .= get_error_messages();

  return $header . $body . $trailer;
}

function makeshield( $node ) {
  global $dom;

  static $id_nodes = array();

  if ( $node->has_attribute('ID') ) $id_nodes[$node->get_attribute('ID')] = $node;
  if ( $node->has_attribute('IDREF') ) $node = $id_nodes[$node->get_attribute('IDREF')];
  

  $retval = '<g><title>Shield</title>';
  foreach ( $node->child_nodes() as $child ) {
    $children = $child->child_nodes();
    switch ( $child->node_name() ) {
      case 'plain':
        // Does this shield contain a chief?
        $found = false;
        foreach ( $children as $kid ) {
          if ( !$found and $kid->node_name() == 'ord_chgs' ) $found = find_chief ( $kid );
        }
        chief('push', $found ? 'CH' : 'NC');
        // Process the shield parts
        foreach ( $children as $kid ) {
          switch ( $kid->node_name() ) {
            case 'tincture':
              // Paint the field
              $retval .= apply_tincture ( $kid, '<rect x="0" y="0" width="1000" height="1200" ><title>Field</title></rect>' , '1000,1200' );
              break;
            case 'ord_chgs':
              // process ordinaries and charges
              $retval .= makeOrdChgs($kid);
              break;
            case 'absolute': // TODO Is this still needed?
              //region('push','PL');
              chief('push','NC');
              $retval .= makeOrdChgs($kid->first_child());
              chief('pop');
              break;
          }
        }
        chief('pop');
        break;
      case 'dimidiated':
        $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1200 0,1200Z" />' );
        $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1200 500,1200Z" />' );
        region('push','D1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" ><title>Dimidiated</title><desc>Left</desc>' . makeshield( $children[0] ) . "</g>\n";
        region('swap','D2');
        $retval .= '<g clip-path="url(#' . $clip2 . ')" ><title>Dimidiated</title><desc>Right</desc>' . makeshield( $children[1] ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'impaled':
        $clip1 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1200 0,1200Z" />' );
        region('push','I1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="scale(0.5,1)" ><title>Impaled</title><desc>Left</desc>' . makeshield( $children[0] )  . "</g>\n";
        region('swap','I2');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,0) scale(0.5,1)" ><title>Impaled</title><desc>Right</desc>' . makeshield( $children[1] ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'quartered':
        $clip1 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1200 0,1200Z" />' );
        region('push','Q1');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="scale(0.5)" ><title>Quarter</title><desc>First</desc>' . makeshield( $children[0] ) . "</g>\n";
        region('swap','Q2');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,0) scale(0.5)" ><title>Quarter</title><desc>Second</desc>' . makeshield( $children[1] ) . "</g>\n";
        region('swap','Q3');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(0,600) scale(0.5)" ><title>Quarter</title><desc>Third</desc>' . makeshield( $children[2] ) . "</g>\n";
        region('swap','Q4');
        $retval .= '<g clip-path="url(#' . $clip1 . ')" transform="translate(500,600) scale(0.5)" ><title>Quarter</title><desc>Fourth</desc>' . makeshield( $children[3] ) . "</g>\n";
        region('pop');
        $retval .= add_def();
        break;
      case 'missing':
        break;
      case 'overall':
        $retval .= makeOrdChgs($child->first_child());
        break;
    }
  }
  return $retval . '</g>';
}
?>
