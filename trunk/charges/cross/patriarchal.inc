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

// patriarchal

$charge = array (

  'link' => 'http://karlwilcox.com/parker/c/cross/patriarchal',
  'patterns' => array (
  'cross(es)? patriarchal',
  ),
  'modifiers' => array (
    array ( null, '?mounted on # (degree|step|ascent|grice|griece)s?', 'mod', 'mounted' ),
    array ( null, '(on|with) a grie?ce of # steps?', 'mod', 'mounted' ),
  ),

'either' => array ( 'cross', ),

  'file' => 'inkscape/patriarchal.svg',
);

if ( $node != null ) {
  if  ( $num = get_mod($node,'mounted') ) {
    if ($num > 9) $num = 9;
    $charge['file'] = "inkscape/patriarchal-$num.svg";
  }
}
