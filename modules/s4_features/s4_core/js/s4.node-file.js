(function($) {
  $(document).ready(function() {
    if ($('body').hasClass('page-node-add-file')) {
      $('#edit-field-expiration-reminder-und').change(function() {
        var $reminder = $('#edit-field-expiration-reminder-date-und-0-value-datepicker-popup-0');
        if (!$('#edit-field-expiration-reminder-und').is(':checked')) {
          $reminder.attr('disabled', 'disabled');
        }
        else {
          $reminder.removeAttr('disabled');
        }
      });
      $('#edit-field-expiration-reminder-und').trigger('change');
      if (!Drupal.settings.file_category_reminders.node_exists) {
        //Only reset the reminder date if the file doesn't exist yet
        $('#edit-field-file-category-und, #edit-field-expiration-date-und-0-value-datepicker-popup-0').change(function() {
          var days = Drupal.settings.file_category_reminders.days[$('#edit-field-file-category-und').val()];
          var date = new Date($('#edit-field-expiration-date-und-0-value-datepicker-popup-0').val());
          var reminderDate = new Date();
          reminderDate.setTime(date.getTime() - (days * (24 * 60 * 60 * 1000)));
          $('#edit-field-expiration-reminder-date-und-0-value-datepicker-popup-0').val((reminderDate.getMonth() + 1) + '/' + reminderDate.getDate() + '/' + reminderDate.getFullYear());
        });
      }
    }
  });
})(jQuery);