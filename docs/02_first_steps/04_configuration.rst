Configuration
=============

IEGEN configuration is described in iegen_config.cfg file which should be placed under current working directory.
Project configuration is described in yaml format files which should be placed under source code directories.
In yaml files we define input and output sources as well as to define parameters which will affect generated results and tool behaviour.

IEGEN iegen_config.cfg file contains the following main sections.

* Application_
* API_
* Log_

Configuration Example
^^^^^^^^^^^^^^^^^^^^^
Let's now go through the sections and config parameters.

.. literalinclude:: /../src/iegen/config/iegen_config.cfg
   :language: ini

.. note::
   If the parameter is missing from your cfg file then IEGEN default value for that parameter will be used.
   In the above code block you can see all default values for uncommented parameters.
   Parameters which are commented do not have default values.

.. note::
   Keys in sections are case-insensitive and stored lowercase.

APPLICATION
^^^^^^^^^^^

The APPLICATION section defines parameters related the whole application.
Let's go over parameters from this section.

  - **custom_config_dir** - Directory containing project configuration files in yaml format. For more details go to :doc:`Custom type converters </04_advanced_features/01_custom_types>`
  - **context_def_glob**  - Pattern of yaml files where project configuration is described.
  - **rule** - Here we define jinja templates contexts. If user does not want to generate custom code then there's no need to override this parameter.
  - **all_languages** - List of supported languages.
  - **all_platforms** - List of supported platforms.
  - | **error_limit** - Amount of errors after which we need to stop application and report about critical error. Default value is -1, which means we continue when encountering not critical errors and report about all errors.
    | This parameter can be set also from command line (--error-limit).

API
^^^

  - **parser_start** - Tag in the doxygen comment after which everything is considered as instructions for iegen.

LOG
^^^

  - **log_file** - Log file.
  - **level** - Log level.

Log level can be set/modified from command line arguments. **--log-level** option can be used to set desirable log level from possible 5 values:
DEBUG, INFO, WARNING, ERROR, CRITICAL.

Project configuration like where should be generated output files, what arguments should be passed to parse, etc., should be described in yaml
files which path should be defined with **context_def_glob** parameter in iegen_config.cfg file.

Now let's go through the project configuration. User can have a single or multiple configuration files in yaml format spread across the project.
There are five main sections:

* vars

* var_def

* rules

* dir_vars

* file_vars

* type_vars

**vars** and **var_def** sections should be defined only once per project.
**rules** sections can be spread across the project. We merge them together by platform and language specifications.
To generate initial configuration run `iegen init` under project directory.
This will create `iegen.yaml` file containing the initial config example.


Rules contain code snippets, actions, type converter snippets.
This is the minimal rules configuration that each project should have:

.. code-block:: yaml

    rules:
      kotlin.code_snippets:
        !join
        - !include kotlin/code_snippets.yaml
      python.code_snippets:
        !join
        - !include python/code_snippets.yaml
      swift.code_snippets:
        !join
        - !include swift/code_snippets.yaml

      kotlin.type_converters:
        !join
        - !include "kotlin/*_types.yaml"
      python.type_converters:
        !join
        - !include "python/*_types.yaml"
      swift.type_converters:
        !join
        - !include "swift/*_types.yaml"

      kotlin.actions:
        !join
        - !include kotlin/actions.yaml
      python.actions:
        !join
        - !include python/actions.yaml
      swift.actions:
        !join
        - !include swift/actions.yaml

**Join** and **include** are helper constructs which allow to define configuration in different files and then combine them in a single place.

Configuration is described using variables.
All variables used in configuration are described in **var_def** section.
Here we define the types of variables, where they are allowed to be used, etc.
More details on variables definitions you can find :doc:`here </02_first_steps/05_variable_definitions>`.

In **vars** section we define root level configuration. Here we can have variables that are common for the whole project
and variables that can be overridden per directory or per file or even for a piece of code.

**dir_vars** section is used to define API annotations for specific directories. Here is an example:

.. code-block:: yaml

    dir_vars:
      - dir: "path_of_dir"
        vars:
          python.action: gen_package
          name: simple

In this example `dir_vars` section is used to generate package for given directory. Path of directory must be provided via **dir** key.
We support two types of directory paths: if the path starts with "/" root sign, then the path is relative to the current working directory. Otherwise the path
is being considered as relative to the directory where the config file of annotations is located.
**vars** subsection is used to define annotations.

Similar to `dir_vars` we also have **file_vars** section to define API for specific files. The usage and definition are the same as for directories.
To define file path user need to use **file** key:

.. code-block:: yaml

    file_vars:
      - file: "path_of_file"
        vars:
          python.code_fragment: fragment_of_some_code

**type_vars** section is designed to give the user opportunity to describe API annotations outside of the source file.
The main use case of this feature is when the user cannot write annotations in source file (desired type is located in a standard header or a third party lib file).
Iegen uses this feature to define binding rules for std exceptions to generate corresponding bindings for target language. This is described :doc:`here </03_get_started/05_exception_handling>`.
To define API annotations we need to use **type** key.

.. code-block:: yaml

    type_vars:
      - type: "NamespaceExample::ClassExample::methodExample(int)"
        vars:
          action: gen_method
          throws: no_throw

      - type: NamespaceExample
        ::
        - type: ClassExample
          ::
          - type: "anotherMethodExample(std::string)"
            vars:
              action: gen_method
              throws: no_throw

In front of `type` key we must specify the member (class, struct, method, property, etc.) for which we are going to define API.
It must be the c++ correct spelling of the member separated by :: symbols. We have two ways to specify the type. Either we use the full spelling
or we use nested structure. In the first example our member is a method called `methodExample` with one `int` argument which is a member function of
`ClassExample` class defined inside `NamespaceExample` namespace. The second example is the definition of another method, where we use nested form
of definition. :: symbols are used here as a sign of sub section.

.. note::
   Since different **type_vars**/**dir_vars**/**file_vars** sections are being processed and merged with each other user must have single definition for the same member/type, otherwise
   iegen reports merge conflict. This constraint is related to nested structures also in case of `type_vars` section. For the same annotation
   user should have only one type of definition: either with full spelling or with nested structure.
