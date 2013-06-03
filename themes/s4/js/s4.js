(function($) {
	Drupal.behaviors.s4Theme = {
		
		attach : function() {
			$('#search input[type=text]').placeholder();
			
			$('#footer-map .map').css('height', $('#footer-map').height() + 'px');
			
			if($('.horizontal-tabs-panes').length) {
				$(window).resize(function() {
					$('.horizontal-tabs-panes').find('fieldset:not(table fieldset), table').css('width', ($('.horizontal-tabs-panes').width() - 28) + 'px');
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
	  this.element.html('<div class="bar filled"></div>')
	              .after('<div class="message">&nbsp;</div>');
	};
	
	Drupal.progressBar.prototype.setProgress = function (percentage, message) {
	  if (percentage >= 0 && percentage <= 100) {
	    $('div.filled', this.element).css('width', percentage + '%');
	    $('div.percentage', this.element).html(percentage + '%');
	  }
	  this.element.next('div.message').html(message);
	  if (this.updateCallback) {
	    this.updateCallback(percentage, message, this);
	  }
	};
	
	/**
	 * Start monitoring progress via Ajax.
	 */
	Drupal.progressBar.prototype.startMonitoring = function (uri, delay) {
	  this.delay = delay;
	  this.uri = uri;
	  this.sendPing();
	};
	
	/**
	 * Stop monitoring progress via Ajax.
	 */
	Drupal.progressBar.prototype.stopMonitoring = function () {
	  clearTimeout(this.timer);
	  // This allows monitoring to be stopped from within the callback.
	  this.uri = null;
	};
	
	/**
	 * Request progress data from server.
	 */
	Drupal.progressBar.prototype.sendPing = function () {
	  if (this.timer) {
	    clearTimeout(this.timer);
	  }
	  if (this.uri) {
	    var pb = this;
	    // When doing a post request, you need non-null data. Otherwise a
	    // HTTP 411 or HTTP 406 (with Apache mod_security) error may result.
	    $.ajax({
	      type: this.method,
	      url: this.uri,
	      data: '',
	      dataType: 'json',
	      success: function (progress) {
	        // Display errors.
	        if (progress.status == 0) {
	          pb.displayError(progress.data);
	          return;
	        }
	        // Update display.
	        pb.setProgress(progress.percentage, progress.message);
	        // Schedule next timer.
	        pb.timer = setTimeout(function () { pb.sendPing(); }, pb.delay);
	      },
	      error: function (xmlhttp) {
	        pb.displayError(Drupal.ajaxError(xmlhttp, pb.uri));
	      }
	    });
	  }
	};
	
	/**
	 * Display errors on the page.
	 */
	Drupal.progressBar.prototype.displayError = function (string) {
	  var error = $('<div class="messages error"></div>').html(string);
	  $(this.element).before(error).hide();
	
	  if (this.errorCallback) {
	    this.errorCallback(this);
	  }
	};
})(jQuery)
