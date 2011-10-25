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


$ordinary['plural'] = 4;

if ( !array_key_exists('modifiers', $ordinary)) $ordinary['modifiers'] = array();

$ordinary['modifiers'][] = array ( 'first',    'the (dexter|first|1st|upper|higher) ?(one|1)', 'addlinetype', 'barmod' );
$ordinary['modifiers'][] = array ( 'last',     'the (sinister|last|lower|lowest) ?(one|1)', 'addlinetype', 'barmod'   );
$ordinary['modifiers'][] = array ( 'inner',    'the (inner|inside) ?ones?', 'addlinetype', 'barmod'   );
$ordinary['modifiers'][] = array ( 'outer',    'the (outer|outside) ?ones?', 'addlinetype', 'barmod'   );

include 'ordinaries/common/_couped.inc';

if ( $node != null ) {
  $bar_locs = array ( //  0    1     2       3          4          5             6               7                  8
    'all' => array (     'x', '1', '1,2', '1,2,3', '1,2,3,4', '1,2,3,4,5', '1,2,3,4,5,6', '1,2,3,4,5,6,7', '1,2,3,4,5,6,7,8' ),
    'first' => array (   'x', 'x', '1',   '1',     '1',       '1',         '1',           '1',             '1' ),
    'last' => array (    'x', 'x', '2',   '3',     '4',       '5',         '6',           '7',             '8' ),
    'inner' => array (   'x', 'x', 'x',   '2',     '2,3',     '2,3,4',     '3,4',         '3,4,5',         '3,4,5,6' ),
    'outer' => array (   'x', 'x', 'x',   '1,3',   '1,4',     '1,5',       '1,2,5,6',     '1,2,6,7',       '1,2,7,8' ),
  );
  $subtype = $node->getAttribute('subtype');
  $num = $node->getAttribute('number');
  $bar_start = '-100';
  $bar_length = '1200';
  $palet_start = '-100';
  $palet_length = '1400';
  $linetype_size = 30;

  $main_linetype = get_mod($node, 'linetype');
  if ( $main_linetype == null ) $main_linetype = 'none';

  $mods = array_pad(array(), $num, $main_linetype );
  $couped = 'none';
  foreach ( $node->childNodes as $child ) {
    if ( $child->nodeName == 'modifier' ) {
      switch ( ($mod = $child->getAttribute('name')) ) {
        case 'barmod':
          $which = $child->getAttribute('param');
          $linetype = get_mod($child,'linetype');
          if ( $linetype == null ) $linetype = 'none';
          $locs = $bar_locs[$which][$num];
          if ( $locs != 'x' ) foreach ( explode(',',$locs) as $pos ) $mods[$pos-1] = $linetype;
          break;
        case 'couped':
          switch ( $child->getAttribute('param')) {
            case 'both':
              $bar_start = '100';
              $bar_length = '800';
              $palet_start = '100';
              $palet_length = '900';
              break;
            case 'base':
              $palet_start = '-100';
              $palet_length = '1000';
              break;
            case 'chief':
              $palet_start = '100';
              $palet_length = '1200';
              break;
            case 'dexter':
              $bar_start = '100';
              $bar_length = '1000';
              break;
            case 'sinister':
              $bar_start = '-100';
              $bar_length = '1000';
              break;
          }
          break;
        case 'gemel':
          if ( $subtype == 'bar' or $subtype == 'palet' ) $subtype .= '-gemel';
          break;
      }
    }
  }
  switch ($subtype) {
    case 'endorse':
    case 'barrulet':
      $bar_width = 200;
      $linetype_size = 25;
      break;
    case 'closet':
      $bar_width = 100;
      $linetype_size = 20;
      break;
    case 'bar-gemel':
    case 'palet-gemel':
      $linetype_size = 20;
      $bar_width = 400;
      break;
    case 'bar':
    default:
      $bar_width = 400;
      break;
  }
  if ( $num < 1 ) { $num = 1; }
  if ( $num > 8 ) { $num = 8; }
  $body = '';
  $spacing = 1000/($num+1);
  $H1 = min ( 200, ($bar_width / $num) );
  $H2 = $H1 / 2;
  for ( $i = 0; $i < $num; $i++ ) {
    switch ( $subtype ) {
      case 'barrulet':
      case 'closet':
      case 'bar':
        $Y1 = (($i+1) * $spacing) - $H2;
        $spec = "X{$bar_start}Y{$Y1}A{$bar_length}c{$H1}E{$bar_length}g{$H1}";
        break;
      case 'bar-gemel':
        $Y1 = (($i+1) * $spacing) - $H2;
        $Y2 = $Y1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $spec = "X{$bar_start}Y{$Y1}A{$bar_length}c{$H4}E{$bar_length}g{$H4}   X{$bar_start}Y{$Y2}A{$bar_length}c{$H4}E{$bar_length}g{$H4}";
        break;
      case 'palet-gemel':
        $X1 = (($i+1) * $spacing) - $H2;
        $X2 = $X1 + ($H1 * 0.75);
        $H4 = $H1 / 4;
        $spec = "X{$X1}Y{$palet_start}a{$H4}C{$palet_length}e{$H4}G{$palet_length}    X{$X2}Y{$palet_start}a{$H4}C{$palet_length}e{$H4}G{$palet_length}";
        break;
      case 'palet':
      case 'endorse':
        $X1 = (($i+1) * $spacing) - $H2;
        $spec = "X{$X1}Y{$palet_start}a{$H1}C{$palet_length}e{$H1}G{$palet_length}";
        break;
      case 'bendlet':
        $W2 = ($H1/0.707) / 2;
        $X1 = (($i+1) * $spacing) - 500 - $W2;
        $Y1 = 500 - (($i+1) * $spacing);
        $spec = "X{$X1}Y{$Y1}h{$H1}B1600d{$H1}F1600";
        break;
    }
    $body .= createBody( $spec, $mods[$i], $linetype_size );
  }
  $ordinary['body'] = $body;
}
?>
