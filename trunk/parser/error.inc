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

function raise_error($string, $file = '', $line = '', $code = '' ) {
  global $dom, $errors;

  $error = $dom->create_element('error');
  $error->set_attribute('tokNum',tokNum());
  if ( $file ) $error->set_attribute('filename', $file);
  if ( $line ) $error->set_attribute('line', $line);
  if ( $code ) $error->set_attribute('code', $code);
  $text = $dom->create_text_node($string);
  $error->append_child($text);
  $errors->append_child($error);
}
?>
