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

// triangle

$charge = array (

  'patterns' => array (
  'triangles?',
  ),
  
  'modifiers' => array (
    array ( null, 'voided', 'mod', 'voided' ),
  ),

  'doc' => 'Stuff...',

  'width' => 100,
  'height' => 66,
  'orient_to_ordinary' => true,

);

if ( get_mod($node, 'voided') )
  $charge['body'] = '<path fill-rule="evenodd" d="M15,59 L50,12 85,59z M0,66 L50,0 100,66z" />';
else
  $charge['body'] = '<path d="M0,66 L50,0 100,66z" />';

?>
