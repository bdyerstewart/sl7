
Description
------------------
Wraps the node body field in <!-- VOICE_BEGIN --> & <!-- VOICE_END --> tags to enable Phiware Voice text to speech conversion.
Then adds a button that opens a pop-up.

Author
-----------------
Daniele Madama <daniele.madama AT phiware DOT com>
Giulia Perozzo <giulia.perozzo AT phiware DOT com>
Paul Hart <paul.hart AT iriss DOT org DOT uk>

Installation
-----------------
Add the 'phiwarevoice' directory in your modules directory (usually sites/all/modules). Enable the module (administer -> build -> modules) and in the settings page (administer -> site configuration -> phiware voice settings) set your Customer Name.
Choose the way to display the AUDIO button:
	- Form: do not need Javascript to be executed so it (in some cases) can be more compatible
	- Link: uses Javascript to open the new window so it can avoid the resize of the browser (in some configurations)
Choose in which content type you want to enable the module.
Choose the button image.
Finally choose where to display the button by selecting the block position (administer -> build -> block) or simply by adding '<?php theme("phiwarevoice_button", $node); ?>' in your template file.

