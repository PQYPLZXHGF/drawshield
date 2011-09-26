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

function ImagePosition ( $svg_data, $height, $width, $mods ) {
  $transform = '';
  if ( in_array ( 'sinister', $mods )) {
    $xshift = $width;
    $transform .= 'translate(' . $xshift . ',0) scale(-1,1) ';
  }
  if ( in_array ( 'inverted', $mods )) {
    $yshift = $height;
    $transform .= 'translate(0,' . $yshift . ') scale(1,-1) ';
  }
  if ( in_array ( 'enhanced', $mods )) {
    $yshift = (-1) * $height * 0.15;
    $transform .= 'translate(0,' . $yshift . ') ';
  }
  if ( in_array ( 'abased', $mods )) {
    $yshift = $height * 0.15;
    $transform .= 'translate(0, ' . $yshift . ') ';
  }
  if ( $transform != '' ) {
    $svg_data = '<g transform="' . $transform . '">' . $svg_data . "</g>\n";
  }
  return $svg_data;
}

function add_def($element = '', $content = '', $name = '', $title = '', $desc = ''){
  static $defs;

  if ( $element == '' ) {
    $retval = '<defs>' . $defs . '</defs>';
    $defs = '';
    return $retval;
  } // else
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
  return $myid;
}

function apply_tincture ( $tincture, $object, $bb = '1000,1200',
        $rot = '0', $rev = false, $inv = false, $offsetX = 0, $offsetY = 0,
        $xscale = 0, $yscale = 0  ) {
  global $_SERVER; // REMOVE THESE CHECKS - which to leave?

  $bb = choose_fit($bb);
  if ( $tincture->getAttribute('origin') == 'implied' ) return $object; // Nothing to do
  $tinc = $tincture->firstChild;
  switch ( $tinc->nodeName ) {
    case 'colour':
    case 'default': // don't think these two ever occur
    case 'proper':
      if ( $tinc->hasAttribute('name') ) $spec = rgb($tinc->getAttribute('name'));
      elseif ( $tinc->hasAttribute('spec') ) $spec = $tinc->getAttribute('spec');
      else {
        $spec = '#F0F0F0'; // raise error
        draw_message('internal', 'Colour not known', __FILE__, __LINE__);
      }
      return '<g fill="' . $spec . '">' . $object . '</g>';
      break;
    case 'fur':
      $fur_name = $tinc->getAttribute('name');
      $fur_data = makeFur( $fur_name );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      // Don't need to do reversed as all furs are symmetrical
      if ( $inv ) $fur_data[2] = "<g transform=\"translate(0,{$fur_data[1]}) scale(1,-1)\">{$fur_data[2]}</g>";
      list($bb_width,$bb_height) = explode(',',$bb);
      $pat_rot = '';
      if ( $rot != 0 ) $pat_rot = ' rotate(' . ($rot * -1) . ') ';
      $scale = max ( $bb_width / 1000, $bb_height / 1200 );
      $patt_id = add_def ( 'pattern patternTransform="scale(' . $scale .  ')' . $pat_rot . '"' .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $fur_data[0] . '" height="' . $fur_data[1] . '"',
         $fur_data[2] );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      return $retval;
      break;
    case 'treatment':
      $treat_data = makeTreatment( $tinc );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      // Don't need to do reversed as all furs are symmetrical
      if ( $inv ) $treat_data[2] = "<g transform=\"translate(0,{$treat_data[1]}) scale(1,-1)\">{$treat_data[2]}</g>";
      list($bb_width,$bb_height) = explode(',',$bb);
      $pat_rot = '';
      if ( $rot != 0 ) $pat_rot = ' rotate(' . $rot . ') ';
      $scale = max ( $bb_width / 1000, $bb_height / 1200 );
      $patt_id = add_def ( 'pattern patternTransform="scale(' . $scale .  ')' . $pat_rot . '"' .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $treat_data[0] . '" height="' . $treat_data[1] . '"',
         $treat_data[2] );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      return $retval;
      break;
    case 'semyde':
      $treat_data = makeSemy( $tinc );
      // If what we are placing is inverted, we also invert the fill so it appears the "right way up"
      // Don't need to do reversed as all furs are symmetrical
      if ( $inv ) $treat_data[2] = "<g transform=\"translate(0,{$treat_data[1]}) scale(1,-1)\">{$treat_data[2]}</g>";
      if ( $rev ) $treat_data[2] = "<g transform=\"translate({$treat_data[0]},0) scale(-1,1)\">{$treat_data[2]}</g>";
      if ( is_array( $bb ) ) {
        $keys = array_keys($bb); $key = $keys[0];
        $bb = $bb[$key];
      }
      list($bb_width,$bb_height) = explode(',',$bb);
      $pat_rot = '';
      if ( $rot != 0 ) $pat_rot = ' rotate(' . $rot . ') ';
      $scale = max ( $bb_width / 1000, $bb_height / 1200 );
      $patt_id = add_def ( 'pattern patternTransform="scale(' . $scale .  ')' . $pat_rot . '"' .
         ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="0" y="0" width="' .
         $treat_data[0] . '" height="' . $treat_data[1] . '"',
         $treat_data[2] );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      return $retval;
      break;
    case 'division': // scale to bounding box
      // Only take account of chief if filling an ordinary that does so
      if ( $bb != '1000,1200' ) { // If we are given a bounding box, ignore chief
        chief('push','NC');
        $div_data = makeDivision( $tinc );
        chief('pop');
      } else {
        $div_data = makeDivision( $tinc );
      }
      $parent = $tincture->parentNode;
      if ( $parent->nodeName == 'plain' ) return '<g><title>' . $tinc->getAttribute('subtype') . '</title>' . $div_data . '</g>';
      list($bb_width,$bb_height,$bbX,$bbY) = explode(',', $bb . ',0,0');
      $type = $tinc->getAttribute('subtype');
      $height = ($type == 'per-bend' || $type == 'per-bend-sinister' || $type == 'quarterly') ? 1000 : 1200;
/*      if ( (preg_match ( '/Chrome/' , $_SERVER['HTTP_USER_AGENT'] ) != 0) and $parent->nodeName == 'charge' ) {
        $patt_id = add_def ( 'pattern width="100%" height="100%"',
          '<title>Division</title><desc>' . $tinc->getAttribute('subtype') . '</desc>' .
           '<svg  preserveAspectRatio="none" viewBox="0 0 1000 ' . $height . '" height="' . $bb_height .
           '" width="' . $bb_width . '">' . $div_data . '</svg>' );
      } else { */
        $xScale = $bb_width / 1000; $yScale = $bb_height / $height;
        $patt_id = add_def ( 'pattern patternTransform="scale(' . $xScale . ',' . $yScale .
            ')" patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse"
            x="' . (($bbX % $bb_width)/$xScale) . '" y="' . (($bbY % $bb_height)/$yScale) . '" width="1000" height="' . $height . '"',
             $div_data );
//        $patt_id = add_def ( 'pattern patternUnits="objectBoundingBox" patternContentUnits="objectBoundingBox" x="0" y="0" width="1" height="' . $height . '"',
//             $div_data );
/*      } */
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      return $retval;

      /*
       * // Only take account of chief if filling an ordinary that does so
      if ( $bb != '1000,1200' ) { // If we are given a bounding box, ignore chief
        chief('push','NC');
        $div_data = makeDivision( $tinc );
        chief('pop');
      } else {
        $div_data = makeDivision( $tinc );
      }
      list($width, $height, $data) = $div_data;
      list($bb_width,$bb_height,$bbX,$bbY) = explode(',', $bb . ',0,0');
      $xScale = $bb_width / 1000; $yScale = $bb_height / $height;
      $patt_id = add_def ( 'pattern patternTransform="scale(' . $xScale . ',' . $yScale .
          ')" patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse"
          x="' . (($bbX % $bb_width)/$xScale) . '" y="' . (($bbY % $bb_height)/$yScale) . '" width="' . $width . '" height="' . $height . '"',
          '<title>Division</title><desc>' . $tinc->getAttribute('subtype') . '</desc>' . $data );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval;
      list($bb_width,$bb_height,$bbX,$bbY) = explode(',', $bb . ',0,0');
      $type = $tinc->getAttribute('subtype');
      $height = 1200;
      if ( $bb_height != 1200 and ($type == 'per-bend' || $type == 'per-bend-sinister')) $height = 1000;
      $patt_id = add_def ( 'pattern width="100%" height="100%"',
          '<title>Division</title><desc>' . $tinc->getAttribute('subtype') . '</desc>' .
           '<svg  preserveAspectRatio="none" viewBox="0 0 1000 ' . $height . '" height="' . $bb_height .
           '" width="' . $bb_width . '">' . $div_data . '</svg>' );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval; */
      break;
    case 'counterchanged': // Never change anything, just fill with this pattern
      // First we have to locate the field
      $parent = $tincture->parentNode;
      while ( $parent->nodeName != 'plain' ) { // TODO what about if overall?
        $parent = $parent->parentNode;
      }
      $field = $parent->firstChild;
      // Then confirm that the field is a division
      $field_tinc = $field->firstChild;
      if ( $field_tinc->nodeName != 'division' ) return '<g fill="#050505"><title>Counterchange</title><desc>Not possible</desc>' . $object . '</g>';
      $div_data = makeDivision( $field_tinc, true );
      $pattTrans = '';
      if ( $xscale or $yscale ) {
        $pattTrans = 'patternTransform="scale(' . ( 1 / $xscale) . ',' . (1/ $yscale) . ')"';
      }
      $patt_id = add_def ( 'pattern ' . $pattTrans . ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="' .
          $offsetX . '" y="' . $offsetY . '" width="' . '1000" height="1200"', '<title>Counterchanged</title>' . $div_data );
      $retval = add_def();
      $retval .= '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      return $retval;
      break;
  }
}

function createBody($spec, $lineType, $feature_size) {
  return '<path fill-rule="evenodd" d="' . makePath ( $spec, $lineType, $feature_size ) . '" />';
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
?>