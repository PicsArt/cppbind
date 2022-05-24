Command line interface
======================
CppBind provides a command-line interface for running and configuration. To see the list of available commands, use ``cppbind --help``.

cppbind init
^^^^^^^^^^^^

.. code-block:: bash

    cppbind init

CppBind's command-line interface(CLI) allows us to create an initial config file in the current directory.
To generate the initial configuration, run ``cppbind init`` under the project directory.
This creates ``cppbind.yaml`` file containing the initial config example.

.. literalinclude:: /../src/cppbind/config/cppbind.yaml
   :language: yaml

.. note::
        | If you are using Windows please make sure to set standard library include path in
        | **win.include_dirs**:
        |   - C:/mingw64/lib/clang/14.0.1/include



cppbind run
^^^^^^^^^^^

.. code-block:: bash

    cppbind run <language_list>

To generate the bindings, use the ``cppbind run`` command by providing one or more supported languages.

.. code-block:: bash

    cppbind run kotlin swift python


**Optional arguments:**

.. code-block:: text

  --log-level {DEBUG,INFO,WARNING,ERROR,CRITICAL}
                    The option can set a desirable log level from possible 5 values.

  --error-limit ERROR_LIMIT
                    Amount of errors, after which CppBind stops the execution and reports an error.
                    The default value is -1, which means CppBind skips all noncritical errors and only
                    after the execution reports all encountered errors.

  --out_prj_dir OUT_PRJ_DIR
                    The root directory of project output.
                    All includes and imports are generated relative to this directory.

  --cxx_out_dir CXX_OUT_DIR
                    The root directory where all C bindings are stored.

  --out_dir OUT_DIR
                    Directory where generated target language files are saved.

  --cxx_base_out_dir CXX_BASE_OUT_DIR
                    The directory where CppBind helper types are being copied.
                    If the user does not want to use CppBind base classes, there's no need to specify this variable.

  --target_arch TARGET_ARCH
                    Variable for setting target architecture.

.. note::
        Most of the optional arguments are command-line level CppBind variables. For more info see ``cmd_line`` in :ref:`var-def-label`



cppbind clean
^^^^^^^^^^^^^

To clean all generated files from the given directory, use this command.

.. code-block:: bash

    cppbind clean <dir>

.. note::
    | ``cppbind clean`` works by finding and removing all files that contain the CppBind banner logo.
    | Make sure not to remove banner logos from the generated files.
