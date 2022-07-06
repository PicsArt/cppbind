# Functions

For binding global and member functions, **gen_function** and
**gen_method** actions should be used, respectively.

## Global functions

Let's take a look at a global function binding example. Here is a
sample source codes of it:

~~~C++
{% 
include "../../examples/primitives/cxx/globs/utils.h"
start="[simple-example-start]"
end="// [simple-example-end]"
%} 
~~~

Except for the **\_\_API\_\_** tag, we have four variables which are
instructions for CppBind. With **action: gen_function**, we define what
should be generated in the target language. **package** variable
indicates the package for generated `concat` function and **file** shows
the place of the saved file. Notice that we have a prefixed variable
**file** with **swift** prefix, which means that its value will be used
only for generated Swift bindings, and for other languages, default
value will be used, i.e., source file name. And finally, variable
**throws** defines what kind of exceptions the `concat` function can
throw. Its value is **no_throw** which means it does not throw any
exception. For more details on variables, see [Variable Definitions](../03_get_started/09_var_def.md).

And here is a small code demonstrating usage of the generated bindings:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt" 
    start="[simple-usage-example-start]"
    end="// [simple-usage-example-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/globs/main.py" 
    start="[simple-usage-example-start]"
    end="# [simple-usage-example-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/globs/main.swift" 
    start="[simple-usage-example-start]"
    end="// [simple-usage-example-end]"
    %} 
    ~~~

Let's bind more complex examples like template `makePair` and `max`,
overloaded `concat`, etc.

~~~C++
{% 
include "../../examples/primitives/cxx/globs/utils.h"
start="[example-start]"
end="// [example-end]"
%} 
~~~

Code using generated functions:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt" 
    start="[glob-func-examples-start]"
    end="// [glob-func-examples-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/globs/main.py" 
    start="[glob-func-examples-start]"
    end="# [glob-func-examples-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/globs/main.swift" 
    start="[glob-func-examples-start]"
    end="// [glob-func-examples-end]"
    %} 
    ~~~

Here we have overloaded `concat` for Kotlin and Swift, but it's
slightly different for Python as there's no overloading in Python. We
have two `concat`, and `concat1` in Python for C++ `concat` functions
with 2 and 3 arguments respectively. Similarly, we have an overloaded
function for each template combination in Kotlin and Swift. In the case
of Python, a postfix generated from argument types is appended to the
function name.

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/utils.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/globs/utils_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/globs/GlobUtils.swift" 
        %} 
        ~~~

## Overloaded methods

Let's now bind a struct with overloaded methods:

~~~C++
{% 
include "../../examples/primitives/cxx/overloads/utils.hpp"
start="[overload-example-start]"
end="// [overload-example-end]"
%} 
~~~

As you can see, overloaded methods are like regular methods. There's
nothing special to add to the **API** for them.

!!! Note
    Python does not have method overloading, but we have overloaded `sum`
    and `concatenate` methods in this case, with some tricks under the hood.

We are ready to use the generated bindings:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt" 
    start="[overload-usage-start]"
    end="// [overload-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/overloads/main.py" 
    start="[overload-usage-start]"
    end="# [overload-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/overloads/main.swift" 
    start="[overload-usage-start]"
    end="// [overload-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/overloads/utils_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/overloads/Utils.swift" 
        %} 
        ~~~

## Static methods

The binding mechanism of static methods is similar to the binding of
regular methods. Nothing special should be added in **API** comments:

~~~C++
{% 
include "../../examples/primitives/cxx/overloads/utils.hpp"
start="[static-example-start]"
end="// [static-example-end]"
%} 
~~~

Here are the usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt" 
    start="[static-usage-start]"
    end="// [static-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/overloads/main.py" 
    start="[static-usage-start]"
    end="# [static-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/overloads/main.swift" 
    start="[static-usage-start]"
    end="// [static-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/overloads/utils_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/overloads/Utils.swift" 
        %} 
        ~~~

Also, note that CppBind supports static overloaded methods.

## Custom argument names and labels

It is possible to specify argument names and argument labels (for Swift
only) using **argument_name** and **argument_label** variables. Here's
an example function where the user explicitly gives the argument name
and label for each argument. Those new values will be used in the target
language instead of the names they have in C++.

~~~C++
{% 
include "../../examples/primitives/cxx/globs/utils.h"
start="[custom-arg-examples-start]"
end="// [custom-arg-examples-end]"
%} 
~~~

And here is a small code example using generated bindings:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt" 
    start="[custom-arg-examples-start]"
    end="// [custom-arg-examples-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/globs/main.py" 
    start="[custom-arg-examples-start]"
    end="# [custom-arg-examples-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/globs/main.swift" 
    start="[custom-arg-examples-start]"
    end="// [custom-arg-examples-end]"
    %} 
    ~~~

!!! Note
    If the original function does not have argument names, CppBind will
    generate argument names using indexing, i.e. `arg1`, `arg2`, etc. The
    users can override this by using generated argument names in the
    `argument_name` variable. Here's a small example:

    ``` yaml
    action: gen_function
    argument_name:
    arg1: input
    arg2: output
    ```


??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/custom_args/customArgUtils.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/globs/customArgUtils_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/globs/customArgUtils.swift" 
        %} 
        ~~~

## Nullable arguments

Let's take a look at the following example:

~~~C++
{% 
include "../../examples/primitives/cxx/nullables/nullable_utils.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

CppBind uses the **nullable_arg** variable to identify which arguments
are nullable. It is a list of argument names. And for the nullable
return value, CppBind uses the **nullable_return** boolean variable. In
the above example, we have an overloaded method `max`. The first one has
one nullable and one non-null argument, which returns a nullable value.
The second one has two nullable arguments and returns a nullable value.
In this example, you can also find a constructor taking a nullable
argument and nullable getters/setters.

!!! Note
    In case of nullable pair of getter/setter methods both must be annotated
    similarly as **gen_getter** and **gen_setter**. If the getter is
    **nullable_return: True**, then setter should be marked as
    **nullable_arg: <arg_name\>**. In the above example, we have a pair of
    nullable getter/setter: `nullable` and `setNullable`.

!!! Note
    Kotlin and Swift support nullable arguments. For Python, nullable
    arguments and return values are marked as `Optional`. Since all
    arguments are nullable in Python, CppBind does additional runtime checks
    not to allow passing null values where a non-null value is expected.

Now let's see some usage examples for generated bindings:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/nullables/main.kt" 
    start="[nullables-usage-start]"
    end="// [nullables-usage-end]"
    %} 
    ~~~

=== "Python"
    As you can see here `ValueError` is thrown when None is passed but
    expected value is not Optional. The same is for return values.
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/nullables/main.py" 
    start="[nullables-usage-start]"
    end="# [nullables-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/nullables/main.swift" 
    start="[nullables-usage-start]"
    end="// [nullables-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/nullables/nullable_utils.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/nullables/nullable_utils_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/nullables/NullableUtils.swift" 
        %} 
        ~~~

## Default arguments

Default argument support for literals and enums are handled differently
from default arguments with expressions. Let's go through these two
cases.

Here are some sample functions with default arguments:

~~~C++
{% 
include "../../examples/primitives/cxx/globs/utils.h"
start="[non-complex-defaults-example-start]"
end="// [non-complex-defaults-example-end]"
%} 
~~~

Here's a sample code using the above functions:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt" 
    start="[non-complex-defaults-usage-start]"
    end="// [non-complex-defaults-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/globs/main.py" 
    start="[non-complex-defaults-usage-start]"
    end="# [non-complex-defaults-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/globs/main.swift" 
    start="[non-complex-defaults-usage-start]"
    end="// [non-complex-defaults-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/primitives/primitiveDefaults.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/globs/primitiveDefaults_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/globs/primitiveDefaults.swift" 
        %} 
        ~~~

Complex cases like `t=Task("MyTask")` or `t=24>>2` are handled
differently. Let's take a look at the following example:

~~~C++
{% 
include "../../examples/primitives/cxx/globs/utils.h"
start="[complex-defaults-example-start]"
end="// [complex-defaults-example-end]"
%} 
~~~

In the above example, we have two functions. The first one has one
argument of type `Task` with a default value. In this case, CppBind
generates two overloaded functions for **Kotlin** and **Swift**: one
with no arguments and another one with one argument with no default
value specified. The second function has three arguments of `Task`, `i`
and `Root`. The second argument is an `int`, and its' default value is
generated in all target languages. CppBind will generate appropriate
overloaded options for **Kotlin** and **Swift** for the other two
arguments. For **Python**, CppBind does not generate overloaded
functions; instead, the `None` default value is generated. Although the
actual default values for complex types are not visible in generated
code, they work as expected.


??? "Generated functions"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/complex/complexDefaults.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/globs/complexDefaults_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/globs/complexDefaults.swift" 
        %} 
        ~~~ 

And here are some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt" 
    start="[complex-defaults-usage-start]"
    end="// [complex-defaults-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/globs/main.py" 
    start="[complex-defaults-usage-start]"
    end="# [complex-defaults-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/globs/main.swift" 
    start="[complex-defaults-usage-start]"
    end="// [complex-defaults-usage-end]"
    %} 
    ~~~

## Return value policies 

C++ and target languages may differently manage the memory and lifetime
of objects. Having only the return value type, CppBind cannot identify
whether the binding language will take care of deallocating the returned
object or C++ part should handle that. CppBind provides a variable named
**return_value_policy** to control this. Using **return_value_policy**
variable user can override default policies.

The default policies for getters and methods are different. For getters
(properties) the default policy is **reference_internal**. For methods,
the default policy is **automatic**.

Supported return value policies are:

-   **copy** - Create an object copy and give ownership of the new
    object to the target language. The lifetimes of these two objects
    are decoupled.
-   **move** - Move the returned object into a new one and give
    ownership of the new object to the target language. The lifetimes of
    these two objects are decoupled.
-   **take_ownership** - Reference an existing object but give ownership
    to the target language. The target language is responsible for
    deallocating it.
-   **reference** - Reference an existing object but do not give
    ownership to the target language. C++ is responsible for
    deallocating it.
-   **automatic** - This policy falls back to **take_ownership** when
    the return value is a pointer and **move** and **copy** for rvalue
    and lvalue references.
-   **automatic_reference** - Falls back to **move** and **copy** for
    lvalue and rvalue references, respectively, but falls back to
    **reference** when the return type is a pointer.
-   **reference_internal** - This policy is like **reference** but also
    binds the returned object's lifetime with the lifetime of its
    parent object, i.e., the parent object won't be deallocated until
    the returned object is not deallocated.

Let's take a look at the following example:

~~~C++
{% 
    include "../../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp"
    start="[singleton-example-start]"
    end="// [singleton-example-end]"
%} 
~~~

In this example, we have two members returning the same singleton
instance by reference and pointer. The default return value policy for
member functions is **automatic**, which falls back to
**take_ownership** for pointers. This means ownership is given to the
binding language responsible for deallocating the returned object. In
the case of references, it falls back to the **copy** policy, which
creates a copy of the returned object, and its owner is the target
language. Notice that if the default policy is used, the generated code
for the first one won't compile as the copy constructor is deleted. In
this example, the default policies for both cases are not what we want.
We have specified **reference** policy for both cases not to pass the
ownership to the binding language and not create a new copy.

Now let's take a look at another example:

~~~C++
{% 
    include "../../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp"
    start="[factory-example-start]"
    end="// [factory-example-end]"
%} 
~~~

Here we have a factory method `create`. As was discussed previously the
default policy is take_ownership, which is the right policy for this
case as we want to give ownership over the returned object to the target
language.

!!! Note
    Object caching for Kotlin and Swift is not supported yet. Each function
    call creates a new binding object with different ownership depending on
    the function's return value policy.

!!! Note
    **copy** and **move** are used, respectively, if the object is returned
    by value or by rvalue reference.

!!! Note
    For shared pointers, **take_ownership** is always used.

## Keep alive policy

Besides the return value policies, CppBind supports the **keep_alive**
policy to bind the argument's lifetime to `this` object's lifetime.
This ensures that the object won't be deallocated by target language
Garbage Collector until the object that keeps a reference on it is
alive.

Let's take a look at the following example:

~~~C++
{% 
    include "../../examples/primitives/cxx/rv_policies/policies_doc_examples.hpp"
    start="[employer-example-start]"
    end="// [employer-example-end]"
%} 
~~~

In the above example, `Employer` holds references for `Employee`. The
constructor and the method `addEmployee` are annotated with the
**keep_alive** variable to keep added `employees` alive at least until
the `employer` is alive. Otherwise, added employees might be deallocated
before the destruction of employer, which causes employer to hold
invalid data.

!!! Note
    If the argument is a container(e.g., `std::vector`), then the policy is
    applied to all its elements.

!!! Note
    The indexing of arguments starts with one, and the policy can be applied
    to all arguments.

!!! Note
    When applying the **keep_alive policy**, strong reference cycles may
    occur. Let's assume we have two types, and each keeps a reference to
    the other. Applying the **keep_alive** policy for both, a strong
    reference cycle will occurs. Currently, CppBind does not detect
    reference cycles, so it's up to users to be careful not to create them.

!!! Note
    For shared pointers, it's redundant to specify the **keep_alive**
    policy.
