<?php
$maxRecords = 20;
echo '<?xml version="1.0" encoding="utf-8" ?>' . "\n";
echo '<blazondb>' . "\n";

if (isset($_GET['name'])) {
  $pass = trim(file_get_contents('../../etc/blazondb.txt'));
  
  
  $db = @mysql_connect('localhost', 'karlwilc_blazons', $pass);
  if ( !$db ) {
    echo  "<error>No database connection</error>\n";
  } else {
    mysql_select_db('karlwilc_blazons');
    $term = mysql_real_escape_string( html_entity_decode($_GET['name']));
    $sql = "SELECT * from blazon WHERE lower(keyname) LIKE '$term%';";
    $results = mysql_query($sql);
    if ( !$results ) {
      echo  "<error>Query 1 failed</error>\n";
    } else {
      $count = mysql_num_rows($results);
      if ( $count > $maxRecords ) {
        echo "<error>Too many records (&gt; 20)</error>\n";
      } else {
        for ( $i = 0; $i < $count; $i++ ) {
          $record = mysql_fetch_assoc($results);
          echo "<result>\n";
          echo '<name>'. $record['keyname'] . "</name>\n";
          echo '<description>'. $record['description'] . "</description>\n";
          echo '<blazon>'. $record['blazon'] . "</blazon>\n";
          echo '<source>'. $record['source'] . "</source>\n";
          echo "</result>\n";
        }
      }
    }
    mysql_close($db);
  }
} else {
    echo  "<error>No search term</error>\n";
}

echo "</blazondb>\n";
