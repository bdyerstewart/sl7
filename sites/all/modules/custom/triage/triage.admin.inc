<?php
function triage_admin_form($form, &$form_state) {
  global $base_url;
  $ta_nid = arg(1);
  $names = node_type_get_names();
  drupal_add_js($base_url . ('/misc/drupal.js'), 'file');
  drupal_add_js($base_url . ('/misc/collapse.js'), 'file');
  drupal_add_js($base_url . ('/misc/jquery.cookie.js'), 'file');
  drupal_add_js($base_url . ('/misc/vertical-tabs.js'), 'file');
  $popup_msg = variable_get('triage_popup_basemsg', '');
  if (!isset($popup_msg['value'])) {
    $popup_basemsg_text = '';
  }
  else {
    $popup_basemsg_text = $popup_msg['value'];
  }
  if (!isset($popup_msg['format'])) {
    $popup_basemsg_format = 2;
  }
  else {
    $popup_basemsg_format = $popup_msg['format'];
  }
  $fld_opts = array();
  $opts = db_query("select distinct field_name from field_config where type = 'taxonomy_term_reference'")->fetchCol();
  $fld_opts[] = "None";
  foreach ($opts as $opt) {
    $fld_opts[$opt] = $opt;
  }
  $cnty_opts = array();
  $copts = db_query("select distinct field_name from field_config")->fetchCol();
  foreach ($copts as $copt) {
    $cnty_opts[$copt] = $copt;
  }
  $form = array();
  $form['triage_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage General Options'),
    '#collapsible' => TRUE, // Added
  );
  $form['triage_general']['triage_use_sms'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_use_sms', FALSE),
    '#title' => t('Use Messaging Service, if available, as Results Option'),
  );
  $form['triage_general']['triage_sms_block'] = array(
    '#type' => 'textfield',
    '#name' => 'triage_sms_block',
    '#default_value' => variable_get('triage_sms_block', 'block-webform-client-block-2252'),
    '#size' => 125,
    '#title' => t('ID of Webform for Text Cell Phone #'),
  );
  $form['triage_general']['triage_use_search_views'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_use_search_views', TRUE),
    '#title' => t('Use Triage Info in various search views'),
  );
  $form['triage_css_option'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#title' => t('Triage Custom CSS options'),
    '#collapsible' => TRUE, // Added
  );
  $form['triage_css_option']['triage_custom_css'] = array(
    '#type' => 'textfield',
    '#name' => 'triage_custom_css',
    '#size' => 50,
    '#default_value' => variable_get('triage_custom_css', '', $ta_nid),
    '#title' => t('Path and file name of custom css file'),
    '#description' => t('file name of custom css file for Triage, assumed to be in root of the theme, e.g. <em>/my_triage_custom.css</em>'),
  );
  $form['triage_css_option']['triage_css_dropdown'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Custom Class Dropdown Items'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['triage_css_option']['triage_css_dropdown']['triage_custom_classes'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom Classes for Class Dropdowns'),
    '#default_value' => variable_get('triage_custom_classes',
      'none~None
ta-contrast-background~Contrasting Background
ta-alert~Warning Box
*ta-two-panels~Two Panel Layout
*ta-right~Right Pane
*ta-left~Left Panel
*clear-both~Clear Float', $ta_nid),
    '#description' => 'Enter custom classes in the format classname~Class Name, e.g. 
                          <em>ta-contrast-background~Contrasting Background</em><br />
                          One class per line.  Use an * in front of the entry for wrapper-only classes',
    '#rows' => 5,
    '#suffix' => "<div style='margin-bottom:10px;'></div>",
  );
  $form['content_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Search'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['content_types']['triage_search'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Search Configuration'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['content_types']['triage_search']['triage_search_field'] = array(
    '#type' => 'select',
    '#options' => $fld_opts,
    '#default_value' => variable_get('triage_search_field', ''),
    '#title' => t('Triage Search Tag Table'),
    '#description' => t('Table that holds triage tags for various content'),
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['content_types']['triage_search']['triage_search_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Type to Include in Search'),
    '#options' => array_map('check_plain', $names),
    '#default_value' => variable_get('triage_search_types', array()),
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['content_types']['triage_orgsearch'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Organization Search Configuration'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['content_types']['triage_orgsearch']['triage_orgtype_field'] = array(
    '#type' => 'select',
    '#options' => $fld_opts,
    '#default_value' => variable_get('triage_orgtype_field', ''),
    '#title' => t('Triage Organizational Type Table'),
    '#description' => t('Table that holds organizational type info'),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['content_types']['triage_orgsearch']['triage_orgcounty_field'] = array(
    '#type' => 'select',
    '#options' => $cnty_opts,
    '#default_value' => variable_get('triage_orgcounty_field', ''),
    '#title' => t('Triage County Table'),
    '#description' => t('Table that holds county info'),

  );
  $form['content_types']['triage_orgsearch']['triage_orgsearch_field'] = array(
    '#type' => 'select',
    '#options' => $fld_opts,
    '#default_value' => variable_get('triage_orgsearch_field', ''),
    '#title' => t('Triage Organization Search Tag Table'),
    '#description' => t('Table that holds triage tags for various content'),
    //'#suffix' => "</div>",
  );
  $form['content_types']['triage_orgsearch']['triage_orgincome_field'] = array(
    '#type' => 'select',
    '#options' => $fld_opts,
    '#default_value' => variable_get('triage_orgincome_field', ''),
    '#title' => t('Triage Income Visibility Table'),
    '#description' => t('Table that holds triage income filters'),
  );
  $form['content_types']['triage_orgsearch']['triage_status_field'] = array(
    '#type' => 'select',
    '#options' => $fld_opts,
    '#default_value' => variable_get('triage_status_field', ''),
    '#title' => t('Triage Status Table'),
    '#description' => t('Table that holds status info'),
  );
  $form['content_types']['triage_orgsearch']['triage_search_func'] = array(
    '#type' => 'textfield',
    '#name' => 'triage_search_func',
    '#size' => 50,
    '#default_value' => variable_get('triage_search_func', 'triage_orgsearch'),
    '#title' => t('Name of custom organizational search function'),
    '#description' => t('Name of custom organizational search function, found in triage.orgsearch.inc'),
  );
  $form['content_types']['triage_orgsearch']['triage_use_multiple_org_filters'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_use_multiple_org_filters', FALSE),
    '#title' => t('Use Multiple Organization Filter Capability'),
    '#description' => t('When checked, the advanced, multiple organizational filtering function is turned on, allowing a finer grained eligibility criteria'),
    '#suffix' => "</div>",
  );
  $form['content_types']['triage_orgsearch']['triage_orgsearch_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Type to Include in Organization Search'),
    '#options' => array_map('check_plain', $names),
    '#default_value' => variable_get('triage_orgsearch_types', array()),
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );

  $form['reports'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Report Settings'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['reports']['triage_nonservice'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_nonservice', FALSE),
    '#title' => t('Include Out of Service Area Stats'),
  );
  $form['reports']['triage_use_county'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_use_county', FALSE),
    '#title' => t('Include County Information'),
    '#description' => 'If you are collecting town/zipcode info, turn on to display County data',
  );
  $form['reports']['triage_use_income'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('triage_use_income', FALSE),
    '#title' => t('Display Income Information'),
    '#description' => 'If you are collecting income info, turn on to display Income data',
  );
  $form['popup'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Popup Settings'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['popup']['triage_use_popup'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable Popup for Triage',
    '#description' => t("If checked, a popup will display tagged content to suggest triage"),
    '#default_value' => variable_get('triage_use_popup', FALSE),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['popup']['triage_pop_min_width'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('triage_pop_min_width', "0"),
    '#title' => t('Popup screen width threshhold'),
    '#description' => 'Mimimum screen width before triage popup is activated',
  );
  $form['popup']['triage_pop_max_width'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('triage_pop_max_width', "0"),
    '#title' => t('Popup screen width turn-off'),
    '#description' => 'Maximum screen width before triage popup is de-activated',
  );
  $form['popup']['triage_use_parents_in_popup'] = array(
    '#type' => 'checkbox',
    '#title' => 'Include checked parent categories in popup search',
    '#description' => t("If checked, a popup will be flagged for parent categories as well as specific"),
    '#default_value' => variable_get('triage_use_parents_in_popup', FALSE),
  );
  $form['popup']['triage_use_alt_url'] = array(
    '#type' => 'checkbox',
    '#title' => 'Use Alt Base URL',
    '#description' => t("If checked, an alternate base url can be used for triage"),
    '#default_value' => variable_get('triage_use_alt_url', FALSE),
  );
  $form['popup']['triage_alt_base_url'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('triage_alt_base_url', "http://michiganlegalhelp.org"),
    '#title' => t('Alternate base_url for triage'),
    '#description' => 'Fill in base url for triage testing, if different than content/popup testing site',
  );
  $form['popup']['triage_default_voc'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('triage_default_voc', "me_triage"),
    '#title' => t('Triage path'),
  );
  $form['popup']['triage_popup_title'] = array(
    '#type' => 'textfield',
    '#default_value' => t(variable_get('triage_popup_title', "Can we help you?")),
    '#title' => t('Popup Header'),
  );
  $form['popup']['triage_yes_text'] = array(
    '#type' => 'textfield',
    '#default_value' => t(variable_get('triage_yes_text', "Yes I'd Like Help")),
    '#title' => t('Popup Yes Text'),
  );
  $form['popup']['triage_gen_text'] = array(
    '#type' => 'textfield',
    '#default_value' => t(variable_get('triage_gen_text', "I'd Like Help with</br> Something Else")),
    '#title' => t('Popup General Help Text'),
  );
  $form['popup']['triage_no_text'] = array(
    '#type' => 'textfield',
    '#default_value' => t(variable_get('triage_no_text', "No Thanks - Don't Ask Again")),
    '#title' => t('Popup No Text'),
  );
  $form['popup']['triage_popup_speed'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('triage_popup_speed', "5000"),
    '#title' => t('Popup Delay'),
  );
  $form['popup']['triage_popup_norepeat'] = array(
    '#type' => 'textfield',
    '#description' => 'To minimize confusion, it can be helpful to skip popup for several iterations',
    '#default_value' => variable_get('triage_popup_norepeat', 2),
    '#title' => t('#popups to skip after reaching an endpoint'),
  );
  $form['popup']['triage_popup_basemsg'] = array(
    '#type' => 'text_format',
    '#title' => t('Popup Base Message'),
    '#default_value' => $popup_basemsg_text,
    '#format' => $popup_basemsg_format,
    '#rows' => 3,
    '#description' => t('Text used at the bottom of the popup, just ahead of the buttons'),
  );
  $form['popup']['triage_use_popup_taxonomy_language'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add taxonomy reference text'),
    '#description' => t("If checked, a taxonomy reference title will be added to popup message - You seem to be interested in..."),
    '#default_value' => variable_get('triage_use_popup_taxonomy_language', TRUE),
  );
  $form['popup']['triage_libtable'] = array(
    '#type' => 'textfield',
    '#description' => t("Table that you're currently using to hold primary content categorization data"),
    '#default_value' => variable_get('triage_libtable', "field_data_taxonomy_vocabulary_10"),
    '#title' => t('Taxonomy table used for categorization'),
  );
  $form['popup']['triage_libtid'] = array(
    '#type' => 'textfield',
    '#description' => t("Taxonomy id field (tid) from the above taxonomy data table"),
    '#default_value' => variable_get('triage_libtid', "taxonomy_vocabulary_10_tid"),
    '#title' => t('Taxonomy id field used for categorization'),
  );
  $form['popup']['triage_ref_field'] = array(
    '#type' => 'textfield',
    '#description' => t("Taxonomy reference field that points to triage question/issue, for popop navigation"),
    '#default_value' => variable_get('triage_ref_field', "field_triage_ref_me_triage"),
    '#title' => t('Taxonomy reference field from above taxonomy that points to triage question'),
    '#suffix' => "</div>",
  );
  $form['popup']['triage_popup_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Types that will activate Popup'),
    '#options' => array_map('check_plain', $names),
    '#default_value' => variable_get('triage_popup_types', array()),
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );

  $form['ips'] = array(
    '#type' => 'fieldset',
    '#title' => t('IPs to exclude from Report '),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
  );
  $form['ips']['triage_exclude_ips'] = array(
    '#type' => 'textarea',
    '#description' => t("One entry per line"),
    '#default_value' => variable_get('triage_exclude_ips', ""),
    '#title' => t('IPs to exclude from Summary Report'),
  );
  return system_settings_form($form);
}

function triage_setup_form($form, &$form_state) {
  global $base_url;
  $factor_default_text = "Check all that apply so we can find the best resources for you.<br /><hr>";
  $ta_nid = arg(1);
  $_SESSION['triage']['triage_page_nid'] = $ta_nid;
  drupal_add_js($base_url . ('/misc/drupal.js'), 'file');
  drupal_add_js($base_url . ('/misc/collapse.js'), 'file');
  drupal_add_js($base_url . ('/misc/jquery.cookie.js'), 'file');
  drupal_add_js($base_url . ('/misc/vertical-tabs.js'), 'file');
  $one_state_vals = ta_variable_get('triage_one_state_text', '', $ta_nid);
  if (!isset($one_state_vals['value'])) {
    $one_state_text = '';
  }
  else {
    $one_state_text = $one_state_vals['value'];
  }
  if (!isset($one_state_vals['format'])) {
    $one_state_format = 2;
  }
  else {
    $one_state_format = $one_state_vals['format'];
  }
  $vocs = taxonomy_get_vocabularies();
  $voc_options = array();
  $voc_options[0] = 'None';
  foreach ($vocs as $voc) {
    $voc_options[$voc->vid] = $voc->name;
  }

  $logictext = "Ordering logic for display groups in triage action output. Intended to have instructions 
                  as to how to arrange display wrappers in the triage output.";

  $form['triage_setup'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['triage_setup_default'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Vocabulary and Path'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  // Text field for the e-mail subject.
  $form['triage_setup_default']['triage_page_nid'] = array(
    '#type' => 'hidden',
    '#size' => 15,
    '#default_value' => $ta_nid,
  );
  $form['triage_setup_default']['triage_vocabulary'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_vocabulary', '', $ta_nid),
    '#title' => t('Triage Taxonomy Tree'),
    '#description' => t('Taxonomy vocabulary to use for this set of triage questions'),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['triage_setup_default']['triage_libtable'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#description' => t("Table that you're currently using to hold primary content categorization data"),
    '#default_value' => ta_variable_get('triage_libtable', "", $ta_nid),
    '#title' => t('Taxonomy table used for categorization'),
    '#suffix' => "</div>",
  );

  $form['triage_setup_default']['triage_path'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_path', '', $ta_nid),
    '#title' => t('Path'),
    '#description' => t('URL alias that will access page.  
                            triagepage, e.g. would allow access to this page from http://vtlegal.org/triagepage 
                            if your home url is vtlegal.org'),
    '#prefix' => "<div class='two-panel'>",
    '#suffix' => "</div>",
  );
  $form['separation1'] = array(
    '#markup' => "<div class='clear-both'></div>",
  );
  $form['triage_location'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Location Info'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_location']['triage_state'] = array(
    '#type' => 'select',
    '#options' => triage_get_state_options(),
    '#default_value' => ta_variable_get('triage_state', '', $ta_nid),
    '#title' => t('Triage State'),
    '#description' => t('State (location) in which triage services apply'),
  );
  $form['triage_location']['triage_not_in_state'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_not_in_state', '', $ta_nid),
    '#size' => 30,
    '#title' => t('Triage Out of State Resource URL'),
    '#description' => t('URL to goto if out-of-state'),
  );
  $form['triage_location']['triage_one_state_text'] = array(
    '#type' => 'text_format',
    '#title' => t('One State Only Text'),
    '#default_value' => $one_state_text,
    '#format' => $one_state_format,
    '#rows' => 3,
    '#description' => t('Text in this field will inform the city\zipcode finder 
                          to only search for items within the Triage Page State. This text will be 
                          display when the zipcode or city is not found within the state.'),
  );
  $form['triage_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage User Status Settings'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_status']['triage_status_voc'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_status_voc', '', $ta_nid),
    '#title' => t('Triage Status Vocabulary'),
    '#description' => t('Taxonomy vocabulary to use for user status dropdown'),
  );
  $form['triage_income'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Income Taxonomy'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_income']['triage_income_eligibility'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_income_eligibility', 'triage_income_eligibility', $ta_nid),
    '#title' => t('Triage Income Vocabulary'),
    '#description' => t('Taxonomy vocabulary to use for income ranges, used to filter results'),
  );
  $form['triage_categories'] = array(
    '#type' => 'fieldset',
    '#title' => t('Legal Category Taxonomy'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_categories']['triage_legal_categories'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_legal_categories', '', $ta_nid),
    '#title' => t('Triage Legal Categories Vocabulary'),
    '#description' => t('Legal category by organizations to identify areas of legal services; <br />
                            will be added to triage taxonomy so that end points can match to facilitate organizational serarch'),
  );
  $form['triage_public_benefits'] = array(
    '#type' => 'fieldset',
    '#title' => t('Public Benefits Taxonomy'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_public_benefits']['triage_public_benefits'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_public_benefits', '', $ta_nid),
    '#title' => t('List of additional financial assistance benefits'),
    '#description' => t('Select taxonomy that holds additional financial benefits'),
  );
  $form['triage_factors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Lists and Options'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_factors']['triage_factos_text'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_factos_text', $factor_default_text, $ta_nid),
    '#size' => 125,
    '#title' => t('Text to display above factor checkboxes'),
  );
  $form['triage_factors']['triage_order_action_divs'] = array(
    '#type' => 'checkbox',
    '#default_value' => ta_variable_get('triage_order_action_divs', FALSE, $ta_nid),
    '#title' => t('Allow additional output ordering logic'),
    '#description' => t('Turn on to use other factors to order triage output display wrappers<br />this also adds a "kind of help" field to divs to use in ordering logic'),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['triage_factors']['triage_kind_of_help'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_kind_of_help', '', $ta_nid),
    '#title' => t('Kind of Help Being Sought'),
    '#description' => t('Select taxonomy that holds kind of help options'),
  );
  $form['triage_factors']['triage_factors'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_factors', '', $ta_nid),
    '#title' => t('List of other factors that might help direct kind of help'),
    '#description' => t('Select taxonomy that holds the list of other factors'),
    '#suffix' => "</div>",
  );
  $form['triage_factors']['triage_order_cmds'] = array(
    '#type' => 'textarea',
    '#rows' => 10,
    '#description' => $logictext,
    '#default_value' => ta_variable_get('triage_order_cmds', '', $ta_nid),
    '#title' => t('Ordering logic for display groups'),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['triage_own_words'] = array(
    '#type' => 'fieldset',
    '#title' => t('Own Words Search'),
    '#collapsible' => TRUE,
    '#group' => 'triage_setup',
  );
  $form['triage_own_words']['triage_use_own_word'] = array(
    '#type' => 'checkbox',
    '#default_value' => ta_variable_get('triage_use_own_word', FALSE, $ta_nid),
    '#title' => t('Include Houston AI In Your Own Words search box'),
    '#description' => t('If checked, adds a search box to the top category page where users can type in problem in their own words'),
    '#prefix' => "<div class='two-panel'>",
  );
  $form['triage_own_words']['triage_own_words_title'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_own_words_title', 'Describe your problem in your own words...', $ta_nid),
    '#size' => 30,
    '#title' => t('Title for In Your Own Words search box'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration')
  );
  return $form;
}

function triage_setup_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $ta_nid = $form_state['values']['triage_page_nid'];
  foreach ($values as $key => $val) {
    if (strpos($key, 'triage_') !== FALSE) {
      ta_variable_set($key, $val, $ta_nid);
    }
  }
  $statvid = ta_variable_get('triage_status_voc', '', $ta_nid);
  if ($statvid > 0) {
    $statvoc = taxonomy_vocabulary_load($statvid)->machine_name;
    $recs = db_query("select * from field_config where deleted = 0");
    foreach ($recs as $rec) {
      $ray = unserialize($rec->data);
      if (isset($ray['settings']['allowed_values'])
        && isset($ray['settings']['allowed_values']['0'])
        && isset($ray['settings']['allowed_values']['0']['vocabulary'])
      ) {
        $voc = $ray['settings']['allowed_values'][0]['vocabulary'];
        if ($voc == $statvoc) {
          ta_variable_set('triage_status_table', $rec->field_name, $ta_nid);
        }
      }
    }
  }
  $node = node_load($ta_nid);
  triage_node_update($node);
  drupal_set_message('The Triage Setup Information has been saved');
}

function triage_config_form($form, &$form_state) {
  global $base_url;
  $ta_nid = arg(1);
  drupal_add_js($base_url . ('/misc/drupal.js'), 'file');
  drupal_add_js($base_url . ('/misc/collapse.js'), 'file');
  drupal_add_js($base_url . ('/misc/jquery.cookie.js'), 'file');
  drupal_add_js($base_url . ('/misc/vertical-tabs.js'), 'file');
//    $vocs = taxonomy_get_vocabularies();
//    $voc_options = array();
//    $voc_options[0] = 'None';
//    foreach($vocs as $voc){
//      $voc_options[$voc->vid] = $voc->name;
//    }
  $voc_options = db_query("SELECT vid, name FROM taxonomy_vocabulary WHERE 1")->fetchAllKeyed();
  $triage_nav_type = ta_variable_get('triage_nav_type', 'bottom', $ta_nid);
  $resetcss = ta_variable_get('triage_reset_css', array(
    'background-color' => '#5670ac',
    'background-image' => 'none',
    'background-position' => '',
    'background-repeat' => '',
    'border-radius' => '5px',
    'box-shadow' => '2px 2px #777',
    'color' => '#fff',
    'float' => 'none',
    'font-size' => 'inherit',
    'height' => '25px',
    'margin' => '0 10px 0 0',
    'padding' => '6px 0 0 6px',
    'text-indent' => '7px',
    'width' => '100px',
  ), $ta_nid);
  $submitcss = ta_variable_get('triage_submit_css', array(
    'background-color' => '#5670ac',
    'background-image' => 'none',
    'background-position' => '',
    'background-repeat' => '',
    'border-radius' => '5px',
    'box-shadow' => '2px 2px #777777',
    'color' => '#FFFFFF',
    'float' => 'none',
    'font-size' => 'inherit',
    'height' => '25px',
    'margin' => '0 10px 0 0',
    'padding' => '6px 0 0 6px',
    'text-indent' => '-15px',
    'width' => '100px'
  ), $ta_nid);
  $form['triage'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['triage_laytout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Layout'),
    '#collapsible' => TRUE,
    '#group' => 'triage',
  );
  // Text field for the e-mail subject.
  $form['triage_laytout']['triage_page_nid'] = array(
    '#type' => 'hidden',
    '#size' => 15,
    '#default_value' => $ta_nid,
  );
  $form['triage_laytout']['triage_nav_type'] = array(
    '#type' => 'select',
    '#options' => array(
      'split' => "Navigation buttons split between top and bottom of display",
      'bottom' => "Navigation buttons in a bar at the bottom",
    ),
    '#default_value' => $triage_nav_type,
    '#title' => t('Navigation style'),
  );
  $form['triage_laytout']['triage_nav_bar_color'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_nav_bar_color', 'inherit', $ta_nid),
    '#title' => t('Color for Triage Navigation Bar'),
  );
  $form['triage_misc_text'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Text and Label Settings'),
    '#attributes' => array('class' => array('triage-inline')),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['triage_misc_text']['triage_menu_text'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#default_value' => ta_variable_get('triage_menu_text', 'Last Help', $ta_nid),
    '#title' => t('Menu text when referencing last triage endpoint'),
    '#description' => t('Menu text when referencing last triage endpoint'),
  );
  $form['triage_misc_text']['triage_page_title'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#default_value' => ta_variable_get('triage_page_title', 'Find Legal Help', $ta_nid),
    '#title' => t('Page Title'),
    '#description' => t('Title that you would like to appear when this set of questions if called.'),
  );
  $form['triage_misc_text']['triage_top_text'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#default_value' => ta_variable_get('triage_top_text', 'Please choose the issue you need help with.', $ta_nid),
    '#title' => t('Top Text'),
    '#description' => t('Text that will appear above the top categories on the page.'),
  );
  $form['triage_misc_text']['triage_sub_text'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#default_value' => ta_variable_get('triage_sub_text', 'Select the statement that best describes your legal problem.', $ta_nid),
    '#title' => t('Bottom Text'),
    '#description' => t('Text that will appear above the sub-questions - e.g. Select which item most accurately describes your legal problem.'),
  );
  $form['triage_misc_text']['triage_location_text1'] = array(
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => ta_variable_get('triage_location_text1', '', $ta_nid),
    '#title' => t('Text for Service Area Location Question 1'),
    '#description' => t('Text for option 1 of the In Service Area form'),
  );
  $form['triage_misc_text']['triage_location_text2'] = array(
    '#type' => 'textfield',
    '#size' => 35,
    '#default_value' => ta_variable_get('triage_location_text2', '', $ta_nid),
    '#title' => t('Text for Service Area Location Question 2'),
    '#description' => t('Text for option 2 of the In Service Area form'),
  );
  $form['triage_button_text'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Button Text'),
    '#attributes' => array('class' => array('triage-inline')),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['triage_button_text']['triage_submit_text'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_submit_text', 'Submit', $ta_nid),
    '#title' => t('Text for Submit button'),
    '#description' => t('Text for submit button, on finishing navigation of questionnaire'),
  );
  $form['triage_button_text']['triage_reset_text'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_reset_text', 'Back', $ta_nid),
    '#title' => t('Text for Back button'),
  );
  $form['triage_button_text']['triage_next_text'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_next_text', 'Continue', $ta_nid),
    '#title' => t('Text for Continue button'),
  );
  $form['triage_button_text']['triage_restart_text'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_restart_text', 'Start Again', $ta_nid),
    '#title' => t('Text for Start Again button'),
  );
  $form['triage_button_text']['triage_restart_nav_bar'] = array(
    '#type' => 'checkbox',
    '#description' => "If checked, re-Start button will be on nav bar between back and submit buttons",
    '#default_value' => ta_variable_get('triage_restart_nav_bar', FALSE, $ta_nid),
    '#title' => t('Include Start Again Button on Nav Bar'),
  );
  $form['triage_css_option'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Custom CSS options'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['triage_css_option']['triage_email_logo'] = array(
    '#type' => 'textfield',
    '#name' => 'triage_email_logo',
    '#size' => 50,
    '#default_value' => ta_variable_get('triage_email_logo', '', $ta_nid),
    '#title' => t('Path and file name of triage email logo'),
    '#description' => t('file name and path of triage email logo e.g. <em>/images/email_logo.jpg</em>'),
  );
  $form['triage_css_option']['triage_use_css_builder'] = array(
    '#type' => 'checkbox',
    '#name' => 'triage_use_css_builder',
    '#description' => "If checked, a css for forward and back buttons will be built from the values below",
    '#default_value' => ta_variable_get('triage_use_css_builder', FALSE, $ta_nid),
    '#title' => t('Use Button CSS Builder'),
  );
  $form['triage_css_option']['resetcss'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Back Button CSS Settings'),
    '#attributes' => array('class' => array('triage-inline')),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#states' => array(
      'visible' => array(
        ':input[name="triage_use_css_builder"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['triage_css_option']['submitcss'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Continue Button CSS Settings'),
    '#attributes' => array('class' => array('triage-inline')),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#states' => array(
      'visible' => array(
        ':input[name="triage_use_css_builder"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Page Settings'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['triage_css_option']['resetcss']['triage_reset_left_icon'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_reset_left_icon', '', $ta_nid),
    '#title' => t('Font Awesome Icon Name for before the Back button'),
  );
  $form['triage_css_option']['resetcss']['triage_reset_right_icon'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_reset_right_icon', '', $ta_nid),
    '#title' => t('Font Awesome Icon Name for after the Back button'),
  );
  foreach ($resetcss as $key => $css) {
    $form['triage_css_option']['resetcss']['triage_reset_css-' . $key] = array(
      '#type' => 'textfield',
      '#size' => 15,
      '#default_value' => $css,
      '#title' => t($key),
    );
  }
  $form['triage_css_option']['submitcss']['triage_submit_left_icon'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_submit_left_icon', '', $ta_nid),
    '#title' => t('Font Awesome Icon for before the Continue button'),
  );
  $form['triage_css_option']['submitcss']['triage_submit_right_icon'] = array(
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => ta_variable_get('triage_submit_right_icon', '', $ta_nid),
    '#title' => t('Font Awesome Icon for after the Continue button'),
  );
  foreach ($submitcss as $key => $css) {
    $form['triage_css_option']['submitcss']['triage_submit_css-' . $key] = array(
      '#type' => 'textfield',
      '#size' => 15,
      '#default_value' => $css,
      '#title' => t($key),
    );
  }
  $form['settings']['triage_hide_page_sections'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_hide_page_sections', 'sidebar_first,sidebar_second,postscript_first,postscript_second,postscript_third', $ta_nid),
    '#title' => t('Page sections that should be hidden'),
  );
  $form['progress'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Progress Bar'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['progress']['triage_use_progress_bar'] = array(
    '#type' => 'checkbox',
    '#name' => 'triage_use_progress_bar',
    '#default_value' => ta_variable_get('triage_use_progress_bar', FALSE, $ta_nid),
    '#title' => t('Display Progress Bar'),
  );
  $form['progress']['triage_progress_type'] = array(
    '#type' => 'select',
    '#options' => array(
      'bar' => "Progress Bar",
      'chart' => "Pie Chart",
    ),
    '#default_value' => ta_variable_get('triage_progress_type', 'bar', $ta_nid),
    '#title' => t('Progress Bar Type'),
  );
  $form['progress']['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Progress Settings'),
    '#states' => array(
      'visible' => array(
        ':input[name="triage_use_progress_bar"]' => array('checked' => TRUE),
      ),
    ),
    '#collapsible' => TRUE, // Added
  );
  $form['progress']['settings']['triage_progress_bar_title'] = array(
    '#type' => 'textfield',
    '#description' => "Title displayed atop progress bar",
    '#default_value' => ta_variable_get('triage_progress_bar_title', "Triage Progress", $ta_nid),
    '#title' => t('Title atop progress bar'),
  );
  $form['progress']['settings']['triage_progress_home_div'] = array(
    '#type' => 'textfield',
    '#description' => "Id of existing DIV, such as the menu bar, which will be replaced by the progress bar.  
                            Leave blank to use default area just below page title",
    '#default_value' => ta_variable_get('triage_progress_home_div', "", $ta_nid),
    '#title' => t('Existing DIV to be replaced by progress bar'),
  );
  $form['progress']['settings']['triage_progress_extra_step'] = array(
    '#type' => 'checkbox',
    '#default_value' => ta_variable_get('triage_progress_extra_step', FALSE, $ta_nid),
    '#title' => t('Add a Results step as a final step'),
  );
  $form['progress']['settings']['triage_progress_extra_step_text'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_extra_step_text', "Results", $ta_nid),
    '#title' => t('Progress Bar Extra Step Text'),
  );
  $form['progress']['settings']['triage_progress_border'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_border', "#aaa", $ta_nid),
    '#title' => t('Progress Bar Border Color'),
  );
  $form['progress']['settings']['triage_progress_background'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_background', "#fff", $ta_nid),
    '#title' => t('Progress item background color, unselected'),
  );
  $form['progress']['settings']['triage_progress_selected_background'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_selected_background', "#133785", $ta_nid),
    '#title' => t('Selected Progress Item background color'),
  );
  $form['progress']['settings']['triage_progress_text'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_text', "#000", $ta_nid),
    '#title' => t('Progress item text color, unselected'),
  );
  $form['progress']['settings']['triage_progress_selected_text'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_selected_text', "#fff", $ta_nid),
    '#title' => t('Selected Progress Item Text Color'),
  );
  $form['progress']['settings']['triage_progress_icon_color'] = array(
    '#type' => 'textfield',
    '#default_value' => ta_variable_get('triage_progress_icon_color', "#aaa", $ta_nid),
    '#title' => t('Progress Icon Color'),
  );
  $form['wrapping'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display Wrapper Templates'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    '#group' => 'triage',
  );
  $form['wrapping']['triage_use_wrap_templates'] = array(
    '#type' => 'checkbox',
    '#name' => 'triage_use_wrap_templates',
    '#default_value' => ta_variable_get('triage_use_wrap_templates', FALSE, $ta_nid),
    '#title' => t('Allow Display Wrapper Templates'),
  );
  $form['wrapping']['triage_use_wrap_assoc'] = array(
    '#type' => 'checkbox',
    '#name' => 'triage_use_wrap_assoc',
    '#default_value' => ta_variable_get('triage_use_wrap_assoc', FALSE, $ta_nid),
    '#title' => t('Display Wrappers can be linked to taxonomy'),
    '#description' => t('Turn on feature that allows selection of an associated taxonomy for display wrappers'),
  );
  $form['wrapping']['triage_wrap_assoc'] = array(
    '#type' => 'select',
    '#options' => $voc_options,
    '#default_value' => ta_variable_get('triage_wrap_assoc', '', $ta_nid),
    '#title' => t('Associated Taxonomy'),
    '#description' => t('Select taxonomy to associate display wrapper with - could be used in ordering'),
    '#states' => array(
      'visible' => array(
        ':input[name="triage_use_wrap_assoc"]' => array('checked' => TRUE),
      ),
    ),
  );

//    return system_settings_form($form);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration')
  );
  return $form;
}

function triage_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $ta_nid = $form_state['values']['triage_page_nid'];
  $triage_reset_css = array();
  $triage_submit_css = array();
  foreach ($values as $key => $val) {
    if (strpos($key, 'triage_reset_css-') !== FALSE) {
      $realkey = str_replace('triage_reset_css-', "", $key);
      $triage_reset_css[$realkey] = $val;
    }
    else {
      if (strpos($key, 'triage_submit_css-') !== FALSE) {
        $realkey = str_replace('triage_submit_css-', "", $key);
        $triage_submit_css[$realkey] = $val;
      }
      else {
        if (strpos($key, 'triage_') !== FALSE) {
          ta_variable_set($key, $val, $ta_nid);
        }
      }
    }
  }
  ta_variable_set('triage_reset_css', $triage_reset_css, $ta_nid);
  ta_variable_set('triage_submit_css', $triage_submit_css, $ta_nid);
  drupal_set_message('The Triage Configuration Information has been saved');
}

function triage_config_alt($form, &$form_state) {
  global $base_url;
  $ta_nid = arg(1);
  $form['triage_page_nid'] = array(
    '#type' => 'hidden',
    '#size' => 15,
    '#default_value' => $ta_nid,
  );
  $form['triage_use_alt_display'] = array(
    '#type' => 'checkbox',
    '#name' => 'triage_use_alt_display',
    '#description' => "If checked, page will be rebuilt from the commands below",
    '#default_value' => ta_variable_get('triage_use_alt_display', FALSE, $ta_nid),
    '#title' => t('Use Alternative Page Display'),
  );
  $form['triage_content_block'] = array(
    '#type' => 'textfield',
    '#name' => 'triage_content_block',
    '#description' => "DIV id that holds triage content which will be moved to the triage wrapper div for more stylized display",
    '#default_value' => ta_variable_get('triage_content_block', '#container', $ta_nid),
    '#title' => t('DIV id that holds triage content'),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Triage Alt Display Advanced Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['triage_use_alt_commands'] = array(
    '#type' => 'textarea',
    '#rows' => 10,
    '#description' => "Alternative page display commands",
    '#default_value' => ta_variable_get('triage_use_alt_commands', '', $ta_nid),
    '#title' => t('Alternative Page Display Commands'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration')
  );
  return $form;
}

function triage_config_alt_submit($form, &$form_state) {
  $values = $form_state['values'];
  $ta_nid = $form_state['values']['triage_page_nid'];
  foreach ($values as $key => $val) {
    if (strpos($key, 'triage_reset_css-') !== FALSE) {
      $realkey = str_replace('triage_reset_css-', "", $key);
      $triage_reset_css[$realkey] = $val;
    }
    else {
      if (strpos($key, 'triage_submit_css-') !== FALSE) {
        $realkey = str_replace('triage_submit_css-', "", $key);
        $triage_submit_css[$realkey] = $val;
      }
      else {
        if (strpos($key, 'triage_') !== FALSE) {
          ta_variable_set($key, $val, $ta_nid);
        }
      }
    }
  }
  drupal_set_message('The Master Triage Page Styling has been saved');
}

function triage_add_fields($vid) {
  $voc = taxonomy_vocabulary_load($vid);
  $bundle = $voc->machine_name;
  if (!field_info_field('field_icon')) {
    $field_name = 'field_icon';
    $field = array('field_name' => $field_name, 'type' => 'image',);
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', 'field_icon', $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'inline',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_icon',
      'label' => 'Icon',
      'required' => FALSE,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'entity_translation_sync' => FALSE,
        'file_directory' => '',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => '2',
      ),
    );
    field_create_instance($instance);
  }
  $fld = 'field_triage_extra';
  if (!field_info_field($fld)) {
    $field_name = $fld;
    $field = array('field_name' => $field_name, 'type' => 'text',);
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Extra field for case type or other categorization tags',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_triage_extra',
      'label' => 'Additional Category',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '3',
      ),
    );
    field_create_instance($instance);
  }
  $fld = 'field_triage_ref_' . $bundle;
  if (!field_info_field($fld)) {
    $field_name = $fld;
    $field = array(
      'field_name' => $field_name,
      'type' => 'taxonomy_term_reference',
    );
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Allows the use of a common set of subquestions.  Pointing this question to another taxonomy term will show the selected term\'s sub-items as if they were part of this question.  ',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => $fld,
      'label' => 'Point to questions in another taxonomy',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'term_reference_tree',
        'settings' => array(
          'cascading_selection' => 0,
          'filter_view' => '',
          'leaves_only' => 0,
          'max_depth' => '',
          'parent_term_id' => '',
          'select_parents' => 0,
          'start_minimized' => 1,
          'token_display' => '',
          'track_list' => 0,
        ),
        'type' => 'term_reference_tree',
        'weight' => '3',
      ),
    );
    field_create_instance($instance);
  }
  $fld = 'field_triage_status_' . $bundle;
  if (!field_info_field($fld)) {
    $field_name = $fld;
    $field = array(
      'field_name' => $field_name,
      'type' => 'taxonomy_term_reference',
      'cardinality' => -1,
    );
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => $fld,
      'label' => 'Show for these Status',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => '4',
      ),
    );
    field_create_instance($instance);
  }
  $fld = 'field_triage_keep_private';
  if (!field_info_field($fld)) {
    $field_name = $fld;
    $field = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_triage_keep_private',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => 0,
      'type' => 'list_boolean',
    );
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => 0,
      'description' => 'Check to unpublish term',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_triage_keep_private',
      'label' => 'Do not show in Triage',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 3,
      ),
    );
    field_create_instance($instance);
  }
}

function triage_add_fields2($ta_nid = 0) {
  $triage_voc = taxonomy_vocabulary_load(ta_variable_get('triage_vocabulary', '', $ta_nid))->machine_name;
  $vid = ta_variable_get('triage_libtable', "", $ta_nid);
  if ($vid == '' || $ta_nid == 0) {
    return;
  }
  $voc = taxonomy_vocabulary_load($vid);
  $bundle = $voc->machine_name;
  $fld = 'field_triage_use_popup';
  if (!field_info_field($fld)) {
    $field_name = $fld;
    $field = array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_triage_use_popup',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
        'allowed_values_php' => '',
      ),
      'translatable' => 0,
      'type' => 'list_boolean',
    );
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'default_value_function' => '',
      'default_value_php' => '',
      'deleted' => 0,
      'description' => 'Check box to have triage popup screen appear on any pages marked with this term or child terms',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_triage_use_popup',
      'label' => 'Allow Triage Popup',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => 3,
      ),
    );
    field_create_instance($instance);
  }

  $fld = 'field_triage_categories';
  if (!field_info_field($fld)) {
    $field = array(
      'field_name' => $field_name,
      'type' => 'taxonomy_term_reference',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => $triage_voc,
            'parent' => '0',
          ),
        ),
      ),

    );
    field_create_field($field);
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'bundle' => $bundle,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Maps term item to triage level for search and popup links',
      'entity_type' => 'taxonomy_term',
      'field_name' => $fld,
      'label' => 'Map to Triage',
      'required' => 0,
      'widget' => array(
        'active' => 1,
        'module' => 'term_reference_tree',
        'settings' => array(
          'cascading_selection' => 0,
          'filter_view' => '',
          'leaves_only' => 0,
          'max_depth' => '',
          'parent_term_id' => '',
          'select_parents' => 0,
          'start_minimized' => 1,
          'token_display' => '',
          'track_list' => 0,
          'vocabulary' => $triage_voc,
        ),
        'type' => 'term_reference_tree',
        'weight' => '3',
      ),
    );
    field_create_instance($instance);
  }
  $legalvoc = taxonomy_vocabulary_load(ta_variable_get('triage_legal_categories', '', $ta_nid))->machine_name;
  if ($legalvoc && $bundle) {
    $fld = "field_legalcat_reference";
    if (!field_info_field($fld)) {
      $field_name = $fld;
      $field = array(
        'field_name' => $field_name,
        'type' => 'taxonomy_term_reference',
        'settings' => array(
          'allowed_values' => array(
            0 => array(
              'vocabulary' => $legalvoc,
              'parent' => '0',
            ),
          ),
        ),

      );
      field_create_field($field);
    }
    if (!field_info_instance('taxonomy_term', $fld, $triage_voc)) {
      $instance = array(
        'bundle' => $triage_voc,
        'default_value' => NULL,
        'deleted' => '0',
        'description' => 'Maps term item to legal cateogry system',
        'entity_type' => 'taxonomy_term',
        'field_name' => $fld,
        'label' => 'Map to Legal Categories',
        'required' => 0,
        'widget' => array(
          'active' => 1,
          'module' => 'term_reference_tree',
          'settings' => array(
            'cascading_selection' => 0,
            'filter_view' => '',
            'leaves_only' => 0,
            'max_depth' => '',
            'parent_term_id' => '',
            'select_parents' => 0,
            'start_minimized' => 1,
            'token_display' => '',
            'track_list' => 0,
            'vocabulary' => $legalvoc,
          ),
          'type' => 'term_reference_tree',
          'weight' => '3',
        ),
      );
      field_create_instance($instance);
    }
  }

}

function triage_add_fields3($vid) {
  $voc = taxonomy_vocabulary_load($vid);
  $bundle = $voc->machine_name;
  $fld = "field_results_title";
  if (!field_info_field($fld)) {
    field_create_field(array(
      'field_name' => $fld,
      'label' => t('Triage Results Page Title'),
      'type' => 'text',
    ));
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'field_name' => $fld,
      'entity_type' => 'taxonomy_term',
      'label' => t('Triage Results Page Title'),
      'bundle' => $bundle,
      'widget' => array('type' => 'text_textfield'),
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'hidden',
        ),
      ),
    );
    field_create_instance($instance);
  }
  $fld = "field_triage_help";
  if (!field_info_field($fld)) {
    field_create_field(array(
      'field_name' => $fld,
      'type' => 'text_long',
      'label' => t('Triage Help'),
      'description' => t('Triage Help for popup help on specific questions'),
      'widget' => array('type' => 'text_textarea'),
      'settings' => array('text_processing' => 1),
      'format' => 'filter_html',
    ));
  }
  if (!field_info_instance('taxonomy_term', $fld, $bundle)) {
    $instance = array(
      'field_name' => $fld,
      'entity_type' => 'taxonomy_term',
      'label' => t('Triage Help'),
      'bundle' => $bundle,
      'widget' => array('type' => 'text_textarea'),
      'settings' => array('text_processing' => 1),
      'format' => 'filter_html',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'type' => 'hidden',
        ),
      )
    );
    field_create_instance($instance);
  }

}

function triage_get_state_options() {
  $options = array(
    ' ' => '-None-',
    'AL' => 'Alabama',
    'AK' => 'Alaska',
    'AZ' => 'Arizona',
    'AR' => 'Arkansas',
    'CA' => 'California',
    'CO' => 'Colorado',
    'CT' => 'Connecticut',
    'DE' => 'Delaware',
    'DC' => 'District Of Columbia',
    'FL' => 'Florida',
    'GA' => 'Georgia',
    'HI' => 'Hawaii',
    'ID' => 'Idaho',
    'IL' => 'Illinois',
    'IN' => 'Indiana',
    'IA' => 'Iowa',
    'KS' => 'Kansas',
    'KY' => 'Kentucky',
    'LA' => 'Louisiana',
    'ME' => 'Maine',
    'MD' => 'Maryland',
    'MA' => 'Massachusetts',
    'MI' => 'Michigan',
    'MN' => 'Minnesota',
    'MS' => 'Mississippi',
    'MO' => 'Missouri',
    'MT' => 'Montana',
    'NE' => 'Nebraska',
    'NV' => 'Nevada',
    'NH' => 'New Hampshire',
    'NJ' => 'New Jersey',
    'NM' => 'New Mexico',
    'NY' => 'New York',
    'NC' => 'North Carolina',
    'ND' => 'North Dakota',
    'OH' => 'Ohio',
    'OK' => 'Oklahoma',
    'OR' => 'Oregon',
    'PA' => 'Pennsylvania',
    'RI' => 'Rhode Island',
    'SC' => 'South Carolina',
    'SD' => 'South Dakota',
    'TN' => 'Tennessee',
    'TX' => 'Texas',
    'UT' => 'Utah',
    'VT' => 'Vermont',
    'VA' => 'Virginia',
    'WA' => 'Washington',
    'WV' => 'West Virginia',
    'WI' => 'Wisconsin',
    'WY' => 'Wyoming',
  );
  return $options;
}

function triage_endpoint($vid = NULL) {
  $cnt = 0;
  $hasacts = 0;
  if (is_null($vid)) {
    $vid = $_SESSION['triage']['triage_actions_admin_voc'];
  }
  if (is_null($vid) || $vid == '') {
    return '';
  }
  else {
    $tids = db_query("select tid from taxonomy_term_data where vid=:vid", array(":vid" => $vid))->fetchCol();
    $cnt = 0;
    foreach ($tids as $tid) {
      $kids = -1;
      $kids = count(taxonomy_get_children($tid));
      if ($kids == 0) {
        $cnt++;
        $acts = count(db_query("select id from triage_actions where bundle='taxonomy' and entity_id = :id", array(':id' => $tid))->fetchCol());
        if ($acts > 0) {
          $hasacts++;
        }
      }
    }
  }
  $output[] = "Endpoints: " . $cnt;
  $output[] = "Endpoints with Actions: " . $hasacts;
  dpm($output);
}

function triage_has_filled(){

}
