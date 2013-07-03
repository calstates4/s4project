<div class="row">
	<div class="span9">
		<?php print $form; ?>
	</div>
	<div class="span2">
		<div class="btn-group">
		  <a class="btn btn-success dropdown-toggle" data-toggle="dropdown" href="#">
		    <i class="icon-plus icon-white"></i> <?php print t('Add'); ?>
		    <span class="caret"></span>
		  </a>
		  <ul class="dropdown-menu">
		    <li><?php print l(t('Form'), 'node/add/file/'. $site->nid, array('query' => array('destination' => 'node/'. $site->nid .'/log'))); ?></li>
		    <li><a href="#add-form" data-toggle="modal">Online form</a></li>
		    <li><?php print l(t('Log entry'), 'node/add/contact-record/'. $site->nid, array('query' => array('destination' => 'node/'. $site->nid .'/log'))); ?></li>
		    <li><a href="#moderate-form" data-toggle="modal">Approval</a></li>
		  </ul>
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
</div>
<div class="row">
	<div class="span12">
		<?php print $results; ?>
	</div>
</div>