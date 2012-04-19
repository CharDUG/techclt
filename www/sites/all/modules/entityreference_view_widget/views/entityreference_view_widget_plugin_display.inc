<?php

/**
 * Provides the "Entityreference View Widget" display which configures
 * the view for inclusion in the widget.
 */
class entityreference_view_widget_plugin_display extends views_plugin_display {
  function option_definition() {
    $options = parent::option_definition();

    $options['style_plugin']['default'] = 'grid';
    $options['style_options']['default']['columns'] = '3';
    $options['defaults']['default']['style_plugin'] = FALSE;
    $options['defaults']['default']['style_options'] = FALSE;

    $options['exposed_form']['contains']['type']['default'] = 'entityreference_view_widget';
    $options['defaults']['default']['exposed_form'] = FALSE;

    $options['row_plugin']['default'] = 'entity';
    $options['row_options']['default']['view_mode'] = 'entityreference_view_widget';
    $options['defaults']['default']['row_plugin'] = FALSE;
    $options['defaults']['default']['row_options'] = FALSE;

    // Set the display title to an empty string (not used in this display type).
    $options['title']['default'] = '';
    $options['defaults']['default']['title'] = FALSE;

    return $options;
  }
}
