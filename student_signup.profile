<?php
if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_signup');

/**
 * Implements hook_install_tasks().
 */
function student_signup_install_tasks() {
	return array('student_signup_profiler_install_tasks' => array(
		'display_name' => st('Student signup setup'),
		'type' => 'batch',
		),
	);
}

/**
 * Install tasks, sets a batch API to occur after site configuration.
 */
function student_signup_profiler_install_tasks() {
	$batch = array(
	  'title' => t('Completing student signup setup.'),
	  'operations' => array(
        array('student_signup_setup_homepage', array()),
	  ),
	  'finished' => 'student_signup_profiler_finished',
	  'file' => drupal_get_path('profile', 'student_signup') .'/libraries/profiler/profiler_api.inc',
	);
	$config = profiler_v2_load_config('student_signup');
	$components = profiler_components();
  unset($components['terms']);
  foreach ($components as $name => $component) {
    if (!empty($config[$name]) && isset($component['callback'])) {
      if (function_exists($component['callback'])) {
        $batch['operations'][] = array('student_signup_profiler_install_step', array($component['callback'], $config[$name], $config));
      }
    }
  }
  $vocabs = taxonomy_get_vocabularies();
  foreach ($vocabs as $vid => $vocab) {
    $vocabs_by_machine_name[$vocab->machine_name] = $vid;
  }
  foreach ($config['terms'] as $term) {
    // Support the 'vocabulary_machine_name' key for referring to a term's vocabulary
    // by its machine name.
    $batch['operations'][] = array('student_signup_profiler_install_terms', array($term, $vocabs_by_machine_name, $vocabs));
  }
  $batch['operations'][] = array('student_signup_install_rebuild_permissions', array());
  $batch['operations'][] = array('student_signup_install_cache_clear', array());
  $batch['operations'][] = array('student_signup_install_rebuild_features', array());
  return $batch;
}

/**
 * Install back callback - rebuild node permissions.
 */
function student_signup_install_rebuild_permissions(&$context) {
  node_access_rebuild();
  $context['messages'] = t('Rebuilding node permissions');
  $context['results'][] = 'node_rebuild';
}

/**
 * Install back callback - now that permissions are setup, rebuild features.
 */
function student_signup_install_rebuild_features(&$context) {
  features_revert(array('s4_sites' => array('user_permission')));
  $context['messages'] = t('Rebuilding access permissions');
  $context['results'][] = 'features_rebuild';
}

/**
 * Clear cache so views is happy.
 */
function student_signup_install_cache_clear(&$context) {
  drupal_flush_all_caches();
  $context['messages'] = t('Clearing caches');
  $context['results'][] = 'cache_clear';
}

/**
 * Install batch callback that sets up role-based homepages.
 */
function student_signup_setup_homepage(&$context) {
  foreach(user_roles() as $rid => $name) {
    db_delete('front_page')
         ->condition('rid', $rid)
         ->execute();
    if($name == 'staff') {
      $result = db_insert('front_page')
      ->fields(array('rid' => $rid,
               'mode' => 'alias',
               'data' => 'home',
               'filter_format' => '',
               'weight' => 0))
      ->execute();
      //While we are here, add the role "staff" to user 1.
      $user = user_load(1);
      $user->roles[$rid] = $name;
      user_save($user);
    }
    else {
      db_insert('front_page')
      ->fields(array('rid' => $rid,
               'mode' => '',
               'data' => '',
               'filter_format' => '',
               'weight' => 0))
      ->execute();
    }
  }
  // Disable all DB blocks
  if (module_exists('block')) {
    db_query("UPDATE {block} SET status = 0, region = ''");
  }
  $context['messages'] = t('Setting up homepage');
  $context['results'][] = 'homepage';
}

/**
 * Install batch callback that completed regular profiler install steps
 */
function student_signup_profiler_install_step($callback, $data, $config, &$context) {
	if(empty($context['sandbox'])) {
    $context['sandbox']['identifiers'] = array();
  }
  $callback($data, $config, $context['sandbox']['identifiers']);
	$context['message'] = t('Completing installation callback @callback', array('@callback' => $callback));
	$context['results'][] = $callback;
}

/**
 * Install batch callback for setting up taxonomy terms.
 */
function student_signup_profiler_install_terms($term, $vocabs_by_machine_name, $vocabs, &$context) {
	$weight = 0;
  if (isset($term['vocabulary_machine_name'], $vocabs_by_machine_name[$term['vocabulary_machine_name']])) {
    $term['vid'] = $vocabs_by_machine_name[$term['vocabulary_machine_name']];
  }
  // Sanity checks before creating.
  if (!empty($term['name']) && !empty($term['vid']) && isset($vocabs[$term['vid']])) {
    $term['weight'] = !isset($term['weight']) ? $weight++ : $term['weight'];
    //Cast the term as an object, to allow it to be saved properly.
    taxonomy_term_save((object) $term);
    $context['message'] = t('Installing category @term', array('@term' => check_plain($term['name'])));
    $context['results'][] = $term['name'];
  }
}

function student_signup_profiler_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  if ($success) {
    $message = format_plural(count($results), 'One install process finished.', '@count install process finished.');
  }
  else {
    $message = t('Finished with an error.');
  }
  drupal_set_message($message);
  // Providing data for the redirected page is done through $_SESSION.
  foreach ($results as $result) {
    $items[] = t('Loaded node %title.', array('%title' => $result));
  }
  $_SESSION['my_batch_results'] = $items;
}