(function($) {
	$(document).ready(function() {
		$('#search input[type=text]').placeholder();
		
		$('#footer-map .map').css('height', $('#footer-map').height() + 'px');
	});
})(jQuery)