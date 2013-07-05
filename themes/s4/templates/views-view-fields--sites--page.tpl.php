<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class="row site search-result">
	<div class="span9">
		<h3><?php print $fields['title']->content; ?></h3>
		<div class=" meta popover-wrapper">
			<a class="popover-link map-link right" data-lat="<?php print $fields['latitude']->raw; ?>" data-lon="<?php print $fields['longitude']->raw; ?>"><?php print strip_tags(str_replace('<br />', ', ', $fields['field_location']->content)); ?></a>
		</div>
		<?php print $fields['body']->content; ?>
	</div>
	<div class="span3 tags">
		<ul class="nav nav-stacked nav-details">
			<li class="odd">
				<?php print $fields['field_site_restrict']->content; ?>
			</li>
			<li class="even">
				<strong>Type:</strong> <?php print $fields['field_csu_org_type']->content; ?>
			</li>
			<li class="odd last">
				<strong>Issues:</strong> <?php print $fields['field_csu_facility']->content; ?>
			</li>
		</ul>
	</div>
</div>
