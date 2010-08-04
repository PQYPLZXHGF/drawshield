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

require 'parser/charge.inc';

function make_list($charges) {
  $alpha = array();
  $cats = array();
  $retval = '';
  foreach ($charges as $charge) {
    $cat = $charge[2];
    $words = explode ( '/', $charge[1] );
    foreach ($words as $word ) {
      $cats[$cat][] = $word;
      $alpha[] = $word;
    }
  }
  sort($alpha);
  foreach ( $cats as $cat ) sort ($cat);
  foreach ($alpha as $words) {
    $retval .= $words . "\n";
  }
  return $retval;
}
$output = simple_charge(false,false,true);
header("Content-Transfer-Encoding: text");
header('Content-Type: text/plain');
echo 'hello world';
echo $output;

?>
