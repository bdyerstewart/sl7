(function ($) {
  
  $(document).ready(function() {
    $('.landing-page-step-active .views-row-first .step a').addClass('active');
    // Logic for classroom navigation buttons
    $('.classroom-navigation-wrapper a').click(function(e) {
      e.preventDefault();
      if ($(this).hasClass('classroom-previous-button')) {
        if ($('.view-classroom-steps .step a.active').parents('.views-row').hasClass('views-row-first')) {
          $('.view-classroom-steps .views-row-last .step a').click();
        } else {
          $('.view-classroom-steps .step a.active').parents('.views-row').prev('.views-row').find('.step a').click();
        }
      }
      else if ($(this).hasClass('classroom-next-button')) {
        if ($('.view-classroom-steps .step a.active').parents('.views-row').hasClass('views-row-last')) {
          $('.view-classroom-steps .views-row-first .step a').click();
        } else {
          $('.view-classroom-steps .step a.active').parents('.views-row').next('.views-row').find('.step a').click();
        }
      }
    });
    // Logic for step panel
    $('.view-classroom-steps .step a').click(function(e) {
      e.preventDefault();
      $('.view-classroom-steps .step a').removeClass('active');
      $(this).addClass('active');
      window.history.pushState('', $(this).text(), $(this).attr('href'));
    });
  });
  
  Drupal.behaviors.classroomAjax = {
    attach: function (context, settings) {
      if (Drupal.views !== undefined) {
        $.each(Drupal.views.instances, function(i, view) {
          if (view.settings.view_name == "classroom_steps") {
            // Enable AJAX for Step Pane
            $('.view-display-id-panel_pane_1 .views-row .views-field-title', context).each(function(index, element) {
              var $this = $(element),
              viewData = {},
              arg = $('.step a', $this).attr('rel');
              // Load the argument
              view.settings['view_args'] = arg;
              // This is the way we update the viewData object with defaults and
              // later with overridden values
              $.extend(viewData, view.settings);
              view.element_settings.submit = viewData;
              // Create the Drupalish ajax call
              new Drupal.ajax(false, $this, view.element_settings);
            });
          } // endif
        });
      } // endif
    }
  };
  
})(jQuery);
