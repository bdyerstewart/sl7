<?php
/**
 * @file
 * online_classroom.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function online_classroom_default_rules_configuration() {
  $items = array();
  $items['rules_activate_classroom'] = entity_import('rules_config', '{ "rules_activate_classroom" : {
      "LABEL" : "Activate Classroom",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "term" : { "label" : "Term", "type" : "taxonomy_term" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "term" ], "field" : "field_classroom_status" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "term:field-classroom-status" ], "value" : 1 } }
      ]
    }
  }');
  $items['rules_deactivate_classroom'] = entity_import('rules_config', '{ "rules_deactivate_classroom" : {
      "LABEL" : "Deactivate Classroom",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "term" : { "label" : "Term", "type" : "taxonomy_term" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "term" ], "field" : "field_classroom_status" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "term:field-classroom-status" ], "value" : 0 } }
      ]
    }
  }');
  return $items;
}
