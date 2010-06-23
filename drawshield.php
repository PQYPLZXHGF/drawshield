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

// Set default values for arguments
$blazon = '';
$asFile = false;
$asText = false;
$size = 500;
$format = 'svg';
// Process arguments
if (isset($_GET['blazon'])) $blazon = strip_tags ($_GET['blazon']);
if (isset($_GET['format'])) $format = strip_tags ($_GET['format']);;
if (isset($_GET['asfile'])) $asFile = true; 
if (isset($_GET['size'])) {
  $size = strip_tags ($_GET['size']);  
  if ( $size < 100 ) $size = 100;
}
if ( $format != 'svg' ) $asText = true;
if ( $format == 'svgtext' ) $format = 'svg';

//
// Global Variables
//

$tagline1 = "drawshield 2.2a3";   // Advertising lines at bottom right
$tagline2 = "shield.karlwilcox.com";

// This is the list of words in the blazon, and the current parsing position
$words = array();
$cur_word = 0;

// This is our XML generator and top level item for the parse tree
$dom = domxml_new_doc('1.0');

// Read in the parsing code
$dir = opendir('parser');
while ( ($file = readdir($dir)) != false ) {
  if ( substr($file,-4) == '.inc' ) require 'parser/' . $file;
}

fill_words();

$errors = $dom->create_element('errors');
$node = $dom->create_element('blazon');
$node->set_attribute("blazonText", $blazon);
$node->set_attribute("blazonTokens", implode(' ',$words));
$node->append_child(shield());
if ( $cur_word < count($words) ) raise_error ( 'Do not understand after');
if ( $errors->has_child_nodes() ) $node->append_child($errors);
$dom->append_child($node);

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
