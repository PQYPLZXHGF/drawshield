<?php
// This is the global array, used by the parser to resolve back references
$p_globals = array (
  'offield' => null,
  'offirst' => null,
  'ofsecond' => null,
  'ofthird' => null,
  'offourth' => null,
  'ofsame' => null,
  'oflast' => null,
  'asmany' => null,
);

function parser_message($category, $string, $file = '', $line = '' ) {
  global $dom, $parser_messages;

  $message = $dom->createElement('message');
  $message->setAttribute( 'tokens',tokens());
  $message->setAttribute( 'category',$category);
  if ( $file ) $message->setAttribute('filename', $file);
  if ( $line ) $message->setAttribute('line', $line);
  $text = $dom->createTextNode($string);
  $message->appendChild($text);
  $parser_messages->appendChild($message);
}

function deep_copy($node) {
  global $dom;

  $newnode = $dom->createElement($node->tagName);
  foreach ($node->attributes as $attribute) {
    $newnode->setAttribute($attribute->name,$attribute->value);
  }
  foreach ($node->childNodes as $child) {
    $newnode->appendChild(deep_copy($child));
  }
  return $newnode;
}

function save() {
  global $cur_word;

  return $cur_word;
}

function restore($state) {
  global $cur_word;

  $cur_word = $state;
}

function next_word() { // return next token (or null)
  global $cur_word, $words;

  if ( $cur_word > count($words) ) return null;
  return $words[$cur_word++];
}

function get_tokens($num = 1) {
  global $cur_word, $words;

  if ( $num < 0 ) $num = 1;

  $retval = '';
  for ( $i = 0; $i < $num; $i++ )
    if ( ($token = next_word()) != null ) $retval .= $token . ' ';
  return (rtrim($retval));
}

function lookahead($inc = 1) {
  global $cur_word, $words;

  if ((($cur_word + $inc) > count($words)) or (($cur_word + $inc) < 0)) {
    return false;
  } else {
    $cur_word += $inc;
    return true;
  }
}

function andd() {
  $and_words = array (
    array ( true, '(and|&)' ),
  );

  if ( search_match($and_words) ) return true;
  return false;
}

function semicolon() {
  $semi = array (
    array ( true, ';'),
   );
  if ( search_match($semi) != null ) return true;
  $state = save();
  if ( lookahead(-1) && search_match($semi) != null ) return true;
  restore($state);
  return false;
}

function comma() {
  // Consume a comma (or similar) character if present, and return true
  // But also return true if the *previous* character was a comma
  $commas = array (
    array ( true, ',' ),
  );

  if ( search_match($commas) != null ) return true;
  $state = save();
  if ( lookahead(-1) && search_match($commas) != null ) return true;
  restore($state);
  return false;
}

function tokens() {
  global $matched_tokens;

  $retval = $matched_tokens;
  $matched_tokens = '';
  return $retval;
}

function unique($prefix = 'item') {
  static $uni_num = 0;

  $uni_num += 1;
  return "$prefix$uni_num";
}

function make_mod($name, $param = null, $tokens = null ) {
  global $dom;

  $mod = $dom->createElement('modifier');
  $mod->setAttribute('name', $name);
  if ( $param ) $mod->setAttribute('param', $param);
  if ( $tokens ) $mod->setAttribute('tokens', $tokens);
  $mod->setAttribute('tokens',tokens());
  return $mod;
}

function make_colour($colour) {
  global $dom;

  $tinc = $dom->createElement('tincture');
  $col = $dom->createElement('colour');
  $col->setAttribute('name',$colour);
  $tinc->appendChild($col);
  return $tinc;
}

function get_mod($node, $name) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->tagName == 'modifier' and $child->getAttribute('name') == $name ) {
      $retval = $child->getAttribute('param');
      if ( $retval == null ) $retval = true; // Just say the modifier exists
      return $retval;
    }
  }
  return null;
}

function get_child($node,$tagname) {
  $retval = null;
  foreach ( $node->childNodes as $child ) {
    if ( $child->tagName == $tagname ) {
      $retval = $child;
      break;
    }
  }
  return $retval;
}
?>
