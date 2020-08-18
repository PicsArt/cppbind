# iegnen
C++ public API Java, Obj-C binding generator


We need to generate C++ public API binding for various languages


# Specification

## Commands

Commands are predefined macros in C++ by which users can annotate the code. Example, to generate class wrappers in other languages, the user adds macro ``IEG_GEN_CLASS`` on top of class, for getter and setter the user can write ``IEG_GEN_GETTER``, ``IEG_GEN_SETTER``, for methods ``IEG_GEN_METHOD``.

### Commands list
```c++
IEG_GEN_CLASS
IEG_GEN_ENUM
IEG_GEN_GETTER
IEG_GEN_SETTTER
IEG_GEN_METHOD
```
### Attributes

Attributes are additional generation rules for specific commands. For example, users can specify the name for the generated class ``IEG_NAME(MyClassName)`` or for specific language ``IEG_NAME(MyJavaName, java)``.

### Attributes list
```c++
// class, namespace, enum, method, set, get
IEG_NAME(name)
IEG_NAME(name, platform)

// file, namespace, class, enum
IEG_FILE(name)
IEG_FILE(name, platform)

// file, namespace, class, enum
IEG_MODULE(name)
IEG_MODULE(name, platform)

//all commands
IEG_INFO(field, value)
IEG_INFO(field, value, platform)
```
## Python API

All code generation rules are defined via python. The generator defines a strict API by which users can write rules to build generated code.  Library has 2 key classes - context and builder. For each command corresponding python function will be called with context and builder arguments.  Example:
```python
def gen_class(context, builder):
	context.module
	context.file
	context.info.is_ref
	# code
```
## Context

Context is a class which provides contextual information about current commands. For example for IEG_GEN_METHOD command contextual information is file name, return value type information, arguments information, method name, keywords (static) and also user additional attributes (IEG_NAME, …). 
Also context must have a method which will return another context  of the  other command located in the same level or above. The levels are defined by opening “{“ and closing “}” scopes in c++ code. This feature will be useful for getter and setter generation in such  languages as swift or kotlin.
Context has property type which represents the type information about the current command type. It can be “file”, “class”, “enum”, “method”, “getter”, “setter”, … (Also the typing can be done with class inheritance). Context has a mutable ‘info’ object. Each command function can modify the info object properties. Also the IEG_INFO(field, value) attribute will add a field to the ‘info’ object.

Note: command functions will be called by command list order.

## Builder
Builder is a class that provides functionality to build code via string.

Builder has scopes and can create and share files alonge all builders. Each file has a name and physical path and it is also derived from Scope. Scope is a logical code snapped which has relative tabulation. 
Scope provides an API to add lines to the top, bottom and current cursor position.
Builders files are stored in a flat list. 
Builders scopes are stored in a stack. The scope get function returns last scope with the given name.
Each builder is associated with its context.  

```python
def gen_class(context, builder):
	file_path = # path
	# get or create logical file
	builder.get_file(contex.file_name, file_path).add([
			f“class {context.name} {{”,
			Scope(“class_body”, tab = 4),
			“}}”
	])

def gen_method(context, builder):
	args = # build args code
	builder.get_scope(‘class_body’).add([
		f“{context.return_type} {context.metod_name}({args}) {{”,
		Scope(“method_body”), # default tab=4
		“}}”
	])

	builder.get_scope(“method_body”).add([
		….code
	])


//////////////////////////////////// OBJ-C
def gen_class(context, builder):
	file_path = # path
	# get or create logical file
	builder.get_file(contex.file_name+’.h’, file_path).add([
			f“class {context.name} {{”,
			Scope(“class_decl”, tab = 4),
			“}}”
	])

	builder.get_file(contex.file_name+’.mm’, file_path).add([
			f“class {context.name} {{”,
			Scope(“class_imp”, tab = 4),
			“}}”
	])

def gen_method(context, builder):
	args = # build args code
	builder.get_scope(‘class_decl’).add([
			f“{context.return_type} {context.metod_name}({args}) {{”,
			Scope([
					F“aaaa”,
					F“aaaa”,
					f“aaaa”,
			])
			“}}”
	])

	builder.get_scope(“method_body”).add([
			….code
	])

	args = # build args code

	builder.get_scope(‘class_impl’).add([
			f“{context.return_type} {context.metod_name}({args}) {{”,
			Scope([
					F“aaaa”,
					F“aaaa”,
					f“aaaa”,
			])
			“}}”
	])


```


# System requirements
 Operating system: Linux, Mac, Windows

# iegnen installation for developers

1. Clone iegnen master branch into current directory.
 ```bash
 git clone  https://github.com/PicsArt/iegnen.git
 ```
2. If the project is already cloned, pull the latest version:

 ```bash
 git fetch
 git pull
 ```
## Installing requirements

 + Update/upgrade the system:
 ```bash
 # Linux
 sudo apt-get update
 sudo apt-get upgrade
 ```
 + Install required libs:
 ```bash
 sudo apt-get install -y libclang-dev
 ```


# Utils

## ast_dump
 Dumps c++ code using clang parser.

**example:** 
```bash
bin/utils/ast_dump ./experiments/example.cpp
```
