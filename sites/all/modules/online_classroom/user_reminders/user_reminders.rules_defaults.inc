<?php
/**
 * @file
 * user_reminders.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_reminders_default_rules_configuration() {
  $items = array();
  $items['rules_remove_reminder'] = entity_import('rules_config', '{ "rules_remove_reminder" : {
      "LABEL" : "Remove Reminder",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "reminder" : "reminder" } }
          }
        }
      ],
      "DO" : [
        { "schedule_delete" : { "component" : "rules_send_reminder", "task" : "[node:nid]" } }
      ]
    }
  }');
  $items['rules_send_reminder'] = entity_import('rules_config', '{ "rules_send_reminder" : {
      "LABEL" : "Send Reminder",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "[node:title]",
            "message" : "This reminder was sent to you from [site:name] - [site:url]",
            "from" : "reminder@ctlawhelp.org"
          }
        }
      ]
    }
  }');
  $items['rules_set_reminder'] = entity_import('rules_config', '{ "rules_set_reminder" : {
      "LABEL" : "Set Reminder",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "reminder" : "reminder" } }
          }
        }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "rules_send_reminder",
            "date" : [ "node:field-reminder-date" ],
            "identifier" : "[node:nid]",
            "param_node" : [ "node" ]
          }
        }
      ]
    }
  }');
  return $items;
}
