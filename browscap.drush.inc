<?php

/**
 * @file
 * Browscap Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function browscap_drush_command() {
  $items['browscap-import'] = array(
    'description' => 'Imports/updates browscap data via HTTP.',
  );
  return $items;
}

/**
 * Imports/updates browscap data via HTTP.
 */
function drush_browscap_import() {
  drush_log(dt('Importing Browscap data...'), 'ok');
  switch (_browscap_import()) {
    case BROWSCAP_IMPORT_VERSION_ERROR:
      drush_set_error('BROWSCAP', dt('Could not check current available Browscap data version.'));
      break;

    case BROWSCAP_IMPORT_NO_NEW_VERSION:
      drush_log(dt('No new version of Browscap data to import.'), 'ok');
      break;

    case BROWSCAP_IMPORT_DATA_ERROR:
      drush_set_error('BROWSCAP', dt('Failed to retrieve or load Browscap data.'));
      break;

    case BROWSCAP_IMPORT_OK:
      drush_log(dt('Imported Browscap data successfully.'), 'ok');
      break;
  }
}
