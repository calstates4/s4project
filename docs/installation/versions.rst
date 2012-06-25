.. _versioning:

=============
S4 Versioning
=============

S4 follows a standard versioning process, which consists of [major].[minor]-[extra] formats (for example, 1.0-beta2, or 1.3). Changes to numbers mean the following:

1. **Major** - A change in major versions means that backwards-compatability may be broken, although we will try to prevent this as much as possible. Major revision changes may introduce changes in user interface which require extra user training or documentation, and may change or add new features.
2. **Minor** - A bug fix which does not change the experience of users or alters the way S4 is intended to work.
3. **Extra** - Notation showing if this release is in beta, or is in "release candidate" state. These will usually be found on new major versions, rather than minor releases.