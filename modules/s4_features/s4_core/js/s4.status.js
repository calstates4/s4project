(function($) {
	$(document).ready(function() {
		/*$('.signup a').click(function() {
			var link = $(this);
			$.getJSON($(this).attr('href') + '?js=1', function(data) {
				if(data.success && data.action == 'add') {
					link.parent('.signup')
					    .addClass('signed-up')
					    .after('<div class="fineprint">Click again to cancel</div>');
					link.html(data.message);
					$('#' + link.attr('data-target')).fadeOut('normal', function() {
						$(this).addClass('done');
						$(this).fadeIn('normal');
					});
				}
				if(data.success && data.action == 'remove') {
					link.parent('.signup')
						.removeClass('signed-up')
						.parent('div')
						.find('.fineprint')
						.remove();
					link.html(data.message);
					$('#' + link.attr('data-target')).fadeOut('normal', function() {
						$(this).removeClass('done');
						$(this).fadeIn('normal');
					});
				}
			});
			return false;
		});*/
	});
})(jQuery);