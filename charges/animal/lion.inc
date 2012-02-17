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

// lion

$charge = array (

  'patterns' => array (
  'lions?',
  'lioncels?',
  ),

  'modifiers' => array (
    /* Features */
    array ( 'armed', 'armed', 'feature' ),
    array ( 'langued', 'langued', 'feature' ),
    array ( 'crowned', 'crowned', 'warn', 'crowned' ),
    /* Stance */
    array ( 'rampant', 'rampant', 'mod', 'stance' ),
    array ( 'salient', 'salient', 'mod', 'stance' ),
    array ( 'passant', 'passant', 'mod', 'stance' ),
    array ( 'statant', 'statant', 'mod', 'stance' ),
    array ( 'sejant',  'sejant', 'mod', 'stance' ),
    array ( 'sejant-erect',  'sejant erect', 'mod', 'stance' ),
    array ( 'couchant', 'couchant', 'mod', 'stance' ),
    array ( 'courant', 'courant', 'mod', 'stance' ),
    array ( 'dormant', 'dormant', 'mod', 'stance' ),
    array ( 'coward', 'coward', 'mod', 'stance' ),
    array ( 'cadent', 'cadent ?dexter', 'mod', 'stance' ),
    /* tail type */
    array ( 'nowed', 'tail nowed', 'mod', 'tail-type' ),    
    array ( 'fourche', 'tail (fourche|forked)', 'mod', 'tail-type' ),    
    array ( 'saltire', 'tail (fourche|forked) ?in saltire', 'mod', 'tail-type' ),    
    array ( 'saltire-reverse', 'tail (fourche|forked) ?in saltire reversed', 'mod', 'tail-type' ),    
    /* facing direction */
    array ( 'guardant', 'guardant', 'mod', 'head-pos' ),
    array ( 'reguardant', 'reguardant', 'mod', 'head-pos' ),
  ),

  'doc' => 'Stuff...',
  
  'hflex' => 3,
  'wflex' => 3,
  
  'demi' => 'top',

);

if ($node != null ) {
  $type = $node->getAttribute('type');
  if ( ($stance = get_mod($node, 'stance')) == null ) $stance = 'rampant'; 
  if ( ($looking = get_mod($node, 'head-pos')) == null ) $looking = 'normal';
  if ( ($tail = get_mod($node, 'tail-type')) == null ) $tail = 'normal';
  /* Try to get the most specific lion */
  $filename = "inkscape/lion-$stance-$looking-$tail.svg";
  if ( file_exists("charges/$type/$filename") )
    $charge['file'] = $filename;
  else {
    $filename = "inkscape/lion-$stance-$looking.svg";
    if ( file_exists("charges/$type/$filename") )
      $charge['file'] = $filename;
    else {
      $filename = "inkscape/lion-$stance.svg";
      if ( file_exists("charges/$type/$filename") )
        $charge['file'] = $filename;
      else {
        draw_message ( 'warning', 'no lion of given type' );
        $charge['file'] = 'inkscape/lion-courant.svg';
      }
    }
  }

}

?>
