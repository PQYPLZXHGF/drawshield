<?php
// Line spec is name, overall length then moves
// Moves are triples of direction, short side, long side
$line_specs = array (
  array ( 'indented', '{S*2}', 'L4:{S/2}:{S*0.707}#R4:{S}:{S*1.414}#L4:{S/2}:{S*0.707}' ),
  array ( 'embattled', '{S*2}', 'L9:{S/2}:{S*0.353}#FW:{S}:{S*0.707}#R9:{S}:{S*0.707}#FW:{S}:{S*0.707}#L9:{S/2}:{S*0.353}'),
);

//echo '$lineSpecs = array (' . "\n";
foreach ( $line_specs as $line_spec ) {
  echo "'${line_spec[0]}' => \n";
  echo "  'A:*:${line_spec[1]}:-:-:";
  $moves = explode('#', $line_spec[2]);
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'R9': echo "v$dist "; break;
      case 'R4': echo "l$dist,$dist "; break;
      case 'FW': echo "h$dist "; break;
      case 'BW': echo "h-$dist "; break;
      case 'L4': echo "l$dist,-$dist "; break;
      case 'L9': echo "v-$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'B:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'R9': echo "l-$dist,$dist "; break;
      case 'R4': echo "v$dist "; break;
      case 'FW': echo "l$dist,$dist "; break;
      case 'BW': echo "l-$dist,-$dist "; break;
      case 'L4': echo "h$dist "; break;
      case 'L9': echo "l$dist,-$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'C:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'R9': echo "h-$dist "; break;
      case 'R4': echo "l-$dist,$dist "; break;
      case 'FW': echo "v$dist "; break;
      case 'BW': echo "v-$dist "; break;
      case 'L4': echo "l$dist,$dist "; break;
      case 'L9': echo "h$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'D:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'R9': echo "l-$dist,-$dist "; break;
      case 'R4': echo "h-$dist "; break;
      case 'FW': echo "l-$dist,$dist "; break;
      case 'BW': echo "l$dist,-$dist "; break;
      case 'L4': echo "v$dist "; break;
      case 'L9': echo "l$dist,$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'E:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'L9': echo "v-$dist "; break;
      case 'L4': echo "l-$dist,-$dist "; break;
      case 'FW': echo "h-$dist "; break;
      case 'BW': echo "h$dist "; break;
      case 'R4': echo "l-$dist,$dist "; break;
      case 'R9': echo "v$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'F:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'L9': echo "l$dist,-$dist "; break;
      case 'L4': echo "h-$dist "; break;
      case 'FW': echo "l-$dist,-$dist "; break;
      case 'BW': echo "l$dist,$dist "; break;
      case 'R4': echo "v-$dist "; break;
      case 'R9': echo "l-$dist,$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'G:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'L9': echo "h$dist "; break;
      case 'L4': echo "l$dist,-$dist "; break;
      case 'FW': echo "v-$dist "; break;
      case 'BW': echo "v$dist "; break;
      case 'R4': echo "l-$dist,-$dist "; break;
      case 'R9': echo "h-$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'H:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'L9': echo "l$dist,$dist "; break;
      case 'L4': echo "h$dist "; break;
      case 'FW': echo "l$dist,-$dist "; break;
      case 'BW': echo "l-$dist,$dist "; break;
      case 'R4': echo "v-$dist "; break;
      case 'R9': echo "l-$dist,-$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'P:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'R9': echo "v-$dist "; break;
      case 'R4': echo "l-$dist,-$dist "; break;
      case 'FW': echo "h-$dist "; break;
      case 'BW': echo "h$dist "; break;
      case 'L4': echo "l-$dist,$dist "; break;
      case 'L9': echo "v$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'Q:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'R9': echo "l$dist,-$dist "; break;
      case 'R4': echo "h-$dist "; break;
      case 'FW': echo "l-$dist,-$dist "; break;
      case 'BW': echo "l$dist,$dist "; break;
      case 'L4': echo "v-$dist "; break;
      case 'L9': echo "l-$dist,$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'R:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[1];
    switch ( $dir ) {
      case 'R9': echo "h$dist "; break;
      case 'R4': echo "l$dist,-$dist "; break;
      case 'FW': echo "v-$dist "; break;
      case 'BW': echo "v$dist "; break;
      case 'L4': echo "l-$dist,-$dist "; break;
      case 'L9': echo "h-$dist"; break;
    }
  }
  echo "    ' .\n"; 
  echo "  'S:*:${line_spec[1]}:-:-:";
  foreach ( $moves as $move ) {
    $moveparts = explode(':',$move);
    $dir = $moveparts[0];
    $dist = $moveparts[2];
    switch ( $dir ) {
      case 'R9': echo "l$dist,$dist "; break;
      case 'R4': echo "h$dist "; break;
      case 'FW': echo "l$dist,-$dist "; break;
      case 'BW': echo "l-$dist,$dist "; break;
      case 'L4': echo "v-$dist "; break;
      case 'L9': echo "l-$dist,-$dist"; break;
    }
  }
  echo "    ' .\n"; 


  echo "  '',\n";
}
//echo ");\n";


?>
