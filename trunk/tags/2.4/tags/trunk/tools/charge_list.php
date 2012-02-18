<?php

$copyright = '/* Copyright 2011 Karl R. Wilcox 

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

echo "Processing...\n"; 

$data = fopen('charge_list.txt','r');

$type = null;
$subtype = null;
$patterns = array();
$docs = null;
$mods = array();

while ( !feof($data) ) {
  $line = trim(fgets($data));
  if ( strlen($line) == 0 and $type != null and $subtype != null and count($patterns) ) {
    $outfile = 'charges/' . $type . '/' . $subtype . '.inc';
    echo "Trying to create $outfile...\n";
    if ( !is_dir( 'charges/' . $type ) ) mkdir ( 'charges/' . $type );
    if ( file_exists ( $outfile )) {
      echo "$outfile already exists\n";
      $patterns = array();
      $type = null;
      $subtype = null;
      $mods = array();
      $docs = null;
      continue;
    } else {
      if ( ($out = fopen($outfile,"w")) == false ) exit;
      // header
      fwrite ( $out, '<?php ' . $copyright );
      fwrite ( $out, "\n// $subtype\n" );
      // Patterns
      fwrite ( $out, "\n\$charge = array (\n 'patterns' => array (\n" );
      foreach ( $patterns as $pattern ) fwrite ( $out, "    '$pattern',\n" );
      fwrite ( $out, "  ),\n" );
      $patterns = array();
      // Modifiers
      if ( count($mods)) {
        fwrite ( $out, "\n  'modifiers' => array (\n" );
        foreach ( $mods as $mod ) fwrite($out, "    array ( $mod ),\n" );
        fwrite ( $out, "  ),\n" );
        $mods = array();
      }
      // Documentation
      if ( $docs ) fwrite ( $out, "  'doc' => \"$docs\",\n" );
      // Footer
      fwrite ( $out, ");\n?>\n" );
      // Reset all
      fclose($out);
      $type = null;
      $subtype = null;
      $docs = null;
    }
    continue;
  } // else
  switch ( $line{0} ) {
    case 't':
      $type = substr($line,2);
      break;
    case 's':
      $subtype = substr($line,2);
      break;
    case 'd':
      $docs = substr($line,2);
      break;
    case 'p':
      $patterns[] = substr($line,2);
      break;
    case 'm':
      $mods[] = substr($line,2);
  }
}
echo "Finished\n";
?>