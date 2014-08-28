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


$ordinary = array(
  'link' => 'http://karlwilcox.com/parker/t/tressure',
      'patterns' => array (
        'trea?s?sure',
      ),
      
      'doc' => 'Stuff...',
      
      'body' => array (
        'PLNC' => '<path fill-rule="nonzero" d="m 24.2, 24.2 c 0,0 2.3,811.8 4.1,817.8 63.6,228 355.7,278 474.7,328 116,-50 402,-100 465,-317 1,-4 4,-826.8 4,-826.8 l -947.8,-2 z M 927, 64.6 c 0,0 -1,758.4 -2,761.4 C 915,998 594,1100 497,1120 390,1090 97,988 74.7,826 74.5,824 68.7,64.6 68.7,64.6 z" />',
        'PLCH' => '<path fill-rule="nonzero" d="m 24.2,324 c 0,0 2.3,512 4.1,518 63.6,228 355.7,278 474.7,328 116,-50 402,-100 465,-317 1,-4 4,-527 4,-527 L 24.2,324 z M 927,365 c 0,0 -1,458 -2,461 C 915,998 594,1100 497,1120 390,1090 97,988 74.7,826 c -0.2,-2 -6,-461 -6,-461 z" />',
        // 'PLNC' => '<path fill-rule="evenodd" d="M 24.24, 24.18 C 24.24, 24.18 26.53,836.26 28.28,842.40 C 91.94,1065.58 383.85,1121.20 503.05,1171.71 C 619.15,1119.58 905.09,1067.45 967.72,852.50 C 968.85,848.62 971.76, 26.20 971.76, 26.20 L 24.24, 24.18 z M 68.69, 64.58 C 68.69, 64.58 74.47,824.24 74.75,826.24 C 96.97,988.24 389.91,1092.92 496.99,1123.22 C 593.96,1094.94 914.82,998.29 925.29,826.24 C 925.50,822.90 927.32,64.58 927.32,64.58 L 68.69,64.58 z" />',
        // 'PLCH' => '<path fill-rule="evenodd" d="M 24.24,324.18 C 24.24,324.18 26.53,836.26 28.28,842.40 C 91.94,1065.58 383.85,1121.20 503.05,1171.71 C 619.15,1119.58 905.09,1067.45 967.72,852.50 C 968.85,848.62 971.76,326.20 971.76,326.20 L 24.24,324.18 z M 68.69,364.58 C 68.69,364.58 74.47,824.24 74.75,826.24 C 96.97,988.24 389.91,1092.92 496.99,1123.22 C 593.96,1094.94 914.82,998.29 925.29,826.24 C 925.50,822.90 927.32,364.58 927.32,364.58 L 68.69,364.58 z" />',
        'Q1NC' => '<path fill-rule="evenodd" d="M25,25 h950v1150h-950z M75,75 h850v1050h-850z" />',
        'Q1CH' => '<path fill-rule="evenodd" d="M25,325 h950v850h-950z M75,375 h850v750h-850z" />',
        'Q2NC' => '<path fill-rule="evenodd" d="M25,25 h950v1150h-950z M75,75 h850v1050h-850z" />',
        'Q2CH' => '<path fill-rule="evenodd" d="M25,325 h950v850h-950z M75,375 h850v750h-850z" />',
        'Q3NC' => '<path fill-rule="evenodd" d="M25,25 L25,500 A1550,850 0,0,0 975,1155 L 975,25Z M75,75 L 75,500 A1550,850 0,0,0 925,1105 L 925,75Z" />',
        'Q3CH' => '<path fill-rule="evenodd" d="M25,325 L25,500 A1550,850 0,0,0 975,1155 L 975,325Z M75,375 L 75,500 A1550,850 0,0,0 925,1105 L 925,375Z" />',
        'Q4NC' => '<path fill-rule="evenodd" d="M25,25 L25,1155 A1550,850 0,0,0 975,500 L 975,25Z M75,75 L 75,1105 A1550,850 0,0,0 925,500 L 925,75Z" />',
        'Q4CH' => '<path fill-rule="evenodd" d="M25,325 L25,1155 A1550,850 0,0,0 975,500 L 975,325Z M75,375 L 75,1105 A1550,850 0,0,0 925,500 L 925,375Z" />',
        'I1NC' => '<path fill-rule="evenodd" d="M25,13 L25,870 A1450,850 0,0,0 975,1168 L 975,13Z M75,50 L 75,870 A1450,850 0,0,0 925,1130 L 925,50Z" />',
        'I1CH' => '<path fill-rule="evenodd" d="M25,313 L25,870 A1450,850 0,0,0 975,1168 L 975,313Z M75,350 L 75,870 A1450,850 0,0,0 925,1130 L 925,350Z" />',
        'I2NC' => '<path fill-rule="evenodd" d="M25,13 L25,1168 A1450,850 0,0,0 975,870 L 975,13Z M75,50 L 75,1130 A1450,850 0,0,0 925,870 L 925,50Z" />',
        'I2CH' => '<path fill-rule="evenodd" d="M25,313 L25,1168 A1450,850 0,0,0 975,870 L 975,313Z M75,350 L 75,1130 A1450,850 0,0,0 925,870 L 925,350Z" />', ),
 );
?>
