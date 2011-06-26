(function($) {
	$(document).ready(function() {
		$('#search input[type=text]').placeholder();
		
		/** BINDING THE TOOLS SLIDE **/
		$('#tool-menu').click(function() {
			if($('#tools').css('display') == 'none') {
				$(this).addClass('active');
			}
			else {
				$(this).removeClass('active');
			}
			$('#tools').slideToggle();
			return false;
		});
		$('.bookmarks .flag-bookmarks').each(function() {
			$(this).hide();
		});
		$('.bookmarks li a').focus(function() {
			$('.bookmarks .flag-bookmarks').show();
		});
		$('.bookmarks li a').focusout(function() {
			$('.bookmarks .flag-bookmarks').hide();
		});
		$('.bookmarks li').hover(function() {
			$(this).find('.flag-bookmarks').show();
		},
		function() {
			$(this).find('.flag-bookmarks').hide();
		});
	});
})(jQuery)