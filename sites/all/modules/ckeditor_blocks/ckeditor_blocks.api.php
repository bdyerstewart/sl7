<?php
/**
 * Edit CKEditor Block list
 *
 * This hook is invoked from ckeditor_blocks_blocks_ajax() when retrieving
 * a list of blocks to be inserted. It allows you to restrict blocks globally.
 *
 * @param $blocks
 *   A list of blocks that can be inserted using the plugin.
 */

function hook_ckeditor_blocks_list_alter(&$blocks) {
  foreach ($blocks as $key => $value) {
    // Never allow Devel blocks to be added.
    if ($value['module'] == 'devel') {
      unset($blocks[$key]);
    }
  }
}
