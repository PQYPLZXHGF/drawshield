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
	 
function get_div_height ( $node ) {
	// TODO rewrite this, possibly as full rewrite of divisions to match charges and ordinaries
	// it relies on exact knowledge of internal division name
  $subtype = $node->getAttribute('subtype');
	if ( in_array($subtype,array('per-bend', 'per-bend-sinister', 'gyronny', 'quarterly', 'per-saltire', 'per-chevron')))
		return 1000;
	else
	  return 1200;
 }

function makeDivision( $node, $counter = false ) {

  $type = $node->getAttribute('type');
  $subtype = $node->getAttribute('subtype');
  $div_func = 'makeDiv_' . $type;
  if ( ! function_exists($div_func) ) {
    require_once ( 'svg/divisions/' . $type . '.inc' );
  }
  if ( ! function_exists($div_func) ) {
    draw_message('internal', 'Cannot draw division' . $subtype, __FILE__, __LINE__ );
    return '<g />';
  }
  // Collect the required shapes
  $line_type = get_mod($node, 'linetype');
  $children = $node->childNodes;
  $secondDiv = null;
  $tinctures = array();
  foreach ( $children as $child ) {
    if ( $child->nodeName == 'tincture' )
      $tinctures[$child->getAttribute('index')] = $child;
    elseif ( $child->nodeName == 'division' )
      $secondDiv = $child;
  }
  $div2 = choose_fit($div_func( $node, 2 ));
  $div3 = choose_fit($div_func( $node, 3 ));
  if ( $div2{0} != '<' ) $div2 = createBody( $div2, $line_type, 60 );
  if ( ($div3 != '') and ($div3{0} != '<') ) $div3 = createBody( $div3, $line_type, 60 );
  if ( $counter and $div3 ) {
    draw_message('blazon', 'Cannot counterchange 3 tinctures' );
    return '<g />';
  }
  // set the main colours
  if ( $tinctures[2]->getAttribute('origin') == 'implied' ) { // This is a 2nd division
    $div1 = '';
    $div2 = apply_tincture( $tinctures[1], $div2 );
  } else {
    if ( $counter ) {
      $div1 = apply_tincture ( $tinctures[2], '<rect x="0" y="0" width="1000" height="1200" />',
                                '1000,1200' );
      $div2 = apply_tincture( $tinctures[1], $div2 );
    } else {
      $div1 = apply_tincture ( $tinctures[1], '<rect x="-100" y="-100" width="1200" height="1400" />',
                                '1000,1200' );
      $div2 = apply_tincture( $tinctures[2], $div2 );
      if ( $div3 != null ) $div3 = apply_tincture( $tinctures[3], $div3 );
    }
  }
  $retval = "$div1\n$div2\n$div3\n";
  if ( !$counter and $secondDiv ) {
    $retval .= makeDivision( $secondDiv );
  }
  return $retval;
}

?>