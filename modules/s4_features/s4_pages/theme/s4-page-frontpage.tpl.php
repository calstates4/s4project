<div class="page-header">
	<h1 class="title" id="page-title"><?php print $title; ?></h1>
</div>
<div class="s4-frontpage">
	<?php if ($alerts && count($alerts)): ?>
		<div class="alert alert-info">
			<?php foreach($alerts as $block): ?>
				<h2>
					<?php if($block['href']): ?>
						<?php print l($block['href'], $block['subject']); ?></a>
					<?php else: ?>
						<?php print $block['subject']; ?>
					<?php endif; ?>
				</h2>
				<div>
					<?php print $block['content']; ?>
				</div>
			<?php endforeach; ?>
		</div>
	<?php endif; ?>
	<?php foreach($blocks as $block): ?>
		<h2><a href="<?php print url($block['href']); ?>"><?php print $block['subject']; ?></a></h2>
		<div class="lead">
			<?php print $block['content']; ?>
		</div>
	<?php endforeach; ?>
</div>