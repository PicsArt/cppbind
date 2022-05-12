Generation instructions
^^^^^^^^^^^^^^^^^^^^^^^

CppBind uses doxygen comments for defining API for the given entity.
CppBind API must contain **__API__** tag. Everything after **__API__** are instructions for CppBind.
For defining an API we use variables from :doc:`Variable Definitions </05_detailed_info/03_var_def>`.
CppBind uses them to know what should be generated, where the generated files should be saved, etc.
**__API__** comments should be written in yaml format, otherwise CppBind will complain about wrong format.
Jinja expressions, predefined system variables can be used here. Available system variables are described :doc:`here </05_detailed_info/03_var_def>`.

.. note::
    **__API__** tag can be overridden in **cppbind_config.cfg** application config file. To do that set **parser_start** property in **[API]** section.

**action** variable is used to define what should be generated in the target code.
If it's missing then nothing will be generated.
It can be skipped when we don't want to generate anything but we want to define some inheritable variables to pass them to children entities.
For example, we can define **package** variable for a directory and the files under that directory can use or override it.

Supported values for **action** are the following ones:

* **gen_class** - Used to generate a class/struct.

* **gen_interface** - For the languages which do not support multiple inheritance this action can be used to generate interfaces. For more details see: :ref:`multiple-inheritance-label`.

* **gen_enum** - Used to generate enums.

* **gen_constructor** - Used to generate constructors.

* **gen_method** - Used to generate regular methods.

* **gen_function** - Used to generate regular functions.

* **gen_getter** - Used to generate a getter method.

* **gen_setter** - Used to generate a setter. Important thing here is that setter is parsed alongside with getter. If no getter is provided then nothing will be generated.

* **gen_property_getter** - Used to generate a getter for public member.

* **gen_property_setter** - Used to generate both setter and getter for a public member.

* | **gen_package** - Used to generate a package for Python bindings. This action can be attached to a directory and CppBind will
                      generate **__init__.py** file in that directory, thus making a Python package. This can be used to add some imports
                      and custom code fragments in **__init__.py** file. This action is ignored for other languages.


Everything above __API__ tag is considered as a pure comment which is present in generated target language bindings.

.. note::
    Getters/setters are regular methods in C++, but they may be transferred into properties for target language.

.. note::
    If you tag only a getter, then only a property with getter will be generated.
    But if you tag only a setter, then nothing will be generated.
    If you want to bind only a setter then use **action: gen_method** instead to generate a regular method.

.. note::
    CppBind uses some patterns to search for a corresponding setter for getter to generate them together if both are
    exposed(i.e. they are tagged as **action: gen_getter** and **action: gen_setter**).
    For example, for **getProp** CppBind searches a method named **setProp** or **set_prop**. To find setter for **get_some_prop** CppBind
    will search for **set_some_prop** or **setSomeProp**. And for **prop** it will search for **setProp** or **set_prop**.
