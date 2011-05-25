<?php

function rewrite() {
  global $dom;
  
  $xpath = new DOMXPath($dom);
  
  // orientation: "inbar" becomes "inpale fesswise"
  foreach ( $xpath->query("//modifier[@name='arrangement' and @param='inbar']") as $item ) {
    $item->setAttribute('param','inpale');
    $mod = make_mod('orientation', 'fesswise');
    $item->insertBefore($mod);
  }
  
  // We implement concentric annulets as a single charge of "number" rings
  foreach ( $xpath->query("//charge[@subtype='annulet' and modifier/@name='concentric']") as $item ) {
    $number = $item->getAttribute('number');
    $item->setAttribute('number','1');
    $mod = make_mod('concentric',"$number");
    $item->appendChild($mod);
  }
  
  // icicles (are inverted gouttes)
  foreach ( $xpath->query("charge[@subtype='icicle']") as $item ) {
    $item->setAttribute('subtype','goutte');
    $mod = make_mod('inverted');
    $item->appendChild($mod);
  }
  
  // fountain (is a roundel with wavy bars)
  foreach ( $xpath->query("//charge[@subtype='fountain']") as $item ) {
    $item->setAttribute('subtype','roundel');
    $tinc = get_child($item, 'tincture'); // replace existing "proper"
    $div = $dom->createElement('division');
    $div->setAttribute('type', 'bar');
    $div->setAttribute('subtype', 'barry');
    $div->setAttribute('linetype', 'wavy');
    $tinc1 = make_colour('azure');
    $tinc2 = make_colour('argent');
    $mod = make_mod('ofnum','6');
    $div->appendChild($tinc1);
    $div->appendChild($tinc2);
    $div->appendChild($mod);
    $tinc->replaceChild($div,$tinc->firstChild);
    $item->appendChild($tinc);
  }

  // ford (a base with wavy bars) 
  foreach ( $xpath->query("//ordinary[@subtype='ford']") as $item ) {
    $item->setAttribute('subtype','base');
    $tinc1 = make_colour('azure');
    $tinc2 = make_colour('argent');
    $mod = make_mod('ofnum','4');
    $div = $dom->createElement('division');
    $tinc = get_child($item,'tincture');
    $div->setAttribute('type', 'bar');
    $div->setAttribute('subtype', 'barry');
    $div->setAttribute('linetype', 'wavy');
    $div->appendChild($tinc1);
    $div->appendChild($tinc2);
    $div->appendChild($mod);
    $tinc->replaceChild($div,$tinc->firstChild);
    $item->appendChild($tinc);
  }

  // humets (are bars couped)
  foreach ( $xpath->query("//ordinary[@subtype='humet']") as $item ) {
      $item->setAttribute('subtype','bar');
      $item->appendChild(make_mod('couped','both'));
  }

  // bar sinister (is really a bend sinister)
  foreach ( $xpath->query("//ordinary[@subtype='bar' and modifier/@name='sinister']") as $item ) {
    $item->setAttribute('type','bend');
    $item->setAttribute('subtype','bend');
  }
  
  // A charge en soleil means placed on the sun
  foreach ( $xpath->query("//charge[modifier/@name='ensoleil']") as $item ) {
    $sun = $dom->createElement('charge');
    $sun->setAttribute('type','celestial');
    $sun->setAttribute('subtype','sun');
    $sun->setAttribute('number', '1');
    $tinc = $dom->createElement('tincture');
    $tinc->appendChild($dom->createElement('proper'));
    $sun->appendChild($tinc);
    $with = make_mod('on');
    $with->appendChild(deep_copy($item));
    $sun->appendChild($with);
    $item->parentNode->replaceChild($sun,$item);
  }

  // on ordinary another of the first => voided
  foreach ( $xpath->query("//ordinary/modifier[@name='on' and child::ordinary/@subtype='another']") as $item ) {
    $item->setAttribute('name','voided');
  }

  // an orle ermine is implemented as 12 ermine spots on an orle, similarly for other furs
  foreach ( $xpath->query("//ordinary[@subtype='orle' and tincture/fur]") as $item ) {
    $tinc = $xpath->query("tincture",$item);
    $fur = $xpath->query("tincture/fur",$item);
    $spot_col = null;
    $orle_col = null;
    switch ($fur->item(0)->getAttribute('name')) {
      case 'ermine':
        $orle_col = make_colour('argent');
        $spot_col = make_colour('sable');
        break;
      case 'erminois':
        $orle_col = make_colour('or');
        $spot_col = make_colour('sable');
        break;
      case 'ermines':
        $orle_col = make_colour('sable');
        $spot_col = make_colour('argent');
        break;
      case 'pean':
        $orle_col = make_colour('sable');
        $spot_col = make_colour('or');
        break;
    }
    if ( $orle_col != null ) {
      $item->replaceChild($orle_col,$tinc->item(0));
      $on = make_mod('on');
      $chg = $dom->createElement('charge');
      $chg->setAttribute('type','symbol');
      $chg->setAttribute('subtype','ermine-spot');
      $chg->setAttribute('number','12');
      $chg->appendChild($spot_col);
      $on->appendChild($chg);
      $item->appendChild($on);
    }
  }

  // Some sub-ordinaries can be doubled, by adding a "sinister" version
  $mirror_if_2 = array ( 'canton', 'gyron', 'gusset', 'graft', 'flaunch', 'square-flaunch', 'gore' );
  foreach ( $xpath->query("//ordinary[@number='2']") as $item ) {
    if ( in_array($item->getAttribute('subtype'), $mirror_if_2) ) {
      $item2 = deep_copy($item);
      $item2->appendChild(make_mod('sinister'));
      $item->parentNode->insertBefore($item2,$item);
    }
  }

  // Some treatments are actually (colour) semy de (object) 
  foreach ( $xpath->query("//treatment") as $item ) {
    $type = null;
    $subtype = null;
    $mod = null; $modval = null;
    switch ( $item->getAttribute('name') ) {
      case 'annuletty':
        $type = 'geometric';
        $subtype = 'annulet';
        break;
      case 'billetty':
        $type = 'geometric';
        $subtype = 'billet';
        break;
      case 'counter-billetty':
        $type = 'geometric';
        $subtype = 'billet';
        break;
      case 'estoilly':
        $type = 'geometric';
        $subtype = 'mullet';
        $mod = 'points'; $modval = '6';
        break;
      case 'fleury':
        $type = 'symbol';
        $subtype = 'fleurdelys';
        break;
      case 'goutty':
        $type = 'geometric';
        $subtype = 'goutte';
        break;
      case 'bezanty':
        $type = 'named-roundel';
        $subtype = 'bezant';
        break;
      case 'platy':
        $type = 'named-roundel';
        $subtype = 'plate';
        break;
      case 'hurty':
        $type = 'named-roundel';
        $subtype = 'hurt';
        break;
      case 'mullety':
        $type = 'geometric';
        $subtype = 'mullet';
        $mod = 'points'; $modval = '5';
        break;
    }
    if ( $type != null ) {
      $kids = $item->childNodes;
      $charge = $dom->createElement('charge');
      $charge->setAttribute('type', $type);
      $charge->setAttribute('subtype', $subtype);
      $charge->setAttribute('number', '1');
      if ( ($tinc2 = $kids->item(1)) == null ) {
        $proper = $dom->createElement('proper');
        $tinc2 = $dom->createElement('tincture');
        $tinc2->appendChild($proper);
      }
      $charge->appendChild($tinc2);
      if ( $mod != null ) $charge->appendChild(makemod($mod,$modval));
      $charge->appendChild(make_mod('wflex','1'));
      $charge->appendChild(make_mod('hflex','1'));
      $semyde = $dom->createElement('semyde');
      $semyde->appendChild($kids->item(0));
      $semyde->appendChild($charge);
      $item->parentNode->replaceChild($semyde,$item);
    }
  }

  // charges blazoned "entire" can stretch as much as they want..
  foreach ( $xpath->query("//charge[modifier/@name='entire']") as $item ) {
    $item->appendChild(make_mod('hflex','9999'));
    $item->appendChild(make_mod('wflex','9999'));
  }

  // Bit of a fudge, look for 2 single charges, the second "in saltire", make them
  // look like they are both in saltire
  foreach ( $xpath->query("//charge[@number='1' and modifier/@param='insaltire']") as $item ) {
    if ( ($prev = $item->previousSibling) != null and $prev->nodeName == 'charge' and $prev->getAttribute('number') == '1' ) {
      $inbend = make_mod('arrangement', 'inbend' );
      $prev->appendChild($inbend);
    }
  }
  
  /*

  //
  foreach ( $xpath->query("//") as $item ) {
    ;
  }
*/  
}

?>