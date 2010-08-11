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

  $subtypes = array (
  // Animals
  'boars-head' => array (
      array ( 'armed', 'armed', 'feature' ),
    ),
  'bears-head' => array (
      array ( 'tongued', 'tongued', 'feature' ),
      array ( 'muzzled', 'muzzled', 'feature' ),
    ),
  'tiger' => array (
      array ( 'armed', 'armed', 'feature' ),
      array ( 'tongued', 'tongued', 'feature' ),
    ),
  'unicorn' => array (
      array ( 'armed', 'armed', 'feature' ),
      array ( 'tongued', 'tongued', 'feature' ),
    ),
  // Crosses
/*   'calvary' => array (
      array ( null, '?mounted on # (degree|step|ascent|grice|griece)s?', 'mod', 'mounted' ),
     array ( null, '(on|with) a grie?ce of # steps?', 'mod', 'mounted' ),
   ),
   'patriarchal' => 'calvary',
   'crow' => array (
      array ( 'crow-volant', 'volant', 'subtype' ),
      array ( 'crow-rising', 'rising', 'subtype' ),
      array ( 'crow-head', 'heads?', 'subtype' ),
    ), */
  // Geometric
   'fountain' => array (
      array ( null, 'barry wavy of # argent ?and azure', 'ignore' ),
      ),
/*    'triangle' => array (
      array ( 'triangle-voided', 'voided', 'subtype' ),
      ),
    'chevron' => array ( 
      array ( 'chevron-sinister', 'couched sinister', 'subtype' ),
      array ( 'chevron-dexter', 'couched dexter', 'subtype' ),
       ), */
    'crescent' => array (
      array ( null, 'pendent', 'mod', 'inverted' ),
       ),
    'annulet' => array (
      array ( null, 'one (within|inside) ?the other', 'mod', 'concentric' ),
       ),
    // hearts
    'heart' => array (
      array ( 'flammant', 'flammant', 'feature' ), 
      array ( 'flammant', 'emitting flames of fire', 'feature' ), 
      array ( 'crowned', '?imperially crowned', 'feature' ), 
    ),
    'mullet' => array ( 
      array ( null, '(pierced|voided)', 'mod', 'pierced' ),
      array ( 5, '(of|de) # ?points', 'mod', 'points' ),
    ),      
   'rose' => array (
      array ( 'barbed', 'barbed', 'feature' ),
      array ( 'seeded', 'seeded', 'feature' ),
    ),
   'thistle' => array (
      array ( 'slipped', 'slipped', 'feature' ),
      array ( 'leaved', 'leaved', 'feature' ),
    ),
   'columbine' => array (
      array ( 'slipped', '(slipped|stalked|leaved)', 'feature' ),
      array ( 'barbed', 'barbed', 'feature' ),
      array ( 'flowers', '(flowered|flowers|buds)', 'feature'),
      array ( null, 'pendent', 'ignore' ),
      array ( null, 'slips crossed', 'ignore' ),
      array ( null, 'drooping', 'ignore' ),
    ),
   'orb' => array (
      array ( 'banded', 'banded|encircled', 'feature' ),
      array ( 'crossed', 'crossed/ensigned with a cross', 'feature' ),
    ),
    'sword' => array ( 
      array ('hilt', 'hilts?|hilted', 'feature' ),
      array ('pommell', 'pom?mell?s?|pomm?ell?ed', 'feature' ),
    ),
    'sheaf-arrows' => array (
      array ( 'barbed', 'barbed|armed', 'feature' ),
      array ( 'feathered', '(flighted|feathered)', 'feature' ),
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'arrow' => array (
      array ( 'barbed', 'barbed|armed', 'feature' ),
      array ( 'feathered', '(flighted|feathered)', 'feature' ),
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'pheon' => array (
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
    'broad-arrow' => array (
      array ( 'up',  'points? upwards?', 'mod', 'pointing' ),
      array ( 'down',  'points? downwards?', 'mod', 'pointing' ),
    ),
  );
  
?>
