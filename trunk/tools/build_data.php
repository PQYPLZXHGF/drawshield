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

function get_mod ( $node, $name ) { return null; }

function include_charge () {
  $node = null;
  $charge = array();
  include_once func_get_arg(0);
  return $charge;
}

$node = null;

  $charges = array();
  $modifiers = array();
  $either = array();
  // Read in the parsing code
    $dir = opendir('../charges');
    while ( ($subdir = readdir($dir)) != false ) {
      if ( $subdir{0} != '.' and is_dir('../charges/' . $subdir) ) {
        $ddir = opendir('../charges/' . $subdir );
        while ( ($file = readdir($ddir)) != false ) {
          if ( ($file{0} != '_') and substr($file,-4) == '.inc' ) {
          	$type = $subdir;
          	$subtype = substr($file,0,strlen($file)-4);
            $charge = include_charge ( '../charges/' . $subdir . '/' . $file );
            $either_type = array_key_exists ( 'either', $charge ) ? $charge['either'] : array();
            if ( count($either_type) > 0) {
              if ( isset($either_type[1]) ) {
                $type = $either_type[1] . ':' . $subdir;
                $category = 'either';
              } else {
                $category = 'charge';
              }
              foreach ( $charge['patterns'] as $pattern ) 
                $either[] = array ( $subtype, $pattern, $type, $category );
            } else {
              foreach ( $charge['patterns'] as $pattern ) {
              	if ( array_key_exists('default_colour', $charge ))
                  $charges[] = array ( $subtype, $pattern, $type, $charge['default_colour'] );
              else
                  $charges[] = array ( $subtype, $pattern, $type );
              }
            }
            if ( array_key_exists( 'modifiers' , $charge ) )
              $modifiers[$subtype] = $charge['modifiers'];
          }
        }
      }
    }
  $fp = fopen('../parser/charge_list.dat','w');
  fwrite ( $fp, serialize($charges) );
  fclose ( $fp );
  unset ( $charges );
  $fp = fopen('../parser/modifier_list.dat','w');
  fwrite ( $fp, serialize($modifiers) );
  fclose($fp);
  unset ( $modifiers );
  $fp = fopen('../parser/either_list.dat','w');
  fwrite ( $fp, serialize($either) );
  fclose($fp);
  unset ( $either );
  
 /* Fudge if web server can't write to folder, open in web browser
 header("Content-Transfer-Encoding: text");
 header('Content-Type: text/plain');
 echo "charge_list\n";
 echo serialize($charges) . "\n";
 echo "modifier_list\n";
 echo serialize($modifiers) . "\n";
 echo "either_list\n";
 echo serialize($either) . "\n";   */
?>
 