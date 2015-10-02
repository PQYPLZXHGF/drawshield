# Installation Instructions #

All files should be placed into a folder named "shield" somewhere in your PHP include path,
(e.g. /www/include/shield). All file references in the drawshield code are relative to this
"shield" folder.

See [Usage](Usage.md) for information on how to call the drawshield program.

## Optional components ##

There is one sub-folder for each output format supported, if you only intend to produce SVG output
then you do not need the sub-folders "blazonml" and "prepro" - although you may wish to modify the
top-level file "drawshield.php" to match this more limited range of outputs.

(The sub-folder named "regress" is for regression testing only and is not necessary for operation -
regression testing can cause quite a CPU hit so it may be best to remove this folder in a production
environment).

## Other Information ##

See also the [Requirements](Requirements.md) page for the PHP environment that has been used for development.

# Testing the Installation #

The shield folder also contains a file "demopage.html". It contains some simple html elements and some Javascript to demonstrate how to call the program using AJAX. Note that the Javascript code assumes that drawshield has been installed in `/include/shield`, modify the code where indicated if this is not the case.

To use the demonstration, type in a blazon in the text box and click on the `Create!` button.