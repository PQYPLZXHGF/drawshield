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

  $newnode = $dom->createElement($node->nodeName);
  foreach ($node->attributes as $attribute) {
    $newnode->setAttribute($attribute->name,$attribute->value);
  }
  foreach ($node->childNodes as $child) {
    $newnode->appendChild(deep_copy($child));
  }
  return $newnode;
}

function copy_children(&$fromNode, &$toNode) {
  $fromNode_childNodes = $fromNode->childNodes;
  $length = $fromNode_childNodes->length;
  $fromChildren_array = array();
 
  for($i = 0; $i < $length; $i++)
    $fromChildren_array[] = $fromNode_childNodes->item($i);
 
  foreach($fromChildren_array as $old_c)
     $toNode->appendChild($old_c);
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

function make_colour($colour, $index='1') {
  global $dom;

  $tinc = $dom->createElement('tincture');
  $col = $dom->createElement('colour');
  $col->setAttribute('name',$colour);
  $tinc->setAttribute('index',$index);
  $tinc->appendChild($col);
  return $tinc;
}

function get_mod($node, $name) {
  if ( $node == null ) return null;
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'modifier' and $child->getAttribute('name') == $name ) {
      $retval = $child->getAttribute('param');
      if ( $retval == null ) $retval = true; // Just say the modifier exists
      return $retval;
    }
  }
  return null;
}

function get_mods($node, $name) {
  $retval = array();
  if ( $node == null ) return null;
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'modifier' and $child->getAttribute('name') == $name ) {
      $val = $child->getAttribute('param');
      if ( $val == null ) $val = true; // Just say the modifier exists
      $retval[] = $val;
    }
  }
  return $retval;
}

function get_mod_node($node, $name) {
  if ( $node == null ) return null;
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'modifier' and $child->getAttribute('name') == $name ) {
      return $child;
    }
  }
  return null;
}


function get_child($node,$nodeName) {
  $retval = null;
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == $nodeName ) {
      $retval = $child;
      break;
    }
  }
  return $retval;
}

function get_rgb($tinc_node) {
	$col = $tinc_node->firstChild;
	if ( !$col or $col->nodeName != 'colour' ) {
	  draw_message('warning','plain colour expected');
	  return ( '#555555' );
	} // So now we have a colour node
	return rgb($col->getAttribute('name'));
}

function get_tincture($node,$index=null) {
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'tincture' ) {
		  if ( !$index ) return $child;
			if ( $child->getAttribute('index') == $index ) {
			  return $child;
			}
    }
  }
  return null; // TODO should this return missing node?
}

function rgb($name) {

  static $colours = array (
  // basic tinctures (with abbreviations
   'or' => '#EFD807',
   'azure' => '#1E7FCB'   ,
   'vert' => '#149414' ,
   'gules' => '#E21313'    ,
   'argent' => '#F0F0F0'  ,
   'sable' => '#050505' ,
   'purpure' => '#965578' ,
  // additional tinctures
   'murrey' => '#8C004B'  ,
   'sanguine' => '#850606'  ,
   'carnation' => '#FEC3AC' ,
   'brunatre' => '#7E0001' ,
   'cendree' => '#848484'  ,
   'rose' => '#FF006E' ,
   'bis' => '#F1E2BE' ,
   'celestial-azure' => '#96C8F9' ,
   'senois' => '#8D4024' ,
   'tanned' => '#A75502' ,
   'tenne' => '#A75502' ,
   'orange' => '#FAA401' ,
  // "de" names (for gouttes particularly
   'd-eau' =>  '#F0F0F0',
   'de-larmes' =>  '#1E7FCB',
   'de-sangue' => '#E21313',
   'de-vin' => '#965578',
   'de-poix' =>  '#050505',
   'd-huile' => '#149414',
  // Special value used in masks
   'mask' => '#FFFFFF' ,
  // Named web colors
   'alice blue' => '#f0f8ff',
   'antique white' => '#faebd7',
   'aqua' => '#00ffff',
   'aquamarine' => '#7fffd4',
//   '#f0ffff,'azure',
   'beige' => '#f5f5dc',
//   'bisque' => '#ffe4c4',
   'black' => '#000000',
   'blanched almond' => '#ffebcd',
   'blue' => '#0000ff',
   'blue violet' => '#8a2be2',
   'brown' => '#a52a2a',
   'burly wood' => '#deb887',
   'cadet blue' => '#5f9ea0',
   'chartreuse' => '#7fff00',
   'chocolate' => '#d2691e',
   'coral' => '#ff7f50',
   'cornflower blue' => '#6495ed',
   'cornsilk' => '#fff8dc',
   'crimson' => '#dc143c',
   'cyan' => '#00ffff',
   'dark blue' => '#00008b',
   'dark cyan' => '#008b8b',
   'dark goldenrod' => '#b8860b',
   'dark gray' => '#a9a9a9',
   'dark green' => '#006400',
   'dark khaki' => '#bdb76b',
   'dark magenta' => '#8b008b',
   'dark olive green' => '#556b2f',
   'dark orange' => '#ff8c00',
   'dark orchid' => '#9932cc',
   'dark red' => '#8b0000',
   'dark salmon' => '#e9967a',
   'dark sea green' => '#8fbc8f',
   'dark slate blue' => '#483d8b',
   'dark slate gray' => '#2f4f4f',
   'dark turquoise' => '#00ced1',
   'dark violet' => '#9400d3',
   'deep pink' => '#ff1493',
   'deep sky blue' => '#00bfff',
   'dim gray' => '#696969',
   'dodger blue' => '#1e90ff',
   'fire brick' => '#b22222',
   'floral white' => '#fffaf0',
   'forest green' => '#228b22',
   'fuchsia' => '#ff00ff',
   'gainsboro' => '#dcdcdc',
   'ghost white' => '#f8f8ff',
   'gold' => '#ffd700',
   'goldenrod' => '#daa520',
   'gray' => '#808080',
   'green' => '#008000',
   'green yellow' => '#adff2f',
   'honeydew' => '#f0fff0',
   'hot pink' => '#ff69b4',
   'indian red' => '#cd5c5c',
   'indigo' => '#4b0082',
   'ivory' => '#fffff0',
   'khaki' => '#f0e68c',
   'lavender' => '#e6e6fa',
   'lavender blush' => '#fff0f5',
   'lawn green' => '#7cfc00',
   'lemon chiffon' => '#fffacd',
   'light blue' => '#add8e6',
   'light coral' => '#f08080',
   'light cyan' => '#e0ffff',
   'light goldenrod yellow' => '#fafad2',
   'light gray' => '#d3d3d3',
   'light green' => '#90ee90',
   'light pink' => '#ffb6c1',
   'light salmon' => '#ffa07a',
   'light sea green' => '#20b2aa',
   'light sky blue' => '#87cefa',
   'light slate gray' => '#778899',
   'light steel blue' => '#b0c4de',
   'light yellow' => '#ffffe0',
   'lime' => '#00ff00',
   'lime green' => '#32cd32',
   'linen' => '#faf0e6',
   'magenta' => '#ff00ff',
   'maroon' => '#800000',
   'medium aquamarine' => '#66cdaa',
   'medium blue' => '#0000cd',
   'medium orchid' => '#ba55d3',
   'medium purple' => '#9370d8',
   'medium sea green' => '#3cb371',
   'medium slate blue' => '#7b68ee',
   'medium spring green' => '#00fa9a',
   'medium turquoise' => '#48d1cc',
   'medium violet red' => '#c71585',
   'midnight blue' => '#191970',
   'mint cream' => '#f5fffa',
   'misty rose' => '#ffe4e1',
   'moccasin' => '#ffe4b5',
   'navajo white' => '#ffdead',
   'navy' => '#000080',
   'old lace' => '#fdf5e6',
   'olive' => '#808000',
   'olive drab' => '#6b8e23',
//   'orange' => '#ffa500',
   'orange red' => '#ff4500',
   'orchid' => '#da70d6',
   'pale goldenrod' => '#eee8aa',
   'pale green' => '#98fb98',
   'pale turquoise' => '#afeeee',
   'pale violet red' => '#d87093',
   'papaya whip' => '#ffefd5',
   'peach puff' => '#ffdab9',
   'peru' => '#cd853f',
   'pink' => '#ffc0cb',
   'plum' => '#dda0dd',
   'powder blue' => '#b0e0e6',
   'purple' => '#800080',
   'red' => '#ff0000',
   'rosy brown' => '#bc8f8f',
   'royal blue' => '#4169e1',
   'saddle brown' => '#8b4513',
   'salmon' => '#fa8072',
   'sandy brown' => '#f4a460',
   'sea green' => '#2e8b57',
   'sea shell' => '#fff5ee',
   'sienna' => '#a0522d',
   'silver' => '#c0c0c0',
   'sky blue' => '#87ceeb',
   'slate blue' => '#6a5acd',
   'slate gray' => '#708090',
   'snow' => '#fffafa',
   'spring green' => '#00ff7f',
   'steel blue' => '#4682b4',
   'tan' => '#d2b48c',
   'teal' => '#008080',
   'thistle' => '#d8bfd8',
   'tomato' => '#ff6347',
   'turquoise' => '#40e0d0',
   'violet' => '#ee82ee',
   'wheat' => '#f5deb3',
   'white' => '#ffffff',
   'white smoke' => '#f5f5f5',
   'yellow' => '#ffff00',
   'yellow green' => '#9acd32',
  );
  if ( array_key_exists($name,$colours) ) return $colours[$name];
  draw_message('internal', "unknown colour - $name" );
  return '#888888';
}
?>
