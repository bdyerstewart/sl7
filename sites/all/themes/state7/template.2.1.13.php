<?php
function state7_preprocess_page(&$vars, $hook) {
  // Removes a tab called 'Reviews, change with your own tab title
  state7_removetab('Log', $vars);
}
// Remove undesired local task tabs.
// Related to yourthemename_removetab() in yourthemename_preprocess_page().
function state7_removetab($label, &$vars) {

  // Remove from primary tabs
  $i = 0;
  if (is_array($vars['tabs']['#primary'])) {
    foreach ($vars['tabs']['#primary'] as $primary_tab) {
      if ($primary_tab['#link']['title'] == $label) {
        unset($vars['tabs']['#primary'][$i]);
      }
      ++$i;
    }
  }

  // Remove from secondary tabs
  $i = 0;
  if (is_array($vars['tabs']['#secondary'])) {
    foreach ($vars['tabs']['#secondary'] as $secondary_tab) {
      if ($secondary_tab['#link']['title'] == $label) {
        unset($vars['tabs']['#secondary'][$i]);
      }
      ++$i;
    }
  }
}