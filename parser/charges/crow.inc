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


function charge_crow ( $subtype ) {
  $crow_data = array (
    array ( 'legged', 'legged', 'feature' ),
    array ( 'beaked', 'beaked', 'feature' ),
    array ( 'crow-volant', 'volant', 'subtype' ),
    array ( 'crow-rising', 'rising', 'subtype' ),
    array ( 'crow-head', 'heads?', 'subtype' ),
  );

  return $crow_data;
}
?>
