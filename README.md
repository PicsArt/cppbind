### Table of contents
- [About the project](#about-the-project)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Specification](#specification)
    * [Commands](#commands)
    * [Attributes](#attributes)
    * [Python API](#python-api)
    * [Context](#context)
    * [Builder](#builder)
 - [Utils](#utils)

# About the project
C++ public API Java, Obj-C binding generator

We need to generate C++ public API binding for various languages

# Installation

### System requirements
 Operating system: Linux, Mac, Windows
 
### Dev environment setup
- Clone iegen master branch into current directory.
 ```bash
 git clone  https://github.com/PicsArt/iegen.git
 ```
- If the project is already cloned, pull the latest version:

 ```bash
 git fetch
 git pull
 ```

#### Linux setup


 + **Update/upgrade the system**:
 ```bash
 # Linux
 sudo apt-get update
 sudo apt-get upgrade
 ```
 + **Install required libs**:
 ```bash
 sudo apt-get install -y libclang-9-dev
 ```

 + **Python Installation**

Check python version and if its >= 3.7 then skip this step
 ```bash
 python3 --version
 ```

 ```bash
 sudo apt install software-properties-common
 sudo add-apt-repository ppa:deadsnakes/ppa
 sudo apt install python3.7
 sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.7 1
 sudo update-alternatives --config python3
 python3 -m pip install --upgrade pip
 python3 -m pip install virtualenv
 ```

 + **Create and activate virtualenv**
 ```bash
 cd /path/to/project/
 python3 -m venv venv
 source venv/bin/activate
 ```
  
#### Mac OS X setup

 + **Missing headers fix**
 For MacOS version 10.14 or below 
 ```
 open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_{version}.pkg
 echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Library/Developer/CommandLineTools/usr/lib"' >> ~/.profile
 ```
For higher versions

 
 + **Python Installation**

Check python version and if its >= 3.7 then skip this step
 ```bash
 python3 --version
 ```
 ```bash
 brew install python@3.7
 echo 'export PATH="/usr/local/opt/python@3.7/lib:$PATH"' >> ~/.profile
 python3 -m pip install virtualenv
 ```

 + **Create and activate virtualenv**
 ```bash
 cd /path/to/project/
 python3 -m venv venv
 source venv/bin/activate
 ```

### Installation

 ```bash
 pip3 install -r src/requirements
 python3 setup.py install
 ```

Installation is complete to test run the following command
  ```iegen -h``` 

# Configuration
 
 Create **iegen_config.cfg** file under working directory.
 The following is an example of iegen_config file.
 ```
    [DEFAULT]
        out_prj_dir=/path/to/output/
        cxx_base_out_dir=%(source_dir)s/core/
        source_dir = ./source/
        src_glob = *.h*
        run_dir = package_name
        include_dirs = /path/to/somae/sources/, /usr/lib/jvm/java-11-openjdk-amd64/include
                    , /usr/lib/jvm/java-11-openjdk-amd64/include/linux
        
    
    [KOTLIN]
        package_prefix = com.company.package
        clang_args = -D__ANDROID__
        out_src_dir = source/main/java/
        out_dir = %(out_prj_dir)s/%(run_dir)s/android/%(run_dir)s/%(out_src_dir)s

    [LOG]
        log_file = 
        level = INFO
 ```
  **DEFAULT** section.  
  This section configs are common for all languages and can be overridden for each language.
  
   - **_out_prj_dir_** - Root directory where output files will be saved.  
   - **_cxx_base_out_dir_** - Base classes will be copied into this directory, they can be used by source classes. An example of base class is the Object class.  
   - **_source_dir_** - Directory containing source files which are going to be processed.  
   - **_src_glob_** - File pattern used to find files from source_dir.  
   - **_include_dirs_** - Directories which contain sources that are used by the files to be processed.  
   - **_run_dir_** - This can be used in out_dir.
  
  **KOTLIN** section.
 
  - **_package_prefix_** - Package name for generated kotlin files.  
  - **_clang_args_** - Arguments passed to clang parser.  
  - **_out_src_dir_** - Source directory used as a part of out_dir.  
  - **_out_dir_** - Full directory where output files will be saved.  
  
  **LOG** section.
  - **_log_file_** - If no file specified then the logs will be redirected to stdout.
  - **_log_level_** - INFO, DEBUG, etc.

# Usage

- After proper configuration run the following command to get base classes copied.
 ```
  iegen kotlin  
 ```  
- To use iegen all namespaces, classes, methods, etc. need to be properly commented.
The following is an example of commented source file.
```/**
 * comments
 * 
 * __API__
 * kotlin.file: utils
 * kotlin.prefix: PI
 */
namespace pi::utils {
    /**
     * commants
     * 
     * __API__
     * gen: class
     * shared_ref: False
     * kotlin.module: pi.xxx.Example
     */
    struct Example
    {
        /**
         * comments
         * 
         * __API__
         * gen: enum
         * swift.name: ExampleType
         */
        enum class Type { A, B, C };

        /**
         * comments
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example(int& x, std::string name = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        Type f(Type t, int i =10, char* test = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        int get_attribute(char* test = "XXX");
    };
    /**
     * comments
     * 
     * __API__
     * gen: enum
     * swift.name: ExampleType
     */
    enum class Type2 { A2, B2, C2 };
}
```
Comments below **\_\_API__** keyword are used for parsing.  
It's required to specify **gen** for each class, enum, constructor, method, getter, setter that need to be parsed.  
Everything used for **\_\_API__** except **gen** are called attributes.  
All acceptable attributes are the following.
```
file:
  inheritable: true
  default: '{file_name}'
  allowed_on: [ class, struct, namespace, enum ]

file_full_name:
  inheritable: true
  default: '{file_full_name}'
  allowed_on: [ class, struct, namespace, enum ]

module:
  inheritable: false
  default: '{module_name}'
  allowed_on: [ class, struct, namespace, enum ]

package:
  inheritable: true
  default: 'undefined'
  allowed_on: [ class, struct, namespace, enum ]

name:
  inheritable: false
  default: '{object_name}'

include:
  inheritable: true
  array: true
  default: [ ]
  allowed_on: [ namespace ]

shared_ref:
  inheritable: true
  default: false
  allowed_on: [ class, struct ]
```
Where
- **file** - File name for the generated file. If not specified then the actual file name will be used.
- **file_full_name** - If not specified then the original file's absolute path is taken. 
- **module** - Module's name. This attribute is not used for kotlin.
- **package** - Package name which with **package_prefix** from iegen_config.cfg file is used for the final package ({package_prefix}.{package}).
- **name** - Name of the class, namespace etc. If not specified then the actual name will be used.
- **include** - Additional includes that will be added to the generated file.
- **shared_ref** - If true creates a shared pointer instance.
Values which are using curly braces are generated at runtime.

Attribute properties
- **inheritable** indicates whether attribute is inherited from it's parent or no,
- **default** indicates the default value,
- **allowed_on** indicates on which units the attribute is allowed to be used,
- **array** indicates if attribute can be used for multiple times or no

You can provide a language before the attribute, in this case the value will be used only for that language.

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



# Utils

## ast_dump
 Dumps c++ code using clang parser.

**example:** 
```bash
bin/utils/ast_dump ./experiments/example.cpp
```
