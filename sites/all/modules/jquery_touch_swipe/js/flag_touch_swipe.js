function is_touch_device() {
  return 'ontouchstart' in window || 'onmsgesturechange' in window;
};

function is_flag_triggered(flag_events,direction,fingerCount){
  for(event in flag_events){
    key = flag_events[event];
    is_single_left_enabled = (direction == 'left' && fingerCount == 1 && key == 'single_swipe_left');
    is_double_left_enabled = (direction == 'left' && fingerCount == 2 && key == 'double_swipe_left');
    is_single_down_enabled = (direction == 'down' && key == 'swipe_down');
    is_single_right_enabled = (direction == 'right' && key == 'single_swipe_right');
    if(is_single_left_enabled || is_single_down_enabled || is_single_right_enabled || is_double_left_enabled){
      return 'span.flag-' + event;
    }
  }
  return 'none';
}

(function ($) {
	Drupal.behaviors.touch_swipe_flag = {
		attach: function(context, settings) {			
  		var flag_events = Drupal.settings.touch_swipe.flag_events[0];
  		var attach_selector = Drupal.settings.touch_swipe_selector.selector[0];
  		  if(is_touch_device()){
  		    for(event in flag_events){
      		  selector = 'span.flag-' + event;
    		    $(selector).css('visibility','hidden');
      		  $(selector).css('position','absolute');
    		}
    		$("."+attach_selector).swipe({
          swipe:function(event, direction, distance, duration, fingerCount) {
          chiave = is_flag_triggered(flag_events,direction,fingerCount);
            if(chiave != 'none'){
              $(chiave + ' a.flag-link-toggle').click();
            }
          },
           threshold:0,
           fingers:'all'
        });
  		}
    }
  }	
})(jQuery);