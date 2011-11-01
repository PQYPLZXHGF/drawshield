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
    array ( null, 'pierced', 'mod', 'pierced' ),
    array ( null, '(fimbriated|edged)', 'mod+1tinc', 'fimbriated' ),
    array ( 'all', 'fitch(y|ee)', 'mod', 'fitchy' ),
    array ( 'foot', 'fitch(y|ee) at ?the foot', 'mod', 'fitchy' ),
    array ( null, '?on ?the (upper|lower|side) ?limbs?', 'warn', 'limbs' ),
    array ( null, '(at|on) each (corner|limb)', 'mod+charge', 'on' ),
);

if ( $node != null ) {
  $fitchy = get_mod($node,'fitchy');
  $voided = get_mod($node,'voided');
  $pierced = get_mod($node,'pierced');
  $fimbriated = get_mod_node($node,'fimbriated');
  if ( !isset($main ) ) {
    draw_message('internal',"No Cross of type $crossType" );
  } else {
    if ( !isset($size) ) $size = 100;
    if ( !isset($start) ) $start = 100;
    if ( !isset($voidStart) ) $voidStart = 70;
    if ( !isset($void) ) $void = 'h5v65';
    if ( !isset($pierce) ) $pierce = 'c 4.566474,0.144509 5.1445087,0.144509 7.6011561,2.83237';
    if ( !isset($pierceStart) ) $pierceStart = 10;
    if ( !isset($fitch) ) $fitch = 'v60l-10,30'; // standard fitchy, 20 wide, 100 high
    if ( !isset($foot) ) $foot = 'x';
    if ( !isset($mirror) ) $mirror = reversePath(mirrorPath($main,'y'));
    $path = $main;
    $path .= rotatePath($mirror,90);
    $path .= rotatePath($main,90);
    if ( ($fitchy == 'foot') && ($foot != 'x') ) {
      $path .= $foot;
      $path .= reversePath(mirrorPath($foot,'y'));
    } elseif ( ($fitchy) && ($fitch != 'x') ) {
      $path .= $fitch;
      $path .= reversePath(mirrorPath($fitch,'y'));
    } else {
      $path .= rotatePath($mirror,180);
      $path .= rotatePath($main,180);
    }
    $path .= rotatePath($mirror,270);
    $path .= rotatePath($main,270);
    $path .= $mirror;
    $path = 'm' . $size . ',' . ($size - $start) . $path . ((isset($separate))? '' : 'z');
    if ( $pierced ) {
      if ( $pierce != 'x' ) {
        $pierceMirror = reversePath(mirrorPath($pierce,'y'));
        $piercepath = $pierce;
        $piercepath .= rotatePath($pierceMirror,90);
        $piercepath .= rotatePath($pierce,90);
        $piercepath .= rotatePath($pierceMirror,180);
        $piercepath .= rotatePath($pierce,180);
        $piercepath .= rotatePath($pierceMirror,270);
        $piercepath .= rotatePath($pierce,270);
        $piercepath .= $pierceMirror;
        $path .= ' M' . $size . ',' . ($size - $pierceStart) . reversePath($piercepath) . 'z';
      } else
        draw_message('warning','Cannot draw cross pierced' );
    }
    elseif ( $voided ) {
      if ( $void != 'x' ) {
        $voidMirror = reversePath(mirrorPath($void,'y'));
        $voidpath = $void;
        $voidpath .= rotatePath($voidMirror,90);
        $voidpath .= rotatePath($void,90);
        $voidpath .= rotatePath($voidMirror,180);
        $voidpath .= rotatePath($void,180);
        $voidpath .= rotatePath($voidMirror,270);
        $voidpath .= rotatePath($void,270);
        $voidpath .= $voidMirror;
        $path .= ' M' . $size . ',' . ($size - $voidStart) . reversePath($voidpath) . 'z';
      } else
        draw_message('warning','Cannot draw cross voided' );
    }
	  $stroke = ( $fimbriated ) ? 'stroke="' . get_rgb( get_tincture($fimbriated) ) . '" stroke-width="4"' : '';
    $charge['height'] = $size * 2;
    $charge['width'] = $size * 2;
    $charge['body'] = "<path $stroke d=\"$path\" />";
  }
}
?>
