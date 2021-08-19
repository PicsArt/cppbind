Configuration
=============

IEGEN's configuration is described in iegen_config.cfg which should be placed under current working directory.
Project's configurations is described in yaml format files which should be placed under source code directories.
In yaml files we define input and output sources as well as to define parameters which will affect on generated results and tool behaviour.

IEGEN's iegen_config.cfg contains the following main sections.

* Application_
* API_
* Log_

Configuration Example
^^^^^^^^^^^^^^^^^^^^^
Let's now go through the sections and config parameters.

.. literalinclude:: /../src/iegen/config/iegen_config.cfg
   :language: ini

.. note::
   If the parameter is missing from your cfg file then IEGEN's default value for that parameter will be used.
   In the above code block you can see all default values for uncommented parameters.
   Parameters which are commented do not have default values.

.. note::
   Keys in sections are case-insensitive and stored in lowercase.

APPLICATION
^^^^^^^^^^^

The APPLICATION section defines parameter's related the whole application.
Let's go over parameters from this section.

  - **custom_config_dir** - Directory containing project's configuration files in yaml format. For more details go to :doc:`Custom type converters </04_advanced_features/01_custom_types>`
  - **context_def_glob**  - Pattern of yaml files where project's configuration is described.
  - **rule** - Here we define jinja templates contexts. If user does not want to generate custom code then there's no need override this parameter.
  - **all_languages** - Supported languages.
  - **all_platforms** - Supported platforms.

API
^^^

  - **parser_start** - Tag in the doxygen comment after which everything is considered as instructions for iegen.

LOG
^^^

  - **log_file** - Log file.
  - **level** - Log level.


Project's configuration like where should be generated output files, what arguments should be passed to parser etc. should be described in yaml
files which path should be defined with **context_def_glob** parameter in iegen_config.cfg file.

Now let's go through the project configuration. User can have a single or multiple configuration files in yaml format spread across the project.
There are five main sections:
 * rules
 * vars
 * var_def
 * dir_vars
 * type_vars

Vars and var_def should be defined only once per project.
Rules can be spread across the project.
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

**Join** and **include** are helper constructs which allow defining configuration in different files and then combining them in a single place.

Configuration is described using variables.
All variables used in configuration are described in **var_def** section.
Here we define what is the type of the variable, where it's allowed to be used etc.
More details on variables definitions here :doc:`Variable Definitions </02_first_steps/05_variable_definitions>`.

In **vars** section we define root level configuration. Here we can have variables that are common for the whole project
and variables that can be overridden per directory or file or even for a piece of code.
