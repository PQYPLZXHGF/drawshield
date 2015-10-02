# Description #

Ordinaries are (typically) large shapes that occupy a significant portion of the [field](Field.md). They can be of
any [tincture](Tincture.md), and in most cases can themselves be split by a [division](Division.md).

The basic syntax is:

**a** {**an**} [Ordinary](Ordinaries.md) [Line Type](LineTypes.md) [Ordinary Modifiers](OrdinaryModifier.md) [Tincture](Tincture.md)


## Large Ordinaries ##

These are the large ordinaries, most of which can be drawn with variant [line types](LineTypes.md):

**base**, **bend**, **bend** (**bar**) **sinister**, **chevron**, **chevron inverted**, **chevron rompu**, **chevron throughout**,
**chevron couched**, **chevron fracted {disjoint**, **debruised}**, **chief**, **chief triangular**, **cross**,
**cross formy throughout**, **cross-fillet**, **cross quarter pierced**, **cross parted and fretty**,
**cross tripartite and fretty**, **fess**, **inescutcheon**,
**pale**, **pall**, **pile**, **pile inverted**, **quarter**, **quarter sinister**, **saltire**, **tierce**,
**tierce sinister**

There is also a special ordinary, **ford** which does not need a tincture. It is equivalent to
**a base barry wavy azure and argent**.

## Diminutives ##

Some of the larger ordinaries come in smaller versions, called diminutives that can appear multiple times. (If no number is
given, or the diminutive is plural, then 4 is assumed). Note that **between**
and **on** (see below) don't really make sense with these ordinaries. The available diminutives are:

**bar**, **bar gemel**, **palet**, **bendlet** {**scarpe**}, **chevronel**, **chevronel interlaced**
{**chevronel braced**}, **piles**

There are various nuances, which are shown in the table below:

| **Diminutive** | **Can be drawn with Variant Linetypes?** | **Number Range** |
|:---------------|:-----------------------------------------|:-----------------|
| bar            | Yes (see below)                          | 1 - 8            |
| bar gemel      | Yes                                      | 1 - 8            |
| palet          | Yes (see below)                          | 1 - 8            |
| bendlet        | Yes (see below)                          | 1 - 8            |
| chevronel      | No                                       | 1 - 4            |
| chevronel interlaced | No                                       | 2 - 4            |
| piles          | No                                       | 2 - 4            |

Not only can **bars**, **palets** and **bendlets** be given a [line type](LineTypes.md), but you can specify different line types for
different bars or whatever, using any combination of **the inner**, **the outer**, **the upper**, **the lower**, **the dexter**,
**the sinister**, **the first**, **the last**, **the inside**, **the outside**. For example:

```
sable 4 bars the outer invected the inner engrailed vert
```
![http://www.karlwilcox.com/images/wiki/ordinary-ex3.png](http://www.karlwilcox.com/images/wiki/ordinary-ex3.png)

Finally, note that a **bar** will draw a thick horizontal line but **bar sinister** will draw a **bend sinister**. This is the correct
heraldic usage.

## Sub-Ordinaries ##

These ordinaries are generally smaller and take up less of the space on the field.

**fret**, **escutcheon**, **orle**, **bordure**, **canton**, **gyron**, **baton**, **graft**, **gusset**, **shakefork**, **pall**, **tressure**, **double-tressure**, **flaunch**, **square flaunch**

They have various little nuances, which are captured in the table below

| **Sub-Ordinary** | **Can be drawn with Variant Linetypes?** | **Action if 2 requested** | **Action if > 2 requested** |
|:-----------------|:-----------------------------------------|:--------------------------|:----------------------------|
| fret             | No	                                      | Treated as a charge       | Treated as a charge         |
| escutcheon       | No	                                      | Treated as a charge       | Treated as a charge         |
| orle             | No	                                      | Number silently ignored   | Number silently ignored     |
| bordure          | No	                                      | Number silently ignored   | Number silently ignored     |
| canton           | Yes                                      | Dexter and sinister drawn | Number silently ignored     |
| gore             | Yes                                      | Dexter and sinister drawn | Number silently ignored     |
| gyron            | No                                       | Dexter and sinister drawn | Number silently ignored     |
| baton            | No	                                      | Number silently ignored   | Number silently ignored     |
| graft            | No                                       | Dexter and sinister drawn | Number silently ignored     |
| gusset           | No                                       | Dexter and sinister drawn | Number silently ignored     |
| shakefork        | No	                                      | Number silently ignored   | Number silently ignored     |
| pall             | No	                                      | Number silently ignored   | Number silently ignored     |
| tressure         | No	                                      | Number silently ignored   | Number silently ignored     |
| double-tressure  | No	                                      | Number silently ignored   | Number silently ignored     |
| flaunch          | No                                       | Dexter and sinister drawn | Number silently ignored     |
| square flaunch   | No                                       | Dexter and sinister drawn | Number silently ignored     |

## Combining Charges and Ordinaries ##

It is possible to combine [Charges](Charges.md) with [Ordinaries](Ordinaries.md) in various ways:

  * One or more charges placed around or within an ordinary
  * One or more charges placed on the ordinary
  * Some charges around the ordinary and some (other) charges on the ordinary

The basic syntax is as follows, where Ordinary indicates the normal syntax for an ordinary, as shown above.


[Ordinary](Ordinaries.md) **between** [Number](Number.md) [Charges](Charges.md)

[Ordinary](Ordinaries.md) **within** [Number](Number.md) [Charges](Charges.md)

**on** [Ordinary](Ordinaries.md) [Number](Number.md) [Charges](Charges.md)

**on** [Ordinary](Ordinaries.md) **between** [Number](Number.md) [Charges (between)](Charges.md) [Number](Number.md) [Charges (on)](Charges.md)


## Combining Ordinaries ##

It is also possible to place one ordinary on top of another:

**on** [Ordinary](Ordinaries.md) [Ordinary](Ordinaries.md)

Normally the second ordinary is only visible where it overlays the first one, look for example at:


```
Azure, on a bend or a fess gules
```
![http://www.karlwilcox.com/images/wiki/ordinary-ex1.png](http://www.karlwilcox.com/images/wiki/ordinary-ex1.png)

However, the **chief** and **canton** are often used as an augmentation or difference and so are treated a little
differently if they are the first ordinary - the second ordinary is scaled to fit entirely on the chief or
canton. Compare the blazon below with the one above:
```
Azure, on a canton or a fess gules
```
![http://www.karlwilcox.com/images/wiki/ordinary-ex2.png](http://www.karlwilcox.com/images/wiki/ordinary-ex2.png)

You may also use the construction:

**on** [Ordinary](Ordinaries.md) **another** [Tincture](Tincture.md)

This is exactly equivalent to:

[Ordinary](Ordinaries.md) **voided** [Tincture](Tincture.md)

See [Ordinary Modifiers](OrdinaryModifiers.md) for more details.

# Points To Note #

If an ordinary cannot be drawn with the specified line type it is drawn with straight edges but no error message is generated.

# Navigation #

Previous [Division](Division.md) Top [SupportedHeraldry](SupportedHeraldry.md) Next [OrdinaryModifiers](OrdinaryModifiers.md)

