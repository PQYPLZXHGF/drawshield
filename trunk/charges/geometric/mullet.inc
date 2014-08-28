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
'file' => 'inkscape/mullet.svg',
  'link' => 'http://karlwilcox.com/parker/m/mullet',
'patterns' => array (
  0 => 'm(o|u)ll?ets?',
),
'modifiers' => array (
  0 => 
  array (
    0 => NULL,
    1 => '(pierced|voided)',
    2 => 'mod',
    3 => 'pierced',
  ),
  1 => 
  array (
    0 => 5,
    1 => '(of|de) # ?points',
    2 => 'mod',
    3 => 'points',
  ),
),
);
