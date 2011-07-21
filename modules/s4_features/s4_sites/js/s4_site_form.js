(function($) {
	$(document).ready(function () {
		$('select').each(function() {
			if($(this).attr('multiple')) {
				$(this).chosen();
			}
		});
		$('.field-name-field-site-demographics table tbody').append('<tr><td>Total percent</td><td id="demographic-total"></td></tr>');
		$('.field-name-field-site-demographics input[type=text]').keyup(function() {
			var total = 0;
			$('.field-name-field-site-demographics input[type=text]').each(function() {
				if(!isNaN(parseFloat($(this).val())) && isFinite($(this).val())) {
					$(this).removeClass('error');
					total += parseFloat($(this).val());
				}
				else {
					if($(this).val().trim() != '') {
						$(this).addClass('error');
					}
					else {
						$(this).removeClass('error');
					}
				}
			});
			$('#demographic-total').html(total + '%');
			if(total > 100) {
				$('#demographic-total').addClass('error');
			}
			else {
				$('#demographic-total').removeClass('error');
			}
		});
		$('.field-name-field-site-demographics input[type=text]:first').trigger('keyup');
	});
})(jQuery);