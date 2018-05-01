<?php

/**
 * @file
 * Wysiwyg API integration.
 */

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function pov_guides_pov_guides_wysiwyg_plugin() {
  $plugins['pov_guides_wysiwyg'] = array(
    'title' => t('Create Poverty Guidelines Display'),
    'vendor url' => '',
    'icon file' => 'money.gif',
    'icon title' => t('Federal Povery Guidelines'),
    'settings' => array(),
  );
  return $plugins;
}