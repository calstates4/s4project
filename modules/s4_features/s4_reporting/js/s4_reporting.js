(function($) {
	$(document).ready(function() {
		$('input#edit-fields-all').change(function() {
			if($(this).is(':checked')) {
				$('input.s4-reporting-fields').attr('checked', true);
			}
			else {
				$('input.s4-reporting-fields').attr('checked', false);
			}
		});
	});
})(jQuery);