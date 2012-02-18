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


function number( $layout_only = false ) {
  global $p_globals;

  $numbers = array (
  array (0, '(0|zero)' ) ,// just for completeness...
  array (1, '(1|one)' ),
  array ('a', '(a|an|un|une|the)' ),
  array (2, '(2|two|deux)/a (pair|couple) of' ),
  array (3, '(3|three|trois)' ),
  array (4, '(4|four|quatre)' ),
  array (5, '(5|five|cinq)' ),
  array (6, '(6|six)/?a half dozen'  ),
  array (7, '(7|seven|sept)' ),
  array (8, '(8|eight|huit)' ),
  array (9, '(9|nine|neuf)' ),
  array (10, '(10|ten|dix)' ),
  array (11, '(11|eleven|onze)' ),
  array (12, '(12|twelve|douze)/?a dozen' ),
  array (13, '(13|thirteen)' ),
  array (14, '(14|fourteen)' ),
  array (15, '(15|fifteen)' ),
  array (16, '(16|sixteen)' ),
  array (17, '(17|seventeen)' ),
  array (18, '(18|eighteen)' ),
  array (19, '(19|nineteen)' ),
  array (20, '(20|twenty)/a score ?of' ),
  array ('asmany', 'as many' ),
  array ('asmany', 'so many' ),
  );

  $state = save();
  if ( ($number = search_match($numbers)) != null ) {
    $number = $number[0];
    if ( $number == 'a' ) {
      if ( $layout_only ) {
        restore($state);
        return null;
      } else {
        $number = 1;
      }
    } elseif ( $number == 'asmany' ) {
      if ($p_globals['asmany'] == null ) {
        parser_message('blazon', 'No previous number');
        $number = 2;
      } else {
        $number = $p_globals['asmany'];
      }
    } elseif ( $number > 1 and !$layout_only ) {
        $p_globals['asmany'] = $number;
    }
  }
  return $number;
}
?>
