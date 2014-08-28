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


function makeDiv_quarterly( $node, $div_num ) {

  if ( $div_num != 2 ) return '';

  $q_data = array ( 
    'quarterly' =>          array ( 'NC' => 'O1Q1X500Y500C800e600g800A600   O1Q1X500Y500G600a600c600E600',  'CH' => 'O1Q1X500Y700C600e600g600A600   O1Q1X500Y700G600a600c600E600' ),
    'quarterly-per-fess' => array ( 'NC' => 'O1Q1X500Y500c800e600g800A600   O1Q1X500Y500g600a600c600E600',  'CH' => 'O1Q1X500Y700c600e600g600A600   O1Q1X500Y700g600a600c600E600' ),
    'quarterly-per-pale' => array ( 'NC' => 'O1Q1X500Y500C800e600g800a600   O1Q1X500Y500G600a600c600e600',  'CH' => 'O1Q1X500Y700c600e600g600a600   O1Q1X500Y700g600a600c600e600' ),
  );
  $name = $node->getAttribute('subtype');
  draw_message('link', $name . ' ' . 'http://karlwilcox.com/parker/q/quarterly');

  return $q_data[$name];
}
?>
