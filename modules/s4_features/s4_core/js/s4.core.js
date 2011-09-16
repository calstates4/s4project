(function($) {
	Drupal.behaviors.s4Core = {
		
		attach : function() {
			this.addChosen();
			$('.view.quicksearch').each(function(index, element) {
		      $(this).prepend('<div class="search-filter"><label for="filter-' + index + 
		               '">Filter: </label><input type="text" id="filter-' + index +
		               '" name="filter-' + index + '"></div>');
		      if ($(this).find('.view-content table').length) {
		        $(this).find('.view-content table').attr('id', 'list-' + index);
		        $('input#filter-' + index).quicksearch('table#list-' + index +' tbody tr');
		      }
		      if ($(this).find('.view-content ul').length) {
		        $(this).find('.view-content ul').attr('id', 'list-' + index);
		        $('input#filter-' + index).quicksearch('ul#list-' + index +' li');
		      }
		    });
		},
		addChosen : function() {
			$('select[multiple=multiple], select.chosen').each(function() {
				$(this).chosen();
			});
		}
	};
})(jQuery);