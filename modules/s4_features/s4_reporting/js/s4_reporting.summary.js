(function($) {
  Drupal.behaviors.s4ReportingSummary = {
    
    attach : function() {
      $('table.population').each(function() {
        var $link = $('<a href="#">' + Drupal.t('Hide population statistics') + '</a>');
        $(this).before($link);
        $link.click(function() {
          if($(this).hasClass('hidden-active')) {
            $(this).removeClass('hidden-active')
                   .html(Drupal.t('Show population statistics'));
            $(this).next('table')
                   .find('.demographics')
                   .show();
          }
          else {
            $(this).addClass('hidden-active')
                   .html(Drupal.t('Hide population statistics'));
            $(this).next('table')
                   .find('.demographics')
                   .hide();
          }
          return false;
        });
        
      });
    }
  };
})(jQuery);