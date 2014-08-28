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


function splitStyle ( $styles ) {
  $retval = '';
  $styles = explode(';', $styles . ';');
  foreach ($styles as $style) {
    if ( $style == null ) continue;
    list($setting,$value) = explode(':',$style);
    switch($setting) {
      case 'fill': // Any of the "primary" colours are just placeholders, to be replaced by the charge colour
        if ( !in_array( $value, array ( '#ff0000', '#00ff00', '#0000ff', '#ffff00')) ) $retval .= 'fill="' . $value . '" ';
        break; // any other colour is left as it is
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


function rewriteAttributes($attributes, $class = '') {
  $retval = '';
  $myId = '';
  foreach ($attributes as $key => $data ) {
    switch ($key) {
      case 'id':
        $myId = $data;
        // $retval .= " id=\"$data\" ";  // remove IDs as they will not be unique
        break;
      case 'class':
        $class .= " $data ";
        break;
      case 'style':
        $retval .= splitStyle( $data );
        break;
      case 'fill': // Any of the "primary" colours are just placeholders, so we ignore them (will be replaced by the charge colour)
        if ( !in_array( strtolower($data), array ( '#ff0000', '#00ff00', '#0000ff', '#ffff00', '#ff00ff', '#00ffff')) )
          $retval .= ' fill="' . $data . '" ';
        break; // any other colour is left as it is
      case 'stroke':
        if ( $data == '#000000' ) $data = 'inherit';
        $retval .= ' stroke="' . $data . '" ';
        break;
      case 'transform':
        draw_message('internal',"Transform in element $myId " );
        break;
      default:
        if (( strpos($key,'sodipodi:') === false ) and (strpos($key,'inkscape:') === false ))
          $retval .= $key . '="' . $data . '" ';
        break;
    }
  }
  if ( $class != '' ) $retval .= ' class="' . trim($class) . '" ';
  return $retval;
}

function addChild(SimpleXMLElement $element, $featureColours) {
  $name = $element->getName();
  if ( in_array($name, array( 'metadata', 'defs' ) ))
    return null;
  if (( strpos($name,'sodipodi:') !== false ) or (strpos($name,'inkscape:') !== false ))
    return null;
  $id = isset($element['id']) ? (string)$element['id'] : null;
  $class = '';
  $item = "<$name ";
  if ( $id != null and array_key_exists($id,$featureColours) ) { // this is a feature with a given colour
    $class = "feature $id";
    $item .= ' fill="' . $featureColours[$id] . '" ';
  }
  $item .= rewriteAttributes($element->attributes(), $class);
  $subitem = '';
  foreach( $element->children() as $child )
      $subitem .= addChild($child,$featureColours);
  if ( $subitem != '') {
    $item .= ">$subitem</$name>\n";
  } else {
    $item .= "/>\n";
  }
  return $item;
}

function getSvgFragment ($svgCode, $featureTinctures) {
  $retval = array();

  if ( ($svg = simplexml_load_string($svgCode)) == null ) {
    draw_message('internal',"XML error reading charge data");
    return null;
  }
  $retval['height'] = floatval($svg['height']);
  $retval['width'] = floatval($svg['width']);
  $retval['licence'] = '(not known)';
  @$metadata = $svg->xpath('//cc:Agent/dc:title');
  if ( is_array($metadata) and count($metadata) > 0) {
    $retval['licence'] = $metadata[0];
  }
  $fragment = '';
  foreach( $svg->children() as $child )
    $fragment .= addChild($child, $featureTinctures);
  // Set the global stroke colour
  $fragment = '<g stroke="' . rgb('charge-stroke') . '">' . $fragment . '</g>';
  $retval['body'] = $fragment;
  return $retval;
}
