/* Copyright 2010 Karl R. Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

// Javascript shield common bits


var xmlhttp;
var asText;
var useId;
var IEver = -1;
var shieldsize = 500;
var shieldtarget = 'shieldimg';
var captiontarget = 'shieldcaption';
var tabletarget = 'resultstable';

if (navigator.appName == 'Microsoft Internet Explorer')
{
  var ua = navigator.userAgent;
  var re  = new RegExp("MSIE ([0-9]{1,}[\.0-9]{0,})");
  if (re.exec(ua) != null)
    IEver = parseFloat( RegExp.$1 );
}

function updateSVG() {
	if ( xmlhttp.readyState == 4 && xmlhttp.status == 200 ) {
    var shieldImg = document.getElementById(useId);
    while ( shieldImg.hasChildNodes() ) {
      shieldImg.removeChild(shieldImg.firstChild);
    }
    if ( xmlhttp.responseXML == null ) {
      errorText = document.createTextNode(xmlhttp.responseText);
      errorPara = document.createElement('p');
      errorPara.appendChild(errorText);
      shieldImg.insertBefore(errorPara,null);
    } else {
      if ( IEver != -1 && IEver < 9.0 ) {
    	  if ( typeof shieldSize=="undefined" ) {
    		  var shieldSize = 500;
    	  }
      	var width = shieldSize;
      	var height = (shieldSize * 1.2);
      	height = height.toFixed();
        var obj = document.createElement('object', true);
        obj.setAttribute('type', 'image/svg+xml');
        obj.setAttribute('data', 'data:image/svg+xml,' + xmlhttp.responseText);
        obj.setAttribute('width', width.toString());
        obj.setAttribute('height', height.toString());
        obj.addEventListener('load', function() { ; }, false);
        svgweb.appendChild(obj, shieldImg);
      } else if ( (navigator.userAgent.indexOf( "iPad" ) > 0) ||
                  (navigator.userAgent.indexOf( "iPod" ) > 0) ||
                  (navigator.userAgent.indexOf( "iPhone" ) > 0) 
                ) {
         var svg = document.importNode(xmlhttp.responseXML.firstChild, true);
       } else {
         var svg = xmlhttp.responseXML.documentElement;
         svg = cloneToDoc(svg);
         //shieldImg.innerHTML = xmlhttp.responseText;
       }
       shieldImg.appendChild(svg);
    }
    asText = xmlhttp.responseText;
  }
}

function requestSVG(url,id) {
  if (!xmlhttp) xmlhttp = new XMLHttpRequest();
  if (!xmlhttp) return;
  useId = id;
  xmlhttp.open('GET', url, true);
  xmlhttp.onreadystatechange = updateSVG;
  xmlhttp.send(null);
}

function saveshield() {
   blazonText = document.getElementById('blazon').value;
   window.location.replace( '/include/shield/drawshield.php?asfile=1&blazon=' + encodeURIComponent(blazonText));
}

// Function provided by http://stackoverflow.com/users/405017/phrogz
function cloneToDoc(node,doc){
  if (!doc) doc=document;
  var clone = doc.createElementNS(node.namespaceURI,node.nodeName);
  for (var i=0,len=node.attributes.length;i<len;++i){
    var a = node.attributes[i];
    if (/^xmlns\b/.test(a.nodeName)) continue; // IE can't create these
    clone.setAttributeNS(a.namespaceURI,a.nodeName,a.nodeValue);
  }
  for (var i=0,len=node.childNodes.length;i<len;++i){
    var c = node.childNodes[i];
    clone.insertBefore(
      c.nodeType==1 ? cloneToDoc(c,doc) : doc.createTextNode(c.nodeValue),
      null
    ); }
  return clone;
}


function drawshield() {
   shieldCaption = document.getElementById(captiontarget);
   blazonText = document.getElementById('blazon').value;
   eol1 = blazonText.indexOf('#');
   eol2 = blazonText.indexOf('/');
   if ( eol1 == -1 ) { eol = eol2; }
   else if ( eol2 == -1 ) { eol = eol1; }
   else { eol = Math.min(eol1, eol2); }
   if ( eol != -1 ) { shieldCaption.firstChild.nodeValue = blazonText.slice(0,eol);}
   else { shieldCaption.firstChild.nodeValue= blazonText; } 
	 // Add a random number to force resend (avoids caching)
   requestSVG('/include/shield/drawshield.php?&size=' + shieldsize + '&rand=' + Math.random()
	   + '&blazon=' + encodeURIComponent(blazonText),shieldtarget);
}

function dbquery() {
  searchTerm = document.getElementById('searchterm').value;
  requestSVG('/include/shield/dbquery.php?term=' + encodeURIComponent(searchTerm),tabletarget);
}

// Arguments are:
// target - name of the div element that holds the shield image
// size - horizontal size of the shield, in pixels, if null = 500
// initial - the initial blazon to use
// caption - name of the paragraph element that contains the shield caption

function setupshield(target,size,initial,caption) {
  initBlazon="";
  if ( typeof(target) !== 'undefined' && target != null ) shieldtarget = target;
  if ( typeof(caption) !== 'undefined' && caption != null ) captiontarget = caption;
  if ( typeof(initial) !== 'undefined' && initial != null )
    initBlazon = '&blazon=' + encodeURIComponent(initial);
  else
    initial = "Your shield here";
  if ( typeof(size) !== 'undefined' && size > 0 ) shieldsize = size;
  shieldCaption = document.getElementById(captiontarget);
  shieldCaption.firstChild.nodeValue = initial;
	requestSVG('/include/shield/drawshield.php?nolog=1&size=' + shieldsize + initBlazon, shieldtarget);
}

