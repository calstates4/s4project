<div class="dropdown">
  <a href="#" data-toggle="dropdown" class="btn btn-large btn-success">Yes, sign me up.</a>
  <ul class="dropdown-menu" role="menu" aria-labelledby="dLabel">
    <?php if($courses): ?>
    	<?php foreach($courses as $course): ?>
    		<li>
    			<a href="<?php print url('opportunities/create/place-immediately/' . $course->nid); ?>">
    			<?php print $course->field_field_course_subject[0]['raw']['value'] .' '.
						$course->field_field_course_catalog_number[0]['raw']['value'] .' section '. 
						$course->field_field_course_section[0]['raw']['value'] .': '.
						$course->field_field_course_title[0]['raw']['value']; ?>
					</a>
				</li>
    	<?php endforeach; ?>
    	<?php foreach($programs as $program): ?>
    		<li>
    			<a href="<?php print url('opportunities/create/place-immediately'); ?>">Program: <?php print $program->name; ?></a>
    		</li>
    	<?php endforeach; ?>
	  <?php endif; ?>
  </ul>
</div>

<a href="<?php print url('opportunities/create/done'); ?>">
	<h4>No, do not place me</h4>
</a>
<p>Thanks for letting us know about this <?php print $type->label; ?>!
</p>