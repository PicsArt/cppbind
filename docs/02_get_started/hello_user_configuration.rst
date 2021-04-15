Configuration For Hello User project
====================================

To get used to IEGEN configuration please read :doc:`Configuration </02_get_started/04_configuration>`
Here we will just show Hello User project configuration.


.. code-block:: ini

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
