.. _texteditor:
=====================
Text (WYSIWYG) editor
=====================

S4 comes with a What-you-see-is-what-you-get editor pre-installed called TinyMCE. Technical administrators can configure the editor by visiting Admin > Config > Content Authoring > WYSIWYG Profiles or ``admin/config/content/wysiwyg``. There should be a single profile for the Filtered HTML text format (see :ref:`textformats`).

The most common task when editing the WYSIWYG editor is to add or remove buttons from the editor itself. Administrators should note that while you might enable a button to insert a specific HTML tag, the text formats are always run regardless of what buttons you enable or disable (see :ref:`textformats`).