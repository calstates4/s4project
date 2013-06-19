<p class="lead">Now that your <?php print $type->label; ?> has been created, would you like to be placed with this <?php print $type->label; ?>?</p>
<div class="row">
	<div class="span6">
	<a href="<?php print url('opportunities/create/place-immediately'); ?>">
		<h3>Yes, place me</h3>
	</a>
	<p>You will receive an email with further instructions, most placements require approval by a department staff.</p>
	</div>
	<div class="span6">
		<a href="<?php print url('opportunities/create/done'); ?>">
			<h3>Do not place me</h3>
		</a>
		<p>Thanks for letting us know about this <?php print $type->label; ?>!
		</p>
</div>
</div>