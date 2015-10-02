# Description #

When a division is applied to a shape it is partitioned into two or more sections and can have
either two or three tinctures. They can be applied to anything, but most commonly are applied to
the field. Some of the divisions may be further modified by specifying a [line type](LineTypes.md) which
draws the major division lines in a pattern rather than straight. Typically, only the larger divisions
can be drawn with variant line types, however all line types are accepted, if the program cannot draw
them they are silently ignored.

## Large Divisions of Two Tinctures ##

These divisions split the shield into two large areas.

The basic syntax is:


[Division](Division.md) [LineType](LineTypes.md) [Tincture](Tincture.md) **and** [Tincture](Tincture.md)



The available divisions are:

**chape**, **chausse**, **per-bend**, **per-bend sinister**,
**per-chevron**, **per-fess**,
**per-pale**, **per-pile**, **per-saltire**, **pily**, **pily-bendy**, **pily-bendy-sinister**,
**quarterly**, **quarterly-per-fess**, **quarterly-per-pale**

Instead of **per bend** you can use **party per bend** or **parted bendwise**, and similarly for the other divisions.

## Large Divisions of Three Tinctures ##


[Division](Division.md) [LineType](LineTypes.md) [Tincture](Tincture.md) **and** [Tincture](Tincture.md) **and** [Tincture](Tincture.md)


The available divisions are:

**per-pall**, **per-pall-reversed**, **tierced-in-pale**, **tierced-in-fess**

## Bar Type Divisions (Two Tinctures) ##

These divisions are made out of a variable number of bars, with the syntax


[Division](Division.md) {**of** [Number](Number.md)} [LineType](LineTypes.md) [Tincture](Tincture.md) **and** [Tincture](Tincture.md)


The available divisions are:

**barry**, **barry-pily**, **bendy**, **bendy sinister**, **paly**

It is an error if the given number is odd, less than 4 or greater than 20.

In addition, the following bar type divisions are available but it is not (yet) possible
to specify the number of bars:

**barry-bendy**, **barry-bendy-sinister**, **barry-indented the one in the other**, **paly-bendy**

## Patterned Divisions (Two Tinctures) ##

These divisions are a bit like [treatments](Treatment.md) but are of a fixed size. They are:

**chevronny** {**of** 4,5,6,7 or 8}, **fusily**, **lozengy**, **gyronny** {**of** 6,8,10,12 or 16}

**gyronny** without a number defaults to 8, **chevronny** defaults to 4.

# Combining Divisions #

It is possible to have two divisions on the same shield, where the second division
is **counterchanged** (i.e. of opposite colours to the first). For example:

```
Barry azure and or per pale counterchanged
```
![http://www.karlwilcox.com/images/wiki/division-ex1.png](http://www.karlwilcox.com/images/wiki/division-ex1.png)

# Points to Note #

Sometimes the existence of a division will affect the placement of charges on the
field, for example two charges placed on a field divided per bend will be placed
in the centre of each of the two triangular areas. If you _do not_ want this
behaviour place the charges **overall** (see [Marshalling](Marshalling.md)).


# Navigation #

Previous [Fur](Fur.md) Top [SupportedHeraldry](SupportedHeraldry.md) Next [Ordinaries](Ordinaries.md)



