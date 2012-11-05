(function($) {
	Drupal.behaviors.s4Core = {
		
		attach : function(context) {
			this.addChosen(context);
			this.openModal(context);
			$('.view.quicksearch:has(table)').each(function(index, element) {
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
		addChosen : function(context) {
			$('select[multiple=multiple], select.chosen', context).each(function() {
		    $(this).css({
  		    width : ($(this).width() < 250) ? 250 : $(this).width()
  		  }).chosen();
			});
			$('.chosen-widget').each(function() {
			 $(this).css('min-width', '150px');
			});
		}
	};
})(jQuery);