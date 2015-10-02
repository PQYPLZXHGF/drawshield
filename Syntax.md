# Description #

Drawshield aims to be fairly flexible in use of punctuation, except
where it is necessary to clarify situations where there are two
or more possible interpretations.
Importantly, the punctuation scheme allows blazons in
[Parker's Glossary of Heraldry](http://www.heraldsnet.org/saitou/parker/) to be cut and pasted directly into Drawshield.

At present Drawshield does **NOT** support accented characters. Please replace all accented characters in blazons with their unaccented versions. This will be addressed in a future release.


# Special Characters #

| (whitespace) | Any whitespace character indicates the end of a word, dashes inside       words are also treated like whitespace so may be used freely, e.g. <em>fleur-de-lys</em>       and <em>fleur de lys</em> are equivalent. |
|:-------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| - :          | (dash and colon) Blazons often have the name of the family following the shield description, separated by a dash or colon. Everything after these characters is ignored. Note that the dash must be preceded by a space, otherwise the program will consider it part of a hyphenated word. |
| () `[]` {}   | (brackets) Everything within a matched pair of brackets is ignored. This allows parts of the blazon that the program cannot draw to be commented out, but still present in the blazon.                             |
| #            | (hash) Everything following a hash is ignored completely, and does not even appear in the shield caption                                                                                                           |
| ,            | (comma) This character should be used after each separate tincture, for example 	  the list of tinctures <em>per pall azure, grillage or and azure, ermine</em>. The word 	  <em>and</em> serves the same purpose. A comma should also be used to separate multiple charges, e.g. <em>a heart gules, in chief 3 pommes</em> |
| ;            | (semi-colon) This character can be used to indicate the end of the 	  description of each quarter of a quartered shield. It <em>must</em> be used if there is a charge that is <strong>overall</strong> the quartered shield. Without the semi-colon the program could not tell if the charge were to be placed over the final quarter of the shield, or over the whole shield.|

# Navigation #

Previous [SupportedHeraldry](SupportedHeraldry.md) Top [SupportedHeraldry](SupportedHeraldry.md) Next [Marshalling](Marshalling.md)