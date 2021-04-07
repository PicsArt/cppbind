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
      cxx_base_out_dir=./source/out
      src_glob = ./source/*.h*
      run_dir = package_name
      custom_config_dir = /home/iegen_config
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

Custom types
^^^^^^^^^^^^

Type conversions are described in yaml config files. There are predefined basic and complex types. User can also have custom types configuration.
The files containing this configuration must be of pattern **\*_types.yaml**  and placed under **custom_config_dir** directory.
Following is an example of converter for std::pair and nlohmann::json from cxx to kotlin and vice versa.

  .. code-block::

    std::pair:
      custom:
        pname: Pair
      kotlin:
        type_info: "Pair<{{args_t[0]}}, {{args_t[1]}}>"
      jni:
        type_info: jobject
      jdk:
        type_info: "Pair<{{args_t[0]}}, {{args_t[1]}}>"
      jni_to_cxx: |
        jclass pairClass = env->FindClass("kotlin/Pair");

        jfieldID firstID = env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
        jfieldID secondID = env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");

        auto firstObject = env->GetObjectField({{name}}, firstID);
        auto secondObject = env->GetObjectField({{name}}, secondID);
        {%- set tmp_first = '_' + target_name %}
        {%- set extract_first = 'iegen::extract{}'.format(args[0].custom.pname) %}
        {%- set extract_second = 'iegen::extract{}'.format(args[1].custom.pname) %}
        auto first = {{extract_first}}(env, firstObject);
        auto second = {{extract_second}}(env, secondObject);
        {{args[0].snippet('first')|indent}}
        {{args[1].snippet('second')|indent}}
        {{cxx_pointee_unqualified_name}} {{target_name}} = std::make_pair({{args[0].converted_name('first')}}, {{args[0].converted_name('second')}})
      cxx_to_jni: |
        {{target_type_name}} {{target_name}} = std::make_pair(f, s);
      kotlin_to_jdk: |
        val first = {{name}}.first
        val second = {{name}}.second
        {{args[0].snippet('first')|indent}}
        {{args[1].snippet('second')|indent}}
        val {{target_name}} = {{target_type_name}}({{args[0].converted_name('first')}}, {{args[0].converted_name('second')}})
      jdk_to_kotlin: |
        val first  = {{name}}.first
        val second  = {{name}}.second
        {{args[0].snippet('first')|indent}}
        {{args[1].snippet('second')|indent}}
        val {{target_name}} = {{target_type_name}}({{args[0].converted_name('first')}}, {{args[0].converted_name('second')}})

    nlohmann::json:
      custom:
        pname: json
      kotlin:
        type_info: JsonObject
      jni:
        type_info: jstring
      jdk:
        type_info: String
      jni_to_cxx: |
        auto {{target_name}} = json::parse(iegen::jni_to_string(env, {{name}}))
      cxx_to_jni: |
        {{target_type_name}} {{target_name}} = iegen::string_to_jni(env, {{name}}.dump(4));
      kotlin_to_jdk:
        val {{target_name}} = {{name}}.toString()
      jdk_to_kotlin: |
        val {{target_name}}: {{target_type_name}} = JsonParser.parseString({{name}}).asJsonObject()


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

