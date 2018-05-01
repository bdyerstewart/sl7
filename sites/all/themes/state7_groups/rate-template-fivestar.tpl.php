<?php

/**
 * @file
 * Rate widget theme
 */
$exclude_pages = array();
$exclude_pages[] = 'my-groups';
$thispage = basename($_SERVER['REQUEST_URI']);
if (in_array($thispage,$exclude_pages)){
    return;
}
print theme('item_list', array(
  'items' => $stars,
  //'title' => $display_options['title'],
  ));

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
