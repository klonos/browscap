<?php
/**
 * @file
 * Generate configuration form.
 */

/**
 * Callback for settings form.
 * Turn monitoring on or off and refresh the reference data.
 */
function browscap_settings() {
  $form['browscap_data_status'] = array(
    '#markup' => '<p>' . t('Current browscap data version: %fileversion.', array('%fileversion' => $version ? $version : t('Never fetched'))) . '</p>',
  );
  $form['browscap_monitor'] = array(
    '#type' => 'checkbox',
    '#title' => t('Monitor browsers'),
    '#default_value' => variable_get('browscap_monitor', FALSE),
    '#description' => t('Monitor all user agents visiting the site. View the reports in the <a href="!reports">Browscap reports</a> area.', array('!reports' => url('admin/reports/browscap'))),
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['refresh'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh browscap data'),
  );
  return $form;
}

/**
 * Submit handler for settings page.
 */
function browscap_settings_submit($form, &$form_state) {
  switch ($form_state['clicked_button']['#id']) {
    case 'edit-save':
      variable_set('browscap_monitor', $form_state['values']['browscap_monitor']);
      break;
    case 'edit-refresh':
      _browscap_import(FALSE);
      break;
  }
}
