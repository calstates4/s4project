<?php if(!count($types)): ?>
<p class="lead">There are no types of opportunities defined.</p>
<?php else: ?>
	<ul>
		<?php foreach($types as $type): ?>
			<li>
				<a href="<?php print url('opportunities/create/'. $type->type); ?>">
					<h3><?php print $type->label; ?></h3>
				</a>
				<p>
					<?php print check_markup($type->data['description']['value'], $type->data['description']['format']); ?>
				</p>
			</li>
		<?php endforeach; ?>
	</ul>
<?php endif; ?>
