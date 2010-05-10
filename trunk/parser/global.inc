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

function deep_copy($node) {
  global $dom;

  $newnode = $dom->create_element($node->tagname());
  foreach ($node->attributes() as $attribute) {
    $newnode->set_attribute($attribute->name,$attribute->value);
  }
  foreach ($node->child_nodes() as $child) {
    $newnode->append_child(deep_copy($child));
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

function tokNum() {
  global $cur_word;

  return $cur_word;
}

function unique($prefix = 'item') {
  static $uni_num = 0;

  $uni_num += 1;
  return "$prefix$uni_num";
}

function make_mod($name, $param = null) {
  global $dom;

  $mod = $dom->create_element('modifier');
  $mod->set_attribute('name', $name);
  if ( $param ) $mod->set_attribute('param', $param);
  $mod->set_attribute('tokNum',tokNum());
  return $mod;
}

function get_mod($node, $name) {
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->tagname() == 'modifier' and $child->get_attribute('name') == $name ) return $child->get_attribute('param');
  }
  return null;
}

function get_child($node,$tagname) {
  $retval = null;
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->tagname() == $tagname ) {
      $retval = $child;
      break;
    }
  }
  return $retval;
}
?>
