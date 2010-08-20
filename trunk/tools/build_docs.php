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

function format ( $regex ) {
  $retvals = array();
  $retvals[] = '';
  
  $words = explode(' ', $regex );
  foreach ( $words as $word ) {
    $t_words = array();
    $t_words[] = '';
    if ( $word{0} == '?' ) { // optional word
      $retcount = count($retvals);
      for ( $i = 0; $i < $retcount; $i++ ) {
        $retvals[] = $retvals[$i] . substr($word,1) . ' ';
      }
    } else {
        $len = strlen($word);
        for ( $i = 0; $i < $len; $i++ ) {
          if ( $word{$i} != '(' and $i <= ($len - 2) and $word{$i+1} == '?' ) {
            for ( $j = 0; $j < count($t_words); $j += 1 ) 
              $t_words[$j] .= '(' . $word{$i} . ')';
            $i += 1;
          } elseif ( $word{$i} == '(' ) {
            $i += 1;
            $temp_a = array();
            $temp = '';
            while ( $i < $len ) {
              if ( $word{$i} == '|' ) {
                $temp_a[] = $temp;
                $temp = '';
              } elseif ( $word{$i} == ')' ) {
                $temp_a[] = $temp;
                break;
              } else 
                $temp .= $word{$i};
              $i += 1;
            }
            $retcount = count($t_words);
            for ( $k = 1; $k < count($temp_a); $k += 1 )
              for ( $l = 0; $l < $retcount; $l += 1 )
                $t_words[] = $t_words[$l] .= $temp_a[$k];
            for ( $l = 0; $l < $retcount; $l += 1 )
              $t_words[$l] .= $temp_a[0];
          } else {
            for ( $j = 0; $j < count($t_words); $j += 1 ) 
             $t_words[$j] .= $word{$i};
          }
        }
      }
      $retcount = count($retvals);
      for ( $j = 1; $j < count($t_words); $j += 1 ) 
        for ( $i = 0; $i < $retcount; $i++ )
          $retvals[] = $retvals[$i] .= ' ' . $t_words[$j];     
      for ( $i = 0; $i < $retcount; $i++ ) {
        $retvals[$i] .= ' ' . $t_words[0];
    }
    $retcount = count($retvals);
    for ( $i = 0; $i < $retcount; $i++ ) {
      $retvals[$i] .= ' ';
    }
  }
  return $retvals;
}

  define('CHARGE_DATA', 'parser/charge_data' );
  define('SUBTYPE_FEATURES', 'parser/subtype_features' );
  define('TYPE_FEATURES', 'parser/type_features' );

  $charges = null;
  $subtype_features = null;
  $type_features = null;
  
  $table = array();
  $output = '';

  if ( $charges == null ) {
    if ( !file_exists (CHARGE_DATA . '.dat') || filemtime(CHARGE_DATA . '.inc') >= filemtime(CHARGE_DATA . '.dat') ) {
      require_once CHARGE_DATA . '.inc';
    }
    $charges = unserialize(file_get_contents('parser/charge_data.dat'));
  }
  if ( $subtype_features == null ) {
    if ( !file_exists (SUBTYPE_FEATURES . '.dat') || filemtime(SUBTYPE_FEATURES . '.inc') >= filemtime(SUBTYPE_FEATURES . '.dat') ) {
      require_once SUBTYPE_FEATURES . '.inc';
    }
    $subtype_features = unserialize(file_get_contents(SUBTYPE_FEATURES.'.dat'));
  }
  if ( $type_features == null ) {
    if ( !file_exists (TYPE_FEATURES . '.dat') || filemtime(TYPE_FEATURES . '.inc') >= filemtime(TYPE_FEATURES . '.dat') ) {
      require_once TYPE_FEATURES . '.inc';
    }
    $type_features = unserialize(file_get_contents(TYPE_FEATURES.'.dat'));
  }
  foreach ( $charges as $charge ) {
    $table[$charge[0]] = array ( $charge[1], $charge[2] );
  }
  ksort($table);
  $cur_letter = ' ';
  foreach($table as $key => $item) {
    $this_letter = strtoupper($key{0});
    if ( $this_letter != $cur_letter ) {
      $output .= "\n==" . $this_letter . "==\n\n";
      $cur_letter = $this_letter;
    }
    $output .= $key . "\n";
    $variants = array();
    $regexs = explode ('/',$item[0]);
    foreach ( $regexs as $regex ) 
      $variants += format($regex);
    foreach ($variants as $variant )
      $output .= "         $variant \n";
    $output .= "\n";
  }


header("Content-Transfer-Encoding: text");
header('Content-Type: text/plain');
echo 'hello world';
echo $output;

?>
