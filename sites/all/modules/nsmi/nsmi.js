
function UpdateChildren(chk, checked) {
  var row = $(chk).parents('tr:first');
  var id = $(row).attr('ui_sid');
  
  if (checked) {
    $(row).addClass('selected');
    $(chk).attr('checked', 'checked');
  }
  else {
    $(row).removeClass('selected');
    $(chk).removeAttr('checked');
  }

  $("tr[ui_pid='" + id + "'] :checkbox").trigger('updateChildren', [checked]);                           
}

function UpdateParents(chk, checked) {            
  var row = $(chk).parents('tr:first');
  var pid = $(row).attr('ui_pid');
  var parent_row = $("tr[ui_sid='" + pid + "']");
  var parent_chk = $(parent_row).find(':checkbox');
  
  if (checked) {
    parent_chk.attr('checked', 'checked');
    $(row).addClass('selected');
    $(parent_chk).trigger('updateParents', [checked]);
  }               
}

$(function() {
  $('input.form-checkbox').bind('updateChildren', function(e, checked){ UpdateChildren(this, checked) });
  $('input.form-checkbox').bind('updateParents', function(e, checked){ UpdateParents(this, checked) });
  
  $('input.form-checkbox').bind('click', function() {                                                
    var checked = $(this)[0].checked;

    $(this).trigger('updateChildren', [checked]);
    $(this).trigger('updateParents', [checked]);
  });
});