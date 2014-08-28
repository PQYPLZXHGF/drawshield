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

$charge = array ( 
  'patterns' => array (
  'lions? heads?',
  'leopards? heads?'
  ),
  'modifiers' => array (
    /* Features */
    array ( 'armed', 'armed', 'feature' ),
    array ( 'langued', 'langued', 'feature' ),
    array ( 'crowned', 'crowned', 'feature' ),
    /* facing direction */
    array ( 'guardant', 'guardant', 'mod', 'head-pos' ),
    array ( 'reguardant', 'reguardant', 'mod', 'head-pos' ),
  ),

  'file' => 'inkscape/lion-head.svg',
);

if ($node != null ) {
    /* Try to get the most specific lion */
	$head_pos = (get_mod($node, 'head-pos'));
    if ( $head_pos  == "guardant" )
      $charge['file'] = "inkscape/lion-head-guardant.svg";
    elseif ( $head_pos == 'reguardant')
      $charge['file'] = "inkscape/lion-head-reguardant.svg";
    elseif ( has_feature($node, 'crowned' ))
		$charge['file'] = 'inkscape/lion-head-crowned.svg';
  }


