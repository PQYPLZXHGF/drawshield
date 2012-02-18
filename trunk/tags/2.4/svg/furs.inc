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


function makeFur ( $name ) {
  $fur_data = array (
    'counter-ermine' => array ( 222, 400, '<polygon points="0,0 222,0 222,400 0,400" fill="#050505"/>
        <g fill="#F0F0F0">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>
        <g transform="translate(111,200)" fill="#F0F0F0">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>'  ),
    'counter-potent' => array ( 333, 200, '<polygon points="0,0 0,200 333,200 333,0" fill="#F0F0F0"/>
        <polygon points="125,0 209,0 209,50 292,50 292,98 42,98 42,50 125,50" fill="#0504FF" />
        <polygon transform="scale(1,-1) translate(0,-200)" points="125,0 209,0 209,50 292,50 292,98 42,98 42,50 125,50" fill="#0504FF" />' ),
    'counter-vair' => array ( 250, 480, '<polygon points="0,0 0,480 250,480 250,0" fill="#F0F0F0"/>
        <polygon points="125,0 193,40 193,200 250,238 0,238 66,200 66,40" fill="#0504FF"/>
        <polygon transform="scale(1,-1) translate(0,-480)" points="125,0 193,40 193,200 250,238 0,238 66,200 66,40" fill="#0504FF"/>' ),
    'ermine' => array ( 222, 400, '        <polygon points="0,0 222,0 222,400 0,400" fill="#F0F0F0"/>
        <g fill="#050505">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>
        <g transform="translate(111,200)" fill="#050505">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>' ),
    'erminois' => array ( 222, 400, '<polygon points="0,0 222,0 222,400 0,400" fill="#EFD807"/>
        <g fill="#050505">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>
        <g transform="translate(111,200)" fill="#050505">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>' ),
    'pean' => array ( 222, 400, '<polygon points="0,0 222,0 222,400 0,400" fill="#050505"/>
        <g fill="#EFD807">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>
        <g transform="translate(111,200)" fill="#EFD807">
            <circle r="10" cx="55" cy="30"/>
            <circle r="10" cx="36" cy="55"/>
            <circle r="10" cx="74" cy="55"/>
            <path d="M 53 60 A 50 210 0 0,1 10,180 A 60 40 0 0,0 45,170 A 30 40 0, 0,0 55 200 A 30 40 0, 0,0 62,170 A 60 40 0 0,0 101, 180 A 50 210 0 0,1 57 60 Z"/>
        </g>' ),
    'potent' => array ( 333, 200, '<polygon points="0,0 0,400 333,400 333,0" fill="#F0F0F0"/>
        <polygon points="125,0 209,0 209,50 292,50 292,100 42,100 42,50 125,50" fill="#0504FF" />
        <polygon points="0,100 42,100 42,150 125,150 125,200 0,200" fill="#0504FF"/>
        <polygon points="209,200 209,150 292,150 292,100 333,100 333,200" fill="#0504FF"/>' ),
    'potent-counter-potent' => array ( 333, 200, '<polygon points="0,0 0,400 333,400 333,0" fill="#F0F0F0"/>
        <polygon points="125,0 209,0 209,50 292,50 292,98 42,98 42,50 125,50" fill="#0504FF" />
        <polygon transform="scale(1,-1) translate(0,-300)" points="0,100 42,100 42,150 125,150 125,200 0,200" fill="#0504FF"/>
        <polygon transform="scale(1,-1) translate(0,-300)" points="209,200 209,150 292,150 292,100 333,100 333,200" fill="#0504FF"/>' ),
    'vair' => array ( 250, 480, '<polygon points="0,0 0,480 250,480 250,0" fill="#F0F0F0"/>
        <polygon points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>
        <polygon transform="translate(125,240)" points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>
        <polygon transform="translate(-125,240)" points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>' ),
    'vair-en-point' => array ( 125, 240, '<g transform="scale(0.5)">
            <polygon points="0,0 0,480 250,480 250,0" fill="#F0F0F0"/>
            <polygon points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>
            <polygon transform="scale(1,-1) translate(125,-480)"
                points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>
            <polygon transform="scale(1,-1) translate(-125,-480)"
                points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>
        </g>'),
    'vair-in-pale' => array ( 250, 240, '<polygon points="0,0 0,240 250,240 250,0" fill="#F0F0F0"/>
        <polygon points="125,0 193,40 193,200 250,240 0,240 66,200 66,40" fill="#0504FF"/>'),
  );

  if ( ! array_key_exists($name, $fur_data) ) {
   $name = 'pean';
   draw_message( 'internal', "Cannot draw fur $name" );
  }
  return $fur_data[$name];
}
?>