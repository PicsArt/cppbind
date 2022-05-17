Application configuration
^^^^^^^^^^^^^^^^^^^^^^^^^

CppBind application configuration is done via **cppbind_config.cfg** file which can be placed under the project root directory.
If there is no user-provided application config file then CppBind will use the default one:

.. literalinclude:: /../src/cppbind/config/cppbind_config.cfg
   :language: ini

Application config file contains the following main sections:

* Application_
* API_
* Log_

.. note::
   If the parameter is missing from application config file then CppBind default value for that parameter will be used.
   In the above code block you can see all default values for uncommented parameters.
   Parameters which are commented do not have default values.

.. note::
   Keys in sections are case-insensitive and stored lowercase.

APPLICATION
-----------

The APPLICATION section defines parameters related to the whole application.
Let's go over parameters from this section:

- **custom_config_dir** - Directory containing user-defined type converter yaml files. For more details go to :doc:`Custom type converters </04_advanced_features/02_custom_types>`.
- **context_def_glob** - Glob pattern of project configuration yaml files.
- **rule** - Python module which defines jinja template contexts. If user does not want to generate custom code then there's no need to override this parameter.
- **all_languages** - List of supported languages.
- **all_platforms** - List of supported platforms.
- | **error_limit** - Amount of errors after which CppBind stops the execution and reports an error. Default value is -1, which means CppBind skips all noncritical errors and only after the execution reports about all encountered errors.
  | This parameter can be set also from command line (--error-limit).

API
---

- **parser_start** - Tag in the doxygen comment after which everything is considered as instructions for CppBind.

LOG
---

- **log_file** - Logging file where CppBind logs will be stored. If empty, the standard output is considered.
- **level** - Logging level.

Log level can be set/modified from command line arguments. **--log-level** option can be used to set desirable log level from 5 possible values:
DEBUG, INFO, WARNING, ERROR, CRITICAL.
