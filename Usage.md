# Drawshield Usage #

## Quick Summary ##

The main program is in the file "drawshield.php". The program expects to be called with an HTTP GET message, e.g.
(assuming drawshield has been installed a folder called "shield" in your PHP include directory.
```
GET /include/shield/shielddraw.php?blazon=Azure HTTP/1.1
```

## Input Paramters ##

### Required Parameters ###

There is one required parameter, **blazon**, this is the _blazon_ (heraldic shield description to be drawn).
Obviously it should be properly URL encoded so that spaces and other significant charaters are escaped, for
example by the Javascript `encodeURIComponent` function.

For details of the punctuation and layout of the blazon see the [Syntax and Punctuation Page](Syntax.md).

### Optional Parameters ###

At present, there are four optional paramters.

The parameter **size** determines the width (in pixels) of the resulting image, the default value is
500 pixels. (There is no need to specify the height as this will _always_ be 1.2 times the width). The size
is implemented by setting the **viewbox** attributes of the resulting SVG to the appropriate height and width.
This means that
the image SVG can be used "inline" on a page, without needing an enclosing element to specify its size.

The parameter **asfile**, if present, and with any value, will cause the resulting data (of whatever format)
to be download as a file. It does this by manipulating the HTTP headers to force a download with the filename
"shield.svg". It seems to work in most browsers.

The paramter **astext** , if present and with any value, forces the resulting data (of whatever format)
to appear as plain text, again, this is
done by manipulating the HTTP headers to suggest that download is in plain text format. If not present,
the HTTP is set to an appropriate format for the output data, for example SVG data will have the header
`Content-Type: image/svg+xml`.

The paramter **format** is intended to allow different output formats to be generated. The default value
is "svg".

At present, the only other valid values are:

**blazonml** which downloads as XML the intermediate form
produced by the parser, adhering to the schema BlazonML.xsd, a copy of which can be found in the
"shield" directory.

**prepro** also an XML format download, of debugging interest only which shows the intermediate form
after the XLST preprocessor has run. It also adheres to the BlazonML.xsd schema.

## Output Format ##

In normal operation, the program returns an image in the requested format, by default, an XML file
(include xml header) adhering to the SVG specification. The content type header is set to `text/xml`.

## Using Drawshield in a Web Page ##

### As a Static Image ###

This is the simplest (although least flexible way) of using drawshield - just use it inside an
object tag:

```
<object type="image/svg+xml"
   data="http://YOUR.SERVER.HERE/include/shield/drawshield.php?blazon=Azure%20a%20bend%20or"
   height="600" width="500" >
   <img src="no-svg-support.jpg" alt="Image if object not supported" />
</object>
```

In theory, you could then use Javascript to modify the **data** attribute of the object with a
new blazon (for example, from a text box filled in by the user). Unfortunately, Mozilla [bug 521569](https://code.google.com/p/drawshield/issues/detail?id=21569)
shows that although the Javascript executes correctly, the object is not updated. This approach
may be the simplest once this bug is fixed, as of this writing it was waiting to be picked up by
someone.