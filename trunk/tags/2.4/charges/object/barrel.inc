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
  'barrels?',
  'tu(b|n)s?',
  'hogsheads?',
  ),

  'modifiers' => array (
    array ( 'hooped', 'hooped', 'feature' ),
   ),

   'licence' => 'commons.wikimedia.org by LeMorvandiau',

  'height' => 188.14508, 'width' => 144.44278,
    'body' => '
      <path stroke="inherit" stroke-width="1.2" d="m 14.5,2.1 117.5,0 c 0,0 6,20.3 10,43.9 2,18 3,38 3,50 0,12 -1,32 -3,50 -4,23 -10,43 -10,43 l -117.5,0 c 0,0 -5.6,-19 -9.1,-42 C 2.7,129 1.9,108 1.9,96 1.9,84 2.5,64 5.1,46 8.7,22.3 14.5,2.1 14.5,2.1 z" />
      <path stroke="inherit" stroke-width="1.2" d="m 58.5,2.7 c 0,0 -2.6,65.3 -2.6,93.3 0,28 2.6,93 2.6,93 M 44.1,2.3 c 0,0 -6.7,65.7 -6.7,92.7 0,28 6.7,94 6.7,94 M 28.1,2.7 c 0,0 -8.9,65.3 -8.9,93.3 0,28 8.9,93 8.9,93 M 88,2.7 c 0,0 3,65.3 3,93.3 0,28 -3,93 -3,93 M 103,2.3 c 0,0 6,65.7 6,92.7 0,28 -6,94 -6,94 M 119,2.7 c 0,0 9,65.3 9,93.3 0,28 -9,93 -9,93 M 73,2.1 73,188" />
      ',
    'features' => array (
            'hooped' => array (
        'body' => '
      <path stroke="inherit" stroke-width="1.2" d="m 1.3,100 c 0,-3 0,-5 0,-9 L 144,91 c 1,3 1,5 0,9 z m 7.3,64 c -0.7,-3 -1.2,-6 -1.8,-9 l 133.2,0 c -1,4 -1,6 -2,9 z m 4.5,20 c -0.7,-3 -1.5,-5 -2.2,-9 l 125.1,0 c -1,3 -2,6 -2,9 z M 8.5,27.4 C 7.8,30.3 7.6,32 6.8,36 L 140,36 c -1,-3 -1,-5.6 -2,-8.6 z M 13,7.6 c -0.7,3 -1.2,4.5 -2.1,8.8 l 125.1,0 c -1,-3.7 -1,-5.9 -2,-8.8 z" />
      '),
      ),
  );
?>
