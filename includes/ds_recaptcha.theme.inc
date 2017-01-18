<?php

/**
 * @file
 * Custom theme implementations
 */

/*
 * Implements theme_preprocess_page()
 */
function ds_recaptcha_preprocess_page(&$variables){
  $form_ids_var = variable_get('ds_recaptcha_form_ids');
  $form_ids = explode(',', $form_ids_var);
  if(count($form_ids) > 0){
    drupal_add_js('https://www.google.com/recaptcha/api.js','external');
    drupal_add_js(array('ds_recaptcha' => array('forms' => $form_ids)), 'setting');
    drupal_add_js(array('ds_recaptcha' => array('sitekey' => variable_get('ds_recaptcha_sitekey'))), 'setting');
    drupal_add_js(array('ds_recaptcha' => array('error_msg' => t('Please fill up reCAPTCHA.'))), 'setting');
  }
}

function ds_recaptcha_js_alter(&$javascript){

  $javascript['https://www.google.com/recaptcha/api.js']['async'] = TRUE;
  $javascript['https://www.google.com/recaptcha/api.js']['defer'] = TRUE;

}