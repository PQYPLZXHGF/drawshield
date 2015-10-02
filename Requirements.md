# PHP Requirements #

Drawshield is written in PHP5. It is **NOT** compatible with PHP4. It uses the PHP5 DOM extension, but not XSL transforms.

The regression test suite uses the PEAR Text\_Diff extension.

The author tests on EasyPHP 5.3.10 on a Windows 7 (64 bit) host.

Other than the normal configuration settings, I have not made any
changes to the PHP.ini file.

# SVG Requirements #

Almost all open source SVG implementations seem to be broken in one way or another. The author targets
the latest stable releases of Firefox and Chrome under Windows XP to at least not crash, even if both do not
display everything correctly. I have  not tested the SVG implementation in IE9.

The SVG Viewer with the Oxygen XML Editor (a commercial product) is used as reference for valid SVG.
