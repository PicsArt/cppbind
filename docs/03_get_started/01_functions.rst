Functions
^^^^^^^^^

For binding global and member functions, **gen_function** and **gen_method** actions should be used, respectively.

Global functions
~~~~~~~~~~~~~~~~

Let's take a look at a global function binding example. Here is a sample source codes of it:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.h
   :language: cpp
   :start-after: [simple-example]
   :end-before: [simple-example]

Except for the **__API__** tag, we have four variables which are instructions for CppBind. 
With **action: gen_function**, we define what should be generated in the target language.
**package** variable indicates the package for generated ``concat`` function and **file** shows the place of the saved file. Notice that we have a prefixed variable **file** with **swift** prefix, which means that its value will be used only for generated Swift bindings, and for other languages, default value will be used, i.e., source file name. And finally, variable **throws** defines what kind of exceptions the ``concat`` function can throw.
Its value is **no_throw** which means it does not throw any exception. For more details on variables, see :ref:`var-def-label`.

And here is a small code demonstrating usage of the generated bindings:

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

.. literalinclude:: /../examples/primitives/cxx/globs/utils.h
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


Here we have overloaded ``concat`` for Kotlin and Swift, but it's slightly different for Python as there's no overloading in Python. We have two ``concat``, and ``concat1`` in Python for C++ ``concat`` functions with 2 and 3 arguments respectively.
Similarly, we have an overloaded function for each template combination in Kotlin and Swift. In the case of Python, a postfix generated from argument types is appended to the function name.

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

As you can see, overloaded methods are like regular methods. There's nothing special to add to the **API** for them.

.. note::
    Python does not have method overloading, but we have overloaded ``sum`` and ``concatenate`` methods in this case, with some tricks under the hood.


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


Also, note that CppBind supports static overloaded methods.

.. _arg-names-and-labels:

Custom argument names and labels
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It is possible to specify argument names and argument labels (for Swift only) using **argument_name** and **argument_label** variables. Here's an example function where the user explicitly gives the argument name and label for each argument. Those new values will be used in the target language instead of the names they have in C++.

.. literalinclude:: /../examples/primitives/cxx/globs/utils.h
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
    | If the original function does not have argument names, CppBind will generate argument names using indexing, i.e. ``arg1``, ``arg2``, etc. The users can override this by using generated argument names in the ``argument_name`` variable.
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

CppBind uses the **nullable_arg** variable to identify which arguments are nullable. It is a list of argument names. And for the nullable return value, CppBind uses the **nullable_return** boolean variable.
In the above example, we have an overloaded method ``max``. The first one has one nullable and one non-null argument, which returns a nullable value. The second one has two nullable arguments and returns a nullable value. In this example, you can also find a constructor taking a nullable argument and nullable getters/setters.

.. note::
    In case of nullable pair of getter/setter methods both must be annotated similarly as **gen_getter** and **gen_setter**. If the getter is **nullable_return: True**, then setter should be marked as **nullable_arg: <arg_name>**. In the above example, we have a pair of nullable getter/setter: ``nullable`` and ``setNullable``.

.. note::
    Kotlin and Swift support nullable arguments. 
    For Python, nullable arguments and return values are marked as ``Optional``. Since all arguments are nullable in Python, CppBind does additional runtime checks not to allow passing null values where a non-null value is expected.

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

Default argument support for literals and enums are handled differently from default arguments with expressions. Let's go through these two cases.

Here are some sample functions with default arguments:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.h
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

.. literalinclude:: /../examples/primitives/cxx/globs/utils.h
   :language: cpp
   :start-after: [complex-defaults-example]
   :end-before: [complex-defaults-example]

In the above example, we have two functions. The first one has one argument of type ``Task`` with a default value.
In this case, CppBind generates two overloaded functions for **Kotlin** and **Swift**: one with no arguments and 
another one with one argument with no default value specified. The second function has three arguments of ``Task``, ``i`` and ``Root``.
The second argument is an ``int``, and its' default value is generated in all target languages. CppBind will generate appropriate overloaded options for **Kotlin** and **Swift** for the other two arguments.
For **Python**, CppBind does not generate overloaded functions; instead, the ``None`` default value is generated.
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

C++ and target languages may differently manage the memory and lifetime of objects.
Having only the return value type, CppBind cannot identify whether the binding language will take care of deallocating the returned object 
or C++ part should handle that. CppBind provides a variable named **return_value_policy** to control this. 
Using **return_value_policy** variable user can override default policies.

The default policies for getters and methods are different. For getters (properties) the default policy is **reference_internal**. For methods, the default policy is **automatic**.

Supported return value policies are:

* **copy** - Create an object copy and give ownership of the new object to the target language. The lifetimes of these two objects are decoupled.
* **move** - Move the returned object into a new one and give ownership of the new object to the target language. The lifetimes of these two objects are decoupled.
* **take_ownership** - Reference an existing object but give ownership to the target language. The target language is responsible for deallocating it.
* **reference** - Reference an existing object but do not give ownership to the target language. C++ is responsible for deallocating it.
* **automatic** - This policy falls back to **take_ownership** when the return value is a pointer and **move** and **copy** for rvalue and lvalue references.
* **automatic_reference** - Falls back to **move** and **copy** for lvalue and rvalue references, respectively, but falls back to **reference** when the return type is a pointer.
* **reference_internal** - This policy is like **reference** but also binds the returned object's lifetime with the lifetime of its parent object, i.e., the parent object won't be deallocated until the returned object is not deallocated.

Let's take a look at the following example:


.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [singleton-example]
   :end-before: [singleton-example]

In this example, we have two members returning the same singleton instance by reference and pointer.
The default return value policy for member functions is **automatic**, which falls back to **take_ownership** for pointers.
This means ownership is given to the binding language responsible for deallocating the returned object.
In the case of references, it falls back to the **copy** policy, which creates a copy of the returned object, and its owner is the target language.
Notice that if the default policy is used, the generated code for the first one won't compile as the copy constructor is deleted.
In this example, the default policies for both cases are not what we want.
We have specified **reference** policy for both cases not to pass the ownership to the binding language and not create a new copy.

Now let's take a look at another example:

.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [factory-example]
   :end-before: [factory-example]

Here we have a factory method ``create``. As was discussed previously the default policy is take_ownership, which is the right policy for this case as we want to give ownership over the returned object to the target language.

.. note::
    Object caching for Kotlin and Swift is not supported yet.
    Each function call creates a new binding object with different
    ownership depending on the function's return value policy.

.. note::
    **copy** and **move** are used, respectively, if the object is returned by value or by rvalue reference.

.. note::
    For shared pointers, **take_ownership** is always used.

.. _keep-alive-policy:

Keep alive policy
~~~~~~~~~~~~~~~~~

Besides the return value policies, CppBind supports the **keep_alive** policy to bind the argument's lifetime to ``this`` object's lifetime.
This ensures that the object won't be deallocated by target language Garbage Collector until the object that keeps a reference on it is alive.

Let's take a look at the following example:

.. literalinclude:: /../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp
   :language: cpp
   :start-after: [employer-example]
   :end-before: [employer-example]

In the above example, ``Employer`` holds references for ``Employee``. The constructor and the method ``addEmployee``
are annotated with the **keep_alive** variable to keep added ``employees`` alive at least until the ``employer`` is alive.
Otherwise, added employees might be deallocated before the destruction of employer, which causes employer to hold invalid data.

.. note::
    If the argument is a container(e.g., ``std::vector``), then the policy is applied to all its elements.

.. note::
    The indexing of arguments starts with one, and the policy can be applied to all arguments.

.. note::
    When applying the **keep_alive policy**, strong reference cycles may occur. Let's assume we have two types,
    and each keeps a reference to the other. Applying the **keep_alive** policy for both, a strong reference cycle will occurs. Currently, CppBind does
    not detect reference cycles, so it's up to users to be careful not to create them.

.. note::
    For shared pointers, it's redundant to specify the **keep_alive** policy.

