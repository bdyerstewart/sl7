
Description
------------------
Wraps the node body field in <!-- VOICE_BEGIN --> & <!-- VOICE_END --> tags to enable Tingwo text to speech conversion.
Then adds a button that opens a pop-up.


Installation
-----------------
Add the 'tingwo' directory in your modules directory (usually sites/all/modules). Enable the module (administration -> modules) and in the settings page (administration -> configuration -> media -> tingwo settings) set your Customer ID.
Choose the way to display the AUDIO button:
	- Form: do not need Javascript to be executed so it (in some cases) can be more compatible
	- Link: uses Javascript to open the new window so it can avoid the resize of the browser (in some configurations)
Choose in which content type you want to enable the module.
Choose the button image.
Finally choose where to display the button by selecting the block position (administration -> structure -> blocks) or simply by adding '<?php theme("tingwo_button", $node); ?>' in your template file.

