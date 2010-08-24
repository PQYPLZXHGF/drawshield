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
  'patterns' => array (
  'griffins? heads?',
  'grypons? heads?'
  ),

  'modifiers' => array (
    array ( 'beaked', 'beaked', 'feature' ),
    array ( 'tongued', '(tongued|langued)', 'feature' ),
   ),

  'height' => "112", 'width' => "100",
    'body' => '
      <path stroke="#000000" stroke-width="2" d="m 12,92 10,-10 6,0 10,-10 8,0 4,0 -4,-20 -8,0 -8,-20 5,0 9,-10 4,-10 6,-10 5,0 3,0 1,10 -4,10 7,0 9,0 4,-10 4,-10 4,10 1,10 -2,0 -4,10 4,10 c 0,0 6,0 7,10 l -5,0 3,0 0,10 -8,-10 6,10 -4,0 6,10 -10,0 3,10 1,10 1,0" />
      <path stroke="#000000" stroke-width="2" d="m 45,32 c 5,0 11,0 11,0 l 2.5,7 -3.2,5 -6,1 -5.3,-3 -1.7,-4 z" />
      <path stroke="#000000" stroke-width="2" d="m 82,12 -3,10 5,0 z" />
      <path stroke="#000000" stroke-width="2" d="m 57,12 -2,0 -6,10 6,0 3,-10 z" />
      <path stroke="#000000" stroke-width="2" d="M 75,32 85,42" />
      <path stroke="#000000" stroke-width="2" d="M 71,32 86,52" />
      <path stroke="#000000" stroke-width="2" d="M 73,42 83,62" />
      <path stroke="#000000" stroke-width="2" d="m 73,52 8,20" />
      <path stroke="#000000" stroke-width="2" d="m 74,72 7,10" />
      <path stroke="#000000" stroke-width="2" d="m 73,82 5,10" />
      <path stroke="#000000" stroke-width="2" d="m 48,42 3,0 2,-3 -4.3,0 z" />
      ',
    'features' => array (
            'beaked' => array (
        'body' => '
        <path stroke="#000000" stroke-width="2" d="M 30,32 20,42 11,42 C 9.7,42 5.93,39 4.73,49 l -0.13,3 6.4,0 9,0 10,0 7,0 z" />
        <path stroke="#000000" stroke-width="2" d="M 48,72 41,72 29,72 21.5,69 14,62 29.3,65 40,64 46,62 z" />
      '),
            'tongued' => array (
        'body' => '
        <path stroke="#000000" stroke-width="2" d="m 44,52 -12.5,6 c -4,0 -17.3,-2 -17.3,-2 L 2.6,62 14.3,60 28,62 48,62 z" />
      '),
            'couped' => array (
        'body' => '
        <path stroke="#000000" stroke-width="2" d="m 13.4,91 -5.82,9 0,6 1.76,6 74.76,0 3.3,-7 -2.5,-13" />
        <path stroke="#000000" stroke-width="2" d="m 70.5,92 10.6,15" />
        <path stroke="#000000" stroke-width="2" d="m 65.4,96 10.9,13" />
      ', 'notpresent' => '<g />' ),
            'couped-fitchy' => array (
        'body' => '
        <path stroke="#000000" stroke-width="2" d="m 12.9,92 -3.05,7 5.85,5 27.2,0 3.1,8 5.3,-8 33.6,0 2.5,-4 -3,-9" />
        <path stroke="#000000" stroke-width="2" d="m 70.7,91 7.1,7" />
        <path stroke="#000000" stroke-width="2" d="m 66.9,94 5.8,5" />
      ', 'notpresent' => '<g />' ),
            'erased' => array (
        'body' => '
        <path stroke="#000000" stroke-width="2" d="m 11.9,92 -4.07,3 -2.27,5 -3.79,10 6.82,-4 5.01,-4 12.7,-3 4.5,2 0.8,3 -4.3,3 -7.9,3 10.4,-2 9.8,-3 9.9,-7 3.3,1 5,6 12.9,5 17.2,2 12.1,-1 -7.1,-3 -11.6,-4 -1,-6 3.5,-2 1.8,-4" />
        <path stroke="#000000" stroke-width="2" d="m 70.7,94 3.8,10 4.3,2" />
      ', 'notpresent' => '<g />' ),
    ),
    
  );

include 'charges/animal/_head.inc';

if ( $node != null ) {
  switch (get_mod($node, 'neckline') ) {
    case 'couped-fitchy':
      $charge['body'] .= '
        <path stroke="#000000" stroke-width="2" d="m 12.9,90 -3.05,7 5.85,5 27.2,0 3.1,8 5.3,-8 33.6,0 2.5,-4 -3,-9" />
        <path stroke="#000000" stroke-width="2" d="m 70.7,91 7.1,7" />
        <path stroke="#000000" stroke-width="2" d="m 66.9,94 5.8,5" /> ';
      break;
    case 'erased':
      $charge['body'] .= '
        <path stroke="#000000" stroke-width="2" d="m 11.9,90 -4.07,3 -2.27,5 -3.79,10 6.82,-4 5.01,-4 12.7,-3 4.5,2 0.8,3 -4.3,3 -7.9,3 10.4,-2 9.8,-3 9.9,-7 3.3,1 5,6 12.9,5 17.2,2 12.1,-1 -7.1,-3 -11.6,-4 -1,-6 3.5,-2 1.8,-4" />
        <path stroke="#000000" stroke-width="2" d="m 70.7,94 3.8,10 4.3,2" /> ';
      break;
    default: // couped
      $charge['body'] .= '
        <path stroke="#000000" stroke-width="2" d="m 13.4,90 -5.82,9 0,6 1.76,6 74.76,0 3.3,-7 -2.5,-13" />
        <path stroke="#000000" stroke-width="2" d="m 70.5,92 10.6,15" />
        <path stroke="#000000" stroke-width="2" d="m 65.4,96 10.9,13" /> ';
      break;
  }
}
?>
