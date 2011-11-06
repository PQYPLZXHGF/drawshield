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


$message_list = array();

function draw_message( $category, $message, $filename = null, $line = null ) {
  global $message_list;

  if (! array_key_exists($category, $message_list)) $message_list[$category] = array();
	foreach ( $message_list[$category] as $item )
	  if ( $item['message'] == $message )
		  return; // ignore duplicate messages

  $message_list[$category][] = compact ( 'message', 'filename', 'line');
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
  global $message_list, $dom, $time_start;
  $yCount = 0;
  $retval = '';

  // First, gather any parser messages
  $parser_messages = $dom->documentElement->lastChild;
  if ( $parser_messages->nodeName == 'messages' ) {
    foreach ( $parser_messages->childNodes as $message )  {
      draw_message($message->getAttribute('category'), $message->firstChild->wholeText);
    }
  }
  draw_message('information', 'Blazon - ' . $dom->documentElement->getAttribute('blazonText'));

/*  $time_end = microtime(true);
  $time = $time_end - $time_start;
  draw_message('information', sprintf ( "Elapsed time %.4f seconds", $time) ); */


//  if ( count($message_list) < 1 ) return null;
  $notify = false;
  foreach ( $message_list as $key => $messages ) {
    switch ( $key ) {
      case 'warning':
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="orange" >Warnings:' . "</text>\n";
        $notify = true;
        break;
      case 'blazon':
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="red" >Blazon Problems:' . "</text>\n";
        $notify = true;
        break;
      case 'internal':
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="red" >Internal Errors:' . "</text>\n";
        $notify = true;
        break;
      case 'licence':
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="black" >Image Credits:' . "</text>\n";
        break;
      case 'information':
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="black" >Drawshield Information:' . "</text>\n";
        break;
      default:
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" text-decoration="underline" font-size="30" fill="black" >' . $key . "</text>\n";
        break;
    }
    foreach ( $messages as $message_item ) {
      $text = $message_item['message'];
      /* if ( $message_item['filename'] != null ) {
        $text .= " (${message_item['filename']}";
        if ( $message_item['line'] != null )
          $text .= ":${message_item['line']}";
        $text .= ')'; 
      }*/
      $formatted = format($text);
      foreach($formatted as $line) {
        $retval .= '<text x="10" y="' . ($yCount += 30) . '" font-size="30" fill="black" >' . htmlspecialchars($line) . "</text>\n";
      }
    }
  }
  $retval = '<g id="errorbox" visibility="hidden"><rect x="0" y="0" height="' . ($yCount+30) . '" width="1000" fill="rgb(255,255,255)" />' . $retval . '</g>';
  if ( $notify) $retval .= '<text onclick="showerrors(evt)" fill="red" text-anchor="end" x="990" y="1160" font-size="30">Error reported</text>';
  $retval .= '<text onclick="showerrors(evt)" fill="black" text-anchor="end" x="990" y="1190" font-size="30">Click for information</text>';
  return $retval;
}


function get_error_text() {
  global $message_list, $dom;
  $retval = '';

  // First, gather any parser messages
  $parser_messages = $dom->documentElement->lastChild;
  if ( $parser_messages->nodeName == 'messages' ) {
    foreach ( $parser_messages->childNodes as $message )  {
      draw_message($message->getAttribute('category'), $message->firstChild->wholeText);
    }
  }

  foreach ( $message_list as $key => $messages ) {
    foreach ( $messages as $message_item ) {
      $retval .= "$key: " . $message_item['message'] . "\n";
    }
  }
  return $retval;
}

?>