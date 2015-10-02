# Introduction #

The main shield drawing engine is highly modular with fairly clean interfaces. Orchestration of the module execution is managed in the
top level program `drawshield.php`. The major modules, in their order of execution are as follows.

## Lexical Analyser ##

This is a straightforward tokeniser. The input string (taken from the GET parameters) is broken down into individual "words" separated by whitespace characters. The lexical analyser is also responsible for:

  * Converting accented letters into their unaccented forms
  * Discarding all punctuation, except for:
    * Commas and semi-colons, which are retained as individual tokens
    * Hyphens, which are treated as spaces
    * Brackets, the contents of which are ignored
    * Dashes and colons, which indicate the end of the blazon proper
    * Hash symbols, after which all further input is ignored
  * Converting all input to lower case

The interface to other modules is currently through a global array of strings, each containing a token, although this may change to a purely function based scheme in the future.

## Parser ##

This is a fairly "pure" parser, which groups tokens into "phrases" and builds an in-memory parse tree. Matched tokens are included in the parse tree in case the renderer needs them. Parsing errors are also included in the parse tree itself so that rendering can still continue where possible.

The only "heraldic" processing that the parser is also responsible for is:

  * Resolving back references (e.g. **of the first**)
  * Resolving forward references (e.g. **A chief and bend gules**)
  * Converting all number phrases into actual numbers

The interface to other modules is solely the parse tree, in the form of an in-memory XML document. A schema for this XML `blazonML.xsd` is available in the root directory of the source tree.

## Rewriter ##

This module operates on the parse tree, rewriting it in certain places to reduce the rendering problem. It does many different things, based on knowledge of blazonry, examples include:

  * Substitutions e.g. **inbar** means **inpale fesswise**
  * Replacing objects with corresponding ones, e.g. **ford** becomes **base barry wavy azure and argent**
  * Replacing some treatments by a field strewn with particular charges

The easiest way to see what this does is look at the code, which is well commented.

The interface to the other modules is also the in-memory copy of the XML parse tree, the rewriter still adheres to the blazonML schema.

## Renderer ##

In theory, there can many of these, each rendering the shield in a different graphical format. At present I have only implemented an SVG renderer and two, trivial, renderers that display the parse tree as XML text either before or after the rewriter operation.

Details of the SVG renderer can be found in a page I haven't written yet.

