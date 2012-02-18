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
    'chevrons?',
  ), 
  
  'either' => true,
  
  'modifiers' => array (
    array ( null, 'throughout', 'mod', 'throughout' ),
    array ( null, 'couped', 'mod', 'couped' ),
    array ( null, 'inarched', 'mod', 'inarched' ),
    array ( null, '(de)?bruised|fracted|disjoint ?at ?the ?top', 'mod', 'debruised' ),
  ),
  
  'flags' => array (
    'max_num' => 2,
    ),

  'doc' => '',

); // TODO either create 2 of each, or split across separate files, each with its own max_num

include 'ordinaries/common/_compony.inc';


if ( $node != null ) {
  if ( get_mod($node,'throughout') )
    // $ordinary['shape_spec'] = array ( 'NC' => 'V1X500Y0K1200l200M1000L1000m200J1200', 'CH' => 'V1X500Y300K1000l200M800L800m200J1000');
    $ordinary['body'] = array ( 'NC' => '<path fill-rule="evenodd" d="M500,0l600,1039 -100,173 -500,-866 -500,866 -100,-173 600,-1039z" />', 'CH' => '<path fill-rule="evenodd" d="M500,300l600,1039 -100,173 -500,-866 -500,866 -100,-173 600,-1039z" />');
  elseif ( get_mod($node,'fracted') )
    $ordinary['shape_spec'] = array ( 'NC' => 'V1X500Y200B100c282B800d200F600g282f100d100c282D600f200H800g282H100', 'CH' => 'V1X500Y300B100c282B800d200F600g282f100d100c282D600f200H800g282H100');
  elseif ( get_mod($node,'debruised') )
    $ordinary['shape_spec'] = array ( "NC" => 'X-65.6Y1065.6f200H800b200h200B800d200F800D800', 'CH' => 'X-65.6Y1165.6f200H800b200h200B800d200F800D800' );
  elseif ( get_mod($node,'couped') )
    $ordinary['shape_spec'] = array ( "NC" => 'V1X200Y800f200H624B624d200F424D424', "CH" => 'V1X200Y1000f200H624B624d200F424D424' );
  elseif ( get_mod($node,'inarched') )
    $ordinary['body'] = array ( 
                  "NC" => '<path fill-rule="evenodd" d="m 720,900 c 0,300 -100,500 -220,500 -120,0 -220,-200 -220,-500 0,-250 100,-460 220,-460 120,0 220,210 220,460 z m -80,-10 c 0,210 -60,310 -140,310 -80,0 -140,-100 -140,-310 0,-200 60,-350 140,-350 80,0 140,150 140,350 z" />
                  			<path fill-rule="evenodd" d="M-65.6,1065.6l-141.4,-141.4l707,-707l707,707l-141.4,141.4l-565.6,-565.6l-565.6,565.6Z" />', 
                  'CH' => '<path fill-rule="evenodd" d="m 720,1100 c 0,300 -100,500 -220,500 -120,0 -220,-200 -220,-500 0,-250 100,-460 220,-460 120,0 220,210 220,460 z m -80,-10 c 0,210 -60,310 -140,310 -80,0 -140,-100 -140,-310 0,-200 60,-350 140,-350 80,0 140,150 140,350 z" />
                           <path fill-rule="evenodd" d="M-65.6,1215.6l-141.4,-141.4l707,-707l707,707l-141.4,141.4l-565.6,-565.6l-565.6,565.6Z" />' ); 
	else  {
	  if ( $node->getAttribute('number') == '1' )
      $ordinary['shape_spec'] = array ( "NC" => 'V1X500Y500D800f200H1000B1000d200F800', "CH" => 'V1X500Y650D800f200H1000B1000d200F800');
    else
      $ordinary['shape_spec'] = array ( "NC" => 'V1X500Y400D800f200H1000B1000d200F800     V1X500Y600D800f200H1000B1000d200F800', "CH" => 'V1X500Y650D800f200H1000B1000d200F800');
	  $compony = get_mod($node,'compony');
	  if ( $compony == 'single' )
			$ordinary['body2'] = array ( 'NC' => '<path d="M 957,542 672,828 797,953 1080,668 z M 45,542 331,828 205,953 -80,668 z M 296,292 171,417 456,702 501,657 546,702 832,417 706,292 501,497 296,292 z" />',
			                              'CH' => '<path d="M 957,692 672,978 797,1100 1080,818 z M 45,692 331,978 205,1100 -80,818 z M 296,442 171,567 456,852 501,807 546,852 832,567 706,442 501,647 z" />' );
		elseif ( $compony == 'double' )
		   $ordinary['body2'] = array ( 'NC' => '<path d="M 941,810 1070,684 1190,810 1070,935 941,810 M 815,684 690,810 815,935 941,810 z M 690,559 815,434 941,559 815,684 690,559 M 62.7,810 -62.7,684 -188,810 -62.7,935 z M 188,684 314,810 188,935 62.7,810 188,684 M 314,559 188,434 62.7,559 188,684 z M 439,434 502,496 564,434 690,559 502,747 314,559 439,434 m 0,0 L 314,308 502,120 690,308 564,434 502,371 z" />',
			                              'CH' => '<path d="M 941,960 1070,834 1190,960 1070,1090 941,960 M 815,834 690,960 815,1090 941,960 z M 690,709 815,584 941,709 815,834 690,709 M 62.7,960 -62.7,834 -188,960 -62.7,1090 z M 188,834 314,960 188,1090 62.7,960 188,834 M 314,709 188,584 62.7,709 188,834 z M 439,584 502,646 564,584 690,709 502,897 314,709 439,584 m 0,0 L 314,458 502,270 690,458 564,584 502,521 z" />');
		
	  if ( division_to_modifier($node, 'quarterly') )
		  $ordinary['body2'] = array ( 'NC' => 'V1X500Y100C259D848g259h848   V1X1100Y958c259f849G259B849',
																		'CH' => 'V1X500Y250C259D848g259h848   V1X1100Y1108c259f849G259B849' );
	}             			 
}

?>
