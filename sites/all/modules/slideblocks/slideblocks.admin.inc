<?php

function slideblocks_admin_form($form, &$form_state) {
    
    $form = array();

    $form['slides'] = array(
        '#type' => 'fieldset',
        '#title' => t('Basic Settings'),
        '#weight' => -1,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    );
    $form['slides']['slideblocks_use_slideblock'] = array(
        '#type' => 'checkbox',
        '#name' => 'slideblocks_use_slideblock',
        '#default_value' => variable_get('slideblocks_use_slideblock',TRUE),
        '#title' => t('Add side pull out options to blocks'),
    );
    $form['slides']['slideblocks_location'] = array(
        '#type' => 'radios',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_location',"left"),
        '#title' => t('Location of sliding blocks'),
        '#options' => array(
                    "left" => t('Left'),
                    "right" => t('Right'),
         ),
    );
    $form['slideblocks'] = array(
        '#type' => 'fieldset',
        '#title' => t('DOM settings'),
        '#weight' => 0,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['slideblocks']['slideblocks_content_dom'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_content_dom',""),
        '#title' => t('DOM ID of content area'),
        '#description' => t('Main Content area which will have a margin applied in mobile view separate tabs and content'),
    );
    $form['slideblocks']['slideblocks_content_margin'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_content_margin',45),
        '#title' => t('Content margin offset'),
        '#description' => t('Content margin offset'),
    );
    $form['slideblocks']['slideblocks_sidebar_threshold'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_sidebar_threshold',800),
        '#title' => t('Sidebar Threshold'),
        '#description' => t('Width that triggers sidebar to go from 100% width to sidebar proportion'),
    );
    $form['slideblocks']['slideblocks_main_area'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_main_area',"body"),
        '#title' => t('DOM ID we want to attach tabs to'),
        '#description' => t('By default, SlideBlocks attaches to the body.  Change this setting to attach to a different DOM element, include the # if using an ID'),
    );
    $form['slideblocks']['slideblocks_top_margin'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('slideblocks_top_margin',40),
        '#title' => t('Top margin offset'),
        '#description' => t('Top margin offset'),
    );
    return system_settings_form($form);    
}

