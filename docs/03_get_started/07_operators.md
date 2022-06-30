# Operator overloading

This section covers an example of overloading arithmetic and comparison
operators. CppBind will generate appropriate operators for target
languages by default. If the target language does not allow some of the
operators to be overloaded or we don't want them to be overloaded in
target languages, we can set the **is_operator** variable to **False**.
In this case, we must specify the **name** variable so that CppBind will
use it to generate a function with that name.

~~~C++
{% 
include "../../examples/primitives/cxx/operators/counter.hpp"
start="[example-start]"
end="// [example-end]" 
%} 
~~~

!!! Note
    All comparisons in Kotlin are translated into calls to `compareTo`, that
    is required to return **Int**. That's why we have `compareTo` method in
    C++ with kotlin.is_operator variable set to True (this is mandatory as
    compareTo is not a C++ operator and by default, is_operator is False for
    it). Also notice we didn't specify Kotlin instruction for `operator>`.

!!! Note
    We have specifed binding instructions `.action: gen_method` for
    **operator+=** only for Python and Swift. In Kotlin, the signature of
    operator **operator+=** is different, it is covered by **operator+**.
    Therefore, we specify instructions for generating only **operator+** for
    Kotlin.

And the usage example:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt" 
    start="[counter-usage-start]"
    end="// [counter-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/operators/main.py" 
    start="[counter-usage-start]"
    end="# [counter-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/operators/main.swift" 
    start="[counter-usage-start]"
    end="// [counter-usage-end]"
    %} 
    ~~~

??? "Generated operators for target languages"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/operators/counter.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/operators/counter_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/operators/counter.swift" 
        %} 
        ~~~

----

## Overloading subscript operator

Here is an example of overloading **operator\[\]**.

~~~C++
{% 
include "../../examples/primitives/cxx/operators/intarray.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

Usage example:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt" 
    start="[subscript-operator-usage-start]"
    end="// [subscript-operator-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/operators/main.py" 
    start="[subscript-operator-usage-start]"
    end="# [subscript-operator-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/operators/main.swift" 
    start="[subscript-operator-usage-start]"
    end="// [subscript-operator-usage-end]"
    %} 
    ~~~

----

??? "Overloaded subscript operators for target languages"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/operators/intarray.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/operators/intarray_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/operators/intarray.swift" 
        %} 
        ~~~

!!! Note
    As you can see, we have only generated one set operator. It is the case
    when the return value of the overloaded subscript operator is a
    non-const-qualified reference.
