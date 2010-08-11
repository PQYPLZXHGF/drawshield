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

  define('CHARGE_DATA', '../parser/charge_data' );
  define('SUBTYPE_FEATURES', '../parser/subtype_features' );
  define('TYPE_FEATURES', '../parser/type_features' );


  //    require_once '../parser/charge_data.inc';
  $charges = array();
      require_once '../parser/subtype_features.inc';
      require_once '../parser/type_features.inc';
      require_once '../parser/either_data.inc';
  // Read in the parsing code
    $PARSER = true;
    $dir = opendir('../charges');
    while ( ($subdir = readdir($dir)) != false ) {
      if ( $subdir{0} != '.' and is_dir('../charges/' . $subdir) ) {
        $ddir = opendir('../charges/' . $subdir );
        while ( ($file = readdir($ddir)) != false ) {
          if ( substr( '../charges/' . $subdir . '/' . $file,-4) == '.inc' ) {
            $patterns = array();
            $features = array();
            $either_type = array();
            include_once '../charges/' . $subdir . '/' . $file;
            if ( count($either_type) > 0) {
              if ( $either_type[1] )
                $type_spec = $either_type[1] . ':/' . $subdir;
              else
                $type_spec = $subdir;
              foreach ( $patterns as $pattern ) 
                $either[] = array ( $file, $pattern, $type_spec, $either_type[0] );
            } else {
              foreach ( $patterns as $pattern ) 
                $charges[] = array ( $file, $pattern, '/' . $subdir );
            }
            if ( count($features) > 0 )
              $subtypes[$file] = $features;
          }
        }
      }
    }
    unset ($PARSER);
  $fp = fopen('../parser/charge_data.dat','w');
  fwrite ( $fp, serialize($charges) );
  fclose ( $fp );
  unset ( $charges );
  $fp = fopen('../parser/type_features.dat','w');
  fwrite ( $fp, serialize($types) );
  fclose($fp);
  unset ( $types );
  $fp = fopen('../parser/subtype_features.dat','w');
  fwrite ( $fp, serialize($subtypes) );
  fclose($fp);
  unset ( $subtypes );
  $fp = fopen('../parser/either_data.dat','w');
  fwrite ( $fp, serialize($either) );
  fclose($fp);
  unset ( $either );
  
?>
