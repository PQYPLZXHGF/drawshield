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
'file' => 'inkscape/ship.svg',
  'link' => 'http://karlwilcox.com/parker/s/ship',
'patterns' => array (
  0 => '?(3|three) ?masted (ship|galley)s?',
),
'modifiers' => array (
  0 => 
  array (
    0 => 'pennants',
    1 => '?with pennants',
    2 => 'feature',
  ),
  1 => 
  array (
    0 => 'sails',
    1 => '?with sails',
    2 => 'feature',
  ),
  2 => 
  array (
    0 => NULL,
    1 => 'of # masts',
    2 => 'mod',
    3 => 'masted',
  ),
  3 => 
  array (
    0 => NULL,
    1 => 'at anchor',
    2 => 'mod',
    3 => 'anchored',
  ),
  4 => 
  array (
    0 => NULL,
    1 => 'in full sail',
    2 => 'mod',
    3 => 'fullsail',
  ),
  5 => 
  array (
    0 => NULL,
    1 => '?(her|the) sails set',
    2 => 'mod',
    3 => 'fullsail',
  ),
  6 => 
  array (
    0 => NULL,
    1 => '?(her|the) sails furled ?and ?shrouded',
    2 => 'mod',
    3 => 'furledsail',
  ),
),
'hflex' => 1.2,
'wflex' => 1.4,
'proper' => rgb('brunatre'),
);
