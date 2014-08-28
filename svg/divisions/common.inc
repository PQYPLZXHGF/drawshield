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

function makeDiv_common( $node, $div_num ) {

  $div_data = array (
    'per-fess' =>  array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' => array ( 'CH' =>'X-8Y700A1016c508e1016g508' , 'NC' =>'X-8Y500A1016c708e1016g708' )),
    // 'per-bend' => array ( 'div2' => array ( 'NC' => 'X0Y0B1414c200e1000g1200', 'CH' => 'X0Y300B1414e1000g900')),
    'per-bend' => array (  'link' => 'http://karlwilcox.com/parker/b/bend-per', 'div2' => array ( 'NC' => 'X-106Y-106B1714c100e1212g1312', 'CH' => 'X0Y300B1414e1000g900')),
    'per-bend-fracted' => array (  'link' => 'http://karlwilcox.com/parker/b/bend-per', 'div2' => array ( 'NC' => 'X200Y0B717e500B1131c100e1010g1410', 'CH' => 'X200Y300B717e500B717e1010g1310' )),
    'per-bend-sinister' => array (  'link' => 'http://karlwilcox.com/parker/b/bend-per', 'div2' => array ( 'NC' => 'X1000Y0c1200e1000g200H1414', 'CH' => 'X1000Y300c1000e1000H1414' )),
    'per-bend-sinister-fracted' => array (  'link' => 'http://karlwilcox.com/parker/b/bend-per', 'div2' => array ( 'NC' => 'X800Y0a200c1300e1000H1131e500H717', 'CH' => 'X800Y300a200c1000e800H717e500H717' )),
    'per-pale' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' => array ( 'NC' => 'X500Y0a500c1200e500G1200', 'CH' => 'X500Y200a500c1100e500G1100' )),
    'chape' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' => array ( 'NC' => 'V1X0Y0a1000c500F708D707g500', 'CH' => 'V1X0Y300a1000c500F708D707g500' )),
    'chausse' => '<path d="m500,1200 l500,-866 0,866 -1000,0 0,-866 500,866z" />',
    'paly-bendy' => '<path d="m 999,600 0,300 171,300 0,-300 z m -167,0 0,300 167,300 0,-300 z m -166,0 0,300 167,300 0,-300 z m -167,0 0,300 167,300 0,-300 z m -166,0 0,300 167,300 0,-300 z m -167,0 0,300 167,300 0,-300 z m -166,0 0,300 167,300 0,-300 z M 999,0 l 0,300 171,300 0,-300 z m -167,0 0,300 167,300 0,-300 z m -166,0 0,300 167,300 0,-300 z m -167,0 0,300 167,300 0,-300 z m -166,0 0,300 167,300 0,-300 z m -167,0 0,300 167,300 0,-300 z M 0,0 0,300 167,600 167,300 z" />',
    'per-chevron' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' =>  array ( 'NC' => 'V1X500Y500B848c500e1200g500H848', 'CH' => 'V1X0Y1275g200H707B708c200e1000' )),
    'per-chevron-inverted' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' =>  array ( 'NC' => 'V1X-100Y300a100B707H708c900a100e1200g900', 'CH' => 'V1X-100Y500a100B707H708c900a100e1200g900' )),
    'per-pall' => array (  'link' => 'http://karlwilcox.com/parker/p/pall', 'div2' => array ( 'NC' => 'X1000Y0c1200e600g700a100H707', 'CH' => 'X1000Y300c900e600g400a100H707' ),
                          'div3' => array ( 'NC' => 'X0Y0B707C700e500g1200', 'CH' => 'X0Y300B707C400e500g900' )),
    'per-pall-inverted' => array (  'link' => 'http://karlwilcox.com/parker/p/pall',  'div2' => array ( 'NC' => 'O1X500Y0a500c1100f707G600', 'CH' => 'O1X500Y200a500c800f707G400' ),
      'div3' => array ( 'NC' => 'O1X0Y1000H708B707c200e1000g200', 'CH' => 'O1X0Y1000H708B707c200e1000g200' )),
    'per-pile' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' => '<polygon points="1000,-200 500,1200 500,1400 1000,1400" />',
                          'div3' => '<polygon points="0,-200 500,1200 500,1400 0,1400" />' ),
    'per-saltire' => array (  'link' => 'http://karlwilcox.com/parker/p/party', 'div2' => array ( 'NC' => 'O1Q1X500Y500D848g1200B848   O1Q1X500Y500H848c1200F848', 'CH' => 'O1Q1X500Y800D848g1200B848   O1Q1X500Y800H848c1200F848' )),
    'pily-bendy' => array (  'link' => 'http://karlwilcox.com/parker/p/pily', 'div2' => array ( 'PLNC' => '<path d="M 0,1200 L 0,923 241,1111  0,750  564,1184  0,500  750,1121  0,170  962,956  180,0  1000,619  503,0  1000,384  750,0  1000,175  902,0 1000,0  1000,1200 z" />',
                     'PLCH' => '<path d="m 0,1200 0,-90 241,0 L 0,800 564,1180 0,605 750,1120 0,405 898,1030 130,300 1000,919 403,300 1000,684 640,300 1000,475 822,300 l 178,0 0,900 -1000,0 z" />',
                     'I1NC' => '<path d="M 0,1200 0,923 189,1030 0,750 509,1120 0,500 811,1180 0,170 1000,1010 180,0 1000,619 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'I1CH' => '<path d="m 0,1200 0,-120 247,0 L 6.13,970 509,1120 0,800 811,1180 0,470 994,1070 180,300 1000,881 503,300 1000,670 750,300 l 250,175 -98,-175 98,0 0,900 -1000,0 z" />',
                     'I2NC' => '<path d="M 0,1200 0,923 266,1170 0,750 497,1130 0,500 719,1060 0,170 947,933 180,0 1000,619 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'I2CH' => '<path d="M 0,1200 3.06,1080 266,1170 9.2,926 497,1130 15.3,720 676,1070 0,470 873,987 180,300 991,875 503,300 1000,684 750,300 l 250,175 -98,-175 98,0 c -3,294 -19,562 0,900 L 0,1200 z" />',
                     'Q2CH' => '<path d="M 0,1200 0,1010 318,1200 0,750 593,1200 0,500 831,1200 0,170 1000,1020 180,0 1000,619 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'Q2CH' => '<path d="M 0,1200 0,1060 318,1200 0,820 593,1200 0,600 831,1200 0,370 1000,1120 180,300 1000,919 503,300 1000,684 750,300 l 250,175 -98,-175 98,0 0,900 -1000,0 z" />',
                     'Q1CH' => '<path d="M 0,1200 0,1010 318,1200 0,750 593,1200 0,500 831,1200 0,170 1000,1020 180,0 1000,619 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'Q1CH' => '<path d="M 0,1200 0,1060 318,1200 0,820 593,1200 0,600 831,1200 0,370 1000,1120 180,300 1000,919 503,300 1000,684 750,300 l 250,175 -98,-175 98,0 0,900 -1000,0 z" />',
                     'Q3NC' => '<path d="M 0,1200 0,923 318,1200 0,750 593,1200 0,500 831,1170 0,170 1000,1020 180,0 1000,619 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'Q3CH' => '<path d="M 0,1200 0,923 318,1200 0,850 593,1200 9.2,748 785,1150 0,470 1000,1120 180,300 1000,919 503,300 1000,684 750,300 l 250,175 -98,-175 98,0 0,900 -1000,0 z" />',
                     'Q4NC' => '<path d="M 0,1200 1.8,955 261,1130 0,750 435,1070 0,500 626,974 0,170 809,841 180,0 980,592 503,0 1000,384 750,0 1000,175 902,0 l 98,0 0,1200 -1000,0 z" />',
                     'Q4CH' => '<path d="M 0,1200 0,1050 262,1130 0,850 423,1080 0,605 609,988 0,405 742,901 130,300 862,809 403,300 960,650 640,300 1000,475 822,300 l 178,0 0,900 -1000,0 z" />', )),
    'pily-bendy-sinister' => array (  'link' => 'http://karlwilcox.com/parker/p/pily', 'div2' => array (
                      'PLNC' => '<path d="M 1000,1200 L 1000,923 759,1111  1000,750  436,1184  1000,500  250,1121  1000,170  38,956  820,0  0,619  497,0  0,384  250,0  0,175  98,0 0,0 0,1200 z" />',
                      'PLCH' => '<path d="M 1000,1200 982,1040 759,1130 1000,850 436,1180 1020,661 250,1120 1000,445 104,1030 835,300 10.7,905 517,300 0,684 265,300 0,475 98,300 l -98,0 0,900 1000,0 z" />',
                      'I1NC' => '<path d="M 1000,1200 1000,963 725,1160 1000,750 516,1120 1000,500 293,1060 1000,170 53.3,939 820,0 0,619 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'I1CH' => '<path d="m 1000,1200 10,-100 -285,60 L 1000,940 516,1120 1020,728 293,1060 1000,470 105,971 820,300 0,879 497,300 0,684 250,300 0,475 98,300 l -98,0 0,900 1000,0 z" />',
                      'I2NC' => '<path d="m 1000,1200 0,-277 -158,87 L 1000,750 494,1120 1000,500 170,1180 1000,170 -7.98,987 820,0 0,619 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'Q1NC' => '<path d="M 1000,1200 1000,923 707,1200 1000,750 427,1200 1000,500 189,1200 1000,170 -1.85,987 820,0 0,619 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'Q1CH' => '<path d="m 1000,1200 0,20 L 777,1200 1000,970 507,1200 1000,740 189,1200 1000,470 -1.85,1080 820,300 0,889 497,300 0,684 250,300 0,475 98,300 l -98,0 0,900 1000,0 z" />',
                      'Q2NC' => '<path d="M 1000,1200 1000,923 707,1200 1000,750 427,1200 1000,500 189,1200 1000,170 -1.85,987 820,0 0,619 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'Q2CH' => '<path d="m 1000,1200 0,20 L 777,1200 1000,970 507,1200 1000,740 189,1200 1000,470 -1.85,1080 820,300 0,889 497,300 0,684 250,300 0,475 98,300 l -98,0 0,900 1000,0 z" />',
                      'Q3NC' => '<path d="M 1000,1200 1000,990 728,1140 1000,750 546,1070 1000,500 376,977 1000,170 170,821 820,0 24.5,604 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'Q3CH' => '<path d="m 1000,1200 0,-140 -226,80 L 991,885 577,1070 994,696 413,995 1000,470 271,901 820,300 150,794 497,300 39.8,647 250,300 0,475 98,300 l -98,0 0,900 1000,0 z" />',
                      'Q4NC' => '<path d="M 1000,1200 1000,923 759,1110 1000,750 647,960 1000,500 216,1150 1000,170 -1.85,984 820,0 0,619 497,0 0,384 250,0 0,175 98,0 0,0 l 0,1200 1000,0 z" />',
                      'Q4CH' => '<path d="m 1000,1200 0,-80 -241,-10 241,-60 -353,10 L 1000,861 216,1150 1000,470 -7.98,1070 820,300 0,879 497,300 0,684 250,300 0,475 98,300 l -98,0 0,900 1000,0 z" />')),
    'pily' =>  array (  'link' => 'http://karlwilcox.com/parker/p/pily', 'div2' =>  array ( 'NC' => '<path d="m 0,1200 L 0,0 125,800 250,0 375,1100 500,0 625,1100 750,0 875,800 1000,0 1000,1200 Z" />',
               'CH' => '<path d="m 0,1200 L 0,300 125,800 250,300 375,1100 500,300 625,1100 750,300 875,800 1000,300 1000,1200 Z" />')),
    'tierced-in-fess' => array(   'link' => 'http://karlwilcox.com/parker/t/tierce', 'div2' => array ( 'NC' => 'X0Y400A1000c800e1000g800',  'CH' => 'X0Y600A1000c600e1000g600' ) ,
                                 'div3' => array ( 'NC' => 'X0Y800A1000c400e1000g400',  'CH' => 'X0Y900A1000c300e1000g300' ) ),
    'tierced-in-pale' => array(   'link' => 'http://karlwilcox.com/parker/t/tierce', 'div2' => array ( 'NC' => 'X333Y0a667c1200e667G1200',  'CH' => 'X333Y200a667c1100e667G1100' ) ,
                                 'div3' => array ( 'NC' => 'X666Y0a337c1200e337G1200',  'CH' => 'X666Y200a337c1100e337G1100' ) ),
    'tierced-in-bend' => array (  'link' => 'http://karlwilcox.com/parker/t/tierce', 'div2' => array ( 'NC' => 'X-100Y-100a300B1131c600e1300g1200', 'CH' => 'X-100Y200a400B1131c300e1200g1100' ),
                                 'div3' => array ( 'NC' => 'X-200Y100B1697e1200g1200', 'CH' => 'X0Y400B1272e900g900' )),
    'tierced-in-bend-sinister' => array (  'link' => 'http://karlwilcox.com/parker/t/tierce', 'div2' => array ( 'NC' => 'X800Y-100a400c1400e1200g600H1131', 'CH' => 'X1100Y200c1100e1200g300H1131a400' ),
                                 'div3' => array ( 'NC' => 'X1200Y100c1200e1200H1697', 'CH' => 'X1000Y400c900e900H1272' )),
    'tierced-in-chevron' => array (  'link' => 'http://karlwilcox.com/parker/t/tierce', 'div2' => array ( 'NC' => 'V1X-100Y1200g500H848B849c500e1200', 'CH' => 'V1X-100Y1300g400H848B849c400e1200' ),
                                 'div3' => array ( 'NC' => 'V1X-100Y1300g100H848B849c100e1200', 'CH' => 'V1X-100Y1400g100H848B849c100e1200' )),
  );
  $name = $node->getAttribute('subtype');
  $linetype = get_mod($node,'linetype');
  $modifiers = '';
  // Order of these tests needs to match order of division names in the array above!
  if ( get_mod($node, 'inverted')) $modifiers .= '-inverted';
  if ( get_mod($node, 'sinister')) $modifiers .= '-sinister';
  if ( get_mod($node, 'fracted')) $modifiers .= '-fracted';
  if ( array_key_exists($name . $modifiers, $div_data))
    $name .= $modifiers;
  else
  draw_message ( 'warning', "Cannot draw $name as $modifiers" );
  if ( array_key_exists($name, $div_data) ) {
    $retval = $div_data[$name];
    if ( ($name == 'per-fess') and ($linetype == 'nebuly' or $linetype == 'potenty')) 
      $retval = 'X-100Y600A1200c608e1200g608';
    if ( is_array($retval) ) {
      if ( array_key_exists('link',$retval))
        draw_message('link',$name . ' ' . $retval['link']);
      if ( $div_num == 2 and array_key_exists('div2', $retval) ) {
        $retval = $retval['div2'];
      } elseif ( $div_num == 3 and array_key_exists('div3', $retval) ) {
        $retval = $retval['div3'];
      } else {
        $retval = '';
      }
    } elseif ( $div_num == 3 ) { // Not array, so there is no div3
      $retval = '';
    }
  } else {
    draw_message ( 'internal', "No division $name", __FILE__, __LINE__ );
    $retval = '<g/>';
  }
  return $retval;
}


?>
