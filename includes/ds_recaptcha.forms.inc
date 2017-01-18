<?php

/**
 * @file
 * Custom Form API alterations
 */

/**
 * Implements hook_form_alter().
 */
function ds_recaptcha_form_alter(&$form, &$form_state, $form_id) {

  $form_ids_var = str_replace(' ','', variable_get('ds_recaptcha_form_ids'));


  $form_ids = explode(',', $form_ids_var);
  if(!count($form_ids)){
    return;
  }
  
  if(in_array($form_id,$form_ids)){
    $form['#attributes']['data-recaptcha-id'] = $form_id;

    $div_id = $form['#form_id'].'-captcha';
    //wrapper for reCAPTCHA widget
    $form['actions']['captcha']['#markup'] = '<div id="'.$div_id.'" class="captcha captcha-wrapper"></div>';
    $form['actions']['captcha']['#weight'] = -1;
    //helper JS file
    $form['#attached']['js'] = array(drupal_get_path('module','ds_recaptcha').'/js/ds_recaptcha.js');
  }
}
