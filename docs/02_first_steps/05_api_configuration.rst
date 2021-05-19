API attributes
^^^^^^^^^^^^^^

Iegen uses doxygen comments for processing. If the comment contains **__API__** tag then it will pe parsed by iegen.
**__API__** comment should be of yaml format, otherwise an error will be thrown and should contain **gen** instruction.
Everything coming after **__API__** except **gen** are called attributes.
Attributes are instructions on how target code should be generated.

.. note::
    **__API__** tag can be overridden in iegen_config.cfg file. To do that declare **parser_start** property in **[API]** section.

Everything above __API__ tag is considered as a pure comment.
**gen** instruction is mandatory and is used to identify what should be generated:

    *  **gen: class** is used to generate a simple class/struct which is not used as a base for multiple inheritance.

    *  **gen: interface** is used if the target class/struct is a base for another type which is multi base or if the target class/struct is inherited from another type which is marked as **gen: interface**.

    * **gen: enum** is used to generate enums.

    * **gen: constructor** is used to generate constructors.

    * **gen: method** is to generate regular methods.

    * **gen: getter** is used to generate getter method.

    * **gen: setter** is for setter method. Important thing here is that setter is parsed along side with getter. If no getter is provided then nothing will be generated.

    * **gen: property_getter** is used to generate a getter for public member.

    * **gen: property_setter** is to generate both setter and getter for a public member.

.. note::
    Getters/setters are regular methods in c++, but they may be parsed into properties for target language.

.. note::
    You tag only getter tagged, in this case only a property with getter will be generated.
    But you can't tag only setter. In this case nothing will be generated.
    If you want to bind only setter the use **gen: method** instead to generate a regular method.

.. note::
    Iegen uses patterns to find corresponding setter for getter to generate them together if both are
    exposed(i.e are tagged as **gen: getter** and **gen: setter**).
    For **getProp** it searches method named **setProp** or **set_prop**. To find setter for **get_some_prop** it
    will search for **set_some_prop** or **setSomeProp**. And for **prop** it will search for **setProp** or **set_prop**.

Let's now go through the list of attributes.

.. literalinclude:: /../src/iegen/config/attributes.yaml
   :language: yaml

* **file** - File name of the generated file. If not specified then the original file name will be used.
* **file_full_name** - If not specified then the original file's absolute path is taken.
* **package** - Package name which with **package_prefix** from iegen_config.cfg file is used for the final package ({package_prefix}.{package}).
* **name** - Name of the class, method etc. If not specified then the original name is used.
* **include** - Additional includes that will be added to the generated file.
* **shared_ref** - This attribute is to manage how the object will be hold. If false then the generated wrapper will create a regular pointer otherwise it a shared pointer.

Values which are using curly braces are system variables generated at runtime.

If attribute is not specified then the default value is used for all languages.
There are cases when attribute values may differ for each language.
For this we can prefix attribute with the language:

.. code-block:: yaml

    package: examples.hello
    kotlin.package: com.examples.hello

In this case iegen will use com.examples.hello for kotlin and examples.hello for all other target languages.

Each attribute has the following properties.

* **inheritable** indicates whether attribute is inherited from it's parent or no,
* **default** indicates the default value,
* **allowed_on** indicates on which parts the attribute is allowed to be used,
* **required_on** indicates on which parts the attribute is required,
* **array** indicates if attribute can be used for multiple times or no
* **type** is the type of attribute's value. The default type is string. Other supported types bool and dict.
