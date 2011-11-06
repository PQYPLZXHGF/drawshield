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

function add_def($element = '', $content = '', $name = '', $title = '', $desc = ''){
  static $defs;

  if ( $element == '' ) { // If no arguments then return a complete <defs> section
	  if ( $defs == '' ) { // Unless nothing has been defined yet
			$retval = '';
		} else {
      $retval = '<defs>' . $defs . '</defs>';
      $defs = ''; // Clear defs, ready for some more
		}
    return $retval;
  } // else if we given some arguments, then create an approprate defintion
  $element_words = explode(' ', $element);
  $type = $element_words[0];
  if ( $name == '' ) { $name = $type; }
  $myid = unique($name);
  $def = '<' . $element . ' id="' . $myid . '" >' . "\n";
  if ($title != '' ) {
    $def .= '<title>' . $title . "</title>\n";
  }
  if ($desc != '') {
    $def .= '<desc>' . $desc . "</desc>\n";
  }
  $def .= $content;
  $def .= "\n</" . $type . ">\n";

  $defs .= $def;
  return $myid; // and return an id unique to this SVG file
}

function apply_tincture ( $tincture, $object, $chg_size = '',
        $rot = '0', $rev = false, $inv = false ) {
  global $_SERVER;
	
	$patTrans = '';
	$object_type = $tincture->parentNode->nodeName;
	if ( $object_type == 'charge' and $chg_size != '' ) // We make some things a wee bit smaller if on a charge, just for looks
	{
	  list($chgX,$chgY) = explode(',', $chg_size);
		$scale = max ( $chgX / 1000, $chgY / 1200 ); // multiply here to adjust relative size of fur etc. on a charge
	  $patTrans = ' scale(' . $scale . ') ';
	}
	if ( $rot != '0' ) // If the object is rotated, we rotate some of the tinctures to match_number()
	  $patTrans .= ' rotate(' . ($rot * -1) . ') ';
	if ( $patTrans != '' )
	  $patTrans = ' patternTransform="' . $patTrans . '" ';

  if ( $tincture->getAttribute('origin') == 'implied' ) return $object; // Nothing to do
  $child = $tincture->firstChild;
  switch ( $child->nodeName ) {
    case 'colour':
    case 'default': // don't think these two ever occur
    case 'proper':
      if ( $child->hasAttribute('name') ) $spec = rgb($child->getAttribute('name'));
      elseif ( $child->hasAttribute('spec') ) $spec = $child->getAttribute('spec');
      else {
        $spec = '#F0F0F0'; // raise error
        draw_message('internal', 'Colour not known', __FILE__, __LINE__);
      }
      $retval = '<g fill="' . $spec . '">' . $object . '</g>';
      break;
    case 'fur':
      $fur_name = $child->getAttribute('name');
      $fur_data = makeFur( $fur_name );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      // Don't need to do reversed as all furs are symmetrical
      if ( $inv ) $fur_data[2] = "<g transform=\"translate(0,{$fur_data[1]}) scale(1,-1)\">{$fur_data[2]}</g>";
      $patt_id = add_def ( 'pattern ' . $patTrans .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $fur_data[0] . '" height="' . $fur_data[1] . '"',
         $fur_data[2] );
      $retval = add_def();
      $stroke = ($object_type == 'ordinary') ? 'stroke="black" stroke-width="5"' : '';
      $retval .= '<g ' . $stroke . ' fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      break;
    case 'treatment':
      $treat_data = makeTreatment( $child );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      // Don't need to do reversed as all treatments are symmetrical
      if ( $inv ) $treat_data[2] = "<g transform=\"translate(0,{$treat_data[1]}) scale(1,-1)\">{$treat_data[2]}</g>";
      $patt_id = add_def ( 'pattern ' . $patTrans .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $treat_data[0] . '" height="' . $treat_data[1] . '"',
         $treat_data[2] );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      break;
    case 'semyde':
      $treat_data = makeSemy( $child );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      if ( $inv ) $treat_data[2] = "<g transform=\"translate(0,{$treat_data[1]}) scale(1,-1)\">{$treat_data[2]}</g>";
      if ( $rev ) $treat_data[2] = "<g transform=\"translate({$treat_data[0]},0) scale(-1,1)\">{$treat_data[2]}</g>";
      $patt_id = add_def ( 'pattern ' . $patTrans .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $treat_data[0] . '" height="' . $treat_data[1] . '"',
         $treat_data[2] );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      break;
    case 'division': 
		  $title = '<title>' . $child->getAttribute('subtype') . '</title>';
	    // What we do depends on what we are filling...
      switch ($object_type) {
				case 'plain': // just the field of the shield
				  $retval = '<g>' . $title . '<desc>Division used to fill field</desc>' . makeDivision( $child ) . '</g>';
			  	break;
			  case 'ordinary':
				case 'charge':
				  chief('push','NC');
          $new_div = makeDivision( $child );
          chief('pop');
					$height = get_div_height($child);
          $patt_id = add_def ( 'pattern width="100%" height="100%" patternUnits="objectBoundingBox" preserveAspectRatio="none" viewBox="0 0 1000 ' .   $height . '"',
              $title . "<desc>Division used to fill $object_type</desc>" .
               $new_div ); 
          $retval = add_def();
          $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
				  break;
			}
			break;	
    case 'counterchanged': // Never change anything, just fill with this pattern
      // First we have to locate the field
      $parent = $tincture->parentNode;
      while ( $parent->nodeName != 'plain' ) { // TODO what about if overall?
        $parent = $parent->parentNode;
      }
      $field = $parent->firstChild;
      // Then confirm that the field is a division
      if ( $field->firstChild->nodeName != 'division' ) 
			  return '<g fill="#050505"><title>Counterchange</title><desc>Not possible</desc>' . $object . '</g>';
			// else go ahead
      $div_data = makeDivision( $field->firstChild, true );
      if ( $object_type == 'charge' and (preg_match ( '/(chrome|firefox)/i' , $_SERVER['HTTP_USER_AGENT'] ) != 0))
        draw_message ('warning','Browser bug may not render counterchanged charge correctly.' );
      $patt_id = add_def ( 'clipPath', $object );
      $retval = add_def() . '<g clip-path="url(#' . $patt_id . ')"  >' . $div_data . '</g>';
			if ( $object_type == 'charge' ) // add the outline and any shading
			  $retval .= '<g fill="none">' . $object . '</g>';
      break;
			// END of switch
  }
  return $retval;
}

function choose_fit( $choices ) {
  global $svg_region, $svg_chief;

  if ( !is_array($choices) ) return $choices;
  // Look for chief/no chief first
  if ( array_key_exists($svg_chief, $choices) ) return $choices[$svg_chief];
  // Look for region alone next
  if ( array_key_exists($svg_region, $choices) ) return $choices[$svg_region];
  // Last resort, look for the combination
  $combo = $svg_region . $svg_chief;
  if ( array_key_exists($combo, $choices) ) return $choices[$combo];
  // raise error
  draw_message('internal', 'Cannot find placement for region', __FILE__, __LINE__);
  return null;
}

function rotatePoint( $x, $y, $theta ) {
  $retval = '';
  switch ( $theta ) {
    case 360:
    case 0: // should not happen, but just in case...
      $x2 = $x;
      $y2 = $y;
      break;
    case 90:
      $x2 = $y * -1;
      $y2 = $x;
      break;
    case 180:
      $x2 = $x * -1;
      $y2 = $y * -1;
      break;
    case 270:
      $x2 = $y;
      $y2 = $x * -1;
      break;
    default:
      $cos = cos(deg2rad($theta));
      $sin = sin(deg2rad($theta));
      $x2 = ($cos * $x) - ($sin * $y);
      $y2 = ($cos * $y) + ($sin * $x);
      $retval = sprintf('%.3f,%.3f',$x2,$y2);
      break;
  }
  if ($retval == '') $retval = "$x2,$y2";
  return $retval;
}

function getNumbers( $argString ) {
  $chunks = preg_split('/([ ,\-])/', $argString, null, PREG_SPLIT_DELIM_CAPTURE);
  $argArray = array();
  $negate = false;
  foreach ($chunks as $chunk) {
    if ( $chunk == '' or $chunk == ' ' or $chunk == ',' )
      continue;
    if ( $chunk == '-' ) {
      $negate = true;
      continue;
    }
    // We must have a number
    if ( $negate ) {
      $argArray[] = '-' . $chunk;
      $negate = false;
    }
    else
      $argArray[] = $chunk;
  }
  return $argArray;
}

function rotatePath( $path, $theta ) {
  if ( $theta == 0 ) return $path;
  $newPath = '';
  $chunks = preg_split('/([a-z])/i', $path, null, PREG_SPLIT_DELIM_CAPTURE );
  for ( $i = 0; $i < count($chunks); $i++ ) {
    $command = $chunks[$i];
    if ( isset($chunks[$i+1]) )
      $numbers = getNumbers( $chunks[$i+1] );
    switch ( strtolower($command) ) {
      case 'h':
        $x = $numbers[0];
        if ($theta == 270 )
          $newPath .= 'v' . ($x * -1);
        elseif ( $theta == 180 )
          $newPath .= 'h' . ($x * -1);
        elseif ( $theta == 90 )
          $newPath .= 'v' . $x;
        else
          $newPath .= 'l' . rotatePoint($x,0, $theta);
        break;
      case 'v':
        $y = $numbers[0];
        if ($theta == 270 )
          $newPath .= 'h' . $y;
        elseif ( $theta == 180 )
          $newPath .= 'v' . ($y * -1);
        elseif ( $theta == 90 )
          $newPath .= 'h' . ($y * -1);
        else
          $newPath .= 'l' . rotatePoint(0,$y, $theta);
        break;
      case 'a':
        list($rx,$ry,$rot,$arc,$sweep,$x,$y) = $numbers;
        $newPath .= "a$rx,$ry " . (($rot + $theta)%360) . ",$arc,$sweep " . rotatePoint($x,$y, $theta);
        break;
      case 'l':
      case 'q':
      case 'c':
      case 'm':
        $newPath .= $command;
        if ($command == 'M') {
          $newPath .= $numbers[0] . ',' . $numbers[1];
        } else {
          for ( $j = 0; $j < count($numbers); $j += 2 )
            $newPath .= rotatePoint($numbers[$j], $numbers[$j+1], $theta ) . ' ';
          }
        break;
      case 'z':
        $newPath .= $command;
        break;
    }
    $newPath .= ' ';
  }
  return $newPath;
}

function mirrorPath ( $path, $axis = 'x' ) {
  $newPath = '';
  $chunks = preg_split('/([a-z])/i', $path, null, PREG_SPLIT_DELIM_CAPTURE );
  for ( $i = 0; $i < count($chunks); $i++ ) {
    $command = $chunks[$i];
    if ( isset($chunks[$i+1]) ) {
      $numbers = getNumbers($chunks[$i+1]);
    }
    switch ( strtolower($command) ) {
      case 'h':
        $x = $numbers[0];
        if ($axis == 'x')
          $newPath .= 'h' . $x;
        else
          $newPath .= 'h' . ($x * -1);
        break;
      case 'v':
        $y = $numbers[0];
        if ($axis == 'x')
          $newPath .= 'v' . ($y * -1);
        else
          $newPath .= 'v' . $y;
        break;
      case 'a':
        list($rx,$ry,$rot,$arc,$swap,$x,$y) = $numbers;
        if ( $axis == 'x' ) {
          $swap = $swap == 1? 0 : 1;
          $newPath .= "a$rx,$ry " . (($rot + 180)%360) . ",$arc,$swap $x,$y";
        } else {
          $x *= -1;
          $newPath .= "a$rx,$ry " . (($rot + 180)%360) . ",$arc,$swap $x,$y";
        }
        break;
      case 'l':
      case 'q':
      case 'c':
      case 's':
      case 'm':
        $newPath .= $command;
        for ( $j = 0; $j < count($numbers); $j += 2 ) {
          if ( $command == 'M' ) {
            $newX = $numbers[$j];
            $newY = $numbers[$j+1];
          } elseif ( $axis == 'x' ) {
            $newX = $numbers[$j];
            $newY = $numbers[$j+1] * -1;
          } else {
            $newX = $numbers[$j] * -1;
            $newY = $numbers[$j+1];
          }
          $newPath .= "$newX,$newY ";
        }
        break;
      case 'z':
        $newPath .= $command;
        break;
    }
    $newPath .= ' ';
  }
  return $newPath;
}

function scalePath ( $path, $xScale = 1, $yScale = 1 ) {
  $newPath = '';
  $chunks = preg_split('/([a-z])/i', $path, null, PREG_SPLIT_DELIM_CAPTURE );
  for ( $i = 0; $i < count($chunks); $i++ ) {
    $command = $chunks[$i];
    if ( isset($chunks[$i+1]) ) {
      $numbers = getNumbers($chunks[$i+1]);
    }
    switch ( strtolower($command) ) {
      case 'h':
        $x = $numbers[0];
        if ($xScale == 1)
          $newPath .= 'h' . $x;
        else
          $newPath .= 'h' . ($x * $xScale);
        break;
      case 'v':
        $y = $numbers[0];
        if ($yScale == 1)
          $newPath .= 'v' . $y;
        else
          $newPath .= 'v' . ($y * $yScale);
        break;
      case 'a':
        list($rx,$ry,$rot,$arc,$swap,$x,$y) = $numbers;
        if ( $xScale != 1 ) {
          $rx *= $xScale;
          $x *= $xScale;
        }
        if ( $yScale != 1 ) {
          $ry *= $yScale;
          $y *= $yScale;
        }
        $newPath .= "a$rx,$ry $rot,$arc,$swap $x,$y";
        break;
      case 'c':
      case 'l':
      case 'q':
      case 's':
      case 'm':
        $newPath .= $command;
        for ( $j = 0; $j < count($numbers); $j += 2 ) {
          $newY = $numbers[$j+1];
          $newX = $numbers[$j];
          if ( $xScale != 1 ) {
            $newX *= $xScale;
          }
          if ( $yScale != 1 ) {
            $newY *= $yScale;
          }
          $newPath .= "$newX,$newY ";
        }
        break;
      case 'z':
        $newPath .= $command;
        break;
    }
    $newPath .= ' ';
  }
  return $newPath;
}

function makeRelative ( $path, $Xoff = 0, $Yoff = 0 ) {
  $newPath = '';
  $chunks = preg_split('/([a-z])/i', $path, null, PREG_SPLIT_DELIM_CAPTURE );
  $curX = $Xoff; $curY = $Yoff; 
  for ( $i = 0; $i < count($chunks); $i++ ) {
    $command = $chunks[$i];
    if ( isset($chunks[$i+1]) ) {
      $numbers = getNumbers($chunks[$i+1]);
    }
    switch ( $command ) {
      case 'h':
        $x = $numbers[0];
        $curX += $x;
        $newPath .= 'h' . $x;
        break;
      case 'H':
        $x = $numbers[0];
        $newPath .= 'h' . ($x - $curX);
        $curX = $x;
        break;
      case 'v':
        $y = $numbers[0];
        $curY += $y;
        $newPath .= 'v' . $y;
        break;
      case 'V':
        $y = $numbers[0];
        $newPath .= 'v' . ($y - $curY);
        $curY = $y;
        break;
      case 'a':
        list($rx,$ry,$rot,$arc,$swap,$x,$y) = $numbers;
        $newPath = "a$rx,$ry $rot,$arc,$swap $x,$y";
        $curX += $x;
        $curY += $y;
        break;
      case 'A':
        list($rx,$ry,$rot,$arc,$swap,$x,$y) = $numbers;
        $newPath = "a$rx,$ry $rot,$arc,$swap " . ($x - $curX) . ',' . ($y - $curY);
        $curX = $x;
        $curY = $y;
        break;
      case 'c':
        $tempPath = 'c';
        for ( $j = 0; $j < count($numbers); $j += 6 ) {
          $cpStartX = $numbers[$j+0];
          $cpStartY = $numbers[$j+1];
          $cpEndX = $numbers[$j+2];
          $cpEndY = $numbers[$j+3];
          $endX = $numbers[$j+4];
          $endY = $numbers[$j+5];
          $tempPath .= "$cpStartX,$cpStartY $cpEndX,$cpEndY $endX,$endY ";
          $curX += $endX;
          $curY += $endY;
        }
        $newPath .= $tempPath;
        break;
      case 'C': // $newPath .= "($curX,$curY)";
        $tempPath = 'c';
        for ( $j = 0; $j < count($numbers); $j += 6 ) {
          $cpStartX = $numbers[$j+0];
          $cpStartY = $numbers[$j+1];
          $cpEndX = $numbers[$j+2];
          $cpEndY = $numbers[$j+3];
          $endX = $numbers[$j+4];
          $endY = $numbers[$j+5];
          $tempPath .= ($cpStartX - $curX) . ',' . ($cpStartY - $curY) . ' ';
          $tempPath .= ($cpEndX - $curX) . ',' . ($cpEndY - $curY) . ' ';
          $tempPath .= ($endX - $curX) . ',' . ($endY - $curY) .' ';
          $curX = $endX;
          $curY = $endY;
        }
        $newPath .= $tempPath;
        break;
      case 'l':
      case 'm':
        $tempPath = $command;
        for ( $j = 0; $j < count($numbers); $j += 2 ) {
          $y = $numbers[$j+1];
          $x = $numbers[$j];
          $tempPath .= "$x,$y ";
          $curX += $x;
          $curY += $y;
        }
        $newPath .= $tempPath;
        break;
      case 'L':
      case 'M':
        $tempPath = strtolower($command);
        for ( $j = 0; $j < count($numbers); $j += 2 ) {
          $y = $numbers[$j+1];
          $x = $numbers[$j];
          $tempPath .= ($x - $curX) . ',' . ($y - $curY) . ' ';
          $curX = $x;
          $curY = $y;
        }
        $newPath .= $tempPath;
        break;
      case 'z':
      case 'Z':
        $newPath .= $command;
        break;
    }
    $newPath .= ' ';
  }
  draw_message('warning',$newPath);
  return $newPath;
}

function reversePath ( $path ) {
  $newPath = '';
  $chunks = preg_split('/([a-z])/i', $path, null, PREG_SPLIT_DELIM_CAPTURE );
  for ( $i = 0; $i < count($chunks); $i++ ) {
    $command = $chunks[$i];
    if ( isset($chunks[$i+1]) ) {
      $numbers = getNumbers($chunks[$i+1]);
    }
    switch ( strtolower($command) ) {
      case 'h':
        $x = $numbers[0];
        $newPath = 'h' . ($x * -1) . $newPath;
        break;
      case 'v':
        $y = $numbers[0];
        $newPath = 'v' . ($y * -1) . $newPath;
        break;
      case 'a':
        list($rx,$ry,$rot,$arc,$swap,$x,$y) = $numbers;
        $newPath = "a$rx,$ry $rot,$arc,$swap " . ($x * -1) . ',' . ($y * -1) . $newPath;
        break;
      case 'c':
        $tempPath = '';
        for ( $j = 0; $j < count($numbers); $j += 6 ) {
          $cpStartX = $numbers[$j+0];
          $cpStartY = $numbers[$j+1];
          $cpEndX = $numbers[$j+2];
          $cpEndY = $numbers[$j+3];
          $endX = $numbers[$j+4];
          $endY = $numbers[$j+5];
          $newCPStart = ($cpEndX - $endX) . ',' . ($cpEndY - $endY);
          $newCPEnd = ($cpStartX - $endX) . ',' . ($cpStartY - $endY);
          $newEnd = ($endX * -1) . ',' . ($endY * -1);
          $tempPath = "$newCPStart $newCPEnd $newEnd $tempPath";
        }
        $tempPath = $command . $tempPath;
        $newPath = $tempPath . $newPath;
        break;
      case 'l':
      case 'q':
      case 's':
        $tempPath = '';
        for ( $j = 0; $j < count($numbers); $j += 2 ) {
          $newY = $numbers[$j+1] * -1;
          $newX = $numbers[$j] * -1;
          $tempPath = "$newX,$newY " . $tempPath;
        }
        $tempPath = $command . $tempPath;
        $newPath = $tempPath . $newPath;
        break;
      case 'z':
        $newPath .= $command;
        break;
    }
    $newPath .= ' ';
  }
  return $newPath;
}


function lineStraight( $angle, $dist ) {
  return rotatePath('h'.$dist, $angle);
}

?>