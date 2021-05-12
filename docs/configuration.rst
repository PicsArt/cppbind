Configuration
^^^^^^^^^^^^^

Iegen's configuration is described in iegen_config.cfg file which should be placed under current working directory.
It has a DEFAULT section which options are common for all languages and each language can override them.
Here is an example of configuration file\ :

.. code-block::

    [DEFAULT]
      out_prj_dir=/path/to/output/
      cxx_base_out_dir=./source/out
      src_glob = ./source/*.h*
      run_dir = package_name
      custom_config_dir = /home/iegen_config
      include_dirs = /path/to/some/sources/, /path/to/jni

    [KOTLIN]
      package_prefix = com.company.project
      clang_args = -D__ANDROID__
      out_src_dir = source/main/java/
      out_dir = %(out_prj_dir)s/%(run_dir)s/android/%(run_dir)s/%(out_src_dir)s

    [LOG]
      log_file =
      level = INFO

**DEFAULT**
  * **out_prj_dir** - Root directory where output files will be saved.
  * **cxx_base_out_dir** - Base classes will be copied into this directory, they can be used by source classes. An example of base class is the Object class.
  * **src_glob** - File pattern used to find source files.
  * **run_dir** - This can be used in out_dir.
  * **custom_config_dir** - Directory containing custom configuration files. An example is custom types files which will be used for parsing different types from cxx to the target language.

  Check the example :ref:`Custom types`

  * **include_dirs** - Directories which contain sources that are used by the files to be processed.

**KOTLIN**
  * **package_prefix** - Package name for generated kotlin files.
  * **clang_args** - Arguments passed to clang parser.
  * **out_src_dir** - Source directory used as a part of out_dir.
  * **out_dir** - Full directory where output files will be saved.

**LOG**
  * **log_file** - If no file specified then the logs will be redirected to stdout.
  * **log_level** - INFO, DEBUG, etc.

