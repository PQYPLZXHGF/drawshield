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

// word

$charge = array (

  'link' => 'http://karlwilcox.com/parker/w/word',
  'patterns' => array (
  'words?',
  ),
  
  'flags' => array (
    'get_item' => 1,
    'default_colour' => 'sable',
  ),

  'file' => 'null', // overridden in use
);

if ( $node != null ) {
  $item = get_mod( $node, 'item' );
  if ( $item == null ) $item = '???';
  $len = 25 * strlen($item);
  $charge['svgCode'] = '<svg height="44" width="' . $len . '"><text x="' . $len / 2 . '" y="44" text-anchor="middle" font-size="44" font-style="italic" font-family="serif">' .
        $item . '</text></svg>';
}

