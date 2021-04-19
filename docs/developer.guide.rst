User Guide
==========

Usage
^^^^^

Iegen uses comments to generate the target code. Classes, structs, enums, methods, getters/setters and properties should be commented to be parsed.
Iegen uses comment starting from **__API__** keyword code generation. This keyword can be overridden in iegen_config.cfg file. To do that add **[API]** section with **parser_start** option.
Everything above __API__ comment is considered as a pure comment for the target code.
API comment should contain **gen** attribute to indicate whether the target is a class, struct, enum, method, getter/setter or a property.
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

Values which are using curly braces are system variables generated at runtime.

Each attribute has the following properties.

* **inheritable** indicates whether attribute is inherited from it's parent or no,
* **default** indicates the default value,
* **allowed_on** indicates on which units the attribute is allowed to be used,
* **array** indicates if attribute can be used for multiple times or no




.. literalinclude:: /examples/python/src/enums/color_pygen.py
   :language: python

