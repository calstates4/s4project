(function($) {
	Drupal.behaviors.s4_reporting_views = {
		
		attach : function() {
			$('#show-fields').fancybox({
				'onClosed' : function() {
					$('#field-selector').addClass('element-invisible')
										.parent('div')
										.addClass('element-invisible');
				},
				'onStart'  : function() {
					$('#field-selector').removeClass('element-invisible');
				},
				'autoDimensions' : false
			});
		}
	};
})(jQuery);