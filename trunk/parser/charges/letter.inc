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


function charge_letter ( &$node, &$mods ) {
  global $dom;

  $numbers = array ( 'one' => '1', 'two' => '2', 'three' => '3', 'four' => '4', 'five' => '5',
        'six' => '6', 'seven' => '7', 'eight' => '8', 'nine' => '9', 'zero' => '0' );

  if ( ($item = next_word()) == null ) {
    raise_error ( 'expecting a ' . $node->get_attribute('subtype') );
    return null;
  }
  $first = strtolower($item{0});
  switch ( $node->get_attribute('subtype') ) {
    case 'letter':
      $item = $first;
      break;
    case 'digit':
      if (ctype_digit($first)) {
        $item = $first;
      } elseif ( array_key_exists($item, $numbers) ) {
        $item = $numbers[$item];
      } else {
        raise_error('Expecting digit, found ' . $item );
        $item = '1';
      }
      break;
    // case 'word: just use $item
  }
  $node->append_child(make_mod('item',$item));

  return null;
}
?>
