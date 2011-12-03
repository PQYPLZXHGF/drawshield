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

set_include_path('C:\Users\K Wilcox\Documents\Projects\website\www-new\include\shield');
   
function draw_message($category,$message) { echo $message; }
function get_mod ( $node, $name ) { return null; }
function rgb( $colour ) { return null; }

function include_charge () {
  $node = null;
  $charge = array();
  include_once func_get_arg(0);
  return $charge;
}

function include_ordinary () {
  $node = null;
  $ordinary = array();
  include_once func_get_arg(0);
  return $ordinary;
}

$node = null;

  $charges = array();
  $ordinaries = array();
  $either = array();
  // Go through charges
  $dir = opendir('../charges');
  echo "Building charges...\n";
  while ( ($subdir = readdir($dir)) != false ) {
    if ( $subdir{0} != '.' and is_dir('../charges/' . $subdir) ) {
      $ddir = opendir('../charges/' . $subdir );
      while ( ($file = readdir($ddir)) != false ) {
        if ( ($file{0} != '_') and substr($file,-4) == '.inc' ) {
        	$type = $subdir;
        	$subtype = substr($file,0,strlen($file)-4);
        	//echo "\r$subtype";
            $charge = include_charge ( '../charges/' . $subdir . '/' . $file );
            $def_col = array();
            // Add this to the either list, for disambiguation?
            if ( array_key_exists ( 'either', $charge ) ) {
              foreach ( $charge['patterns'] as $pattern )
                $either[] = array ( $subtype, $pattern, $type, 'charge');
            } else {
              foreach ( $charge['patterns'] as $pattern ) {
                $charges[] = array ( $subtype, $pattern, $type, 'charge');
              }
            }
        }
      }
    }
  }
  echo "\rcompleted\n";
  // Go through ordinaries
  echo "Building ordinaries...";
  $dir = opendir('../ordinaries');
  while ( ($subdir = readdir($dir)) != false ) {
    if ( $subdir{0} != '.' and is_dir('../ordinaries/' . $subdir) ) {
      $ddir = opendir('../ordinaries/' . $subdir );
      while ( ($file = readdir($ddir)) != false ) {
        if ( ($file{0} != '_') and substr($file,-4) == '.inc' ) {
        	$type = $subdir;
        	$subtype = substr($file,0,strlen($file)-4);
        	//echo "\r$subtype";
            $ordinary = include_ordinary ( '../ordinaries/' . $subdir . '/' . $file );
            // Add this to the either list, for disambiguation?
            if ( array_key_exists ( 'either', $ordinary ) ) {
              foreach ( $ordinary['patterns'] as $pattern ) {
                $found = false;
                for ( $i = 0; $i < count($either); $i++ ) {
                  if ( strcmp($either[$i][1], $pattern) === 0 ) {
                    $either[$i][3] = 'either';
                    $either[$i][0] .= ':' . $subtype;
                    $either[$i][2] .= ':' . $type;
                    $found = true;
                    break;
                  }
                }
                if ( !$found )
                  $either[] = array ( $subtype, $pattern, $type, 'ordinary' );
              }
            } else {
              foreach ( $ordinary['patterns'] as $pattern ) {
                $ordinaries[] = array ( $subtype, $pattern, $type );
              }
            }
        }
      }
    }
  }
  echo "\ncompleted\n";
  // Write out the data files
  echo "Writing files...";
  $fp = fopen('../parser/data/charge_list.dat','w');
  fwrite ( $fp, serialize($charges) );
  fclose ( $fp );
  unset ( $charges );
  $fp = fopen('../parser/data/ordinary_list.dat','w');
  fwrite ( $fp, serialize($ordinaries) );
  fclose($fp);
  unset ( $ordinaries );
  $fp = fopen('../parser/data/either_list.dat','w');
  fwrite ( $fp, serialize($either) );
  fclose($fp);
  unset ( $either );
  echo "completed\n";

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
