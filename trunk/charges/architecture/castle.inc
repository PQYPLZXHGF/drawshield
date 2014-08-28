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
'file' => 'inkscape/castle.svg',
  'link' => 'http://karlwilcox.com/parker/c/castle',
'patterns' => array (
  0 => 'castles?',
),
'modifiers' => array (
  0 => 
  array (
    0 => '3',
    1 => 'triple towered',
    2 => 'mod',
    3 => 'towers',
  ),
),
);

if ( $node != null ) {
  if ( get_mod($node, 'towers'))
    $charge['file'] = 'inkscape/tower-triple.svg';
}