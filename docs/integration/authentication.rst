===================
User authentication
===================

S4 uses Drupal's modular authentication framework to let users login, you can have multiple authentication methods at the same time, and even indicate different login methods for students, staff, and faculty. 

S4 also includes a generic sign-on system that allows people to login without using your campus' authentication system. This is useful for ad-hoc access, including letting community members login to manage site information.

These modules are not maintined by the S4 project, but we will provide additional documentation on installing and setting these authentication system up, integrating them with your campus.

1. `LDAP <http://drupal.org/project/ldap>`_
2. `Shibboleth <drupal.org/project/shib_auth/>`_
3. `CAS single-signon & SAML <drupal.org/project/cas/>`_

Once you download and install an authentication module (see :ref:`drupal`), follow the module's project page for instructions on installation and setup. Once your authentication module is setup, click the *Site settings* link and then *General configuration*. From here, you can select which form of authentication different kinds of users should be using. 

Make sure that the username returned by any authentication system matches the username your authentication system uses is the same as the username found in the User Importers (see :ref:`user-import`).