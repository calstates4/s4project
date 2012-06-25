===========
Updating S4
===========

S4 has regular updates to cover bug fixes and add new features. Updates within major versions (see :ref:`versioning`) require a simple installation process, while major versions may require more work. Since S4 is still within the 1.0 branch, we cannot offer more information on major branch updates untill a roadmap for 2.0 is created.

Upgrades to S4 are very similar to the standard `Drupal upgrade process <http://drupal.org/upgrade/>`_, namely:

1. Go to ``admin/config/development/maintenance`` and put the site into maintenance mode.
2. `Backup your site's files and database <http://drupal.org/node/22281>`_.
3. Copy the contents from the new version of S4 into your installation of S4, making sure to **not replace your existing "sites" folder**.
4. Visit http://mysite.edu/update.php and update S4.
5. If everything looks good, take the site out of maintenance mode.

.. _versioning:

S4 Version numbers
=============

S4 follows a standard versioning process, which consists of [major].[minor]-[extra] formats (for example, 1.0-beta2, or 1.3). Changes to numbers mean the following:

1. **Major** - A change in major versions means that backwards-compatability may be broken, although we will try to prevent this as much as possible. Major revision changes may introduce changes in user interface which require extra user training or documentation, and may change or add new features.
2. **Minor** - A bug fix which does not change the experience of users or alters the way S4 is intended to work.
3. **Extra** - Notation showing if this release is in beta, or is in "release candidate" state. These will usually be found on new major versions, rather than minor releases.