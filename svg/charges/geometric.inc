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


function makeChg_geometric( $node ) {
  $geom_data = array (
    'bbox' => array ( 'width' => 100, 'height' => 100,
        'body' => '<path fill-rule="evenodd" d="M0,0h100v100h-100zM15,15h70v70h-70z" />
                  <text x="50" y="65" font-size="30" text-anchor="middle">^UP^</text>', 'wflex' => 999, 'hflex' => 999 ),
    'billet' => array ( 'width' => 250, 'height' => 500, 'wflex' => 1.0, 'hflex' => 2.0,
        'body' => '<rect height="500" width="250" rx="20" ry="20" />
        			<path stroke="none" fill="#4D4D4D" opacity="0.5" d="M 250.9,59.9 C 235.2,182.7 227.3,453 22.29,501 c -10,-2 201.41,3 210.71,1 9.3,-2 19.3,-6 19.3,-19 0,-12 -0.7,-422.4 -1.4,-423.1 z" />' ),
    'cartouche' => array ( 'width' => 100, 'height' => 400,  'wflex' => 1.5, 'hflex' => 2,
        'body' => '<rect x="0" y="0" height="400" width="100" rx="50" ry="50" />' ),
//    'chevron' => array ( 'width' => 400, 'height' => 200, 'wflex' => 2, 'hflex' => 2,
 //       'body' => '<polygon points="0,200 200,0 400,200 320,200 200,80 80,200" />' ),
    'chevron-sinister' => array ( 'width' => 200, 'height' => 400, 'wflex' => 2, 'hflex' => 2,
        'body' => '<polygon points="0,200 120,0 200,0 80,200 200,400 120,400" />' ),
    'chevron-dexter' => array ( 'width' => 200, 'height' => 400, 'wflex' => 2, 'hflex' => 2,
        'body' => '<polygon points="0,0 80,0 200,200 80,400 0,400 120,200" />' ),
    'crescent' => array ( 'width' => 400, 'height' => 400,  'wflex' => 2, 'hflex' => 2,
        'body' => '<path stroke="#000000" stroke-width="6" d="M 400,200 C 400,310 310,400 200,400 90,400 0,310 0,200 0,150 71,9.9 130,8.8 46,110 150,150 200,150 260,150 350,94 270,8.8 340,11 400,140 400,200" />
                   <path stroke="#000000" stroke-width="6" fill="none" d="M 130,8.8 C 71,9.9 28,130 50,200 c 18,60 90,90 150,90 60,0 130,-40 150,-90 C 370,130 340,11 270,8.8" />', ),
    'delf' => array ( 'width' => 100, 'height' => 100,
        'body' => '<polygon points="0,0 100,0 100,100, 0,100" />' ),
    'escutcheon' => array ( 'width' => 600, 'height' => 800,
        'body' => '<path d="m 0,0 600,0 0,600 c 1,22 -5,45 -18,67 -14,21 -35,41 -62,59 -27,18 -60,34 -97,47 -38,12 -79,21 -123,27 C 256,794 215,785 177,773 140,760 107,744 79.8,726 52.8,708 31.9,688 18.4,667 4.82,645 -1.42,622 0,600 L 0,0 z" />', ),
    'goutte' => array ( 'width' => 150, 'height' => 400, 'wflex' => 1.5, 'hflex' => 1.5,
        'body' => '<path d="M 77.85,2.14 C 71.42,144.28 43.57,70.0 27.14,155.71 C 21.05,187.47 1.56,348.11 32.85,376.42 C 55.55,396.96 109.57,425.22 138.57,345 C 152.31,306.97 114.28,244.9 96.42,222.85 C 85.77,209.64 55.71,172.14 91.42,114.28 C 105.37,91.69 110.05,90.05 112.14,44.28 C 113.59,12.58 77.85,2.14 77.85,2.14 z" />' ),
    'lozenge' => array ( 'width' => 400, 'height' => 500, 'hflex' => 1.2, 'wflex' => 1.2,
        'body' => '<polygon points="0,250 200,500 400,250 200,0" />' ),
 //   'rustre' => array ( 'width' => 400, 'height' => 500,
   //     'body' => '<path fill-rule="evenodd" d="M0,250 L 200,500 400,250 200,0Z M 170,250 A 30 30 0,1 1 230,220 A 30 30 0,1 1 170 250" />' ),
    'fusil' => array ( 'width' => 200, 'height' => 400, 'wflex' => 1.2, 'hflex' => 2,
        'body' => '<polygon points="0,200 100,400 200,200 100,0" />' ),
    'mascle' => array ( 'width' => 200, 'height' => 500, 'wflex' => 1.5, 'hflex' => 1.5,
        'body' => '<path d="M 100,0 200,250 100,500 0,250 100,0 z M 100,75.1 168,250 100,425 31.7,250 100,75.1 z" fill-rule="evenodd" />' ),
    'saltorel' => array ( 'width' => 520, 'height' => 603,
        'body' => '<path d="M 518,150 455,87 3,540 66,603 518,150 z M 65,86 2,150 455,602 518,539 65,86 z" />' ),
    'roundel' => array ( 'width' => 500, 'height' => 500, 'body' => '<circle cx="250" cy="250" r="250" />' ),
    'fret' => array ( 'width' => 370, 'height' => 370, 'body' => '<path d="m 212,248 -18,19 -9,9 -91,-91 28,-27 18,18 -9,9 54,54 9,-9 18,18 z m -36,-108 -18,-18 27,-28 91,91 -28,27 -18,-18 9,-9 -54,-54 -9,9 z M 19.7,2 176,158 158,176 1.6,20 19.7,2 z M 212,194 371,351 351,371 194,212 212,194 z m -18,-36 18,18 -36,36 -18,-18 36,-36 z m -72,72 18,18 L 19.6,367 1.5,351 122,230 z M 351,1 367,20 248,140 230,122 351,1 z" />' ),
    'triangle' => array ( 'width' => 100, 'height' => 66, 'body' => '<path d="M0,66 L50,0 100,66z" />', ),
    'triangle-voided' => array ( 'width' => 100, 'height' => 66, 'body' => '<path fill-rule="evenodd" d="M15,59 L50,12 85,59z M0,66 L50,0 100,66z" />', ),
  );
  $name = $node->get_attribute('subtype');
  $retval = null;
  if ( isset($geom_data[$name]) ) {
      $retval = $geom_data[$name];
      $retval['orient_to_ordinary'] = true;
  } else {
    my_trigger_error ( "No charge $name", E_USER_WARNING, __FILE__, __LINE__ );
  }
  return $retval;
}
?>
