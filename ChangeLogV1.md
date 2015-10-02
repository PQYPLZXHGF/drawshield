# Shield Release Notes #

For completeness, this is the changelog for version 1 of Drawshield. This used fixed bitmap graphics but has been
almost completely rewritten for version 2.

# Version 1.1c #

Further additions to charge placement, e.g. PILEWISE and IN PILE and BETWEEN works for a
few ordinaries now (more to be added).

Improved input handling, words in brackets ignored, hash to indicate end of input.

Added ordinaries to the random shield generator.

# Version 1.1b #

Confirmed that all crosses work (except cross formy throughout which needs to be
re-drawn)

Added **crosslet(s)** as a synonym for cross but only when referring to a
cross as a charge, not as an ordinary

Added error handler to return PHP error message in an image, and improved display of
internal errors.

Positions (**in dexter side** etc.) now work for all charges, and are ignored
if the charges are explicitly positioned elsewhere (e.g. **on** or
**between** ordinaries).

Clarified meaning of **same, last, first and field**, see shield information
page for details.

Fixed artifacts on shield when chief is present (used resize, not resample)

# Version 1.1a #

All colours, heraldic and modern

All furs

All field treatments, including semy of _charge_

Back references (but not with treatments!)

Counterchanged

All divisions (some modifiers give silly results but that is mostly a case of **garbage-in,
garbage-out**)

The diminutives

All ordinaries (most modifiers work on most ordinaries, as above where it doesn't work it
probably isn't sensible to ask for it anyway)

Line types on divisions (NOT ordinaries)

One ordinary ON another

Charges and charge arrangement is incomplete and may not work

Marshalling works but needs improvement to take account of the different shapes of partial
shields. Dimidiated works best!