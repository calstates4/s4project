(function($) {
	$(document).ready(function() {
		$('input#edit-fields-all').change(function() {
			if ($(this).is(':checked')) {
				$('input.s4-reporting-fields').attr('checked', true);
			}
			else {
				$('input.s4-reporting-fields').attr('checked', false);
			}
		});
		
		$('.field-name-field-filter-field select').chosen();
		$('.field-name-field-report-field select').chosen();
		$('.field-name-field-filter-field select').change(function() {
			var $valueCell = $(this).parents('tr:first').find('.field-name-field-filter-values');
			if (typeof Drupal.settings.s4_reporting_filters[$(this).val()] != 'undefined') {
				var text = $valueCell.find('input.form-text').val().split(',');
				var $valueField = $('<select>');
				$valueField.attr('multiple', 'multiple');
				$.each(Drupal.settings.s4_reporting_filters[$(this).val()], function(index, value) {
					var $option = $('<option>').attr('value', index)
											   .html(value);
					if (text.indexOf(index) != -1) {
						$option.attr('selected', 'selected');
					}
					$valueField.append($option);
				});
				$valueCell.find('input[type=text]').hide();
				$valueCell.append($valueField);
				$valueField.chosen().change(function() {
					$valueCell.find('input.form-text').val($(this).val());
				});
			}
			else {
				$valueCell.find('select').remove();
			}
		});
		$('.field-name-field-filter-field select').each(function() {
			$(this).trigger('change');
		});
	});
	
  	Drupal.ajax.prototype.success = function (response, status) {
		// Remove the progress element.
		  if (this.progress.element) {
		    $(this.progress.element).remove();
		  }
		  if (this.progress.object) {
		    this.progress.object.stopMonitoring();
		  }
		  $(this.element).removeClass('progress-disabled').removeAttr('disabled');
		
		  Drupal.freezeHeight();
		
		  for (var i in response) {
		    if (response[i]['command'] && this.commands[response[i]['command']]) {
		      this.commands[response[i]['command']](this, response[i], status);
		    }
		  }
		
		  // Reattach behaviors, if they were detached in beforeSerialize(). The
		  // attachBehaviors() called on the new content from processing the response
		  // commands is not sufficient, because behaviors from the entire form need
		  // to be reattached.
		  if (this.form) {
		    var settings = this.settings || Drupal.settings;
		    Drupal.attachBehaviors(this.form, settings);
		  }
		
		  Drupal.unfreezeHeight();
		
		  // Remove any response-specific settings so they don't get used on the next
		  // call by mistake.
		  this.settings = null;
			$('.field-name-field-filter-field select').chosen();
			$('.field-name-field-report-field select').chosen();
	};
})(jQuery);

