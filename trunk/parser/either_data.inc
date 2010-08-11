<?php
  $either = array (
    // Long crosses
//    array ( 'tau',                'tau ?cross(es)?',               'cross', 'charge' ),
//    array ( 'tau',                'cross(es)? ?of (saint|st) anthony', 'cross', 'charge' ),
    array ( 'cross-formy',        'cross formy throughout',           'cross2', 'ordinary' ),
    array ( 'fillet-cross',       'cross fillet',                       'cross2', 'ordinary' ),
    array ( 'calvary',            'cross(es)? calvary',                'cross', 'charge' ),
    array ( 'patriarchal',         'cross(es)? patriarchal',            'cross', 'charge' ),
    array ( 'fillet-cross',       'fillet cross',                       'cross2', 'ordinary' ),
    array ( 'cross-pierced',      'cross quarter pierced',            'cross2', 'ordinary' ),
    array ( 'cross-2fretty',      'cross ?double parted ?and fretty', 'cross2', 'ordinary' ),
    array ( 'cross-3fretty',      'cross tripartite ?and fretty',  'cross2', 'ordinary' ),
    array ( 'cross',              '?plain cross(es)? ?passant',                    'cross:cross', 'either' ),
    // Quadrate crosses
    array ( 'cross-botonny',      'cross(es)? (botonny|trefle)',  'quadrate', 'charge' ),
    array ( 'cross-pointed',      'cross(let|lets|es)? pointeds?',  'quadrate', 'charge' ),
    array ( 'cross-flory',        'cross(let|lets|es)? florys?',      'quadrate', 'charge' ),
    array ( 'cross-pomme',        'cross(let|lets|es)? pommes?',      'quadrate', 'charge' ),
    array ( 'cross-potent',       'cross(es)? potent',             'quadrate', 'charge' ),
    array ( 'cross-floretty',     'cross(let|lets|es)? florettys?', 'quadrate', 'charge' ),
    array ( 'cross-paty-floretty','cross(let|lets|es)? paty florettys?', 'quadrate', 'charge' ),
    array ( 'cross-fourche',      'cross(let|lets|es)? fourche', 'quadrate', 'charge' ),
    array ( 'cross-moline',       'cross(let|lets|es)? (molines?|ancre|anchory)','quadrate', 'charge' ),
    array ( 'maltese-cross',      'maltese cross(let|lets|es)?',   'quadrate', 'charge' ),
    array ( 'maltese-cross',      'cross(let|lets|es)? of (8|eight|huit) points','quadrate', 'charge' ),
    array ( 'cross-cercele',      'cross(let|lets|es)? (re)?cercelee?s?','quadrate', 'charge' ),
    array ( 'cross-patonce',      'cross(let|lets|es)? patonces?', 'quadrate', 'charge' ),
    array ( 'cross-formy',        'cross(let|lets|es)? (formy|patt?y)', 'quadrate',   'charge' ),
    array ( 'cross-formy',        'cross(let|lets|es)? (formee|pattee)', 'quadrate',   'charge' ),
    array ( 'cross-cleche',       'cross(let|lets|es)? (cleche|urde)', 'quadrate',   'charge' ),
    array ( 'cross-crosslet',     'cross(es)? crosslets?',         'quadrate', 'charge' ),
    array ( 'fylfot',             'cross(es)? potent rebated',        'quadrate', 'charge' ),
    array ( 'fylfot',             'cross(es)? gammadions?',                'quadrate', 'charge' ),
    array ( 'fylfot',             'fylfots?',                                         'quadrate', 'charge' ),
    // Chevrons
//    array ( 'chevron',            'chevron(el)?s?', 'chevron:geometric', 'either' ),
    // Subordinaries
    array ( 'fret', 'frets?',     'subordinary:geometric', 'either' ),
    array ( 'fret-couped',        'frets? couped' , 'common', 'ordinary' ),
  );
?>
