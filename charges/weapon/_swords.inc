<?php

$charge['modifiers'] =  array (
    array ( 'hilt', '(hilts?|hilted)', 'feature',    ),
    array ( 'pomell', '(pom?mell?s?|pomm?ell?ed)', 'feature',    ),
    array ( 'blade', 'blades?d?', 'feature',    ),
    array ( 'hilt', 'handles?d?', 'feature', ), // This isn't quite right, should also include pomell?
    array ( null, 'points? upwards?', 'ignore',    ),
    array ( null, 'erect', 'ignore',    ),
    array ( null, 'points? uppermost', 'ignore',    ),
    array ( null, '?the points? in chief', 'ignore',    ),
    array ( null, 'points? downwards?', 'mod', 'inverted',    ),
    array ( null, '?the points? in base', 'mod', 'inverted',    ),
  );

$charge['proper'] = rgb('argent');

$charge['features'] = 
  array (
    'pomell' => 
    array (
      'proper' => rgb('or'),
    ),
    'hilt' => 
    array (
      'proper' => rgb('or'),
    ),
  );
  
$charge['orient_to_ordinary'] = true;

