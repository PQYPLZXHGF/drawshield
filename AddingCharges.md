# Introduction #

Charges in drawshield are completely described in a single php file, so it is reasonably straightforward to
add new charges.

## File and Folder Structure ##

Charges can be found in the "charges" folder of the shield sources folder, "shield". The "charges" folder may
contain any number of sub-folders, with any name. These folders exist solely as an aide to organising charges
into categories for developer convenience.

Within the sub-folders are charge files, each charges being described by a single php file, with the suffix ".inc".
The filename may be anything, but may not
start with the underscore character "_"._

Thus for example, the developer may choose to place the description of a calvary cross into the file:

```
/shield/charges/cross/calvary.inc
```

## Charge File Usage and Context ##

The charge file will be "included" directly in some other PHP code, and may be called multiple times, - thus
the file should consist **only** of
PHP statements. It should not contain function declarations or definitions, but may contain includes of
other files that abide by these same rules. These included files _must_ begin with the underscore character.

The objective of the PHP statements should be to populate an array called **$charge** with the keys shown below.
At the point of the inclusion the PHP context will be within a function, the only variables visible will
be **$node** and an empty **$charge** array. This means that the charge description may declare and use any
other named variables as required. The "including" function will immediately return the **$charge** array value
so any variables defined by the included file will immediately go out of scope.

Charge files will be included once at build time, and zero, one or more times at run time.

At build time the **$node** value will be null. The charge file may choose to behave differently depending
on the value of **$node**, for example only populating the "build time" keys indicated below when **$node** is
null, or perhaps more usefully, returning an indicative or example "body" key to show the general form
of the charge which can be used in automatically generated documentation.

At build time, there will also be a function called "get\_mod" available which locates and returns modifier values,
but this will always return null.

At run time the value of **$node** will be a DOM node of the type _charge_. It will have (as a minimum), attributes
_type_ and _subtype_ (which equate to the sub-folder and filename of the charge), and _number_, which is the
number of times the charge will be drawn. The node is part of the full BlazonML tree so may be navigated as
required to determine context within the shield, tinctures, modifiers and so on. In particular, the helper function
"get\_mod( $node, $name )" will be available which will return the value of a modifier named "$name", or null if there
is no such modifier. (It returns "true" if the modifier exists but has no explicit value).

The **$node** variable is passed by reference and so may be modified by the charge file if required (but only if
you really know what you are doing!).

## Charge Array Keys and Values ##

As noted above, the purpose of the charge file is to populate an array called **$charge** with various values
indexed by keys. The keys, and their expected values are shown below:

|**Key Name**|**Value Type**|**Optionality**|**Description**|**Usage**|
|:-----------|:-------------|:--------------|:--------------|:--------|
|patterns    |Array of strings|Required       |Search strings, see [Matching Words](SearchStrings.md)|Build time - populating the charge parsing array|
|modifiers   |Array of arrays|Optional       |The available modifiers for this charge, see below|Build time - populating the feature parsing array|
|doc         |String        |Description of the charge|Recommended    |Build time - added to auto-generated documentation|
|either      |Array of 1 or 2 strings|Optional       |Something of fudge to avoid ambiguity with ordinaries of a similar name, see below|Build time - populating the charge parsing array|
|width       |Integer       |Required for SVG|Width in SVG units of the charge|Run time - positioning of the generated SVG|
|height      |Integer       |Required for SVG|Height in SVG units of the charge|Run time - positioning of the generated SVG|
|body        |String        |Required for SVG|SVG code to draw the charge, within the coordinates given by height and width|Run time - see below|

Note that other keys may be added in future to allow for other output formats, and perhaps the SVG related elements
should have an "SVG_" prefix or something, but that is for the future..._

### Modifiers ###

### Use of the Either Key ###

The "either" key is used to help use resolve two parsing problems, firstly charges and ordinaries that begin with the same
word. For example,in **Azure, a cross cleche or** the cross is a charge, in **Azure, a cross cotticed or** it is an ordinary. If
this is the case for your charge then 'either' should be set to a sub-array containing at least one element, which can be anything.

Secondly, we also have some charges and ordinaries that are both known by the same word, and must be distinguished by context, for example **cross**, **fret** and **chevron**. If this is the case then 'either' should be a sub-array of two elements, the second
of which should be the "type" of the ordinary.

In most cases you won't need this, and I hope in time to replace the need for it entirely by combining the
charge and ordinary parsing code.