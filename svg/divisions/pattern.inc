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

function makeDiv_pattern( $node, $div_num ) {

  $div_data = array (
    'fusily' => array ( 166.67, 600, 'v600l83.3,-300z m166.67,0v600l-83.3,-300z' ),
    'fusily-bendy' => array ( 800, 800, 'm-200,200 l300,100 100,300 -300,-100z m200,-200l300,100 100,300 -300,-100z m200,-200l300,100 100,300 -300,-100z m400,400l300,100 100,300 -300,-100z m-200,200l300,100 100,300 -300,-100z m-200,200l300,100 100,300 -300,-100z' ),
    'fusily-bendy-sinister' => array ( 800, 800, 'm200,200l100,-300 300,-100 -100,300z m200,200l100,-300 300,-100 -100,300z m200,200l100,-300 300,-100 -100,300z m-400,400l100,-300 300,-100 -100,300z m-200,-200l100,-300 300,-100 -100,300z m-200,-200l100,-300 300,-100 -100,300z' ),
    'lozengy' => array( 166.67, 300, 'v300l83.33,-150zm166.67,0v300l-83.33,-150z'), 
    'barry-bendy' => array ( 250, 500, 'l67.5,125h125l-67.5,-125z m0,125v125h125l-62.5,-125z m187.5,0l62.5,125v-125z m0,250h62.5v-125h-125z m-125,0l-62.5,-125v125z l62.5,125h125l-62.5,-125z' ),
    'barry-bendy-sinister' => array ( 250, 500, 'm62.5,125h125l62.5,-125h-125z h-62.5v125z m125,0h62.5v125h-125z m-125,250h-62.5v-125h125z h125l-62.5,125h-125z m125,0h62.5v-125z' ),
    'barry-indented-oio' => array ( 250, 433, 'm0,216.5h250l-125,-216.5z v216.5h125z m250,0v216.5h-125z' ),
  );

  $name = $node->get_attribute('subtype');
  $retval = '';
  if ( $div_num != 2 ) return $retval;

  if ( isset($div_data[$name]) ) {
    $retval = '<path d="';
    list($width, $height, $pattern) = $div_data[$name];
    for ( $y = 0; $y < 1200; $y += $height ) {
      for ( $x = 0; $x < 1000; $x += $width ) {
        $retval .= "M$x,$y $pattern ";
      }
    }
    $retval .= '" />';
  }
  return $retval;
}


?>
