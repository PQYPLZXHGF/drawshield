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

// bbox

$charge = array (

  'patterns' => array (
  '?bounding box(es)?',
  ),

  'doc' => 'Stuff...',

  'width' => 100,
  'height' => 100,
  'body' => '<path fill-rule="evenodd" d="M0,0h100v100h-100zM15,15h70v70h-70z" />
                  <text x="50" y="65" font-size="30" text-anchor="middle">^UP^</text>',
  'wflex' => 999,
  'hflex' => 999,
  'orient_to_ordinary' => true,

)

?>
