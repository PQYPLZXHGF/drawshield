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

$groupXTrans = 0;
$groupYTrans = 0;

function get_item($item) {
  switch ($item->getName()) {
    case 'path':
      return get_path($item);
      break;
    case 'rect':
      return get_rect($item);
      break;
    default:
      draw_message('INTERNAL', 'inkscape: element not handled - ' . $item->getName());
      break;
  }
}

function split_style ( $styles ) {
  $retval = '';
  $styles = explode(';', $styles);
  foreach ($styles as $style) {
    list($setting,$value) = explode(':',$style);
    switch($setting) {
      case 'fill':
        if ( $value != '#ff0000' and $value != '#00ff00' and $value != '#0000ff' ) $retval .= 'fill="' . $value . '" ';
        break;
      case 'fill-opacity':
      case 'opacity':
        if ( $value != '1' ) $retval .= $setting . '="' . $value . '" ';
        break;
      case 'stroke-width':
      case 'fill-rule':
        $retval .= $setting . '="' . $value . '" ';
        break;
      case 'stroke':
        if ( $value == '#000000' ) $value = 'inherit';
        $retval .= 'stroke="' . $value . '" ';
        break;
    }
  }
  return $retval;
}

function get_rect($rect) {
  $retval = '<rect ';
  $retval .= split_style($rect['style']);
  $retval .= 'width="' . $rect['width'] . '" ';
  $retval .= 'height="' . $rect['height'] . '" ';
  $retval .= 'x="' . $rect['x'] . '" ';
  $retval .= 'y="' . $rect['y'] . '" ';
  $retval .= " />\n";
  return $retval;
}

function get_transform ( $transform ) {
  global $groupXTrans, $groupYTrans;
  
  if ( !$transform ) return array(0,0);
  preg_match('/translate *\(([\d\.-]+),([\d\.-]+)\)/', $transform, $match );
  return array ( ($match[1] + $groupXTrans), ($match[2] + $groupYTrans) );
}

function get_path($path) {
  $retval = '<path ';
  list($xTrans,$yTrans) = get_transform( $path['transform'] );
  $retval .= split_style( $path['style']);
  $retval .= 'd="' . (translatePath($path['d'], $xTrans, $yTrans)) . "\" />\n";
  return $retval;
}

function ink2chg($filename) {
  global $groupXTrans, $groupYTrans;

  $groupXTrans = 0;
  $groupYTrans = 0;
  $body = '';
  $features = array();
  if ( ($xml = simplexml_load_file($filename)) == null ) return null;
  $groups = $xml->g;
  if ( substr($groups[0]['id'],1,4) == 'ayer' )
    $groups = $groups[0];
  else
    $groups = $xml;
  foreach ( $groups->g as $group ) {
    list($groupXTrans, $groupYTrans) = get_transform($group['transform']);
  	if ( $group['id'] == 'body' or $group['id'] == 'layer1') {
  	  foreach ( $group->children() as $child ) {
  		  $body .= "      " . get_item($child);
  	  }
  	} else {
  	  foreach ( $group->children() as $child ) {
  		  $temp .= "      " . get_item($child);
  	  }
  	  $features[$group['id']] = array('body'=> $temp);
  	}
  }
  //$f .= "\n  'height' => " . $xml['height'] . ", 'width' => " . $xml['width'] . ",\n";
  if (count($features) > 0)
    return array('body' => $body, 'features' => $features );
  else
    return array('body' => $body);
}


?>
