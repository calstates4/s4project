(function($) {
	$(document).ready(function() {
		$('#search input[type=text]').placeholder();
		
		$('.sticky, .site-list .region-content-right').sticky({topSpacing:0});
		
		$('#footer-map .map').css('height', $('#footer-map').height() + 'px');
	});
})(jQuery)