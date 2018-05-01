
////SETTING UP OUR POPUP  
//0 means disabled; 1 means enabled;  
var popupStatus = 0;  
    //loading popup with jQuery magic!  
function statesideloadPopup(){  
//loads popup only if it is disabled  
    if(popupStatus==0){  
        jQuery("#backgroundPopup").css({"opacity": "0.7"});  
        jQuery("#backgroundPopup").fadeIn("slow");  
        jQuery("#statesidepopup").fadeIn("slow");  
        popupStatus = 1;  
    }  
}  
//disabling popup with jQuery magic!  
function statesidedisablePopup(){  
//disables popup only if it is enabled  
    if(popupStatus==1){  
        jQuery("#backgroundPopup").fadeOut("slow");  
        jQuery("#statesidepopup").fadeOut("slow");  
        popupStatus = 0;  
    }  
} 
//centering popup  
function statesidecenterPopup(){  
//request data for centering  
var windowWidth = document.documentElement.clientWidth;  
var windowHeight = document.documentElement.clientHeight;  
var popupHeight = jQuery("#statesidepopup").height();  
var popupWidth = jQuery("#statesidepopup").width();  
//centering  
jQuery("#statesidepopup").css({  
    "position": "absolute",  
    "top": windowHeight/2-popupHeight/2,  
    "left": windowWidth/2-popupWidth/2  
});  
//only need force for IE6  
  
jQuery("#backgroundPopup").css({  
"height": windowHeight  
});  
  
}

jQuery(function(){
    //LOADING POPUP  
    //Click the button event!  
    jQuery("#search3").click(function(){  
    //centering with css  
    statesidecenterPopup();  
    //load popup  
    statesideloadPopup();  
    });  
    //CLOSING POPUP  
    //Click the x event!  
    jQuery("#statesidepopupClose").click(function(){statesidedisablePopup();  })
    //Click out event!  
    jQuery("#backgroundPopup").click(function(){statesidedisablePopup(); });  
    //Press Escape event!  
    jQuery(document).keypress(function(e){  
        if(e.keyCode==27){statesidedisablePopup(); }  
      });      
})

jQuery(document).ready(function($) {
  $('.nav-toggle').click(function() {
    $('#nav-wrapper ul').slideToggle(250);
    return false;
  });
  $('.print-link').parent().wrap('<div class="VOICE_SKIP"></div>');
  if( ($(window).width() > 640) || ($(document).width() > 640) ) {
      $('#nav-wrapper li').mouseenter(function() {
        $(this).children('ul').css('display', 'none').stop(true, true).slideToggle(250).css('display', 'block').children('ul').css('display', 'none');
      });
      $('#nav-wrapper li').mouseleave(function() {
        $(this).children('ul').stop(true, true).fadeOut(250).css('display', 'block');
      })
        } else {
    $('#nav-wrapper li').each(function() {
      if($(this).children('ul').length)
        $(this).append('<span class="drop-down-toggle"><span class="drop-down-arrow"></span></span>');
    });
    $('.drop-down-toggle').click(function() {
      $(this).parent().children('ul').slideToggle(250);
    });
  }
});