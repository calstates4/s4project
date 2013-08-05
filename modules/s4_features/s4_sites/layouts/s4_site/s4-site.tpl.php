<?php

/**
 * @file
 * S4 two column template
 */


?>
<div class="s4-2col row <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($left): ?>
    <div class="span9 group-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <div class="span3 group-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </div>
  <?php endif; ?>

</div>
<div class="row">
  <div class="span12">
    <ul class="nav nav-tabs in-page-tabs" id="site-tabs">
      <li class="active"><a href="#details">Details</a></li>
      <?php if($risks): ?>
        <li><a class="text-error" href="#risks">Risks</a></li>
      <?php endif; ?>
      <?php if($staff): ?>
        <li><a href="#staff">Site staff</a></li>
      <?php endif; ?>
      <?php if($demographics || $language || $population): ?>
        <li><a href="#demographics">Population &amp; Language</a></li>
      <?php endif; ?>
      <?php if($opportunities): ?>
        <?php $opportunity_count = s4_opportunity_get_site_opportunities($node->nid); ?>
        <?php if(count($opportunity_count)): ?>
          <li><a href="#opportunities">Opportunities <span class="badge badge-important"><?php print count($opportunity_count); ?></span></a></li>
        <?php endif; ?>
      <?php endif; ?>
      <?php if($hours): ?>
        <li><a href="#hours">Hours</a></li>
      <?php endif; ?>
    </ul>

    <div id="site-tab-content" class="tab-content">
      <div class="tab-pane fade active in" id="details">
        <div class="row">
          <div class="span9">
            <?php print $details; ?>
          </div>
          <div class="span3">
            <ul class="nav nav-stacked nav-details">
              <?php s4_even_odd(TRUE); ?>
              <?php if($details_1): ?>
                <li class="<?php print s4_even_odd(); ?>">
                  <?php print $details_1; ?>
                </li>
              <?php endif; ?>
              <?php if($details_2): ?>
                <li class="<?php print s4_even_odd(); ?>">
                  <?php print $details_2; ?>
                </li>
              <?php endif; ?> 
              <?php if($details_3): ?>
                <li class="<?php print s4_even_odd(); ?>">
                  <?php print $details_3; ?>
                </li>
              <?php endif; ?> 
              <?php if($details_4): ?>
                <li class="<?php print s4_even_odd(); ?>">
                  <?php print $details_4; ?>
                </li>
              <?php endif; ?>
            </ul>
          </div>
        </div>
      </div>
      <?php if($risks): ?>
        <div class="tab-pane fade" id="risks">  
          <?php print $risks; ?>
        </div>
      <?php endif; ?>
      <?php if($staff): ?>
        <div class="tab-pane fade" id="staff">  
          <?php print $staff; ?>
        </div>
      <?php endif; ?>
      <?php if($demographics || $language || $population): ?>
        <div class="tab-pane fade" id="demographics">  
          <div class="row">
            <div class="span4">
              <?php print $demographics; ?>
            </div>
            <div class="span4">
              <?php print $language; ?>
            </div>
            <div class="span4">
              <?php print $population; ?>
            </div>
          </div>
        </div>
      <?php endif; ?>
      <?php if($opportunities && count($opportunity_count)): ?>
        <div class="tab-pane fade" id="opportunities">  
          <?php print $opportunities; ?>
        </div>
      <?php endif; ?>
      <?php if($hours): ?>
        <div class="tab-pane fade" id="hours">  
          <?php print $hours; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
