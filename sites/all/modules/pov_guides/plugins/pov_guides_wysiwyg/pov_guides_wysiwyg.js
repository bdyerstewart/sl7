// $Id
var this_id = null;
(function ($) {
/**
 * Wysiwyg plugin button implementation for pov_guides plugin.
 */
    Drupal.wysiwyg.plugins.pov_guides_wysiwyg = {
    /**
    * Return whether the passed node belongs to this plugin.
    *
    * @param node
    *   The currently focused DOM element in the editor content.
    */
    isNode: function(node) {
        return ($(node).is('img.pov_guides_wysiwyg-pov_guides_wysiwyg'));
    },

    /**
    * Execute the button.
    *
    * @param data
    *   An object containing data about the current selection:
    *   - format: 'html' when the passed data is HTML content, 'text' when the
    *     passed data is plain-text content.
    *   - node: When 'format' is 'html', the focused DOM element in the editor.
    *   - content: The textual representation of the focused/selected editor
    *     content.
    * @param settings
    *   The plugin settings, as provided in the plugin's PHP include file.
    * @param instanceId
    *   The ID of the current editor instance.
    */
    invoke: function(data, settings, instanceId) {
        this_id = instanceId;
        Drupal.wysiwyg.plugins.pov_guides_wysiwyg.insert_form(data, settings, instanceId);    
    },


    insert_form: function (data, settings, instanceId) {
        // Here's the meat of the new InsertGuidelines button
        // We'll create a div and create a form on it to allow the user to choose:
        //	One or more % of guideline columns
        //  Income period to display - Annual, Monthly or weekly
        // The form is created by creating a variable with the HTML as text and then using the InnerHTML property 
        // Submitting this form drops a customized javascript call into the underlying text field we're editing through FCKEditor
        //  with a PovertyGuidelines link to visually hold the space
        var povBack = document.createElement("div");
        povBack.id = "pov_background";
        document.body.appendChild(povBack);
        var newDiv = document.createElement("div");
        newDiv.id = "newDiv";
        document.body.appendChild(newDiv);
        document.getElementById("newDiv").style.display = "Block";
        var txt = '<div class="pov-guide-display">';
        txt = txt + '<form name="myform">';
        txt = txt + '<table width="100%" border="1" cellpadding="5" cellspacing="3">';
        txt = txt + '<tr width="100%" align="center">';
        txt = txt + '<td colspan="2" valign="middle">';
        txt = txt + '<h3>Please select information to configure Poverty Guideline Table</h3>';
        txt = txt + '</td>';
        txt = txt + '</tr>';
        txt = txt + '<tr>';
        txt = txt + '<td><h4>% of Federal Guidelines</h4>';
        txt = txt + "Multiple values can be selected<br>";
        txt = txt + "by holding the CTRL button as you click<br>";
        txt = txt + '</td>';
        txt = txt + '<td>';
        txt = txt + '<select class="pv_options" name="percent" multiple size=8>';
        var opts = Drupal.settings.pov_guides;
        var arrayopts = opts.split(",");
        for (var i=0;i<arrayopts.length;i++){
            var v = arrayopts[i];
            txt = txt + '<option value="' + v + '">' + v + '%</option>';
        }
        txt = txt + '</select>'
        txt = txt + '</td>'
        txt = txt + '</tr>'
        txt = txt + '<tr>'
        txt = txt + '<td><h4>Income Period</h4>'
        txt = txt + '</td>'
        txt = txt + '<td>'
        txt = txt + '<select name="period">'
        txt = txt + '<option value="annual">Annual</option>'
        txt = txt + '<option value="monthly">Monthly</option>'
        txt = txt + '<option value="weekly">Weekly</option>'
        txt = txt + '</select>'
        txt = txt + '</td>'
        txt = txt + '</tr>'
        txt = txt + '<tr align="center">'
        txt = txt + '<td colspan="2" valign="middle">'
        txt = txt + '<input name="finish" type="button" value="OK" onClick="gtguidelines(retmulti(document.myform.percent),document.myform.period.value)"></input>'
        txt = txt + '</td>'
        txt = txt + '</tr>'
        txt = txt + '</table>'
        txt = txt + '</form>'
        txt = txt + '</div>'
        document.getElementById("newDiv").innerHTML = txt
    }
    };
})(jQuery);
function gtguidelines(percent,period,lnoheader) {
    jQuery('.pov-guide-display').hide();
    jQuery('#pov_background').remove();

    //document.getElementById("pov-guide-display").style.visibility = "hidden";
    var js_file = "http://" + location.hostname + Drupal.settings.basePath + "sites/all/modules/pov_guides/pov_guides_display.js"; 
    var ctext = '<script type="text/javascript" src="http://statesidelegal.org/documents/currentGuidelines.js"></script>' ;
    ctext = ctext + '<script type="text/javascript" src="' + js_file + '"></script>' ;
    ctext = ctext + '<div class="guidediv" align="center">' ;
    ctext = ctext + '<a href="../povertyguidelines.htm">Poverty Guidelines</a>' ;
    ctext = ctext + '<script type="text/javascript">' 
    ctext = ctext + 'document.write(getguidelines([' + percent + '],"' + period + '"))</script></div>' ;
    Drupal.wysiwyg.instances[this_id].insert(ctext);
}
function formatCurrency(Num) {
        Num = '' + parseInt(Num);
        var temp1 = '';
        var temp2 = '';
        var count = 0;
        for (var k = Num.length-1; k >= 0; k--) {
                var oneChar = Num.charAt(k);
                if (count == 3) {
                        temp1 += ',';
                        temp1 += oneChar;
                        count = 1;
                continue;
                }
                else {
                        temp1 += oneChar;
                        count ++;
                        }
        }
        for (var k = temp1.length-1; k >= 0; k--) {
                var oneChar = temp1.charAt(k);
                temp2 += oneChar;
        }
        temp2 = '$' + temp2;
        return temp2
}
function retmulti(selObj){
  var selectedArray = new Array();
  var retval = "";
  var i;
  var count = 0;
  for (i=0; i<selObj.options.length; i++) {
    if (selObj.options[i].selected) {
      selectedArray[count] = selObj.options[i].value;
      count++;
    }
  }
  retval = selectedArray;
  return retval
}
function getBaseURL () {
   return "http://" + location.hostname;
}