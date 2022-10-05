# Classes/Structs

Let's generate a binding code for the following custom type.

~~~C++
{% 
include "../../examples/primitives/cxx/simple/task.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

In the code above, we are exporting all public members and constructors.

!!! Note
    The title method is marked as a getter, a read-only property for the
    target language.

!!! Note
    By default, CppBind generates `System.loadLibrary("wrapper_jni")` for
    each Kotlin class. To disable this behavior define
    **c_wrapper_lib_name** with null value: **c_wrapper_lib_name: null** or
    **c_wrapper_lib_name:**.

Usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt" 
    start="[task-usage-start]"
    end="// [task-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/simple/main.py" 
    start="[task-usage-start]"
    end="# [task-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/simple/main.swift" 
    start="[task-usage-start]"
    end="// [task-usage-end]"
    %} 
    ~~~

??? "Generated code for the target languages"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/simple/task.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/simple/task/task_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/simple/task.swift" 
        %} 
        ~~~

Let's assume we have another class using the one above.

~~~C++
{% 
include "../../examples/primitives/cxx/simple/project.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

And the usage example:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt" 
    start="[project-usage-start]"
    end="// [project-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/simple/main.py" 
    start="[project-usage-start]"
    end="# [project-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/simple/main.swift" 
    start="[project-usage-start]"
    end="// [project-usage-end]"
    %} 
    ~~~

??? "Here are the generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/simple/project.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/simple/project_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/simple/project.swift" 
        %} 
        ~~~

## Factory method as a constructor

CppBind allows generating a constructor from a factory method by just annotating it with
**gen_constructor**.
Here's an example:

~~~C++
{% 
include "../../examples/primitives/cxx/factories/school.h"
start="[example-start]"
end="// [example-end]"
%} 
~~~

Here we have two overloaded factory methods marked with **gen_constructor**.
CppBind generates two constructors corresponding to them.


Here's a small usage example:
=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/factories/main.kt" 
    start="[factories-usage-start]"
    end="// [factories-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/factories/main.py" 
    start="[factories-usage-start]"
    end="# [factories-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/factories/main.swift" 
    start="[factories-usage-start]"
    end="// [factories-usage-end]"
    %} 
    ~~~

??? "The generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/factories/school.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/factories/school_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/factories/school.swift" 
        %} 
        ~~~

## Special methods

Many languages have a base class from which other classes are derived.
This class contains methods like `hash`, `equals`, `toString`, etc. For
the languages which have this base class, CppBind generates
implementations for `hash`, `equals`, `toString`. This is done to make
sure the objects which are wrapping the same C++ instance are equal and
have the same value for `hash` and `toString`.

The generated methods are implemented in the following way:

-   **hash** - returns the hash value of underlying C++ object address.
-   **equals** - returns whether the underlying C++ objects are
    identical or not.
-   **toString** - returns a string containing type and address of the
    underlying C++ object.

Users can define their own implementations by adding `hash`, `equals`
and `toString` to C++ classes. The names of these methods can be
configured with **hash_method**, **equals_method** and
**tostring_method** variables. More on variables can be found
[here](../main_features/var_def.md).

Let's see an example:

~~~C++
{% 
include "../../examples/primitives/cxx/hashing/objects.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

In the above example the first class: `Object1`, contains custom
definitions for `hash`, `equals` and `toString` which means CppBind
generates appropriate methods for all target languages, and if it's
required also implements appropriate interfaces. Particularly for Swift
the generated class conforms `Hashable`, `Equatable` and
`CustomStringConvertible`.

In case of the second example, i.e. `Object2`, CppBind generates the
default implementations for Kotlin.

For Python CppBind does not generate the default ones, as pybind already
does that. Instead CppBind generates a `__repr__` method which returns a
string containing C++ object address and type information. This can be
used for debugging purposes. Users can have their own `__repr__` by just
annotating the appropriate method with `python.name: __repr__`.

For Swift the default implementations won't be generated, as by
default, classes in Swift are neither hashable nor equatable.

!!! Note
    It is not allowed to define `hash`, `equals` and `toString` for
    interfaces. If they are defined then CppBind raises an error.

!!! Note
    If `hash` is defined but `equals` is not defined then CppBind raises an
    error for Swift. All `Hashable` types are also `Equatable` in Swift.

Now let's see some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/hashing/main.kt" 
    start="[hashing-usage-example-start]"
    end="// [hashing-usage-example-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/hashing/main.py" 
    start="[hashing-usage-example-start]"
    end="# [hashing-usage-example-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/hashing/main.swift" 
    start="[hashing-usage-example-start]"
    end="// [hashing-usage-example-end]"
    %} 
    ~~~

??? "The generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/hashing/objects.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/hashing/objects_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/hashing/objects.swift" 
        %} 
        ~~~

## Nested Types

Let's now generate bindings for nested types. Here's a small example:

~~~C++
{% 
include "../../examples/primitives/cxx/nested_types/list.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

!!! Note
    Here we used **header_code_fragment** and **footer_code_fragment**
    variables to create nested types.

Some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/nested_types/main.kt" 
    start="[nested-types-usage-start]"
    end="// [nested-types-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/nested_types/main.py" 
    start="[nested-types-usage-start]"
    end="# [nested-types-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/nested_types/main.swift" 
    start="[nested-types-usage-start]"
    end="// [nested-types-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/nested_types/list.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/nested_types/list_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/nested_types/list.swift" 
        %} 
        ~~~
