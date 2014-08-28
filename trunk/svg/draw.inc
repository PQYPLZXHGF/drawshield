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
  /**
   * @var DOMElement $child
   */
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
  global $options;
  global $version;

  $infobox = new infobox();

  // Apply heraldic knowledge!
  rewrite();

  // Get all the charge data
  get_chg_data();

  $header = '<?xml version="1.0" encoding="utf-8" ?>
  <svg version="1.1"
       baseProfile="full"
       xmlns="http://www.w3.org/2000/svg"
       xmlns:xlink="http://www.w3.org/1999/xlink" ' .
       'preserveAspectRatio="xMidYMid meet" height="' . (int)($options['size'] * 1.2) . '" width="' . $options['size'];
  if ( $options['highlight'] )
    $header .= '" viewBox="0 0 1020 1220">';
  else
    $header .= '" viewBox="0 0 1000 1200">';
  if ( $options['highlight']) {
    $header .= '<defs>
    <linearGradient id="linearGradient1">
      <stop style="stop-color:white;stop-opacity:0.3137255;" offset="0" />
      <stop offset="0.19" style="stop-color:white;stop-opacity:0.25098041;" />
      <stop style="stop-color:#6b6b6b;stop-opacity:0.1254902;" offset="0.60000002" />
      <stop style="stop-color:black;stop-opacity:0.1254902;" offset="1" />
    </linearGradient>
    <radialGradient xlink:href="#linearGradient1" id="radialGradient1"
       gradientUnits="userSpaceOnUse"
       gradientTransform="matrix(1.353218,0,0,1.348928,-77.62935,-85.74693)"
       cx="450"
       cy="450"
       fx="450"
       fy="450"
       r="500" />
     <linearGradient id="linearGradient2">
      <stop style="stop-color:#9b9b9b;stop-opacity:0.3137255;" offset="0" />
      <stop style="stop-color:#black;stop-opacity:0.9;" offset="0.60000002" />
      <stop style="stop-color:#6b6b6b;stop-opacity:0.6;" offset="1" />
    </linearGradient>
    <radialGradient xlink:href="#linearGradient2" id="radialGradient2"
       gradientUnits="userSpaceOnUse"
       gradientTransform="matrix(1.353218,0,0,1.348928,-77.62935,-85.74693)"
       cx="450"
       cy="450"
       fx="450"
       fy="450"
       r="500" />      </defs>';
  }

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
  // Add highlights, if required
  if ( $options['highlight']) {
  $body .= '<path d="M 0,0 h1000 v1200 h-1000z"
       style="opacity:1;fill:url(#radialGradient1);fill-opacity:1;fill-rule:evenodd;stroke:none;stroke-width:1px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1"
       />';
  }
  // Clip to shield shape
  $clipShield = add_def('clipPath', '<path d="m 0,0 0,800 c -6.0479349,41.93063 1.2341419,84.33503 21.489586,125.13639 20.255443,40.80137 53.477613,79.98631 98.039434,115.63581 44.56181,35.6494 100.44867,67.7517 164.92346,94.7345 64.47479,26.9828 137.51639,48.8374 215.54752,64.4933 78.03113,-15.6559 151.07273,-37.5105 215.54752,-64.4933 64.47479,-26.9828 120.36165,-59.0851 164.92346,-94.7345 44.56182,-35.6495 77.78399,-74.83444 98.03943,-115.63581 C 998.76586,884.33503 1006.0479,841.93063 1000,800 l 0,-800 z" />' );
  $body .= add_def();
  // Add dropshadow
  $dropShadow = '';
  if ( $options['highlight'] )
    $dropShadow = '<path d="m 20,20 0,800 c -6.047935,41.93063 1.234142,84.33503 21.489586,125.13639 20.255443,40.80137 53.477613,79.98631 98.039434,115.63581 44.56181,35.6494 100.44867,67.7517 164.92346,94.7345 64.47479,26.9828 137.51639,48.8374 215.54752,64.4933 78.03113,-15.6559 151.07273,-37.5105 215.54752,-64.4933 64.47479,-26.9828 120.36165,-59.0851 164.92346,-94.7345 44.56182,-35.6495 77.78399,-74.83444 98.03943,-115.63581 C 1018.7659,904.33503 1026.0479,861.93063 1020,820 l 0,-800 z"
       style="opacity:0.5;fill:url(#radialGradient2);fill-opacity:1;fill-rule:evenodd;stroke:none;"
       />';
  $body = $dropShadow . '<g clip-path="url(#' . $clipShield . ')">' . $body . '</g>';
  // Add outline of shield shape, only if required
  if ( $options['palette'] == 'nocolour')
    $body .=  '<path fill="none" stroke="' . rgb('division-stroke') . '" stroke-width="4" d="M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" />';
  if ( $options['asFile'] and $options['saveFormat'] != 'svg') // Fix for Imagick
    $body .=  '<path fill="#FFFFFF" stroke="none" d="M 0 1200 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 1200 Z" />';
  // Rest depends on output format
  if ( $options['asFile'] or $options['printable'] ) { // minimal decoration, no infobox
      $body .= '<text id="test1" x="10" y="1160" font-size="30" >' . $version['name'] . ' ' . $version['release'] . '</text><text x="10" y="1190" font-size="30" >' . $version['website'] . '</text>';
  } else { // in line version, all the bells and whistles
    $infobox->setTab(2,'(Spare)');
    $infobox->setTab(3,'(Spare)');
    $infobox->setTab(4,'Legal');
    $infobox->addHeader(4,'Disclaimer:');
    $infobox->addText(4,'Provided for education and information only. The use of heraldic devices is restricted in many countries, independently of copyright. The granting of a Coat of Arms is solely the right of the appropriate Heraldic Authority for your nationality and country of residence.');
    $infobox->AddHeader(4,'Program Code Credits:');
    $infobox->addText(4,'(c) Karl R. Wilcox 2010-2014' );
    $infobox->addText(4,'Apache 2.0 License karl@karlwilcox.com');
    $body .= '<text id="test1" x="10" y="1160" font-size="30" >' . $version['name'] . ' ' . $version['release'] . '</text><text x="10" y="1190" font-size="30" >' . $version['website'] . '</text>';
    get_error_messages($infobox);
    $body .= '<g onclick="document.getElementById(\'infobox\').setAttribute(\'visibility\',\'visible\');document.getElementById(\'text1\').setAttribute(\'visibility\',\'visible\');" >';
    if ( $options['notify'] ) $body .= '<text fill="red" text-anchor="end" x="990" y="1160" font-size="30">Error reported</text>';
    $body .= '<text fill="black" text-anchor="end" x="990" y="1190" font-size="30">Click for information</text>';
    $body .= '</g>';
    $body .= $infobox->getInfobox();
  }
  return $header . $body . $trailer;
}

