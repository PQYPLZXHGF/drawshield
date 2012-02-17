<!DOCTYPE
    html
    PUBLIC
    "-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN"
    "http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd">
<!-- Assumes shield directory is in /include, change below if not -->
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
  <head>
    <title>
      Drawshield Demonstration
    </title>
  </head>

  <body>
    <h1>
      Draw a Shield
    </h1>
    <p>
      Enter a
      <strong>
        blazon
      </strong>
      into the box and click the
      <code>
        Create!
      </code>
      button. 
    </p>
    <form action="POST" id="myform">
      <table style="width:600px" summary="shield table">
        <tr>
          <td rowspan="3" style="width: 459px; text-align:center">
            <textarea name="blazon" rows="5" cols="50"></textarea>
          </td>
          <td style="width: 81px">
            <input type="button" name="createbutton" value="Create!" style="width: 90px"/>
          </td>
        </tr>
        <tr>
          <td style="width: 90px">
            <input type="button" name="textbutton" value="Save As File" style="width: 90px"/>
          </td>
        </tr>
        <tr>
          <td style="width: 90px">
            <select name="format" size="1">
              <option value="svg" selected="selected">
                SVG
              </option>
              <option value="blazonml">
                BlazonML
              </option>
              <option value="prepro">
                Prepro
              </option>
              <option value="svgtext">
                SVG(text)
              </option>
            </select>
          </td>
        </tr>
        <tr>
          <td style="text-align:center" colspan="2">
            <div id="shieldimg">
            </div>
            <p id="shieldcaption">
              Your shield here
            </p>
          </td>
        </tr>
        <tr>
          <td style="width: 459px;">
            <textarea name="searchterm" rows="2" cols="50"></textarea>
          </td>
          <td style="width: 81px">
            <input type="button" name="searchbutton"  id="searchbutton" value="Search" style="width: 90px"/>
          </td>
        </tr>
      </table>
    </form>
    <div id="resultstable"></div>
    <?php $basedir = basename(getcwd()); ?>
    <script type="text/javascript" src="XMLHttpRequest.js"></script>
    <script type="text/javascript">
      //<![CDATA[
      var xmlhttp = new XMLHttpRequest();
      var incDir = '/include/';
      var asText;
      var useId;
      function showerrors(evt) {
       var errorbox = document.getElementById("errorbox");
       if ( errorbox.getAttribute("visibility") == "hidden" ) {
         errorbox.setAttribute("visibility","visible");
       } else {
         errorbox.setAttribute("visibility","hidden");
       }
      }
      function updateSVG() { // Simple AJAX updater
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
            if ( (navigator.userAgent.indexOf( "iPad" ) > 0) ||
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
        }
      }
      function requestSVG(url,id) {
        useId = id;
        xmlhttp.open('GET', url, true);
        xmlhttp.onreadystatechange = updateSVG;
        xmlhttp.send(null);
      }
      // Set button actions
      document.forms['myform'].createbutton.onclick = function () {
        shieldCaption = document.getElementById('shieldcaption');
        shieldCaption.firstChild.nodeValue= document.forms['myform'].blazon.value;
        choice = document.forms['myform'].format.options.selectedIndex;
        format = document.forms['myform'].format.options[choice].value;
        requestSVG( incDir + '<?php echo $basedir; ?>/drawshield.php?nolog=1&format=' + format + '&blazon=' + encodeURIComponent(document.forms['myform'].blazon.value),'shieldimg');
      };
      document.forms['myform'].textbutton.onclick = function () {
        window.location.replace( incDir + '<?php echo $basedir; ?>/drawshield.php?asfile=1&nolog=1&blazon=' + encodeURIComponent(document.forms['myform'].blazon.value));
      };
      document.forms['myform'].searchbutton.onclick = function () {
        requestSVG( incDir + '<?php echo $basedir; ?>/dbquery.php?term=' + encodeURIComponent(document.forms['myform'].searchterm.value),'resultstable');
      };
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
    // Run automatically
    window.onload=requestSVG( incDir + '<?php echo $basedir; ?>/drawshield.php?nolog=1&blazon=','shieldimg');
 //]]>
</script>
</body>
</html>
