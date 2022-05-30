Generation instructions
^^^^^^^^^^^^^^^^^^^^^^^

CppBind uses doxygen style comments for defining API for the given entity.
CppBind API must contain **__API__** tag. Everything after **__API__** are instructions for CppBind.
For defining an API we use variables from :doc:`Variable Definitions </05_detailed_info/03_var_def>`.
CppBind uses them to know what should be generated, where the generated files should be saved, etc.
**__API__** comments should be written in yaml format. Otherwise, CppBind complains about the wrong format.
Jinja expressions and predefined system variables can be used here. Available system variables are described :doc:`here </05_detailed_info/03_var_def>`.

.. note::
    **__API__** tag can be overridden in **cppbind_config.cfg** application config file. To do that set **parser_start** property in **[API]** section.

**action** variable defines what should be generated in the target code.
If it's missing then nothing is generated.
It can be skipped when the user doesn't want to generate anything but want to define inheritable variables to pass them to children entities.
For example, we can define the **package** variable for a directory, and the files under that directory can use or override it.

Supported values for **action** are the following ones:

* **gen_class** - used to generate a class/struct.

* **gen_interface** - generate interfaces for the languages that do not support multiple inheritance. For more details see: :ref:`multiple-inheritance-label`.

* **gen_enum** - used to generate enums.

* **gen_constructor** - used to generate constructors.

* **gen_method** - used to generate regular methods.

* **gen_function** - used to generate regular functions.

* **gen_getter** - used to generate a getter method.

* **gen_setter** - used to generate a setter. The important thing here is that setter is parsed alongside with getter. If no getter is provided, then nothing is generated.

* **gen_property_getter** - used to generate a getter for public member.

* **gen_property_setter** - used to generate both setter and getter for a public member.

* | **gen_package** - used to generate a package for Python bindings. This action can be attached to a directory, and CppBind
                      generates a **__init__.py** file, making that directory a Python package. This can be used to add some imports
                      and custom code fragments in the **__init__.py** file. This action is ignored in other languages.


Everything above the __API__ tag is considered a pure comment present in generated target language bindings.

.. note::
    Getters/setters are regular methods in C++, but they may be transferred into properties for the target language.

.. note::
    If you tag only a getter, then only a property with a getter is generated.
    But if you tag only a setter, then nothing is generated.
    If you want to bind only a setter, use **action: gen_method** instead to generate a regular method.

.. note::
    CppBind uses some patterns to search for a corresponding setter for getter to generate them together if both are
    exposed(i.e. they are tagged as **action: gen_getter** and **action: gen_setter**).
    For example, for **getProp** CppBind searches a method named **setProp** or **set_prop**. To find setter for **get_some_prop**, CppBind
    searches **set_some_prop** or **setSomeProp**. And for **prop** it searches **setProp** or **set_prop**.
