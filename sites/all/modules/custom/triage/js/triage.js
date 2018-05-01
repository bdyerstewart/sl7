var is_changed = false;
var nokids = 0;
var popupStatus = 0;
var alreadyclicked = false;
var zitem = '';
var newtriage = true;
var reason = '';
var control = '';
var waiting = "false";
var triage_chart = '';
var max_chars = 0;
var tid = 0;
var newtitle = '';
var item = null;
var val = '';
var inputs = null;
var slct = null;
var ret = '';
var row = null;
var vals = null;
var i = null;
var k = null;
(function ($) {
  Drupal.behaviors.triage = {
    attach: function (context, settings) {
      var triage_path = window.location.protocol + "//" + window.location.host;
      var exist = $('#triage-popup').length;
      adjust_nav_css();
      $('.ta-contrast-background').each(function (ndx) {
        if ($(this).html() == '') {
          $(this).remove();
        }
      });
      if (typeof Drupal.settings.my_progress_bar !== 'undefined') {
        if (Drupal.settings.my_progress_bar.restart) {
          triage_progress(0);
          Drupal.settings.my_progress_bar.restart = false;
        }
      }
      if (typeof Drupal.settings.max_chars == 'undefined') {
        max_chars = 75;
      }
      else {
        max_chars = Drupal.settings.max_chars;
      }
      var options2 = {
        'maxCharacterSize': max_chars,
        'originalStyle': 'originalTextareaInfo',
        'warningStyle': 'warningTextareaInfo',
        'warningNumber': 40,
        'displayFormat': '#input used / #left characters remaining'
      };
      if ($('textarea[name=triage_suggestion]').length) {
        $('textarea[name=triage_suggestion]').textareaCount(options2);
      }
      $("#triage_suggestion_submit").click(function () {
        //$("<div/>", {class: "waiting",text: "Searching"}).appendTo("body");
        var windowWidth = document.documentElement.clientWidth;
        //centering
        $("div.waiting").css({
          "left": windowWidth / 2 - 75
        });

      });
      if ($('body.front').length > 0) {
        $.cookie('triage_last_tid', '', {path: '/'});
      }
      else {
        if ($.cookie('triage_last_tid')) {
          var newpath = window.location.protocol + "//" + window.location.host;
          newpath += Drupal.settings.basePath;
          $('#zone-menu a.menu-guided-help').attr('href', newpath + 'triage_actions_process/' + $.cookie('triage_last_tid'));
          $('#zone-menu a.menu-guided-help').html(Drupal.settings.triage_last_help_text);
        }
      }
      if ($('body.page-triage').length > 0) {
        if ($('.triage-top').length){
          //$('.triage-group-reset').html('Start Again');
        }
        if (Drupal.settings.triage_item > 0) {
          tid = Drupal.settings.triage_item;
          Drupal.settings.triage_item = 0;
          var triage_path = window.location.protocol + "//" + window.location.host;
          var lang = Drupal.settings.my_triage.lang;
          var defa_lang = Drupal.settings.my_triage.default_lang;
          if (lang == defa_lang) {
            lang = '';
          }
          else {
            lang = lang + "/";
          }
          triage_path = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "/";
          var len = Drupal.settings.my_triage.tid.length;
          Drupal.settings.my_triage.tid[len] = tid;
          var url = triage_path + tid + "/1/-1";
          triage_getdata(url, tid);
          //set opening values
          if (newtriage) {
            $.cookie('triage_completed', 0, {path: '/'});
            $.cookie('triage_hist', '', {path: '/'});
            $.cookie('triage_current_step', 1, {path: '/'});
            $.cookie('triage_last', '', {path: '/'});
            $.cookie('triage_last_tid', '', {path: '/'});
            $.cookie('triage_no_write', 0, {path: '/'});
            $.cookie('waiting', "false", {path: '/'});
            $.cookie('income_amt', 0, {path: '/'});
            newtriage = false;
          }
        }
        if (Drupal.settings.my_alt_display.use_alt) {
          var home_path = window.location.protocol + "//" + window.location.host;
          home_path += Drupal.settings.basePath;
          var homebutton = "<div class='home-button'><a href='" + home_path + "'>Home</a></div>";
          var el = $('#triage-page-wrapper').detach();
          $('body.page-triage').append(el);
          if ($('.home-button').length == 0) {
            $('#triage-page-wrapper').prepend(homebutton);
          }
          $('#triage-page-wrapper').show();
          var cmds = Drupal.settings.my_alt_display.alt_cmds;
          if (cmds > '') {
            eval(cmds);
          }
        }
        if (typeof Drupal.settings.bypass_questions !== 'undefined') {
          if (Drupal.settings.bypass_questions) {
            triage_progress();
          }
          else {
            triage_progress();
          }
        }
      }
      if (exist == 0) {
        $("body").append("<div id='triage-popup'></div>");
      }
      exist = $('#bdslegalpopup').length;
      if (exist == 0) {
        $("body").append("<div id='bdslegalpopup'></div>");
      }
      if (typeof Drupal.settings.triage_popup != 'undefined') {
        var min_width = parseInt(Drupal.settings.triage_popup.min_width);
        var max_width = parseInt(Drupal.settings.triage_popup.max_width);
        var window_width = $(window).width();
        if (window_width > min_width) {
          if (window_width < max_width || max_width == 0) {

            if (Drupal.settings.triage_popup.parent > 0 && Drupal.settings.triage_popup.msg) {
              $('#bdslegalpopup').html(Drupal.settings.triage_popup.msg);
              bdslegalcenterPopup('bdslegalpopup');
              //window.setTimeout( bdslegalloadPopup('bdslegalpopup'),7000);
              bdslegalloadPopup('bdslegalpopup');
              popupStatus = 1;
              $('#triage_change_info').click(function () {
                var url = window.location.protocol + "//" + window.location.host;
                var thisval = $(this).attr('checked');
                if (typeof thisval == "undefined") {
                  thisval = "false";
                }
                else {
                  thisval = "true";
                }
                url += Drupal.settings.basePath + "triage_change_it/" + thisval;
                $.post(url);

              });
            }
          }
        }
      }
      $('#block-triage-triage-menu-block li').click(function () {
        if ($(this).hasClass('collapsed')) {
          $(this).addClass('expanded');
          $(this).removeClass('collapsed');
        }
        else {
          if ($(this).hasClass('expanded')) {
            $(this).removeClass('expanded');
            $(this).addClass('collapsed');
          }
        }
      });
      $('.form-item-triage-income label').css('color', 'red');
      var selector = 'form input.triage-input';
      $(selector).each(function (index) {
        var slct = $(this);
        if (slct.attr('type') == 'checkbox') {
          var newval = slct.attr('checked');
          if (typeof slct.data('last') == "undefined") {
            slct.data('last', newval);
          }
        }
        else {
          if (typeof slct.data('last') == "undefined") {
            slct.data("last", slct.val());
          }
        }
      });
      $('.page-triage-actions-process #breadcrumbs').html("<a href='" + triage_path + Drupal.settings.basePath + "'>Home</a>");
      $('.page-triage #breadcrumbs').html("<a href='" + triage_path + Drupal.settings.basePath + "'>Home</a>");
      $('#block-system-main').show();
      $('#block-system-main .content').show();
      $('.triage-forms .triage-top-form').last().css('border', 'none');
      triage_clicks();
      $('input[type=radio][name=triage_income_period]').change(function () {
        newtitle = this.value + " Income";
        $('.form-item-triage-income label').html(newtitle);
      });

      function triage_restart() {
        if (typeof Drupal.settings.my_triage == "undefined"){
          var lang = "";
          var defa_lang = "";
        }
        else {
          var lang = Drupal.settings.my_triage.lang;
          var defa_lang = Drupal.settings.my_triage.default_lang;
        }
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        var triage_path = window.location.protocol + "//" + window.location.host;
        window.location.href = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "?clear=true";
        triage_progress(0);
      }

      $('#triage-zip-form').submit(function (event) {
        event.preventDefault();
        item = $(event.target).parents('.triage-group').find('.triage-group-submit');
        triage_grpmove(item)
      });
      $('#triage-in-service-area-form').submit(function (event) {
        event.preventDefault();
        item = $(event.target).parents('.triage-group').find('.triage-group-submit');
        triage_grpmove(item)
      });
      $("#edit-node-ref-nid").focus(function () {
        $(this).select();
      });
      $('#edit-node-ref-nid').blur(function () {
        var nid = $(this).val();
        var proc_path = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath;
        proc_path += "triage_get_title/" + nid;
        triage_loading();
        var out = 'noway';
        $.getJSON(proc_path, function (data) {
          if (data) {
            out = data;
            console.log(data);
          }
          $('.triage-form-node-title').html(out);
          $(".triage-loading").remove();
        });
      });

      function triage_grpmove(item) {
        $('div.triagetip').remove();
        var stop_scroll = new Array();
        stop_scroll[0] = false;
        var proc_path = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath;
        var post_url = proc_path + 'triage-post';
        var keepgoing = true;
        var data = {};
        data.rows = [];
        var frm = item.parent().parent().find('form');
        item.parent().parent().find('form').each(function (index) {
          var formname = $(this).attr('id');
          var classes = $(this).parent('.triage-action-form').attr('class');
          if (classes.indexOf('mandatory') > -1) {
            switch (formname) {
              case 'triage-pov-form':
                if (!triage_income_validate()) {
                  keepgoing = false;
                  return;
                }
                break;
              case 'triage-income-form':

                if (!triage_income2_validate(stop_scroll)) {
                  keepgoing = false;
                  return;
                }
                break;
              case 'triage-bank-form' :
                if (!triage_bank_validate()) {
                  keepgoing = false;
                  return;
                }
                break;
              case 'triage-location-form' :
                if (!triage_location_validate()) {
                  keepgoing = false;
                  return;
                }
                break;
              case 'triage-status-form' :
                if (!triage_status_validate()) {
                  keepgoing = false;
                  return;
                }
                break;

              case 'triage-zip-form' :
                if (Drupal.settings.zip_code_success) {
                  if (!triage_zip_validate()) {
                    keepgoing = false;
                    return;
                  }
                }
                else {
                  keepgoing = triage_zip_validate();
                  return;
                }
                break;
              case 'triage-in-service-area-form' :
                if (!triage_sa_validate()) {
                  keepgoing = false;
                  return;
                }
                break;
            }
          }
          var selector = "#" + formname;
          val = '';
          inputs = '';
          $(selector).find('input.triage-input, select.triage-input').each(function (index) {
            slct = $(this);
            inputs = inputs + slct.attr('id');
            if (inputs > '') {
              inputs = inputs + ","
            }
            if (slct.attr('type') == 'checkbox' || slct.attr('type') == 'radio') {
              if (slct.attr('checked')) {
                val = val + slct.val();
                if (val > '') {
                  val = val + ",";
                }
              }
            }
            else {
              val = val + slct.val();
              if (val > '') {
                val = val + ",";
              }
            }
          });
          var row = {
            form: formname, inputs: inputs, values: val
          };
          data.rows.push(row);
        });
        if (keepgoing) {
          triage_loading();
          $.post(post_url, data, function (response, status) {
            if (status == 'success') {
              $('.triage-loading').remove();
              triage_group_check(item);
            }
          });
        }
        if (stop_scroll[0]) {
          $('#edit-triage-last-info')[0].scrollIntoView( true );
          // var top = $('#div_' + element_id).position().top;
          // $(window).scrollTop(top);
        }
        else {
          var offset = Drupal.settings.my_triage.scroll_offset;
          $('html, body').animate({scrollTop: (offset)}, 'fast');
        }
      }

      function triage_group_check(item) {
        var triage_path = window.location.protocol + "//" + window.location.host;
        var cookiepath = triage_path + Drupal.settings.basePath;
        var lang = Drupal.settings.my_triage.lang;
        var defa_lang = Drupal.settings.my_triage.default_lang;
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        triage_path = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "/";
        nokids = item.hasClass('nokids');
        if (nokids) {
          item.removeClass('nokids');
        }
        var thisclass = item.attr('class');
        var grpid = thisclass.replace('triage-group-submit next-', '');
        var msg = item.parent().children('.triage-group-reset').attr('class');

        if (typeof msg === "undefined") {
          $.cookie('triage_hist', '', {path: '/'});
          $.cookie('triage_last', '', {path: '/'});
          $.cookie('triage_current_step', 1, {path: '/'});
        }
        var pre_cook = $.cookie('triage_hist', {path: '/'});
        if (pre_cook === null) {
        }
        else {
          if (grpid != 0) {
            var ref = Drupal.settings.my_group[parseInt(grpid)];
            $.cookie('triage_hist', pre_cook + ">>" + ref, {path: '/'});
            $.cookie('triage_last', ref, {path: '/'});
            $.cookie('triage_current_step', 1, {path: '/'});
          }
        }
        triage_progress(grpid);
        var url = triage_path + "0/1/" + grpid;
        var parent = null;
        parent = item.parent('.triage-group');
        $('.triage-group').hide();
        $('.grp-' + grpid).removeClass('hidden');
        $('.grp-' + grpid).show();
        if (grpid == 0) {
          //$.cookie('triage_no_write',1,{ path: '/' });
          $('.grp-' + grpid).hide();
          var dtid = Drupal.settings.direct_nid;
          if (typeof dtid == "undefined") {
            url = triage_path + "0/1/-1";
            triage_getdata(url, 0);
          }
          else {
            url = triage_path + Drupal.settings.direct_nid;
            window.location.href = url;
          }
        }
        else {
          //$('.triage-loading').remove();
        }
      }

      function triage_grpreset(item) {
        triage_loading();
        var triage_path = window.location.protocol + "//" + window.location.host;
        var lang = Drupal.settings.my_triage.lang;
        var defa_lang = Drupal.settings.my_triage.default_lang;
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        triage_path = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "/";
        nokids = item.hasClass('nokids');
        if (nokids) {
          item.removeClass('nokids');
        }
        var thisclass = item.attr('class');
        var grpid = thisclass.replace('triage-group-reset prev-', '');
        var url = triage_path + "0/1/" + grpid;
        $('.triage-group').hide();
        $('.grp-' + grpid).show();
        $('.triage-content').html("");
        triage_progress(grpid);
        $('.triage-loading').remove();
        var offset = Drupal.settings.my_triage.scroll_offset;
        $('html, body').animate({scrollTop: (offset)}, 'fast');
      }

      function triage_submit() {
        var changed = triage_is_changed();
        var proc_path = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath;
        var write_url = proc_path + 'triage_write_history';
        var lang = Drupal.settings.my_triage.lang;
        var defa_lang = Drupal.settings.my_triage.default_lang;
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        var len = Drupal.settings.my_triage.tid.length;
        var tid = Drupal.settings.my_triage.tid[len - 1];
        var url = proc_path + lang + "triage_actions_process/" + tid;
        $(".triage-loading").remove();
        triage_loading();
        $.cookie('triage_last_tid', tid, {path: '/'});
        if (changed == "") {
          $.cookie('triage_completed', 1, {path: '/'});
          window.location.href = url;
        }
        else {
          is_changed = true;
          $('#' + changed).change();
          $(document).ajaxComplete(function () {
            if (is_changed == true) {
              is_changed = false;
              $.cookie('triage_completed', 1, {path: '/'});
              window.location.href = url;
              $(".triage-loading").remove();
            }
          });
          $(".triage-loading").remove();
        }
      }

      function triage_is_changed(item) {
        //Sorts through inputs to see if any haven't been updated yet and
        // returns the id so that we call change() on submit
        item = item || ".triage-forms";
        var ret = "";
        var selector = item + ' input.triage-input';
        $(selector).each(function (index) {
          slct = $(this);
          var last = slct.data("last");
          if (slct.attr('type') == 'checkbox' || slct.attr('type') == 'radios') {
            if (last !== slct.attr('checked')) {
              var newval = slct.attr('checked');
              slct.data('last', newval);
              ret = slct.attr('id');
              return ret;
            }
          }
          else {
            if (slct.val() !== last) {
              var newval = slct.val();
              slct.data('last', newval);
              ret = slct.attr('id');
              return ret;
            }
          }
        });
        return ret;
      }

      function triage_income_validate() {
        triage_clicks();
        var msg = '';
        $('#edit-triage-household').removeClass('alert');
        $('#edit-triage-income').removeClass('alert');
        $('div.notice').remove();
        var ret = true;
        var size = $('#edit-triage-household').val();
        msg = isTriageInteger(size, "Household Size");
        if (msg > "") {
          $('#edit-triage-household').val('');
          $('#triage-pov-form').prepend('<div class="notice">' + msg + '</div>');
          $('#edit-triage-household').addClass('alert');
          return false;
        }
        if (size === '0' || size.trim() === '') {
          if (size === '0') {
            msg = "Household size must be at least 1";
            $('#edit-triage-household').addClass('alert');
            $('#triage-pov-form').prepend('<div class="notice">' + msg + '</div>');
            return false;
          }
          else {
            msg = "Household size must be entered";
            $('#edit-triage-household').addClass('alert');
            $('#triage-pov-form').prepend('<div class="notice">' + msg + '</div>');
            return false;
          }
        }
        else {
          $('#edit-triage-household').removeClass('alert');
        }
        var income = $('#edit-triage-income').val();
        msg = isTriageInteger(income, "Income");
        if (msg > "") {
          $('#edit-triage-income').val('');
          $('#triage-pov-form').prepend('<div class="notice">' + msg + '</div>');
          return false;
        }
        if (income === null || income.trim() === '') {
          msg = "Household income must be entered";
          $('#edit-triage-income').addClass('alert');
          $('#triage-pov-form').prepend('<div class="notice">' + msg + '</div>');
          return false;
        }
        else {
          $('#edit-triage-income').removeClass('alert');
        }
        var pc = triageComputePOV(size, income);
        if (pc > 400) {
          if (!confirm("Are you sure $" + income + " is your MONTHLY income?")) {
            return false
          }
        }
        return true;
      }

      function triage_income2_validate(stop_scroll) {

        triage_clicks();
        var msg = '';
        $('#edit-triage-household').removeClass('alert');
        $('#edit-triage-income').removeClass('alert');
        $('#edit-triage-income-period').removeClass('alert');
        $('div.notice').remove();
        var alone = $("input[name='triage_live_alone']:checked").val();
        var inc_type = $("input[name='triage_income_period']:checked").val();
        var ret = true;
        var size = $('#edit-triage-household').val();
        msg = isTriageInteger(size, "Household Size");
        if (msg > "" && !alone == '0') {
          $('#edit-triage-household').val('');
          $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
          $('#edit-triage-household').addClass('alert');
          return false;
        }
        if (alone === '1') {
          if (size === '0' || size.trim() === '') {
            if (size === '0') {
              msg = "Household size must be at least 1";
              $('#edit-triage-household').addClass('alert');
              $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
              return false;
            }
            else {
              msg = "Household size must be entered";
              $('#edit-triage-household').addClass('alert');
              $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
              return false;
            }
          }
        }
        else {
          $('#edit-triage-household').removeClass('alert');
        }
        var income = $('#edit-triage-income').val();
        msg = isTriageInteger(income, "Income");
        if (msg > "") {
          $('#edit-triage-income').val('');
          $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
          return false;
        }
        if (income === null || income.trim() === '') {
          msg = "Household income must be entered";
          $('#edit-triage-income').addClass('alert');
          $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
          return false;
        }
        else {
          $('#edit-triage-income').removeClass('alert');
        }
        var period = inc_type;
        if (typeof inc_type === "undefined") {
          msg = "Please enter income type";
          $('#edit-triage-income-period').addClass('alert');
          $('#triage-income-form').prepend('<div class="notice">' + msg + '</div>');
          return false;
        }
        if (size.trim() === '') {
          size = '0';
        }
        var pc = triageComputePOV(parseInt(size) + 1, income, period);
        if (pc < 200) {
          if ($('#edit-triage-last-info').css('display') == "none") {
            $('#edit-triage-last-info').css('display', 'block');
            stop_scroll[0] = true;
            return false;
          }
        }

        return true;
      }

      function triage_location_validate() {
        triage_clicks();
        var msg = '';
        $('#edit-triage-county').removeClass('alert');
        $('div.notice').remove();

        ret = true;
        val = $('#edit-triage-county').val();
        if (val == '') {
          ret = false;
          msg = "Please select a county";
          $('#edit-triage-county').addClass('alert');
          $('#triage-location-form').prepend('<div class="notice">' + msg + '</div>');
        }
        return ret;
      }

      function triage_bank_validate() {
        triage_clicks();
        $('#edit-triage-bank-amt').removeClass('alert');
        $('div.notice').remove();
        var ret = true;
        var amt = $('#edit-triage-bank-amt').val();
        if (amt === null || amt == '') {
          ret = false;
          $('#edit-triage-bank-amt').addClass('alert');
        }
        else {
          $('#edit-triage-bank-amt').removeClass('alert');
        }
        if (!ret) {
          $('div.notice').remove();
          $('#triage-bank-form').prepend('<div class="notice">Values outlined in red are required</div>');
        }
        return ret;
      }

      function triage_zip_validate() {
        triage_clicks();
        ret = true;
        $('#edit-triage-zip').removeClass('alert');
        $('div.notice').remove();
        //$('.city-fail').remove();
        if (Drupal.settings.zip_code_success===false || typeof Drupal.settings.zip_code_success=="undefined"){
          ret = false;
        }
        if ($('.city-fail').length > 0) {
          ret = false;
        }
        else {
            if ($('#triage_city').length > 0 &&  $.trim($('#triage_city').html()) > ''){
            ret = true;
          }
        }
        if (!ret) {
          $('div.notice').remove();
          //$('#edit-triage-zip').addClass('alert');
          var msg = 'Values outlined in red are required';
          if (Drupal.settings.zip_code_success == false || typeof Drupal.settings.zip_code_success == "undefined") {
            msg = "Enter 000, if you don't know your town name or zipcode";
          }
          //$('#triage-zip-form').prepend('<div class="notice">' + msg +
          // '</div>');
        }
        return ret;
      }

      function triage_status_validate() {
        triage_clicks();
        $('#edit-triage-status').removeClass('alert');
        $('div.notice').remove();
        var ret = true;
        var num = $('#edit-triage-status input:checked').length;
        if (num === 0) {
          ret = false;
        }
        if (!ret) {
          $('div.notice').remove();
          $('#edit-triage-status').addClass('alert');
          $('#triage-status-form').prepend('<div class="notice">Please Select one or more options</div>');
        }
        return ret;
      }

      function triage_sa_validate() {
        triage_clicks();
        var sa = $("#edit-triage-area input[type='radio']:checked").val();
        $('#edit-triage-area').removeClass('alert');
        $('div.notice').remove();
        var ret = true;
        if (typeof sa == 'undefined') {
          ret = false;
          $('#edit-triage-area').addClass('`');
        }
        else {
          if (sa == '1') {
            var proc_path = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath;
            var post_url = proc_path + 'triage-post';
            var data = {};
            data.rows = array();
            row = {
              form: 'triage-in-service-area-form', inputs: '', values: sa
            };
            data.rows.push(row);
            triage_loading();
            $.post(post_url, data, function (response, status) {
              if (status == 'success') {
                $('.triage-loading').remove();
              }
              url = proc_path + Drupal.settings.sa_url;
              window.location.href = url;
            });
            return false;
          }
        }
        if (!ret) {
          $('div.notice').remove();
          $('#triage-in-service-area-form').prepend('<div class="notice">Please Select one of the Options</div>');
        }
        return ret;
      }

      function triage_reset(item) {
        $('div.triagetip').remove();
        triage_loading();
        var triage_path = window.location.protocol + "//" + window.location.host;
        var lang = Drupal.settings.my_triage.lang;
        var defa_lang = Drupal.settings.my_triage.default_lang;
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        triage_path = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "/";
        var len = Drupal.settings.my_triage.tid.length - 1;
        var tid = Drupal.settings.my_triage.tid[len - 1];
        if (tid == 0) {
          var url = triage_path + tid + "/1/-1";
        }
        else {
          var url = triage_path + tid + "/1/-1";
        }
        Drupal.settings.my_triage.tid.length = len;
        triage_getdata(url, tid);
        $('.triage-loading').remove();
      }

      function triage_moveon(item) {
        $('div.triagetip').remove();
        var triage_path = window.location.protocol + "//" + window.location.host;
        var lang = Drupal.settings.my_triage.lang;
        var defa_lang = Drupal.settings.my_triage.default_lang;
        if (lang == defa_lang) {
          lang = '';
        }
        else {
          lang = lang + "/";
        }
        triage_path = triage_path + Drupal.settings.basePath + lang + "triage/" + Drupal.settings.my_triage.vocab + "/";
        nokids = item.hasClass('nokids');
        if (nokids){item.removeClass('nokids');}
        var nohelp = item.hasClass('tr-help');
        if (nohelp) {
          item.removeClass('tr-help');
        }
        var thisclass = item.attr('class');
        var tid = thisclass.replace('triage-row trow-', '');
        var len = Drupal.settings.my_triage.tid.length;
        Drupal.settings.my_triage.tid[len] = tid;
        var url = triage_path + tid + "/1/-1";
        triage_getdata(url, tid, nokids);
        triage_clicks();
        var offset = Drupal.settings.my_triage.scroll_offset;
        $('html, body').animate({scrollTop: (offset)}, 'fast');
      }

      function triage_clicks() {
        if ($('.triage-top').length) {
          //$('.triage-group-reset').html('Start Again');
        }
        if ($('.ta-message-panel').height() > 0) {
          $('.ta-help-panel').css('margin-top', 0);
        }

        if ($('.display-wrapper:contains("Public Benefits")').children('div.triage-action-item').size() < 2) {
          $('.display-wrapper:contains("Public Benefits")').hide();
        }
        $('#edit-triage-income').change(function () {
          if ($(this).val() == 0) {
            $('#edit-triage-income-period-annual').attr('checked', 'checked');
            $('.triage-income_period').hide();
          }
          else {
            $('.triage-income_period').show();
          }
        });
        alreadyclicked = false;
        //$('input[type=radio][name=triage_area_info]').unbind();
        $('input[type=radio][name=triage_area_info]').change(function () {
          if (this.value == '0') {
            $('#triage-page-wrapper').css('opacity', '0.2');
            triage_loading();
            var url = Drupal.settings.my_triage.oos_url;
            if (url.indexOf("http") === -1){
              url = window.location.protocol + "//" + window.location.host;
              url += Drupal.settings.basePath + Drupal.settings.my_triage.oos_url;
            }
            window.location.href = url;
          }
        });
        // unsets click and  functions so that we don't get doubles
        $('.triage-row').unbind();
        $('.triage-row').die("click");
        $('.triage-row').live('click', function () {
          //e.stopPropagation();
          //e.preventDefault();
          var el = $(this);
          triage_moveon($(el));
          return false;
        });
        $('.triage-reset').unbind();
        $(".triage-reset").die("click");
        $(".triage-reset").live('click', function () {
          var el = $(this);
          triage_reset($(el));
        });
        $('.triage-submit').unbind();
        $(".triage-submit").die("click");
        $(".triage-submit").live('click', function () {
          triage_submit();
          return false;
        });
        $('.triage-group-submit').unbind();
        $(".triage-group-submit").die("click");
        $(".triage-group-submit").live('click', function () {
          var el = $(this);
          triage_grpmove($(el));
        });
        $('.triage-group-reset').unbind();
        $(".triage-group-reset").die("click");
        $(".triage-group-reset").live('click', function () {
          $('div.triagetip').remove();
          triage_loading();
          var el = $(this);
          if (el.hasClass('bypass')) {
            el.removeClass('bypass');
            var triage_path = window.location.protocol + "//" + window.location.host;
            url = triage_path + Drupal.settings.basePath + "triage_change_it/true";
            $.post(url, function (data) {
              triage_path += Drupal.settings.basePath + "triage/" + Drupal.settings.my_triage.vocab + "/";
              window.location.href = triage_path;
              triage_loading();
            });
          }
          triage_grpreset($(el));
        });
        $('.tr-help').after("<div class='tr1-help'>&#xf05a;</div>");
        $('.tr1-help').click(function () {
          $('div.triagetip').remove();
          item = $(this).prev('.tr-help');
          if (!$(this).hasClass('expanded')) {
            $('.tr1-help').removeClass('expanded');
            $('.tr1-help').html('&#xf05a;');
            $(this).html('&#xf057;');
            $(this).addClass('expanded');
            $(this).attr('title', "Close Help");
            var thisclass = item.attr('class');
            var tid = thisclass.replace('nokids', '');
            tid = tid.replace('tr-help', '');
            tid = tid.replace('triage-row trow-', '');
            tid = tid.trim();
            var pick = '.thelp-' + tid;
            var text = $(pick).html() + '<div class="arrow"></div>';
            if ($('div.triagetip').length == 0) {
              $('<div class="triagetip"></div>').appendTo('body');

            }
            $('.triagetip').html(text);
            var thisheight = $('.triagetip').height();
            if ($(window).width() - 400 - $(this).offset().left > 0) {
              var tPosX = $(this).offset().left - 70;
            }
            else {
              $(this).width = $(window).width();
              var tPosX = 0
            }
            var tPosY = item.offset().top - thisheight - 60;
            $('div.triagetip').css({
              'position': 'absolute',
              'top': tPosY,
              'left': tPosX
            });
            $('div.triagetip').show();
            $('<span class="x-it">&#xf057;</span>').appendTo('.triagetip');
            $('.x-it').click(function () {
              $(this).parent().remove();
              $('.tr1-help').removeClass('expanded');
              $('.tr1-help').html('&#xf05a;');
            })
          }
          else {
            $(this).html('&#xf05a;');
            $(this).removeClass('expanded');
            $(this).attr('title', "Get Info");
            $('div.triagetip').remove();
          }
        });
        $('.triage-restart').unbind();
        $(".triage-restart").die("click");
        $('.triage-restart').live('click', function () {
          var el = $(this);
          triage_restart();
        });
      }

      function triage_getdata(url, tid, nokids) {
        var out = '';
        triage_loading();
        $.getJSON(url, function (data) {
          if (data) {
            out = out + data;
          }
          $(".triage-main-body").parent().html(out);
          //$(".triage-content").html(out);
          if (Drupal.settings.my_alt_display.use_alt) {
            var home_path = window.location.protocol + "//" + window.location.host;
            home_path += Drupal.settings.basePath;
            var homebutton = "<div class='home-button'><a href='" + home_path + "'>Home</a></div>";
            if ($('.home-button').length == 0) {
              $('#triage-page-wrapper').prepend(homebutton);
            }
          }
          $(".triage-loading").remove();
          if (nokids) {
            $('.triage-sub-text').remove();
          }
          adjust_nav_css();
          triage_clicks();
          $(".triage-loading").remove();
          var offset = Drupal.settings.my_triage.scroll_offset;
          $('html, body').animate({ scrollTop:(offset)}, 'fast');

        });
      }

      function triage_writedata(url) {
        var out = '';
        $.getJSON(url, function (data) {
          if (data) {
            console.log('in data');
          }
          $(".triage-loading").remove();
        });
      }

      function triage_getpopup(url) {
        var out = '';
        $.getJSON(url, function (data) {
          if (data) {
            out = out + data;
          }
        });
      }

      function objToString(obj) {
        var str = '';
        for (var p in obj) {
          if (obj.hasOwnProperty(p)) {
            str += p + '::' + obj[p] + '\n';
          }
        }
        return str;
      }

      function adjust_nav_css() {
        if (typeof Drupal.settings.my_triage !== 'undefined') {
          $('.ta-nav-bar').css('background-color', Drupal.settings.my_triage.triage_nav_bar_color);
          var resetcss = Drupal.settings.my_triage.resetcss;
          var button = $('.triage-group-reset');
          $.each(resetcss, function (key, value) {
            button.css(key, value);
          });
          var button = $('.triage-reset');
          $.each(resetcss, function (key, value) {
            button.css(key, value);
          });
          var submitcss = Drupal.settings.my_triage.submitcss;
          var button = $('.triage-group-submit');
          $.each(submitcss, function (key, value) {
            button.css(key, value);
          });
          var button = $('.triage-submit');
          $.each(submitcss, function (key, value) {
            button.css(key, value);
          });
          var button = $('.triage-restart');
          $.each(submitcss, function (key, value) {
            button.css(key, value);
          });
        }
      }

      function triageComputePOV(size, inc, period) {
        if (typeof period === "undefined") {
          period = "Monthly";
        }
        var div_by = 12;
        switch (period) {
          case 'Weekly':
            div_by = 52;
            break;
          case 'Bi-Weekly':
            div_by = 26;
            break;
          case 'Monthly':
            div_by = 12;
            break;
          case 'Annual':
            div_by = 1;
            break;
        }
        vals = Drupal.settings.povguides;
            var base = vals[size] / div_by;
            return Math.round(inc*100/base);

      }

      function nobread() {
        var triage_path = window.location.protocol + "//" + window.location.host;
        $('.page-triage-actions-process #breadcrumbs').html("<a href='" + triage_path + "'>Home</a>");
      }

      function is_touch_device() {
        return (('on' in window) || (navigator.msMaxTouchPoints > 0))
      }

      function triage_sleep(milliseconds) {
        var start = new Date().getTime();
        for (var i = 0; i < 1e7; i++) {
          if ((new Date().getTime() - start) > milliseconds) {
            break;
          }
        }
      }

      function bdslegalloadPopup(popid) {
        //loads popup only if it is disabled
        var speed = Drupal.settings.triage_popup.speed;
        if (popupStatus === 0) {
          $("#triage-popup").css({"opacity": "0.7"});
          $("#triage-popup").delay(speed).fadeIn("slow");
          $("#" + popid).delay(speed).fadeIn("slow");
        }
      }

      //disabling popup with jQuery magic!
      function bdslegaldisablePopup(popid) {
        //disables popup only if it is enabled
        if (popupStatus === 1) {
          $("#triage-popup").fadeOut("slow");
          $("#" + popid).fadeOut("slow");
        }
      }

      //centering popup
      function bdslegalcenterPopup(popid) {
        //request data for centering
        // var windowWidth = document.documentElement.clientWidth;
        // var windowHeight = document.documentElement.clientHeight;
        var windowWidth = $(window).width();
        var windowHeight = screen.height;
        var popupHeight = $("#" + popid).height();
        var popupWidth = $("#" + popid).width();
        //centering
        $("#" + popid).css({
          "position": "fixed",
          "top": windowHeight / 2 - popupHeight / 2 - 100,
          "left": windowWidth / 2 - popupWidth / 2
        });
        //only need force for IE6
        $("#triage-popup").css({
          "height": windowHeight
        });
      }

      //LOADING POPUP
      //Click the button event!
      //CLOSING POPUP
      $("#bdslegalpopupClose").click(function () {
        bdslegaldisablePopup('bdslegalpopup');
        popupStatus = 0;
      });
      $(".no-popbutton").click(function () {
        var url = window.location.protocol + "//" + window.location.host + Drupal.settings.basePath + "triage-no-thanks";
        triage_getpopup(url);
        bdslegaldisablePopup('bdslegalpopup');
        popupStatus = 0;
      });
      $("#triage-popup").click(function () {
        bdslegaldisablePopup('bdslegalpopup');
        popupStatus = 0;
      });
      $(document).keypress(function (e) {
        if (e.keyCode === 27) {
          bdslegaldisablePopup('bdslegalpopup');
          popupStatus = 0;
        }
      });
    }
  };


  function triage_progress(grpid) {
    var steps = Drupal.settings.my_steps;
    var title = Drupal.settings.my_progress_bar.title;
    var extra = Drupal.settings.my_progress_bar.extra_step;
    var len = steps.length;
    if (extra) {
      len++;
    }
    var pct = 100 * (1 / len);
    if (grpid == -1) {
      grpid = Drupal.settings.my_steps[0];
    }
    var goby = false;
    if (typeof Drupal.settings.bypass_questions !== 'undefined') {
      if (Drupal.settings.bypass_questions) {
        goby = true;
      }
    }
    if (Drupal.settings.direct_nid || goby) {
      len = Drupal.settings.my_steps.length;
      grpid = Drupal.settings.my_steps[len - 1];
    }
    if (Drupal.settings.my_progress_bar.type == 'bar') {
    var origback = Drupal.settings.my_progress_bar.background;
    var origiconcolor = Drupal.settings.my_progress_bar.icon_color;
    var origactive = Drupal.settings.my_progress_bar.selected_back;
    var origtextcolor = Drupal.settings.my_progress_bar.text;
    var origactivetext = Drupal.settings.my_progress_bar.selected_text;
      $('.triage-step.active').removeClass('step-in-use');
      $('.triage-step-icon.active').removeClass('step-in-use');
      $('.triage-step').removeClass('active');
      $('.triage-step').css('background-color', origback);
      $('.triage-step').css('color', origtextcolor);
      $('.triage-step-icon').removeClass('active');
      $('.triage-step-icon').css('color', origiconcolor);
    }
    if (grpid >= 0) {
      if (Drupal.settings.my_progress_bar.type == 'bar') {
        $('#step-last').css('background-color', origback);
        $('#step-last').css('color', origtextcolor);
        $('#step-last').removeClass('active')
      }
      for (i = 0; i < len; i++) {
      var grp = steps[i];
        $('#step-' + steps[i]).addClass('step-in-use');
        $('#icon-' + steps[i]).addClass('step-in-use');
        if (parseInt(grp) == grpid) {
          if (Drupal.settings.my_progress_bar.type == 'bar') {
            $('#step-' + steps[i]).css('background-color', origactive);
            $('#step-' + steps[i]).css('color', origactivetext);
            $('#icon-' + steps[i]).css('color', origactive);
            $('#step-' + steps[i]).addClass('active');
            $('#icon-' + steps[i]).addClass('active');
          }
          break;
        }

      }
    }
    else {
      if (Drupal.settings.my_progress_bar.type == 'bar') {
        $('#step-last').addClass('step-in-use');
        $('#icon-last').addClass('step-in-use');
        $('#step-last').css('background-color', origactive);
        $('#step-last').css('color', origactivetext);
        $('#step-last').addClass('active');
        $('#icon-last').css('color', origactive);
        $('#icon-last').addClass('active')
      }
      i = len - 1;
    }
    var curstep = i + 1;
    if (curstep == len){
      $('.triage-step').addClass('step-in-use');
      $('.triage-step-icon').addClass('step-in-use');
    }
    pct = 100 * (curstep / len);
  var text = title + ' (Step ' + curstep + ' of ' +  (len) + ')';
    $.cookie('triage_current_step', curstep, {path: '/'});
    if (Drupal.settings.my_progress_bar.type == 'bar') {
      $('.triage-progress-bar').html(text);
    }
  var dist = 0;
  var amt = 0;
  var op = 0;
    if (Drupal.settings.my_progress_bar.type == 'bar') {
      for (k = 0; k < i; k++) {
        dist = i - k;
        dist = Math.max(dist, 1);
        len = steps.length - 1;
        len = Math.max(len, 2);
        amt = 100 / len;
        op = (amt * dist) / 100;
        var newcolor = ColorLuminance(origactive, op);
        var newcolor2 = ColorLuminance(origactivetext, (-op/1.25));
        $('#step-' + steps[k]).css('background-color', newcolor);
        $('#step-' + steps[k]).css('color', newcolor2);
        $('#icon-' + steps[k]).css('color', newcolor);
      }
    }
    else {
      var pie = '<span class="triage-chart" data-percent="' + pct + '"><span class="triage-percent"></span></span>';
      $('.triage-chart').remove();
      $('.ta-help-panel').prepend(pie);
      $('.triage-chart').easyPieChart({
        animate: 500,
        barColor: '#69c',
        trackColor: '#ace',
        scaleColor: false,
        lineWidth: 20,
        trackWidth: 16,
        lineCap: 'butt',
        onStep: function (from, to, percent) {
          $(this.el).find('.triage-percent').text(Math.round(percent));
        }
      });
      triage_chart = window.triage_chart = $('.triage-chart').data('easyPieChart');
    }
  }

  function ColorLuminance(hex, lum) {
    // validate hex string
    hex = String(hex).replace(/[^0-9a-f]/gi, '');
    if (hex.length < 6) {
      hex = hex[0] + hex[0] + hex[1] + hex[1] + hex[2] + hex[2];
    }
    lum = lum || 0;
    // convert to decimal and change luminosity
    var rgb = "#", c, i;
    for (i = 0; i < 3; i++) {
      c = parseInt(hex.substr(i * 2, 2), 16);
      c = Math.round(Math.min(Math.max(0, c + (c * lum)), 255)).toString(16);
      rgb += ("00" + c).substr(c.length);
    }
    return rgb;
  }

  function triage_loading() {
    $('div.triage-loading').remove();
    $('body').append("<div class='triage-loading'><i class='fa fa-spinner fa-spin'></i>Loading...</div>");
    $('div.triage-loading').show();
  }

  function isTriageInteger(s, fn) {
    if (typeof fn === 'undefined') {
      fn = 'This Field';
    }
    var error = "";
    var i;
    s = s.replace(",", '');
    s = s.replace("$", '');
    var find = s.indexOf(".");
    if (find > -1) {
      s = s.substring(0, find);
    }
    for (i = 0; i < s.length; i++) {
      // Check that current character is number.
      var c = s.charAt(i);
      if (((c < "0") || (c > "9"))) {
        error = fn + " must be a number only, with no commas or dollar sign\n";
      }
    }
    if (fn == "Income") {
      $("#edit-triage-income").val(s);
    }
    // All characters are numbers.
    return error;
  }
})(jQuery);
