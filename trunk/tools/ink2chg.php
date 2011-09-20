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

function get_item($item) {
  switch ($item->getName()) {
    case 'path':
      return get_path($item);
      break;
    case 'rect':
      return get_rect($item);
      break;
    default:
      echo 'WARNING: unrecognised element - ' . $item->getName();
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
        if ( $value != '1' ) $retval .= 'fill-opacity="' . $value . '" ';
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

function get_path($path) {
  $retval = '<path ';
  $retval .= split_style( $path['style']);
  $retval .= 'd="' . $path['d'] . "\" />\n";
  return $retval;
}

function ink2php($filename) {

  $header = '<?php /* Copyright 2011 Karl R. Wilcox

     Licensed under the Apache License, Version 2.0 (the "License");
     you may not use this file except in compliance with the License.
     You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

     Unless required by applicable law or agreed to in writing, software
     distributed under the License is distributed on an "AS IS" BASIS,
     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
     See the License for the specific language governing permissions and
     limitations under the License. */';

  $body = "'<g/>'";
  $features = array();
  $modifiers = array();
  if ( ($xml = simplexml_load_file($filename)) == null ) return null;
  $groups = $xml->g;
  if ( substr($groups[0]['id'],1,4) == 'ayer' )
    $groups = $groups[0];
  else
    $groups = $xml;
  foreach ( $groups->g as $group ) {
  	if ( $group['id'] == 'body' ) {
  	  $body = "    'body' => '\n";
  	  foreach ( $group->children() as $child ) {
  		$body .= "      " . get_item($child);
  	  }
  	  $body .= "      ',\n";
  	} else {
  	  $temp = "      '" . $group['id'] . "' => array (\n        'body' => '\n";
  	  foreach ( $group->children() as $child ) {
  		$temp .= "      " . get_item($child);
  	  }
  	  $temp .= "      '),\n";
  	  $features[] = $temp;
  	  $modifiers[] = $group['id'];
  	}
  }
  $f = '';
  $f .=  $header . "\n\n";
  $f .= "\$charge = array ( \n";
  $f .= "  'patterns' => array (\n  'PATTERN',\n  ),\n";
  if ( count($modifiers) > 0 ) {
    $f .= "\n  'modifiers' => array (\n";
    foreach ($modifiers as $mod) {
      $f .= "    array ( '$mod', '$mod', 'feature' ),\n";
    }
    $f .= "   ),\n";
  }
  $f .= "\n  'height' => " . $xml['height'] . ", 'width' => " . $xml['width'] . ",\n";
  $f .= $body;
  if ( count($features) > 0 ) {
    $f .= "    'features' => array (\n";
    foreach ($features as $feature) {
      $f .= "      $feature";
    }
    $f .= "      ),\n";
  }
  $f .= "  );\n?>\n";
  return $f;
}


/*
header("Content-Transfer-Encoding: text");
header('Content-Type: text/plain');
$output = null;
if ( is_uploaded_file($_FILES['inksvg']['tmp_name']) ) {
  $output = ink2php($_FILES['inksvg']['tmp_name']);
}
if ( $output == null )
  echo 'no valid SVG found';
else {
  echo $output;
}  */

$filename = $argv[1];
for ( $i = 2; $i < $argc; $i++ ) $filename .= ' ' . $argv[$i];
echo ink2php($filename);
exit();
?>
