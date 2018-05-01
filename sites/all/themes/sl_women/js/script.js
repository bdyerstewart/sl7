(function ($) {
  Drupal.behaviors.sl_women = {
    attach: function (context, settings) {
       $('.advocate-network').click(function(){
          var url = $(this).find('a.more').attr('href');
          window.location.href = url;
       });        
    }
  };
})(jQuery);
