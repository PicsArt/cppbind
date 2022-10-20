# Command line interface

CppBind provides a command-line interface for running and configuration.
To see the list of available commands, use `cppbind --help`.

## cppbind init

``` bash
cppbind init
```

CppBind's command-line interface(CLI) allows us to create an initial
config file in the current directory. To generate the initial
configuration, run `cppbind init` under the project directory. This
creates `cppbind.yaml` file containing the initial config example.

~~~Yaml
{% 
include "../../src/cppbind/config/cppbind.yaml"
%} 
~~~

!!! Note
    If you are using Windows please make sure to set standard library
    include path in **win.include_dirs**: <br />
    - C:/mingw64/lib/clang/14.0.1/include

## cppbind run

``` bash
cppbind run <language_list>
```

To generate the bindings, use the `cppbind run` command by providing one
or more supported languages.

``` bash
cppbind run kotlin swift python
```

**Optional arguments:**

``` text
--log-level {DEBUG,INFO,WARNING,ERROR,CRITICAL}
                  The option can set a desirable log level from possible 5 values.

--error-limit ERROR_LIMIT
                  Amount of errors, after which CppBind stops the execution and reports an error.
                  The default value is -1, which means CppBind skips all noncritical errors and only
                  after the execution reports all encountered errors.
                  
--profile         Profiling code and generating reports

--out_prj_dir OUT_PRJ_DIR
                  The root directory of project output.
                  All includes and imports are generated relative to this directory.

--cxx_out_dir CXX_OUT_DIR
                  The root directory where all C bindings are stored.

--out_dir OUT_DIR
                  Directory where generated target language files are saved.

--target_arch TARGET_ARCH
                  Variable for setting target architecture.
```

!!! Note
    Most of the optional arguments are command-line level CppBind variables.
    For more info see `cmd_line` in [Variable Definitions](../main_features/var_def.md).

!!! Note
    To visualize profiling results you can use snakeViz browser based graphical viewer.
    : Install with pip:
        : **pip install snakeviz**
    : Start SnakeViz from the command line:
        : **snakeviz profile.prof**

## cppbind clean

To clean all generated files from the given directory, use this command.

``` bash
cppbind clean <dir>
```

!!! Note
    `cppbind clean` works by finding and removing all files that contain
    the CppBind banner logo. <br />
    Make sure not to remove banner logos from the generated files.
