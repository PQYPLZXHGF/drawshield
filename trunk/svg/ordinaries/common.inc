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


function makeOrd_common($node) {
  $ord_data = array (
  'octogon' => array ( 'shape_spec' => 'X200Y400h200B500d200F500' ),
  'square' => array ( 'shape_spec' => 'X200Y500A200O200,200,0,200,-200G100A200C500E600G200', 'bounding_box' => '600,500,200,200', ),
  'diamond' => array ( 'shape_spec' => 'X200Y200a600c200D424F424g200' ),
  'gore' => array ( 'shape_spec' => 'X-200Y-400a200d100O650,950,-30,300,950b60d60O350,650,-30,150,700b100e650g1876', ),
  'quarter' => array ( 'shape_spec' => array ( 'NC' => 'X-100Y500g600a600C600E600', 'CH' =>  'X-100Y700g500a600C500E600'),
        'bounding_box' => array ( 'NC' => '500,500', 'CH' => '500,400,0,300' )),
  'saltire' => array ( 'shape_spec' => array ( 'NC' => 'X-100Y-241B848H848b200D848B848d200F848D848f200H848F848h200', 'CH' => 'X-100Y0B848H848b200D848B848d200F848D848f200H848F848h200' ),), 
  'fret-couped' => array ( 'body' => array ( 'NC' => '<path d="m 698,415 57,57 28,28 -283,283 -85,-85 57,-57 28,29 170,-170 -29,-28 57,-57 z m -339,113 -57,57 -85,-85 283,-283 85,85 -57,57 -28,-29 -170,170 29,28 z M 118,825 415,528 471,585 175,882 118,825 z M 528,415 825,118 882,175 585,472 528,415 z M 415,472 472,415 585,528 528,585 415,472 z M 641,698 698,641 884,827 827,884 641,698 z M 118,175 175,118 358,302 302,358 118,175 z" />',
                  'CH' => '<path d="m 698,615 57,57 28,28 -283,283 -85,-85 57,-57 28,29 170,-170 -29,-28 57,-57 z m -339,113 -57,57 -85,-85 283,-283 85,85 -57,57 -28,-29 -170,170 29,28 z m -241,302 297,-302 56,57 -296,295 -57,-50 z M 528,615 825,318 882,375 585,672 528,615 z m -113,57 57,-57 113,113 -57,57 -113,-113 z m 226,226 57,-57 186,189 -57,50 L 641,898 z M 118,375 175,318 358,502 302,558 118,375 z" />')),
  'grid' => '<polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" />
             <g transform="translate(100,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(200,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(300,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(400,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(500,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(600,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(700,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(800,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /><polygon points="98,0 102,0 102,1200 98,1200" /></g>
             <g transform="translate(900,0)"><polygon points="49.5,0 50.5,0 50.5,1200 49.5,1200" /></g>
             <path d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,100)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,200)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,300)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,400)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,500)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,600)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,700)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,800)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,900)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,1000)" d="M0,49.5h1000v1h-1000z M0,98h1000v4h-1000z" />
             <path transform="translate(0,1100)" d="M0,49.5h1000v1h-1000z" />
             ',
  );
  $name = $node->get_attribute('subtype');

  if ( isset($ord_data[$name]) ) {
    if ( is_array($ord_data[$name]) ) {
      $retval = $ord_data[$name];
    } else {
      $retval = array ( 'body' => $ord_data[$name] );
    }
  } else {
    my_trigger_error ( "No ordinary $name", E_USER_WARNING, __FILE__, __LINE__ );
    $retval = array ( 'body' => '<g/>');
  }
  return $retval;
}


?>
