<?php
/**
 * @file
 * Displays user agent information.
 */

/**
 * Page callback to show details about known useragents.
 *
 * @param $useragent
 *   The useragent object, loaded from the database.
 * @return string an HTMl blob representing the data about this useragent.
 */
function browscap_useragent_properties($useragent = NULL) {
  drupal_set_title(check_plain($useragent['browser'] .' '. $useragent['version']));
  $headers = array(t('Property'), t('Value'));
  foreach ($useragent as $key => $val) {
    $rows[] = array(check_plain($key), check_plain($val));
  }
  $output = theme('table', $headers, $rows);
  return $output;
}
