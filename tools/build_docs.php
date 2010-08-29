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


function get_mod($node,$what) { return null; }

function get_main_name($patterns) {
  $pattern = $patterns[0];
  $words = explode(' ',$pattern);
  $retval = '';
  foreach ( $words as $word ) {
    if ( $word{0} == '?' ) continue;
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

$node = null;
$output = '<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xml:lang="en" xmlns="http://www.w3.org/1999/xhtml">
<head><title>Docs</title></head>
<body>
';

$rows = array();
$charges = array();
// Read in the parsing code
$dir = opendir('../charges');
while ( ($subdir = readdir($dir)) != false ) {
  if ( $subdir{0} != '.' and is_dir('../charges/' . $subdir) ) {
    $ddir = opendir('../charges/' . $subdir );
    while ( ($file = readdir($ddir)) != false ) {
      if ( ($file{0} != '_') and substr($file,-4) == '.inc' ) {
        $this_row = '<tr>';
        $type = $subdir;
        $subtype = substr($file,0,strlen($file)-4);
        $charge = array();
        include '../charges/' . $subdir . '/' . $file;
        $main_name = get_main_name($charge['patterns']);
        $id = preg_replace ( '/ /', '_', $main_name );
        $features = array();
        $others = array();
        if ( array_key_exists( 'modifiers' , $charge ) ) {
          foreach ( $charge['modifiers'] as $mod ) {
            $mod_pattern =  $mod[1];//preg_replace('/\?/', '', $mod[1] );
            // $mod_pattern = preg_replace('/\|/', ' / ', $mod_pattern );
            if ( $mod[2] == 'feature' )
              $features[] = $mod_pattern;
            else
              $others[] = $mod_pattern;
          }
        }
        // Column 1 - Charge name
        $this_row .= "<td><p><a id=\"$id\">$main_name</a></p></td>";
        // Column 2 - Colour features and information
        $this_row .= '<td>';
        if ( count($features) ) {
          $feat_names = get_alt_names($features);
          foreach ( $feat_names as $feat_name )
            $this_row .= "<p>$feat_name</p>";
        }
        if ( array_key_exists('default_colour',$charge) ) {
          if ( $charge['default_colour'] == false )
            $this_row .= '<p>(Charge tincture is fixed)</p>';
          else
            $this_row .= '<p>(If no tincture given, charge will be ' . $charge['default_colour'] . ')</p>';
        }
        if ( array_key_exists('proper',$charge) )
          $this_row .= '<p>(Charge tincture may be "proper")</p>';
        $this_row .= '</td>';
        // Column 3 - Other modifiers
        $this_row .= '<td>';
        if ( count($others) ) {
          $other_names = get_alt_names($others);
          foreach ( $other_names as $other_name )
            $this_row .= "<p>$other_name</p>";
        } else
          $this_row .= "<p>&nbsp;</p>";
        $this_row .= '</td>';
        // Column 4 - Notes
        $this_row .= '<td>';
        if ( array_key_exists('doc',$charge) and $charge['doc'] != 'Stuff...' ) 
          $this_row .= '<p>' . $charge['doc'] . '</p>';
        else
          $this_row .= "<p>&nbsp;</p>";
        $this_row .= '</td>';
        // Column 5 - example image
        if ( array_key_exists('body',$charge) ) {
          $filename = 'charges/' . $subdir . '/' . substr($file,0,(strlen($file)-4)) . '.svg';
          $svg = '<?xml version="1.0" encoding="UTF-8"?>' . "\n";
          $svg .= '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" baseProfile="full" preserveAspectRatio="xMidYMid meet" height="100px" width="100px" viewBox="0 0 ' . $charge['width'] . ' ' . $charge['height'] . '" >';
          $svg .= '<g fill="#3F3F3F">';
          $svg .= $charge['body'];
          if ( array_key_exists('features', $charge))
            foreach($charge['features'] as $extra)
              $svg .= $extra['body'];
          $svg .= '</g>';
          $svg .= '</svg>' . "\n";
          $this_row .= '<td><object type="image/svg+xml" data="data:image/svg+xml;base64,' . base64_encode($svg) . '" height="100" width="100"/></td>';
        } else
          $this_row .= "<td><p>&nbsp;</p></td>";
        $this_row .= "</tr>\n";
        // Add current row
        $rows[$main_name] = $this_row;
        // Add all alternate names
        $alts = get_alt_names($charge['patterns'],$main_name);
        foreach ( $alts as $alt )
          if ( $alt != '' )
            $rows[$alt] = "<tr><td><p>$alt</p></td><td colspan=\"4\"><p>See <a href=\"#$id\">$main_name</a></p></td></tr>";
      }
    }
  }
}

ksort($rows);
$prev = ' ';
foreach ( $rows as $key => $row ) {
  if ( $key{0} != $prev ) {
    if ( $prev != ' ' ) 
      $output .= "</table>\n";
    $output .= '<h1>' . strtoupper($key{0}) . "</h1>\n";
    $output .= "<table border=\"1\">\n";
    $output .= "<tr><th width=\"120\">Name</th><th width=\"150\">Features</th><th width=\"150\">Other</th><th width=\"110\">Notes</th><th width=\"160\">Example</th></tr>\n";
  }
  $prev = $key{0};
  $output .= $row;
}
$output .= "</table>\n";
$output .= "</body>\n</html>\n";
file_put_contents('docs.html',$output);

?>
