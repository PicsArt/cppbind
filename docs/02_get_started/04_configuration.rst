Configuration
=============

IEGEN's configuration is described in iegen_config.cfg file which should be placed under current working directory.
Configuration is used to define input and output sources as well as to define parameters which will affect on generated results and tool behaviour.
Configuration has following main sections. 

* Default_
* `Language section`_
* Logging_


Configuration Example
^^^^^^^^^^^^^^^^^^^^^
Lets take a look on following example of configure and go thought sections and parameters.

.. code-block:: ini

    [DEFAULT]
      src_glob = ./source/*.h*
      include_dirs = /path/to/other/sources/
      out_prj_dir =/path/to/output/
      out_dir = %(out_prj_dir)s%/bindings/

    [KOTLIN]
      clang_args = -D__ANDROID__
      include_dirs = /path/to/other/sources/,/path/to/jni
      out_src_dir = source/main/java/
      out_dir = %(out_prj_dir)s/android/%(out_src_dir)s

    [LOG]
      log_file =
      level = INFO

.. note::
   If required parameter is missing from your configuration IEGEN default value for that parameter will be used.

.. note::
   Keys in sections are case-insensitive and stored in lowercase.

.. note::
   You can define your own parameter that can be used within config. E.g. out_src_dir is not required, it's just used in the configuration.

Default
^^^^^^^

The DEFAULT section defines parameter's default values for all languages. Each language can override them if necessary.
Let's go over parameters used in example above.

**Common parameters**
  * **src_glob** - File pattern used to find source files that are going to be processed by IEGEN.
  * **include_dirs** - Directories which contain sources that are used by the files to be processed.
  * **out_prj_dir** - Root directory of your output project. All includes and imports will be generated relative to this directory.
  * **out_dir** - Root directory where all generated files will be placed.

For list of all parameters please see `All Configuration Parameters`_


Language section
^^^^^^^^^^^^^^^^

The language section is starting by language name for example [KOTLIN] and it can be used to set/override parameters to
better feet for the target. For example, you might want to generate Kotlin bindings in a specific folder or
define precompiler parameters to enable or disable some features, use different include sources and so on.

Let's go through [KOTLIN] section above and see what it does.

**KOTLIN**
  * **clang_args** - Arguments passed to clang parser. We are defining *__ANDROID__* to have code used for android only as well.
  * **include_dirs** - Directories which contain sources that are used by the files to be processed. We have added jni directory as well.
  * **out_src_dir** - Source directory used as a part of out_dir.
  * **out_dir** - Full directory where output files will be saved. For Kotlin we have changed it and now it depends on other parameters.

Logging
^^^^^^^
The section used to enable disable and control logging of the tool.

**LOG**
  * **log_file** - If no file specified then the logs will be redirected to stdout.
  * **log_level** - INFO, DEBUG, etc.



All Configuration Parameters
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

As we've seen above each parameter(if not a user defined) in configuration file has a default value, which is used if user does not override it.
Let's take a look at iegen's default configuration:

.. literalinclude:: /../src/iegen/config/iegen_config.cfg
   :language: ini

Let's go section by section.

#. **[DEFAULT]**. As we already know this section describes default parameters for all languages. Let's go through them.

    - **out_prj_dir = wr_out/** - Root directory of your output project. All includes and imports will be generated relative to this directory.

    - **run_dir = example_lib** - Helper parameter used in other parameters. Users also can have their custom parameters to use within the config file.

    - **common_helpers_dir = std_helpers/** - This directory contains iegen's standard helper files per language.

    - **cxx_helpers_dir = %(common_helpers_dir)scxx/** - This is iegen's c++ helpers directory. Might be different per language.

    - **cxx_out_dir = %(out_prj_dir)s%(run_dir)s/cxx_out/**  - The directory where all c/c++ wrappers will be generated.

    - **cxx_base_dir = base/**  - Iegen's internal directory containing base classes.

    - **cxx_base_out_dir = ./examples/example_cxx/**  - The directory where iegen's base classes are copied. **NOTE**: This is not a mandatory parameter and it's commented in the default config. If user does not want to use iegen's base classes then there's no need to specify this parameter.

    - **custom_config_dir = /home/iegen_config**  - Directory containing user defined configuration files in yaml format. See section

    - **file_postfix = _gen** - This postfix is appended to each generated file.

    - **src_glob = ./examples1/\*\*/\*.h\*,./examples2/\*\*/\*.h\*** - Source code patterns to be processed.

    - **clang_args = -D__ANDROID__** - Arguments passed to clang parser.

    - **include_dirs = .** - Include directories required for parsing. These directories are passed to clang parser.

    - **src_exclude_glob = ./examples1/\*\*/\*.hpp** - Patterns/files to exclude from processing.


#. **[LANGUAGES]**. Here we define all supported languages.


#. **[KOTLIN]**. Let's go through the parameters from this section that were not defined in the default section. Most likely you won't need to change them if you are not going generate different code with iegen.

    - **snippets = snippets/kotlin/config.yaml** - Code templates that are used by iegen to generate the bindings are described in yaml files using jinja templates syntax. This is the config file that includes all required snippet files.

    - **rule = rules/snippets_kotlin.py** - Here we define jinja templates contexts.

    - **extension = kt** - Target language file extension.

    - **helpers_dir=%(common_helpers_dir)skotlin/** - Directory containing iegen's kotlin helpers.


#. **[PYTHON]**. Let's go through parameters from this section that were not explained in previous sections. These tree attributes explained next are python specific.

    - **helpers_package_prefix = %(package_prefix)s** - This is a path relative to **out_dir** where python helpers from **helpers_dir** are copied.

    - **helpers_include_prefix = %(helpers_package_prefix)s** - The generated python code might be used as a submodule. In this case we have to attach appropriate prefix to helper includes. This parameter is used for this purpose.

    - **pybind_module = example_lib** - For python bindings iegen also generates pybind code. This parameter is used for collecting all pybind modules. For this config iegen will collect all generated pybind code into a package named example_lib.

#. **[SWIFT]**. All parameters from this section we've already discussed.


#. **[API]**.
    - **attributes = attributes.yaml** - This file contains API tags definitions that iegen uses for parsing. For more details please see API Attributes section.
    - **parser_start = __API__** - Tag in the doxygen comment after which everything is considered as instructions for iegen.

#. **[LOG]**. Section containing logging configuration.

