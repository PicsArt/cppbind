API configuration
^^^^^^^^^^^^^^^^^

Besides the yaml configuration IEGEN also uses doxygen comments for defining the API for the target code.
If the comment contains **__API__** tag then it'll be parsed by IEGEN. Everything under **__API__** are instructions for IEGEN.
For defining the API we use variables from :doc:`Variable Definitions </02_first_steps/05_variable_definitions>`
IEGEN uses them to know what should be generated, where should be generated etc.
**__API__** comment should be of yaml format, otherwise an error will be thrown.
Jinja expressions, sys variables can be used here.

.. note::
    **__API__** tag can be overridden in iegen_config.cfg file. To do that declare **parser_start** property in **[API]** section.

**action** variable is very important here. It defines what should be generated in the target code.
If it's missing then nothing will be generated.
It can be skipped when we don't want to generate anything but we want to define some inheritable variables to pass them to children.
For examples we can define **package** variable for the directory and files under that directory can use or override it.

Supported values for **action** are the following:

    * **gen_class** - Used to generate a simple class/struct.

    * **gen_interface** - For the languages which do not support multiple inheritance these can be used to generate interfaces. For more details got to :doc:`Variable Definitions </03_get_started/04_inheritance>`.

    * **gen_enum** - Used to generate enums.

    * **gen_constructor** - Used to generate constructors.

    * **gen_method** - Used to generate regular methods.

    * **gen_getter** - Used to generate getter method.

    * **gen_setter** - Used to generate a setter. Important thing here is that setter is parsed along side with getter. If no getter is provided then nothing will be generated.

    * **gen_property_getter** - Used to generate a getter for public member.

    * **gen_property_setter** - Used to generate both setter and getter for a public member.


Everything above __API__ tag is considered as a pure comment.

.. note::
    Getters/setters are regular methods in c++, but they may be parsed into properties for target language.

.. note::
    You tag only getter tagged, in this case only a property with getter will be generated.
    But you can't tag only setter. In this case nothing will be generated.
    If you want to bind only setter the use **action: gen_method** instead to generate a regular method.

.. note::
    IEGEN uses patterns to find corresponding setter for getter to generate them together if both are
    exposed(i.e are tagged as **action: gen_getter** and **action: gen_setter**).
    For **getProp** it searches method named **setProp** or **set_prop**. To find setter for **get_some_prop** it
    will search for **set_some_prop** or **setSomeProp**. And for **prop** it will search for **setProp** or **set_prop**.
