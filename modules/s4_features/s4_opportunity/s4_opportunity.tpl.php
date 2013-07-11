<?php

/**
 * @file
 * A basic template for s4_opportunity entities
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The name of the s4_opportunity
 * - $url: The standard URL for viewing a s4_opportunity entity
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - s4_opportunity-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>>
        <a href="<?php print $url; ?>"><?php print $title; ?></a>
    </h2>
  <?php endif; ?>
  <?php unset($content['field_opportunity_group']); ?>
  <div class="content">
    <ul class="nav nav-stacked nav-details pull-right span3">
      <li class="odd"><?php print render($content['field_site_restrict']); ?></li>
      <li class="even"><?php print render($content['field_opportunity_sites']); ?></li>
      <li class="odd last"><?php print render($content['field_active_date']); ?></li>
    </ul>
    <?php
      print render($content);
    ?>
  </div>
</div>
