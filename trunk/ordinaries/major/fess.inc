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

$ordinary = array (
  'patterns' => array (
    'fesse?',
  ), 

  'doc' => '',

);

  include 'ordinaries/common/_couped.inc';
  include 'ordinaries/common/_compony.inc';
  include 'ordinaries/common/_lozengy.inc';

if ( $node != null ) {
  $couped = get_mod($node,'couped');
  $compony = get_mod($node,'compony');
  
	// Set basic body shape
  if ( $couped == 'both' ) {
		$ordinary['shape_spec'] = 'X100Y350A800c300E800g300';
	}
  elseif ( $couped == 'dexter') {
		$ordinary['shape_spec'] = 'X-8Y350A908c300E908g300';
	}
  elseif ( $couped == 'sinister') {
		$ordinary['shape_spec'] = 'X100Y350A908c300E908g300';
	}
  elseif ( get_mod($node,'lozengy')) {
		$ordinary['body'] = '<path d="M0,350l83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 83.3,150 83.3,-150 v300 l-83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 -83.3,-150 -83.3,150 " />';
	}
  else {
    $ordinary['shape_spec'] = 'X-8Y350A1016c300E1016g300';
	}
	
	// Add extra layer if compony
  if ( $compony == 'single' )
    $ordinary['body2'] = '<path d="M0,300h250v400h-250z M500,300h250v400h-250z" />';
  elseif ( $compony == 'double' )
    $ordinary['body2'] = '<path d="M0,300h250v200h-250z M250,500h250v200h-250z M500,300h250v200h-250z M750,500h250v200h-250z" />';
    
}

?>