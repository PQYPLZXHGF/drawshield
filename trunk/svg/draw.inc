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

?>