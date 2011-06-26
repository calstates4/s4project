<?php

// Put the logo path into JavaScript for the live preview.
drupal_add_js(array('color' => array('logo' => theme_get_setting('logo', 's4'))), 'setting');

$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'top' => t('Header top'),
    'bottom' => t('Header bottom'),
    'nav-top' => t('Navigation top'),
    'nav-bottom' => t('Navigation bottom'),
    'branding-links' => t('Header links'),
  ),
  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('S4 Default'),
      'colors' => array(
      	'top' => '#6aa4c2',
        'bottom' => '#558095',
        'nav-top' => '#e26140',
        'nav-bottom' => '#ca433c',
        'branding-links' => '#fff',
      ),
    ),
    'sepia' => array(
      'title' => t('Sepia'),
      'colors' => array(
      	'top' => '#c8a628',
        'bottom' => '#7a682a',
        'nav-top' => '#e1c23e',
        'nav-bottom' => '#c9983a',
        'branding-links' => '#fff',
      ),
    ),
    'green' => array(
      'title' => t('Swamp'),
      'colors' => array(
      	'top' => '#6ac282',
        'bottom' => '#559566',
        'nav-top' => '#81a9df',
        'nav-bottom' => '#73a6cb',
        'branding-links' => '#fff',
      ),
    ),
  ),
  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'css/colors.css',
  ),

  // Files to copy.
  'copy' => array(
    'logo.png',
  ),

  // Gradient definitions.
  'gradients' => array(
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('top', 'bottom'),
      'lock' => true
    ),
    array(
      // (x, y, width, height).
      'dimension' => array(0, 0, 0, 0),
      // Direction of gradient ('vertical' or 'horizontal').
      'direction' => 'vertical',
      // Keys of colors to use for the gradient.
      'colors' => array('nav-top', 'nav-bottom'),
    ),
  ),

  // Color areas to fill (x, y, width, height).
  'fill' => array(),

  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  'slices' => array(),

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_css'  => 'color/preview.css',
  'preview_js'   => 'color/preview.js',
  'preview_html' => 'color/preview.html',

  // Base file for image generation.
  'base_image' => 'color/base.png',
);
