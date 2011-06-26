<?php
/**
 * @file
 * s4_editor.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function s4_editor_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_default_wysiwyg_profile().
 */
function s4_editor_default_wysiwyg_profile() {
  $items = array();
  $items['filtered_html'] = entity_import('wysiwyg_profile', '{
    "format" : "filtered_html",
    "editor" : "tinymce",
    "settings" : {
      "default" : 1,
      "user_choose" : 0,
      "show_toggle" : 1,
      "theme" : "advanced",
      "language" : "en",
      "buttons" : {
        "default" : {
          "bold" : 1,
          "italic" : 1,
          "underline" : 1,
          "bullist" : 1,
          "numlist" : 1,
          "undo" : 1,
          "redo" : 1,
          "link" : 1,
          "unlink" : 1,
          "anchor" : 1,
          "image" : 1,
          "blockquote" : 1,
          "cut" : 1,
          "copy" : 1,
          "paste" : 1,
          "removeformat" : 1,
          "charmap" : 1
        },
        "font" : { "formatselect" : 1 },
        "imce" : { "imce" : 1 }
      },
      "toolbar_loc" : "top",
      "toolbar_align" : "left",
      "path_loc" : "bottom",
      "resizing" : 1,
      "verify_html" : 1,
      "preformatted" : 0,
      "convert_fonts_to_spans" : 1,
      "remove_linebreaks" : 1,
      "apply_source_formatting" : 0,
      "paste_auto_cleanup_on_paste" : 0,
      "block_formats" : "p,h2,h3,h4,h5,h6",
      "css_setting" : "self",
      "css_path" : "%b%t\\/css\\/editor.css",
      "css_classes" : ""
    },
    "rdf_mapping" : []
  }');
  return $items;
}
