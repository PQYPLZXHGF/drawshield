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


function linetype () {
  $edge_mods = array (
    //      filename      regexs
    //
     array ( 'none',      'none',                                   ),
     array ( 'angled',    'angled',                                 ),
     array ( 'arched',    '(en)?arched',                             ),
     array ( 'battled-embattled', 'battled embattled',),
     array ( 'battled-embattled', '(em)?battled grady',  ),
     array ( 'battled-counter', '(em)?battled counter embattled',  ),
     array ( 'bevilled',    'bevilled',                             ),
    // array ( 'dancetty-floretty', 'dancetty floretty' ,),
     array ( 'dancetty',  'dau?ncetty',                               ),
     array ( 'double-arched', 'double arched',       ),
     array ( 'dovetailed','dovetailed',                             ),
     array ( 'embattled', 'embattled',                              ),
     array ( 'engrailed', 'engrailed',                              ),
     array ( 'escartelly',    'escartelly',                         ),
     array ( 'indented',  'indented',                               ),
     array ( 'invected',  'invected',                               ),
     array ( 'nebuly',    'nebuly',                                 ),
     array ( 'nowy' ,     'nowy',                                   ),
     array ( 'potenty',   'potenty',                                ),
     array ( 'raguly',    'raguly',                                 ),
     array ( 'rayonny',   '(rayonny|radiant)',                      ),
     array ( 'urdy' ,     '(urdy|urde|champaine|champion)',         ),
     array ( 'wavy',      '(wavy|undy)',                           ),
  );

  $mod = search_match ( $edge_mods );
  if ( $mod == null ) { $mod = $edge_mods[0]; }
  return $mod[0];
}

?>
