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

  $types = array (
  'bird' => array (
      array ( 'legged', 'legged', 'feature' ),
      array ( 'beaked', 'beaked', 'feature' ),
    ),
  'axe' => array (
      array ( 'handle', '(handled?s?|staved?s?|hafts|hafted)', 'feature' ),
      array ( 'blade', 'blades?d?', 'feature' ),
    ), 
  'lion' => array (
    array ( 'armed', 'armed', 'feature' ),
    array ( 'tongued', 'langued', 'feature' ),
    array ( 'crowned', 'crowned', 'feature' ),
//    array ( 'lion-rampant', 'rampant', 'subtype' ),
    array ( 'lion-salient', 'salient', 'subtype' ),
    array ( 'lion-passant', 'passant', 'subtype' ),
    array ( 'lion-statant', 'statant', 'subtype' ),
    array ( 'lion-sejant',  'sejant', 'subtype' ),
    array ( 'lion-sejant-affronte',  'sejant affronte', 'subtype'  ),
    array ( 'lion-sejant-erect',  'sejant erect', 'subtype'  ),
    array ( 'lion-couchant', 'couchant', 'subtype' ),
  ),
  'quadrate' => array (
    array ( null, 'fitch(y|ee)', 'mod', 'fitchy' ),
    array ( null, 'fitch(y|ee) at ?the foot', 'mod', 'fitchy-foot' ),
  ),
  );
?>
