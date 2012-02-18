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

// annulet

$charge = array (

  'patterns' => array (
  'annulets?',
  ),
  'modifiers' => array (
    array ( NULL, 'one (within|inside) ?the other', 'mod', 'concentric',    ),
  ),

  'doc' => 'Stuff...',

);

if ($node != null)
  $num = get_mod($node, 'concentric');
else
  $num = 1;
if ( $num == 0 ) $num = 1;
$space = min (40, (225 / $num));
$width = $space * 0.7;
$gap = $space * 0.3;
$body = '';
for ( $i = 0; $i < $num; $i++ ) {
  $outer = $i * ($width + $gap);
  $inner = $outer + $width;
  $out_diam = 500 - ($i * ($width + $gap) * 2);
  $out_rad = $out_diam / 2;
  $in_diam = $out_diam - $width - $width;
  $in_rad = $in_diam / 2;
  $body .= "<path d=\"M $outer,250 a $out_rad,$out_rad 0,0,1 $out_diam,0 a $out_rad,$out_rad 0,0,1 -$out_diam,0 z M $inner,250 a $in_rad,$in_rad 0,0,1 $in_diam,0 a $in_rad,$in_rad 0,0,1 -$in_diam,0 z\" fill-rule=\"evenodd\" />";
}
$charge['body'] = $body;
$charge['width'] = 500;
$charge['height'] = 500;

?>
