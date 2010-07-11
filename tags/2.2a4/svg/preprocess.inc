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

function schemeHandler($xh, $func, $arg) {
//  echo $func . ':' . $arg;
	$arg = substr($arg,1);
	$args = explode('#', $arg);
	$retval = '';
	switch ( count($args) ) {
		case 0:
		  $retval = $func();
		  break;
		case 1:
		  $retval = $func($arg);
		  break;
		case 2:
		  $retval = $func($args[0],$args[1]);
		  break;
		case 3:
		  $retval = $func($args[0],$args[1],$args[2]);
		  break;
		case 4:
		  $retval = $func($args[0],$args[1],$args[2],$args[3]);
		  break;
	}
	return '<?xml version="1.0" encoding="UTF-8"?><g>' . $retval . '</g>';
}

$handlerArray = array ( 'get_all' => 'schemeHandler' );

function preprocess ( $dom ) {
  global $handlerArray;
  $arguments = array(
       '/_xml' => $dom->dump_mem(),
       '/_xsl' => file_get_contents('svg/substitutions.xslt')
  );

  // Allocate a new XSLT processor
  $xh = xslt_create();

  // Do substitutions
  $result = xslt_process($xh, 'arg:/_xml', 'arg:/_xsl', NULL, $arguments);
  if (!$result) {
    echo 'Error in transform ' . xslt_error($xh);
    echo 'Error code ' . xslt_errno($xh);
    xslt_free($xh);
    return $result;
  }
  
  // Do placements
  xslt_set_scheme_handlers($xh, $handlerArray);
  $arguments['/_xml'] = $result;
  $arguments['/_xsl'] = file_get_contents('svg/placements.xslt');
  $result = xslt_process($xh, 'arg:/_xml', 'arg:/_xsl', NULL, $arguments);
  if (!$result) {
    echo 'Error in transform2 ' . xslt_error($xh);
    echo 'Error code ' . xslt_errno($xh);
  }
  xslt_free($xh);
  return $result;
}
?>
