<div class="row">
	<div class="span12">
		<?php print $form; ?>
	</div>
</div>
<div class="row">
	<div class="span12">
		<?php print $results; ?>
	</div>
</div>
<div id="add-form" class="modal hide fade modal-wide">
	  <div class="modal-header">
	    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
	    <h3>Add form</h3>
	  </div>
	  <div class="modal-body">
	    <?php print $send_form; ?>
	  </div>
	</div>
	<div id="moderate-form" class="modal hide fade modal-wide">
	  <div class="modal-header">
	    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
	    <h3>Approval</h3>
	  </div>
	  <div class="modal-body">
	    <?php print $moderate_form; ?>
	  </div>
	</div>
</div>
