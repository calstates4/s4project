===================
System requirements
===================

S4 is built on an open-source web application framework called `Drupal <http://drupal.org>`_, and has the same requirements as outlined on the `Drupal system requirements page <http://drupal.org/requirements>`_.

If you want to use `MS SQL http://drupal.org/project/sqlsrv`_ or `Oracle <http://drupal.org/project/oracle>`_, you can do so by adding additional modules to Drupal. *Caveat emptor:* S4 has not been tested with either MS SQL nor Oracle, although we did follow best practices to ensure these databases will work fine, we cannot make any guarantees about these databases.

However, S4 is a pretty big application, so you should tweak your PHP environment to use at least 85MB of RAM. This is hardly ever reached, but can sometimes happen when importing large numbers of students, for example. `Read about how to increase your memory limit <http://drupal.org/node/29268>`_.