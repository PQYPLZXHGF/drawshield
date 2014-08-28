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
// Global Variables
//
include 'version.inc';


//
// Argument processing
//

$p_globals = null;
// Process arguments
if (isset($_GET['blazon'])) $options['blazon'] = html_entity_decode(strip_tags ($_GET['blazon']));
if (isset($_GET['saveformat'])) $options['saveFormat'] = strip_tags ($_GET['saveformat']);;
if (isset($_GET['asfile'])) $options['asFile'] = true;
if (isset($_GET['palette'])) $options['palette'] = strip_tags($_GET['palette']);
if (isset($_GET['printable'])) $options['printable'] = true;
if (isset($_GET['highlight'])) $options['highlight'] = $_GET['highlight'] == '0' ? false : true;
if (isset($_GET['size'])) {
  $size = strip_tags ($_GET['size']);
  if ( $size < 100 ) $size = 100;
  $options['size'] = $size;
}


// Quick response for empty blazon
if ( $options['blazon'] == '' ) { // TODO "your shield here" message?
  header('Content-Type: text/xml; charset=utf-8');
  $output = '<?xml version="1.0" encoding="utf-8" ?><svg version="1.1" baseProfile="full" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" preserveAspectRatio="xMidYMid meet" height="' .
    ( $options['size'] * 1.2) . '" width="' .  $options['size'] . '" viewBox="0 0 1000 1200" >
    <g clip-path="url(#clipPath1)"><desc>argent</desc><g><title>Shield</title><g fill="#F0F0F0">
    <rect x="0" y="0" width="1000" height="1200" ><title>Field</title></rect></g></g></g>
    <defs><clipPath id="clipPath1" > <path d="M 0 0 L 0 800 A 800 400 0 0,0 500 1200 A 800 400 0 0,0 1000 800 L 1000 0 Z" /> </clipPath></defs>
    <text x="10" y="1160" font-size="30" >'
   . $version['name'] . ' ' . $version['release'] . '</text><text x="10" y="1190" font-size="30" >' . $version['website'] . '</text></svg>';
} else {
  // Otherwise log the blazon for research... (unless told not too)
  if ( $options['logBlazon']) error_log($options['blazon']);

  // Read in the generated parsing tables
  $charge_list = unserialize(file_get_contents('parser/data/charge_list.dat'));
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

  // Set up (empty) backreferences
  setpGlobals();
  $parser_messages = $dom->createElement('messages');

  fill_words($options['blazon']);

  $node = $dom->createElement('blazon');
  $node->setAttribute("blazonText", $options['blazon']);
  $node->appendChild(parse());
  //$node->appendChild(shield());
  $bad_words = '';
  if ( $cur_word < count($words) ) {
    while ($cur_word < count($words))
      $bad_words .= $words[$cur_word++] . ' ';
    parser_message ('blazon', 'Not understood - ' . $bad_words);
  }
  if ( $parser_messages->hasChildNodes() ) $node->appendChild($parser_messages);
  $dom->appendChild($node);

  // Read in the drawing code
  $dir = opendir('svg'); // All formats start out as SVG
  while ( ($file = readdir($dir)) != false ) {
    if ( substr($file,-4) == '.inc' ) require 'svg/' . $file;
  }
  $output = draw();
}

// Output content header
if ( $options['asFile'] ) {
  switch ($options['saveFormat']) {
    case 'svg':
     header("Content-type: application/force-download");
     header('Content-Disposition: inline; filename="shield.svg"');
     header("Content-Transfer-Encoding: text");
     header('Content-Disposition: attachment; filename="shield.svg"');
     header('Content-Type: image/svg+xml');
     echo $output;
     break;
    case 'jpg':
      $im = new Imagick();
      $im->readimageblob($output);
      $im->setimageformat('jpeg');
      $im->setimagecompressionquality(90);
      // $im->scaleimage(1000,1200);
      header("Content-type: application/force-download");
      header('Content-Disposition: inline; filename="shield.jpg"');
      header("Content-Transfer-Encoding: binary");
      header('Content-Disposition: attachment; filename="shield.jpg"');
      header('Content-Type: image/jpg');
      echo $im->getimageblob();
      break;
    case 'png':
    default:
     $im = new Imagick();
     $im->readimageblob($output);
     $im->setimageformat('png');
     // $im->scaleimage(1000,1200);
     header("Content-type: application/force-download");
     header('Content-Disposition: inline; filename="shield.png"');
     header("Content-Transfer-Encoding: binary");
     header('Content-Disposition: attachment; filename="shield.png"');
     header('Content-Type: image/png');
     echo $im->getimageblob();
     break;
   }
} else { // just send it back as SVG
  header('Content-Type: text/xml; charset=utf-8');
  echo $output;
}

