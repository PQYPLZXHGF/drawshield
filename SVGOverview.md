# Important Note #

This is copied from old document and needs to be reviewed for the PHP5 version

> <h1>SVG Content</h1>
> <p>Charge creating code is expected to return a chunk of syntatically<br>
<blockquote>valid SVG code, it does not have to be enclosed within one element.<br>
One or more &quot;path&quot; elements are preferred, although<br>
simple shapes such as &quot;rect&quot; and &quot;polygon&quot; may<br>
be used if this helps. The area that will be filled by the charge<br>
colour should not have any &quot;fill&quot; set. Note that this not<br>
the same as setting the fill to &quot;none&quot;. If you must have<br>
the fill attribute it should be set to &quot;inherit&quot;.</p>
<p>Areas that are shaded (like shadows or details) may be filled<br>
as required. Lines may be stroked as required, although black is<br>
preferred.</p>
<p>The SVG code must <strong>NOT CONTAIN:</strong></p>
<ul>
<li>References to gradiants or anything else that requires use of the<br>
&quot;defs&quot; element.</li>
<li>&quot;use&quot; elements</li>
<li>Any elements that are transformed in any way<span>Inkscape<br>
can be used to convert all elements to paths and then combine then. This will<br>
remove the need for transforms.</span></li>
</ul>