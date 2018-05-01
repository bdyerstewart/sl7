This Drupal 7 module creates a WYSIWYG widget that allows
a customized table of the federal poverty guidelines to
be inserted into a node or block.  The table references a 
centralized data source to keep the display current

The widget works with the WYSIWYG module and has been tested 
and used with CKEditor.  There may be a configuration issue
with TinyMCE - required SCRIPT tags are being stripped on
insertion.  I have not had time to debug that issue - perhaps 
someone from the community will check it out and help resolve it.

Configuration:
1. After downloading and enabling the module, select the format(s) that
   you want the widget to be available from and edit the buttons.  Make sure 
   the Create Poverty Guidelines Display button is checked in the
   wysiwyg configuration at admin/config/content/wysiwyg.  In addition, 
   THE TEASER BREAK BUTTON MUST BE DISABLED.  There is currently a
   conflict with that program that strips SCRIPT tags from node body content.
2. The available percentages can be edited through the Pov_Guides configuration 
   at admin/config/content/pov_guides

Use:

When editing a node, select the Insert Poverty Guidelines button from the WYSIWYG 
menu bar to insert the widget script into your content.  The insertion will happen 
at the current cursor position.  You can select multiple percentages by holding down
the CTRL key while clicking the desired values.  The display can be Annual, Monthly
or Weekly according to the dropdown selection.