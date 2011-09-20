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
        'inescut?cheon',
      ),
      
      'doc' => 'Stuff...',
      
        'shape_spec' => array ( 'NC' => 'X200Y200A600C600I400,200,0,-300,200I400,200,0,-300,-200G600',  'CH' => 'X200Y500A600C300I400,200,0,-300,200I400,200,0,-300,-200G300'),
        'bounding_box' => array( 'NC' => '600,900,200,200', 'CH' => '600,500,200,500' ),
);

?>
