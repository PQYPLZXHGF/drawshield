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

// Astronomy

$charge = array (

  'patterns' => array (
  '?astronomical characters? ?of ?the ?planet ',
  ),
  
  'flags' => array (
    'default_colour' => 'sable',
    'get_item' => 1,
  ),

  'file' => 'inkscape/astron-sun.svg', // overridden in use
  
  'proper' => rgb('sable'),
  'orient_to_ordinary' => true,

);


if ( $node != null ) {
  $item = get_mod( $node, 'item' );
  if ( file_exists( 'charges/' . $node->getAttribute('type') . "/inkscape/astron-$item.svg" ))
    $charge['file'] = "inkscape/astron-$item.svg";
  else
    draw_message('warning',"unknown astronomical symbol $item");
}

?>
