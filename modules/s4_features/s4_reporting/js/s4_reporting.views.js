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
		}
	};
})(jQuery);