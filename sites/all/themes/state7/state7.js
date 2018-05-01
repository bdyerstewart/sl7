(function ($) {
  Drupal.behaviors.state7 = {
    attach: function (context, settings) {
        var heightArray = $(".avail-groups").map(function() {
            return  $(this).height();
        }).get();
        var maxHeight = Math.max.apply(Math, heightArray);
        $(".avail-groups").height(maxHeight);    
       $('.advocate-network').click(function(){
          var url = $(this).find('a.more').attr('href');
          window.location.href = url;
       });
       $('.stateside-copy').click(function(){
         copyToClipboard('#stateside-link');
       });
       $('.page-node-5929 div.rate-widget').remove();
       if ($('body.page-triage-actions-process').length){
         var wrap = $('.article-wrapper h4');
         if(!wrap.hasClass('expanded')){
           wrap.addClass('expanded');
         }
         wrap = $('.form-wrapper h4');
         if(!wrap.hasClass('expanded')){
           wrap.addClass('expanded');
         }
         wrap = $('.classroom-wrapper h4');
         if(!wrap.hasClass('expanded')){
           wrap.addClass('expanded');
         }
         wrap = $('.legal-help-wrapper h4');
         if(!wrap.hasClass('expanded')){
           wrap.addClass('expanded');
         }
         if( $('.legal-help-wrapper div').length==0){
           $('.legal-help-wrapper').hide();
         }
         wrap = $('.video-wrapper h4');
         if(!wrap.hasClass('expanded')){
           wrap.addClass('expanded');
         }
         $('.article-wrapper h4,.form-wrapper h4,.classroom-wrapper h4,.legal-help-wrapper h4, .video-wrapper h4').click(function(){
           $(this).toggleClass('collapsed');
           if($(this).hasClass('collapsed')){
             $(this).parent().children('div').hide();
           }
           else {
             $(this).parent().children('div').show();
           }
         })
       }
       //$(".rate-widget").wrap('<div class="VOICE_SKIP"></div>');
        
    }
  };
  function copyToClipboard(element) {
    var $temp = $("<input>");
    $("body").append($temp);
    //alert($(element).html());
    $temp.val($(element).html()).select();
    document.execCommand("copy");
    $temp.remove();
    $(element).parent().prepend("<div id='copy-confirm'>Code has been added to your clipboard</div>");
    setTimeout(function() { $('#copy-confirm').remove(); }, 4000);
  }
})(jQuery);
