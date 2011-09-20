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

function lineStraight( $dir, $dist ) {
  switch ( strtoupper($dir) ) {
  case 'A': return 'h' . $dist;
  case 'B': return 'l' . ($dist*0.707) . ',' . ($dist*0.707);
  case 'C': return 'v' . $dist;
  case 'D': return 'l' . ($dist*-0.707) . ',' . ($dist*0.707);
  case 'E': case 'P': return 'h-' . $dist;
  case 'F': case 'Q': return 'l' . ($dist*-0.707) . ',' . ($dist*-0.707);
  case 'G': case 'R': return 'v-' . $dist;
  case 'H': case 'S': return 'l' . ($dist*0.707) . ',' . ($dist*-0.707);
  case 'J': return 'l' . ($dist*0.5) . ',' . ($dist*-0.866);
  case 'K': return 'l' . ($dist*0.5) . ',' . ($dist*0.866);
  case 'L': return 'l' . ($dist*-0.5) . ',' . ($dist*0.866);
  case 'M': return 'l' . ($dist*-0.5) . ',' . ($dist*-0.866);
  }
}


function subSize($str,$size) {
  $S = $size/2;
  switch($str) {
  case '+S': return $S;
  case '-S': return $S * -1;
  case '+H': return $S * 1.414;
  case '-H': return $S * -1.414;
  case '+T': return $S * 0.707;
  case '-T': return $S * -0.707;
  case '+K': return $S * 0.414;
  case '-K': return $S * -0.414;
  case '+L': return $S * 2.414;
  case '-L': return $S * -2.414;
  case '+P': return $S * 0.577;
  case '-P': return $S * -0.577;
  case '+Q': return $S * 1.155;
  case '-Q': return $S * -1.155;
  case '+R': return $S * 1.732;
  case '-R': return $S * -1.732;
  case '+0': return 0;
  }
}

$edgeMeets = array (
//                                 endPos = '-'         |                endPos = 'i'                     |            endPos = 'o'
  //        startPos->     'i'                'o'       |      '-'            'i'             'o'         |      '-'            'i'               'o'
  //  angle of      curr                                |                                                 |
  //  edges         next                                |                                                 |
     /* 315 deg 0 */   'X315-i0'=>'-S', 'X315-o0'=>'+S', 'X315i-0'=>'+H', 'X315ii0'=>'+K', 'X315io0'=>'+L', 'X315o-0'=>'-H', 'X315oi0'=>'-L', 'X315oo0'=>'-K',
     /* 315 deg 1 */   'X315-i1'=>'+H', 'X315-o1'=>'-H', 'X315i-1'=>'-S', 'X315ii1'=>'+K', 'X315io1'=>'-L', 'X315o-1'=>'+S', 'X315oi1'=>'+L', 'X315oo1'=>'-K',

     /* 270 deg 0 */   'X270-i0'=>'+S', 'X270-o0'=>'-S', 'X270i-0'=>'+0', 'X270ii0'=>'+S', 'X270io0'=>'-S', 'X270o-0'=>'+0', 'X270oi0'=>'+S', 'X270oo0'=>'-S',
     /* 270 deg 1 */   'X270-i1'=>'+0', 'X270-o1'=>'+0', 'X270i-1'=>'+S', 'X270ii1'=>'+S', 'X270io1'=>'+S', 'X270o-1'=>'-S', 'X270oi1'=>'-S', 'X270oo1'=>'-S',

     /* 135 deg 0 */   'X135-i0'=>'-H', 'X135-o0'=>'+H', 'X135i-0'=>'-S', 'X135ii0'=>'-L', 'X135io0'=>'+K', 'X135o-0'=>'+S', 'X135oi0'=>'-K', 'X135oo0'=>'+L',
     /* 135 deg 1 */   'X135-i1'=>'-S', 'X135-o1'=>'+S', 'X135i-1'=>'-H', 'X135ii1'=>'-L', 'X135io1'=>'-K', 'X135o-1'=>'+H', 'X135oi1'=>'+K', 'X135oo1'=>'+L',

     /* 180 deg n/a */

     /* 225 deg 0 */   'X225-i0'=>'+S', 'X225-o0'=>'-S', 'X225i-0'=>'+H', 'X225ii0'=>'+L', 'X225io0'=>'-K', 'X225o-0'=>'-H', 'X225oi0'=>'-K', 'X225oo0'=>'-L',
     /* 225 deg 1 */   'X225-i1'=>'+H', 'X225-o1'=>'-H', 'X225i-1'=>'+S', 'X225ii1'=>'+L', 'X225io1'=>'-K', 'X225o-1'=>'-S', 'X225oi1'=>'+K', 'X225oo1'=>'-L',

     /*  90 deg 0 */    'X90-i0'=>'-S',  'X90-o0'=>'+S',  'X90i-0'=>'+0',  'X90ii0'=>'-S',  'X90io0'=>'+S',  'X90o-0'=>'+0',  'X90oi0'=>'-S',  'X90oo0'=>'+S',
     /*  90 deg 1 */    'X90-i1'=>'+0',  'X90-o1'=>'+0',  'X90i-1'=>'-S',  'X90ii1'=>'-S',  'X90io1'=>'-S',  'X90o-1'=>'+S',  'X90oi1'=>'+S',  'X90oo1'=>'+S',

     /*  45 deg 0 */    'X45-i0'=>'-H',  'X45-o0'=>'+H',  'X45i-0'=>'+S',  'X45ii0'=>'-K',  'X45io0'=>'+L',  'X45o-0'=>'-S',  'X45oi0'=>'-L',  'X45oo0'=>'+K',
     /*  45 deg 1 */    'X45-i1'=>'+S',  'X45-o1'=>'-S',  'X45i-1'=>'-H',  'X45ii1'=>'-K',  'X45io1'=>'-L',  'X45o-1'=>'+H',  'X45oi1'=>'+L',  'X45oo1'=>'+K',

     /* 360 deg n/a */

     /* 300 deg 0 */   'X300-i0'=>'+P', 'X300-o0'=>'-P', 'X300i-0'=>'+Q', 'X300ii0'=>'+P', 'X300io0'=>'+P', 'X300o-0'=>'+Q', 'X300oi0'=>'-P', 'X300oo0'=>'-P',
     /* 300 deg 0 */   'X300-i1'=>'+Q', 'X300-o1'=>'-Q', 'X300i-1'=>'+R', 'X300ii1'=>'+P', 'X300io1'=>'-P', 'X300o-1'=>'+P', 'X300oi1'=>'+P', 'X300oo1'=>'-P',

     /* 120 deg 0 */   'X120-i0'=>'-P', 'X120-o0'=>'+P', 'X120i-0'=>'+Q', 'X120ii0'=>'-R', 'X120io0'=>'-P', 'X120o-0'=>'+Q', 'X120oi0'=>'+P', 'X120oo0'=>'+R',
     /* 120 deg 0 */   'X120-i1'=>'-Q', 'X120-o1'=>'+Q', 'X120i-1'=>'+R', 'X120ii1'=>'-R', 'X120io1'=>'+P', 'X120o-1'=>'+P', 'X120oi1'=>'-P', 'X120oo1'=>'+R',

     /* 240 deg 0 */   'X240-i0'=>'+P', 'X240-o0'=>'-P', 'X240i-0'=>'-Q', 'X240ii0'=>'+R', 'X240io0'=>'-R', 'X240o-0'=>'+Q', 'X240oi0'=>'+R', 'X240oo0'=>'-R',
     /* 240 deg 0 */   'X240-i1'=>'-Q', 'X240-o1'=>'+Q', 'X240i-1'=>'+P', 'X240ii1'=>'+R', 'X240io1'=>'+R', 'X240o-1'=>'-R', 'X240oi1'=>'-R', 'X240oo1'=>'-R',

     /*  60 deg 0 */    'X60-i0'=>'+P',  'X60-o0'=>'-P',  'X60i-0'=>'-Q',  'X60ii0'=>'-P',  'X60io0'=>'-R',  'X60o-0'=>'+Q',  'X60oi0'=>'+R',  'X60oo0'=>'+P',
     /*  60 deg 0 */    'X60-i1'=>'-Q',  'X60-o1'=>'+Q',  'X60i-1'=>'+P',  'X60ii1'=>'-P',  'X60io1'=>'+R',  'X60o-1'=>'-P',  'X60oi1'=>'-R',  'X60oo1'=>'+P',
);

$curveMeets = array (
        'A0' => '+0', 'B0' => '+T', 'C0' => '+S', 'D0' => '-T', 'E0' => '+0', 'F0' => '-T', 'G0' => '-S', 'H0' => '-T', 'I0' => '+0', 'O0' => '+0',
        'A1' => '-S', 'B1' => '-T', 'C1' => '+0', 'D1' => '+T', 'E1' => '+S', 'F1' => '+T', 'G1' => '+0', 'H1' => '-T', 'I1' => '+0', 'O1' => '+0',
);

function meetCurves($endDir, $endPos, $startDir, $startPos, $size ) {
  global $curveMeets;

  if ( $endPos == '-' and $startPos == '-' ) return array (0,0); // No action if both are in middle
  $endDir = strtoupper($endDir);
  $startDir = strtoupper($startDir);
  // Special treatment for curves
  if ( $endDir == 'I' or $endDir == 'O' ) {
    $retval[0] = subSize($curveMeets[$startDir . '0'], $size);
    $retval[1] = subSize($curveMeets[$startDir . '1'], $size);
  } elseif ( $startDir == 'I' or $startDir == 'O' ) {
    $retval[0] = subSize($curveMeets[$endDir . '0'], $size);
    $retval[1] = subSize($curveMeets[$endDir . '1'], $size);
  }
  // Table above is for 'i', reverse if Pos is 'o'
  if ( ($endPos == 'o' or $startPos == 'o') ) { //xor ( $endDir == 'O' or $startDir == 'O') ) {
    $retval[0] *= -1;
    $retval[1] *= -1;
  }
  return $retval;
}

function meetEdges($endDir, $endPos, $startDir, $startPos, $size ) {
  global $edgeMeets;

  $endDir = strtoupper($endDir);
  $startDir = strtoupper($startDir);
  // We are calculating the CLOCKWISE angle through which we would turn to be on the new "heading"
  $dirAngles = array ( 'A' => 0, 'B' => 45, 'C' => 90, 'D' => 135, 'E' => 180, 'F' => 225, 'G' => 270, 'H' => 315,
                                                                   'P' => 180, 'Q' => 225, 'R' => 270, 'S' => 315,
                        'J' => 300, 'K' => 60, 'L' => 120, 'M' => 240, );
  $angle = $dirAngles[$startDir] - $dirAngles[$endDir];
  if ( $angle < 0 ) $angle += 360;
  if ( ($endPos == '-' and $startPos == '-') or $angle == 180 or $angle == 0 ) return array (0,0); // No action if both are in middle
  $index = 'X' . $angle . $endPos . $startPos ; // From end of one line to start of next
  if ( !array_key_exists($index . '0', $edgeMeets)) return array (0,0);
  $retval[0] = subSize($edgeMeets[$index . '0'], $size);
  $retval[1] = subSize($edgeMeets[$index . '1'], $size);
  return $retval;
}

function makeOffset ( $dir, $disp, $io, $size ) {
  if ( $disp == 0 and $io == '-' ) return array(0,0);
  $x = 0; $y = 0;
  $size /= 2;
  $dispH = $disp * 0.707;
  $dispT = $disp * 0.866;
  $dispU = $disp * 0.5;
  $sizeH = $size * 0.707;
  $sizeT = $size * 0.866;
  $sizeU = $size * 0.5;
  switch($io) {
    case 'o': $ioF = -1;
              break;
    case 'i': $ioF = 1;
              break;
    case '-': $ioF = 0;
              break;
  }
  switch(strtoupper($dir)){
    case 'A': $x -= $disp; $y += $size * $ioF;
              break;
    case 'B': $x -= $dispH; $y -= $dispH; $x -= $sizeH * $ioF; $y += $sizeH * $ioF;
              break;
    case 'C': $y -= $disp; $x -= $size * $ioF;
              break;
    case 'D': $x += $dispH; $y -= $dispH; $x -= $sizeH * $ioF; $y -= $sizeH * $ioF;
              break;
    case 'P':
    case 'E': $x += $disp; $y -= $size * $ioF;
              break;
    case 'Q':
    case 'F': $x += $dispH; $y += $dispH; $x += $sizeH * $ioF; $y -= $sizeH * $ioF;
              break;
    case 'R':
    case 'G': $y += $disp; $x += $size * $ioF;
              break;
    case 'S':
    case 'H': $x -= $dispH; $y += $dispH; $x += $sizeH * $ioF; $y += $sizeH * $ioF;
              break;
    case 'J': $x -= $dispU; $y += $dispT; $x += $sizeT * $ioF; $y += $sizeU * $ioF;
              break;
    case 'K': $x -= $dispU; $y -= $dispT; $x -= $sizeT * $ioF; $y += $sizeU * $ioF;
              break;
    case 'L': $x += $dispU; $y -= $dispT; $x -= $sizeT * $ioF; $y -= $sizeU * $ioF;
              break;
    case 'M': $x += $dispU; $y += $dispT; $x += $sizeT * $ioF; $y -= $sizeU * $ioF; break;
  }
  return array( $x, $y );
}

$subArg = '';

function subFunc( $match ) {
  global $subArg;

  if ( $match[0]{2} == '}' ) {
    return $subArg;
  } else {
    $val = floatVal(substr($match[0],3));
    switch ( $match[0]{2} ) {
      case '*': return sprintf("%.3f", ($subArg * $val));
      case '/': return sprintf("%.3f", ($subArg / $val));
    }
  }
  return $match; // should not happen
}

$lineSpecs = array (
//  'indented' =>  'A:*:{S*2}:-:-:l{S/2},{S/2} {S},-{S} {S/2},{S/2}   B:*:{S*2}:-:-:h{S*1.414}v{S*1.414}   C:*:{S*2}:-:-:l-{S/2},{S/2} {S},{S} -{S/2},{S/2}   D:*:{S*2}:-:-:v{S*1.414}h-{S*1.414}  ' .
                 'E:*:{S*2}:-:-:l-{S/2},-{S/2} -{S},{S} -{S/2},-{S/2}   F:*:{S*2}:-:-:h-{S*1.414}v-{S*1.414}   G:*:{S*2}:-:-:l{S/2},-{S/2} -{S},-{S} {S/2},-{S/2}   H:*:{S*2}:-:-:v-{S*1.414}h{S*1.414}    K:*:{S*2}:-:-:l{S*1.366},{S*0.366} -{S*0.366},{S*1.366}',
  'angled' => 'A:0:100:i:o:h50v-{S}h50   B:0:100:i:o:l35.4,35.4 {S*0.707},-{S*0.707} l35.4,35.4   C:0:100:i:o:v50h{S}v50   D:0:100:o:i:l-35.4,35.4 -{S*0.707},-{S*0.707} l-35.4,35.4   E:0:100:i:o:h-50v{S}h-50   F:0:100:i:o:l-35.4,-35.4 -{S*0.707},{S*0.707} l-35.4,-35.4   G:0:100:i:o:v-50h-{S}v-50   H:0:100:o:i:l35.4,-35.4 {S*0.707},{S*0.707} l35.4,-35.4',
  'bevilled' => 'A:0:100:i:o:h75l-50,-{S}h75   B:0:100:i:o:l35.4,35.4l{S*0.353},{S*0.353}v-{S*1.414}l{S*0.353},{S*0.353}l35.4,35.4   C:0:100:i:o:v75l{S},-50v75   D:0:100:o:i:l-35.3,35.3l-{S*0.353},{S*0.353}v{S*1.414}l-{S*0.353},{S*0.353}l-35.3,35.3   E:0:100:i:o:h-75l50,{S}h-75   F:0:100:i:o:l-35.3,-35.3l-{S*0.353},-{S*0.353}v-{S*1.414}l-{S*0.353},-{S*0.353}l-35.3,-35.3   G:0:100:i:o:v-75l-{S},50v-75   H:0:100:o:i:l35.4,-35.4l{S*0.353},-{S*0.353}v{S*1.414}l{S*0.353},-{S*0.353}l35.4,-35.4',
  'escartelly' => 'A:0:100:i:i:v-{S}h100v{S}   B:0:100:i:i:l{S*0.707},-{S*0.707} 70.7,70.7 -{S*0.707},{S*0.707}   C:0:100:i:i:h{S}v100h-{S}   D:0:100:o:o:l-{S*0.707},-{S*0.707} -70.7,70.7 {S*0.707},{S*0.707}   E:0:100:o:o:v-{S}h-100v{S}   F:0:100:o:o:l{S*0.707},-{S*0.707} -70.7,-70.7 -{S*0.707},{S*0.707}   G:0:100:o:o:h{S}v-100h-{S}   H:0:100:o:o:l-{S*0.707},-{S*0.707} 70.7,-70.7 {S*0.707},{S*0.707}',
  'nowy' => 'A:0:100:i:i:a50,{S},0,0,1,100,0   B:0:100:i:i:a50,{S},45,0,1,70.7,70.7   C:0:100:i:i:a{S},50,0,0,1,0,100   D:0:100:o:o:a50,{S},-45,0,0,-70.7,70.7   E:0:100:o:o:a50,{S},0,0,0,-100,0   F:0:100:o:o:a50,{S},45,0,0,-70.7,-70.7   G:0:100:o:o:a{S},50,0,0,0,0,-100   H:0:100:i:i:a50,{S},-45,0,1,70.7,-70.7',
  'arched' => 'A:1:{D}:i:i:a{D},{S*4} 0,0,1,{D},0   B:1:{D}:i:i:a{D},{S*4} 45,0,1,{D*0.707},{D*0.707}   C:1:{D}:i:i:a{S*4},{D} 0,0,1,0,{D}   D:1:{D}:o:o:a{D},{S*4} -45,0,0 -{D*0.707},{D*0.707}   E:1:{D}:o:o:a{D},{S*4} 0,0,0,-{D},0   F:1:{D}:o:o:a{D},{S*4} 45,0,0 -{D*0.707},-{D*0.707}   G:1:{D}:o:o:a{S*4},{D} 0,0,0 0,-{D}   H:1:{D}:i:i:a{D},{S*4} -45,0,1,{D*0.707},-{D*0.707}',
  'double-arched' => 'A:2:{D/2}:i:i:a{D/2},{S*4} 0,0,1,{D/2},0   B:2:{D/2}:i:i:a{D/2},{S*4} 45,0,1 {D*0.354},{D*0.354}   C:2:{D/2}:i:i:a{S*4},{D/2} 0,0,1 0,{D/2}   D:2:{D/2}:o:o:a{D/2},{S*4} -45,0,0 -{D*0.354},{D*0.354}   E:2:{D/2}:o:o:a{D/2},{S*4} 0,0,0,-{D/2},0   F:2:{D/2}:o:o:a{D/2},{S*4} 45,0,0 -{D*0.354},-{D*0.354}   G:2:{D/2}:o:o:a{S*4},{D/2} 0,0,0 0,-{D/2}   H:2:{D/2}:o:o:a{D/2},{S*4} -45,0,1 {D*0.354},-{D*0.354}',
  'none' => 'A:*:99999:-:-:   B:*:99999:-:-:   C:*:99999:-:-:   D:*:99999:-:-:   E:*:99999:-:-:   F:*:99999:-:-:   G:*:99999:-:-:   H:*:99999:-:-:   J:*:99999:-:-:   K:*:99999:-:-:   L:*:99999:-:-:   M:*:99999:-:-:',
  'urdy' => 'A:*:{S}:i:i:l{S/4},-{S/4} 0,-{S/2} {S/4},-{S/4} {S/4},{S/4} 0,{S/2} {S/4},{S/4}   C:*:{S}:i:i:l{S/4},{S/4} {S/2},0 {S/4},{S/4} -{S/4},{S/4} -{S/2},0 -{S/4},{S/4}   E:*:{S}:i:i:l-{S/4},{S/4} 0,{S/2} -{S/4},{S/4} -{S/4},-{S/4} 0,-{S/2} -{S/4},-{S/4}   G:*:{S}:i:i:l-{S/4},-{S/4} -{S/2},0 -{S/4},-{S/4} {S/4},-{S/4} {S/2},0 {S/4},-{S/4}',
  'invected' => 'A:*:{S*2}:i:i:a{S*2},{S*5},0,0,1,{S*2},0   B:*:{S*2}:i:i:a{S*2},{S*5} 45,0,1 {S*1.414},{S*1.414}   C:*:{S*2}:i:i:a{S*5},{S*2} 0,0,1 0,{S*2}    D:*:{S*2}:i:i:a{S*2},{S*5} -45,0,1 -{S*1.414},{S*1.414}   E:*:{S*2}:i:i:a{S*2},{S*5},0,0,1,-{S*2},0    F:*:{S*2}:i:i:a{S*2},{S*5} 45,0,1 -{S*1.414},-{S*1.414}    G:*:{S*2}:i:i:a{S*5},{S*2} 0,0,1 0,-{S*2}    H:*:{S*2}:i:i:a{S*2},{S*5} -45,0,1 {S*1.414},-{S*1.414}',
  'wavy' => 'A:*:200:i:i:a100,{S*5},0,0,1,100,0a100,{S*5},0,0,0,100,0   B:*:200:i:i:a100,{S*5} 45,0,1 70.7,70.7a100,{S*5} 45,0,0 70.7,70.7   C:*:200:i:i:a{S*5},100 0,0,1 0,100a{S*5},100 0,0,0 0,100    D:*:200:i:i:a100,{S*5} -45,0,1 -70.7,70.7a100,{S*5} -45,0,0 -70.7,70.7   ' .
            'E:*:200:i:i:a100,{S*5},0,0,1,-100,0a100,{S*5},0,0,0,-100,0    F:*:200:i:i:a100,{S*5} 45,0,1 -70.7,-70.7a100,{S*5} 45,0,0 -70.7,-70.7    G:*:200:i:i:a{S*5},100 0,0,1 0,-100a{S*5},100 0,0,0 0,-100    H:*:200:i:i:a100,{S*5} -45,0,1 70.7,-70.7a100,{S*5} -45,0,0 70.7,-70.7',
  'engrailed' => 'A:*:{S*2}:o:o:a{S*2},{S*5},0,0,0 {S*2},0   B:*:{S*2}:o:o:a{S*2},{S*5} 45,0,0 {S*1.414},{S*1.414}   C:*:{S*2}:o:o:a{S*5},{S*2} 0,0,0 0,{S*2}    D:*:{S*2}:o:o:a{S*2},{S*5} -45,0,0 -{S*1.414},{S*1.414}   E:*:{S*2}:o:o:a{S*2},{S*5},0,0,0 -{S*2},0    F:*:{S*2}:o:o:a{S*2},{S*5} 45,0,0 -{S*1.414},-{S*1.414}    G:*:{S*2}:o:o:a{S*5},{S*2} 0,0,0 0,-{S*2}    H:*:{S*2}:o:o:a{S*2},{S*5} -45,0,0 {S*1.414},-{S*1.414}',
'indented' =>
  'A:*:{S*2}:-:-:l{S/2},-{S/2} l{S},{S} l{S/2},-{S/2}     ' .
  'B:*:{S*2}:-:-:h{S*0.707} v{S*1.414} h{S*0.707}     ' .
  'C:*:{S*2}:-:-:l{S/2},{S/2} l-{S},{S} l{S/2},{S/2}     ' .
  'D:*:{S*2}:-:-:v{S*0.707} h-{S*1.414} v{S*0.707}     ' .
  'E:*:{S*2}:-:-:l-{S/2},-{S/2} l-{S},{S} l-{S/2},-{S/2}     ' .
  'F:*:{S*2}:-:-:h-{S*0.707} v-{S*1.414} h-{S*0.707}     ' .
  'G:*:{S*2}:-:-:l{S/2},-{S/2} l-{S},-{S} l{S/2},-{S/2}     ' .
  'H:*:{S*2}:-:-:h{S*0.707} v-{S*1.414} h{S*0.707}     ' .
  'P:*:{S*2}:-:-:l-{S/2},{S/2} l-{S},-{S} l-{S/2},{S/2}     ' .
  'Q:*:{S*2}:-:-:v-{S*0.707} h-{S*1.414} v-{S*0.707}     ' .
  'R:*:{S*2}:-:-:l-{S/2},-{S/2} l{S},-{S} l-{S/2},-{S/2}     ' .
  'S:*:{S*2}:-:-:v-{S*0.707} h{S*1.414} v-{S*0.707}     ' .
  '',
'embattled' =>
  'A:*:{S*2}:-:-:v-{S/2}h{S} v{S} h{S} v-{S/2}    ' .
  'B:*:{S*2}:-:-:l{S*0.353},-{S*0.353}l{S*0.707},{S*0.707} l-{S*0.707},{S*0.707} l{S*0.707},{S*0.707} l{S*0.353},-{S*0.353}    ' .
  'C:*:{S*2}:-:-:h{S/2}v{S} h-{S} v{S} h{S/2}    ' .
  'D:*:{S*2}:-:-:l{S*0.353},{S*0.353}l-{S*0.707},{S*0.707} l-{S*0.707},-{S*0.707} l-{S*0.707},{S*0.707} l{S*0.353},{S*0.353}    ' .
  'E:*:{S*2}:-:-:v-{S/2} h-{S} v{S}h-{S} v-{S/2}     ' .
  'F:*:{S*2}:-:-:l{S*0.353},-{S*0.353} l-{S*0.707},-{S*0.707} l-{S*0.707},{S*0.707}l-{S*0.707},-{S*0.707} l{S*0.353},-{S*0.353}     ' .
  'G:*:{S*2}:-:-:h{S/2} v-{S} h-{S}v-{S} h{S/2}     ' .
  'H:*:{S*2}:-:-:l{S*0.353},{S*0.353} l{S*0.707},-{S*0.707} l-{S*0.707},-{S*0.707}l{S*0.707},-{S*0.707} l{S*0.353},{S*0.353}     ' .
  'P:*:{S*2}:-:-:v{S/2}h-{S} v-{S} h-{S} v{S/2}    ' .
  'Q:*:{S*2}:-:-:l-{S*0.353},{S*0.353}l-{S*0.707},-{S*0.707} l{S*0.707},-{S*0.707} l-{S*0.707},-{S*0.707} l-{S*0.353},{S*0.353}    ' .
  'R:*:{S*2}:-:-:h-{S/2}v-{S} h{S} v-{S} h-{S/2}    ' .
  'S:*:{S*2}:-:-:l-{S*0.353},-{S*0.353}l{S*0.707},-{S*0.707} l{S*0.707},{S*0.707} l{S*0.707},-{S*0.707} l-{S*0.353},-{S*0.353}    ' .
  '',
  'battled-counter' => 'A:*:{S*2}:i:i:h{S}v{S}h{S}v-{S}    C:*:{S*2}:i:i:v{S}h{S}v{S}h-{S}    ' .
                'E:*:{S*2}:i:i:h-{S}v-{S}h-{S}v{S}    G:*:{S*2}:i:i:v-{S}h-{S}v-{S}h{S}    ' .
                'B:*:{S*2}:i:i:l{S*0.707},-{S*0.707} {S*0.707},{S*0.707} -{S*0.707},{S*0.707} {S*0.707},{S*0.707}   ' .
                'F:*:{S*2}:i:i:l-{S*0.707},{S*0.707} -{S*0.707},-{S*0.707} {S*0.707},-{S*0.707} -{S*0.707},-{S*0.707}   ' .
                'H:*:{S*2}:i:i:l{S*0.707},-{S*0.707} -{S*0.707},-{S*0.707} {S*0.707},-{S*0.707} {S*0.707},{S*0.707}    ' .
                'D:*:{S*2}:i:i:l-{S*0.707},{S*0.707} {S*0.707},{S*0.707} -{S*0.707},{S*0.707} -{S*0.707},-{S*0.707}',
  'rayonny' => 'A:*:{S}:o:o:a{S/4},{S*0.4}-30,0,0,{S/4},{S/2}a{S/4},{S*0.4}-30,0,1,{S/4},{S/2}a{S/4},{S*0.4},30,0,0,{S/4},-{S/2}a{S/4},{S*0.4},30,0,1,{S/4},-{S/2}    ' .
               'B:*:{S}:o:o:a{S/4},{S*0.4},15,0,0,-{S*0.177},{S*0.53}a{S/4},{S*0.4},15,0,1,-{S*0.177},{S*0.53}a{S/4},{S*0.4},75,0,0,{S*0.53},-{S*0.177}a{S/4},{S*0.4},75,0,1,{S*0.53},-{S*0.177}    ' .
               'C:*:{S}:o:o:a{S*0.4},{S/4}-30,0,0,-{S/2},{S/4}a{S*0.4},{S/4}-30,0,1,-{S/2},{S/4}a{S*0.4},{S/4},30,0,0,{S/2},{S/4}a{S*0.4},{S/4},30,0,1,{S/2},{S/4}    ' .
               'D:*:{S}:o:o:a{S/4},{S*0.4},-75,0,0,-{S*0.53},-{S*0.177}a{S/4},{S*0.4},-75,0,1,-{S*0.53},-{S*0.177}a{S/4},{S*0.4},-15,0,0,{S*0.177},{S*0.53}a{S/4},{S*0.4},-15,0,1,{S*0.177},{S*0.53}    ' .
               'E:*:{S}:o:o:a{S/4},{S*0.4}-30,0,0,-{S/4},-{S/2}a{S/4},{S*0.4}-30,0,1,-{S/4},-{S/2}a{S/4},{S*0.4},30,0,0,-{S/4},{S/2}a{S/4},{S*0.4},30,0,1,-{S/4},{S/2}    ' .
               'F:*:{S}:o:o:a{S/4},{S*0.4},15,0,0,{S*0.177},-{S*0.53}a{S/4},{S*0.4},15,0,1,{S*0.177},-{S*0.53}a{S/4},{S*0.4},75,0,0,-{S*0.53},{S*0.177}a{S/4},{S*0.4},75,0,1,-{S*0.53},{S*0.177}    ' .
               'G:*:{S}:o:o:a{S*0.4},{S/4}-30,0,0,{S/2},-{S/4}a{S*0.4},{S/4}-30,0,1,{S/2},-{S/4}a{S*0.4},{S/4},30,0,0,-{S/2},-{S/4}a{S*0.4},{S/4},30,0,1,-{S/2},-{S/4}    ' .
               'H:*:{S}:o:o:a{S/4},{S*0.4},-75,0,0,{S*0.53},{S*0.177}a{S/4},{S*0.4},-75,0,1,{S*0.53},{S*0.177}a{S/4},{S*0.4},-15,0,0,-{S*0.177},-{S*0.53}a{S/4},{S*0.4},-15,0,1,-{S*0.177},-{S*0.53}    ',
   'potenty' => 'A:*:{S*2}:i:i:h{S*0.75}v-{S/2}h-{S/2}v-{S/2}h{S*1.5}v{S/2}h-{S/2}v{S/2}h{S*0.75}    ' .
                'B:*:{S*2}:i:i:l{S*.53},{S*0.53} {S*0.354},-{S*0.354} -{S*0.354},-{S*0.354} {S*0.354},-{S*0.354} {S*1.06},{S*1.06} -{S*0.354},{S*0.354} -{S*0.354},-{S*0.354} -{S*0.354},{S*0.354} {S*0.53},{S*0.53}    ' .
                'C:*:{S*2}:i:i:v{S*0.75}h-{S/2}v-{S/2}h-{S/2}v{S*1.5}h{S/2}v-{S/2}h{S/2}v{S*0.75}    ' .
                'D:*:{S*2}:i:i:l-{S*.53},{S*0.53} {S*0.354},{S*0.354} {S*0.354},-{S*0.354} {S*0.354},{S*0.354} -{S*1.06},{S*1.06} -{S*0.354},-{S*0.354} {S*0.354},-{S*0.354} -{S*0.354},-{S*0.354} -{S*0.53},{S*0.53}    ' .
                'E:*:{S*2}:i:i:h-{S*0.75}v{S/2}h{S/2}v{S/2}h-{S*1.5}v-{S/2}h{S/2}v-{S/2}h-{S*0.75}    ' .
                'F:*:{S*2}:i:i:l-{S*.53},-{S*0.53} -{S*0.354},{S*0.354} {S*0.354},{S*0.354} -{S*0.354},{S*0.354} -{S*1.06},-{S*1.06} {S*0.354},-{S*0.354} {S*0.354},{S*0.354} {S*0.354},-{S*0.354} -{S*0.53},-{S*0.53}    ' .
                'G:*:{S*2}:i:i:v-{S*0.75}h{S/2}v{S/2}h{S/2}v-{S*1.5}h-{S/2}v{S/2}h-{S/2}v-{S*0.75}    ' .
                'H:*:{S*2}:i:i:l{S*.53},-{S*0.53} -{S*0.354},-{S*0.354} -{S*0.354},{S*0.354} -{S*0.354},-{S*0.354} {S*1.06},-{S*1.06} {S*0.354},{S*0.354} -{S*0.354},{S*0.354} {S*0.354},{S*0.354} {S*0.53},-{S*0.53}    ',
   'dovetailed' => 'A:*:{S*2}:i:i:l{S*0.95},0 -{S*0.9},-{S} {S*1.9},0 -{S*0.9},{S} {S*0.95},0    ' .
                   'B:*:{S*2}:i:i:l{S*0.672},{S*0.672} 0,-{S*1.345} {S*1.3433},{S*1.3433} -{S*1.345},0 {S*0.672},{S*0.672}    ' .
                   'C:*:{S*2}:i:i:l0,{S*0.95} -{S},-{S*0.9} 0,{S*1.9} {S},-{S*0.9} 0,{S*0.95}    ' .
                   'D:*:{S*2}:i:i:l-{S*0.672},{S*0.672} {S*1.345},0 -{S*1.3433},{S*1.3433} 0,-{S*1.345} -{S*0.672},{S*0.672}    ' .
                   'E:*:{S*2}:i:i:l-{S*0.95},0 {S*0.9},{S} -{S*1.9},0 {S*0.9},-{S} -{S*0.95},0    ' .
                   'F:*:{S*2}:i:i:l-{S*0.672},-{S*0.672} 0,{S*1.345} -{S*1.3433},-{S*1.3433} {S*1.345},0 -{S*0.672},-{S*0.672}    ' .
                   'G:*:{S*2}:i:i:l0,-{S*0.95} {S},{S*0.9} 0,-{S*1.9} -{S},{S*0.9} 0,-{S*0.95}    ' .
                   'H:*:{S*2}:i:i:l{S*0.672},-{S*0.672} -{S*1.345},0 {S*1.3433},-{S*1.3433} 0,{S*1.345} {S*0.672},-{S*0.672}    ',
   'dancetty' => 'A:*:{S*3}:i:i:l{S*1.5},-{S} {S*1.5},{S}     C:*:{S*3}:i:i:l{S},{S*1.5} -{S},{S*1.5}     ' .
                 'B:*:{S*2.828}:i:i:l{S*1.707},{S*0.293} {S*0.293},{S*1.707}    F:*:{S*2.828}:o:o:l -{S*0.293},-{S*1.707} -{S*1.707},-{S*0.293}    ' .
                 'E:*:{S*3}:o:o:l-{S*1.5},-{S} -{S*1.5},{S}     G:*:{S*3}:o:o:l{S},-{S*1.5} -{S},-{S*1.5}     ' .
                 'D:*:{S*2.828}:i:i:l-{S*0.293},{S*1.707} -{S*1.707},{S*0.293}    H:*:{S*2.828}:o:o:l{S*1.707},-{S*0.293} {S*0.293},-{S*1.707}    ',
   'battled-embattled' =>
           'A:*:{S*2}:i:i:l{S/6},0 0,-{S/3} {S/3},0 0,-{S/3} {S/3},0 0,-{S/3} {S/3},0 0,{S/3} {S/3},0 0,{S/3} {S/3},0 0,{S/3} {S/6},0    ' .
           'B:*:{S*2}:i:i:l{S*0.118},{S*0.118} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} -{S*0.235},{S*0.235} {S*0.235},{S*0.235} -{S*0.235},{S*0.235} {S*0.235},{S*0.235} -{S*0.235},{S*0.235} {S*0.118},{S*0.118}    ' .
           'C:*:{S*2}:i:i:l0,{S/6} -{S/3},0 0,{S/3} -{S/3},0 0,{S/3} -{S/3},0 0,{S/3} {S/3},0 0,{S/3} {S/3},0 0,{S/3} {S/3},0 0,{S/6}    ' .
           'H:*:{S*2}:i:i:l{S*0.118},-{S*0.118} -{S*0.235},-{S*0.235} {S*0.235},-{S*0.235} -{S*0.235},-{S*0.235} {S*0.235},-{S*0.235} -{S*0.235},-{S*0.235} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} {S*0.235},-{S*0.235} {S*0.235},{S*0.235} {S*0.118},-{S*0.118}    ',
   'raguly' => 'A:*:{S*2}:i:i:l{S},0 -{S*0.2},-{S} {S},0 {S*0.2},{S}    ' .
               'B:*:{S*2}:i:i:l{S*0.707},{S*0.707} {S*0.629},-{S*0.777} {S*0.707},{S*0.707} -{S*0.629},{S*0.777}    ' .
               'C:*:{S*2}:i:i:l0,{S} -{S},-{S*0.2} 0,{S} {S},{S*0.2}    ' .
               'D:*:{S*2}:i:i:l-{S*0.707},{S*0.707} {S*0.777},{S*0.629} -{S*0.707},{S*0.707} -{S*0.777},-{S*0.629}    ' .
               'E:*:{S*2}:i:i:l-{S},0 {S*0.2},{S} -{S},0 -{S*0.2},-{S}    ' .
               'F:*:{S*2}:i:i:l-{S*0.707},-{S*0.707} -{S*0.629},{S*0.777} -{S*0.707},-{S*0.707} {S*0.629},-{S*0.777}    ' .
               'G:*:{S*2}:i:i:l0,-{S} {S},{S*0.2} 0,-{S} -{S},-{S*0.2}    ' .
               'H:*:{S*2}:i:i:l{S*0.707},-{S*0.707} -{S*0.777},-{S*0.629} {S*0.707},-{S*0.707} {S*0.777},{S*0.629}    ',
   'nebuly' => 'A:*:{S*4}:i:i:a{S},{S/2},0,1,0,{S},-3a{S},{S/2},0,1,1,{S},3a{S},{S/2},0,1,0,{S},-3a{S},{S/2},0,1,1,{S},3    ' .
               'B:*:{S*4}:i:i:a{S},{S/2},45,1,0,{S*0.707},{S*0.727}a{S},{S/2},45,1,1,{S*0.707},{S*0.727}a{S},{S/2},45,1,0,{S*0.707},{S*0.727}a{S},{S/2},45,1,1,{S*0.707},{S*0.727}    ' .
               'C:*:{S*4}:i:i:a{S/2},{S},0,1,0,3,{S}a{S/2},{S},0,1,1,-3,{S}a{S/2},{S},0,1,0,3,{S}a{S/2},{S},0,1,1,-3,{S}    ' .
               'D:*:{S*4}:i:i:a{S},{S/2},-45,1,0,-{S*0.727},{S*0.707}a{S},{S/2},-45,1,1,-{S*0.727},{S*0.707}a{S},{S/2},-45,1,0,-{S*0.727},{S*0.707}a{S},{S/2},-45,1,1,-{S*0.727},{S*0.707}    ' .
               'E:*:{S*4}:i:i:a{S},{S/2},0,1,0,-{S},3a{S},{S/2},0,1,1,-{S},-3a{S},{S/2},0,1,0,-{S},3a{S},{S/2},0,1,1,-{S},-3    ' .
               'F:*:{S*4}:i:i:a{S},{S/2},45,1,0,-{S*0.707},-{S*0.727}a{S},{S/2},45,1,1,-{S*0.707},-{S*0.727}a{S},{S/2},45,1,0,-{S*0.707},-{S*0.727}a{S},{S/2},45,1,1,-{S*0.707},-{S*0.727}    ' .
               'G:*:{S*4}:i:i:a{S/2},{S},0,1,0,-3,-{S}a{S/2},{S},0,1,1,3,-{S}a{S/2},{S},0,1,0,-3,-{S}a{S/2},{S},0,1,1,3,-{S}    ' .
               'H:*:{S*4}:i:i:a{S},{S/2},-45,1,0,{S*0.727},-{S*0.707}a{S},{S/2},-45,1,1,{S*0.727},-{S*0.707}a{S},{S/2},-45,1,0,{S*0.727},-{S*0.707}a{S},{S/2},-45,1,1,{S*0.727},-{S*0.707}    ' .
                '',
);

// Given a shapeSpec, a lineType and a feature size, return the appropriate
// SVG movements to create the path using the linetype. This is the bit
// inside the 'd' parameter of an SVG path element
function makePath ( $shapeSpec, $lineType, $size = 60 ) {
  $retval = '';
  $matches = preg_split('/   */', $shapeSpec);
  foreach ( $matches as $match ) {
    $retval .= makePath2(  $match, $lineType, $size );
  }
  return $retval;
}

function makePath2 ( $shapeSpec, $lineType, $size = 60 ) {
  global $lineSpecs;
  global $subArg;

  if ( $shapeSpec == '' ) return '';
  $matches = array();
  $retval = '';
  // Get the line specification
  if ($lineType == null or  ! (array_key_exists($lineType, $lineSpecs)) ) $lineType = 'none';
  $lineSpec = $lineSpecs[$lineType];
  $subArg = $size;
  // Replace any references to size (as this is fixed for this path)
  $lineSpec = preg_replace_callback('/{S.*?}/', 'subFunc', $lineSpec );
  $matches = preg_split('/   */', $lineSpec);
  foreach ( $matches as $match ) { // insert supplied values
    if ( $match != '') $lineData[$match{0}] = substr($match, 2);
  }
  // Check we have something for each direction
  foreach ( range('A', 'S') as $letter ) {
    if ( ! array_key_exists($letter, $lineData) ) {
      if ( $letter == 'P' and array_key_exists('E',$lineData) ) $lineData['P'] = $lineData['E'];
      elseif( $letter == 'Q' and array_key_exists('F',$lineData) ) $lineData['Q'] = $lineData['F'];
      elseif( $letter == 'R' and array_key_exists('G',$lineData) ) $lineData['R'] = $lineData['G'];
      elseif( $letter == 'S' and array_key_exists('H',$lineData) ) $lineData['S'] = $lineData['H'];
      else $lineData[$letter] = '*:99999:-:-:';
    }
  }
  // Chop the shape specification into "direction+distance" components
  if ( preg_match_all ( '/[A-Za-z][0-9\.\-,<>]*/', $shapeSpec, $matches ) === false ) return '';
  $shape = array();
  $count = 0;
  $Xoff = 0; $Yoff = 0;
  foreach ( $matches[0] as $match ) {
    $space = '-';
    // Get direction and distance
    $dir = $match{0};
    if ( $match{1} == '>' ) {
      $space = '>';
      $dist = floatval(substr($match,2));
    } elseif ( $match{1} == '<' ) {
      $space = '<';
      $dist = floatval(substr($match,2));
    } else {
      $dist = floatval(substr($match,1));
    }
    // Get the line spec for this direction
    if ( $dir == 'X' ) {
      $Xoff = $dist;
      continue;
    } elseif ( $dir == 'Y' ) {
      $Yoff = $dist;
      continue;
    } // else
    if ( $dir == 'I' or $dir == 'O' ) {
      $type = '1';
      $start = '-';
      $end = '-';
      $path = substr($match,1);
      $dist = 0; // This is in the path, above
    } else {
      // Now replace any references to distance (this is specific to each segment)
      $thisLine = $lineData[strtoupper($dir)];
      $subArg = $dist;
      $thisLine = preg_replace_callback('/{D.*?}/', 'subFunc', $thisLine);
      // Split the line spec into its parts
      list($type,$len,$start,$end,$path) = explode(':',$thisLine);
      $len = floatVal($len);
      if ($lineType == 'none' or ctype_lower($dir) or $len > $dist ) { // straight, or cannot fit this path into distance
        $dir = strtolower($dir);
        $start = '-';
        $end = '-';
      }
    }
    $shape[$count++] = compact('type','len','start','end','path','dir','dist', 'space');
  }
  // Move to the offset
  $retval .= "M$Xoff,$Yoff";
  // Adjust distances based on where the edges will meet
  $numSegments = count($shape);
  for ( $i = 0; $i < $numSegments; $i++ ) {
    $next = ($i+1)%$numSegments;
    // Curves we do a bit later...
    if ($shape[$i]['dir'] == 'I' or $shape[$i]['dir'] == 'O' or $shape[$next]['dir'] == 'I' or $shape[$next]['dir'] == 'O' ) continue;
    $adjust = meetEdges($shape[$i]['dir'], $shape[$i]['end'], $shape[$next]['dir'], $shape[$next]['start'], $size );
    $shape[$i]['dist'] += $adjust[0];
    $shape[$next]['dist'] += $adjust[1];
  }
  // The last adjustment also gives us the offset from the current position in the SVG path
  // Calculate the offset for the first segment
  $offs = makeOffset ( $shape[0]['dir'], $adjust[1], $shape[0]['start'], $size );
  if ( $offs[0] != 0 or $offs[1] != 0 ) $retval .= 'm' . $offs[0] . ',' . $offs[1];

  for ( $i = 0; $i < $numSegments; $i++ ) {
    extract($shape[$i]); // creates $dir and $dist etc.
    // Special handling for curves
    if ( $dir == 'I' or $dir == 'O' ) {
      // Curves are always drawn from the centre line
      $next = ($i+1)%$numSegments;
      $prev = ($i-1+$numSegments)%$numSegments;
      $adjust = meetCurves($dir, $start, $shape[$prev]['dir'], $shape[$prev]['end'],  $size);
      if ( $adjust[0] != 0 or $adjust[1] != 0 ) $retval .= "l$adjust[0],$adjust[1] ";
      $a = explode(',',$path);
      $IO = ($dir == 'I') ? '1' : '0';
      $retval .= "a$a[0],$a[1] $a[2],0,$IO $a[3],$a[4] ";
      $adjust = meetCurves($dir, $end, $shape[$next]['dir'], $shape[$next]['start'],  $size);
      if ( $adjust[0] != 0 or $adjust[1] != 0 ) $retval .= 'l' . ($adjust[0] * -1) . ',' . ($adjust[1] * -1) . ' ';
      continue;
    }
    if ( ctype_lower($dir) or $lineType == 'none' ) { // Just a straight line, no need to look up lineSpec
      $retval .= lineStraight($dir,$dist);
      continue;
    }
    switch ( $type ) { // type of line
    case '*': // insert as many times as will fit
      $reps = (int)($dist/$len);
      $left = $dist - ($reps * $len);
      if ( $left > 0 ) {
        if ( $space == '-' ) $retval .= lineStraight($dir,$left/2);
        elseif ( $space == '>' ) $retval .= lineStraight($dir,$left);
      }
      $retval .= str_repeat($path,$reps);
      if ( $left > 0 ) {
        if ( $space == '-' ) $retval .= lineStraight($dir,$left/2);
        elseif ( $space == '<' ) $retval .= lineStraight($dir,$left);
      }
      break;
    case '0': // insert once, at a fixed size
      $left = $dist - $len;
      if ( $left > 0 ) $retval .= lineStraight($dir,$left/2);
      $retval .= $path;
      if ( $left > 0 ) $retval .= lineStraight($dir,$left/2);
      break;
    case '1': // Fits the whole distance
      $retval .= $path;
      break;
    case '2': // Fits into the whole distance twice
      $retval .= $path . $path;
      break;
    }
  }
  $retval .= 'Z';
  return $retval;
}

// This maps lines and curves to their opposite directions, for spec reversal
$toReverse = array ( 'A' => 'E', 'B' => 'F', 'C' => 'G', 'D' => 'H', 'E' => 'A', 'F' => 'B', 'G' => 'C', 'H' => 'D', 'I' => 'O', 'O' => 'I',
                                                                     'P' => 'A', 'Q' => 'B', 'R' => 'C', 'S' => 'D',
                     'a' => 'e', 'b' => 'f', 'c' => 'g', 'd' => 'h', 'p' => 'a', 'q' => 'b', 'r' => 'c', 's' => 'd',
                                                                     'e' => 'a', 'f' => 'b', 'g' => 'c', 'h' => 'd', 'i' => 'o', 'o' => 'i' );

Function reverseSpec ( $shapeSpec ) {
  global $toReverse;

  $retval = '';
  $matches = array(); // Chop the shape specification into "direction+distance" components
  if ( preg_match_all ( '/[A-Za-z]-?[0-9\.\-<>,]*/', $shapeSpec, $matches ) === false ) return '';
  $shape = array();
  foreach ( array_reverse($matches[0]) as $match ) {
    // Get direction and distance
    $dir = $match{0};
    if ( $match{1} == '>' or $match{1} == '<' )
      $dist = substr($match,2);
    else
      $dist = substr($match,1);
    if ( $dir == 'I' or $dir == 'O' ) {
      $a = explode(',',$dist);
      // swap directions to end point
      $a[3] *= -1;
      $a[4] *= -1;
      $dist = implode(',',$a);
      $retval .= $toReverse[$dir] . $dist;
    } elseif ( $dir == 'X' or $dir == 'Y') {
      $retval .= $match;
    } else {
      $retval .= $toReverse[$dir] . $dist;
    }
  }
  return $retval;
}

// The inner and outer curves notionally turn through 90 degrees. This array maps the direction
// at the start of the curve onto its notional direction at the end of the curve, for offset
// matching purposes
$iCurveTo = array ( 'A' => 'C', 'B' => 'D', 'C' => 'E', 'D' => 'F', 'E' => 'G', 'F' => 'H', 'G' => 'A', 'H' => 'B',
                                                                    'P' => 'G', 'Q' => 'H', 'R' => 'A', 'S' => 'B', 'I' => 'I', 'O' => 'O' );
$oCurveTo = array ( 'A' => 'G', 'B' => 'H', 'C' => 'A', 'D' => 'B', 'E' => 'C', 'F' => 'D', 'G' => 'E', 'H' => 'F',
                                                                    'P' => 'C', 'Q' => 'D', 'R' => 'E', 'S' => 'F', 'I' => 'I', 'O' => 'O' );

// Given a shapeSpec, return another shapeSpec that is exactly parallel to the first but
// inside ($io = 'i') or outside ($io = 'o') and offset by $size
function parallelSpec ( $shapeSpec, $io, $size ) {
global $iCurveTo;
global $oCurveTo;

  $retval = '';
  $matches = array(); // Chop the shape specification into "direction+distance" components
  if ( preg_match_all ( '/[A-Za-z]-?[0-9\.\-<>,]*/', $shapeSpec, $matches ) === false ) return '';
  $shape = array();
  $count = 0;
  $Xoff = 0; $Yoff = 0;
  foreach ( $matches[0] as $match ) {
    // Get direction and distance
    $dir = $match{0};
    if ( $dir == 'I' or $dir == 'O' ) {
      $dist = substr($match,1);
      $shape[$count++] = compact('dir','dist');
      continue;
    }
    if ( $match{1} == '>' or $match{1} == '<' )
      $dist = floatval(substr($match,2));
    else
      $dist = floatval(substr($match,1));
    // Get the line spec for this direction
    if ( $dir == 'X' ) {
      $Xoff = $dist;
      continue;
    } elseif ( $dir == 'Y' ) {
      $Yoff = $dist;
      continue;
    } // else
    // Split the line spec into its parts
    $shape[$count++] = compact('dir','dist');
  }
  $numSegments = count($shape);
  // Adjust interior edges to meet
  $prevDir = strtoupper($shape[($numSegments-1)]['dir']);
  for ( $i = 0; $i < $numSegments; $i++ ) {
    extract($shape[$i]); // creates $dir and $dist
    $next = ($i+1)%$numSegments;
    $nextDir = $shape[$next]['dir'];
    // Deal with curves
    if ( $dir == 'I' or $dir == 'O' ) {
      $a = explode(',',$dist);
      if ($io == 'i' xor $dir == 'O' ) {
        $a[0] -= $size; $a[1] -= $size;
      } else {
        $a[0] += $size; $a[1] += $size;
      }
      if ( $dir == 'I' ) {
        $endDir = $iCurveTo[$prevDir];
      } else {
        $endDir = $oCurveTo[$prevDir];
      }
      // Adjust end point in or out for start of curve
      $adjust = meetCurves($dir, '-', $prevDir, $io, $size*2 );
      $a[3] += $adjust[0];
      $a[4] += $adjust[1];
      // Now adjust end point for end of curve
      $adjust = meetCurves($dir, '-', $endDir, $io, $size*2 );
      $a[3] -= $adjust[0];
      $a[4] -= $adjust[1];
      $shape[$i]['dist'] = implode(',',$a);
      $dir = $endDir; // Set up end of curve, for next time
    // Deal with straight edges
    } elseif ( $nextDir != 'I' and $nextDir != 'O' ) {
      $adjust = meetEdges($dir, $io, $nextDir, $io, $size*2 );
      $shape[$i]['dist'] += $adjust[0];
      $shape[$next]['dist'] += $adjust[1];
    }
    $prevDir = strtoupper($dir);
  }
  // The last adjustment also gives us the offset from the current position in the SVG path
  // Calculate the offset for the first segment
  $offs = makeOffset ( $shape[0]['dir'], $adjust[1], $io, $size*2 );
  $retval .= 'X' . ($Xoff + $offs[0]) . 'Y' . ($Yoff + $offs[1]);

  // Create the inner edge
  for ( $i = 0; $i < $numSegments; $i++ ) {
    extract($shape[$i]); // creates $dir and $dist
    $retval .= $dir . $dist;
  }
  return $retval;
}

?>
