
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

-   

    [Functions](03_get_started/01_functions.md)

    :   -   [Global
            functions](03_get_started/01_functions.md#global-functions)
        -   [Overloaded
            functions](03_get_started/01_functions.md#overloaded-methods)
        -   [Optional
            arguments](03_get_started/01_functions.md#nullable-arguments)
        -   [Default
            arguments](03_get_started/01_functions.md#default-arguments)
        -   [Return value's lifetime and ownership
            management](03_get_started/01_functions.md#return-value-policies)
        -   [Controlling function arguments'
            lifetime](03_get_started/01_functions.md#keep-alive-policy)

-   

    [OOP](03_get_started/02_classes.md)

    :   -   [Classes and
            structs](03_get_started/02_classes.md)
        -   [Nested
            types](03_get_started/02_classes.md#nested-types)
        -   [C++ classes/structs as target language
            interfaces](03_get_started/02_classes.md)
        -   [Enumerations](03_get_started/03_enums.md)
        -   
            [Inheritance](03_get_started/04_inheritance.md)
            :   -   [Single
                    inheritance](03_get_started/04_inheritance.md#single-inheritance)
                -   [Multiple inheritance through the target language
                    interfaces](03_get_started/04_inheritance.md#multiple-inheritance)
        -   [Object type
            preservation](04_advanced_features/05_object_type_preservation.md)
        -   [Static
            methods](03_get_started/01_functions.md#static-methods)
        -   [Method
            overloading](03_get_started/01_functions.md#overloaded-methods)
        -   [Converting getters/setters to target language
            properties](03_get_started/01_functions.md)
        -   
            [Operator overloading](03_get_started/07_operators.md)
            :   -   [Overloading subscript
                    operator](03_get_started/07_operators.md#overloading-subscript-operator)
        -   
            [Templates](03_get_started/06_templates.md)
            :   -   [Template
                    classes](03_get_started/06_templates.md#class-templates)
                -   [Template methods and
                    functions](03_get_started/06_templates.md)
                -   [Converting getters/setters with template parameters
                    to target language
                    properties](03_get_started/06_templates.md#template-getterssetters)
        -   [Exception
            handling](03_get_started/05_exception_handling.md)
        -   [Standard library types (std::shared_ptr, std::vector,
            std::map,
            etc.)](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/containers)
        -   [Custom type
            conversions](04_advanced_features/02_custom_types.md)
        -   [Intelligent code
            completion](https://en.wikipedia.org/wiki/Intelligent_code_completion)

# Usage

CppBind instructions are controlled using annotations. There are two
prominent use cases for annotating C++ source files: either you are the
source code owner, or it's from a third-party/standard library. CppBind
annotations are specified directly in the source files in the first
case. In the second case, separate config files can be used. The second
use case works well for binding third-party C++ libraries.

-   To configure a project with self-owned files, you can read our
    "Hello User" [tutorial](02_first_steps/04_hello_user.md).
-   To configure a project with third-party/standard library files, you
    can read our "Array" [tutorial](02_first_steps/05_array_tutorial.md).

Above-described usages can also be mixed: annotations for self-owned
files are written inside those files, while third-party/standard library
files are annotated via separate config files.

# Installation

There are some required steps to install and use CppBind. The
installation steps are described [here](02_first_steps/03_installation.md).

# License

CppBind is provided under the MIT license that can be found in the
[LICENSE](https://github.com/PicsArt/cppbind/blob/master/LICENSE) file.
By using, distributing, or contributing to this project, you agree to
the terms and conditions of this license.

# How to contribute to CppBind?

If you like CppBind and would like to contribute to this open-source
project, please check the [Contribution
guide](https://github.com/PicsArt/cppbind/blob/master/docs/CONTRIBUTING.md).
