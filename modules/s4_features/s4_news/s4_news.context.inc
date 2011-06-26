<?php
/**
 * @file
 * s4_news.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function s4_news_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news';
  $context->description = 'The user is on a news article page';
  $context->tag = 'news';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cck_blocks-field_files' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_files',
          'region' => 'content_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The user is on a news article page');
  t('news');
  $export['news'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-frontpage';
  $context->description = 'News items on the homepage';
  $context->tag = 'news';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'welcome' => 'welcome',
        'frontpage' => 'frontpage',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'content_top_right',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('News items on the homepage');
  t('news');
  $export['news-frontpage'] = $context;

  return $export;
}
