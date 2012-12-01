(function($) {
	Drupal.behaviors.s4_reporting_views = {
		
		attach : function() {
			$('a.show-form-fancybox').each(function() {
				var $link = $(this);
				$link.fancybox({
					'onClosed' : function() {
						$($link.attr('data-selector')).addClass('element-invisible')
											.parent('div')
											.addClass('element-invisible');
					},
					'onStart'  : function() {
						$($link.attr('data-selector')).removeClass('element-invisible');
					},
					'autoDimensions' : false
				});
			});
			$('select.default-filter').each(function() {
  			 if(Drupal.settings.s4_default_program) {
    			 $(this).find('option').each(function() {
    			   console.log(Drupal.settings.s4_default_program[$(this).attr('value')]);
    			   if(typeof Drupal.settings.s4_default_program[$(this).attr('value')] !== 'undefined') {
        			 $(this).attr('selected', 'selected');
      			 }
    			 });
    			 $('select.default-filter').trigger("liszt:updated");
  			 }
			});
			Drupal.behaviors.viewsSavedSearches = { }
		}
	};
})(jQuery);