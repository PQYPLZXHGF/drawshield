<?php /* Copyright 2011 Karl R. Wilcox 

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
 'patterns' => array (
    'br(a|e)ye?s?',
    'barnacles?',
   'hemp (break|bracke)s?',
   'hackles?',
   '?horse br[ae]ys?',
  ),
 
   'modifiers' => array (
     array ( null, '(expanded|extended)', 'mod', 'expanded' ),
   ),
   
  'file' => 'inkscape/brey1.svg',
  'licence' => 'Tim Powys-Lybbe, for a miscellany of bygones: http://powys.org/',
);

if ($node != null) {
  if ( get_mod( $node, 'expanded'))
    $charge['file'] = 'inkscape/brey.svg';
}

