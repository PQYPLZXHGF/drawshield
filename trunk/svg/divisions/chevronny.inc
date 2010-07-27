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


function makeDiv_chevronny( $node, $div_num ) {

  if ( $div_num != 2 ) return '';

  $num_of = get_mod ($node, 'ofnum');
  if ( $num_of < 1 ) $num_of = 4;

  $NC = '';
  $CH = '';
  $stepV = 846.5 / $num_of;
  $width = $stepV * 0.707;
  $upper = 848.4 + $width;
  $stepVC = 700.0 / $num_of;
  $widthC = $stepVC * 0.707;
  $upperC = 848.4 + $widthC;
  for ( $i = 0; $i < $num_of; $i++ ) {
    $startY = 1200 - ( $i * 2 * $stepV);
    $NC .= "X500Y{$startY}D848f{$width}H{$upper}B{$upper}d{$width}F848     ";
    $startYC = 1200 - ( $i * 2 * $stepVC );
    $CH .= "X500Y{$startYC}D848f{$widthC}H{$upperC}B{$upperC}d{$widthC}F848     ";
  }
  return compact ( 'CH', 'NC' );
}
?>
