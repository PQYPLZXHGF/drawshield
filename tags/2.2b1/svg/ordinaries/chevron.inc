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


function makeOrd_chevron($node) {
  $ord_data = array (
  'chevron' => array ( 
        'bounding_box' => array ( 'NC' => '1000,800,0,200', 'CH' => '1000,800,0,400' ),
        'shape_spec' => array ( "NC" => 'X-65.6Y1065.6f200H>1000B<1000d200F800D800', "CH" => 'X-65.6Y1215.6f200H1000B1000d200Q800D800') ,),
  'chevron-throughout' => array ( 'shape_spec' => array ( 'NC' => 'X500Y0K1200l200M1000L1000m200J1200', 'CH' => 'X500Y300K1000l200M800L800m200J1000')),
  'chevron-rompu' => array ( 'shape_spec' => array ( 'NC' => 'X500Y200B100c282B800d200Q600g282f100d100c282D600f200H800g282H100', 'CH' => 'X500Y300B100c282B800d200Q600g282f100d100c282D600f200H800g282H100'),
        'bounding_box' => '1000,900,0,200',),
  'chevron-debruised' => array ( 'shape_spec' =>  array ( "NC" => 'X-65.6Y1065.6f200H800b200h200B800d200Q800D800', 'CH' => 'X-65.6Y1165.6f200H800b200h200B800d200Q800D800' ),
        'bounding_box' => '1000,600,0,350',),
  'chevron-couped' => array ( 'shape_spec' => array ( "NC" => 'X200Y800f200H624B624d200Q424D424', "CH" => 'X200Y1000f200H624B624d200Q424D424' ),
        'bounding_box' => array ( "NC" => '1000,600,0,350', "CH" => '1000,600,0,550'),),
  'chevron-couched' => array ( 'shape_spec' => array ( "NC" =>  'X0Y-100B700D700f200H500Q500h200', "CH" =>  'X0Y200B700D700f200H500Q500h200' ),
        'bounding_box' => array ( "NC" => '500,1000,0,0', 'CH' => '500,1000,0,200' ), ),
  'chevron-inarched' => array ( 'body' => array ( 
                  "NC" => '<path fill-rule="evenodd" d="m 720,900 c 0,300 -100,500 -220,500 -120,0 -220,-200 -220,-500 0,-250 100,-460 220,-460 120,0 220,210 220,460 z m -80,-10 c 0,210 -60,310 -140,310 -80,0 -140,-100 -140,-310 0,-200 60,-350 140,-350 80,0 140,150 140,350 z" />
                  			<path fill-rule="evenodd" d="M-65.6,1065.6l-141.4,-141.4l707,-707l707,707l-141.4,141.4l-565.6,-565.6l-565.6,565.6Z" />', 
                  'CH' => '<path fill-rule="evenodd" d="m 720,1100 c 0,300 -100,500 -220,500 -120,0 -220,-200 -220,-500 0,-250 100,-460 220,-460 120,0 220,210 220,460 z m -80,-10 c 0,210 -60,310 -140,310 -80,0 -140,-100 -140,-310 0,-200 60,-350 140,-350 80,0 140,150 140,350 z" />
                           <path fill-rule="evenodd" d="M-65.6,1215.6l-141.4,-141.4l707,-707l707,707l-141.4,141.4l-565.6,-565.6l-565.6,565.6Z" />' ),), 
                  			 
  );

  $name = $node->get_attribute('subtype');
  if ( isset($ord_data[$name]) ) {
    if ( is_array($ord_data[$name]) ) {
      return $ord_data[$name];
    } else {
      return array ( 'body' => $ord_data[$name] );
    }
  } else {
    my_trigger_error ( "No chevron $name", E_USER_WARNING, __FILE__, __LINE__ );
    return array ( 'body' => '<g/>');
  }
}
?>
