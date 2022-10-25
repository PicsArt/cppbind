title: Binding C++ with Kotlin, Python, Swift
description: CppBind is a software development tool that automates 
            language bindings generation between C++ and Kotlin, Python, Swift.

![Binding C++ with Kotlin Python Swift](https://drive.google.com/uc?export=view&id=1ex-4r2ZNZK3f4eYr09me_7TREj8H-wln)

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

## Features

CppBind generates bindings for C++ types and entities like classes,
methods, global functions, enums, nested structures, templates, etc. The
list of the main features of CppBind is following:

-   

    [Functions](main_features/functions.md)

    :   -   [Global
            functions](main_features/functions.md#global-functions)
        -   [Overloaded
            functions](main_features/functions.md#overloaded-methods)
        -   [Optional
            arguments](main_features/functions.md#nullable-arguments)
        -   [Default
            arguments](main_features/functions.md#default-arguments)
        -   [Return value's lifetime and ownership
            management](main_features/functions.md#return-value-policies)
        -   [Controlling function arguments'
            lifetime](main_features/functions.md#keep-alive-policy)

-   

    [OOP](main_features/classes.md)

    :   -   [Classes and
            structs](main_features/classes.md)
        -   [Nested
            types](main_features/classes.md#nested-types)
        -   [C++ classes/structs as target language
            interfaces](main_features/classes.md)
        -   [Enumerations](main_features/enums.md)
        -   
            [Inheritance](main_features/inheritance.md)
            :   -   [Single
                    inheritance](main_features/inheritance.md#single-inheritance)
                -   [Multiple inheritance through the target language
                    interfaces](main_features/inheritance.md#multiple-inheritance)
        -   [Object type
            preservation](main_features/object_type_preservation.md)
        -   [Static
            methods](main_features/functions.md#static-methods)
        -   [Method
            overloading](main_features/functions.md#overloaded-methods)
        -   [Converting getters/setters to target language
            properties](main_features/functions.md)
        -   
            [Operator overloading](main_features/operators.md)
            :   -   [Overloading subscript
                    operator](main_features/operators.md#overloading-subscript-operator)
        -   
            [Templates](main_features/templates.md)
            :   -   [Template
                    classes](main_features/templates.md#class-templates)
                -   [Template methods and
                    functions](main_features/templates.md)
                -   [Converting getters/setters with template parameters
                    to target language
                    properties](main_features/templates.md#template-getterssetters)
        -   [Exception
            handling](main_features/exception_handling.md)
        -   [Standard library types (std::shared_ptr, std::vector,
            std::map,
            etc.)](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/containers)
        -   [Custom type
            conversions](advanced_topics/cppbind_snippets/custom_types.md)
        -   [Intelligent code
            completion](https://en.wikipedia.org/wiki/Intelligent_code_completion)

## Usage

CppBind instructions are controlled using annotations. There are two
prominent use cases for annotating C++ source files: either you are the
source code owner, or it's from a third-party/standard library. CppBind
annotations are specified directly in the source files in the first
case. In the second case, separate config files can be used. The second
use case works well for binding third-party C++ libraries.

-   To configure a project with self-owned files, you can read our
    "Hello User" [tutorial](first_steps/hello_user.md).
-   To configure a project with third-party/standard library files, you
    can read our "Array" [tutorial](first_steps/array_tutorial.md).

Above-described usages can also be mixed: annotations for self-owned
files are written inside those files, while third-party/standard library
files are annotated via separate config files.

## Installation

There are some required steps to install and use CppBind. The
installation steps are described [here](first_steps/installation.md).

## License

CppBind is provided under the MIT license that can be found in the
[LICENSE](https://github.com/PicsArt/cppbind/blob/master/LICENSE) file.
By using, distributing, or contributing to this project, you agree to
the terms and conditions of this license.

### Contributing

If you like CppBind and would like to contribute to this open-source
project, please check the [Contribution
guide](https://github.com/PicsArt/cppbind/blob/master/docs/CONTRIBUTING.md).
