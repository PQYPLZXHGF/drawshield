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
      'patterns' => array (
        'quarter',
      ),
      
      'doc' => 'Stuff...',
      
      'shape_spec' => array ( 'NC' => 'X0Y500g500a500C500E500', 'CH' =>  'X-100Y700g500a600C500E600'),
  //    'bounding_box' => array ( 'NC' => '500,500', 'CH' => '500,400,0,300' ),
			'if_ord_on' => 'scale',
);

?>
