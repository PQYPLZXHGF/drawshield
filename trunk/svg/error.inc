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


$error_list = array();

function error_handler($error_num, $error_string, $filename, $line, $symbols = null) {
  global $error_list;
  foreach ( $error_list as $error_item ) {
    if ( $error_item['error_string'] == $error_string ) return;
  } // This is a new error
  $error_list[] = compact ( 'error_num', 'error_string', 'filename', 'line' );
  switch ( $error_num ) {
    case E_SVG:
    case E_PARSER:
    case E_USER_NOTICE:
    case E_USER_WARNING: // These are safe(ish), just continue
      break;
    default:
      fatal_error();
      restore_error_handler();
      die();
  } 
}

function format($string) {
  $lines = array();
  $line_count = 0;
  $length = 0;
  $lines[0] = '';

  $words = explode(' ',$string);
  foreach($words as $word) {
    $lines[$line_count] .= $word . ' ';
    $length += strlen($word) + 1;
    if ( $length > 65 ) {
      $line_count += 1;
      $lines[$line_count] = '';
      $length = 0;
    }
  }

  return $lines;
}

function get_error_messages() {
  global $error_list, $dom;
  $yCount = 30;
  $retval = '';

  $blazonNode = $dom->document_element();
  $parse_errors = $blazonNode->last_child();
  if ( $parse_errors->node_name() == 'errors' ) {
    $tokens = explode(' ', $blazonNode->get_attribute('blazonTokens'));
    foreach ( $parse_errors->child_nodes() as $parse_error )  {
      $tokNum = $parse_error->get_attribute('tokNum');
      $tok_string = ' - ';
      for ( $i = $tokNum; $i < $tokNum + 5 and $i < count($tokens); $i++ )
        $tok_string .= $tokens[$i] . ' ';
      if ( $i < count($tokens) ) $tok_string .= '...';
      my_trigger_error($parse_error->get_content() . $tok_string, E_PARSER);
    }
  }

  if ( count($error_list) < 1 ) return '';
  foreach ( $error_list as $error_item ) {
    $this_error = '';
    switch ( $error_item['error_num'] ) {
      case E_SVG:
        $this_error .= 'SVG PROBLEM - ' . $error_item['error_string'];
        break;
      case E_PARSER:
        $this_error .= 'Problem in Blazon - ' . $error_item['error_string'];
        break;
      case E_USER_WARNING:
        $this_error .= 'INTERNAL ERROR - ' . $error_item['error_string'];
        break;
      case E_USER_NOTICE:
        $this_error .= 'Problem in Blazon - ' . $error_item['error_string'];
        break;
      default:
        $this_error .= $error_item['error_string'] . ' ' . $error_item['filename'] . '(' . $error_item['line'] . ') ';
        break;
    }
    $formatted = format($this_error);
    foreach($formatted as $line) {
      $retval .= '<text x="10" y="' . ($yCount += 30) . '" font-size="30" fill="black" >' . $line . "</text>\n";
    }
  }
  $retval = '<g id="errorbox" visibility="hidden"><rect x="0" y="0" height="' . ($yCount+30) . '" width="1000" fill="rgb(255,255,255)" />' . $retval . '</g>';
  $retval .= '<text onclick="showerrors(evt)" fill="red" text-anchor="end" x="990" y="1160" font-size="30">Error reported</text>';
  $retval .= '<text onclick="showerrors(evt)" fill="red" text-anchor="end" x="990" y="1190" font-size="30">Click here for details</text>';
  return $retval;
}

function fatal_error() {
  global $error_list;
  foreach ( $error_list as $error_item ) {
    echo 'PROGRAM ERROR - ' . $error_item['error_string'] . ' in ' . $error_item['filename'] . ' at line: ' . $error_item['line'];
  }
  exit;
}

function my_trigger_error( $message, $number = E_USER_WARNING, $file = '(no file)', $line = '(no line)' ) {
  error_handler( $number, $message, $file, $line );
}
?>
