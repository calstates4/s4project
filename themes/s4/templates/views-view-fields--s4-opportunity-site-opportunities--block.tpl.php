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
$type = s4_opportunity_type_load($row->s4_opportunity_type);

?>
<div class="row opportunity search-result">
	<div class="span9">
		<h3><?php print $fields['name']->content; ?></h3>
		<div class="description">	
			<?php print $fields['field_opportunity_description']->content; ?>
		</div>
	</div>
	<div class="span3 tags">
		<ul class="nav nav-stacked nav-details">
			<?php if($button = _s4_opportunity_place_button(s4_opportunity_load($row->s4_opportunity_id))): ?>
				<li class="odd">
					<?php print $button; ?>
				</li>
			<?php endif; ?>
			<li class="even">
				<div class="popover-wrapper">
					<a class="popover-link left"><?php print $fields['type']->content; ?></a>
					<div class="popover-content element-invisible">
		  			<div>
		  				<?php print check_markup($type->data['description']['value'], $type->data['description']['format']); ?>
		  			</div>
		  		</div>
				</div>
			</li>
			<li class="odd last"><strong>Ends: </strong><?php print $fields['field_active_date']->content; ?></li>
		</ul>
	</div>
</div>
