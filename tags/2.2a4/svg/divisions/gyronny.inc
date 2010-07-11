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


function makeDiv_gyronny( $node, $div_num ) {

  if ( $div_num != 2 ) return '';

  $g_data = array (
    'gyronny-of-8' => array ( 'NC' => '<polygon  points="500,500 500,-200, 1000,-200 1000,0" /><polygon points="500,500 1000,500 1000,1000" /><polygon points="500,500 500,1400 0,1400 0,1000" /><polygon points="500,500 0,500 0,0" />',
                                    'CH' => '<polygon  points="500,750 500,50, 1000,50 1250,0" /><polygon points="500,750 1000,750 1000,1250" /><polygon points="500,750 500,1650 0,1650 0,1250" /><polygon points="500,750 0,750 0,250" />'),
    'gyronny-of-6' =>array ( 'NC' =>  '<path  d="M -279,950 -1060,-400 500,500 z M 500,500 1280,950 500,2300 z m 0,-900 1560,0 -1560,900 z" />',
                       'CH' => '<path  d="M -279,1150 -1060,-200 500,700 z M 500,700 1280,1150 500,2500 z m 0,-900 1560,0 -1560,900 z" />'),
    'gyronny-of-10' => array ( 'NC' => '<path  d="M 1360,778 1560,160 500,500 z M 1030,-227 504,-609 500,502 z M -27.7,-228 -554,155 502,500 z M -356,778 -155,1400 500,500 z m 856,622 650,0 -650,-900 z" />',
                        'CH' => '<path  d="M 1360,978 1560,360 500,700 1360,978 z M 1030,-27 504,-409 500,702 1030,-27 z M -27.7,-28 -554,355 502,700 -27.7,-28 z M -356,978 -155,1600 500,700 -356,978 z m 856,622 650,0 -650,-900 0,900 z" />'),
    'gyronny-of-12' => array ( 'NC' => '<path  d="M -279,50 -19.4,-400 500,500 z m 0,897 -260,-450 1039,0 z m 779,453 -520,0 520,-900 z M 1280,950 1020,1400 497,500 z m 0,-900 260,450 -1040,0 z m -780,-450 520,0 -520,900 z" />',
                        'CH' => '<path  d="M -279,250 -19.4,-200 500,700 -279,250 z m 0,900 -260,-453 1039,0 -779,453 z m 779,450 -520,0 520,-900 0,900 z m 780,-450 -260,450 -523,-900 783,450 z m 0,-900 260,450 -1040,0 780,-450 z m -780,-450 520,0 -520,900 0,-900 z" />'),
  );
  $allowed = array ( '6', '8', '10', '12' );

  $num_of = '0';
  foreach ( $node->child_nodes() as $child ) {
    if ( $child->node_name() == 'modifier' and $child->get_attribute('name') == 'ofnum' ) {
      $num_of = $child->get_attribute('param');
      break;
    }
  }
  if ( !in_array($num_of, $allowed) ) $num_of = '8';

  return $g_data[('gyronny-of-' . $num_of)];
}
?>
