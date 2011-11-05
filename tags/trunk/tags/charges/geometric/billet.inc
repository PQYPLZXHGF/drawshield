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

// billet

$charge = array (

  'patterns' => array (
  'billets?',
  ),

  'doc' => 'Stuff...',

  'width' => 250,
  'height' => 500,
  'wflex' => 1,
  'hflex' => 2,
  'body' => '<rect height="500" width="250" rx="20" ry="20" />
        			<path stroke="none" fill="#4D4D4D" opacity="0.5" d="M 250.9,59.9 C 235.2,182.7 227.3,453 22.29,501 c -10,-2 201.41,3 210.71,1 9.3,-2 19.3,-6 19.3,-19 0,-12 -0.7,-422.4 -1.4,-423.1 z" />',
  'orient_to_ordinary' => true,

)

?>
