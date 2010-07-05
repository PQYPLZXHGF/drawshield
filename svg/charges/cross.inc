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


function makeChg_cross ( $node ) {
  $cross_data = array (
    'cross' => array ( 'height' => 200, 'width' => 150,
        'body' => '<polygon stroke="#000000" stroke-width="4" points="0,50 50,50 50,0 100,0 100,50 150,50 150,100 100,100 100,200 50,200 50,100 0,100"  />', ),
    'crosslet' => array ( 'height' => 400, 'width' => 400,
        'body' => '<polygon points="170,0 230,0 230,170 400,170 400,230 230,230 230,400 170,400 170,230 0,230 0,170 170 170" />', ),
/*    'cross-fitchy' => array ( 'height' => 200, 'width' => 150,
        'body' => '<polygon stroke="#000000" stroke-width="4" points="0,50 50,50 50,0 100,0 100,50 150,50 150,100 100,100 100,200 50,200 50,100 0,100"  />', ),
    'crosslet-fitchy' => array ( 'height' => 400, 'width' => 400,
        'body' => '<polygon points="170,0 230,0 230,170 400,170 400,230 230,230 230,325 200,400 170,325 170,230 0,230 0,170 170 170" />', ), */
    'long' => array ( 'height' => 400, 'width' => 200,
        'body' => '<path d="M75,0h50v100h75v50h-75v250h-50v-250h-75v-50h75z" stroke="#000000" stroke-width="4" />' ),
    'calvary' => array ( 'height' => 400, 'width' => 200, 'mountable' => true,
        'body' => '<path d="M{START},0h25v100h75v50h-75v250h-50v-250h-75v-50h75v-100z" stroke="#000000" stroke-width="4" />'),
    'patriarchal' => array ( 'height' => 400, 'width' => 240, 'mountable' => true,
        'body' => '<path d="M{START},0h20v50h50v40h-50v50h100v40h-100v250h-40v-250h-100v-40h100v-50h-50v-40h50v-50z" stroke="#000000" stroke-width="4" />'),
    'tau' => array ( 'height' => 400, 'width' => 300,
        'body' => '<path d="M0,0L50,25 250,25 300,0 300,100 250,75 175,75 175,350 200,400 100,400 125,350 125,75 50,75 0 100Z" stroke="#000000" stroke-width="4" />' ),
  );
  $type = $node->get_attribute('subtype');
  $num = 0;
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->node_name() == 'modifier'  and $child->get_attribute('name') == 'mounted' ) $num = $child->get_attribute('param');
  }
  if ( isset($cross_data[$type]) ) {
    $retval = $cross_data[$type];
    if ( array_key_exists('mountable', $retval) )  {
      if ( $num )  {
        $width = max ( $retval['width'], 60 + ($num * 30) );
        $height = $retval['height'] + 30 * $num;
        $retval['body'] = preg_replace( '/{START}/', ($width / 2), $retval['body']);
        for ( $count = 0; $count < $num; $count++ ) {
          $inc = $count * 30;
          $len = 90 + $inc + $inc;
          $ypos = $retval['height'] + $inc;
          $xpos = ($width - $len)/2;
          $retval['body'] .= '<rect x="' . $xpos . '" y="' . $ypos .'" width="' . $len . '" height="30" stroke="#000000" stroke-width="3" />' . "\n";
        }
        $retval['width'] = $width;
        $retval['height'] = $height;
      } else {
        $retval['body'] = preg_replace( '/{START}/', ($retval['width'] / 2), $retval['body']);
      }
    }
    return $retval;
  } else {
    my_trigger_error ( "No cross $type", E_USER_WARNING, __FILE__, __LINE__ );
    return null;
  }
}
?>
