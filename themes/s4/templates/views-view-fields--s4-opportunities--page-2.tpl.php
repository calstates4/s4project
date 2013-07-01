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
		<div class="popover-wrapper">
  		<p class="site">at <?php print $fields['title']->content; ?></p>
  		<div class="popover-content element-invisible">
  			<h4><?php print strip_tags($fields['title']->content); ?></h4>
  			<div>
  				<?php print $fields['field_location']->content; ?>
  				<?php if($fields['field_csu_facility']->content): ?>
	  				<div><strong>Issues addressed:</strong>
	  					<?php print $fields['field_csu_facility']->content; ?>
	  				</div>
	  			<?php endif; ?>
	  			<div>
	  				<?php print l(t('Read more <span class="element-invisible">about @name', array('@name' => strip_tags($fields['title']->content))),
	  						'node/'. $row->node_field_data_field_opportunity_sites_nid, array('html' => TRUE)); ?>
	  			</div>
  			</div>
  		</div>
  	</div>
		<div class="description">	
			<?php print $fields['field_opportunity_description']->content; ?>
		</div>
	</div>
	<div class="span3 tags">
		<ul class="nav nav-stacked">
			<li class="odd">
				<div class="popover-wrapper">
					<a class="popover-link left"><?php print $fields['type']->content; ?></a>
					<div class="popover-content element-invisible">
		  			<div>
		  				<?php print check_markup($type->data['description']['value'], $type->data['description']['format']); ?>
		  			</div>
		  		</div>
				</div>
			</li>
			<li class="even"><?php print $fields['field_csu_org_type']->content; ?></li>
			<li class="odd last"><strong>Ends: </strong><?php print $fields['field_active_date']->content; ?></li>
		</ul>
	</div>
</div>