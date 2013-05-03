(function($) {
	$(document).ready(function() {
		$('#search input[type=text]').placeholder();
		
		$('#footer-map .map').css('height', $('#footer-map').height() + 'px');
		
		if($('.horizontal-tabs-panes').length) {
			$(window).resize(function() {
				$('.horizontal-tabs-panes').find('fieldset').css('width', ($('.horizontal-tabs-panes').width() - 28) + 'px');
			});
			$(window).trigger('resize');
		}
	});
})(jQuery)