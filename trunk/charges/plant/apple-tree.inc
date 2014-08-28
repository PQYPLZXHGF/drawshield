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
'file' => 'inkscape/apple-tree.svg',
'patterns' => array (
  0 => 'apple trees?',
),
'modifiers' => array (
  0 => 
  array (
    0 => 'leaved',
    1 => 'leave(d|s)?',
    2 => 'feature',
  ),
  1 => 
  array (
    0 => 'fructed',
    1 => 'fructed',
    2 => 'feature',
  ),
  2 => 
  array (
    0 => NULL,
    1 => 'eradicated',
    2 => 'ignore',
  ),
),
'proper' => rgb('brunatre'),
);
