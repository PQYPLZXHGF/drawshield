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
      newNode = document.importNode(xmlhttp.responseXML.firstChild, true);
      shieldImg.appendChild(newNode);
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

function showerrors(evt) { 
  var errorbox = document.getElementById("errorbox");
  if ( errorbox.getAttribute("visibility") == "hidden" ) {
    errorbox.setAttribute("visibility","visible"); 
  } else {
    errorbox.setAttribute("visibility","hidden"); 
  }
}
