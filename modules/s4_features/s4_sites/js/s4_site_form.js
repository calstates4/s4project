(function($) {
  Drupal.behaviors.s4SiteForm = {
    
    attach : function() {
      $('.field-name-field-site-demographics table tbody').append('<tr><td>Total percent</td><td id="demographic-total"></td></tr>');
      $('.field-name-field-site-demographics input[type=text]').keyup(function() {
        var total = 0;
        $('.field-name-field-site-demographics input[type=text]').each(function() {
          if (!isNaN(parseFloat($(this).val())) && isFinite($(this).val())) {
            $(this).removeClass('error');
            total += parseFloat($(this).val());
          }
          else {
            if ($(this).val().trim() != '') {
              $(this).addClass('error');
            }
            else {
              $(this).removeClass('error');
            }
          }
        });
        $('#demographic-total').html(total + '%');
        if (total != 100) {
          $('#demographic-total').removeClass('success');
        }
        if (total > 100) {
          $('#demographic-total').addClass('error');
        }
        else {
          $('#demographic-total').removeClass('error');
          if (total == 100) {
            $('#demographic-total').addClass('success');
          }
        }
      });
      $('.field-name-field-site-demographics input[type=text]:first').trigger('keyup');
      $('#matrix-field-field_site_hours tr').each(function(){
        var $first = $(this).find('td:first');
        $first.html('<a href="#" class="select-all-days">' + $first.html() +'</a>');
      });
      $('.select-all-days').click(function() {
        $(this).parents('tr').find('.matrix-col-1 :checkbox, .matrix-col-2 :checkbox, .matrix-col-3 :checkbox, .matrix-col-4 :checkbox, .matrix-col-5 :checkbox').each(function() {
          if($(this).is(':checked')) {
            $(this).attr('checked', '');
          }
          else {
            $(this).attr('checked', 'checked');
          }
        });
        return false;
      });
    }
  };
})(jQuery);