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

  $bb = choose_fit($bb);
  $tinc = $tincture->first_child();
  switch ( $tinc->node_name() ) {
    case 'implied':
      return $object;
      break;
    case 'colour':
    case 'proper':
      if ( $tinc->has_attribute('name') ) $spec = rgb($tinc->get_attribute('name'));
      elseif ( $tinc->has_attribute('spec') ) $spec = $tinc->get_attribute('spec');
      else {
        $spec = '#F0F0F0'; // raise error
        my_trigger_error('Colour not known', E_SVG);
      }
      return '<g fill="' . $spec . '"><title>Colour</title><desc>' . $tinc->get_attribute('name') . '</desc>' . $object . '</g>';
      break;
    case 'fur':
      $fur_name = $tinc->get_attribute('name');
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
         '<title>Fur</title><desc>' . $fur_name . '</desc>' .  $fur_data[2] );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval;
      break;
    case 'treatment':
      $treat_name = $tinc->get_attribute('name');
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
         '<title>Treatment</title><desc>' . $treat_name . '</desc>' .  $treat_data[2] );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval;
      break;
    case 'semyde':
      $treat_name = $tinc->get_attribute('name');
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
         '<title>Treatment</title><desc>' . $treat_name . '</desc>' .  $treat_data[2] );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
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
      $parent = $tincture->parent_node();
      if ( $parent->node_name() == 'plain' ) return $div_data;
      list($bb_width,$bb_height,$bbX,$bbY) = explode(',', $bb . ',0,0');
      $type = $tinc->get_attribute('subtype');
      $height = ($type == 'per-bend' || $type == 'per-bend-sinister') ? 1000 : 1200;
      if ( preg_match ( '/Firefox/' , $_SERVER['HTTP_USER_AGENT'] ) != 0 ) {
        $xScale = $bb_width / 1000; $yScale = $bb_height / $height;
        $patt_id = add_def ( 'pattern patternTransform="scale(' . $xScale . ',' . $yScale .
            ')" patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse"
            x="' . (($bbX % $bb_width)/$xScale) . '" y="' . (($bbY % $bb_height)/$yScale) . '" width="' . $width . '" height="' . $height . '"',
            '<title>Division</title><desc>' . $tinc->get_attribute('subtype') . '</desc>' . $div_data );
      } else {
        $patt_id = add_def ( 'pattern width="100%" height="100%"', 
          '<title>Division</title><desc>' . $tinc->get_attribute('subtype') . '</desc>' .
           '<svg  preserveAspectRatio="none" viewBox="0 0 1000 ' . $height . '" height="' . $bb_height . 
           '" width="' . $bb_width . '">' . $div_data . '</svg>' );
      }
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
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
          '<title>Division</title><desc>' . $tinc->get_attribute('subtype') . '</desc>' . $data );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval;
      list($bb_width,$bb_height,$bbX,$bbY) = explode(',', $bb . ',0,0');
      $type = $tinc->get_attribute('subtype');
      $height = 1200;
      if ( $bb_height != 1200 and ($type == 'per-bend' || $type == 'per-bend-sinister')) $height = 1000;
      $patt_id = add_def ( 'pattern width="100%" height="100%"', 
          '<title>Division</title><desc>' . $tinc->get_attribute('subtype') . '</desc>' .
           '<svg  preserveAspectRatio="none" viewBox="0 0 1000 ' . $height . '" height="' . $bb_height . 
           '" width="' . $bb_width . '">' . $div_data . '</svg>' );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval; */
      break;
    case 'counterchanged': // Never change anything, just fill with this pattern
      // First we have to locate the field
      $parent = $tincture->parent_node();
      while ( $parent->node_name() != 'plain' ) { // TODO what about if overall?
        $parent = $parent->parent_node();
      }
      $field = $parent->first_child();
      // Then confirm that the field is a division
      $field_tinc = $field->first_child();
      if ( $field_tinc->node_name() != 'division' ) return '<g fill="#050505"><title>Counterchange</title><desc>Not possible</desc>' . $object . '</g>';
      $div_data = makeDivision( $field_tinc, true );
      list($width, $height, $data) = $div_data;
      $pattTrans = '';
      if ( $xscale or $yscale ) {
        $pattTrans = 'patternTransform="scale(' . ( 1 / $xscale) . ',' . (1/ $yscale) . ')"';
      }
      $patt_id = add_def ( 'pattern ' . $pattTrans . ' patternContentUnits="userSpaceOnUse" patternUnits="userSpaceOnUse" x="' .
          $offsetX . '" y="' . $offsetY . '" width="' . '1000" height="1200"', '<title>Colour</title><desc>counterchanged</desc>' . $data );
      $retval = '<g fill="url(#' . $patt_id . ')"  >' . $object . '</g>';
      $retval .= add_def();
      return $retval;
      break;
  }
}

function createBody($spec, $pathLine, $feature_size) {
  return '<path fill-rule="evenodd" d="' . makePath ( $spec, $pathLine, $feature_size ) . '" />';
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
  my_trigger_error('Cannot find placement for region', E_SVG);
  return null;
}
?>
