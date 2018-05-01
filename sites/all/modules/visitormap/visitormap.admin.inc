<?php

function visitormap_admin_form($form, &$form_state) {
    
    $form = array();
    // Text field for the e-mail subject.
    $form['visitormap_block_title'] = array(
        '#type' => 'textfield',
        '#size' => 35,
        '#default_value' => variable_get('visitormap_block_title',""),
        '#title' => t('Visitormap Block Title'),
        '#description' => t('Visitormap Block Title - leave blank for default'),
    );
    $form['visitormap_center_point'] = array(
        '#type' => 'textfield',
        '#size' => 25,
        '#default_value' => variable_get('visitormap_center_point',"45.384828,-69.120483"),
        '#title' => t('Set map center point'),
        '#description' => t('Set map center point Lat,Long such as "45.384828,-69.120483"'),
    );
    $form['visitormap_zoom'] = array(
        '#type' => 'textfield',
        '#size' => 25,
        '#default_value' => variable_get('visitormap_zoom',2),
        '#title' => t('Map Zoom Level'),
        '#description' => t('Set map zoom level'),
    );
    $form['visitormap_refresh_interval'] = array(
        '#type' => 'textfield',
        '#size' => 15,
        '#default_value' => variable_get('visitormap_refresh_interval',10000),
        '#title' => t('Refresh Rate Interval'),
        '#description' => t('Set refresh interval in milliseconds'),
    );
    $form['visitormap_map_refresh_cycles'] = array(
        '#type' => 'textfield',
        '#size' => 15,
        '#default_value' => variable_get('visitormap_map_refresh_cycles',25),
        '#title' => t('Refresh Map after xx Cylces'),
        '#description' => t('Number of intervals (from above) that must complete before page refresh'),
    );
    return system_settings_form($form);
    
}
