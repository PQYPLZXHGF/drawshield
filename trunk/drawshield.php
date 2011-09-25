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

//
// Argument processing
//
$time_start = microtime(true);

// Set default values for arguments
$blazon = '';
$asFile = false;
$asText = false;
$size = 500;
$format = 'svg';
$log = true;
// Process arguments
if (isset($_GET['blazon'])) $blazon = html_entity_decode(strip_tags ($_GET['blazon']));
if (isset($_GET['format'])) $format = strip_tags ($_GET['format']);;
if (isset($_GET['asfile'])) $asFile = true;
if (isset($_GET['nolog'])) $log = false;
if (isset($_GET['size'])) {
  $size = strip_tags ($_GET['size']);
  if ( $size < 100 ) $size = 100;
}
if ( $format != 'svg' ) $asText = true;
if ( $format == 'svgtext' ) $format = 'svg';

//
// Global Variables
//

$tagline1 = "drawshield 2.3h";   // Advertising lines at bottom left
$tagline2 = "shield.karlwilcox.com";

// Quick response for empty blazon
if ( $format == 'svg' and $blazon == '' ) {
  header('Content-Type: text/xml; charset=utf-8');
  echo '<?xml version="1.0" encoding="utf-8" ?> <svg version="1.1" baseProfile="full" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" preserveAspectRatio="xMidYMid meet" height="' . ($size * 1.2) . '" width="' . $size . '" viewBox="0 0 1000 1200" > <g clip-path="url(#clipPath1)"><desc>argent</desc><g><title>Shield</title><g fill="#F0F0F0"><rect x="0" y="0" width="1000" height="1200" ><title>Field</title></rect></g></g></g><defs><clipPath id="clipPath1" > <path d="M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" /> </clipPath> </defs><text x="10" y="1160" font-size="30" >'
   . $tagline1 . '</text><text x="10" y="1190" font-size="30" >' . $tagline2 . '</text></svg>';
  exit;
}
// Otherwise log the blazon for research... (unless told not too)
if ( $log ) error_log($blazon);

// Read in the generated parsing tables
$flag_list = unserialize(file_get_contents('parser/data/flag_list.dat'));
$charge_list = unserialize(file_get_contents('parser/data/charge_list.dat'));
$modifier_list = unserialize(file_get_contents('parser/data/modifier_list.dat'));
$either_list = unserialize(file_get_contents('parser/data/either_list.dat'));
$ordinary_list = unserialize(file_get_contents('parser/data/ordinary_list.dat'));
// This is the list of words in the blazon, and the current parsing position
$words = array();
$cur_word = 0;
$matched_tokens = '';
// This is a list of charges or ordinaries awaiting a tincture
$pending_items = array();

// This is our XML generator and top level item for the parse tree
$dom = new DOMDocument('1.0');

// Read in the parsing code
$dir = opendir('parser');
while ( ($file = readdir($dir)) != false ) {
  if ( substr($file,-4) == '.inc' ) require 'parser/' . $file;
}

$parser_messages = $dom->createElement('messages');

fill_words($blazon);

$node = $dom->createElement('blazon');
$node->setAttribute("blazonText", $blazon);
$node->appendChild(shield());
$bad_words = '';
if ( $cur_word < count($words) ) {
  while ($cur_word < count($words))
    $bad_words .= $words[$cur_word++] . ' ';
  parser_message ('blazon', 'Not understood - ' . $bad_words);
}
parser_message('Disclaimer:', 'Provided for education and information only. The use of heraldic devices is restricted in many countries, independently of copyright. The granting of a Coat of Arms is solely the right of the appropriate Heraldic Authority for your nationality and country of residence.');
if ( $parser_messages->hasChildNodes() ) $node->appendChild($parser_messages);
$dom->appendChild($node);

// Read in the drawing code
$dir = opendir($format);
while ( ($file = readdir($dir)) != false ) {
  if ( substr($file,-4) == '.inc' ) require $format . '/' . $file;
}

$output = draw();

// Output content header
if ( $asFile ) {
 header("Content-type: application/force-download");
 header('Content-Disposition: inline; filename="shield.svg"');
 header("Content-Transfer-Encoding: text");
 header('Content-Disposition: attachment; filename="shield.svg"');
 header('Content-Type: image/svg+xml');
} elseif ( $asText ) {
 header("Content-Transfer-Encoding: text");
 header('Content-Type: text/plain');
} else {
header('Content-Type: text/xml; charset=utf-8');
}

echo $output;

?>