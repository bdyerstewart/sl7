

(function ($) {

  Drupal.behaviors.triage_actions = {
    attach: function (context, settings) {
        $('.page-triage-actions-admin ul.taxonomy-tree > li').addClass('collapsible');
        $('.page-triage-actions-admin ul.taxonomy-tree > li > a').removeAttr('href');
        $('.page-triage-actions-admin ul.taxonomy-tree > li > div').addClass('hidden');
        $('li.collapsible >a').click(function(){
          $(this).parent().children().toggleClass('hidden');
          $(this).parent().toggleClass('collapsed');
          $(this).removeClass('hidden');
        });
        $('.page-taxonomy-actions #overlay-close').click(function(event){
          event.preventDefault();
          var path = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath + 'triage_actions_admin';
          window.location.href=path;
        });
        $('div.sl-accordion').parents('.group-header').siblings('div').hide();
        $('div.sl-accordion').parents('.field').siblings().hide();
        $('div.sl-accordion').click(function(){
          //alert('hi');
          if ($(this).hasClass('expanded')){
            $(this).removeClass('expanded');
            $(this).parents('.triage-action-item').find('.group-header').siblings('div').hide();
            $(this).parents('.group-header').show();
            $(this).parents('.group-header').find('fieldset').hide();
          }
          else{
            $(this).addClass('expanded');
            $(this).parents('.triage-action-item').find('.group-header').siblings('div').show();
            $(this).parents('.group-header').show();
            $(this).parents('.group-header').find('fieldset').show();
          }
        });
        if ($('body.page-triage-org-filter').length > 0){
          $('#edit-triage-org-visibility-submit').click(function(){
            if( $('select#counties.counties_sel options').length == 0){
              $('select#counties.counties_sel').append('<option val=" "></option>');
            }
          })
        }
    }
  };
})(jQuery);
