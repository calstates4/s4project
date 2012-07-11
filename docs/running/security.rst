.. _security:

====================
Information security
====================

S4 is built with security and flexible-yet-simple role-based permission system in mind so that department staff can get their jobs done, and IT professionals can sleep well at night.

Role-based security
===================

Like all of Drupal sites (see :ref:`drupal`), S4 has a role-based security model. This means that for each "role," i.e. a "staff" user, has different levels of permissions. Users can have multiple roles, and each role adds new permissions to the user with that role. In short, S4 follows an *additive permission* model, where each role you add to a user adds more permissions.

Technical administrators can manage roles, assign roles to users, and create new roles from the **People** administration page (``admin/people``). S4 comes with a pre-defined set of roles:

* **administrator** - The technical admin, this role can do anything on the system.
* **staff** - A department staff, like a program manager for a Service Learning department, or administrative assistant in an internship program.
* **site approver** - Someone who's job it is to approve or not approve pending sites, but who cannot view students and courses.
* **manager** - A user who can add or remove roles to other users.

Each of these role's permissions can be viewed from ``people/permissions/roles``, where you can also add or remove roles.

Important permissions
---------------------

There are literally hundreds of kinds of permissions available in S4, and most of them are pretty self-explanatory, but a few should be kept an eye on when you are setting up a role:


Text formats
============

S4 filters input from users, including administrators and site staff, to make sure that they cannot inject cross-site scripts into content, and to make sure that your HTML is nice and clean. This is also helpful when users are trying to change fonts, or do other things that would make the site's experience inconsistent. While whatever a user enters in a form is stored as is (with things like SQL injection escaped, of course), it is filtered when it is displayed, meaning if someone types in something that is not allowed, but a filter is changed to allow it, that information will become immediately available.

Technical administrators can find input filters under Admin > Configuration > Content Authoring > Text formats or at ``admin/config/content/formats``. S4 comes with two default formats, **Full HTML** and **Filtered HTML**. Only techincal administrators can use Full HTML, and everyone else is limited to using Filtered HTML. There are two other default formats that should be left alone and are not editable, Plain text and Display Suite code.

You can edit the Filtered HTML format and change the allowed tags by clicking edit and scrolling down to the **Filter settings** area of the form. By default, Filtered HTML only allows the following tags::

  <a> <p> <br> <em> <strong> <img> <h2> <h3> <h4> <h5> <h6> <blockquote> <ul> <ol> <li> <dl> <dt> <dd>


You can add other tags to this list if your users need them, but even if you add the ``<script>`` tag, it will be cleaned for cross-site scripts. Note also that even if you add a tag to the list, most users will also need their WYSIWYG editor tweaked to add that corresponding feature (see :ref:`texteditor`).

Other things to watch out for
=============================

S4 comes with a very secure default set of permissions, but if you are a technical administrator, there are some things that you should definately *not* do:

* **Enabling the PHP filter module** - Because S4 is built on Drupal, there are some modules that are shipped with the project which are not needed by the project and are disabled. You can find modules at ``admin/modules``. PHP filter can be a useful module in some sites, but should be left disabled on your S4 site.