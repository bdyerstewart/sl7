<?php
/**
 * @file
 * online_classroom.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function online_classroom_user_default_permissions() {
  $permissions = array();

  // Exported permission: access classroom.
  $permissions['access classroom'] = array(
    'name' => 'access classroom',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'classroom_permissions',
  );

  return $permissions;
}
