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

// calvary

$charge['modifiers'] = array (
     array ( null, '?mounted on # (degree|step|ascent|grice|griece)s?', 'mod', 'mounted' ),
     array ( null, '(on|with) a grie?ce of # steps?', 'mod', 'mounted' ),
);

if  ( $num = get_mod($node,'mounted') ) {
  $width = max ( $charge['width'], 60 + ($num * 30) );
  $height = $charge['height'] + 30 * $num;
  $charge['body'] = preg_replace( '/{START}/', ($width / 2), $charge['body']);
  for ( $count = 0; $count < $num; $count++ ) {
    $inc = $count * 30;
    $len = 90 + $inc + $inc;
    $ypos = $charge['height'] + $inc;
    $xpos = ($width - $len)/2;
    $charge['body'] .= '<rect x="' . $xpos . '" y="' . $ypos .'" width="' . $len . '" height="30" stroke="#000000" stroke-width="3" />' . "\n";
  }
  $charge['width'] = $width;
  $charge['height'] = $height;
} else {
  $charge['body'] = preg_replace( '/{START}/', ($charge['width'] / 2), $charge['body']);
}

?>
