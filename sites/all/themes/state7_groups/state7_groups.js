(function ($) {
  Drupal.behaviors.state7_groups = {
    attach: function (context, settings) {
       var status = $('div.view-my-membership-status div.views-field-state span.field-content');       
       if (status.length > 0){
           switch (status.html()) {
               case "Active" :
                status_color = '#8CE560';
                break;
               case "Pending" :
                status_color = '#f6dd1c';
                break;
               case "Blocked" :
                status_color = '#D6B3B3';
                break;
           }
           status.parent().parent().css('background-color',status_color)
       }
       $('.view-group-search .views-row').click(function(){
          var url = $(this).find('.views-field-title a').attr('href');
          var path = window.location.protocol + "//" + window.location.host ;
          url = path + url;
          window.location.href = url;
       });
    }
  };
})(jQuery);
