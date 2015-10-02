

# Introduce Me Gently #

When a web page displays a photograph on your computer screen you are downloading a file (typically ending in .jpeg or .png) which tells your computer what colour each pixel on your screen should be. Drawshield does not work this way, it use a file format called Scalable Vector Graphics, or SVG. In an SVG file are a series of instructions about drawing shapes and it is your computer that will work out what to draw and what colours each pixel should be. These instructions might be things like "draw a box from here to here and fill it with red", or draw a curved line from here to here and make it this wide, coloured black".

The advantages of using SVG are that it doesn't matter how big or small you make the SVG image, it will always display at the best quality (not blocky "jaggies" like you see if you scale up a photograph). Also, it is easier for the drawshield program to move and scale parts of the shield and give them different colours, you simply change the instructions.

The easiest way to create SVG is to use an Vector Graphics program, such as Inkscape, available from www.inkscape.org, or an online editor such as Aviary.com's Raven ( www.aviary.com/tools/raven ). It is beyond the scope of this document to teach you how to use these programs, there is plenty of on-line help available, and in the case of Inkscape there are several books now available.

I hope to expand this section to include a tutorial on how to create a simple charge using Inkscape in the near future.

# I'm an Expert, Just Tell Me #

Ideally, Drawshield charges are provided as a single SVG source file containing the charge image. The SVG should conform to the following guidelines, (see the notes below if you want to understand why these restrictions exist):

  * The image should occupy a space of around 100 to 800 units on each side, (1) any aspect ratio is acceptable
  * The leftmost point of the image should be at x=0, the topmost (or bottom-most, depends on your editor) point should be y=0 and all **drawn** points should be positive (curve control points may be negative) (2)
  * The image should not contain any references to "use" elements, or any gradients (3)
  * Areas that are to be coloured should be set to a pure red, green or blue colour, or have "fill" set to inherit. (4)
  * Areas that are always a fixed colour can be filled as required (e.g. transparent blacks are useful for shading areas)
  * Stroke colours can be set if required to a colour, or to "none", if not set they will be stroked in a light gray
  * If the charge has "features" that can be drawn in a different tincture then the main body and each feature should be enclosed in "g" (group) elements with a sensible name (5)

It would also be helpful if the following documentation was provided:

  * The name of the charge and any plurals or variant names and spellings (French spellings not required, I only implement English Heraldry at present)
  * Any named features that can be given different tinctures, along with their variant names and spellings
  * Any other words that are sometimes associated with it
  * If the charge can be drawn "proper" what are the proper tinctures for the body and any features
  * The name of the artist / author and any other credit or licensing information that is required

And finally, there are some optional items that are helpful hints but not mandatory:

  * Should this charge be turned to match the orientation of any ordinary that is placed upon (e.g. should it be turned bendwise if placed on a bend?) (YES/NO)
  * Can the charge be stretched to fill all the available space, or should it maintain its aspect ratio? (YES/NO or percentage)
  * If the charge is to be drawn "demi" should that be the top half (normal for animals) or the dexter half (normal for objects)?
  * If there are more charges placed on this charge, should they placed anywhere in particular?

An example SVG file is shown below.

## Notes ##

(1) The images are scaled as required so in theory they can be any size. In practice, and to save space, I round all SVG data to 2 decimal places, so if your image uses a very small range of units (e.g. between 0.0 and 1.0) it is likely that detail will be lost.

(2) Scaling and placement of images is done based on its bounding box, this is assumed to start at 0,0 and extend in the positive direction to the furthest points. This bounding box is only used for calculation, it is not clipped so anything outside the box (or large empty areas at the left, top or bottom) will cause positioning errors, e.g. when a charge is drawn "entire".

(3) Two reasons here, as the final SVG output is assembled from many fragments of SVG from different sources it is difficult to ensure that all "use" ID attributes are unique. Secondly, SVG applies fill **before** moving and scaling "use" elements. Consider a quadrate cross, in theory we could just draw the upper "arm" and then "use" rotated and moved copies for the other three arms. This works fine for flat fills but if the cross were filled with a division or a fur then each of the copies has its fill applied first, **then** is rotated, so furs etc. on the copied arms will point the wrong way.

(4) Fill colours are supplied by an enclosing "g" element.

(5) For example a lion might have a "body" group and other groups called "langued" and "armed"

# Converting From Other Formats #

Many existing charges are drawn as bitmaps (e.g. JPEGs or BMP files created with Photoshop or similar). Dawshield cannot use these directly as they typically consume a lot of space and they do not scale (up or down) particularly well. This is not a major problem as the Inkscape program can do a fairly good job of converting bitmap images into SVG that can be used by Drawshield. To get the best quality Inkscape conversion it helps if the image has the following characteristics:

  * If a line drawing, all areas closed (so they can be filled without "leaking")
  * If coloured, flat colours, with clearly defined edges, ideally each "feature" in a different colour
  * Shown against a white (or transparent) background
  * Provided with the same supporting documentation as the SVG shown below

Inkscape conversion does **not** work well with very complicated shapes or subtle gradations of shading. Ideally, we want a cartoon sketch, not a full colour photograph!

# An example SVG File #

```
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="300" height="400" >
<!--
Charge: Columbine(s)
Variants: Columbian Flower
Extra words: pendent / slips crossed / drooping (all can be ignored)
Features: slipped / stalked / leaved
                barbed
Proper: body and barbs #006DFF, slipped #00FB00
Turn if on Ordinary: True
Demi: treat as object
Stretching: 150% height, 150% width
Author: Karl Wilcox, released under a creative commons licence
-->
  <g id="slipped">
    <path d="m 76,19 -9,6 c 0,0 63,53 73,53 10,0 0,-11 0,-11 L 76,19 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="M 86,40 C 75,78 80,79 86,80 93,81 100,53 98,49 94,45 87,40 86,40 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 110,63 c -10,3 -15,26 -10,28 10,2 30,-14 20,-25 -10,-11 0,-1 -10,-3 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 130,72 c 0,0 10,38 10,38 10,10 20,0 20,-10 C 150,89 140,79 140,76 130,74 130,73 130,72 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 96,36 c 24,-12 64,-7 64,1 0,9 -50,10 -50,7 0,-3 -14,-7 -14,-8 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 140,67 c 20,5 50,14 50,26 0,17 -50,-11 -50,-14 10,-3 10,-5 0,-12 z"
       style="fill:#00ff00;fill-opacity:1;stroke:#000000;stroke-width:2;stroke-opacity:1" />
  </g>
  <g id="barbed">
    <path d="m 100,110 c -27,10 -39,50 -25,100 -1,50 -2,90 -19,140 64,-10 54,-70 54,-110 0,-20 -10,-60 -17,-90 6,-10 7,-30 7,-40 z"
       style="fill:#ff0000;fill-opacity:1;stroke:#000000;stroke-width:4;stroke-opacity:1" />
    <path d="m 200,110 c 10,0 20,10 30,80 0,30 20,110 40,160 -30,0 -60,0 -70,-80 -10,-60 -20,-50 -10,-80 10,-50 10,-80 10,-80 z"
       style="fill:#ff0000;fill-opacity:1;stroke:#000000;stroke-width:4;stroke-opacity:1" />
    <path d="m 89,160 c 5,30 21,120 11,140 0,10 -12,30 -12,30"
       style="fill:none;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 210,140 c -10,40 -20,60 -20,70 0,10 20,60 30,100 0,10 10,20 20,30"
       style="fill:none;stroke:#000000;stroke-width:2;stroke-opacity:1" />
  </g>
  <g id="body">
    <path d="m 150,120 c -10,-10 -50,-10 -40,30 10,30 10,80 0,170 0,10 -41,40 -34,40 7,10 64,0 64,-20 10,-20 10,-170 0,-180 -10,-10 -20,-20 -10,-30 0,0 20,-10 20,-10 z"
       style="fill:#0000ff;fill-opacity:1;stroke:#000000;stroke-width:4;stroke-opacity:1" />
    <path d="m 150,120 c 20,-10 40,-10 40,10 0,20 -10,130 0,150 10,30 10,100 30,100 10,0 -60,10 -70,-70 0,-70 0,-140 10,-140 20,-10 0,-50 -10,-50 z"
       style="fill:#0000ff;fill-opacity:1;stroke:#000000;stroke-width:4;stroke-opacity:1" />
    <path d="m 110,140 c 10,10 20,80 10,110 0,40 0,100 -10,100"
       style="fill:none;stroke:#000000;stroke-width:2;stroke-opacity:1" />
    <path d="m 180,140 c 0,0 0,60 0,100 0,40 10,120 20,130"
       style="fill:none;stroke:#000000;stroke-width:2;stroke-opacity:1" />
  </g>
</svg>
```

## SVG Example Notes ##

This example was produced by Inkscape. Inkscape adds more information such as individual IDs, a defs section and so on.
The drawshield program will automatically strip all of this stuff so I haven't included them here.