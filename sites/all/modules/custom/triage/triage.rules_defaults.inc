<?php

function triage_default_rules_configuration() {
  $items = array();
  $items['rules_text_triage_results'] = entity_import('rules_config', '{ "rules_text_triage_results" : {
    "LABEL" : "Text Triage Results",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "webform_rules", "php", "rules", "twilio" ],
    "ON" : { "webform_rules_submit" : [] },
    "IF" : [
      { "webform_has_id" : {
        "form_id" : [ "form_id" ],
          "selected_webform" : { "value" : { "webform-client-form-2252" : "webform-client-form-2252" } }
        }
      },
      { "php_eval" : { "code" : "if ($data[\u0027components\u0027][\u0027cell_phone_number\u0027][\u0027value\u0027][0] \u003E \u0022\u0022){\r\n   return true;\r\n}\r\nelse {\r\n   dsm(\u0027Cell phone number must be filled in to recieve text\u0027);\r\n   global $base_url;\r\n   $url = $base_url . \u0027\/triage_actions_process\/\u0027 . $_SESSION[\u0027triage\u0027][\u0027triage_final_tid\u0027];\r\n   drupal_goto($url);\r\n}\r\n" } }
    ],
    "DO" : [
      { "twilio_send_sms_to_number" : {
        "country" : "1",
          "number" : "\u003C?php echo $data[\u0027components\u0027][\u0027cell_phone_number\u0027][\u0027value\u0027][0] ?\u003E",
          "message" : "\u003C?php \r\nglobal $base_url;\r\n$url = $base_url . \u0027\/triage_actions_process\/\u0027 . $_SESSION[\u0027triage\u0027][\u0027triage_final_tid\u0027];\r\nif (isset( $_SESSION[\u0027triage_session\u0027]) ) {\r\n   $id = uniqid();\r\n   db_insert(\u0027triage_session\u0027) \r\n        -\u003Efields(array(\r\n             \u0027sid\u0027 =\u003E $id,\r\n             \u0027value\u0027 =\u003E $_SESSION[\u0027triage_session\u0027],\r\n   ))-\u003Eexecute();\r\n   $url .= \u0027?sid=\u0027 . $id;\r\n}\r\n$out = \u0022View your Legal Results at \u0022 . $url;\r\necho $out;\r\n?\u003E\r\n"
        }
      },
      { "redirect" : { "url" : "\u003C?php \r\nglobal $base_url;\r\n$url = $base_url . \u0027\/triage_actions_process\/\u0027 . $_SESSION[\u0027triage\u0027][\u0027triage_final_tid\u0027];\r\necho $url;\r\n?\u003E" } }
    ]
  }
  }');
  return $items;
}
