Functions
^^^^^^^^^

For binding global and member functions, respectively, **gen_function** and **gen_method** actions should be used.

Global functions
~~~~~~~~~~~~~~~~

Let's bind a simple global function.
Here is the source code of it:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [simple-example]
   :end-before: [simple-example]

After **__API__** tag we have four variables which are instructions for CppBind.
With **action: gen_function** we define what should be generated in the target language.
**package** variable indicates what will be the package for generated ``concat`` function and **file** indicates
in which file it will be saved. Notice that we have prefixed variable **file** with **swift** prefix,
which means that its value will be used only for generated Swift bindings and for other languages the default value will be used,
i.e. source file name. And finally variable **throws** defines what kind of exceptions ``concat`` function can throw.
In this case its value is **no_throw** which means it will not throw any exception.
For more details on variables, see :ref:`var-def-label`.

And here is a small code using generated bindings:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [simple-usage-example]
           :end-before: [simple-usage-example]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [simple-usage-example]
           :end-before: [simple-usage-example]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [simple-usage-example]
           :end-before: [simple-usage-example]

Let's bind more complex examples like template ``makePair`` and ``max``, overloaded ``concat``, etc.

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Code using generated functions:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]


Here we have overloaded ``concat`` for Kotlin and Swift but for Python it's slightly different
as there's no overloading for Python. We have two methods ``concat`` and ``concat1`` in Python.
Similarly for template function we have an overloaded function for each template combination for Kotlin and Swift.
In case of Python a postfix generated from argument types is appended to the function name.

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/utils.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/utils_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/globs/GlobUtils.swift
               :language: swift

|

Overloaded methods
~~~~~~~~~~~~~~~~~~

Let's now bind a struct with overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [overload-example]
   :end-before: [overload-example]


As you can see overloaded methods are like regular methods. There's nothing special to add in the **API** for them.

.. note::
    Python does not have method overloading, but here with some tricks under the hood we have overloaded ``sum`` and ``concatenate`` methods.


We are ready to use the generated bindings:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
           :language: kotlin
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/main.py
           :language: py
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/main.swift
           :language: swift
           :start-after: [overload-usage]
           :end-before: [overload-usage]


.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/utils_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/overloads/Utils.swift
               :language: swift

|

Static methods
~~~~~~~~~~~~~~

The binding mechanism of static methods is similar to the binding of regular methods. Nothing special should be added in **API** comments:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [static-example]
   :end-before: [static-example]

Here are the usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
           :language: kotlin
           :start-after: [static-usage]
           :end-before: [static-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/main.py
           :language: py
           :start-after: [static-usage]
           :end-before: [static-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/main.swift
           :language: swift
           :start-after: [static-usage]
           :end-before: [static-usage]

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/utils_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/overloads/Utils.swift
               :language: swift

|

.. note::
    In generated Python bindings ``sum`` is a classmethod as it was static in the original code.

Also note that CppBind supports static overloaded methods.

.. _arg-names-and-labels:

Custom argument names and labels
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

You can specify argument names and argument labels(only for Swift) by using **argument_name** and **argument_label**
variables. Here's an example function where user explicitly gives argument name and label for each given argument.
Those values will be used in the target language instead of the values used in C++.

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [custom-arg-examples]
   :end-before:  [custom-arg-examples]

And here is a small code example using generated bindings:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [custom-arg-examples]
           :end-before: [custom-arg-examples]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [custom-arg-examples]
           :end-before: [custom-arg-examples]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [custom-arg-examples]
           :end-before: [custom-arg-examples]


.. note::
    | If the original function has no argument names then CppBind will generate argument names using indexing, i.e. ``arg1``, ``arg2`` etc.
      User can override this by using generated argument names in ``argument_name`` variable.
    | Here's a small example:

    .. code-block:: yaml

          action: gen_function
          argument_name:
            arg1: input
            arg2: output



.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/custom_args/customArgUtils.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/customArgUtils_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/globs/customArgUtils.swift
               :language: swift

|

.. _nullables-label:

Nullable arguments
~~~~~~~~~~~~~~~~~~

Let's take a look at the following example:

.. literalinclude:: /../examples/primitives/cxx/nullables/nullable_utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

CppBind uses **nullable_arg** variable to identify which arguments are nullable. This is a list of argument names.
And for nullable return value CppBind uses **nullable_return** boolean variable.
In the above example we have an overloaded method ``max``. The first one has one nullable and one non null argument and it returns nullable value.
The second one has two nullable arguments and returns a nullable value.
In this example you can find also a constructor taking nullable argument and nullable getters/setters.

.. note::
    For getter/setter methods marked as **gen_getter** and **gen_setter** both must be tagged similarly.
    If the getter is marked with **nullable_return: True** then setter should be marked with **nullable_arg: <arg_name>**.
    In the above example we have a pair of nullable getter/setter: ``nullable`` and ``setNullable``.

.. note::
    Kotlin and Swift have a support for nullable arguments.
    For Python nullable arguments and return values are marked as Optional.
    Since all arguments are nullable in Python, CppBind does additional runtime checks to not allow passing null value where a non null value is expected.

Now let's see some usage examples for generated bindings:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nullables/main.kt
           :language: kotlin
           :start-after: [nullables-usage]
           :end-before: [nullables-usage]

    .. tab-item:: Python

        As you can see here ``ValueError`` is thrown when None is passed but expected value is not Optional.
        The same is for return values.

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/nullables/main.py
            :language: py
            :start-after: [nullables-usage]
            :end-before: [nullables-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/nullables/main.swift
            :language: swift
            :start-after: [nullables-usage]
            :end-before: [nullables-usage]

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nullables/nullable_utils.kt
                :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/nullables/nullable_utils_pygen.py
                :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/nullables/NullableUtils.swift
                :language: swift

|

Default arguments
~~~~~~~~~~~~~~~~~

Default argument support for builtin types(e.g. bool, int, nullptr, etc.), enums and strings differs from the support for user-defined project types.
Let's go through these two cases.

Here are some sample functions having default arguments:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [non-complex-defaults-example]
   :end-before: [non-complex-defaults-example]

Here's a sample code using the above functions:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [non-complex-defaults-usage]
           :end-before: [non-complex-defaults-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [non-complex-defaults-usage]
           :end-before: [non-complex-defaults-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [non-complex-defaults-usage]
           :end-before: [non-complex-defaults-usage]

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/primitives/primitiveDefaults.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/primitiveDefaults_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/globs/primitiveDefaults.swift
               :language: swift

|

Complex cases like ``t=Task("MyTask")`` or ``t=24>>2`` are handled differently.
Let's take a look at the following example:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [complex-defaults-example]
   :end-before: [complex-defaults-example]

In the above example we have two functions. The first one has one argument of type ``Task`` with a default value.
In this case CppBind generates two overloaded functions for **Kotlin** and **Swift**: one without arguments and
the other with one argument without default value. The second function has three arguments of types ``Task``, ``Color`` and ``Root``.
The second argument is an enum, thus its' default value is generated in all target languages and for other two arguments CppBind will generate
appropriate overloaded options for **Kotlin** and **Swift**.
For **Python** CppBind does not generate overloaded functions, instead ``None`` default value is generated.
Although the actual default values for complex types are not visible in generated code, they work as expected.

.. collapse:: Generated functions

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/complex/complexDefaults.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/complexDefaults_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/globs/complexDefaults.swift
               :language: swift

|


And here are some usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [complex-defaults-usage]
           :end-before: [complex-defaults-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [complex-defaults-usage]
           :end-before: [complex-defaults-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [complex-defaults-usage]
           :end-before: [complex-defaults-usage]


.. _rv-policies:

Return value policies
~~~~~~~~~~~~~~~~~~~~~

C++ and other languages may differently manage memory and lifetime of the objects.
Just by return value type CppBind cannot decide whether the binding language should take care of deallocating the returned object
or C++ is responsible for that.
For this reason CppBind provides a variable named **return_value_policy**.
Using this variable user can override the default policies.

Let's take a look at the following example:

.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [singleton-example]
   :end-before: [singleton-example]

In this example we have two members returning the same singleton instance by reference and by pointer.
The default return value policy for member functions is **automatic** which falls back to **take_ownership** for pointers.
This means ownership is given to the binding language which is responsible for deallocating the returned object.
In case of references it falls back to **copy** policy which creates a copy of returned object and the owner of it is the target language.
Notice that the generated code for the first one in case if the default policy is used won't compile as the copy constructor is deleted.
In this example the default policies for both cases are not what we want.
For both cases we have specified **reference** policy to not pass the ownership to the binding language or to not create a new copy.

Now let's take a look to another example:

.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [factory-example]
   :end-before: [factory-example]

Here we have a factory method ``create``. In this case the default policy is the right policy as it refers to
the returned object and gives the ownership to the target language.

.. note::
    The default policies for getters and methods are different.
    For getters and properties the default policy is **reference_internal**.
    For methods the default policy is **automatic**.

.. note::
    Object caching for Kotlin and Swift are not supported yet,
    that's why each function call creates a new binding object with different
    ownership depending on the function's return value policy.

Supported return values policies are:

* **copy** - Create a new object and give the ownership to the target language. The lifetimes of these two objects are decoupled.
* **move** - Move the returned object into a new one and give the ownership to the target language. The lifetimes of these two objects are decoupled.
* **take_ownership** - Reference an existing object but give the ownership to the target language. Target language is responsible for deallocating it.
* **reference** - Reference an existing object but do not give the ownership to the target language. C++ is responsible for deallocating it.
* **automatic** - This policy falls back to **take_ownership** when the return value is a pointer and to **move** and **copy** for rvalue and lvalue references respectively.
* **automatic_reference** - Falls back to **move** and **copy** for lvalue and rvalue references respectively, but falls back to **reference** when the return type is a pointer.
* **reference_internal** - This policy is like **reference** but additionally binds the lifetime of returned object with the lifetime of its parent object, i.e. parent object won't be deallocated at least until the returned object is not deallocated.

.. note::
    If the object is returned by value or by rvalue reference then **copy** and **move** are used respectively.

.. note::
    For shared pointers **take_ownership** is always used.

.. _keep-alive-policy:

Keep alive policy
~~~~~~~~~~~~~~~~~

Besides the return value policies CppBind supports **keep_alive** policy to bind argument's lifetime to ``this`` object's lifetime.
This is to ensure that the argument won't be deallocated at least until the object which keeps a reference on it is alive.

Let's take a look at the following example:

.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [employer-example]
   :end-before: [employer-example]

In the above example ``Employer`` holds references of ``Employee``. The constructor and the method ``addEmployee``
are annotated with **keep_alive** variable to keep added ``employees`` alive at least until the ``employer`` is alive,
otherwise added employees might be deallocated before the destruction of employer which will cause employer to
hold invalid data.

.. note::
    If the argument is a container(e.g. ``std::vector``) then the policy is applied on all its elements.

.. note::
    The indexing of arguments starts with 1 and the policy can be applied on all arguments.

.. note::
    When applying **keep_alive** policy strong reference cycles may occur. Let's assume we have two types
    and each of them keep a reference to the other. In this case, if we
    apply **keep_alive** policy for both then a strong reference cycle will occur. Currently, CppBind does not detect
    reference cycles so it's up to users to be careful to not create them.

.. note::
    For shared pointers it's redundant to specify **keep_alive** policy.
