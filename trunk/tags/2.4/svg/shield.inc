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

function scripts($action, $data = '', $name = '') {
  static $scriptText = '';
  static $scriptNames = array();
  
  switch ( $action ) {
  case 'add':
    if ( $name != '' ) {
      if ( in_array($name, $scriptNames)) return;
      $scriptNames[] = $name;
    }
    $scriptText .= $data . "\n";
    break;
  case 'show':
    return $scriptText;
    break;
  }
  return null;
}


function draw() {
  global $dom;
  global $size, $tagline1, $tagline2;
  global $asFile;
  global $scripts;

  // Apply heraldic knowledge!
  rewrite();

  // Get all the charge data
  get_chg_data();

  $header = '<?xml version="1.0" encoding="utf-8" ?>
  <svg version="1.1"
       baseProfile="full"
       xmlns="http://www.w3.org/2000/svg"
       xmlns:xlink="http://www.w3.org/1999/xlink" ' .
       'preserveAspectRatio="xMidYMid meet" height="' . (int)($size * 1.2) . '" width="' . $size . '" viewBox="0 0 1000 1200">';

  $trailer =  "</svg>\n";

  $blazonNode = $dom->documentElement;
  $body = '';
  foreach ( $blazonNode->childNodes as $node ) {
    switch ( $node->nodeName ) {
    case 'shield':
      $body .= makeshield($node,'10:12');
      break;
      // other elements for future expansion
    }
  }
  $clipShield = add_def('clipPath', '<path d="M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" />' );
  $body .= add_def();
  $body = '<g clip-path="url(#' . $clipShield . ')">' . $body . '</g>';
  if ( !$asFile ) {
    $body .= '<text id="test1" x="10" y="1160" font-size="30" >' . $tagline1 . '</text><text x="10" y="1190" font-size="30" >' . $tagline2 . '</text>';
    $body .= get_error_messages();
    $header .= '
    <script type="text/ecmascript">
<![CDATA[
';
    $header .= scripts('show');
    $header .= '
 ]]>
</script>
';
  } else {
    $header .= '<title>' . htmlentities($blazonNode->getAttribute('blazonText')) . '</title>';
    $header .= '<desc>'  . htmlentities(get_error_text()) . '</desc>'; 
  }
  return $header . $body . $trailer;
}

function get_hierarchy( $item ) {
  $hierarchy = '';
  
  do {
    if ( $item->nodeName == 'shield') {
      $index = $item->getAttribute('index');
      switch ( $item->parentNode->nodeName ) {
      case 'blazon':
        $hierarchy = 'PL' . $hierarchy;
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

function makePlain( &$children, $drawnAR = '10:12' ) {
  global $aspect_ratio;
  
  $aspect_ratio = $drawnAR;
  
  $retval = '';
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
  return $retval;
}

function makeshield( &$node, $this_AR ) {
  global $dom;
  
  $origNode = $node;
  if ( $node->hasAttribute('IDREF') ) {
    $node = $dom->getElementById($node->getAttribute('IDREF'));
  }


  $retval = '<g>';
  
  foreach ( $node->childNodes as $child ) {
    $children = $child->childNodes;
    switch ( $child->nodeName ) {
      case 'plain':
        $retval .= makePlain($children, $this_AR);
        break;
      case 'dimidiated':
        switch ( $this_AR ) {
        case '10:12':
          $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1200 0,1200Z" />' );
          $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1200 500,1200Z" />' );
          $child_AR = '10:12';
          break;
        case '10:10':
          $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1000 0,1000Z" />' );
          $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1000 500,1000Z" />' );
          $child_AR = '10:12';
          break;
        case '10:14':
          $clip1 = add_def( 'clipPath', '<path d="m70,0L430,0 430,1200 0,1200Z" />' );
          $clip2 = add_def( 'clipPath', '<path d="m500,0L860,0 860,1200 500,1200Z" />' );
          $child_AR = '10:14';
          break;
        default:
          draw_message('warning', "Dimidiated shield too narrow" );
          $clip1 = add_def( 'clipPath', '<path d="m70,0L430,0 430,1200 0,1200Z" />' );
          $clip2 = add_def( 'clipPath', '<path d="m500,0L860,0 860,1200 500,1200Z" />' );
          $child_AR = '10:14';
          break;
        }
        foreach ( $children as $kid ) {
          switch( $kid->getAttribute('index') ) {
          case '1':
            region('push','D1');
            $retval .= '<g clip-path="url(#' . $clip1 . ')" >' . makeshield( $kid, $child_AR ) . "</g>\n";
            region('pop');
            break;
          case '2':
            region('push','D2');
            $retval .= '<g clip-path="url(#' . $clip2 . ')" >' . makeshield( $kid, $child_AR ) . "</g>\n";
            region('pop');
            break;
          }
        }
        $retval .= add_def();
        break;
      case 'impaled':
        switch ( $this_AR ) {
        case '10:12':
          $clipI = add_def( 'clipPath', '<path d="M250,0h500v1200h-500v-1200z" />' );
          $xOffset = 250;
          $child_AR = '10:24';
          break;
        case '10:10':
          $clipI = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1000z" />' );
          $xOffset = 250;
          $child_AR = '10:20';
          break;
        case '10:14':
          $clipI = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
          $xOffset = 285;
          $child_AR = '10:28';
          break;
        default:
          draw_message('warning', "Impaled shield too narrow" );
          $clipI = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
          $xOffset = 285;
          $child_AR = '10:28';
          break;
        }
        foreach ( $children as $kid ) {
          switch( $kid->getAttribute('index') ) {
          case '1':
            region('push','I1');
            $imp1 = makeshield( $kid, $child_AR ); 
            region('pop');
            break;
          case '2':
            region('push','I2');
            $imp2 = makeshield( $kid, $child_AR );
            region('pop');
            break;
          }
        }
        $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(-' . (500 - $xOffset) . ',0)" >' .  $imp1  . "</g>\n";
        $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(' . (500 - $xOffset) . ',0)" >' . $imp2 . "</g>\n";
        $retval .= add_def();
        break;
      case 'quartered':
        switch ( $this_AR ) {
        case '10:12':
          $clipQ12 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1000 0,1000Z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="m70,0L930,0 930,1200 70,1200Z" />' );
          $trans1 =  ' transform="scale(0.5,0.5)" ';
          $trans2 =  ' transform="translate(500,0) scale(0.5,0.5)" ';
          $trans3 =  ' transform="translate(0,500) scale(0.58333) translate(-70,0)" ';
          $trans4 =  ' transform="translate(500,500) scale(0.58333)  translate(-70,0)" ';
          $child12_AR = '10:10';
          $child34_AR = '10:14';
          break;
        case '10:10':
          $clipQ12 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1000 0,1000Z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="m0,0L1000,0 1000,1000 0,1000Z" />' );
          $trans1 =  ' transform="scale(0.5,0.5)" ';
          $trans2 =  ' transform="translate(500,0) scale(0.5)" ';
          $trans3 =  ' transform="translate(0,500) scale(0.5)" ';
          $trans4 =  ' transform="translate(500,500) scale(0.5)" ';
          $child12_AR = '10:10';
          $child34_AR = '10:10';
          break;         
        case '10:14':
          $clipQ12 = add_def( 'clipPath', '<path d="m70,0L930,0 930,1200 70,1200Z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="m70,0L930,0 930,1200 70,1200Z" />' );
          $trans1 =  ' transform="scale(0.58333) translate(-70,0)" ';
          $trans2 =  ' transform="translate(500,0) scale(0.58333) translate(-70,0)" ';
          $trans3 =  ' transform="translate(0,500) scale(0.58333) translate(-70,0)" ';
          $trans4 =  ' transform="translate(500,500) scale(0.58333) translate(-70,0)" ';
          $child12_AR = '10:14';
          $child34_AR = '10:14';
          break; 
          
        case '10:20':
          $clipQ12 = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1000z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1000z" />' );
          $trans1 =  ' transform="translate(250,0) scale(0.5) translate(-250,0)"';
          $trans2 =  ' transform="translate(500,0) scale(0.5) translate(-250,0)" ';
          $trans3 =  ' transform="translate(250,500) scale(0.5) translate(-250,0)" ';
          $trans4 =  ' transform="translate(500,500) scale(0.5) translate(-250,0)" ';
          $child12_AR = '10:20';
          $child34_AR = '10:20';
          break;
        case '10:24':
          $clipQ12 = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1200z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1200z" />' );
          $trans1 =  ' transform="translate(250,0) scale(0.5) translate(-250,0)"';
          $trans2 =  ' transform="translate(500,0) scale(0.5) translate(-250,0)" ';
          $trans3 =  ' transform="translate(250,600) scale(0.5) translate(-250,0)" ';
          $trans4 =  ' transform="translate(500,600) scale(0.5) translate(-250,0)" ';
          $child12_AR = '10:24';
          $child34_AR = '10:24';
          break;         
        case '10:28':
          $clipQ12 = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
          $clipQ34 = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
          $trans1 =  ' transform="translate(285,0) scale(0.58333) translate(-285,0)" ';
          $trans2 =  ' transform="translate(500,0) scale(0.58333) translate(-285,0)" ';
          $trans3 =  ' transform="translate(285,600) scale(0.58333) translate(-285,0)" ';
          $trans4 =  ' transform="translate(500,600) scale(0.58333) translate(-285,0)" ';
          $child12_AR = '10:28';
          $child34_AR = '10:28';
          break; 

        default:
          draw_message ( 'internal', 'Unknown aspect ratio for quartered ' . $this_AR );
        }
        foreach ( $children as $kid ) {
          switch( $kid->getAttribute('index') ) {
          case '1':
            region('push','Q1');
            $retval .= '<g clip-path="url(#' . $clipQ12 . ')" ' . $trans1 . ' >' . makeshield( $kid, $child12_AR ) . "</g>\n";
            region('pop');
            break;
          case '2':
            region('push','Q2');
            $retval .= '<g clip-path="url(#' . $clipQ12 . ')" ' . $trans2 . ' >' . makeshield( $kid, $child12_AR ) . "</g>\n";
            region('pop');
            break;
          case '3':
            region('push','Q3');
            $retval .= '<g clip-path="url(#' . $clipQ34 . ')" ' . $trans3 . ' >' . makeshield( $kid, $child34_AR ) . "</g>\n";
            region('pop');
            break;
          case '4':
            region('push','Q4');
            $retval .= '<g clip-path="url(#' . $clipQ34 . ')" ' . $trans4 . ' >' . makeshield( $kid, $child34_AR ) . "</g>\n";
            region('pop');
            break;
          }
        }
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