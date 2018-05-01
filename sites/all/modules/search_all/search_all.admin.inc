<?php

function search_all_admin_form($form, &$form_state) {
    $names =  node_type_get_names();
    $vocobj = db_query('SELECT name FROM {taxonomy_vocabulary}')->fetchCol();
    $vocs = array();
    foreach($vocobj as $v){
        $vocs[$v] = $v;
    }
    $do_triage = db_table_exists('triage_log');
    if ($do_triage){
        $vTypes = db_query('select distinct vid from triage_log');
        $choices=array();
        foreach ($vTypes as $vt){
            $vc = taxonomy_vocabulary_load($vt->vid);
            $choices[$vc->machine_name] = $vc->name;
        }
    }
    $form = array();
    // Text field for the e-mail subject.
    $form['advocate'] = array(
        '#type' => 'fieldset',
        '#title' => t('Advocate Settings'),        
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
    );
    $form['advocate']['search_all_filter_advocate'] = array(
        '#type' => 'checkbox',
        '#default_value' => variable_get('search_all_filter_advocate', array()) ,
        '#title' => t('Include Advocate Search'),
    );
    $form['advocate']['search_all_advfilter_public'] = array(
        '#type' => 'checkbox',
        '#default_value' => variable_get('search_all_advfilter_public', array()) ,
        '#title' => t('Advocate Filter Available to Public'),
    );
    $form['synonym'] = array(
        '#type' => 'fieldset',
        '#title' => t('Synonym Settings'),        
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
    );
    $form['synonym']['search_all_synonym_vocabs'] = array(
        '#type' => 'checkboxes',
        '#options' => $vocs,
        '#default_value' => variable_get('search_all_synonym_vocabs', array()) ,
        '#title' => t('Vocabularies to include in Synonym Construction'),
    );
    if ($do_triage){
        $form['triage'] = array(
        '#type' => 'fieldset',
        '#title' => t('Guided Pathway (Triage) Settings'),
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
        );
        $form['triage']['search_all_summary_voc'] = array(
          '#type' => 'select',
          '#title' => 'Triage Vocabulary',
          '#options' => $choices,
          //'#title' => t('Do any of these statements apply to you?'),  
          '#default_value' => variable_get('search_all_summary_voc', 'me_triage'),
          '#attributes' => array(
              'class' => array('summary_voc'),
          ),
        );    
        $form['triage']['search_all_use_triage'] = array(
            '#type' => 'checkbox',
            '#default_value' => variable_get('search_all_use_triage', true) ,
            '#title' => t('Offer Guided Pathway (Triage) Button'),
        );
        $form['triage']['search_all_triage_text'] = array(
            '#type' => 'textfield',
            '#default_value' => variable_get('search_all_triage_text', 'Guided Pathway for ') ,
            '#title' => t('Triage Button Introductory Text'),
        );    
        $form['triage']['search_all_triage_icon'] = array(
            '#type' => 'textfield',
            '#default_value' => variable_get('search_all_triage_icon', "<i class='fa fa-compass'></i>") ,
            '#title' => t('Triage Button Icon'),
        );    
    }
    $form['map'] = array(
    '#type' => 'fieldset',
    '#title' => t('Table and Field Mapping'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    );
    $form['map']['search_all_attachedfile_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_attachedfile_table', array()) ,
        '#title' => t('Attached File Table'),
    );    
    $form['map']['search_all_attachedfile_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_attachedfile_field', array()) ,
        '#title' => t('Attached File Field'),
    );    
    $form['map']['search_all_searchapi_attachment_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_searchapi_attachment_table', array()) ,
        '#title' => t('Search API Attachment Table'),
    );    
    $form['map']['search_all_nsmi_tax_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_nsmi_tax_table', array()) ,
        '#title' => t('NSMI Taxonomy Table'),
    );    
    $form['map']['search_all_nsmi_tax_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_nsmi_tax_field', array()) ,
        '#title' => t('NSMI Taxonomy Field'),
    );    
    $form['map']['search_all_freetags_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_freetags_table', array()) ,
        '#title' => t('Freetags Table'),
    );    
    $form['map']['search_all_freetags_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_freetags_field', array()) ,
        '#title' => t('Freetags Field'),
    );    
    $form['map']['search_all_promonsmi_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_promonsmi_table', array()) ,
        '#title' => t('Promoted NSMI Table'),
    );    
    $form['map']['search_all_promonsmi_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_promonsmi_field', array()) ,
        '#title' => t('Promoted NSMI Field'),
    );       
    $form['map']['search_all_promotags_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_promotags_table', array()) ,
        '#title' => t('Promoted Tags Table'),
    );    
    $form['map']['search_all_promotags_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_promotags_field', array()) ,
        '#title' => t('Promoted Tags Field'),
    );       
    $form['map']['search_all_synonyms_table'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_synonyms_table', array()) ,
        '#title' => t('Synonyms Table'),
    );    
    $form['map']['search_all_synonyms_field'] = array(
        '#type' => 'textfield',
        '#default_value' => variable_get('search_all_synonyms_field', array()) ,
        '#title' => t('Synonyms Field'),
    );       
    $form['promo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Promotion Content Types'),
    '#collapsible' => TRUE, // Added
    '#collapsed' => TRUE,  // Added
    );
    $form['promo']['search_all_types'] = array(
        '#type' => 'checkboxes',
        '#options' => array_map('check_plain', $names),
        '#default_value' => variable_get('search_all_types', array()) ,
        '#title' => t('Add Promote to Top fields to these content types'),
    );
    $form['search'] = array(
        '#type' => 'fieldset',
        '#name' => 'search',
        '#title' => t('Search Content Types'),
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
    );
    $form['search']['search_all_libtypes'] = array(
        '#type' => 'checkboxes',
        '#options' => array_map('check_plain', $names),
        '#default_value' => variable_get('search_all_libtypes', array()) ,
        '#title' => t('Content Types to include in Search'),
    );
    $form['advsearch'] = array(
        '#type' => 'fieldset',
        '#title' => t('Advocate Search Content Types'),
        '#collapsible' => TRUE, // Added
        '#collapsed' => FALSE,  // Added
        '#states' => array(
                    'visible' => array(
                    ':input[name="search_all_filter_advocate"]' => array('checked' => TRUE),
                    ),
        )
    );
    $form['advsearch']['search_all_advlibtypes'] = array(
        '#type' => 'checkboxes',
        '#options' => array_map('check_plain', $names),
        '#default_value' => variable_get('search_all_advlibtypes', array()) ,
        '#title' => t('Advocate Content Types to include in Search'),
    );
    $form['search_exclude'] = array(
        '#type' => 'fieldset',
        '#title' => t('Exclude common add on words from search key'),
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
    );
    $form['search_exclude']['search_all_extraneous_search_words'] = array(
        '#type' => 'textarea',
        '#default_value' => variable_get('search_all_extraneous_search_words', 'can,do,i,how,you') ,
        '#title' => t('Exclude common add on words from search key'),
        '#description' => t('Searches posed as questions often include extraneous phrases, such as How do I?'
                . ' List words to remove from search key, spearated by commas, e.g. <em>can,do,I,how</em>'),
    );    
    $form['search_phrases'] = array(
        '#type' => 'fieldset',
        '#title' => t('Complete Phrases'),
        '#collapsible' => TRUE, // Added
        '#collapsed' => TRUE,  // Added
    );
    $form['search_phrases']['search_all_phrases'] = array(
        '#type' => 'textarea',
        '#default_value' => variable_get('search_all_phrases', 'power of attorney') ,
        '#title' => t('Complete Phrases'),
        '#description' => t('Complete phrases that need should remain unparsed for best results'),
    );    
    return system_settings_form($form); 
}
function search_all_types(&$array){
    $array = array_values($array);
    $x=0;
    $cnt = count($array);
    while($x < $cnt){
        if (!$array[$x]){
            unset($array[$x]);
        }
        $x++;
    } 
}
function search_all_simplify($text){
  // Decode entities to UTF-8
  $text = decode_entities($text);
  // Lowercase
  $text = drupal_strtolower($text);

  // To improve searching for numerical data such as dates, IP addresses
  // or version numbers, we consider a group of numerical characters
  // separated only by punctuation characters to be one piece.
  // This also means that searching for e.g. '20/03/1984' also returns
  // results with '20-03-1984' in them.
  // Readable regexp: ([number]+)[punctuation]+(?=[number])

  $text = str_replace("'", 'xxzzxx', $text);
  //watchdog('bds1',$text);
  $text = preg_replace('/([' . PREG_CLASS_NUMBERS . ']+)[' . PREG_CLASS_PUNCTUATION . ']+(?=[' . PREG_CLASS_NUMBERS . '])/u', '\1', $text);
  $text = str_replace('xxzzxx',"'",$text);
  //watchdog('bds2',$text);
  // Multiple dot and dash groups are word boundaries and replaced with space.
  // No need to use the unicode modifer here because 0-127 ASCII characters
  // can't match higher UTF-8 characters as the leftmost bit of those are 1.
  $text = preg_replace('/[.-]{2,}/', ' ', $text);
  // The dot, underscore and dash are simply removed. This allows meaningful
  // search behavior with acronyms and URLs. See unicode note directly above.
  $text = preg_replace('/[._-]+/', '', $text);
  // With the exception of the rules above, we consider all punctuation,
  // marks, spacers, etc, to be a word boundary.
  $text = str_replace("'", 'xxzzxx', $text);
  $text = preg_replace('/[' . PREG_CLASS_UNICODE_WORD_BOUNDARY . ']+/u', ' ', $text);
  $text = str_replace('xxzzxx',"'",$text);
  // Truncate everything to 50 characters.
  $words = explode(' ', $text);
  array_walk($words, '_search_index_truncate');
  $text = implode(' ', $words);

  return $text;
}
function search_all_extraneous($text){
    $extra = explode(",",variable_get('search_all_extraneous_search_words','can,i,do'));
    $search = explode(" ", $text);
    $ret = '';
    foreach($search as $word){
        if (!in_array($word,$extra)){
            $ret .= $word . " ";
        }
    }
    return trim($ret);
}