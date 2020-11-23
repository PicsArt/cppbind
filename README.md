# iegen
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

# iegen installation for developers

1. Clone iegen master branch into current directory.
 ```bash
 git clone  https://github.com/PicsArt/iegen.git
 ```
2. If the project is already cloned, pull the latest version:

 ```bash
 git fetch
 git pull
 ```
## Installing requirements

### Dev setup
 + #####Update/upgrade the system:
 ```bash
 # Linux
 sudo apt-get update
 sudo apt-get upgrade
 ```
 + #####Install required libs:
 ```bash
 sudo apt-get install -y libclang-9-dev
 ```

+ #####Install Python

    Check python version and if its >= 3.6 then skip this step
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
 ```

+ #####Create and activate virtualenv
 ```bash
 python3 -m pip install virtualenv
 cd /path/to/project/
 python3 -m venv venv
 source venv/bin/activate
 ```

+ #####Install requirements and the project
 ```bash
 pip3 install -r src/requirements
 python3 setup.py install
 ```
  Now iegen should work, to test run the following command
  ```iegen -h``` 
  
 + #####Configuration
 
 Under the working direactory iegen_config.cfg file needs to be created.
 The following is an example of iegen_config file.
 ```
    [DEFAULT]
        out_prj_dir=/mnt/c/workspace/test_iegen/out/
        cxx_base_out_dir=%(source_dir)s/core/
        source_dir = ./pi/
        src_glob = video_engine/model/**/*.h*
        run_dir = video_engine
        include_dirs = /mnt/c/workspace/test_iegen/, /usr/lib/jvm/java-11-openjdk-amd64/include
                    , /usr/lib/jvm/java-11-openjdk-amd64/include/linux
        
    
    [KOTLIN]
        package_prefix = com.picsart.video_engine
        clang_args = -D__ANDROID__
        package_prefix = com.picsart.example_lib
        out_src_dir = source/main/java/
        out_dir = %(out_prj_dir)s%(run_dir)s/android/%(run_dir)s/%(out_src_dir)s
 ```
  DEFAULT section configs are common for all languages and can be overridden for each language.
  
   - **_out_prj_dir_** - Root directory where output files will be saved.  
   - **_cxx_base_out_dir_** - Base classes will be copied under this directory, they can be used by source classes an example is Object class.  
   - **_source_dir_** - Directory containing source files which are going to be processed.  
   - **_src_glob_** - File pattern, used to find files from source_dir.  
   - **_include_dirs_** - Directories which contain sources that are used by the files to be processed.  
   - **_run_dir_** - This can be used in out_dir.
  
  Kotlin configuration.
 
  - **_package_prefix_** - Package name for generated kotlin files.  
  - **_clang_args_** - Arguments passed to clang parser.  
  - **_out_src_dir_** - Source directory used as a part of out_dir.  
  - **_out_dir_** - Full directory where output files will be saved.  


Now after configuration, files can be processed using the following command
 ```
  iegen kotlin  
 ```  


# Utils

## ast_dump
 Dumps c++ code using clang parser.

**example:** 
```bash
bin/utils/ast_dump ./experiments/example.cpp
```
