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
    'quarterly' =>          array ( 'NC' => 'X500Y-100a600c600P>600R<600   X-100Y500A>600C<800e600g800', 'CH' => 'X500Y200a500c500E>500G<500   X0Y700A>500C<500e500g500' ),
    'quarterly-per-fess' => array ( 'NC' => 'X500Y-100a600c600E>600g600    X-100Y500A>600c800e600g800',  'CH' => 'X500Y200a500c500E>500g500    X0Y700A>500c500e500g500' ),
    'quarterly-per-pale' => array ( 'NC' => 'X500Y-100a600c600e600G<600    X-100Y500a600C<800e600g800',  'CH' => 'X500Y200a500c500e500G<500    X0Y700a500C<500e500g500' ),
  );
  $name = $node->get_attribute('subtype');

  return $q_data[$name];
}
?>
