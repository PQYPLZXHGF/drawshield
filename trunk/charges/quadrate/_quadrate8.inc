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

$charge['modifiers'] = array (
    array ( null, 'voided', 'mod', 'voided' ),
    array ( 'all', 'fitch(y|ee)', 'mod', 'fitchy' ),
    array ( 'foot', 'fitch(y|ee) at ?the foot', 'mod', 'fitchy' ),
);


$crossData = array (
  'cross-crosslet' => '100:100:l10,0 0,10 20,0 0,20 -20,0 0,60::s:',
  'cross-test' => '100:100:l10,0 0,10 20,0 0,20 -20,0 c 0,30 5,85 10,90::s:',
  // 'cross-test' => '100:100:h20v80:::',
  'cross-botonny' => '100:100:a15,15 0,0,1 10,24a15,15 0,0,1 2,24v42::s',
  );

if ( $node != null ) {
  $crossType = $node->getAttribute('subtype');
  $fitchy = get_mod($node,'fitchy');
  if ( ! array_key_exists($crossType, $crossData) ) {
    draw_message('internal',"No Cross of type $crossType" );
  } else {
    list ( $size, $start, $main, $void, $fitch, $foot ) = explode ( ':', $crossData[$crossType] . ':::' );
    $mirror = reversePath(mirrorPath($main,'y'));
    $path = $main;
    $path .= rotatePath($mirror,90);
    $path .= rotatePath($main,90);
    if ( $fitchy && ($fitch != '') ) {
      if ( $fitch == 's' ) { // standard fitchy, 20 wide, 100 high
        $path .= 'v60l-10,30 -10,-30v-60';
      } else {
        $path .= $fitch;
        $path .= reversePath(mirrorPath($fitch,'y'));
      }  
    } else {
      $path .= rotatePath($mirror,180);
      $path .= rotatePath($main,180);
    }
    $path .= rotatePath($mirror,270);
    $path .= rotatePath($main,270);
    $path .= $mirror;
    $path = 'm' . $size . ',' . ($size - $start) . $path . 'z';
    $charge['height'] = $charge['width'] = $size * 2;
    $charge['body'] = "<path d=\"$path\" />";
  }
}
?>
