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
if (! ( gethostname() == 'Home-Laptop' or isset($_GET['execute']) ) ) {
	echo "You can't play here\n";
	exit;
}

set_include_path('..');
$target_dir = '../parser/data/';
   
function draw_message($category,$message) { echo $message; }
function get_mod ( $node, $name ) { return null; }
function rgb( $colour ) { return $colour; }

function get_main_name($patterns) {
  $pattern = $patterns[0];
  $words = explode(' ',$pattern);
  $retval = '';
  foreach ( $words as $word ) {
    if ( $word{0} == '?' ) continue;
    $word = preg_replace('/s\?/','',$word);
    $word = preg_replace('/\?/','',$word);
    $word = preg_replace('/\|.*?\)/',')',$word);
    $word = preg_replace('/\((.*?)\)/','\1',$word);
    $retval .= $word . ' ';
  }
  $retval = trim($retval);
  return $retval;
}

function get_alt_names($patterns, $main = '') {
  $names = array();
  foreach ($patterns as $pattern) {
    $cur_names = array ( '' );
    $words = explode ( ' ', $pattern );
    foreach ( $words as $word ) {
      $word = preg_replace('/s\?/','',$word);
      $word = preg_replace('/\?/','',$word);
      $cur_words = array ( '' );
      $in_brackets = false;
      $temp = '';
      for ( $i = 0; $i < strlen($word); $i++ ) {
        if ( $word{$i} == '(' ) {
          $in_brackets = true;
          $i++;
        }
        elseif ( $word{$i} == ')' ) {
          $alts = explode('|',$temp);
          $orig_num_words = count($cur_words);
          for ( $k = 1; $k < count($alts); $k++ ) {
            for ( $j = 0; $j < $orig_num_words; $j++ )
              $cur_words[] .= $cur_words[0] .  $alts[$k];
          }
          for ( $j = 0; $j < $orig_num_words; $j++ )
            $cur_words[$j] .= $alts[0];
          $temp = '';
          $in_brackets = false;
          $i++;
        }
        if ( $in_brackets )
          $temp .= $word{$i};
        elseif ( $i < strlen($word))
          for ( $j = 0; $j < count($cur_words); $j++ )
            $cur_words[$j] .= $word{$i};
      }
      $orig_num_names = count($cur_names);
      for ( $i = 1; $i < count($cur_words); $i++ )
        for ( $j = 0; $j < $orig_num_names; $j++ )
          $cur_names[] = $cur_names[0] . ' ' . $cur_words[$i];
      for ( $i = 0; $i < $orig_num_names; $i++ )
        $cur_names[$i] .= ' ' . $cur_words[0];
    }
    $names = array_merge($names, $cur_names);
  }
  for ( $i = 0; $i < count($names); $i++ ) {
    $names[$i] = trim($names[$i]);
    if ( $names[$i] == $main ) {
      $names[$i] = '';
      continue;
    }
  }
  return $names;
}


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
  $chargeList = '"Names","Type","Features","Modifiers","Ignored","Proper","Flags","SVG","Filename"' . "\n";
  // Go through charges
  $dir = opendir('../charges');
  echo "Building charges...\n";
  while ( ($subdir = readdir($dir)) != false ) {
    if ( $subdir{0} != '.' and is_dir('../charges/' . $subdir) ) {
      $ddir = opendir('../charges/' . $subdir );
      while ( ($file = readdir($ddir)) != false ) {
        // Set up charge list items
        $features = '';
        $mods = '';
        $ignored = '';
        $proper = '';
        $flags = '';
        $source = 'none';
        $name = '';
        // Go through each item
        if ( ($file{0} != '_') and substr($file,-4) == '.inc' ) {
        	$type = $subdir;
        	$subtype = substr($file,0,strlen($file)-4);
        	//echo "\r$subtype";
          $charge = include_charge ( '../charges/' . $subdir . '/' . $file );
          if ( array_key_exists('file',$charge) and ! file_exists('../charges/' . $type . '/' . $charge['file']))
            echo "Warning: file " .  $charge['file'] . " not found\n";
          // Gather data for charge list
          foreach ( $charge as $item => $data ) {
            switch ($item) {
            case 'modifiers':
              $featArray = array();
              $modArray = array();
              $ignoreArray = array();
              foreach ($data as $modifier ) {
                switch ( $modifier[2]) {
                  case 'feature':
                    $featArray[] = $modifier[1];
                    break;
                  case 'warn':
                  case 'ignore':
                    $ignoreArray[] = $modifier[1];
                    break;
                  case 'mod':
                    $modArray[] = $modifier[1];
                    break;
                 }
              }
              if ( count ( $featArray)) $features = implode (get_alt_names($featArray), ' / ');
              if ( count ( $modArray)) $mods = implode (get_alt_names($modArray), ' / ');
              if ( count ( $ignoreArray)) $ignored = implode (get_alt_names($ignoreArray), ' / ');
              break;
              case 'features':
                foreach ($data as $feature => $details) {
                  if ( array_key_exists('proper',$details))
                    $proper .= '(' . $feature . ' ' . $details['proper'] . ') ';
                }
                break;
              case 'proper':
              case 'default':
                if ( is_array($data))
                  $proper .= implode(',', $data) . ' ';
                else
                  $proper .= $data . ' ';
                break;
              case 'file':
                $source = str_replace('inkscape/','',$data);
                break;
              case 'body':
                $source = 'built-in';
                break;
              case 'patterns':
                // $name = implode($data,' ');
                $name = implode(get_alt_names($data),' / ');
                break;
              case 'doc':
                // To be deleted, never used
                break;
              case 'either':
              case 'flags':
              // data for use in parser so don't care, do nothing
              break;
              case 'licence':
              case 'height':
              case 'width':
                echo "Warning, obsolete field in $subtype\n";
                // obsolete soon I hope!
                break;
              default:
                if ( is_array($data))
                  echo "$item is array in $subtype\n";
                else
                  $flags .= "$item=$data ";
                break;
            }
          }
          $chargeList .= "\"$name\",\"$type\",\"$features\",\"$mods\",\"$ignored\",\"$proper\",\"$flags\",\"$source\",\"$file\"\n";
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
  $fp = fopen($target_dir . 'charge_list.dat','w');
  fwrite ( $fp, serialize($charges) );
  fclose ( $fp );
  unset ( $charges );
  $fp = fopen($target_dir . 'ordinary_list.dat','w');
  fwrite ( $fp, serialize($ordinaries) );
  fclose($fp);
  unset ( $ordinaries );
  $fp = fopen($target_dir . 'either_list.dat','w');
  fwrite ( $fp, serialize($either) );
  fclose($fp);
  unset ( $either );
  file_put_contents('charges.csv', $chargeList);
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
