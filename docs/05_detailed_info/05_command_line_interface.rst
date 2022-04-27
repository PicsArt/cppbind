Command line interface
======================
IEGEN provides command line interface for running and configuration. To see the list of available commands use ``iegen --help``.

.. code-block:: none

    iegen --help
    usage: iegen [-h] {clean,init,run} ...

    These are common IEGEN commands:

    positional arguments:
      {clean,init,run}
        clean           Clean all iegen generated files from directory.
        init            Creates an initial config file in current directory.
        run             Run iegen to generate code for given languages.

    optional arguments:
      -h, --help        show this help message and exit


iegen init
^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    iegen init

IEGEN's command line interface(CLI) allows us to create an initial config file in current directory.
To generate initial configuration run ``iegen init`` under project directory.
This will create ``iegen.yaml`` file containing the initial config example.

.. literalinclude:: /../src/iegen/config/iegen.yaml
   :language: yaml

iegen run
^^^^^^^^^

.. code-block:: bash

    iegen run <language_list>

In order to generate the bindings use the ``iegen run`` command by providing one or more supported languages.

.. code-block:: bash

    iegen run kotlin swift python


**Optional arguments:**

.. code-block:: bash

  --log-level {DEBUG,INFO,WARNING,ERROR,CRITICAL}
                    Option can be used to set desirable log level from possible 5 values.

  --error-limit ERROR_LIMIT
                    Amount of errors after which IEGEN stops the execution and reports an error.
                    Default value is -1, which means IEGEN skips all noncritical errors and only
                    after the execution reports about all encountered errors.

  --out_prj_dir OUT_PRJ_DIR
                    Root directory of project output.
                    All includes and imports will be generated relative to this directory.

  --cxx_out_dir CXX_OUT_DIR
                    Root directory where all C bindings will be stored.

  --out_dir OUT_DIR
                    Directory where generated target language files will be saved.

  --cxx_base_out_dir CXX_BASE_OUT_DIR
                    The directory where IEGEN helper types are being copied.
                    If user does not want to use IEGEN base classes then there's no need to specify this variable.

  --target_arch TARGET_ARCH
                    Variable for setting target architecture.

.. note::
        Most of the optional arguments are command line level IEGEN variables. For more info see ``cmd_line`` in :ref:`var-def-label`



iegen clean
^^^^^^^^^^^^^^^^^^^^^

In order to clean all generated files from the given directory use this command.

.. code-block:: bash

    iegen clean <dir>

.. note::
    | *iegen clean* works by finding and removing all files that contain the IEGEN banner logo.
    | Make sure not to remove banner logos from the generated files.
