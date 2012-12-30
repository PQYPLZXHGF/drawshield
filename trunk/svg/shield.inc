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

// These are for scaling into quarters & dimidiations
$aspect_ratio = '10:12';
$scale_factor = 1.0;

function get_clipdata ( $AR ) {
  $clip_data = array (
    '10:12' => '0,0,1000,1200',
    '10:10' => '0,0,1000,1000',
    '10:14' => '70,0,860,1200',
    '10:24' => '250,0,500,1200',
    '10:20' => '250,0,500,1000',
    '10:28' => '285,0,430,1200',
    '10:6' => '0,200,1000,600',
  );

  $revtal = array();
  list($x1,$y1,$w,$h) = explode(',',$clip_data[$AR]);
  $retval['clippath'] = "<path d=\"M$x1,$y1 h$w v$h h-$w v-$h Z\" />";
  $retval['xOffset'] = $x1;
  $retval['yOffset'] = $y1;
  return $retval;
}

$halfHeights = array (
    '10:12' => 500,
    '10:10' => 500,
    '10:14' => 600,
    '10:24' => 600,
    '10:20' => 500,
    '10:28' => 500,
    '10:6' => 300,  
);

function getShieldShape( $item ) {
  global $aspect_ratio;
  
  // TODO deal with chiefs as well.
  $shapes = array (
    'PL' => 'v800a800,400 0 0,0 500,400 a800,400 0 0,0 500,-400v-800h-1000z',
   // 'PLQ3' => 'v200a800,400 0 0,0 500,400v-600h-500z',
    'PLQ3' => 'v342a1371,685 0 0,0 857,685v-1028h-857z',
    'PLQ4' => '',
    
   );
  
  $rectangles = array ( 
    '10:12' => 'v1200h1000v-1200h-1000z',
    '10:10' => 'v1000h1000v-1000h-1000z',
    '10:14' => 'v12h860v-1200h-860z',
    '10:24' => 'v1200h500v-1200h-500z',
    '10:20' => 'v1000h500v-1000h-500z',
    '10:28' => 'v1200h430v-1200h-430z',
    '10:6' => 'v600h1000v-600h-1000z',  
  );    
  
  $hierarchy = '';
  
  do {
    if ( $item->nodeName == 'shield') {
      $index = $item->getAttribute('index');
      switch ( $item->parentNode->nodeName ) {
      case 'blazon':
        $hierarchy = 'PL' . $hierarchy;
        break;
      case 'quartered':
        $hierarchy = 'Q' . $index . $hierarchy;
        break;
      case 'impaled':
        $hierarchy = 'I' . $index . $hierarchy;
        break;
      case 'dimidiated':
        $hierarchy = 'D' . $index . $hierarchy;
        break;
      }
    }
    $item = $item->parentNode;
  } while ($item->nodeName != 'blazon');
  
  if ( array_key_exists($hierarchy, $shapes) )
    return $shapes[$hierarchy];
  else
    return $rectangles[$aspect_ratio]; // Just a rectangle
}

function makePlain( &$children, $drawnAR = '10:12' ) {
  global $aspect_ratio;
  
  $aspect_ratio = $drawnAR;
  
  $retval = '';
  // Does this shield contain a chief?
  $found = false;
  foreach ( $children as $kid ) {
    if ( !$found and $kid->nodeName == 'ord_chgs' ) $found = find_chief ( $kid );
  }
  chief('push', $found ? 'CH' : 'NC');
  // Process the shield parts
  foreach ( $children as $kid ) {
    switch ( $kid->nodeName ) {
      case 'tincture':
        // Paint the field
        $retval .= apply_tincture ( $kid, '<rect x="0" y="0" width="1000" height="1200" ><title>Field</title></rect>' , '1000,1200' );
        break;
      case 'ord_chgs':
        // process ordinaries and charges
        $retval .= makeOrdChgs($kid);
        break;
    }
  }
  chief('pop');
  return $retval;
}

function makequarters( $children, $child_ARs, $child_Scales, $translates) {
  global $scale_factor;
  
  $retval = '';
  foreach ( $children as $kid ) {
    $index = $kid->getAttribute('index');
    region('push','Q' . $index ); // Can lose this soon I hope...
    $index -= 1; // Arrays are zero based
    $child_AR = $child_ARs[$index];
    extract( get_clipdata ($child_AR)  ); // Creates clippath, xOffset, yOffset
    $clipdef = add_def( 'clipPath', $clippath );
    $scale = $child_Scales[$index];
    $scale_factor = $scale; // Set the global (used in furs and treatments)
    if ( $scale != '' ) $scale = " scale($scale) ";
    $scaleTrans = '';
    if ( $xOffset != 0 ) $xOffset = "-$xOffset";
    if ( $yOffset != 0 ) $yOffset = "-$yOffset";
    if ( $xOffset or $yOffset ) $scaleTrans = " translate($xOffset, $yOffset) ";
    $translate = $translates[$index];
    $transform = " transform=\" $translate $scale $scaleTrans \" ";
    $retval .= '<g clip-path="url(#' . $clipdef . ')" ' . $transform . ' >' . makeshield( $kid, $child_AR ) . "</g>\n";
    region('pop');
  }
  $retval .= add_def();
  return $retval;
}

function makequartered5( $children, $this_AR ) {
  $retval = '';

}

function makequartered4( $children, $this_AR ) {
  global $halfHeights;
  
  $retval = '';
  switch ( $this_AR ) {
  case '10:12':
    $child_ARs = array ( '10:10', '10:10', '10:14', '10:14' );
    $child_Scales = array ( '0.5', '0.5', '0.5834', '0.5834' );
    $xShift = 0;
    break;
  case '10:10':
    $child_ARs = array ( '10:10', '10:10', '10:10', '10:10' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 0;
    break;         
  case '10:14':
    $child_ARs = array ( '10:14', '10:14', '10:14', '10:14' );
    $child_Scales = array ( '0.5834', '0.5834', '0.5834', '0.5834' );
    $xShift = 70;
    break;  
  case '10:20':
    $child_ARs = array ( '10:20', '10:20', '10:20', '10:20' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 250;
    break;
  case '10:24':
    $child_ARs = array ( '10:24', '10:24', '10:24', '10:24' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 250;
    break;         
  case '10:28':
    $child_ARs = array ( '10:28', '10:28', '10:28', '10:28' );
    $child_Scales = array ( '0.5', '0.5', '0.5834', '0.5834' );
    $xShift = 285;
    break; 
  default:
    draw_message ( 'internal', 'Unknown aspect ratio for quartered ' . $this_AR );
  }
  $halfHeight = $halfHeights[$this_AR];
  $translates = array (
    " translate($xShift,0) ",
    " translate(500,0) ",
    " translate($xShift,$halfHeight) ",
    " translate(500,$halfHeight) ",
  );

  return makequarters( $children, $child_ARs, $child_Scales, $translates );
}

// TODO Finish this function (see 10:12 for working example)
function makequartered6( $children, $this_AR ) {
  global $halfHeights;
  
  $retval = '';
  switch ( $this_AR ) {
  case '10:12':
    $child_ARs = array ( '10:14', '10:14', '10:14', '10:20', '10:20', '10:20' );
    $child_Scales = array ( '0.387,0.417', '0.387,0.417', '0.387,0.417', '0.667,0.7', '0.667,0.7', '0.667,0.7' );
    $xShift0 = 0;
    $xShift1 = 333;
    $xShift2 = 666;
    break;
  case '10:10':
    $child_ARs = array ( '10:10', '10:10', '10:10', '10:10' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 0;
    break;         
  case '10:14':
    $child_ARs = array ( '10:14', '10:14', '10:14', '10:14' );
    $child_Scales = array ( '0.5834', '0.5834', '0.58333', '0.58333' );
    $xShift = 70;
    break;  
  case '10:20':
    $child_ARs = array ( '10:20', '10:20', '10:20', '10:20' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 250;
    break;
  case '10:24':
    $child_ARs = array ( '10:24', '10:24', '10:24', '10:24' );
    $child_Scales = array ( '0.5', '0.5', '0.5', '0.5' );
    $xShift = 250;
    break;         
  case '10:28':
    $child_ARs = array ( '10:28', '10:28', '10:28', '10:28' );
    $child_Scales = array ( '0.5', '0.5', '0.58333', '0.58333' );
    $xShift = 285;
    break; 
  default:
    draw_message ( 'internal', 'Unknown aspect ratio for quartered ' . $this_AR );
  }
  $halfHeight = $halfHeights[$this_AR];
  $translates = array (
    " translate($xShift0,0) ",
    " translate($xShift1,0) ",
    " translate($xShift2,0) ",
    " translate($xShift0,$halfHeight) ",
    " translate($xShift1,$halfHeight) ",
    " translate($xShift2,$halfHeight) ",
  );

  return makequarters( $children, $child_ARs, $child_Scales, $translates );
  return $retval;
}

function makequartered7( $children, $this_AR ) {
  $retval = '';

  return $retval;
}

function makequartered8( $children, $this_AR ) {
  $retval = '';

  return $retval;
}

function makeimpaled( $children, $this_AR ) {
  $retval = '';
  switch ( $this_AR ) {
  case '10:12':
    $clipI = add_def( 'clipPath', '<path d="M250,0h500v1200h-500v-1200z" />' );
    $xOffset = 250;
    $child_AR = '10:24';
    break;
  case '10:10':
    $clipI = add_def( 'clipPath', '<path d="M250,0h500v1000h-500v-1000z" />' );
    $xOffset = 250;
    $child_AR = '10:20';
    break;
  case '10:14':
    $clipI = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
    $xOffset = 285;
    $child_AR = '10:28';
    break;
  default:
    //draw_message('warning', "Impaled shield too narrow" );
    $clipI = add_def( 'clipPath', '<path d="M285,0h430v1200h-430v-1200z" />' );
    $xOffset = 285;
    $child_AR = '10:28';
    break;
  }
  foreach ( $children as $kid ) {
    switch( $kid->getAttribute('index') ) {
    case '1':
      region('push','I1');
      $imp1 = makeshield( $kid, $child_AR ); 
      region('pop');
      break;
    case '2':
      region('push','I2');
      $imp2 = makeshield( $kid, $child_AR );
      region('pop');
      break;
    }
  }
  $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(-' . (500 - $xOffset) . ',0)" >' .  $imp1  . "</g>\n";
  $retval .= '<g clip-path="url(#' . $clipI . ')" transform="translate(' . (500 - $xOffset) . ',0)" >' . $imp2 . "</g>\n";
  $retval .= add_def();

  return $retval;
}
  
function makedimidiated( $children, $this_AR ) {
  $retval = '';
  
  switch ( $this_AR ) {
  case '10:12':
    $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1200 0,1200Z" />' );
    $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1200 500,1200Z" />' );
    $child_AR = '10:12';
    break;
  case '10:10':
    $clip1 = add_def( 'clipPath', '<path d="m0,0L500,0 500,1000 0,1000Z" />' );
    $clip2 = add_def( 'clipPath', '<path d="m500,0L1000,0 1000,1000 500,1000Z" />' );
    $child_AR = '10:12';
    break;
  case '10:14':
    $clip1 = add_def( 'clipPath', '<path d="m70,0L430,0 430,1200 0,1200Z" />' );
    $clip2 = add_def( 'clipPath', '<path d="m500,0L860,0 860,1200 500,1200Z" />' );
    $child_AR = '10:14';
    break;
  default:
    draw_message('warning', "Dimidiated shield too narrow" );
    $clip1 = add_def( 'clipPath', '<path d="m70,0L430,0 430,1200 0,1200Z" />' );
    $clip2 = add_def( 'clipPath', '<path d="m500,0L860,0 860,1200 500,1200Z" />' );
    $child_AR = '10:14';
    break;
  }
  foreach ( $children as $kid ) {
    switch( $kid->getAttribute('index') ) {
    case '1':
      region('push','D1');
      $retval .= '<g clip-path="url(#' . $clip1 . ')" >' . makeshield( $kid, $child_AR ) . "</g>\n";
      region('pop');
      break;
    case '2':
      region('push','D2');
      $retval .= '<g clip-path="url(#' . $clip2 . ')" >' . makeshield( $kid, $child_AR ) . "</g>\n";
      region('pop');
      break;
    }
  }
  $retval .= add_def();
  return $retval;
}

function makeshield( &$node, $this_AR ) {
  global $dom;
  global $aspect_ratio;
  
  
  $origNode = $node;
  if ( $node->hasAttribute('IDREF') ) {
    $node = $dom->getElementById($node->getAttribute('IDREF'));
  }
  
  
  $retval = '<g>';
  
  foreach ( $node->childNodes as $child ) {
    $children = $child->childNodes;
    switch ( $child->nodeName . $child->getAttribute('order') ) {
    case 'plain':
      $retval .= makePlain($children, $this_AR);
        break;
      case 'dimidiated':
        $retval .= makeDimidiated( $children, $this_AR );
        break;
      case 'impaled':
        $retval .= makeImpaled( $children, $this_AR );
        break;
      case 'quartered4':
        $retval .= makeQuartered4( $children, $this_AR );
        break;
      case 'quartered6':
        $retval .= makeQuartered6( $children, $this_AR );
        break;
      case 'missing':
        break;
      case 'overall':
        $aspect_ratio = '10:12';
        $retval .= makeOrdChgs($child->firstChild);
        break;
    }
  }
  return $retval . '</g>';
}
?>