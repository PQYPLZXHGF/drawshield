<?php

$charge['modifiers'] =  array (
    array ( 'hilt', '(hilts?|hilted)', 'feature',    ),
    array ( 'pomell', '(pom?mell?s?|pomm?ell?ed)', 'feature',    ),
    array ( 'blade', 'blades?d?', 'feature',    ),
    array ( 'hilt', 'handles?d?', 'feature', ), // This isn't quite right, should also include pomell?
    array ( null, 'points? upwards?', 'ignore',    ),
    array ( null, 'points? uppermost', 'ignore',    ),
    array ( null, '?the points? in chief', 'ignore',    ),
    array ( null, 'points? downwards?', 'mod', 'inverted',    ),
    array ( null, '?the points? in base', 'mod', 'inverted',    ),
  );

$charge['proper'] = '#F0F0F0';

$charge['features'] = 
  array (
    'pomell' => 
    array (
      'proper' => '#EFD807',
    ),
    'hilt' => 
    array (
      'proper' => '#EFD807',
    ),
  );
  
$charge['orient_to_ordinary'] = true;



?>
