(function($) {
	Drupal.behaviors.s4Theme = {
		
		attach : function() {
			$('#search input[type=text]').placeholder();
			
			$('#footer-map .map').css('height', $('#footer-map').height() + 'px');
			
			if($('.horizontal-tabs-panes').length) {
				$(window).resize(function() {
					$('.horizontal-tabs-panes').find('fieldset').css('width', ($('.horizontal-tabs-panes').width() - 28) + 'px');
				});
				$(window).trigger('resize');
			}
		}
	};
	
	Drupal.progressBar = function (id, updateCallback, method, errorCallback) {
	  var pb = this;
	  this.id = id;
	  this.method = method || 'GET';
	  this.updateCallback = updateCallback;
	  this.errorCallback = errorCallback;
	
	  // The WAI-ARIA setting aria-live="polite" will announce changes after users
	  // have completed their current activity and not interrupt the screen reader.
	  this.element = $('<div class="progress progress-striped active" aria-live="polite"></div>').attr('id', id);
	  this.element.html('<div class="bar filled"></div>' +
	                    '</div>' +
	                    '<div class="message">&nbsp;</div>');
	};
})(jQuery)
