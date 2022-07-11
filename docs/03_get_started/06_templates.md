# Templates

This section covers function and class templates. To generate bindings
for function and class templates, we specify all expected values of
template parameters with the `template` variable. The value of a
`template` variable is a mapping between template parameters and their
expected arguments.

Let's see an example:

~~~C++
{% 
include "../../examples/primitives/cxx/templates/template_methods.hpp"
start="[example-start]"
end="// [example-end]"
%} 
~~~

Here we have two template member functions: `max` and `makePair`. As you
can see, we have specified all possible types for each parameter.
CppBind generates overloaded methods in target languages with each
combination of template arguments.

!!! Note
    Keys in **\_\_API\_\_** should be in the same order as the template
    parameter list.

!!! Note
    We specified the template argument's type full name in **\_\_API\_\_**,
    i.e., cppbind::<example::Task>, not just Task. It is mandatory;
    otherwise, CppBind cannot find the required information about the
    specified type.

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/template_methods.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/templates/template_methods_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/templates/template_methods.swift" 
        %} 
        ~~~

As we can see, CppBind generated two overloaded methods for both `max`
and `makePair`. And here are some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt" 
    start="[template-funcs-examples-start]"
    end="// [template-funcs-examples-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/templates/main.py" 
    start="[template-funcs-examples-start]"
    end="# [template-funcs-examples-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/templates/main.swift" 
    start="[template-funcs-examples-start]"
    end="// [template-funcs-examples-end]"
    %} 
    ~~~

----

## Class templates

For a class template, CppBind generates a new type for each
specialization. Let's generate bindings for a template class `Stack`.
We should specify all expected types for template parameter `T`.

Here is the code in C++:

~~~C++
  {% 
    include "../../examples/primitives/cxx/templates/stack.hpp"
    start="[example-start]"
    end="// [example-end]"
  %} 
~~~

We specified three possible values for template parameter `T` which
means there can be three specializations of `Stack`
(`cppbind::example::Stack<cppbind::example::Task>`,
`cppbind::example::Stack<cppbind::example::Project>`,
`cppbind::example::Stack<cppbind::example::Number<int>>`). CppBind will
generate a new class for each of this specializations.

Note that we have specified `name` property for
`cppbind::example::Project` and `cppbind::example::Number<int>`. This
property is used as a type name postfix in target language, i.e.
`StackPrj` will be generated for
`cppbind::example::Stack<cppbind::example::Project>` and `StackNumInt`
for `cppbind::example::Stack<cppbind::example::Number<int>>`.

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt" 
    start="[stack-examples-start]"
    end="// [stack-examples-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/templates/main.py" 
    start="[stack-examples-start]"
    end="# [stack-examples-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/templates/main.swift" 
    start="[stack-examples-start]"
    end="// [stack-examples-end]"
    %} 
    ~~~

----
Now let's see how CppBind handles cases when the Stack template class
is used as an function argument.

~~~C++
  {% 
    include "../../examples/primitives/cxx/templates/stack_usage.hpp"
    start="[example-start]"
    end="// [example-end]"
  %} 
~~~

Here we have five methods to take `Stack` as an argument and return its first element.
CppBind supports the first four methods, but you cannot generate bindings for the fifth.
To generate bindings for a function taking template arguments, you must specify their full type names. The
fifth one does not meet this requirement.

!!! Note
      CppBind supports types inherited from a specialized template, e.g.,
      `class TaskList: public Stack<Task>`. And to generate bindings for a
      type inherited from a template type (has CppBind API), you must specify
      full name of the base type, e.g.,
      `class TaskList<T>: public cppbind::example::Stack<T>`.


libclang does not provide enough information on template types and these requirements are added to
take the missing information from user provided APIs.

!!! Note
      Due to this missing information, currently CppBind does not support typedefs on template types, even if the type name is fully specified,
      e.g., `using Stack = cppbind::example::Stack<T>` is not supported.

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
          include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/stack.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
          include "../../examples/primitives/python/src/examples_lib/templates/stack_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
          include "../../examples/primitives/swift/src/templates/stack.swift" 
        %} 
        ~~~

----

## Template Getters/Setters

Now let's see how the `name` is used for template getters/setters.

~~~C++
{% 
  include "../../examples/primitives/cxx/getters/fruits.hpp"
  start="[example-start]"
  end="// [example-end]"
%} 
~~~

In the above example, we have a template getter `fruits`, and we have
specified two possible types for parameter `T`:
`cppbind::example::Apple` and `cppbind::example::Pineapple`. Notice that
the `name` is specified for both, which is used as a generated property
name. As a result, we'll have `apple` and `pineapple` correspondingly.
If `name` is not specified, then the target language type name is used.
For this example, we would have `Apple` and `Pineapple` correspondingly.
In the above example, we have another template getter/setter,
`allFruits` with two template parameters, `T` and `U`. Again, we have
specified `name` for both parameters. In the case of multiple template
parameters, target property name is constructed by joining user-provided
names. For this example, it is `applesWithPineapples` for Kotlin and
Swift, `apples_with_pineapples` for Python. Notice that the name is
snake-cased for Python. The API for this getter could also be written in
the following way:

``` yaml
T:
  - type: cppbind::example::Apple
    name: applesWithPineapples
U:
  - type: cppbind::example::Pineapple
```

The result will be the same.

If the `name` is not specified, the target property name is constructed
by joining the names of target language types. For this example, we
would have `applePineapple` (Swift, Kotlin) and `apple_pineapple`
(Python).

And here are some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
      include "../../examples/primitives/kotlin/src/main/java/com/examples/getters/main.kt" 
      start="[template-get-usage-start]"
      end="// [template-get-usage-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
      include "../../examples/primitives/python/src/examples_lib/getters/main.py" 
      start="[template-get-usage-start]"
      end="# [template-get-usage-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
      include "../../examples/primitives/swift/src/getters/main.swift" 
      start="[template-get-usage-start]"
      end="// [template-get-usage-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
          include "../../examples/primitives/kotlin/src/main/java/com/examples/getters/fruits.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
          include "../../examples/primitives/python/src/examples_lib/getters/fruits_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
          include "../../examples/primitives/swift/src/getters/fruits.swift" 
        %} 
        ~~~

## Non-type Template Parameters

Currently, cppbind supports only integral non-type template parameters.
Like a type template parameter all values of non-type parameters should be specified via **\_\_API\_\_**.

Let's see an example:
~~~C++
{% 
include "../../examples/primitives/cxx/templates/array.hpp"
start="// [example-start]"
end="// [example-end]"
%} 
~~~

As you can see, we have specified all possible values for both `T` and `SIZE`.
CppBind generates four types corresponding to each combination of template arguments, i.e.,  `ArrayFloat1`, `ArrayFloat2`, `ArrayInt1` and `ArrayInt2`.

Now let's see some usage examples:

=== "Kotlin"
    ~~~Java
    {% 
    include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt" 
    start="// [array-examples-start]"
    end="// [array-examples-end]"
    %} 
    ~~~

=== "Python"
    ~~~Python
    {% 
    include "../../examples/primitives/python/src/examples_lib/templates/main.py" 
    start="# [array-examples-start]"
    end="# [array-examples-end]"
    %} 
    ~~~

=== "Swift"
    ~~~Swift
    {% 
    include "../../examples/primitives/swift/src/templates/main.swift" 
    start="// [array-examples-start]"
    end="// [array-examples-end]"
    %} 
    ~~~

??? "Generated bindings"
    === "Kotlin"
        ~~~Java
        {% 
        include "../../examples/primitives/kotlin/src/main/java/com/examples/templates/array.kt" 
        %} 
        ~~~
    === "Python"
        ~~~Python
        {% 
        include "../../examples/primitives/python/src/examples_lib/templates/array_pygen.py" 
        %} 
        ~~~
    === "Swift"
        ~~~Swift
        {% 
        include "../../examples/primitives/swift/src/templates/array.swift" 
        %} 
        ~~~
