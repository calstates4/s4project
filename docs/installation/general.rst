.. _drupal:

=================================
Securing and scaling your S4 site
=================================

S4 is built on top of `Drupal <http://drupal.org>`_, which already scales to any size well, and has an excellent security track record. While we won't go into specifics in this documentation, here's some resources on securing and scaling your S4 site:

1. `Drupal security advisories <http://drupal.org/security>`_ - All security advisories are rolled into S4 automatically.
2. `Memcached module <http://drupal.org/project/memcache>`_ - A useful module for speeding up your S4 site.
3. `Server tuning considerations <http://drupal.org/node/2601>`_ - Drupal guide to server tuning
4. `Recipes for scaling drupal <http://www.johnandcailin.com/blog/john/scaling-drupal-open-source-infrastructure-high-traffic-drupal-sites>`_ - Good starting blog post for scaling Drupal.
5. `Google analytics module <http://drupal.org/project/google_analytics>`_ - Google Analytics is a useful tool to see how your site is being used, so you can make the best decisions around scaling.

Our own experience with scaling on our campus is that there's a huge difference between the needs of logged-in and logged-out users. Drupal does an excellent job of caching pages for anonymous users, as they always see basically the same kinds of content, but a logged-in user needs custom things like a link to their account, which cannot be cached.

If your site is getting a lot of traffic from anonymous users, adding additional caching like Memcached is helpful. You can also think about using a front-end cache like `Varnish <https://www.varnish-cache.org/>`_.

We cover more about maintaining the security of your S4 site at :ref:`security`.