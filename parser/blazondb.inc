<?php

// List of retriened blazons, functions 'context' and 'checkDB' work together to
// implement recursion protection
$DBList = array();

function context($action) {
  global $DBList;
  static $wordsStack = array();
  static $cur_wordStack = array();
  static $pending_itemsStack = array();
  static $matched_tokensStack = array(); // Do we need this?
  static $p_globalsStack = array();
  static $depth = 0;
  
  global $words, $cur_word, $pending_items, $p_globals;
  
  switch ($action) {
  case 'push':
    array_push ( $wordsStack, $words );
    $words = array();
    array_push ( $cur_wordStack, $cur_word );
    array_push ( $pending_itemsStack, $pending_items );
    $pending_items = array();
    array_push ( $p_globalsStack, $p_globals );
    setpGlobals() ;
    $depth += 1;
    break;
  case 'pop':
    $words = array_pop($wordsStack);
    $cur_word = array_pop($cur_wordStack);
    $pending_items = array_pop($pending_itemsStack);
    $p_globals = array_pop($p_globalsStack);
    $depth -= 1;
    if ( $depth == 0 ) $DBList = array(); // reset list of retrieved blazons
    break;
  }
}

function checkDB() {
  global $dom;
  global $words, $cur_word;
  
  $retval = null;
  $keyname = $words[$cur_word];
  if ( !file_exists('../../../etc/blazondb.txt')) { // return null; // probably on local test machine, so OK
    $blazonDB = array (
      'england' => 'gules three lions passant guardant in pale or',
      'france' => 'azure seme de lys or',
      'simple' => 'azure a bend or',
      'test1' => 'test1',
      'test2' => 'test3',
      'test3' => 'test2',
      );
    if (array_key_exists($keyname, $blazonDB )) {
      if ( in_array ($keyname, $DBList ) ) 
        parser_message('warning','Recursion in database blazons');
      else {
        $DBList[] = $keyname;
        return $blazonDB[$keyname];
      }
    }
    return null;
  }
  
  $pass = trim(file_get_contents('../../../etc/blazondb.txt'));
  $db = @mysql_connect('localhost', 'karlwilc_blazons', $pass);
  if ( !$db ) {
    parser_message('warning','No database connection');
    return null;
  }
  
  mysql_select_db('karlwilc_blazons');
  
  $keyname = mysql_real_escape_string ($keyname);
  
  $sql = "SELECT * from blazon WHERE lower(keyname) = '$keyname';";
  $results = mysql_query($sql);
  if ( !$results ) {
    parser_message('warning','Query failed');
    return null;
  }
  if ( mysql_num_rows($results) > 0 ) {
    $record = mysql_fetch_assoc($results);
    parser_message($keyname,$record['blazon'] . ' -- ' . $record['description'] . ' (' . $record['source'] . ')');
    $retval =  $record['blazon'];
  }
  mysql_close($db);
  return $retval;
}

?>
