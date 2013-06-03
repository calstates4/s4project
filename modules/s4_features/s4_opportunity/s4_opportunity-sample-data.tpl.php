<?php

/**
 * @file
 * Example tpl file for theming a single s4_opportunity-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $s4_opportunity: The s4_opportunity object this status is derived from
 */
?>

<div class="s4_opportunity-status">
  <?php print '<strong>s4_opportunity Sample Data:</strong> ' . $s4_opportunity_sample_data = ($s4_opportunity_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>