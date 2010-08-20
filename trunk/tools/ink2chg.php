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

function get_path($path) {
  $retval = '<path ';
  $styles = explode(';', $path['style']);
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
        $retval .= 'stroke-width="' . $value . '" ';
        break;
      case 'stroke':
        $retval .= 'stroke="' . $value . '" ';
        break;
    }
  }
  $retval .= 'd="' . $path['d'] . "\" />\n";  
  return $retval;
}

$header = '<?php /* Copyright 2010 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */';

$body = '<g/>';
$features = array();
$modifiers = array();
$xml = simplexml_load_file('input.svg');
foreach ( $xml->g as $group ) {
	if ( $group['id'] == 'body' ) {
	  $body = "    'body' => '\n";
	  foreach ( $group->path as $path ) {
		$body .= "      " . get_path($path);
	  }
	  $body .= "      ',\n";
	} else {
	  $temp = "      '" . $group['id'] . "' => '\n";
	  foreach ( $group->path as $path ) {
	    $temp .= "        " . get_path($path);
	  }
	  $temp .= "      ',\n";
	  $features[] = $temp;
	  $modifiers[] = $group['id'];
	}
}
$f = fopen('charge.php','w');
fwrite($f, $header . "\n\n");
fwrite($f, "\$charge = array ( \n" );
fwrite($f, "  'patterns' => array (\n  'PATTERN',\n  ),\n" );
if ( count($modifiers) > 0 ) {
  fwrite($f, "\n  'modifiers' => array (\n" );
  foreach ($modifiers as $mod) {
    fwrite($f, "    array ( '$mod', '$mod', 'feature' ),\n" );
  }
  fwrite($f, "   ),\n" );
}
fwrite($f, "\n  'height' => \"" . $xml['height'] . "\", 'width' => \"" . $xml['width'] . "\",\n" );
fwrite ($f, $body );
if ( count($features) > 0 ) {
  fwrite ( $f, "    'features' => array (\n" );
  foreach ($features as $feature) {
    fwrite ($f, $feature);
  }
  fwrite($f, "      ),\n" );
}
fwrite ( $f, "  );\n?>\n" );
fclose ( $f);

?>
 