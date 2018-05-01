(function ($) {
  Drupal.behaviors.slideblocks = {
    attach: function (context, settings) {
        if(typeof Drupal.settings.slideblocks_data.blocks !== 'undefined'){
            var blocks = Drupal.settings.slideblocks_data.blocks;
            //alert(blocks.length);
            if (Array.isArray(blocks)){
                var block_id = '#' + blocks[0];
            }
        }
        else {
            var blocks = Array();
        }
        var domattach = "body";
        var sidebar = '.region-sidebar-first';
        if (typeof Drupal.settings.slideblocks_data.content_area !== 'undefined' &&
                Drupal.settings.slideblocks_data.content_area > ""){
            domattach = Drupal.settings.slideblocks_data.content_area;
        }
        if (typeof Drupal.settings.slideblocks_data.sidebar !== 'undefined' &&
                Drupal.settings.slideblocks_data.sidebar > ""){
            sidebar = Drupal.settings.slideblocks_data.sidebar;
        }
        var origw = $(sidebar).css('width');
        var origmr = $(sidebar).css('margin-right');
        var tabloc = Drupal.settings.slideblocks_data.tabloc;
        var content_dom = Drupal.settings.slideblocks_data.content_dom;
        var orig_ml = $(content_dom).css('margin-left');
        var orig_mr = $(content_dom).css('margin-right');
        var content_margin = Drupal.settings.slideblocks_data.content_margin ;
        var top_margin = Drupal.settings.slideblocks_data.top_margin;
        var sidebar_threshold = Drupal.settings.slideblocks_data.sidebar_threshold;
        var css_margin = 'margin-left';
        slide_master(blocks);
        $( window ).resize(function() {
            //slide_master(blocks);
        });
        function slide_master(blocks){
            trigger = Drupal.settings.slideblocks_data.trigger_width;
            loc_class = 'slide-' + Drupal.settings.slideblocks_data.tabloc;
            if (loc_class == 'slide-left'){
                rotate_class = 'rotate90';
            }
            else{
                rotate_class = 'rotate270';
            }
            
            blockmax = 1;
            for (i = 0; i < blocks.length; ++i) {
                if (blocks[i].width > 0){
                    blockmax = Math.max(blockmax, blocks[i].width);
                }
            }
            if (blockmax > 1){trigger = blockmax;}            
            if ( $( window ).width() < trigger ){
                if ( $( window ).width() < 1040 ){
                    if ($('.sidebar-second').length==0){
                        if(content_dom > ''){
                            if (tabloc == "right"){ 
                                css_margin = 'margin-right';
                            }
                            $(content_dom).css(css_margin,parseInt(content_margin));
                            var existingmargin = $(content_dom).width();                    
                            if ($( window ).width() - existingmargin  < content_margin){
                                existingmargin = existingmargin - content_margin;
                            }
                            $(content_dom).css('width',parseInt(existingmargin));
                        }
                    }
                    else {
                        var existingmargin = $(content_dom).width();  
                        if ($( window ).width() - existingmargin < content_margin){
                            existingmargin = existingmargin - content_margin;
                        }
                        $(content_dom).css('width',parseInt(existingmargin));
                    }
                }
                $('.slide-master').remove();
                sub = "";
                sub += "<div class='slide-master " + loc_class + "'>";
                sub += "<div class='showslidetext slide-hide " + loc_class + "'></div>";
                sub += "<div class='slide-one " + loc_class + "'>";
                
                var i;
                for (i = 0; i < blocks.length; i++) {
                    if ($( window ).width() > blocks[i].width){
                        continue;
                    }
                    block_id = '#' + blocks[i].form_id;
                    //alert(block_id);
                    txt = $(block_id).html();
                    if (!txt ){
                        continue;
                    }
                    title = blocks[i].title;
                    if (! title){
                        title = $(block_id).find('h2').first().html();
                    }
                    sub += "<div class='slide-wrapper'>";
                    sub += "<div class='slide-content " + loc_class + "'>" + txt + "</div>";
                    sub += "<div tag='" + i + "' id='sl-" + blocks[i].form_id + "' class='slide-title " + loc_class + "'>";
                    sub += "<div class='rotate " + rotate_class + "'>" + title + "</div>";
                    sub += "</div></div>";
                    $(block_id).hide();
                    var calls = blocks[i].js_calls;
                    if (calls && calls != 0){
                        var callray = calls.replace( /\r\n/g, " " ).split( " " );
                        for( var k = 0; k < callray.length; k++ ) {
                            callx = callray[k];
                            var fn = window[callx];
                            fn();
                        }
                    }
                }
                sub += "</div></div>";
               
                $(domattach).prepend(sub);   
                $(domattach + ' .slide-master').find('h2').first().remove();
                $(domattach + ' .slide-master').find('.contextual-links-wrapper').first().remove();
                for (i = 0; i < blocks.length; i++) {
                    id = '#sl-' + blocks[i].form_id;
                    tabbackcolor = blocks[i].tabbackcolor;
                    tabcolor =  blocks[i].tabcolor;
                    if (tabbackcolor){
                        $(id).css('background-color', "#" + tabbackcolor);
                    }
                    if (tabcolor){
                        $(id).css('color', "#" + tabcolor);
                    }
                }
                $('.slide-master').css('margin-top',parseInt(top_margin));
                if (typeof $(".slide-title").swipe === "function"){
                    $(".slide-title").swipe( {
                      //Generic swipe handler for all directions
                      swipeRight:function(event, direction, distance, duration, fingerCount) {
                        $(this).click(); 
                      },
                      swipeLeft:function(event, direction, distance, duration, fingerCount) {
                        $(this).click(); 
                      }
                    });
                }
                $('.slide-title').click(function(){
                    if($(this).hasClass('slide-active')){
                        $('.showslidetext').hide('fast');
                        $('.slide-title').css('opacity','1');
                        $(this).removeClass('slide-active');
                    }
                    else{
                        $('.slide-title').removeClass('slide-active');
                        $('.slide-title').css('opacity','.4');
                        $(this).addClass('slide-active');
                        $(this).css('opacity','1');
                        txt2 = $(this).siblings('.slide-content').html();
                        $('.showslidetext').html(txt2);
                        num = $(this).attr('tag');
                        var clr = '#333';
                        var foreclr = "#000";
                        if (blocks[num].use_colors){
                            if (! blocks[num].panelbackcolor){clr = '#333';}
                            else{clr = "#" + blocks[num].panelbackcolor;}
                            if (! blocks[num].panelcolor){foreclr = '#000';}
                            else{foreclr = "#" + blocks[num].panelcolor;}
                        }
                        $('.showslidetext').show('fast');
                        $('.showslidetext').css('background-color', clr);
                        $('.showslidetext').css('color', foreclr);
                        $('.showslidetext a:link').css('color', foreclr);
                        var calls = blocks[num].js_calls;
                        if (calls && calls != 0){
                            var callray = calls.replace( /\r\n/g, " " ).split( " " );
                            for( var k = 0; k < callray.length; k++ ) {
                                callx = callray[k];
                                var fn = window[callx];
                                fn();
                            }
                        }
                    }
                });
                $('.slide-title').each(function(){
                    t = $(this).find('.rotate').text().replace(/\n/g,'');
                    t = $.trim(t); 
                    t = t.toUpperCase();
                    obj = $(this).find('.rotate');
                    fname = obj.css('font-family');
                    n = fname.search(",");
                    fname = fname.substr(0,n);
                    fsize = obj.css('font-size');
                    //alert(t + " " + fname + " " + fsize);
                    w = getTextWidth(t,fname, fsize);
                    //alert(t + " " + fname + " " + fsize + "w: " + w);
                    fw = w ;
                    //w = Math.max(w,70);
                    $(this).height(w+10);
                    var loc = Drupal.settings.slideblocks_data.tabloc;
                    if(loc == 'left'){
                        $(this).css('padding-top', 15);
                        $(this).height(w+35);
                        //$(this).css('padding-bottom', w/4);
                    }
                    else{
                        //$(this).css('padding-bottom', w/4);
                        $(this).css('padding-top', fw);
                        
                    }
                });  
                var min_height = $('.slide-one').height();
                $('.showslidetext').css('min-height',min_height-24);
                if ($( window ).width() > sidebar_threshold){                    
                    var loc = Drupal.settings.slideblocks_data.tabloc;
                    if(loc == 'left'){                
                        $(content_dom).css('margin-left',orig_ml);
                    }
                    else {
                        $(content_dom).css('margin-right',orig_mr);
                    }
                }
            }
            else {
                $('.slide-master').remove();
                $('.slide-title').remove();
                $('.showslidetext').remove();
                var i;
                for (i = 0; i < blocks.length; ++i) {
                    block_id = '#' + blocks[i].form_id;
                    $(block_id).show();
                }   
                var loc = Drupal.settings.slideblocks_data.tabloc;
                if(loc == 'left'){                
                    $(content_dom).css('margin-left',orig_ml);
                }
                else {
                    $(content_dom).css('margin-right',orig_mr);
                }
            }
        }
    }
 };
})(jQuery);
function getTextWidth(text, fname, fsize) {
    // re-use canvas object for better performance
    //fsize = (3*fsize)/4;
    font = fsize + "px " + fname;
    var canvas = getTextWidth.canvas || (getTextWidth.canvas = document.createElement("canvas"));
    var context = canvas.getContext("2d");
    context.font = font;
    var metrics = context.measureText(text);
    return metrics.width;
};

