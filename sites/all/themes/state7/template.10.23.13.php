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

// mobile/desktop cookie setup
function state7_mobile_preprocess_html(&$vars) { 
    global $cookie_domain; 
    drupal_add_library("system", "jquery.cookie"); 
    drupal_add_js(array("cookie_domain" => $cookie_domain), "setting"); 
    if (module_exists('rdf')) { 
        $vars['doctype'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN">' . "\n"; $vars['rdf']->version = 'version="HTML+RDFa 1.1"';
        $vars['rdf']->namespaces = $vars['rdf_namespaces']; $vars['rdf']->profile = ' profile="' . $vars['grddl_profile'] . '"'; 
    } 
    else { 
        $vars['doctype'] = '<!DOCTYPE html>' . "\n"; $vars['rdf']->version = ''; $vars['rdf']->namespaces = ''; $vars['rdf']->profile = ''; 
    } 
}
//function state7_breadcrumb($variables) {
//  $breadcrumb = $variables['breadcrumb'];
//  if (!empty($breadcrumb)) {
//    // Adding the title of the current page to the breadcrumb.
//    //print_r($breadcrumb);
//    $this_title = drupal_get_title();
//    if ($this_title != "Stateside Library"){
//        $breadcrumb[] = drupal_get_title();
//    }
//    // Provide a navigational heading to give context for breadcrumb links to
//    // screen-reader users. Make the heading invisible with .element-invisible.
//    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
//    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
//    
//    return $output;
//  }
//}