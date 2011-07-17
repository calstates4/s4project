(function($) {
	$(document).ready(function() {
		$('#edit-preview').addClass('element-invisible');
		$('.ui-accordion-content:not(.ui-accordion-content:last)').each(function() {
			$(this).append('<input type="button" value="Continue" class="continue" />');
		});
		$('.ui-accordion-content .continue').click(function() {
			$(this).parent('.ui-accordion-content').next('h3').trigger('click');
			var position = $(this).parent('.ui-accordion-content').position();
			window.scrollTo(0, position.top);
		});
		$('.ui-accordion-header').each(function(index, element) {
			$(this).prepend('<span class="number">' + (index + 1) +'.</span>');
		});
	});
})(jQuery);