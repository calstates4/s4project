(function ($) {

  Drupal.behaviors.s4_help = {
    attach: function(context) {
      $('#contextual-help').click(this.showHelp);
    },
    
    showHelp: function() {
      $.each(Drupal.settings.s4_help, function(key, help) {
        if (help.overlay) {
          guiders.createGuider(help).show();
        }
        else {
          guiders.createGuider(help);
        }
        
      });
      return false;
    }
  };

})(jQuery);