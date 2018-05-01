ans = {};
(function ($) {
  Drupal.behaviors.statesidelegal = {
    attach: function (context, settings) {
        var base_url = Drupal.settings.basePath;
        $('.sl-loading').remove();
//        if ( $( window ).width() <= 768 ){
//            $('#nav-mobile').css('display','block');
//        }
        $("#sl_blogger_list h2").hover(
            function(){$(this).css("text-decoration","underline");},
            function(){$(this).css("text-decoration","none");}
        );
        $("#sl_blogger_list h2").first().removeClass("searchaccordian");
        $("#sl_blogger_list h2").first().addClass("searchaccordianselect");
        $("#sl_blogger_list h2.searchaccordianselect").next("div").show();
        $("#sl_blogger_list h2.searchaccordian").next("div").hide();
        $("#quicktabs-tab-advocate_info-1").click(function(){
            url = 'advocate-info?qt-advocate_info=1#qt-advocate_info';
            window.location = getBaseURL() + base_url + url;
        });
        $("#quicktabs-tab-advocate_info-0").click(function(){
            url = 'advocate-info?qt-advocate_info=0#qt-advocate_info';
            window.location = getBaseURL() + base_url + url;
        });
        $("#sl_blogger_list h2").click(function(){
            $("#sl_blogger_list h2").removeClass("searchaccordianselect");
            $("#sl_blogger_list h2").addClass("searchaccordian");
            $("#sl_blogger_list div").hide("slow");
            $("div.searchresults").show();
            $(this).removeClass("searchaccordian");
            $(this).addClass("searchaccordianselect");
            $(this).next("div").show("slow");
        });
        if ( $( window ).width() < 768 ){
            $('#block-block-47').removeClass('collapsiblock-processed');
            $('#block-block-47 h2').removeClass('collapsiblock');
            $('#block-block-47 h2').click(function(event){
                event.preventDefault();
            });
            if ($('body.front').length == 0){
                $('#block-block-47').hide();
            }
        }
        if ($('body.front').length > 0){
            stateside_topictoggle();
        }
        topic_setup();
        
        var cols = [];
        var colmax = 0
        cols[0] = $('body.page-node-edit.node-type-organization .org-edit-col1');
        cols[1] = $('body.page-node-edit.node-type-organization .org-edit-col2');
        cols[2] = $('body.page-node-edit.node-type-organization .org-edit-col3');
        for (i = 0; i < cols.length; ++i) {
           if (cols[i].height() > 0){
                colmax = Math.max(colmax, cols[i].height());
            }
        }
        for (i = 0; i < cols.length; ++i) {
            cols[i].height(colmax);
        }
        cols[0].click(function(){
            cols[0].css('background-color','#ccc');
            cols[1].css('background-color','#aaa');
            cols[2].css('background-color','#aaa');
        });
        cols[1].click(function(){
            cols[0].css('background-color','#aaa');
            cols[1].css('background-color','#ccc');
            cols[2].css('background-color','#aaa');
        });
        cols[2].click(function(){
            cols[0].css('background-color','#aaa');
            cols[1].css('background-color','#aaa');
            cols[2].css('background-color','#ccc');
        });
        $('#edit-field-states-served-und').change(function(){
            var url = window.location.protocol + "//" + window.location.host;
            var tid = $(this).val();
            url += Drupal.settings.basePath + "stateside_counties/" + tid/1 ;
            sl_loading('Downloading County Information');
            $.getJSON( url, function( data ) {
                if (data){
                    var opt = '';
                    $.each(data, function( index, value ) {
                        opt += "<option value='" + index + "'>" + value + "</option>";
                    });
                    $('select[name="field_counties_served[und][]"]').find('option').remove().end().append(opt);
                    $('#improvedselect-edit-field-counties-served-und').remove();
                    redo_multi_select('select#edit-field-counties-served-und',tid);
                    $('div.sl-loading').remove();
                }

            });
        })
        function stateside_getdata(tid, repl){
          var url = window.location.protocol + "//" + window.location.host;
          url += Drupal.settings.basePath + "stateside_subtopics/" + tid ;
          var out = repl.html();
          //triage_loading();
          $.getJSON( url, function( data ) {
            if (data){
              out = out + data ;
            }
            repl.html(out);
            //triage_clicks();
            //$(".triage-loading").remove();
          });
        }             
        function stateside_setans(){
            $("#bds input").each(function(  ) {
            });
        }

        function redo_multi_select(selector, state) {
            $('#improvedselect-edit-field-counties-served-und').remove();
            $(selector ).each(function () {
                $(this).parent().append('<div class="improvedselect" sid="' + $(this).attr('id') + '" id="improvedselect-' + $(this).attr('id') + '"><div class="improvedselect-text-wrapper"><input type="text" class="improvedselect_filter" sid="' + $(this).attr('id') + '" prev="" /></div><ul class="improvedselect_sel"></ul><ul class="improvedselect_all"></ul><div class="improvedselect_control"><span class="add" sid="' + $(this).attr('id') + '">&gt;</span><span class="del" sid="' + $(this).attr('id') + '">&lt;</span><span class="add_all" sid="' + $(this).attr('id') + '">&raquo;</span><span class="del_all" sid="' + $(this).attr('id') + '">&laquo;</span></div><div class="clear" /></div>');
                var improvedselect_id = $(this).attr('id');
                $(this).find('option').each(function () {
                    if ($(this).attr('selected')) {
                        $('#improvedselect-' + improvedselect_id + ' .improvedselect_sel').append('<li so="' + $(this).attr('value') + '">' + $(this).text() + '</li>');
                    }
                    else {
                        $('#improvedselect-' + improvedselect_id + ' .improvedselect_all').append('<li so="' + $(this).attr('value') + '">' + $(this).text() + '</li>');
                    }
                });
                $('#improvedselect-' + improvedselect_id + ' li').click(function () {
                    $(this).toggleClass('selected');
                });
                $(this).hide();
                // double click feature request
                $('#improvedselect-' + improvedselect_id + ' li').dblclick(function () {
                    // store selected items
                    var selected = $(this).parent().find('li.selected');
                    var current_class = $(this).parent().attr('class');
                    // add item
                    if (current_class == 'improvedselect_all') {
                        $(this).parent().find('li.selected').removeClass('selected');
                        $(this).addClass('selected');
                        $(this).parent().parent().find('.add').click();
                    }
                    // remove item
                    else {
                        $(this).parent().find('li.selected').removeClass('selected');
                        $(this).addClass('selected');
                        $(this).parent().parent().find('.del').click();
                    }
                    // restore selected items
                    if (selected.length) {
                        for (var k = 0; k < selected.length; k++) {
                            if ($(selected[k]).parent().attr('class') == current_class) {
                                $(selected[k]).addClass('selected');
                            }
                        }
                    }

                });
            });


            $('.improvedselect_filter').keyup(function () {
                var text = $(this).val();
                if (text.length && text != $(this).attr('prev')) {
                    $(this).attr('prev', text);
                    var patt = new RegExp(text, 'i');
                    $('#improvedselect-' + $(this).attr('sid') + ' .improvedselect_all li').each(function () {
                        var str = $(this).text();
                        if (str.match(patt)) {
                            $(this).show();
                        }
                        else {
                            $(this).hide();
                        }
                    });
                }
                else {
                    $(this).attr('prev', '')
                    $('#improvedselect-' + $(this).attr('sid') + ' .improvedselect_all li').each(function () {
                        $(this).show();
                    });
                }
            });

// Add selected items.
            $('.improvedselect .add').click(function () {
                var sid = $(this).attr('sid');
                $('#improvedselect-' + sid + ' .improvedselect_all .selected').each(function () {
                    $(this).removeClass('selected');
                    $(this).show();
                    $('#improvedselect-' + sid + ' .improvedselect_sel').append($(this));
                });
                sl_improvedselectUpdate(sid);
            });

// Remove selected items.
            $('.improvedselect .del').click(function () {
                var sid = $(this).attr('sid');
                $('#improvedselect-' + sid + ' .improvedselect_sel .selected').each(function () {
                    $(this).removeClass('selected');
                    $('#improvedselect-' + sid + ' .improvedselect_all').append($(this));
                });
                sl_improvedselectUpdate(sid);
            });

// Remove all filtered items.
            $('.improvedselect .add_all').click(function () {
                var sid = $(this).attr('sid');
                $('#improvedselect-' + sid + ' .improvedselect_all li').each(function () {
                    if ($(this).css('display') != 'none') {
                        $(this).removeClass('selected');
                        $('#improvedselect-' + sid + ' .improvedselect_sel').append($(this));
                    }
                });
                sl_improvedselectUpdate(sid);
            });

// Remove all items.
            $('.improvedselect .del_all').click(function () {
                var sid = $(this).attr('sid');
                $('#improvedselect-' + sid + ' input').val('');
                $('#improvedselect-' + sid + ' input').attr('prev', '');
                $('#improvedselect-' + sid + ' .improvedselect_sel li').each(function () {
                    $(this).removeClass('selected');
                    $('#improvedselect-' + sid + ' .improvedselect_all').append($(this));
                });
                $('#improvedselect-' + sid + ' .improvedselect_all li').each(function () {
                    $(this).show();
                });
                sl_improvedselectUpdate(sid);
            });
        }
        function sl_improvedselectUpdate(sid) {
            $('#'+ sid +' option:selected').attr("selected", false);
            $('#improvedselect-'+ sid +' .improvedselect_sel li').each(function(){
                $('#'+ sid +' [value="'+ $(this).attr('so') +'"]').attr("selected", "selected");
            });

            $('#' + sid).find('option').each(function() {
                if ($(this).attr("selected")) {
                    $('#improvedselect-'+ sid +' .improvedselect_sel').append($('#improvedselect-'+ sid +' .improvedselect_sel [so="'+ $(this).attr('value') +'"]'));
                }
                else {
                    $('#improvedselect-'+ sid +' .improvedselect_all').append($('#improvedselect-'+ sid +' .improvedselect_all [so="'+ $(this).attr('value') +'"]'));
                }
            });
            $('#'+ sid).trigger('change'); // tell the ajax system the select has changed
        }
    }
  };
})(jQuery);
function stateside_topicslide(tid){
    jQuery('.topic-image').remove();
    jQuery('#block-statesidelegal-stateside-make-topic-block').addClass('collapsed');
    var adiv = jQuery('a.topic-head');
    if( adiv.hasClass('collapsed')){
        adiv.removeClass('collapsed');
    }
    else {
        adiv.addClass('collapsed');
    }
    var img = jQuery('#topic-' + tid).html();
    img = "<div class='topic-image' >" + img + "</div>";
    var div = ".sub-" + tid;
    jQuery(div).show();
    jQuery(div + " nav h4" ).prepend(img);
    jQuery('#topic-list').hide();
    if (tid==3260){
        jQuery('.topic-image img').css('max-width','45px');
        jQuery('.wmn-title-text').hide();
    }
}
function stateside_topictoggle(){
    
    var div = jQuery('a.topic-head');
    var parent = div.parents('.block-statesidelegal');
    if( div.hasClass('collapsed')){
        parent.siblings().each(function(){
          id = jQuery(this).attr('id');
          //alert(id);
          if (jQuery(this).hasClass('collapsiblock-processed')){
               var head =jQuery(this).find('h2');
               if (head.length>0){
                   if (! head.hasClass('collapsiblockCollapsed')){
                       head.addClass('collapsiblockCollapsed');
                       head.siblings('div').hide();
                   }
               }
           }
        });
        div.removeClass('collapsed');
        div.parent('div').removeClass('collapsed');
        parent.removeClass('collapsed');
        jQuery('#topic-list').show();
        jQuery('.subtopic').hide();
        jQuery('.wmn-title-text').show();
    }
    else {
        div.addClass('collapsed');
        div.parent('div').addClass('collapsed');
        parent.addClass('collapsed');
        jQuery('#topic-list').hide();
    }
    if ( jQuery( window ).width() < 768 ){
        jQuery('#block-block-47 h2').remove();
        jQuery('#block-block-47').prepend('<h2>Resources</h2>');
        //jQuery('#block-block-47 h2').html('Resources');
        jQuery('#sl-block-statesidelegal-stateside-make-topic-block a.topic-head').click(function(){
            jQuery('#sl-block-statesidelegal-stateside-make-topic-block a.topic-head').removeClass('collapsed');
        });
    }



}
function stateside_get_topics(){
    if (jQuery('.topic-action').hasClass('active-topic')){
        sl_loading();
        var lib_path = window.location.protocol + "//" + window.location.host;
        lib_path += Drupal.settings.basePath + "library/-1";
        window.location.href = lib_path;
    }
}
function stateside_clear_topics(){
    if (jQuery('.topic-action').hasClass('active-topic')){
        ans = {};
        jQuery("#bds input").each(function(  ) {
           id = jQuery(this).attr('id');
           if (id.indexOf('clickit-') > -1){
              id = id.replace('clickit-','');
              jQuery(this).prop('checked',false) ;
              ans[id] = false ;
            }
        });    
        jQuery.cookie('topic_picks', JSON.stringify(ans),{ path: '/' });
        sl_has_topic()
    }
}
function getBaseURL () {
   return "http://" + location.hostname;
}
function topic_setup(){
    if (jQuery("#bds input").length > 0 ){
        
        if (typeof jQuery.cookie('topic_picks') === "undefined" || ! jQuery.cookie('topic_picks') ){
            ans = {};
            var out = '';
            jQuery("#bds input").each(function(  ) {
                val = false;
                if (typeof jQuery(this).attr('id') !== "undefined"){
                    id = jQuery(this).attr('id');
                    if (id.indexOf('clickit-') > -1){
                        id = id.replace('clickit-','');
                        ans[id] = jQuery(this).prop('checked') ;
                        out += "ID: " + id + " - " + val + "\n";
                    }
                }
            }); 
            jQuery.cookie('topic_picks', JSON.stringify(ans),{ path: '/' });
            //alert("A" + jQuery.cookie('topic_picks'));
        }
        else {
            var newArr = JSON.parse(jQuery.cookie('topic_picks'));
            jQuery.each(newArr, function(key,val){
                //alert("key: " + key + " - Val: " + val);
                seto = '#clickit-' + key;
                //alert(seto);
                if (val){
                    jQuery(seto).prop( "checked", true );
                }
            });             
            ans = {};
            var out = '';
            jQuery("#bds input").each(function(  ) {
                val = false;
                if (typeof jQuery(this).attr('id') !== "undefined"){
                    id = jQuery(this).attr('id');
                    xid = id;
                    //alert(xid);
                    if (id.indexOf('clickit-') > -1){
                        id = id.replace('clickit-','');
                        ans[id] = jQuery("#"+xid).prop('checked') ;
                    }
                }
            }); 
            jQuery.cookie('topic_picks', JSON.stringify(ans),{ path: '/' });
            //alert("B" + jQuery.cookie('topic_picks'));
        }
    }
    sl_has_topic()
    jQuery('.topic-click').click(function(){
        id = jQuery(this).attr('id');
        if (id.indexOf('clickit-') > -1){
            id = id.replace('clickit-','');
            ans = JSON.parse(jQuery.cookie('topic_picks'));
            ans[id] = jQuery(this).prop('checked') ;
            jQuery.cookie('topic_picks', JSON.stringify(ans),{ path: '/' });
        }
        sl_has_topic();
    });
    jQuery('.gctopic-click').click(function(){
        id = jQuery(this).attr('id');
        //alert(jQuery(this).prop('checked'));
        if (id.indexOf('clickit-') > -1){
            id = id.replace('clickit-','');
            ans = JSON.parse(jQuery.cookie('topic_picks'));
            ans[id] = jQuery(this).prop('checked') ;            
            jQuery.cookie('topic_picks', JSON.stringify(ans),{ path: '/' });
        }
        sl_has_topic();
    });
    jQuery('h2.collapsiblock').click(function(){
        div = jQuery(this);
        if (!div.parent('div').hasClass('collapsiblock-processed')){
            div.parent('div').addClass('collapsiblock-processed');
        }
        if (div.hasClass('collapsed')){
            div.removeClass('collapsed');
            div.parent().find('.sl-blog-topics').show();
        }
        else{
            div.addClass('collapsed');
            div.parent().find('.sl-blog-topics').hide();
        }       
    });
    return;
}
function sl_topics_expand(){
        div = jQuery('.showslidetext .topic-wrapper');
//    if (!div.parent('div').hasClass('collapsiblock-processed')){
//        div.parent('div').addClass('collapsiblock-processed');
//    }
//    if (div.hasClass('collapsed')){
//        div.removeClass('collapsed');
        div.find('a.topic-head').removeClass('collapsed');
        jQuery('#topic-list').show();
        jQuery('.subtopic').hide();
        jQuery('.wmn-title-text').show();
        
//    }
    return;
}
function sl_loading(msg){
  jQuery('div.sl-loading').remove();
  if(typeof msg=="undefined"){
      msg = "Loading..."
  }
  jQuery('body').append("<div class='sl-loading'><i class='fa fa-spinner fa-spin'></i>" + msg + "</div>");
  jQuery('div.sl-loading').show();
}
function sl_has_topic(){
    anyyes = false
    jQuery("#bds input").each(function(  ) {
        val = false;
        if (typeof jQuery(this).attr('id') !== "undefined"){
            id = jQuery(this).attr('id');
            xid = id;
            //alert(xid);
            if (id.indexOf('clickit-') > -1){
                id = id.replace('clickit-','');
                ans[id] = jQuery("#"+xid).prop('checked') ;
                if (ans[id]){anyyes = true;}
            }
        }
    }); 
    if (anyyes){
        jQuery('.topic-action').addClass('active-topic');
    }
    else {
        jQuery('.topic-action').removeClass('active-topic');
    }
}