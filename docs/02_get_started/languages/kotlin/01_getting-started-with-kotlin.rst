Binding with Kotlin
===================
This section demonstrates binding examples from simple to more complex cases.

.. _classes-label:

Classes/Structs
^^^^^^^^^^^^^^^
Let's generate a wrapper code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In a code above we are exporting all public methods and constructors.

.. note::
    Notice that the title method is marked as a getter, so it
    will be a read-only property for the target language.

Generated code for kotlin looks as follows.

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/task.kt
   :language: kotlin
   :lines: 6-

Now we are able to use it.

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
   :language: kotlin
   :start-after: [task-usage]
   :end-before: [task-usage]

Let's assume we have another class using the one above.

.. literalinclude:: /../examples/primitives/cxx/simple/project.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are using **include** attribute based on which appropriate import will be generated for
    each target language. In case of kotlin we do not have this attribute, as both wrappers are generated under the same package.

Here is the generated wrapper code for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/project.kt
   :language: kotlin
   :lines: 6-

And the usage example:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
   :language: kotlin
   :start-after: [project-usage]
   :end-before: [project-usage]

Enums
^^^^^

Now let's generate a binding for an enum.
Here is Color enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And the Frame struct using it:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are generating **property_setter** for public field **backgroundColor**.
    A writable property field will correspond to it in kotlin. To generate read-only field we should use **property_getter** instead.

Here is the generated kotlin code for Color:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/color.kt
   :language: kotlin
   :lines: 6-

And for Frame:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/frame.kt
   :language: kotlin
   :lines: 6-

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/main.kt
   :language: kotlin
   :start-after: [color-usage]
   :end-before: [color-usage]


Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's now bind struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


As you can see overloaded or static methods are like regular methods. There's nothing special to add in the **API** for them.

Here is the wrapper for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
   :language: kotlin
   :lines: 6-

We are ready to use it:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
   :language: kotlin
   :start-after: [overload-usage]
   :end-before: [overload-usage]

Inheritance
^^^^^^^^^^^

This section covers single and multiple inheritance.

Single Inheritance
~~~~~~~~~~~~~~~~~~

Assume we have two types **Bicycle** inherited from **Vehicle**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/vehicle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/bicycle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    For both classes we have used the same value for **shared_ref** attribute.
    This is mandatory. This attribute should be the same in type hierarchy.

.. note::
    Currently iegen supports inheritance with polymorphic types only.

.. note::
    If the type which is being parsed is inherited from another one which does not have an **__API__** i.e is not parsed
    by iegen then in the wrapper code it won't appear as a base type for the target type.

As this is a single inheritance we don't have to add something special.
Iegen will generate two kotlin classes one inherited from the other:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/vehicle.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/bicycle.kt
   :language: kotlin
   :lines: 6-

Now we can use them:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
   :language: kotlin
   :start-after: [simple-inheritance-usage]
   :end-before: [simple-inheritance-usage]

Multiple Inheritance
~~~~~~~~~~~~~~~~~~~~
Now let's assume we have a type inherited from two others **Square** inherited from **Rectangle** and **Rhombus**.
The last two in their turn are based from **Parallelogram**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/parallelogram.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/rectangle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/rhombus.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/square.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

In this case again we have used the same value for **shared_ref** for all 4 types.

.. note::
    Here we used **gen: interface** instead of **gen: class**.
    Most of the modern languages do not support multiple inheritance so we have to tell iegen to generate
    interfaces with implementations instead.

.. note::
    It's important to note that in case of multiple inheritance all parent's should have the same root type,
    otherwise an error will be thrown and the code won't be parsed.

Here are the generated wrappers for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/parallelogram.kt
   :language: kotlin
   :lines: 6-


.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rectangle.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rhombus.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/square.kt
   :language: kotlin
   :lines: 6-

.. note::
    As Rectangle and Rhombus are interfaces then Parallelogram also should be an interface.

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
   :language: kotlin
   :start-after: [multi-inheritance-usage]
   :end-before: [multi-inheritance-usage]

Templates
^^^^^^^^^
In this part we will cover template methods and classes/structs.
For templates we must explicitly specify all possible types in **__API__**.


Template Methods
~~~~~~~~~~~~~~~~

Let's assume we have a class with two template methods:

.. literalinclude:: /../examples/primitives/cxx/templates/template_methods.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

For all templates we specify **template** attribute in **__API__**.
It's value must be of JSON format and should contain all template arguments as keys. Values are lists. This lists should
contain either strings(all possible types) or objects with **name** and **type** keys. We will see example with **name** and it's usage later.
Now let's see how kotlin wrappers look like:

.. note::
    Keys in **__API__** should be in the same order as in the template parameter list.

.. note::
    We gave template argument's type full name in **__API__** i.e iegen::example::Task not just Task.
    This is mandatory otherwise iegen won't be able to find Task type.

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/template_methods.kt
   :language: kotlin
   :lines: 5-

As we can see for **makePair** two overloaded methods are generated with types **Project**, **Project** and **Task**, **Project**.
For **max** again two overloaded methods are generated with **String** and **Int**.
Now we can use them, here is an example:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt
   :language: kotlin
   :start-after: [template-funcs-examples]
   :end-before: [template-funcs-examples]


Template Classes/Structs
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's generate bindings for a template class Stack. Assume it will hold Projects or Tasks from  :ref:`classes-label` section.
Here is the code in c++:

.. literalinclude:: /../examples/primitives/cxx/templates/stack.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Similarly to methods we shall have a new kotlin class for each combination of types.
Let's take a look at generated kotlin wrappers:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/stack.kt
   :language: kotlin
   :lines: 6-

Here we have two stacks one for Task and the other for Project. Iegen appends template arguments type names to the class name
i.e Task is appended to Stack an we have **StackTask**.

.. note::
    Currently iegen does not support templates with template type as an argument, for example we can't generate a Stack wrapper
    to hold items of type Stack<Task>.

Now let's see what usages we can have for our example Stack. Here is the source code:

 .. literalinclude:: /../examples/primitives/cxx/templates/stack_usage.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Here we have tree methods. First one takes specialized Stack as an argument. It's important to notice that again we have
specified Stack's full name i.e **iegen::example::Stack<Project>**. Namespace is mandatory here.
Second one takes template Stack as an argument and again we have specified it's full name.
Notice that in third one we haven't specified namespace and it does not have an iegen **__API__**. This is an example which is not supported by iegen.

.. note::
    We can have a type inherited for specialized Stack, e.g ``class TaskList : public Stack<Task>``.
    But currently iegen does not support types inherited from template Stack e.g. ``class TaskList<T> : public Stack<T>``.