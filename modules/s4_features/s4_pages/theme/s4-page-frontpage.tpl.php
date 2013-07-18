<div class="page-header">
	<h1 class="title" id="page-title"><?php print $title; ?></h1>
</div>
<?php foreach($blocks as $block): ?>
	<h2><a href="<?php print url($block['href']); ?>"><?php print $block['subject']; ?></a></h2>
	<div class="lead">
		<?php print $block['content']; ?>
	</div>
<?php endforeach; ?>