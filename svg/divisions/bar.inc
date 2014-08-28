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


function makeDiv_bar( $node, $div_num ) {

  if ( $div_num == 3 ) return '';

  $name = $node->getAttribute('subtype');
  if ( ($name == 'barry-pily' or $name == 'bendy' ) and get_mod($node, 'sinister')) $name .= '-sinister';
  if ( ($num_of = get_mod($node, 'ofnum')) == null ) $num_of = 8;

  $svg = '';
  $NC = '';
  $CH = '';
  $stepH = 1000 / $num_of;
  $stepC = 900 / $num_of; // with a chief
  $stepV = 1200 / $num_of;
  $stepB = 1.414 * $stepH;
  for ( $i = 1; $i < $num_of; $i +=2 ) {
    switch ( $name ) {
      case 'barry-pily':
        draw_message('link',"$name http://karlwilcox.com/parker/b/barry");
        $Y1 = ($i - 1) * $stepV;
        $svg .= "M0,{$Y1}l1000,{$stepV} -1000,{$stepV}z ";
        break;
      case 'barry-pily-sinister':
        draw_message('link',"$name http://karlwilcox.com/parker/b/barry");
        $Y1 = ($i - 1) * $stepV;
        $svg .= "M1000,{$Y1}l-1000,{$stepV} 1000,{$stepV}z ";
        break;
      case 'paly':
        draw_message('link',"$name http://karlwilcox.com/parker/p/paly");
        $X1 = $i * $stepH;
        $NC .= "X{$X1}Y-100a{$stepH}C1400e{$stepH}G1400   ";
        $CH .= "X{$X1}Y200a{$stepH}C1200e{$stepH}G1200   ";
        break;
      case 'bendy':
        draw_message('link',"$name http://karlwilcox.com/parker/b/bendy");
        $X1 = (($i-1) * $stepH) - 500;
        $Y1 = 500 - (($i-1) * $stepH);
        $X2 = (($i-1) * $stepC) - 500;
        $Y2 = 600 - (($i-1) * $stepC);
        $NC .= "X{$X1}Y{$Y1}h{$stepB}B1600d{$stepB}F1600   ";
        $CH .= "X{$X2}Y{$Y2}h{$stepB}B1300d{$stepB}F1300   ";
        break;
      case 'bendy-sinister':
        draw_message('link',"$name http://karlwilcox.com/parker/b/bendy");
        $X1 = 1500 - (($i-1) * $stepH);
        $Y1 = 500 -(($i-1) * $stepH);
        $X2 = 500 - (($i-1) * $stepC);
        $Y2 = 600 - (($i-1) * $stepC);
        $NC .= "X{$X1}Y{$Y1}D1600f{$stepB}H1600b{$stepB}   ";
        $CH .= "X{$X2}Y{$Y2}b{$stepB}D1300f{$stepB}H1300   ";
        break;
      case 'barry':
        draw_message('link',"$name http://karlwilcox.com/parker/b/barry");
        $Y1 = $i * $stepV;
        $YC = 300 + $i * $stepC;
        $NC .= "X-100Y{$Y1}A1200c{$stepV}E1200g{$stepV}   ";
        $CH .= "X-100Y{$YC}A1200c{$stepC}E1200g{$stepC}   ";
        break;
    }
  }
  return  ( $svg == '' ) ? compact('NC', 'CH') : ('<path d="' . $svg . '" />');
}

