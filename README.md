
![](https://raw.githubusercontent.com/PicsArt/cppbind/master/docs/_static/img/cppbind-logo.svg)

# Introduction

CppBind is a software development tool that automates language bindings
generation between C++ and other languages. It works by annotating C++
code to indicate parts desired to expose to all supported target
languages. The current version of the tool supports bindings with
**Swift**, **Kotlin**, and **Python**, while support for new languages
can be added relatively easily.

Manually developing bindings is complex, time-consuming, and
error-prone, especially for large-scale projects requiring frequent
changes. To develop manual bindings, one should be knowledgeable in both
C++ and the target language to implement types serialization from one
language to another, function and method mapping, and more. To overcome
these challenges, we introduce CppBind.

## CppBind main highlights:

-   Generates binding wrappers for multiple languages (Python, Swift,
    and Kotlin);
-   Allows using language-agnostic annotations for all supported
    languages;
-   Supports a rich set of C++ features;
-   Provides the ability to add support for other languages;
-   Can be used to generate bindings for third-party C++ libraries.

# Features

CppBind generates bindings for C++ types and entities like classes,
methods, global functions, enums, nested structures, templates, etc. The
list of the main features of CppBind is following:

- [Functions](https://cppbind.io/main_features/functions.html)
  - [Global functions](https://cppbind.io/main_features/functions.html#global-functions)
  - [Overloaded functions](https://cppbind.io/main_features/functions.html#overloaded-methods)
  - [Optional arguments](https://cppbind.io/main_features/functions.html#nullable-arguments)
  - [Default arguments](https://cppbind.io/main_features/functions.html#default-arguments)
  - [Return value's lifetime and ownership management](https://cppbind.io/main_features/functions.html#return-value-policies)
  - [Controlling function arguments' lifetime](https://cppbind.io/main_features/functions.html#keep-alive-policy)
- [OOP](https://cppbind.io/main_features/classes.html)
  - [Classes and structs](https://cppbind.io/main_features/classes.html)
  - [Nested types](https://cppbind.io/main_features/classes.html#nested-types)
  - [C++ classes/structs as target language interfaces](https://cppbind.io/main_features/classes.html)
  - [Enumerations](https://cppbind.io/main_features/enums.html)
  - [Inheritance](https://cppbind.io/main_features/inheritance.html)
    - [Single inheritance](https://cppbind.io/main_features/inheritance.html#single-inheritance)
    - [Multiple inheritance through the target language interfaces](https://cppbind.io/main_features/inheritance.html#multiple-inheritance)
  - [Object type preservation](https://cppbind.io/main_features/object_type_preservation.html)
  - [Static methods](https://cppbind.io/main_features/functions.html#static-methods)
  - [Method overloading](https://cppbind.io/main_features/functions.html#overloaded-methods)
  - [Converting getters/setters to target language properties](https://cppbind.io/main_features/functions.html)
  - [Operator overloading](https://cppbind.io/main_features/operators.html)
    - [Overloading subscript operator](https://cppbind.io/main_features/operators.html#overloading-subscript-operator)
  - [Templates](https://cppbind.io/main_features/templates.html)
    - [Template classes](https://cppbind.io/main_features/templates.html#class-templates)
    - [Template methods and functions](https://cppbind.io/main_features/templates.html)
    - [Converting getters/setters with template parameters to target language properties](https://cppbind.io/main_features/templates.html#template-getters-setters)
  - [Exception handling](https://cppbind.io/main_features/exception_handling.html)
  - [Standard library types (std::shared_ptr, std::vector, std::map, etc.)](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/containers)
  - [Custom type conversions](https://cppbind.io/advanced_topics/cppbind_snippets/custom_types.html)
  - [Intelligent code completion](https://en.wikipedia.org/wiki/Intelligent_code_completion)

# Usage

CppBind instructions are controlled using annotations. There are two
prominent use cases for annotating C++ source files: either you are the
source code owner, or it's from a third-party/standard library. CppBind
annotations are specified directly in the source files in the first
case. In the second case, separate config files can be used. The second
use case works well for binding third-party C++ libraries.

-   To configure a project with self-owned files, you can read our
    "Hello User"
    [tutorial](https://cppbind.io/first_steps/hello_user.html).
-   To configure a project with third-party/standard library files, you
    can read our "Array"
    [tutorial](https://cppbind.io/first_steps/array_tutorial.html).

Above-described usages can also be mixed: annotations for self-owned
files are written inside those files, while third-party/standard library
files are annotated via separate config files.

# Installation

There are some required steps to install and use CppBind. The
installation steps are described
[here](https://cppbind.io/first_steps/installation.html).

# License

CppBind is provided under the MIT license that can be found in the
[LICENSE](https://github.com/PicsArt/cppbind/blob/master/LICENSE) file.
By using, distributing, or contributing to this project, you agree to
the terms and conditions of this license.

# How to contribute to CppBind?

If you like CppBind and would like to contribute to this open-source
project, please check the [Contribution
guide](https://github.com/PicsArt/cppbind/blob/master/docs/CONTRIBUTING.md).
