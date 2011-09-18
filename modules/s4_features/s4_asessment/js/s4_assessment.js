(function($) {
	Drupal.behaviors.s4_assessment = {
		attach: function() {
			$('.rubric-show').each(function() {
				var $link = $(this);
				$link.fancybox({
					'width' : '80%',
					'onClosed' : function() {
						$($link.attr('href')).addClass('element-invisible')
											 .parent('div')
											 .removeAttr('style');
					},
					'onStart'  : function() {
						$($link.attr('href')).removeClass('element-invisible');
					},
					'autoDimensions' : false
				});
			});
		}
	};
})(jQuery);