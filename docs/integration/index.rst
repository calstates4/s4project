===================================================
Integrating S4 with your Student Information System
===================================================

S4 uses Drupal's [Feeds module](http://drupal.org/project/feeds) to integrate with external systems. This gives your campus enormous flexibility when picking integration methods (REST, batch files, direct database connections) and a thoroughly logged and customizable method to bring in both student data as well as course information and migrating site and site staff data from other databases.

The following modules should be downloaded and isntalled if you need them, as S4 does not come wiht all methods of pulling data from external systems:

`Feeds SQL <http://drupal.org/project/feeds_sql>`_
--------------------------------------------------
Allows feeds to pull data from external database queries. All your database connection information is stored in non-readable config files for maximum security. To add a database to your site, edit the ``settings.php`` file located in the ``sites/default`` directory. The configuration is standard PHP Data Object (PDO) drivers, so you should consult the options for the database you're connecting to. Depending on your server environment, you might need to install the PDO driver as an extra, especially for less standard PHP databases like Oracle or MS SQL. `Read more about PDO and connection options <http://php.net/manual/en/pdo.drivers.php>`_.

.. code-block:: php

  $databases['integration']['mysis'] = array(  //Databases are in nested arrays, but we only have one DB for integration
    'driver' => 'mysql',  //The PDO driver to use
    'database' => 'databasename',
    'username' => 'username',
    'password' => 'password',
    'host' => 'localhost',
    'prefix' => 'main_',
    'collation' => 'utf8_general_ci',
  );