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

  $charges = array (
    // Debugging
    array ( 'bbox', '?bounding box(es)?' ,'geometric' ),
    // Humans (or parts thereof)
    array ( 'heart', '?human hearts?', 'heart' ),
    array ( 'arm', 'arms?', 'human' ),
    array ( 'hand', '?dexter hands?','human' ),
    // Animals
    array ( 'lion', 'lion(cel)?s?', 'lion' ),
    array ( 'scallop', 'e?scallops?', 'animal' ),
    array ( 'tiger', 't(i|y)gers?', 'animal' ),
    array ( 'unicorn', 'unicorns?', 'animal' ),
    array ( 'bee', 'bees?', 'animal' ),
    array ( 'chough', '?cornish choughs?' ,'bird' ),
    array ( 'martlett', 'martletts?', 'bird' ),
    array ( 'boars-head', 'boars? heads? ?couped' ,'animal' ),
    array ( 'bears-head', 'bears? heads? ?couped' ,'animal' ),
    array ( 'stags-head', 'stags? heads? ?couped' ,'animal' ),
    array ( 'dove', 'doves?', 'bird' ),
    array ( 'crow', '(crow|daw|rook|raven)s?', 'bird' ),
    // Plants
    array ( 'rose', 'roses?', 'plant' ),
    array ( 'thistle', 'thistles?', 'plant' ),
    array ( 'trefoil', 'trefoils?', 'plant' ),
    array ( 'cinquefoil', '(cinquefoil|fraise)s?', 'plant' ),
    array ( 'reed', 'reeds?', 'plant' ),
    array ( 'columbine', 'columbines?', 'plant' ),
    // Long crosses
    array ( 'crosslet', '?plain crosslets?',           'cross' ),
    array ( 'long', '(latin|long|passion) cross(es)?', 'cross' ),
    array ( 'calvary', 'calvary cross' ,               'cross' ),
    array ( 'patriarchal', 'patriarchal cross' ,       'cross' ),
    // Geometric
    array ( 'lozenge', 'lozenges?' ,'geometric' ),
    array ( 'escutcheon', 'escut?cheons?' ,'geometric' ),
    array ( 'billet', 'billets?' ,'geometric' ),
    array ( 'mascle', 'mascles?' ,'geometric' ),
    array ( 'roundel', 'roundels?|roundles?' ,'geometric' ),
    array ( 'annulet', 'annulets?' ,'geometric' ),
    array ( 'crescent', 'crescents?' ,'geometric' ),
    array ( 'fusil', 'fusils?' ,'geometric' ),
    array ( 'rustre', 'rustres?' ,'geometric' ),
    array ( 'cartouche', 'cartouches?' ,'geometric' ),
    array ( 'delf', 'delfs?','geometric' ),
    array ( 'fountain', 'fountains?', 'geometric', false ),
    array ( 'saltorel', 'saltorels?' ,'geometric' ),
    array ( 'goutte', 'go?uttes?' ,'geometric' ),
/*    array ( 'plate', 'plates?' ,'roundel', false ),
    array ( 'hurt', 'hurts?' ,'roundel', false ),
    array ( 'torteau', 'torteaux?'  ,'roundel', false ),
    array ( 'bezant', 'bezants?' ,'roundel', false ),
    array ( 'golpe', 'golpes?' ,'roundel', false ),
    array ( 'pellet', 'pellets?/gunstones?/ogress(es)?' ,'roundel', false ),
    array ( 'pomme', 'pommes?' ,'roundel', false ),
    array ( 'orange', 'oranges?' ,'roundel', false ),
    array ( 'guze', 'guzes?' ,'roundel', false ), */
    array ( 'triangle', 'triangles?', 'geometric' ),
    array ( 'mullet', 'm(o|u)ll?ets?', 'mullet' ),
    // Weapons  and armour
    array ( 'sword', 'swords?', 'weapon' ),
    array ( 'arrow', 'arrows?', 'weapon' ),
    array ( 'pheon', '(f|ph)eons? ?heads?','weapon' ),
    array ( 'pheon', 'arrow heads?','weapon' ),
    array ( 'broad-arrow', 'broad arrow ?heads?','weapon' ),
    array ( 'helm', 'helm(et)?s?', 'clothes' ),
    array ( 'gauntlet', 'gauntlets?', 'clothes' ),
    // Symbols
    array ( 'fleurdelys', 'fleurs? de l(y|i)s' ,'symbol' ),
    array ( 'orb', '?royal (orb|mound)', 'symbol' ),
    array ( 'ermine-spot', 'ermine spots?', 'symbol', 'sable' ),
    // Tools
    array ( 'pick-axe', 'pick axes?/hews?/miners axes?', 'axe' ),
    array ( 'addice', 'addices?/carpenters? axes?', 'axe' ),
    array ( 'battle-axe', 'battle axes?/battleaxes?', 'axe' ),
    array ( 'turner-axe', 'turners? axes?', 'axe' ),
    array ( 'common-axe', '?common axes?/hatchets?', 'axe' ),
    array ( 'scythe', 'scythes?', 'tools' ),
    array ( 'water-bouget', '?water bougets?' ,'tools' ),
    array ( 'anvil', '?smiths anvil', 'tools' ),
    // Crockery
    array ( 'cauldron', 'cauldrons?', 'crockery' ),
    array ( 'chalice', '?standing (chalice|cup)s?', 'crockery' ),
    array ( 'covered-cup', '?standing (chalice|cup)s? covered', 'crockery' ),
    array ( 'covered-cup', 'covered (chalice|cup)s?', 'crockery' ),
    array ( 'mug', 'mugs?', 'crockery' ),
    // Musical Instruments
    array ( 'clarion', 'clarions?', 'music' ),
    array ( 'harp', 'harps?', 'music' ),
    array ( 'horn', '?hunting horns?', 'music' ),
    // Clothing
    array ( 'maunche', 'maunches?', 'clothes' ),
    array ( 'buckle', 'buckles?', 'clothes' ),
    // Furniture
    array ( 'table', 'tables?', 'furniture' ),
    // Crowns
    array ( 'antique', '?antique crowns?' ,'crown' ),
    // Architecture
    array ( 'tower', 'towers?', 'architecture' ),
    array ( 'arch', 'arch(es)?', 'architecture' ),
    array ( 'altar', 'altars?', 'architecture' ),
    // Text
    array ( 'letter', 'letters?', 'letter' ),
    array ( 'digit', 'digits?', 'letter' ),
    array ( 'digit', 'numerals?', 'letter' ),
    array ( 'word', 'numbers?', 'letter' ),
    array ( 'word', 'words?', 'letter' ),
    // Misc
    array ( 'flames', 'flames ?of ?fire', 'misc' ),
    array ( 'rainbow', 'rainbows?', 'misc' ),
    // Collective nouns
    array ( 'dummy', '(sheaf|sheave|bundle|tuft)s? ?of', 'collect' ),
  );
?>
