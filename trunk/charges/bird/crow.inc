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

// crow

$charge = array (

  'link' => 'http://karlwilcox.com/parker/c/crow',
  'patterns' => array (
  '(crow|daw|rook|raven)s?',
  ),
  'modifiers' => array (
    array ( 'legged', 'legged', 'feature' ),
    array ( 'beaked', 'beaked', 'feature' ),
    array ( null,  'croaking', 'ignore' ),
    array ( 'volant', 'volant', 'mod', 'variant' ),
    array ( 'rising', 'rising', 'mod', 'variant' ),
  ),

  'proper' => rgb('sable'),

  'features' => array (
    'beaked' => array ( 'proper' => rgb('or'), ),
    'legged' => array ( 'proper' => rgb('gray'), ),
  ),
  'file' => 'inkscape/crow.svg',
);


