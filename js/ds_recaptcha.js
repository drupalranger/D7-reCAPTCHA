(function ($) {
    Drupal.behaviors.ds_recaptcha = {
        attach: function (context, settings) {

            //loop through all form ids supported by reCAPTCHA
            var forms = Drupal.settings.ds_recaptcha.forms
            var captchas = [];

            $.each( forms, function( key, formId) {
                //pick form and submit button
                var $form = $('form[data-recaptcha-id="'+formId+'"]');
                var $submit = $form.find('input[type="submit"]');

                //disable submit button
                $submit.attr('data-disabled','true');

                $submit.on('click', function(e){
                    if( $(this).attr('data-disabled') == 'true' ){
                        // get captcha wrapper
                        var $captcha = $(this).prev('.captcha-wrapper');

                        // render captcha widget if it is first form submission
                        if ($captcha.length && typeof captchas[formId] === 'undefined') {
                            captchas[formId] = grecaptcha.render( $captcha.attr('id'), {'sitekey' : Drupal.settings.ds_recaptcha.sitekey});
                            $captcha.fadeIn();
                            e.preventDefault();
                        }
                        else{
                            //check reCaptcha response
                            var response = grecaptcha.getResponse(captchas[formId]);
                            if(response.length){
                                // submit form if there is a response
                                $(this).removeAttr('data-disabled');
                                $(this).trigger('click');
                            }
                            else{
                                // let user know what's going on
                                $captcha.children().css({'border':'1px solid #e74c3c', 'border-radius':'4px'});
                                e.preventDefault();
                            }
                        }
                    }
                });
            });
        }
    };
})(jQuery);
