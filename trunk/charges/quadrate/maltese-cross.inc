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

// maltese-cross

$charge = array (

  'patterns' => array (
  'maltese cross(let|lets|es)?',
  'cross(let|lets|es)? of (8|eight|huit) points',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',
  );

$main = 'l30,-30 -30,100';
$start = 70;
$fitch = 'l10,3v67l-10,30';
$void = 'x';
$pierce = 'x';

include ('charges/quadrate/_quadrate8.inc');

?>
