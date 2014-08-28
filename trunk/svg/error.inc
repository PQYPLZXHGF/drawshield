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
	  if ( strcmp ( $item['message'], $message ) === 0)
		  return; // ignore duplicate messages

  $message_list[$category][] = compact ( 'message', 'filename', 'line');
}

function get_error_messages(infobox $infobox) {
  global $message_list, $dom, $options;

  // First, gather any parser messages
  $parser_messages = $dom->documentElement->lastChild;
  if ( $parser_messages->nodeName == 'messages' ) {
    foreach ( $parser_messages->childNodes as $message )  {
      draw_message($message->getAttribute('category'), $message->firstChild->wholeText);
    }
  }

  $warnings = array();
  $errors = array();
  $credits = array();
  $other = array();
  $builtins = array();
  $notify = false;
  $links = array();
  foreach ( $message_list as $key => $messages ) {
    switch ( $key ) {
      case 'warning':
        foreach ( $messages as $message )
          $warnings[] = $message['message'];
        $notify = true;
        break;
      case 'blazon':
        foreach ( $messages as $message )
          $errors[] = $message['message'];
        $notify = true;
        break;
      case 'internal':
        foreach ( $messages as $message )
          $errors[] = '(Internal) ' . $message['message'];
        $notify = true;
        break;
      case 'licence':
        foreach ( $messages as $message )
          $credits[] = $message['message'];
        break;
      case 'builtin':
        foreach ( $messages as $message )
          $builtins[] = $message['message'];
        break;
      case 'link':
        foreach ( $messages as $message )
          $links[] = $message['message'];
        break;
      default:
        foreach ( $messages as $message )
          $other[] = $message['message'];
        break;
    }
  }
  $options['notify'] = $notify;
  $infobox->setTab(1,'Blazon');
  $infobox->addText(1,ucfirst($dom->documentElement->getAttribute('blazonText')));
  if (count($builtins)) {
    $infobox->addHeader(1,"Referenced Blazons:");
    foreach($builtins as $item) $infobox->addText(1,$item);
  }
  if (count($errors)) {
    $infobox->addHeader(1,'Errors:','red');
    foreach($errors as $item) $infobox->addText(1,$item);
  }
  if ( count($warnings)) {
    $infobox->addHeader(1,'Warnings:','orange');
    foreach($warnings as $item) $infobox->addText(1,$item);
  }
  if ( count($other)) {
    $infobox->addHeader(1,'Other Notices:','orange');
    foreach($other as $item) $infobox->addText(1,$item);
  }
  if ( count($credits)) {
    $infobox->addHeader(4,'Image Component Credits:');
    foreach($credits as $item) $infobox->addText(4,$item);
  }
  $infobox->setTab(2,'Links');
  foreach($links as $item) $infobox->addText(2,$item);

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
