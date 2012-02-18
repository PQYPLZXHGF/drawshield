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

function placements() {
  global $dom;

  $xpath = new DOMXPath($dom);

  $region = 'pl';
  
  foreach ( $xpath->query("//charge") as $item ) {
    $placement = ''; // This is what we are after, keep going until we find one
    // Set up parameters for this charge
    $chief = $xpath->evaluate("boolean(../../../ordinary[@subtype='chief'] or ../ordinary[@subtype='chief'])", $item);
    $conjoin = get_mod($item, 'conjoin');
    $rows = get_mod($item,'rows');
    $number = $item->getAttribute('number');
    $div_node = $xpath->query("parent::ord_chgs/parent::plain/tincture/division", $item);
    if ( $div_node->length > 0 ) {
      $underlying_div = $div_node->item(0)->getAttribute('subtype');
      if (get_mod($div_node->item(0),'sinister')) $underlying_div .= '-sinister';
      if (get_mod($div_node->item(0),'reversed')) $underlying_div .= '-reversed';
    } else {
      $underlying_div = null;
    }
    if (get_mod($item, 'between')) {
      $charge = $xpath->query("modifier[@name='between']/charge",$item);
      $number += $charge->item(0)->getAttribute('number');
    }
    if ( get_mod($item,'entire') )
      $boundingBox = $chief ? '0,300,1000,900' : '0,0,1000,1200';
    else
      $boundingBox = $chief ? '200,400,600,600' : '100,100,800,800';

    // Try various placement regimes

    // strewn on a field (don't need any placement)
    if ( $item->parentNode->nodeName == 'semyde' )
      $placement = 'i';
    
    // around another charge (no placement) - placement is below
    if ( $placement == '' && $xpath->evaluate("boolean(parent::modifier[@name='between']/parent::charge)",$item) )
      $placement = 'i';
    
    // between another charge (see above)
    if ( $placement == '' && $xpath->evaluate("boolean(modifier[@name='between']/charge[@number > 2])",$item ) ) {
      if ( $item->getAttribute('type') == 'quadrate' )
        $placement = 'x/x/x/x/200,300,160,160:500,600,600,600:800,300,160,160:200,900:800,900';
      elseif ( $chief )
        $placement = 'x/x/x/250,450,160,160:500,700,700,300:750,450,160,160:500,950/250,450,160,160:500,700,700,300:750,450,160,160:250,950:750,950/250,450,160,160:500,700,700,300:750,450,160,160:500,200:250,950:750,950';
      else
        $placement = 'x/x/x/250,200,300,280:500,550,700,400:750,200,300,280:500,1000/250,200,280,280:500,550,700,400:750,200,280,280:250,900:750,900/250,200,240,240:500,550,700,400:750,200,240,240:500,200:250,900:750,900';
    }
    
    // on an ordinary
    if ( $placement == '' && $xpath->evaluate("boolean(parent::modifier[@name='on']/parent::ordinary)",$item ) ) {
      $ordinary = $item->parentNode->parentNode;
      $ordtype = $ordinary->getAttribute('type');
      $ordsubtype = $ordinary->getAttribute('subtype');
      // Test order is important - check specific subtypes before generic type
      if ($ordsubtype=='bend' and $chief==false) $placement = '500,500,180,500,45/333.33,333.33,180,250,45:666.67,666.67/250,250,180,180,45:500,500:750,750/200,200,180,180,45:400,400:600,600:800,800/166.67,166.67,180,180,45:333.33,333.33:500,500:666.67,666.67:833.33,833.33/142.86,142.86,160,160,45:285.71,285.71:428.57,428.57:571.43,571.43:714.29,714.29:857.14,857.14';
      elseif ($ordsubtype=='bend' and $chief==true) $placement = '500,800,180,400,45/333.33,633.33,180,200,45:666.67,966.67/200,500,180,180,45:400,700:600,900/166.67,466.67,180,180,45:333.33,633.33:500,800:666.67,966.67/142.86,442.86,140,140,45:285.71,585.71:428.57,728.57:571.43,871.43:714.29,1014.29/s';
      elseif ($ordsubtype=='base') $placement = '500,950,500,240/333.33,950,300,200:666.67,950/333.33,900,160,160:666.67,900:500,1050/x/x/x';
      elseif ($ordsubtype=='chief' and get_mod($ordinary,'triangular')) $placement = '500,200,200,200/375,180,180,180:625,180/325,140,160,180:500,240:675,140/x/x/x';
      elseif ($ordsubtype=='canton') $placement = calcPlace('w',$number,$conjoin,'20,20,260,260');
      elseif ($ordsubtype=='gyron') $placement = '80,200,100,100/s/s/s/s/s';
      elseif ($ordsubtype=='chief') $placement = calcPlace('h',$number,$conjoin,'100,50,800,200');
      elseif ($ordsubtype=='fess') $placement = calcPlace('h',$number,$conjoin,'100,400,800,200');
      elseif ($ordsubtype=='gore') $placement = '130,700,160,160/130,600,140,140:130,800/x/x/x/x';
      elseif ($ordsubtype=='pale' and $chief==false) $placement = calcPlace('v',$number,$conjoin,'400,100,200,1000');
      elseif ($ordsubtype=='pale' and $chief==true) $placement = calcPlace('v',$number,$conjoin,'400,350,200,750');
      elseif ($ordsubtype=='tierce' and $chief==false) $placement = calcPlace('v',$number,$conjoin,'75,100,200,800');
      elseif ($ordsubtype=='tierce' and $chief==true) $placement = calcPlace('v',$number,$conjoin,'75,350,200,650');
      elseif ($ordsubtype=='chevron' and $chief==false) $placement = '500,400,100,100/250,625,100,100,45:750,625,,,-45/250,625,100,100,45:500,400,,,0:750,625,,,-45/200,675,100,100,45:400,475:600,475,,,-45:800,675/200,675,100,100,45:350,525:500,400,,,0:650,525,,,-45:800,675/150,725,100,100,45:250,625:350,525:650,525,,,-45:750,625:850,725';
      elseif ($ordsubtype=='chevron' and $chief==true) $placement = '500,550,100,100/250,775,100,100,45:750,775,,,-45/250,775,100,100,45:500,550,,,0:750,775,,,-45/200,825,100,100,45:400,625:600,625,,,-45:800,825/200,825,100,100,45:350,675:500,550,,,0:650,625,,,-45:800,825/150,875,100,100,45:250,775:350,675:650,675,,,-45:750,775:850,875';
      elseif ($ordtype=='cross' and $chief==false) $placement = '500,500,200,200//200,500,220,220:800,500:500,250/200,500,200,200:500,220:800,500:500,800//200,500,200,200:500,200:800,500:500,500:500,800:500,1050';
      elseif ($ordtype=='cross' and $chief==true) $placement = '500,700,160,160////250,700,160,160:750,700:500,450:500,700:500,950/x';
      elseif ($ordsubtype=='saltire' and $chief==false) $placement = '500,500,160,160/500,500,220,650,45:500,500,220,650,-45/x/250,250,160,160,-45:750,250,,,45:750,750,,,-45:250,750,,,45/500,500,160,160,0:250,250,,,-45:750,250,,,45:750,750,,,-45:250,750,,,45/x';
      elseif ($ordsubtype=='saltire' and $chief==true) $placement = '500,700,160,160/500,700,180,450,45:500,700,180,450,-45/x/250,450,160,160,-45:750,450,,,45:750,950,,,-45:250,950,,,45/500,740,160,160,0:250,490,,,-45:750,490,,,45:750,990,,,-45:250,990,,,45/x';
      elseif ($ordsubtype=='inescutcheon' and $chief==false) $placement = calcPlace('w',$number,$conjoin,'300,300,400,500');
      elseif ($ordsubtype=='inescutcheon' and $chief==true) $placement = calcPlace('w',$number,$conjoin,'300,600,400,250');
      elseif ($ordsubtype=='pile' and $chief==false) $placement = calcPlace('w',$number,$conjoin,'300,100,400,300');
      elseif ($ordsubtype=='pile' and $chief==true) $placement = calcPlace('w',$number,$conjoin,'300,400,400,300');
      elseif ($ordsubtype=='cross-formy' and $chief==false) $placement = 'x///100,500,120,120:900,500:500,100:500,900/s/s';
      elseif ($ordsubtype=='cross-formy' and $chief==true) $placement = 'x///100,700,120,120:900,700:500,400:500,1100/s/s';
      elseif ($ordsubtype=='quarter' and $chief==false) $placement = calcPlace('w',$number,$conjoin,'20,20,460,460');
      elseif ($ordsubtype=='quarter' and $chief==true) $placement = calcPlace('w',$number,$conjoin,'20,320,460,360');
      elseif ($ordsubtype=='orle' and $chief==false) $placement = 'x///////////130,300,80,80:870,300:500,120:500,1070:130,700:870,700:250,120:750,120:250,970:750,970:130,500:870,500';
      elseif ($ordsubtype=='orle' and $chief==true) $placement = 'x///////////130,800,80,80:870,800:500,420:500,1070:130,800:870,800:250,420:750,420:250,970:750,970:130,600:870,600';
      else $placement = 'n';
    }
    
    // on particular charges
    if ( $placement == '' && $xpath->evaluate("boolean(parent::modifier[@name='on']/parent::charge)",$item )) {
      $type = $item->parentNode->parentNode->getAttribute('type');
      $subtype = $item->parentNode->parentNode->getAttribute('subtype');
      // Test order is important - check specific subtypes before generic type
      if ( $type == 'quadrate' and $number <= 4)
        $placement = '///500,200,200,200:120,600:880,600:500,1000';
      elseif ( $subtype == 'moon' )
        $placement = '500,750,400,400/250,750,375,375:750,750/200,750,300,300:500,950:800,750/s/s/s';
    }
    
    // explicit arrangements
    if ( $placement == '' && ($arr = get_mod($item,'arrangement')) ) {
      if ( $arr == 'inbend' and $chief == false ) $placement = '500,500,400,800,45/333.33,333.33,180,180,45:666.67,666.67/250,250,200,200,45:500,500:750,750/200,200,200,200,45:400,400:600,600:800,800/166.67,166.67,160,160,45:333.33,333.33:500,500:666.67,666.67:833.33,833.33/142.86,142.86,140,140,45:285.71,285.71:428.57,428.57:571.43,571.43:714.29,714.29:857.14,857.14';
      elseif ( $arr == 'inbend' and $chief == true ) $placement = '500,800,350,700,45/333.33,633.33,180,180,45:666.67,966.67/200,500,180,180,45:400,700:600,900/166.67,466.67,180,180,45:333.33,633.33:500,800:666.67,966.67/142.86,442.86,180,180,45:285.71,585.71:428.57,728.57:571.43,871.43:714.29,1014.29/s';
      elseif ( $arr == 'inbendsin' and $chief == false ) $placement = '500,500,400,800,-45/333.33,333.33,180,180,-45:666.67,666.67/250,250,200,200,-45:500,500:750,750/200,200,200,200,-45:400,400:600,600:800,800/166.67,166.67,160,160,-45:333.33,333.33:500,500:666.67,666.67:833.33,833.33/142.86,142.86,140,140,-45:285.71,285.71:428.57,428.57:571.43,571.43:714.29,714.29:857.14,857.14';
      elseif ( $arr == 'inbendsin' and $chief == true ) $placement = '500,800,350,700,-45/333.33,633.33,180,180,-45:666.67,966.67/200,500,180,180,-45:400,700:600,900/166.67,466.67,180,180,-45:333.33,633.33:500,800:666.67,966.67/142.86,442.86,180,180,-45:285.71,585.71:428.57,728.57:571.43,871.43:714.29,1014.29/s';
      elseif ( $arr == 'inpale' and $chief == false ) $placement = calcPlace('v',$number,$conjoin,'200,100,600,1000');
      elseif ( $arr == 'inpale' and $chief == true ) $placement = calcPlace('v',$number,$conjoin,'200,350,600,750');
      elseif ( $arr == 'inchief' ) $placement = calcPlace('h',$number,$conjoin,'100,25,800,250');
      elseif ( $arr == 'inchiefthrough' ) $placement = calcPlace('h',$number,$conjoin,'0,25,1000,250');
      elseif ( $arr == 'inbase' ) $placement = '500,950,500,240/333.33,950,300,200:666.67,950/333.33,900,160,160:666.67,900:500,1050/x/x/x';
      elseif ( $arr == 'inflank' ) $placement = 'x/100,500,150,800:900,500/x/100,333,150,320:900,333:100,666:900:666/x/100,250,150,250:900,250:100,500:900,500:100,750:900,750/x';
      elseif ( $arr == 'inpall' and $chief == false ) $placement = 'x/x/250,250,180,400,-45:750,250,,,45:500,750,,,0/s/s/s';
      elseif ( $arr == 'inpall' and $chief == true ) $placement = 'x/x/250,550,180,400,-45:750,550,,,45:500,950,,,0/s/s/s';
      elseif ( $arr == 'inpalethrough' and $chief == false ) $placement = calcPlace('v',$number,$conjoin,'350,0,300,1200');
      elseif ( $arr == 'inpalethrough' and $chief == true ) $placement = calcPlace('v',$number,$conjoin,'350,300,300,900');
      elseif ( $arr == 'infess' ) $placement = calcPlace('h',$number,$conjoin,'100,300,800,300');
      elseif ( $arr == 'infessthrough' ) $placement = calcPlace('h',$number,$conjoin,'0,300,1000,300');
      elseif ( $arr == 'inchevron' and $chief == false ) $placement = 'x/250,625,160,160,45:750,625,,,-45/250,625,150,150,45:500,400,,,0:750,625,,,-45/200,675,140,140,45:400,475:600,475,,,-45:800,675/200,675,140,140,45:350,525:500,400,,,0:650,525,,,-45:800,675/150,725,120,120,45:250,625:350,525:650,525,,,-45:750,625:850,725';
      elseif ( $arr == 'inchevron' and $chief == true ) $placement = 'x/250,725,160,160,45:750,725,,,-45/250,725,150,150,45:500,500,,,0:750,725,,,-45/200,775,140,140,45:400,575:600,575,,,-45:800,775/200,775,140,140,45:350,625:500,500,,,0:650,625,,,-45:800,775/150,825,120,120,45:250,725:350,625:650,625,,,-45:750,725:850,825';
      elseif ( $arr == 'incross' ) $placement = 'x/x/x/500,200,200,200:250,500:750,500:500,800/500,200,200,200:250,500:500,500:750,500:500,800/x';
      elseif ( $arr == 'insaltire' ) $placement = '500,500,220,650,-45/500,500,220,650,45:500,500,220,650,-45/x/200,200,200,200,-45:800,200,,,45:200,800,,,45:800,800,,,-45/200,200,200,200,-45:800,200,,,45:500,500,,,0:200,800,,,45:800,800,,,-45/x';
      elseif ( $arr == 'inpile' ) $placement = 'x/x/250,250,300,300:500,600:750,250/x/x/250,200,200,200:500:750:333.33,500:666.67:500,800';
      elseif ( $arr == 'inorle' ) $placement = '///////////500,100,100,100:100,650:900,650:500,1050:100,100:900,100:100,400:900,400:200,900:800,900:300,100:700,100';
      elseif ( $arr == 'counter-passant' ) $placement = 'x/500,333.33,800,350:500,666.67,,,,,1/500,250,800,200:500,500,,,,,1:500,750,,,,,0/500,200,600,160:500,400,,,,,1:500,600,,,,,0:500,800,,,,,1/500,166.67,160,160:500,333.33,,,,,1:500,500,,,,,0:500,666.67,,,,,1:500,833.33,,,,,0/500,142.86,500,140:500,285.71,,,,,1:500,428.57,,,,,0:500,571.43,,,,,1:500,714.29,,,,,0:500,857.14,,,,,1';
      elseif ( $arr == 'pilewise' and $chief == false ) $placement = 'x/300,550,200,600,-30,1:700,,,,30,1/250,600,180,550,-30,1:500,550,,,0,1:750,600,,,30,1/200,650,150,500,-38,1:400,600,,,-16,1:600,,,,16,1:800,650,,,38,1/x/x';
      elseif ( $arr == 'pilewise' and $chief == true ) $placement = 'x/300,200,200,600,-30,1:700,,,,30,1/250,750,180,550,-30,1:500,700,,,0,1:750,750,,,30,1/200,850,150,500,-38,1:400,750,,,-16,1:600,,,,16,1:800,800,,,38,1/x/x';
      elseif ( $arr == 'quadrangle' and $chief == false ) $placement = 'x/x/x/250,250,400,400:750,250:250,750:750,750/x';
      elseif ( $arr == 'quadrangle' and $chief == true ) $placement = 'x/x/x/250,500,400,300:750,500:250,900:750,900';
      else $placement = 'i';
    }
    
    // between an ordinary
    if ( $placement == '' && $xpath->evaluate("boolean(parent::modifier[@name='between']/parent::ordinary)",$item )) {
      $ordinary = $item->parentNode->parentNode;
      $ordtype = $ordinary->getAttribute('type');
      $ordsubtype = $ordinary->getAttribute('subtype');
      // Test order is important - check specific subtypes before generic type -->
      if ($ordsubtype=='chevron-couched') $placement = 'n';
      elseif ($ordsubtype=='chevron' and get_mod($ordinary,'throughout')) $placement = 'n';
      elseif ($ordsubtype=='bordure') {
        $style = $rows ? 'r' : 'w';
        $bbox = $chief ? '100,400,800,600' :'100,100,800,800';
        $num = $rows ? $rows : $number;
        $placement = calcPlace($style,$num,$conjoin,$bbox);
      }
      elseif ($ordsubtype=='chevronel') $placement = 'x/x/200,200,180,180:500,900,240,240:800,200,180,180/x/x/x';
      elseif ($ordsubtype=='tressure') $placement = calcPlace('w',$number,$conjoin,'300,300,400,500');
      elseif ($ordsubtype=='chevron' and get_mod($ordinary,'rompu') and $chief==false) $placement = 'x/200,500,300,300:800,500,300,300/200,500,340,340:500,1050,200,200:800,500,340,340/200,500,200,240:500,140,200,160:500,1050,200,200:800,500,200,240/s/s';
      elseif ($ordsubtype=='chevron' and get_mod($ordinary,'rompu') and $chief==true) $placement = 'x/200,500,300,300:800,500,300,300/200,500,340,340:500,1050,200,200:800,500,340,340/s/s/s';
      elseif ($ordsubtype=='saltire' and $chief==false) $placement = 'x///150,500,180,180:850,500:500,150:500,850/x/x';
      elseif ($ordsubtype=='saltire' and $chief==true) $placement = 'x///150,700,180,180:850,700:500,380,140,140:500,1050,180,180/x/x';
      elseif ($ordsubtype=='chevron' and $chief==false) $placement = 'x/500,140,300,180:500,850,300,300/200,200,240,240:500,850,300,300:800,200,240,240/200,240,200,240:500,140,200,160:500,850,300,300:800,240,200,240/200,240,200,240:500,140,200,160:400,900,160,200:600,900:800,240,200,240/200,240,200,240:500,140,200,160:400,950,160,200:500,720:600,950:800,240,200,240';
      elseif ($ordsubtype=='chevron' and $chief==true) $placement = 'x/x/180,480,180,180:500,950,280,280:820,480,180,180/s/s';
      elseif ($ordsubtype=='bend' and $chief==false) $placement = 'x/750,250,250,250:250,750/750,250,250,250:200,700,200,200:400,900/200,650,200,200:400,850:600,150:800,350//600,200,140,140:800,200:800,400:200,600:400,800:200,800';
      elseif ($ordsubtype=='bend' and $chief==true) $placement = 'x/750,550,250,250:250,950,180,180/250,950,180,180:600,450,200,200:800,650/150,850,180,180:350,1050:600,450,200,200:800,650/600,450,140,140:800,450:800,650:200,900:350,1050:150,1050/s';
      elseif ($ordsubtype=='plain-cross' and $chief==false) $placement = 'x/175,750,180,300:825,750/x/175,200,180,160:825,200:175,840:825:840/s/s';
      elseif ($ordsubtype=='plain-cross' and $chief==true) $placement = 'x/200,450,180,160:800,450/x/200,450,180,160:800,450:200,940:800:840/s/s';
      elseif ($ordsubtype=='fillet-cross' and $chief==false) $placement = 'x/250,750,180,180:750,750/x/250,250,180,180:750,250:250,750:750,750/x/x';
      elseif ($ordsubtype=='fillet-cross' and $chief==true) $placement = 'x/250,500,200,200:750,500/x/250,500,200,200:750,500:250,900:750,900/x/x';
      elseif ($ordsubtype=='cross-formy' and $chief==false) $placement = 'x/250,750,180,180:750,750/x/250,250,180,180:750,250:250,750:750,750/x/x';
      elseif ($ordsubtype=='cross-formy' and $chief==true) $placement = 'x/250,950,180,180:750,950/x/250,450,180,180:750,450:250,950:750,950/x/x';
      elseif ($ordsubtype=='pile' and $chief==false) $placement = 'x/150,700,180,180:850,700/x/130,600,160,160:870,600:200,840:800,840/x/x';
      elseif ($ordsubtype=='pile' and $chief==true) $placement = 'x/150,900,180,180:850,900/x/130,800,160,160:870,800:200,1040:800,1040/x/x';
      elseif ($ordtype=='cross' and $chief==false) $placement = 'x/175,750,180,300:825,750/x/175,620,180,160:825,620:175,840:825:840/x/x';
      elseif ($ordtype=='cross' and $chief==true) $placement = 'x/175,850,180,300:825,850/x/175,720,180,160:825,720:175,940:825:840/x/x';
      elseif (($ordsubtype=='orle' or $ordsubtype=='double-tressure') and $chief==false) $placement = calcPlace('w',$number,$conjoin,'250,250,500,600');
      elseif (($ordsubtype=='orle' or $ordsubtype=='double-tressure') and $chief==true) $placement = calcPlace('w',$number,$conjoin,'250,550,500,300');
      elseif ($ordsubtype=='pale') $placement = 'x/175,550,300,800:825,550/x/175,383.33,300,350:175,716.67:825,383.33:825,716.67/x/175,300,250,200:175,550:175,800:825,300:825,550:825,800';
      elseif ($ordsubtype=='fess') $placement = 'x/500,150,400,180:500,850,400,300/333,150,200,200:666,150:500,850,400,300/333.33,150,300,180:667.67,150:333.33,850,300,300:667.66,850/250,150,200,180:500,150:750,150:333.33,850,300,300:667.66,850/250,150,200,180:500,150:750,150:250,850,200,300:500,850:750,850';
      elseif (($ordsubtype=='pall' or $ordsubtype=='shakefork') and $chief==false) $placement = 'x/220,760,240,400:780,760/220,760,240,400:500,150,180,180:780,760,240,400/220,600,200,180:780,600:220,840:780,840/220,600,200,180:780,600:500,150,180,180:220,840,200,180:780,840/x';
      elseif (($ordsubtype=='pall' or $ordsubtype=='shakefork') and $chief==true) $placement = 'x/220,1060,200,300:780,1060/220,1060,200,300:500,450,180,180:780,1060,200,300/220,900,200,160:780,900:220,840:780,1120/220,900,200,180:780,900:500,350,180,180:220,1120,200,160:780,1120/x';
      elseif ($ordsubtype=='flaunch' or $ordsubtype=='square-flaunch') $placement = calcPlace('n',$number,$conjoin,'300,300,400,600');
      else $placement = 'n';
    }
    
    // Explicit rows
    if ( $placement == '' &&  ($rows = get_mod($item, 'rows'))) {
      $placement = calcPlace('r',$rows,$conjoin,$boundingBox);
    }
    
    // On an underlying division
    if ( $placement == '' && $xpath->evaluate("boolean(parent::ord_chgs/parent::plain/tincture/division)", $item) ) {
      $number = $item->getAttribute('number');
      $division = $xpath->query("parent::ord_chgs/parent::plain/tincture/division", $item);
      $ofnum = get_mod($division->item(0),'ofnum');
      $subtype = $division->item(0)->getAttribute('subtype');
      $sinister = get_mod($division->item(0),'sinister');
      $reversed = get_mod($division->item(0),'inverted');
      if ($subtype=='per-bend' and $number==2 and $chief == false) $placement = 'x/300,700,350,350:700,300/x/x/x/x';
      elseif ($subtype=='per-bend' and $sinister and $number==2 and $chief == false) $placement = 'x/300,300,350,350:700,700/x/x/x/x';
      elseif ($subtype=='per-bend' and $sinister and $number==2  and $chief == true) $placement = 'x/300,600,350,350:700,1000/x/x/x/x';
      elseif ($subtype=='per-bend' and $number==2  and $chief == true) $placement = 'x/300,900,250,250:600,600/x/x/x/x';
      elseif (substr($subtype,0,9)=='quarterly' and $number==4  and $chief == false) $placement = 'x/x/x/250,250,300,300:750,250:250,750:750,750/x/x/';
      elseif (substr($subtype,0,9)=='quarterly' and $number==4  and $chief == true) $placement = 'x/x/x/250,450,260,260:750,450:250,850:750,850/x/x/';
      elseif ($subtype=='gyronny' and $ofnum==8 and ($number==8 or $number==4)  and $chief == false) $placement = 'x/x/x/200,500,300,300:500,200:800,500:500,800/x/x/x/200,400,160,160:400,200:600,200:800,400:800,600:600,800:400,800:200,600';
      elseif ($subtype=='gyronny' and $ofnum==8 and ($number==8 or $number==4)  and $chief == true) $placement = 'x/x/x/200,700,250,250:500,400:800,700:500,1000/x/x/x/200,600,150,150:400,400:600,400:800,600:800,800:600,1000:400,1000:200,800';
      elseif ($subtype=='gyronny' and $ofnum==6 and ($number==6 or $number==3)  and $chief == false) $placement = 'x/200,500,300,600:800,500/x/x/x/350,200,200,200:650,200:150,500:850,500:350,800:650,800';
      elseif ($subtype=='gyronny' and $ofnum==6 and ($number==6 or $number==3)  and $chief == true) $placement = 'x/200,800,300,400:800,800/x/x/x/350,450,180,180:650,450:150,700:850,700:350,950:650,950';
      elseif ($subtype=='per-chevron' and $number==3  and $chief == false) $placement = 'x/x/250,200,240,240:500,750,300,300:750,200,240,240';
      elseif ($subtype=='per-chevron' and $number==3  and $chief == true) $placement = 'x/x/250,500,220,220:500,950,300,300:750,500,220,220';
      elseif ($subtype=='per-pall' and $reversed and $number==3  and $chief == false) $placement = 'x/x/250,300,300,300:500,900:750,300/x/x/x/';
      elseif ($subtype=='per-pall' and $reversed and $number==3  and $chief == true) $placement = 'x/x/250,500,260,260:500,950:750,500/x/x/x/';
      elseif ($subtype=='per-pall' and $number==3  and $chief == false) $placement = 'x/x/250,700,300,300:500,200,300,300:750,700,300,300:/x/x/x/';
      elseif ($subtype=='per-pall' and $number==3  and $chief == true) $placement = 'x/x/250,850,260,260:500,500:750,850:/x/x/x/';
      elseif ($subtype=='per-saltire' and $number==3  and $chief == false) $placement = 'x/200,500,240,240:800,500/200,500,240,240:500,850,300,300:800,500,240,240/200,500,240,240:500,850,300,300:800,500,240,240:500,200,240,240/x/x';
      elseif ($subtype=='per-saltire' and $number>=2 and $number<=4  and $chief == true) $placement = 'x/200,700,220,220:800,700/200,700,220,220:500,950,260,260:800,700,220,220/200,700,220,220:500,950,260,260:800,700,220,220:500,450,220,220/x/x';
    }
    
    // in some positions, arrange in narrow rows
    if ( $placement == '' && $xpath->evaluate("boolean(modifier[@name='position'][@param='indexchief' or @param='insinchief' or @param='insinside' or @param='indexside'])", $item))
      $placement = calcPlace('n',$number,$conjoin,$boundingBox);
    
    // default, arrange in wide rows
    if ( $placement == '' ) 
      $placement = calcPlace('w',$number,$conjoin,$boundingBox);

    // Add the placement modifier
    $mod = make_mod('placement', $placement );
    $item->appendChild($mod);

    // If a location is specified, add it as a scaling box modifier
    if ( ($pos = get_mod($item, 'position'))) {
      switch ( $pos ) {
        case 'indexchief': $loc = '50,50,400,400'; break;
        case 'insinchief': $loc = '550,50,400,400'; break;
        case 'inmidchief': $loc = '250,50,400,400'; break;
        case 'indexbase': $loc = '150,750,350,400'; break;
        case 'insinbase': $loc = '500,750,350,400'; break;
        case 'inmidbase': $loc = '300,750,400,400'; break;
        case 'inhonpoint': $loc = '300,150,400,400'; break;
        case 'infesspoint': $loc = '250,250,500,500'; break;
        case 'innombril': $loc = '300,700,400,400'; break;
        case 'insinside': $loc = '50,200,400,600'; break;
        case 'indexside': $loc = '550,200,400,400'; break;
        case 'infirst': 
          switch ( $underlying_div ) { // TODO finish this lot off
            case 'tierced-in-pale': $loc = '50,200,233,233'; break;
            case 'tierced-in-fess': $loc = '350,50,300,300'; break;
            case 'tierced-in-bend': $loc = '750,50,250,250'; break;
            case 'tierced-in-bend-sinister': $loc = '50,50,250,250'; break;
            case 'tierced-in-chevron': $loc = ''; break;
            case 'per-pall': $loc = ''; break;
            case 'per-pile': $loc = ''; break;
            case 'per-pall-inverted': $loc = ''; break;
            case 'quarterly': // any type of quarterly in fact, but the default anyway, so do not need to test all
            default: $loc = '50,50,400,400'; break;
          }
          break;
        case 'insecond': $loc = '550,50,400,400'; break;
        case 'inthird': $loc = '50,550,400,400'; break;
        case 'infourth': $loc = '550,550,400,400'; break; // We only know how to place in a fourth quarter
        default: $loc = 'default';
      }
      $mod = make_mod('location',$loc);
      $item->appendChild($mod);
      // Add a count modifier (used in case of multiple locations)
      if ( $pos == 'inflank' )
        $mod = make_mod('count','2');
      else
        $mod = make_mod('count','1');
      $item->appendChild($mod);
    }
  }
}

?>