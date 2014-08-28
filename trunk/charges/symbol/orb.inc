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
'file' => 'inkscape/orb.svg',
  'link' => 'http://karlwilcox.com/parker/o/orb',
'patterns' => array (
  0 => '?royal (orbs?|mounds?)',
),
'modifiers' => array (
  0 => 
  array (
    0 => 'banded',
    1 => '(banded|encircled)',
    2 => 'feature',
  ),
  1 => 
  array (
    0 => 'crossed',
    1 => 'ensigned with a cross',
    2 => 'feature',
  ),
  2 => 
  array (
    0 => 'crossed',
    1 => 'crossed',
    2 => 'feature',
  ),
),
'orient_to_ordinary' => true,
);
