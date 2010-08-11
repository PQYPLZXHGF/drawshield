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

function my_trigger_error( $string ) {
  trigger_error('internal');
}

$first = '<?php /* Copyright 2010 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */
';
$last = "?>\n";
  require_once('../domxml.inc');

      require_once '../parser/charge_data.inc';
      require_once '../parser/subtype_features.inc';
      require_once '../parser/type_features.inc';
      require_once '../parser/either_data.inc';
$dom = domxml_new_doc('1.0');
$node = $dom->create_element('charge');
$node->set_attribute('number', '1' );
foreach ( $charges as $charge ) {
   $type = $charge[2];
   $subtype = $charge[0];
   $pattern = $charge[1];
   trigger_error($subtype);
   $node->set_attribute('type', $type );
   $node->set_attribute('subtype', $subtype );
   $patterns = explode('/',$pattern);
   $chg_func = 'makeChg_' . $type;
   include_once ( '../svg/charges/' . $type . '.inc' );
   $charge_data = $chg_func($node);
   $charge_array = var_export($charge_data, true);
   if ( !is_dir (  '../charges/' . $type ) ) mkdir ( '../charges/' . $type );
   $fp = fopen( '../charges/' . $type . '/' . $subtype . '.inc', 'w' );
   fwrite ( $fp, $first );
   fwrite ( $fp, "\nif ( isset ( \$PARSER ) ) { \n  \$patterns = array (\n" );
   foreach ($patterns as $pat)
     fwrite ( $fp, '  ' . var_export($pat,true) . ",\n");
   fwrite ( $fp, "  );\n" );
   if ( array_key_exists($subtype, $subtypes) ) 
     fwrite ( $fp, '  $features = ' . var_export($subtypes[$subtype],true)); // This needs more work!
   fwrite ( $fp, "\n\$docs = 'Stuff...';\n\n" );
   fwrite ( $fp, "}\n" );
   fwrite ( $fp, "\nif ( isset(\$SVG) ) {\n" );
   fwrite ( $fp, '  function charge_' . preg_replace('/-/', '_', $subtype ) . "() {\n    return " );
   fwrite ( $fp, $charge_array );
   fwrite ( $fp, ";\n}\n\n}\n");
   fwrite ( $fp, $last );
   fclose($fp);
 }
  
?>
