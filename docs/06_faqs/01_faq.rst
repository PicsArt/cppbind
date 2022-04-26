Frequently asked questions
^^^^^^^^^^^^^^^^^^^^^^^^^^

Clang not installed issue
=========================

Even after adding libclang path to DYLD_LIBRARY_PATH on macOS you still might face an error saying
``clang dev is not installed. Please read README.md``.

This is due to `SIP <https://support.apple.com/en-us/HT204899>`_.
Make sure python is not under a directory protected by SIP. Probably it's under /usr/bin.
Use /usr/local/bin instead.