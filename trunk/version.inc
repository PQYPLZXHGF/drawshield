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
 * Time: 18:39
 */

$version = array (
  'release' => '2.5b',
  'date' => '27 August 2014',
  'name' => 'Drawshield',
  'website' => 'drawshield.net',
  'author' => 'Karl R. Wilcox',
  'email' => 'karl@karlwilcox.com',
);

// Set default values for arguments
$options = array(
  // These options are potentially set by URL arguments
  'blazon' => '',
  'palette' => 'drawshield',
  'printable' => false,
  'size' => 500,
  'saveFormat' => 'png',
  'asFile' => false,
  'highlight' => false,
  // These options can only be set here
  'logBlazon' => false,
);