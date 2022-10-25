# Yaml configuration file management

CppBind provides several helper constructors to work with yaml config files
more easily. Those constructors mainly are helping to keep configuration
sections in separate yaml files, then combine them with each other.

The list of the yaml constructors provided by CppBind:

- [include](#include)
- [join](#join)
- [concat](#concat)

## **include**

Yaml **include** constructor helps including one yaml file content into
another one. Here is an example:

``` yaml    
section_in_main_file:
  !include dir_of_included_file/name_of_included_file.yaml
```

The result of this constructor is the same as we would have by writing
the content of the included yaml file in our main file.
In front of the **!include** command we need to specify the path of the
included file. CppBind has special rules for looking up the included file.
It searches the file in CppBind internal config directory, in the custom
directory defined by the user in the application config file and in the directory
where the main yaml file is located. When user wants to include custom written yaml files,
**custom_config_dir** variable must be set in the application config file. More information about
application configuration can be found  [here](../../configuration/app_config.md#application).
Otherwise, the user must place the included files under the directory where
the main yaml file is located.

It's possible to use file glob patterns in the definition of the included yaml file path:
``` yaml
section_in_main_file:
  !include dir_of_included_file/*.yaml
```
This will include all the files with yaml extension.

!!! Note
    Included files must have **yaml** or **yml** extensions.

It's also possible to include only some nodes of the file instead of
including the whole content. It is done using **&** symbol:
``` yaml
section_in_main_file:
  !include name_of_included_file.yaml&section_name
```

For including only a subsection, **.** (dot) symbol can be used:
``` yaml
section_in_main_file:
  !include name_of_included_file.yaml&section_name.subsection_name
```

User can also specify a nested subsection by using multiple dots:
``` yaml
section_in_main_file:
  !include name_of_included_file.yaml&section_name.subsection_name.nested_subsection_name
```

If the node is a sequence, it's possible to select a particular section by index:
``` yaml
section_in_main_file:
  !include name_of_included_file.yaml&list_section_name.0
```

## **join**

**join** constructor is used for merging several nodes of yaml files with
each other. The result is a union of joined nodes. If there are sections having
the same keys in the input nodes, then the node coming later overwrites the
former one. It's highly flexible to use this constructor with **include**
constructor:

``` yaml
section_in_main_file:
  !join
  - !include file1.yaml
  - !include file2.yaml
  - section_name:
      subsection_name: ...
```

!!! Note
    This constructor operates only on yaml list.

## **concat**

**concat** constructor is used to concatenate the string contents of several
nodes with each other. It's also useful to combine **concat** and **include** constructors:

``` yaml
section_in_main_file:
  !concat
  - !include file1.yaml&section_name
  - !include file2.yaml&section_name
  - |
    section_name: ...
```

!!! Note
    This constructor operates only on yaml list, items of which must be strings.

This constructor is mainly used to include jinja macros defined in other files, and
call them in the place where concat is done:

``` yaml
section_in_main_file:
  !concat
  - !include file_where_macro_is_defined.yaml
  - |
    section_name: {{macro_name()}}
```
