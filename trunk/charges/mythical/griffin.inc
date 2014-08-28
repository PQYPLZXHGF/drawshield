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

$charge = array ( 
  'link' => 'http://karlwilcox.com/parker/g/griffin',
  'patterns' => array (
  'griffins?',
  'gryphons?',
  ),

  'modifiers' => array (
    array ( 'beaked', 'beaked', 'feature' ),
    array ( 'armed', 'armed', 'feature' ),
    array ( 'legged', 'legged', 'warn' ),
    array ( 'tailed', 'tailed', 'warn' ),
    array ( 'winged', 'winged', 'feature' ),
	array ( 'tongued', '(tongued|langued)', 'feature' ),
	array ( null, 'sans wings', 'mod', 'wingless' ),
	array ( null, 'rampant', 'ignore' ),
	array ( null, 'segreant', 'ignore' ),
   ),

  'file' => 'inkscape/griffin.svg',
  );


