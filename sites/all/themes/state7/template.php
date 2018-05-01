<?php

function state7_preprocess_node(&$variables, $hook) {
  
  // Removes a tab called 'Reviews, change with your own tab title
  unset($variables['content']['rate_rate_content']['#title']);
}
function state7_preprocess_page(&$variables, $hook) {
  
  // Removes a tab called 'Reviews, change with your own tab title
  unset($variables['content']['rate_rate_content']['#title']);
  state7_removetab('Log', $variables);
  if (!empty($vars['is_front'])) {
    dsm($vars['page']);
    metatag_page_build($vars['page']);
  }  
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
function state7_page_alter($page) {
  // <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1"/>
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
    'name' =>  'viewport',
    'content' =>  'width=device-width'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

//function state7_css_alter(&$css) { 
//
//  // Sort CSS items, so that they appear in the correct order.
//  // This is taken from drupal_get_css().
//  uasort($css, 'drupal_sort_css_js');
//
//  // The Print style sheets
//  // I will populate this array with the print css (usually I have only one but just in case…)
//  $print = array();
//
//  // I will add some weight to the new $css array so every element keeps its position
//  $weight = 0;
//
//  foreach ($css as $name => $style) {
//
//    // I leave untouched the conditional stylesheets
//    // and put all the rest inside a 0 group
//    if ($css[$name]['browsers']['!IE']) {
//      $css[$name]['group'] = 0;
//      $css[$name]['weight'] = ++$weight;
//      $css[$name]['every_page'] = TRUE;
//    }
//
//    // I move all the print style sheets to a new array
//    if ($css[$name]['media'] == 'print') {
//      // remove and add to a new array
//      $print[$name] = $css[$name];
//      unset($css[$name]);
//    }
//
//  }
//  
//  // I merge the regular array and the print array
//  $css = array_merge($css, $print);
//
//}