# Application configuration

CppBind application configuration is done via **cppbind_config.cfg**
file, which can be placed under the project root directory. If there is
no user-provided application config file, then CppBind uses the default
one:

~~~ini
{% 
include "../../src/cppbind/config/cppbind_config.cfg"
%} 
~~~

The application config file contains the following main sections:

-   [Application](#application)
-   [API](#api)
-   [Log](#log)

!!! Note
    If a parameter is missing from the application config file, then the
    CppBind default value for that parameter will be used. In the above code
    block, you can see all default values for uncommented parameters.
    Parameters that are commented on do not have default values.

!!! Note
    Keys in sections are case-insensitive and stored lowercase.

## APPLICATION

The APPLICATION section defines parameters related to the whole
application. Let's go over the parameters from this section:

-   **custom_config_dir** - Directory containing user-defined type
    converter yaml files. For more details go to
    [Writing type converter](../advanced_topics/cppbind_snippets/custom_types.md).
-   **custom_helpers_dir** - Directory containing user-defined python modules which can be used in jinja snippets
    by their names. Modules search is done with `/**/<language>/**/*.py` pattern. 
    An example can be found in **my_lang** [example](https://github.com/PicsArt/cppbind/tree/master/examples/tests).
    In this example there's a helper module(my_lang.py) under **helpers/my_lang** directory which is used in **code_snippets.yaml**(`{%- do my_lang.validate_default_helper_module() -%}`). 

-   **context_def_glob** - Glob pattern of project configuration yaml
    files.

-   **rule** - Python module defining jinja template contexts. If the
    user does not want to generate custom code, there's no need to
    override this parameter.

-   **all_languages** - List of supported languages.

-   **all_platforms** - List of supported platforms.

-   **error_limit** - Amount of errors after which CppBind stops the
    execution and reports an error. The default value is -1, which
    means CppBind skips all noncritical errors and only after the
    execution reports all encountered errors.
    This parameter can also be set from the command line
    (-error-limit).

## API

-   **parser_start** - Tag in the doxygen style comment, after which
    everything is considered as instructions for CppBind.

## LOG

-   **log_file** - Logging file where CppBind logs are stored. If empty,
    the standard output is considered.
-   **level** - Logging level.

Log level can be set/modified from command line arguments.
**-log-level** option can be used to set desirable log level from 5
possible values: DEBUG, INFO, WARNING, ERROR, CRITICAL.
