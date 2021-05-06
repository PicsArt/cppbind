Configuration
=============

Iegen's configuration is described in iegen_config.cfg file which should be placed under current working directory.
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

      src_glob= ./source/*.h*
      include_dirs= /path/to/some/sources/

      out_prj_dir=/path/to/output/
      out_dir = %(out_prj_dir)s%/bindings/

    [KOTLIN]

      clang_args= -D__ANDROID__
      include_dirs= /path/to/some/sources/, /path/to/jni
      run_dir = hellp_user_lib
      out_src_dir= source/main/java/
      out_dir= %(out_prj_dir)s/%(run_dir)s/android/%(run_dir)s/%(out_src_dir)s

    [LOG]

      log_file=
      level= INFO

.. note::
   if requared parameter is missing from your configuration IEGEN defualt value for that parameter will be used.

.. note::
   keys in sections are case-insensitive and stored in lowercase.

.. note::
   you can define your own parameter that can be used within config.

Default
^^^^^^^

The DEFAULT section defines parameter`s default values for all languages. Each language can override them if necessary.
Let`s go over parameters used in example above.

**Common parmanters**
  * **src_glob** - File pattern used to find source files that are going to be processed by IEGEN.
  * **include_dirs** - Directories which contain sources that are used by the files to be processed.
  * **out_prj_dir** - Root directory of your output project. All includes and imports will be generated relative to this directory.
  * **out_dir** - Root directory where all generated files will be placed.


  For list of all parameters please see :ref:`All Configuration Parameters`



Language section
^^^^^^^^^^^^^^^^

The language section is starting by language name for example [KOTLIN] and it can be used to set/override parameters to better feet for the target. For example, you might want to generate Kotilin bindings in a specific folder and or define precompiler parameters to enable or disable some features, use different include sources and so on.

Let`s go through [KOTLIN] section above and see what it does. 

**KOTLIN**
  * **clang_args** - Arguments passed to clang parser. We are defining *__ANDROID__* to have code used for android only as well.
  * **include_dirs** - Directories which contain sources that are used by the files to be processed. We have added jni directory as well.
  * **run_dir** - Source directory used as a part of out_dir.
  * **out_src_dir** - Source directory used as a part of out_dir.
  * **out_dir** - Full directory where output files will be saved. For Kotilin we have changed it and it is now depend form other parameters.

Logging
^^^^^^^
The section used to enable disable and control logging of the tool.

**LOG**
  * **log_file** - If no file specified then the logs will be redirected to stdout.
  * **log_level** - INFO, DEBUG, etc.

