User Guide
==========

Configuration
^^^^^^^^^^^^^

Iegen's configuration is described in iegen_config.cfg file which should be placed under current working directory.
It has a DEFAULT section which options are common for all languages and each language can override them.
Here is an example of configuration file\ :

.. code-block::

    [DEFAULT]
      out_prj_dir=/path/to/output/
      cxx_base_out_dir=%(source_dir)s/out/
      source_dir = ./source/
      src_glob = *.h*
      run_dir = package_name
      include_dirs = /path/to/some/sources/, /path/to/jni

    [KOTLIN]
      package_prefix = com.company.package
      clang_args = -D__ANDROID__
      out_src_dir = source/main/java/
      out_dir = %(out_prj_dir)s/%(run_dir)s/android/%(run_dir)s/%(out_src_dir)s

    [LOG]
      log_file =
      level = INFO

**DEFAULT**
  * **out_prj_dir** - Root directory where output files will be saved.
  * **cxx_base_out_dir** - Base classes will be copied into this directory, they can be used by source classes. An example of base class is the Object class.
  * **source_dir** - Directory containing source files which are going to be processed.
  * **src_glob** - File pattern used to find files from source_dir.
  * **include_dirs** - Directories which contain sources that are used by the files to be processed.
  * **run_dir** - This can be used in out_dir.

**KOTLIN**
  * **package_prefix** - Package name for generated kotlin files.
  * **clang_args** - Arguments passed to clang parser.
  * **out_src_dir** - Source directory used as a part of out_dir.
  * **out_dir** - Full directory where output files will be saved.

**LOG**
  * **log_file** - If no file specified then the logs will be redirected to stdout.
  * **log_level** - INFO, DEBUG, etc.

Usage
^^^^^

After adding configuration file run iegen command to get base classes copied. The example is for kotlin language.

  .. code-block::

     iegen kotlin

Iegen uses comments to parse the source files. Namespaces, classes, structs, enums, methods, getters and setters should be commented to be parsed.
Iegen uses comment starting from **__API__** keyword to generate the target code. This keyword can be overridden in iegen_config.cfg file. To do that add **[API]** section with **parser_start** option.
Everything above __API__ comment is considered as a pure comment for the target code.
API comment should contain **gen** attribute to indicate whether the target is namespace, class, struct, enum, method, getter or setter.
It can contain other attributes which are not required and have default values.
The list of attributes is:

.. code-block::

    file:
      inheritable: true
      default: '{file_name}'
      allowed_on: [ class, struct, namespace, enum ]

    file_full_name:
      inheritable: true
      default: '{file_full_name}'
      allowed_on: [ class, struct, namespace, enum ]

    module:
      inheritable: false
      default: '{module_name}'
      allowed_on: [ class, struct, namespace, enum ]

    package:
      inheritable: true
      default: 'undefined'
      allowed_on: [ class, struct, namespace, enum ]

    name:
      inheritable: false
      default: '{object_name}'

    include:
      inheritable: true
      array: true
      default: [ ]
      allowed_on: [ namespace ]

    shared_ref:
      inheritable: true
      default: false
      allowed_on: [ class, struct ]

* **file** - File name for the generated file. If not specified then the actual file name will be used.
* **file_full_name** - If not specified then the original file's absolute path is taken.
* **module** - Module's name. This attribute is not used for kotlin.
* **package** - Package name which with **package_prefix** from iegen_config.cfg file is used for the final package ({package_prefix}.{package}).
* **name** - Name of the class, namespace etc. If not specified then the actual name will be used.
* **include** - Additional includes that will be added to the generated file.
* **shared_ref** - If true creates a shared pointer instance.

Values which are using curly braces are generated at runtime.

* **inheritable** indicates whether attribute is inherited from it's parent or no,
* **default** indicates the default value,
* **allowed_on** indicates on which units the attribute is allowed to be used,
* **array** indicates if attribute can be used for multiple times or no

The following is an example of commented source file.

  .. code-block::

     #include<string>

     /*
     * comments
     *
     * __API__
     * kotlin.file: utils
     * kotlin.prefix: PI
     */
     namespace pi::utils {
       /**
        * commants
        *
        * __API__
        * gen: class
        * shared_ref: False
        * kotlin.module: pi.xxx.Example
        */
       struct Example
       {
           /**
            * comments
            *
            * __API__
            * gen: enum
            * swift.name: ExampleType
            */
           enum class Type { A, B, C };

           /**
            * comments
            *
            * __API__
            * gen: constructor
            *
            */
           Example(int& x, std::string name = "XXX");

           /**
            * comments
            *
            * __API__
            * gen: method
            */
           Type f(Type t, int i =10, const char* test = "XXX");

           /**
            * comments
            *
            * __API__
            * gen: method
            */
           int get_attribute(const char* test = "XXX");
       };
       /**
        * comments
        *
        * __API__
        * gen: enum
        * swift.name: ExampleType
        */
       enum class Type2 { A2, B2, C2 };
     }

You can provide a language before the attribute, in this case the value will be used only for that language.

