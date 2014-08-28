<?php
/**
 * Drawshield PHP Source File
 *
 * Description...
 *
 * @author Karl R. Wilcox <karl@karlwilcox.com>
 * @copyright Karl R. Wilcox 2014
 * @license http://www.apache.org/licenses/LICENSE-2.0
 * Date: 12/08/14
 * Time: 18:50
 */

$charge = array(
'file' => 'inkscape/sun.svg',
  'link' => 'http://karlwilcox.com/parker/s/sun',
'patterns' => array (
  0 => 'suns?',
),
'modifiers' => array (
  0 => 
  array (
    0 => NULL,
    1 => '?in ?his glory',
    2 => 'ignore',
  ),
  1 => 
  array (
    0 => NULL,
    1 => 'in ?his splendou?r',
    2 => 'ignore',
  ),
),
'proper' => rgb('or'),
);

if ( $node != null ) {

if ( get_mod($node, 'on')) {
  $charge['body'] = '<path
       d="m 203,2 15,121 C 251,94.7 266,45.4 265,12.1 303,45.4 253,111 239,129 236,134 340,64.6 340,64.6 L 274,158 c 23,-13 69,-11 102,-47 -8,61 -78,41 -88,80 l 112,14 -116,19 c 48,15 61,47 102,46 -27,30 -88,-27 -108,-23 l 63,96 -89,-71 c -5,20 3,59 42,108 -81,-28 -44,-91 -69,-94 -1,12 -21,115 -21,115 L 186,286 c -29,29 -36,51 -43,104 -26,-69 25,-102 12,-119 L 60.6,346 127,257 C 74.5,271 68.7,253 21.2,290 42.5,243 95.8,249 112,232 L -4.04,207 112,182 C 61.5,165 60.6,137 8.08,140 38.4,111 72.6,136 121,162 134,169 58.6,58.6 58.6,58.6 L 154,130 C 155,68 141,37.9 112,23.2 155,2.03 177,88.7 181,121 187,122 203,2 203,2 z"
       stroke="inherit" stroke-width="4" />';
}
}
