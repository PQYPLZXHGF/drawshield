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


function makeOrd_bar($node) {
  $bar_locs = array ( //  0    1     2       3          4          5             6               7                  8
    'all' => array (     'x', '1', '1,2', '1,2,3', '1,2,3,4', '1,2,3,4,5', '1,2,3,4,5,6', '1,2,3,4,5,6,7', '1,2,3,4,5,6,7,8' ),
    'first' => array (   'x', 'x', '1',   '1',     '1',       '1',         '1',           '1',             '1' ),
    'last' => array (    'x', 'x', '2',   '3',     '4',       '5',         '6',           '7',             '8' ),
    'inner' => array (   'x', 'x', 'x',   '2',     '2,3',     '2,3,4',     '3,4',         '3,4,5',         '3,4,5,6' ),
    'outer' => array (   'x', 'x', 'x',   '1,3',   '1,4',     '1,5',       '1,2,5,6',     '1,2,6,7',       '1,2,7,8' ),
  );

  $name = $node->get_attribute('subtype');
  $num = $node->get_attribute('number');

  $mods = array_pad(array(), $num, $node->get_attribute('linetype') );
  $couped = 'none';
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->node_name() == 'modifier' ) {
      switch ( ($mod = $child->get_attribute('name')) ) {
        case 'first':
        case 'last':
        case 'inner':
        case 'outer':
          $linetype = $child->get_attribute('param');
          $locs = $bar_locs[$mod][$num];
          if ( $locs != 'x' ) foreach ( explode(',',$locs) as $pos ) $mods[$pos] = $linetype;
          break;
      }
    }
  }
  if ( $num < 1 ) { $num = 1; }
  if ( $num > 8 ) { $num = 8; }
  $body = '';
  $spacing = 1000/($num+1);
  $H1 = 400 / $num;
  $H2 = $H1 / 2;
  for ( $i = 0; $i < $num; $i++ ) {
    switch ( $name ) {
      case 'bar':
      case 'bars':
        $Y1 = (($i+1) * $spacing) - $H2;
        $spec = "X-100Y{$Y1}A1200c{$H1}E1200g{$H1}";
        $size = 30;
        break;
      case 'bar-couped':
      case 'bars-couped':
        $Y1 = (($i+1) * $spacing) - $H2;
        $spec = "X100Y{$Y1}A800c{$H1}E800g{$H1}";
        $size = 30;
        break;
      case 'bar-couped-dexter': 
      case 'bars-couped-dexter': 
        $spec = "X100Y{$Y1}A1000c{$H1}E1000g{$H1}";
        $size = 30;
            break;
      case 'bar-couped-sinister':
      case 'bars-couped-sinister':
        $spec = "X-100Y{$Y1}A1000c{$H1}E1000g{$H1}";
        $size = 30;
        break;
        break;
      case 'bar-gemel':
      case 'bar-gemels':
        $Y1 = (($i+1) * $spacing) - $H2;
        $Y2 = $Y1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $size = 20;
        $spec = "X-100Y{$Y1}A1200c{$H4}E1200g{$H4}   X-100Y{$Y2}A1200c{$H4}E1200g{$H4}";
        break;
      case 'bar-gemel-couped':
      case 'bar-gemels-couped':
        $Y1 = (($i+1) * $spacing) - $H2;
        $Y2 = $Y1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $size = 20;
        $spec = "X100Y{$Y1}A800c{$H4}E800g{$H4}   X100Y{$Y2}A800c{$H4}E800g{$H4}";
        break;
      case 'bar-gemel-couped-dexter':
      case 'bar-gemels-couped-dexter':
        $Y1 = (($i+1) * $spacing) - $H2;
        $Y2 = $Y1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $size = 20;
        $spec = "X100Y{$Y1}A1000c{$H4}E1000g{$H4}   X100Y{$Y2}A1000c{$H4}E1000g{$H4}";
        break;
      case 'bar-gemel-couped-sinister':
      case 'bar-gemels-couped-sinister':
        $Y1 = (($i+1) * $spacing) - $H2;
        $Y2 = $Y1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $size = 20;
        $spec = "X-100Y{$Y1}A1000c{$H4}E1000g{$H4}   X-100Y{$Y2}A1000c{$H4}E1000g{$H4}";
        break;
      case 'palet':
      case 'palets':
        $X1 = (($i+1) * $spacing) - $H2;
        $spec = "X{$X1}Y-100a{$H1}C1400e{$H1}G1400";
        $size = 30;
        break;
      case 'palet-couped':
      case 'palets-couped':
        $X1 = (($i+1) * $spacing) - $H2;
        $size = 30;
        $spec = "X{$X1}Y100a{$H1}C1000e{$H1}G1000";
        break;
      case 'palet-couped-chief':
      case 'palets-couped-chief':
        $X1 = (($i+1) * $spacing) - $H2;
        $size = 30;
        $spec = "X{$X1}Y100a{$H1}C1200e{$H1}G1200";
        break;
      case 'palet-couped-base':
      case 'palets-couped-base':
        $X1 = (($i+1) * $spacing) - $H2;
        $size = 30;
        $spec = "X{$X1}Y-100a{$H1}C1100e{$H1}G1100";
        break;
      case 'bendlet':
      case 'bendlets':
        $W2 = ($H1/0.707) / 2;
        $X1 = (($i+1) * $spacing) - 500 - $W2;
        $Y1 = 500 - (($i+1) * $spacing);
        $spec = "X{$X1}Y{$Y1}h{$H1}B1600d{$H1}F1600";
        $size = 30;
        break;
    }
    $body .= createBody( $spec, $mods[$i], $size );
  }
  $retval['body'] = $body;
  return $retval;
}
?>
