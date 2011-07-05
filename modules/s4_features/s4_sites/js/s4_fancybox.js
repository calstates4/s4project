(function($) {

/**
 * Initiate Fancybox using selector and options from the module's settings.
 */
Drupal.behaviors.initFancybox = {
  attach : function() {
    if($('.imagefield-fancybox').length) {
	    $('.imagefield-fancybox').each(function() {
	    	$(this).attr('rel', 'fancybox_group');
	    });
	    $('.imagefield-fancybox').fancybox();
	}
  }
}

})(jQuery);