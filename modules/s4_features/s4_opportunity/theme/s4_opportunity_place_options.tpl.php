<p class="lead">Now that your <?php print $type->label; ?> has been created, would you like to be placed with this <?php print $type->label; ?>?</p>
<div class="row">
	<div class="span6">
		<h3>Yes, place me</h3>
		<p>You will receive an email with further instructions, most placements require approval by a department staff.</p>
		<?php if($courses): ?>
			<p class="lead">Select the course you are taking this <?php print $type->label; ?> for.</p>
			<table class="table table-striped table-bordered">
				<thead>
					<th>Course</th>
					<th>Select</th>
				</thead>
				<tbody>
					<?php foreach($courses as $course): ?>
						<tr>
							<td><?php print $course->field_field_course_subject[0]['raw']['value'] .' '.
								$course->field_field_course_catalog_number[0]['raw']['value'] .' section '. 
								$course->field_field_course_section[0]['raw']['value'] .': '.
								$course->field_field_course_title[0]['raw']['value']; ?>
							</td>
							<td>
								<a href="<?php print url('opportunities/create/place-immediately/' . $course->nid); ?>"class="btn btn-primary">Select</a>
							</td>
						</tr>
					<?php endforeach; ?>
				</tbody>
			</table>
		<?php endif;?>
		<p class="lead"><a href="<?php print url('opportunities/create/place-immediately'); ?>">
			I am not taking this <?php print $type->label; ?> as part of a course.</a>
		</p>
	</div>
	<div class="span6">
		<a href="<?php print url('opportunities/create/done'); ?>">
			<h3>No, do not place me</h3>
		</a>
		<p>Thanks for letting us know about this <?php print $type->label; ?>!
		</p>
</div>
</div>