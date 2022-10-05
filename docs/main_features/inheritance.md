# Inheritance

This section covers single and multiple inheritances.

## Single Inheritance

Assume we have two types: `Bicycle` inherited from `Vehicle`:

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/vehicle.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/bicycle.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

As this is a single inheritance, we don't have to add something
special. CppBind generates two classes, one inherited from the other.

!!! Note
    We have used the same value for the **shared_ref** attribute for both
    classes. It is mandatory. This attribute should be the same in the type
    hierarchy.

!!! Note
    If the type parsed is inherited from another one that does not have an
    **\_\_API\_\_**, i.e., is not parsed by CppBind, then in the binding
    code, it won't appear as a base type for the target type.

Usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt" 
    start="[simple-inheritance-usage-start]"
    end="// [simple-inheritance-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/inheritance/main.py" 
    start="[simple-inheritance-usage-start]"
    end="# [simple-inheritance-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/inheritance/main.swift" 
    start="[simple-inheritance-usage-start]"
    end="// [simple-inheritance-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/vehicle.kt" 
        %} 
        ~~~
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/bicycle.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/vehicle_pygen.py" 
        %} 
        ~~~
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/bicycle_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/vehicle.swift" 
        %} 
        ~~~
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/bicycle.swift" 
        %} 
        ~~~

## Multiple Inheritance 

Now let's assume we have a type inherited from two others:
`` Square inherited from Rectangle`and`Rhombus`. The last two, in their turn, are derived from`Parallelogram`:

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/parallelogram.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/rectangle.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/rhombus.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

~~~C++
{% 
include "../../examples/primitives/cxx/inheritance/square.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

Again, we have used the same value for **shared_ref** for all four
types.

We used **action: gen_interface** instead of **action: gen_class** for
the parent types. Most modern languages do not support multiple
inheritance, so we have to tell CppBind to generate interfaces instead.

!!! Note
    It's important to note that CppBind supports multiple inheritance for
    only polymorphic types (when the type has a virtual method/destructor or
    a polymorphic base).

!!! Note
    As Rectangle and Rhombus are interfaces, Parallelogram should also be an
    interface.

Usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt" 
    start="[multi-inheritance-usage-start]"
    end="// [multi-inheritance-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/inheritance/main.py" 
    start="[multi-inheritance-usage-start]"
    end="# [multi-inheritance-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/inheritance/main.swift" 
    start="[multi-inheritance-usage-start]"
    end="// [multi-inheritance-usage-end]"
    %} 
    ~~~

??? "Here are the generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/parallelogram.kt" 
        %} 
        ~~~
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rectangle.kt" 
        %} 
        ~~~
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rhombus.kt" 
        %} 
        ~~~
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/inheritance/square.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/parallelogram_pygen.py" 
        %} 
        ~~~
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/rectangle_pygen.py" 
        %} 
        ~~~
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/rhombus_pygen.py" 
        %} 
        ~~~
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/inheritance/square_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/parallelogram.swift" 
        %} 
        ~~~
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/rectangle.swift" 
        %} 
        ~~~
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/rhombus.swift" 
        %} 
        ~~~
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/inheritance/square.swift" 
        %} 
        ~~~
