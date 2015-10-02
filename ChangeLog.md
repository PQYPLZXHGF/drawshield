# Shield Release Notes #

Versions are numbered in three levels, as follows:

  1. The major version number, only changed on a ground-up re-write.
  1. The minor version number, changed on a significant rewrite of a major section of the code
  1. The sub-version, usually a letter, changed when a new feature is added or a correction is made.

## Updates ##

To receive updates on all the Drawshield suite of programs please subscribe to http://www.karlwilcox.com/blog/rss.

# Version 2.3e #

## New Features ##

Added field division per chevron inverted. The division parsing code has been generally tidied up and the various options and modifiers can now appear in any order.

Added charge question mark. Not actually a heraldic charge but used to mark missing tinctures. May however be useful if developing arms for Batman’s arch-rival, The Riddler.

You can now say on chargeA chargeB, which means the same thing as chargeA charged with chargeB.

## Bug Fixes ##

The pall inverted was not in the correct place, it is now. Further variant spellings have been added.

The not-understood words had disappeared from error messages. They are back.

## Internal Changes ##

BlazonML has been modified to give tinctures an "index" attribute, instead of relying on its position within the parse tree. Tincture and modifier elements can now be freely mixed in any order.

# Version 2.3d #

## New Features ##

Improved text letters, now work much more as described in Parker – e.g. a text ‘K’ gules . Can also use roman instead of text to get a nice serif font. If no tincture is given, sable is used

Added charges characters of the plant x, where x is one of Earth, Moon, Sun, Mercury, etc.

The sun in his splendour has become more splendid.

The demopage provided with the source code has been updated

## Bug Fixes ##

Resolved [issue 148](https://code.google.com/p/drawshield/issues/detail?id=148)

## Internal Changes ##

Pattern fills are required for colouring an ordinary or a charge by a division, but all browsers seem to have problems with this, and each browser has different problems! I have updated the various workarounds to give the best results I can. Firefox is probably the least buggy!


# Version 2.3c #

## New Features ##

Added charges **chess rook**, **castle**, **ox**, **ram {armed,unguled}**, **horse {unguled}**, **Virgin and Child**, **fir tree**, **salmon (trout)**, **boar {armed}**, **mill wheel**, **cog wheel**, **water wheel** and **paschal lamb**. Most of these charges have been adapted from Wikimedia Commons, appropriate attributions have been placed in title elements of these charges.

## Bug Fixes ##

All charges are now drawn a bit bigger. The lion rampant had incorrect dimensions internally.

# Version 2.3b #

## New Features ##

The charges **estoile**, **church bell**, **bomb {fired}**, **spear {hafted, pointed}**, **saxon crown** and **hawk bell** have been added

Also added the **gorge** or **whirlpool**. Although this is actually a charge I have implemented it as an ordinary since you can only have one of them and it occupies the whole field.

Better sizing of charges placed on a bend, e.g. the spear. You can also place 2 charges (like spears) either in saltire or on a saltire. These charges may be of different kinds, for example argent a sword and spear in saltire gules.

I am experimenting with stroke colours on charges, instead of black I am setting them to a mid gray. Comments on this are welcome! It would be possible to set the stroke on a per charge basis to some "opposite" colour from the fill if this would be better….?

Some browsers (e.g. Google Chrome) display the "title" of SVG elements in a box when you hover your mouse over them. I have used this facility to show some simple information, like the name of the ordinary or charge.I am hoping to integrate this more closely with Parker’s Heraldic Dictionary shortly.

## Bugs ##

Charges placed on a bend sinister are the wrong way up.

# Version 2.3a #

## New Features ##

Charges placed directly on the field may be blazoned entire, in which case they will occupy the whole width and height of the field.

Any number of charges may be blazoned as en soleil in which case they will shown surrounded by the rays of the sun

Added charges **caltrap**, **sun {in his splendor}**, **full moon**, **and moon {incresent|decresent|crescent}**.

Exactly 4 four charges may be arranged on the field **in quadrangle**.

## Internal Changes ##

Modified the intermediate XML (blazonML) so that the matched tokens are included as attributes in the appropriate element. This gives the renderer more information to work from, for example determining plurals or variant terms.

In general, I am also moving as much heraldic knowledge out of the parser and into the “rewriter” so it is all gathered in one place. For example, in this release the conversion of some treatments to “semy de (some charge)” has been moved into the rewriter.

# Version 2.3pre #

## Internal Changes ##

This version is functionally largely identical to 2.2c1 however it has been ported to PHP5. It has been rewritten to use PHP5 DOM and removed the need for external XSLT processing. Additionally, all ordinaries are now defined in separate files that are combined into a parse table in a separate "build" stage. (The same way charges are handled).

## New Features ##

The ordinary **tierce** may now be **couped (in base / chief)** and **lozengy**.

There is better handling of charges that can be recognised but not yet drawn (the name of the charge is shown in the correct colour and location on the shield). This allows me to add lots of charges so at least the parser will recognise them, even if the renderer cannot yet draw them.

# Prior Versions #

Prior Versions were numbered in four levels, as follows:

  1. The major version number, changed very infrequently
  1. The minor version number, changed on a significant rewrite of a major part of the code
  1. The sub-version (a letter), changed when the actual program code is altered in some minor way
  1. The sub-sub-version, changed when the program data is modified or added to, for example when a new charge is added or a placement corrected.

# Version 2.2c1 #

## Corrections ##

Fixed positions for charges **on a pale** ([issue 44](https://code.google.com/p/drawshield/issues/detail?id=44))

You can now use **bundle** (**of number**) charges with any charge, although it is usually ignored (except for
**arrows** and **reeds** at present), you can also say things **reed bundles**.

## New Features ##

Add synonyms for crosses mounted on steps ([issue 44](https://code.google.com/p/drawshield/issues/detail?id=44))

## Internal Changes ##

All charge description code has been re-written to make it easier to add new charges. All the information about to a
charge is now held in a single file. A script has been written to help convert inkscape drawings into the required
form automatically. I am working on another script that will automatically generate wiki documentation about the charges.

# Version 2.2b1 #

## Corrections ##

A single **bendlet**, **bar** or **pale** was being drawn too large ([issue 127](https://code.google.com/p/drawshield/issues/detail?id=127)).

Fixed the chevron counts on **chevronnelly** ([issue 170](https://code.google.com/p/drawshield/issues/detail?id=170)) - there were twice as many chevrons as there should have been.

**pendent** is no longer a synonym of **inverted** but has a specific meaning for certain charges

Ordinaries on a canton, and cantons coloured by divisions now fit better ([issue 96](https://code.google.com/p/drawshield/issues/detail?id=96)).

**as many** now only refers back to counts of charges, not numbers used in positioning ([issue 173](https://code.google.com/p/drawshield/issues/detail?id=173))

Automatic layout of charges in triangular arrangements has been fixed ([issue 185](https://code.google.com/p/drawshield/issues/detail?id=185))

## New Features ##

([Issue 191](https://code.google.com/p/drawshield/issues/detail?id=191)) When describing charges you can now freely mix _modifiers_ (like "points upwards") with _features_
(like "armed gules") and _subtypes_ (like "rampant), so you can do things like:

```
Azure, a lion or rampant, armed gules
Azure an arrow in bend or, barbed and feathered argent, point upward
```

Added charges {**smith's**} **anvil** ([issue 54](https://code.google.com/p/drawshield/issues/detail?id=54)), **chevronel couched sinister**, **chevronel couched dexter** ([issue 170](https://code.google.com/p/drawshield/issues/detail?id=170))

Added ordinaries **chevron inarched** ([issue 60](https://code.google.com/p/drawshield/issues/detail?id=60)) and **fillet** ([issue 118](https://code.google.com/p/drawshield/issues/detail?id=118))

Ordinaries and charges may be **debruised** (**depressed**) **with** (**by** or **of**) another ordinary, which will always be
drawn on top ([issue 25](https://code.google.com/p/drawshield/issues/detail?id=25)), and will also have a thin black border.

**Annulets** may be drawn **one within the other** ([issue 25](https://code.google.com/p/drawshield/issues/detail?id=25)).

Up to 20 charges can now be arranged automatically on the field.

## Internal Changes ##

I have rewritten the code and data that describe how charges are parsed, it is much cleaner and smaller.

# Version 2.2a5 #

## Corrections ##

Can use e.g. **bundle of 3 arrows**, however the number is usually ignored.

**chevronny** and variant line types on bars were broken. They have been fixed.

Improved **billet** ([issue 113](https://code.google.com/p/drawshield/issues/detail?id=113))

**erminois** and **pean** were incorrectly coloured ([issue 82](https://code.google.com/p/drawshield/issues/detail?id=82))

## New Features ##

Added charges **reed** and **bundle of reeds**, also **pick-axe** ([issue 172](https://code.google.com/p/drawshield/issues/detail?id=172)); and **columbine** ([issue 107](https://code.google.com/p/drawshield/issues/detail?id=107)) which
can be **proper** and have **flowers**, **buds**, **slipped**, **leaved**, **barbed** of different tinctures.

Added treatment **billetty counter billetty**

Added **gironny of 16** ([issue 31](https://code.google.com/p/drawshield/issues/detail?id=31))

Can put the word **of** in front of a colour (e.g. "a crown of gold")

## Other ##

The program now works on PHP5 (thanks to a Alexandre Alapetite's brilliant and useful script at
http://alexandre.alapetite.fr/doc-alex/domxml-php4-php5/index.en.html). When my web host moves
to PHP5 (or I move web hosts, whichever happens first) I will migrate fully and properly to PHP5.

# Version 2.2a4 #

## Corrections ##

Fixed issues 8, 7 (for Firefox only, falls foul of pattern fill bug in Chrome) and 34

## New Features ##

Added **ermine spot** ([issue 9](https://code.google.com/p/drawshield/issues/detail?id=9)) - sable if no colour given.

Added **platy** ([issue 28](https://code.google.com/p/drawshield/issues/detail?id=28)) and fixed **bezanty**.

Added **vairy** as a treatment ([issue 13](https://code.google.com/p/drawshield/issues/detail?id=13)) - needs two colours.

Added **crow volant**, **crow**, and **crow's head** and **crow rising** ([issue 11](https://code.google.com/p/drawshield/issues/detail?id=11)) which can be **beaked** and **legged**, and have a **proper** colour.

Added **covered cup**, slightly better drawing of **chalice** ([issue 62](https://code.google.com/p/drawshield/issues/detail?id=62))

Clarified and added some axes ([issue 38](https://code.google.com/p/drawshield/issues/detail?id=38)), all of which can have **handles**
{**hafts**, **staves**} and **blades** of different tinctures. Available axes are:

  * **addice** {**carpenter's axe**}
  * **battle axe**
  * **common axe** {**hatchet**}
  * **turner's axe**

If you just ask for an **axe** you will get the common axe.

Added the following synonyms:

  * **on each** for **charged with**
  * **as the** for **of the** (first etc.)
  * **like the** for **of the**
  * **so many** for **as many**
  * **(based) esquires** for **gyrons**
  * **edged** for **fimbriated**
  * **gutte** for **goutte** ([issue 29](https://code.google.com/p/drawshield/issues/detail?id=29))
  * **cup** for **chalice**

# Version 2.2a3 #

## Corrections ##

Fixes for issues 5 & 6. Charges are now properly placed on **inverted**, **abased** or **enhanced** ordinaries. The semi-colon is correctly interpreted
as the end marker for each quarter of a **quartered** shield.

# Version 2.2a2 #

## New Features ##

You may place **on** an ordinary **another** of a different colour, which is equivalent to **voided.**Thus "azure, on a bend or another of the first" is a long way of saying "azure a bend voided or".

Charges may now be given a list of positions, so for example the shield of POTTOCK **Azure, a saltire between in chief an arrow point upward argent, in the flaunches and base three hunting horns of the last** is drawn correctly.

**Swords** and **thistles** may now be **proper.**

Up to 12 charges may be placed **on a** or **in fess, pale or chief** and they may be **conjoined**. Those that are **in** may also be **throughout**.

## Corrections ##

Improved positioning of variant chevrons when a chief is present.

Charges arranged **pilewise** are also inverted.

**tressures** do not work at the moment.

## Internal Changes ##

If a charge or ordinary was filled with a division the resulting SVG code (although valid) was not displayed by Safari and caused Chrome to crash. The program uses slightly different SVG if these browsers are detected. It doesn't always display correctly but at least it doesn't crash.

The charge placement logic has been moved from the PHP code into an XSLT transform based on the intermediate blazonML data structure. This means that charge placement can be made dependent on <em>any</em> feature(s) of the shield, so for example **five mascles on a cross** can be given a different placement to five other things on a cross, or any other arbitrarily complex set of conditions.

# Version 2.2a1 #
## New Features ##
Added the special ordinary **ford (proper)**

Added **quarterly quartered** as a synonym for **gyronny of 8** (a **saltire** of this looks particularly nice).

Added charge **triangle {voided}**.

## Corrections ##

Divisions using bars, single diminutives and some charge positioning actions were broken. These have been fixed.

Instead of a drawing a specific charge for **fountain**, the parser replaces it with a **roundel barry wavy of six argent and azure.**

The internal size of the **fret** charge was wrong, causing it to be misplaced slightly.

# Version 2.2a0 #
## New Features ##

You can now place a charge **between** 2 to 5 other charges. For a charge between 2 others, they just form a line of 3; for the others, the main charge is drawn large and the others are drawn smaller, arranged around it. Quadrate (four equal armed) crosses are an exception, they may only be between 4 other charges and these are placed between the arms of the cross.

## Corrections ##

I have clarified the _layering_ of ordinaries and charges on the field. In order, (lowest first) they are:

  1. The field
  1. All ordinaries and charges not mentioned elsewhere, in the order that they appear in the blazon. These are moved down and scaled if there is a chief present.
  1. Any **chief** (+ associated charges thereon)
  1. Any **cantons** (+ associated charges thereon)
  1. Any **gyrons** (+ associated charges thereon)
  1. Any marks of cadency (only **label** is supported at the moment, but more will be added)
  1. (the debugging ordinary **grid** goes here)
  1. Anything blazoned as **overall**

**Bevilled** lines were not being drawn correctly in some directions. This has been fixed.

I am working to improve variant lines in general, for example in **quarterly** some line variants now correctly meet in the centre, but others need more work. It is proving very difficult to find a general solution that correctly meets up all variant lines in all situations!

## Internal Changes ##

I have separated the **parsing** (i.e. understanding) of the blazon from the drawing of it. The blazon is read and converted into a data structure (which happens to be based on XML) and the data structure is passed to a drawing routine which creates the shield image. This has a number of advantages:

  * More meaningful error messages and better error recovery
  * Ordinaries and charges can now be drawn _knowing_ exactly where they are in relation to all the other features of the shield, so they can sized and positioned appropriately (the previous versions did this to a certain extent but the method was a horrible mess of global variables).
  * In future, other output formats can be supported (in addition to SVG)

These changes have probably introduced a host of new bugs, and broken lots of things that used to work, but I'm sure it will be worth it in the end!

# Version 2.1.e4 #

## New Features ##

I've changed the error handling (again!). If an error is found a notification is displayed at bottom right of the shield. Clicking this will overlay detailed information. I've tried to add more detail in the error messages. Also, any program runtime errors are now reported as plain text. If you get a completely blank screen this usually means a program syntax error, which I can't trap but can look in my error logs - please e-mail me the offending blazon!

Added ordinaries **chief-couped-sinister** and **chief-couped-dexter**.

The **quarterly** division may have just the horizontal or vertical line type specified, e.g. **quarterly per fess dancetty azure and or**.

Added positions **in first|second|third|fourth quarter** (but not yet **in first and fourth quarters**, and they do not correctly respect a chief).

## Corrections ##

Layout fixes for charges on a saltire and cross.

Fix for charge features that have a different **default** colour to the body.

A spurious error message was generated if the number of charges that could be arranged differed between shields with and without a charge (e.g. 6 charges fit on a full bend, but only 5 on a bend with a chief present - trying to place 6 charges on either generated the error). This has been fixed.

Corrected bounding boxes for couped fess, pale, bend and chief

The ordinaries **Cross** and **fillet cross** now respect the presence of a chief.

## Internal Changes ##

The **box** debugging charge now displays the charge number instead of the word UP.

# Version 2.1e3 #

## New Features ##

Added ordinaries **chevron-debruised**, **chevron-couped**,  and **chevron-couched (sinister)**.

The **chevronny** division can now be **of 4|5|6|7|8** and can have line types applied.

## Corrections ##

When placing diminutives **on** ordinaries the number was being ignored. This has been fixed.

I have changed the behaviour if the number of diminutives is not given - if the diminutive is singular,
one is drawn, if it is plural then four are drawn. e.g. **azure bars or** draws 4 bars.

Further variant spellings added.

# Version 2.1e2 #

## New Features ##

Added charges **heart-flammant**, **heart-crowned** and **flames of fire**,
**rainbow**.

Added arrangements **in fess throughout** and **in pale throughout** (which only work for charges that are stretchy!) Also **barwise**.

## Corrections ##

**Nombril** was misspelt in the code, causing position **in nombril** to fail.

**Proper** is allowed as a tincture if a charge has a fixed colour (like fountain), i.e. you can now use **fountain** or **fountain proper**.

## Internal Changes ##

The random blazon generator is now less dumb about picking colours. This has
<a href='/index.php?page=randomnotes'>its own release notes</a>.

# Version 2.1e1 #

## Internal Changes ##

Minor tweaks to the javascript code mean that the program now displays correctly on
webkit based browsers (Chrome / Safari) and Opera.

As all site pages are now served as xhtml, the various shield applications have been
rewritten to avoid use of innerHTML.

# Version 2.1d1 #

## New Features ##

Most straight lines in divisions and ordinaries can now be drawn with all of
the variant line-types.

Ordinaries may be **voided** of a different tincture, e.g. **a fess or voided
vert**.

There have been a lot of changes to the layout algorithms.

Explanatory notes (title and desc elements) within the SVG have been improved,
as have the error messages.

Improved charge **arrow**, added **broad arrow**. Mullets may be **pierced
(voided)**.

Added ordinaries **gusset\*graft [in base](gusset.md)** and
**square flaunch**. Added fess, pale, bend, and chief  **lozengy**.
Most ordinaries may now be treble cotised and cotises may be drawn with line
types.

Added divisions **barry bendy (sinister)**barry invected, the one in the
other\*barry pily (sinister). Barry, paly and bendy divisions may now have
the number specified, up to 20.

Added treatment **hurty**.

A new arrangment is available, 2 4 or 6 charges can be positioned **in (the) flank(s)**

Individual bars, palets or bendlets may now be given separate line types, e.g. **2 bars the lower engrailed or**. Can use
lower, upper, dexter, sinister, first, last, inner or outer on up to 8 of each.

Fess, pale, bars and palets may be **couped** (both ends) or **couped in
chief\*couped in base** or **couped dexter / sinister** as appropriate.

Double clicking on the **create** button will draw the shield and display the
SVG in an alert box.

## Corrections ##

Fountain works again...

I misinterpreted **(counter-)Compony** as a type of division, it is really a special form of treatment.
It can be applied properly only to the fess, bend, chief, tierce or pale. It all other cases it just looks like
**checky** only bigger.

Escutcheon as a charge was fixed.

A **baton** is sinister, so added a dexter baton (can also use **baton couped**, but this is redundant).

A **canton** is always on top of other charges. I've also made it bigger to match the chief and line up with a fess.

The default arrangement for 9 charges was incorrect, it should be 3-3-3.

**mascle** was too thin. This has been fixed.

The yellow in **pean** and **erminois** now matches **or**.

Fixed **Save as SVG** so it does not try to open a new window first.

## Internal Changes ##

Variant shapes (e.g. those that change if they are inside a quartered field, like **bordure**) are
now implemented by an XSLT transform which selects the appropriate elements depending on their class
attributes - previously the program hacked
about with shape's internal SVG data. There is a longer discussion of this in the
<a href='?page=shielddoc'>internal program documentation</a>.

In a similar fashion, those things that change position when a chief is present are now also
implemented through the use of XSLT transforms. There is no longer any distorting **squashing** of ordinaries
and charges to fit beneath a chief, sizes and positions are re-calculated if a chief is present.

The debugging ordinary **grid** is clearer, sits on top of the chief and now honours the requested colour.

The SVG is now in-line with the HTML (previously it was inside an 

&lt;object&gt;

 tag). When pressing the create button
an AJAX request replaces the in-line SVG. This gets around a bug in Firefox 3.6
(<a href='https://bugzilla.mozilla.org/show_bug.cgi?id=521569'><a href='https://code.google.com/p/drawshield/issues/detail?id=21569'>Bug 521569</a></a>) in which object contents are not loaded.

# Version 2.1c1 #

## New Features ##

Major page reorganisation to add the new shield test and shield builder pages and separate
the random shield generator

## Internal Changes ##

The empty shield shown at the start is now generated by sending an empty blazon
(previously it was a separate file).

Fountain doesn't work at the moment...

## Corrections ##

The letter 'c' was missing.

Can now separate row numbers by **and** or commas, e.g. as in _4 roundels 2, 2 and 1 or_
# Version 2.1b2 #

## New Features ##

Added some bends and per-bends with line type modifiers, more to come.

Quick reference page now more compact.

## Corrections ##

Fess embattled was too narrow. Redrew treatments honeycombed, scaly, crusily and maily but
the last still needs more work.
# Version 2.1b1 #

## New Features ##

Added charges **bear's head {tongued} {muzzled}**stag's head**,**tiger {tongued} {armed}**unicorn {tongued} {armed}**

## Internal Changes ##

Added a key to charge feature **notpresent** which is used as an alternate
body if the feature is not mentioned in the blazon. If left blank, the feature is not drawn
unless explicitly mentioned in the blazon.

# Version 2.1a2 #

## New Features ##

Added charges **bee**, **tower**,  **arch**,  **altar**

Added an ordinary called **grid** which draws a grid over the shield to help with
debugging placement issues.

Created a page for some of the <a href='?page=shielddoc'>internal program documentation</a>.

## Corrections ##

Reorganised the list of charges in <a href='?page=shieldref'>the reference page</a>

# Version 2.1a1 #

## New Features ##

charges may be **charged with** other charges. Charge placement is not always sensible,
but can be adjusted per charge - let me know!

An ordinary **on** a canton or a chief is scaled to fit, on all other ordinaries it is
superimposed (as before).

Added **pendent** as a synonym for **inverted** (which it isn't strictly, but
the effect is usually the same), added some synonyms of **paty** / **formy**.

Added **engrailed**, **angled**, **bevilled**, **embattled**
**potenty**, **escartelly**, as bar types.

The arrangment or placement may now be in front of the charges, between the charges
and their colour or after
the colour. This creates an ambiguity in, for exampleAzure a crown or in chief 3 pommes**.
Which charge is in chief? The program assumes that it is the first mentioned charge, unless a comma
is present after the**or

Added charge **dove**, which may be proper.

Bordures and tressures now respect their enclosing spaces when quartered or impaled.
Double tressures still to do

**Bug Fixes**

You could place charges **on** an ordinary or **between** and ordinary, but not
both. This has been fixed.

## Corrections ##

All quadrate crosses have been redrawn and work correctly when coloured by divisions, furs or
treatments.

Redrawn crescent, and cross paty / formy

I am still in the process of redrawing all divisions and ordinaries with variant line types.
So far, all **per fess\*per pale** and **chief** are finished,
**fess** and **tierce** are almost complete, others only have the basic shape.

## Internal Changes ##

Uses clipping paths instead of masks in marshalled shields.

Charges are now only oriented to the bend, saltire and chevron if they are marked as such
in their meta-data.

# Version 2.1 #

This was a fairly major internal rewrite which added some features and probably broke quite
a few existing ones... The main changes are:

  * Improved SVG compatibility - I have tried to conform with Jonathan Watt's
<a href='http://jwatt.org/svg/authoring/'>SVG Authoring Guidelines</a>**, although I
still have some tidying up to do on some charges. The Petre shield now renders on Safari if downloaded, although
my whole site looks awful! I must look into this...
  * Rewrote the colour code so everthing is now either a plain fill or a pattern fill. This means that
all charges and ordinaries can be coloured with furs, treatments, divisions or just plain colours.
  * I am in the process of removing where possible the svg**use**element. It makes the consistent use of
patterns difficult and Mozilla [bug 467498](https://code.google.com/p/drawshield/issues/detail?id=67498) means that they don't always work correctly in Firefox anyway.
  * Similarly to the above I am trying to remove situations where one division or ordinary is scaled, rotated and
transformed to become another (e.g. originally**per bend**was**per fess**made longer and rotated 45 degrees). It makes use of patterns difficult and doesn't always give good results so
I am redrawing most of these. Many of the shapes using different line types like**arched**remain to be
done.**

## Corrections ##

Quarters 3 & 4 in a quartered shield were the wrong way around.

Placement of 4 items on a cross corrected.

The plain cross as a charge was missing a path data point.

Saltire and Per chevron have been redrawn correctly.

Bordures on a quartered shield now follow the border of their respective quarter.

Order of colours on pily and pily-bendy have been corrected.

Pily bendy with a chief - the points nearly but don't quite meet the edge. This needs to work like
Bordure and be aware of the enclosing space.

## Known Problems ##

Can only use plain colours on Quadrate crosses (they need to be redrawn to avoid **use** elements)

Tressure and double tressure need to work like bordure in quartered shields.

# Version 2.0c1 #

## Corrections ##

The divisions **pily-bendy** and **pily-bendy sinister** were redrawn to correctly match
up with the edge of the shield. The ordinaries **Cross\*Cross quarter pierced\*Cross
parted and fretty\*Cross tripartite and fretty** and their associated cotised and voided versions
contained an arithmetic error that drew them too high up. This has been corrected. Thanks to JimB for
noting these.

## New Features ##

Added charges - trefoil

Some additional alternate spellings have been added.

# Version 2.0c #

## New Features ##

Added letters, digits, words and numbers. Single letters and digits are drawn in a monogram, gothic style based on the font
**Verzierte Schwabacher** available from
<a href='http://www.dafont.com*>www.dafont.com'>.<br>
<br>
<h2>Internal Changes</h2>

Case in the Blazon is now preserved internally, so be careful in string comparisons!<br>
<br>
Identified the problem when some charges are coloured using a division, to do with SVG translations while they being drawn. I am<br>
working through existing charges to remove the translations.<br>
<br>
<h1>Version 2.0b</h1>

<b>Release 2.0b5</b>

Re-designed <b>fret</b> so it looks better when fimbriated, added <b>fret couped</b> and allow the use of <b>fret</b>
as a charge. For Corwyn, of (surprise, surprise) Green Fret Consulting.<br>
<br>
<b>Release 2.0b4</b>

Rewritten error handling - was using a PHP5 feature not supported by live host, curse you Yahoo!<br>
<br>
<b>Release 2.0b3</b>

New Features:<br>
<br>
Added the word <b>arranged</b>, optionally before specifying the arrangement of<br>
charges by rows. Can also separate numbers by commas and <b>and</b>.<br>
<br>
Allowed <b>ppr</b> as a synonym for proper.<br>
<br>
The colour definitions have been changed to match those at<br>
<a href='http://commons.wikimedia.org/wiki/User_talk:Phlegmatic'>
<a href='http://commons.wikimedia.org/wiki/User_talk:Phlegmatic'>http://commons.wikimedia.org/wiki/User_talk:Phlegmatic</a></a>, and all the<br>
colours in that list can now be used. Thanks to Corwyn for inspiring this one.<br>
<br>
Any charge can be prefixed by <b>demi</b> to produce just half of the charge<br>
(the top half of animals, the left half of objects). Thanks to Alex for<br>
suggesting this one.<br>
<br>
Bug Fixes:<br>
<br>
Fixed <b>mullet</b> so correctly parses, e.g. <b>Mullet of six of the same</b>.<br>
<br>
The <b>ermine</b> type furs have been re-drawn to better match the examples in<br>
Boutell's Heraldry and other sources. Thanks to Corwyn for pointing this out.<br>
<br>
<b>Release 2.0b2</b>

<b>lozengy</b> was implemented as a division, it should have been a treatment. Thanks to Iwain for pointing this out.<br>
<br>
<b>Release 2.0b1</b>

New Features:<br>
<br>
All ordinaries can now be given a division as a colour. If appropriate,<br>
the division is scaled to fit inside the ordinary.<br>
(EXPERIMENTAL) Charges may also be given a division as a colour, but<br>
this does not always work!<br>
Added divisions pily bendy and pily bendy sinister.<br>
<br>
<br>
Internal changes:<br>
<br>
Clarified the meaning of <i>palewise</i> and <i>fesswise</i>.<br>
Firstly, if the charge has metadata <code>turn_fesswise</code> or <code>turn_palewise</code> the<br>
boolean value of this determines whether the charge is turned. If there is<br>
no metadata, the charge aspect ratio is used, i.e. a tall charge is turned<br>
if described as <i>fesswise</i> but NOT turned if described as <i>palewise</i>.<br>
<br>
<h1>Version 2.0a</h1>

This was a complete re-write to use SVG graphics (earlier versions used GD bitmapped graphics built into PHP). All earlier<br>
features were preserved and many new ones added. The random shield generator was also rewritten.<br>
<br>
<h1>Version 1.1c</h1>

Further additions to charge placement, e.g. PILEWISE and IN PILE and BETWEEN works for a<br>
few ordinaries now (more to be added).<br>
<br>
Improved input handling, words in brackets ignored, hash to indicate end of input.<br>
<br>
Added ordinaries to the random shield generator.<br>
<br>
<h1>Version 1.1b</h1>

Confirmed that all crosses work (except cross formy throughout which needs to be<br>
re-drawn)<br>
<br>
Added <b>crosslet(s)</b> as a synonym for cross but only when referring to a<br>
cross as a charge, not as an ordinary<br>
<br>
Added error handler to return PHP error message in an image, and improved display of<br>
internal errors.<br>
<br>
Positions (<b>in dexter side</b> etc.) now work for all charges, and are ignored<br>
if the charges are explicitly positioned elsewhere (e.g. <b>on</b> or<br>
<b>between</b> ordinaries).<br>
<br>
Clarified meaning of <b>same, last, first and field</b>, see shield information<br>
page for details.<br>
<br>
Fixed artifacts on shield when chief is present (used resize, not resample)<br>
<br>
<h1>Version 1.1a</h1>

All colours, heraldic and modern<br>
<br>
All furs<br>
<br>
All field treatments, including semy of <i>charge</i>

Back references (but not with treatments!)<br>
<br>
Counterchanged<br>
<br>
All divisions (some modifiers give silly results but that is mostly a case of <b>garbage-in,<br>
garbage-out</b>)<br>
<br>
The diminutives<br>
<br>
All ordinaries (most modifiers work on most ordinaries, as above where it doesn't work it<br>
probably isn't sensible to ask for it anyway)<br>
<br>
Line types on divisions (NOT ordinaries)<br>
<br>
One ordinary ON another<br>
<br>
Charges and charge arrangement is incomplete and may not work<br>
<br>
Marshalling works but needs improvement to take account of the different shapes of partial<br>
shields. Dimidiated works best!