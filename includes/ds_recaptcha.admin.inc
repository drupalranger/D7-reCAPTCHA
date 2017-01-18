<?php

/**
 * @file
 * Administration area for ds_recaptcha module
 */

/**
 * Configuration form
 *
 * @see ds_recaptcha_menu()
 */
function ds_recaptcha_form($form, &$form_state) {
  $form['ds_recaptcha_form_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('Form IDs'),
    '#default_value' => variable_get('ds_recaptcha_form_ids'),
    '#description' => t('Fill in textara with IDs of forms on which you would like to turn on reCAPTCHA. Separate form IDs with comma.'),
    '#required' => FALSE,
  );

  $form['ds_recaptcha_sitekey'] = array(
    '#type' => 'textfield',
    '#title' => t('reCAPTCHA sitekey'),
    '#description' => t( 'Sitekey obtained from !link', array('!link' => l(t('Google reCAPTCHA service'), 'https://www.google.com/recaptcha/admin' , array('attributes' => array('target' => '_blank'))))),
    '#default_value' => variable_get('ds_recaptcha_sitekey')
  );

  return system_settings_form($form);
}