(function($) {
	$(document).ready(function() {
		$('input.hours-field').keyup(function() {
			if(!isNaN(parseFloat($(this).val())) && isFinite($(this).val())) {
				$(this).removeClass('error');
			}
			else {
				$(this).addClass('error');
			}
		});
	});
})(jQuery);