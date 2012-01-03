<p class="overview">
Together, we 
<?php if($data['students']): ?>
  have placed <span class="number"><?php print $data['students']; ?></span> students
<?php else: ?>
  will place students
<?php endif; ?>
 with <span class="number"><?php print $data['sites']; ?></span> <?php print format_plural($data['sites'], 'site', 'sites'); ?> in <span class="number"><?php print $data['cities']; ?></span> <?php print format_plural($data['cities'], 'city', 'different cities'); ?>.
</p>
<p class="intro">Would you like to join our program? <?php print l('Let us know about your organization.', 'node/add/site'); ?> </p>