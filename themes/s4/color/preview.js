// $Id: preview.js,v 1.5 2010/12/11 21:37:41 webchick Exp $

(function ($) {
  
  
  
  Drupal.color = {
    logoChanged: false,
    callback: function(context, settings, form, farb, height, width) {
      if($('.form-item-palette-bottom .lock').hasClass('unlocked')) {
      	  $('.form-item-palette-bottom .lock').trigger('click');
      }
      if($('.form-item-palette-nav-bottom .lock').hasClass('unlocked')) {
      	  $('.form-item-palette-nav-bottom .lock').trigger('click');
      } 
      $('#preview #preview-footer a', form).css('color', $('#palette input[name="palette[branding-links]"]', form).val());
      
      // CSS3 Gradients.
      var branding_gradient_start = $('#palette input[name="palette[top]"]', form).val();
      var branding_gradient_end = $('#palette input[name="palette[bottom]"]', form).val();
      var navigation_gradient_start = $('#palette input[name="palette[nav-top]"]', form).val();
      var navigation_gradient_end = $('#palette input[name="palette[nav-bottom]"]', form).val();
       var navigation_border = $('#palette input[name="palette[nav-border]"]', form).val();

      $('#preview #preview-branding, #preview #preview-footer', form).attr('style', "background-color: " + branding_gradient_start + "; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(" + branding_gradient_start + "), to(" + branding_gradient_end + ")); background-image: -moz-linear-gradient(-90deg, " + branding_gradient_start + ", " + branding_gradient_end + ");");
      
      $('#preview #preview-navigation', form).attr('style', "background-color: " + navigation_gradient_start + "; background-image: -webkit-gradient(linear, 0% 0%, 0% 100%, from(" + navigation_gradient_start + "), to(" + navigation_gradient_end + ")); background-image: -moz-linear-gradient(-90deg, " + navigation_gradient_start + ", " + navigation_gradient_end + ");");
      
      $('#preview #preview-navigation', form).css('border-top-color', navigation_border);
    }
  };
})(jQuery);
