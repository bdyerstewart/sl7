/*
############################################################
# Bits 'n Tuts Twitter Alert jQuery Plugin.					#
# Developed by Dave Earley.									#
# www.BitsnTuts.com											#
# October 2010												#
# Please Leave This Message Intact							#
############################################################
*/

/**
			 * Copyright (c) 2009 Mark S. Kolich
			 * http://mark.kolich.com
			 *
			 * Permission is hereby granted, free of charge, to any person
			 * obtaining a copy of this software and associated documentation
			 * files (the "Software"), to deal in the Software without
			 * restriction, including without limitation the rights to use,
			 * copy, modify, merge, publish, distribute, sublicense, and/or sell
			 * copies of the Software, and to permit persons to whom the
			 * Software is furnished to do so, subject to the following
			 * conditions:
			 *
			 * The above copyright notice and this permission notice shall be
			 * included in all copies or substantial portions of the Software.
			 *
			 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
			 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
			 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
			 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
			 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
			 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
			 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
			 * OTHER DEALINGS IN THE SOFTWARE.
			*/


			

			
			if(!window.Kolich){
				Kolich = {};
			}
			
			Kolich.Selector = {};
			// getSelected() was borrowed from CodeToad at
			// http://www.codetoad.com/javascript_get_selected_text.asp
			Kolich.Selector.getSelected = function(){
				var t = '';
				if(window.getSelection){
					t = window.getSelection();
				}else if(document.getSelection){
					t = document.getSelection();
				}else if(document.selection){
					t = document.selection.createRange().text;
				}
				return t;
			}
			
			Kolich.Selector.mouseup = function(){
				var st = Kolich.Selector.getSelected().toString();
				if(st!='' && st.length<30){
					jQuery("body").append("<div id='def_div'></div>");
					jQuery('#def_div').twitter_alert({
                        message: "<iframe src ='http://www.lawny.org/tools/proxy_loader.php?something="+st+"' width='80%' height=105 frameborder=0></iframe><font color=lightblue size=12>&#10006</font>   <font color=greenyellow size=2>read<b><font color=white>clearly.</font></b><sup>alpha</SUP></font>",
			fadeout_time: 4000 
                });
				}
			}
			
			jQuery(document).ready(function(){
				jQuery(document).bind("mouseup", Kolich.Selector.mouseup);
			});

jQuery.fn.twitter_alert = function (options, callback) {
        var defaults = {
                bg_colour: 'cornflowerblue',
                border_colour: 'cornflowerblue',
                text_colour: '#FFF',
                text_size: '24px',
                text_font: 'Georgia',
                message: this.html(),
                fadeout_time: 500,
                override_css: false,
				height: '50px'
        };
        var settings = jQuery.extend({}, defaults, options);
        return this.each(function () {
                jQuery(this).hide();
                var cssObj = {
                        'font-family': 'Arial, Helvetica, sans-serif',
                        'font-size': settings.text_size,
                        'color': settings.text_colour,
                        'background-color': settings.bg_colour,
                        'padding': '10px',
                        'height': '95px',
                        'border-bottom-width': 'thin',
                        'border-bottom-style': 'solid',
                        'border-bottom-color': settings.border_colour,
                        'position': 'fixed',
                        'z-index': '99999',
                        'left': '0px',
                        'top': '0px',
                        'right': '0px',
                        'filter': 'alpha(opacity=90)',
                        '-moz-opacity': '0.9',
                        'opacity': '0.9',
                        'line-height': settings.height,
                        'text-align': 'center'
                }
                if (settings.override_css == false) {
                        jQuery(this).css(cssObj);
                }
                jQuery(this).html(settings.message);
                jQuery(this).slideDown("slow");

jQuery('#def_div').click(function() {
  jQuery('#def_div').slideUp('slow', function() {
    // Animation complete.
  });
});




        });
};


