<html>
<head>
<title>Shield Regression Test Page</title></head>
<body>
<h1>Shield Regression Test V0.1</h1>
<table>
<tr>
<th>Name</th>
<th>Description</th>
<th>Diffs</th>
</tr>
<?php  /* Copyright 2010 Karl R. Wilcox 

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

include_once "Text/Diff.php";
include_once "Text/Diff/Renderer.php";

function formatXML($xmlArray) {
  $xmlText = '';
  foreach ($xmlArray as $line) {
    $len = strlen($line);
    $xmlText .= $line{0};
    for ($i = 1; $i < $len; $i++ ) {
      $ch = $line{$i};
      switch ($ch) {
        case '<':
          $xmlText .= "\n<";
          break;
        case "\n":
          break;
        default:
          $xmlText .= $ch;
          break;
      }
    }
    $xmlText .= "\n";
  }
  return $xmlText;
}

function writeFile($outfile, $output) {
  $fh = fopen( $outfile, 'wb' );
  fwrite($fh,formatXML($output));
  fclose($fh);
}

function runTest($data) {
  global $rebuild;
  
  if ( array_key_exists('format',$data) )
    $output = file('http://server1/include/shield/drawshield?format=' . $data['format'] . '&blazon=' . urlencode($data['blazon']));
  else
    $output = file('http://server1/include/shield/drawshield?blazon=' . urlencode($data['blazon']));
  $outfile = 'regress\\' . $data['name'] . '.out';
  $difffile = 'regress\\' . $data['name'] . '.diff';
  if ( !$rebuild and file_exists ( $outfile )) {
    $output = explode("\n",rtrim(formatXML($output)));
    $previous = file( $outfile );
    $diff = &new Text_Diff($output, $previous);
    $renderer = &new Text_Diff_Renderer();
    $diffString = $renderer->render($diff);
    if ( $diffString ) {
      $back = 'red';
      $diffCell = '<pre>' . htmlentities($diffString) . '</pre>';
    } else {
      $back = 'green';
      $diffCell =  'No changes';
    }
  } else {
    $back = 'yellow';
    $diffCell = 'Output created';
    writeFile( $outfile, $output );
  }
  echo '<tr>';
  echo '<td style="background-color:' . $back . '">' . $data['name'] . '</td>';
  echo '<td>' . $data['desc'] . '</td>';
  echo '<td>' . $diffCell . '</td>';
  echo '</tr>';
  return !( $back == 'red' );
}

function readTests($filename) {
  $lines = file($filename);
  $firstline = trim($lines[0]);
  if ($firstline{0} == '#' )
    echo '<tr><th colspan="3">' . $firstline . '</th></tr>';
  $testData = array( 'fatal' => false, 'desc' => '(not given)', 'blazon' => '' );
  $firstTest = true;
  $multi = false;
  foreach ( $lines as $line ) {
    $line = trim($line);
    if ( $line == '' or $line{0} == '#' ) continue;
    $keyValue = explode(':',$line);
    $key = $keyValue[0];
    $value = count($keyValue) > 1 ? $keyValue[1] : '';
    if ( $multi ) {
      if ( $value == '' ) { 
        $testData['blazon'] .= " $key";
        continue;
      } else
        $multi = false;
    }
    if ( $key == 'blazon' and $value == '' ) {
      $multi = true;
      continue;
    }
    if ( $key == 'name' ) {
      if ( $firstTest  ) {
        $success = true;
        $firstTest = false;
      } else 
        $success = runTest($testData);
      if ( !$success and array_key_exists('fatal',$testData) and $testData['fatal'] == 'true' ) return false;
      $testData = array( 'name' => $value, 'fatal' => false, 'desc' => '(not given)', 'blazon' => '' );
    } else
      $testData[$key] = $value;
  }
  if ( !$firstTest ) runTest($testData);
  return true;
}

$rebuild = false;
$group = '';
if (isset($_GET['rebuild'])) $rebuild = true; 
if (isset($_GET['group'])) $group = $_GET['group'];

// Read in the test scripts
$dir = opendir('regress');
$success = true;
while ( $success and ($file = readdir($dir)) != false ) {
  if ( substr($file,-5) == '.test' ) {
    if ( $group == '' or strpos($file,$group) !== false )
      $success = readTests("regress/$file");
  }
}

?>
</table>
</body>
</html>
