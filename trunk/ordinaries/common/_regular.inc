<?php

$ordinary['modifiers'][] = array ( null, 'voided', 'mod', 'voided' );
$ordinary['modifiers'][] = array ( null, 'sinister', 'mod', 'sinister' );
$ordinary['modifiers'][] = array ( null, 'dexter', 'mod', 'dexter' );
$ordinary['modifiers'][] = array ( null, 'inverted', 'mod', 'inverted' );
$ordinary['modifiers'][] = array ( null, 'enhanced', 'mod', 'enhanced' );
$ordinary['modifiers'][] = array ( null, '(abased|abaisse)', 'mod', 'abased' );
$ordinary['modifiers'][] = array ( null, '(fimbriated|edged)', 'feature', 'fimbriated',  );
$ordinary['modifiers'][] = array ( null, 'voided', 'mod', 'voided' );
$ordinary['modifiers'][] = array ( 1, '(cotised|cotticed|endorsed)', 'feature', 'cotise',  );
$ordinary['modifiers'][] = array ( 1, 'between # cott?ices', 'feature', 'cotise',  );
$ordinary['modifiers'][] = array ( 2, 'double (cotised|cotticed)', 'feature', 'cotise',  );
$ordinary['modifiers'][] = array ( 3, '(triple|treble) (cotised|cotticed)', 'feature', 'cotise',  );

?>