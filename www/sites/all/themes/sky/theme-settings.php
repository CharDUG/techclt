<?php
// Sky
include_once(drupal_get_path('theme', 'adaptivetheme') . '/inc/google.web.fonts.inc');

function sky_form_system_theme_settings_alter(&$form, &$form_state)  {

  $form['at']['font'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fonts'),
    '#description' => t('<h3>Fonts</h3><p>Here you can set a default font which will style all text. You can also set unique fonts for the page title, site name and slogan, and fonts for node, comment and block titles. First select the font type (Websafe or Google web font), then select the font family. You can preview Google web fonts here: <a href="!link" target="_blank">http://www.google.com/webfonts</a></p>', array('!link' => 'http://www.google.com/webfonts')),
  );
  $form['at']['font']['base_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Default font'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['base_font_wrapper']['base_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('base_font_type'),
  );
  $form ['at']['font']['base_font_wrapper']['base_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="base_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['base_font_wrapper']['base_font_container']['base_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('base_font'),
    '#options' => array(
      'bf-sss' => t('Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'bf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'bf-a'   => t('Arial, Helvetica, sans-serif'),
      'bf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'bf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'bf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'bf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'bf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'bf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at'] ['font']['base_font_wrapper']['base_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="base_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['base_font_wrapper']['base_font_gwf_container']['base_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('base_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['site_name_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Site Name'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('site_name_font_type')
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_name_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_container']['site_name_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_name_font'),
    '#options' => array(
      'snf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'snf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'snf-a'   => t('Arial, Helvetica, sans-serif'),
      'snf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'snf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'snf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'snf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'snf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'snf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_name_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['site_name_font_wrapper']['site_name_font_gwf_container']['site_name_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_name_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['site_slogan_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Site Slogan'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['site_slogan_font_wrapper']['site_slogan_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('site_slogan_font_type')
  );
  $form ['at']['font']['site_slogan_font_wrapper']['site_slogan_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_slogan_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_container']['site_slogan_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_slogan_font'),
    '#options' => array(
      'ssf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ssf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ssf-a'   => t('Arial, Helvetica, sans-serif'),
      'ssf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ssf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ssf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ssf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ssf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ssf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="site_slogan_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['site_slogan_font_wrapper']['site_slogan_font_gwf_container']['site_slogan_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('site_slogan_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['font']['page_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Page Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('page_title_font_type')
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="page_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_container']['page_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('page_title_font'),
    '#options' => array(
      'ptf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ptf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ptf-a'   => t('Arial, Helvetica, sans-serif'),
      'ptf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ptf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ptf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ptf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ptf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ptf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="page_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['page_title_font_wrapper']['page_title_font_gwf_container']['page_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('page_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Node title font
  $form['at']['font']['node_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Node Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['node_title_font_wrapper']['node_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('node_title_font_type')
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="node_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_container']['node_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('node_title_font'),
    '#options' => array(
      'ntf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ntf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ntf-a'   => t('Arial, Helvetica, sans-serif'),
      'ntf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ntf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ntf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ntf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ntf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ntf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="node_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['node_title_font_wrapper']['node_title_font_gwf_container']['node_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('node_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Comment title font
  $form['at']['font']['comment_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Comment Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  $form ['at']['font']['comment_title_font_wrapper']['comment_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('comment_title_font_type')
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="comment_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_container']['comment_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('comment_title_font'),
    '#options' => array(
      'ctf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ctf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ctf-a'   => t('Arial, Helvetica, sans-serif'),
      'ctf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ctf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ctf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ctf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ctf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ctf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at']['font']['comment_title_font_wrapper']['comment_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="comment_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['comment_title_font_wrapper']['comment_title_font_gwf_container']['comment_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('comment_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  // Block title font
  $form ['at']['font'] ['block_title_font_wrapper'] = array (
    '#type' => 'fieldset',
    '#title' => t('Block Title'),
    '#attributes' => array('class' => array('font-element-wrapper'))
  );
  // Block title font
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_type'] = array (
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array (
      '' => t('Websafe font'),
      'gwf' => t('Google font'),
    ),
    '#default_value' => theme_get_setting('block_title_font_type')
  );
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="block_title_font_type"]' => array (
          'value' => ''
        )
      )
    )
  );
  $form['at']['font']['block_title_font_wrapper']['block_title_font_container']['block_title_font'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('block_title_font'),
    '#options' => array(
      'btf-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'btf-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'btf-a'   => t('Arial, Helvetica, sans-serif'),
      'btf-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'btf-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'btf-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'btf-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'btf-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'btf-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form ['at']['font']['block_title_font_wrapper']['block_title_font_gwf_container'] = array (
    '#type' => 'container',
    '#states' => array (
      'visible' => array (
        'select[name="block_title_font_type"]' => array (
          'value' => 'gwf'
        )
      )
    )
  );
  $form['at']['font']['block_title_font_wrapper']['block_title_font_gwf_container']['block_title_font_gwf'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('block_title_font_gwf'),
    '#options' => google_web_fonts_list_options(),
  );
  $form['at']['size'] = array(
    '#type' => 'fieldset',
    '#title' => t('Font Size'),
    '#description' => t('<h3>Font Size</h3>'),
  );
  $form['at']['size']['font_size'] = array(
    '#type' => 'select',
    '#title' => t('Font Size'),
    '#default_value' => theme_get_setting('font_size'),
    '#description' => t('This sets a base font-size on the body element - all text will scale relative to this value.'),
    '#options' => array(
      'fs-smallest' => t('Smallest'),
      'fs-small'    => t('Small'),
      'fs-medium'   => t('Medium'),
      'fs-large'    => t('Large'),
      'fs-largest'  => t('Largest'),
    ),
  );
  $form['at']['headings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Heading Styles'),
    '#description' => t('<h3>Heading Styles</h3><p>Add extra styles to headings. Shadows ony work for CSS3 capable browsers such as Firefox, Safari, IE9 etc.</p>'),
  );
  $form['at']['headings']['headings_styles_caps'] = array(
    '#type' => 'checkbox',
    '#title' => t('All Caps'),
    '#default_value' => theme_get_setting('headings_styles_caps'),
  );
  $form['at']['headings']['headings_styles_weight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Font weight normal'),
    '#default_value' => theme_get_setting('headings_styles_weight'),
  );
  $form['at']['headings']['headings_styles_shadow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Text shadows'),
    '#default_value' => theme_get_setting('headings_styles_shadow'),
  );
  $form['at']['corners'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rounded corners'),
    '#description' => t('<h3>Rounded Corners</h3><p>Rounded corners are implimented using CSS and only work in modern compliant browsers. You can set the radius for both the main content and main menu tabs.</p>'),
  );
  $form['at']['corners']['content_corner_radius'] = array(
    '#type' => 'select',
    '#title' => t('Main content radius'),
    '#default_value' => theme_get_setting('content_corner_radius'),
    '#description' => t('Change the corner radius for the main content area.'),
    '#options' => array(
      'rc-0' => t('none'),
      'rc-4' => t('4px'),
      'rc-6' => t('6px'),
      'rc-8' => t('8px'),
      'rc-10' => t('10px'),
      'rc-12' => t('12px'),
    ),
  );
  $form['at']['corners']['tabs_corner_radius'] = array(
    '#type' => 'select',
    '#title' => t('Menu tabs radius'),
    '#default_value' => theme_get_setting('tabs_corner_radius'),
    '#description' => t('Change the corner radius for the main menu tabs.'),
    '#options' => array(
      'rct-0' => t('none'),
      'rct-4' => t('4px'),
      'rct-6' => t('6px'),
      'rct-8' => t('8px'),
      'rct-10' => t('10px'),
      'rct-12' => t('12px'),
    ),
  );
  $form['at']['pagestyles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Textures'),
    '#description' => t('<h3>Textures</h3><p>Textures are small, semi-transparent images that tile to fill the entire page background.</p>'),
  );
  $form['at']['pagestyles']['textures'] = array(
    '#type' => 'fieldset',
    '#title' => t('Textures'),
    '#description' => t('<h3>Body Textures</h3><p>This setting adds a texture over the main background color - the darker the background the more these stand out, on light backgrounds the effect is subtle.</p>'),
  );
  $form['at']['pagestyles']['textures']['body_background'] = array(
    '#type' => 'select',
    '#title' => t('Select texture'),
    '#default_value' => theme_get_setting('body_background'),
    '#options' => array(
      'bb-n'  => t('None'),
      'bb-h'  => t('Hatch'),
      'bb-vl' => t('Vertical lines'),
      'bb-hl' => t('Horizontal lines'),
      'bb-g'  => t('Grid'),
      'bb-d'  => t('Dots'),
    ),
  );
  // Image styles
  $form['at']['images'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Settings'),
    '#description' => '<h3>Image Settings</h3>',
  );
  $form['at']['images']['alignment'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Alignment'),
  );
  $form['at']['images']['alignment']['image_alignment'] = array(
    '#type' => 'radios',
    '#title' => t('<strong>Image field alignment</strong>'),
    '#default_value' => theme_get_setting('image_alignment'),
    '#description' => t('This will only affect images added using an image-field. If you use another method such as embedding images directly into text areas this will not affect those images.'),
    '#options' => array(
      'ia-n' => t('None'),
      'ia-l' => t('Left'),
      'ia-c' => t('Centered'),
      'ia-r' => t('Right'),
    ),
  );
  $form['at']['images']['captions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Image Captions'),
    '#description' => t('<strong>Display the image title as a caption</strong>'),
  );
  $form['at']['images']['captions']['image_caption_teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show captions on teaser view'),
    '#default_value' => theme_get_setting('image_caption_teaser'),
  );
  $form['at']['images']['captions']['image_caption_full'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show captions on full view'),
    '#default_value' => theme_get_setting('image_caption_full'),
  );
  $form['at']['menu_styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu Bullets'),
    '#description' => t('<h3>Menu Bullets</h3><p>This setting allows you to customize the bullet images used on menus items. Bullet images only show on normal vertical block menus.</p>'),
  );
  $form['at']['menu_styles']['menu_bullets'] = array(
    '#type' => 'select',
    '#title' => t('Menu Bullets'),
    '#default_value' => theme_get_setting('menu_bullets'),
    '#options' => array(
      'mb-n' => t('None'),
      'mb-dd' => t('Drupal default'),
      'mb-ah' => t('Arrow head'),
      'mb-ad' => t('Double arrow head'),
      'mb-ca' => t('Circle arrow'),
      'mb-fa' => t('Fat arrow'),
      'mb-sa' => t('Skinny arrow'),
    ),
  );
  $form['theme_settings']['#collapsible'] = TRUE;
  $form['theme_settings']['#collapsed'] = TRUE;
  $form['logo']['#collapsible'] = TRUE;
  $form['logo']['#collapsed'] = TRUE;
  $form['favicon']['#collapsible'] = TRUE;
  $form['favicon']['#collapsed'] = TRUE;
}
