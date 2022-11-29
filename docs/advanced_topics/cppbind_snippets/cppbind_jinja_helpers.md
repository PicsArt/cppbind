# CppBind jinja helpers

CppBind uses jinja template language to describe the content
of the generated code. Jinja provides some helper functions which
are called filters and tests. Filters are used to modify variables and
are separated from the variable by a pipe symbol (**|**). Examples of
jinja builtin filters are: **attr**, **default**, **join**, **select**, etc.
Tests are used to test a variable against an expression. Examples
of builtin jinja tests are: **eq**, **in**, **filter**, **defined**, etc.
More detailed information about jinja filters and tests can be found
[here](https://jinja.palletsprojects.com/en/3.1.x/templates/#filters).

CppBind provides a set of custom filters and tests which can help
users to reuse some common logic and avoid nasty and long `for` cycles and
`if/else` blocks.

## CppBind jinja filters

Here is the set of custom jinja filters provided by CppBind:

- [all](#all)
- [any](#any)
- [decapitalize](#decapitalize)
- [format_list](#format_list)
- [has_api](#has_api)
- [increment](#increment)
- [join_unique](#join_unique)
- [make_doxygen_comment](#make_doxygen_comment)
- [make_py_comment](#make_py_comment)
- [make_py_docstring](#make_py_docstring)
- [map_callback](#map_callback)
- [path_join](#path_join)
- [replace_regex](#replace_regex)
- [set](#set)
- [sort_python_code](#sort_python_code)
- [sort_snippets](#sort_snippets)
- [to_camel_case](#to_camel_case)
- [to_snake_case](#to_snake_case)
- [type](#type)
- [type_converter](#type_converter)
- [type_info](#type_info)
- [unique_snippets](#unique_snippets)
- [zip](#zip)

### all

`all(value: Iterable) -> bool`

Operates like python **all** function: returns True if all
items in an input iterable are True, otherwise returns False. Can be applied to
any iterable object: `iterable_object|all`.

### any

`any(value: Iterable) -> bool`

Operates like python **any** function: returns True if any
item of an input iterable is True, otherwise returns False. Can be applied to
any iterable object: `iterable_object|any`.

### decapitalize

`decapitalize(value: str) -> str`

Operates on a string by making the first character lowercase:
`a_string|decapitalize`.

### format_list

`format_list(value: list[Any], format_string: str, arg_name: str = None) -> list[str]`

Operates on a list of objects by applying provided format to all items:
`list_of_strings|format_list('#include {}')`. In this example we add include
directives to the all items of the input list. The filter works just like
python **format** function. In addition, the placeholder in the format string can
also be identified using named index with the help of **arg_name** optional argument:
`list_of_strings|format_list('#include {item.name}', arg_name='item')`. The value
provided by **arg_name** keyword will be replaced with the input data current item
(**item.name** is an example of the usage with item property access).


### has_api

`has_api(value: CXXElement) -> bool`

Returns whether the given cxx element has a CPPBind API or not.

### increment

`increment(value: int|float, amount: int|float = 1) -> int|float`

Operates on a numeric value by incrementing it by the given input
value. Default increment amount is 1: `numeric_value|increment`, `numeric_value|increment(5)`.

### join_unique

`join_unique(value: list[str]) -> str`

Operates on a list of strings by joining items with the special **marker** provided by CppBind.
Has the same result as `join(marker)`. CppBind splits the content of the rendered **unique_content**
section by **marker**, picks unique tokens and joins them to get the final result.
In CppBind snippets this filter is mainly used to manipulate include/import related code snippets.

### make_doxygen_comment

`make_doxygen_comment(value: str|list[str], style: DoxygenCommentStyle = DoxygenCommentStyle.CPP) -> str`

Operates on a string or a list of strings and makes a Doxygen style
comment from the given input. CppBind provides an option to define the style
of a Doxygen comment: **DoxygenCommentStyle.CPP** will wrap the input string(s)
with **///** symbols, and **DoxygenCommentStyle.JAVADOC** will wrap with
the ***** symbols. Default one is JAVADOC.
Examples of usages: `comment|make_doxygen_comment`,
`comment|make_doxygen_comment(style=DoxygenCommentStyle.CPP)`.

### make_py_comment

`make_py_comment(value: list[str]) -> str`

Operates on a list of strings by commenting them with **#** python comment
symbols: `comment_list|make_py_comment`.

### make_py_docstring

`make_py_comment(value: str|list[str]) -> str`

Operates on a string or a list of strings and makes a python docstring
from the given input: wraps the input with the **"""** symbols: `input_value|make_py_docstring`.

### map_callback

`map_callback(value: Any, callback: Callable) -> Any`

Operates on a single value or an iterable object and returns the result
by applying the provided callback on all items (on a single value):
`list_of_strings|map_callback(decapitalize)`.

### path_join

`path_join(value: list[str]) -> str`

Operates on a list of strings and joins them by os path separator
(works as python **os.path.join** function):
`[path_part_1, path_part_2, "file_name"]|path_join`.

### replace_regex

`replace_regex(value: str, pattern: str, repl: str, count: int = 0) -> str`

Operates on a string like python **re.sub** function:
replaces the occurrences in a string with the given replacement string
in case they match the provided regex pattern. By default, it replaces all
the occurrences, which can be changed with **count** parameter:
`a_string|replace_regex(pattern, replacement_string)`,
`a_string|replace_regex(pattern, replacement_string, count=1)`.

### set

`set(input: Iterable) -> set`

Returns a Python `set` from the given iterable.

### sort_python_code

`sort_python_code(value: list[str]) -> str`

Operates on a list of strings by sorting them in 'pythonic' way
(uses **isort.api.sort_code_string** function): `list_of_import_strings|sort_python_code`.
This is used to sort python import statements.

### sort_snippets

`sort_snippets(value: list[str], cmp: Callback, reverse: bool = False) -> list[str]`

Operates on a list of strings and sorts them by the given comparator
(default one is the **<** operator): `list_of_strings|sort_snippets`,
`list_of_strings|sort_snippets(cmp=custom_comparator_function)`.
It's also possible to use the reverse order while sorting:
`list_of_strings|sort_snippets(cmp=comparator, reverse=True)`.

### to_camel_case

`to_camel_case(value: str, sub_strings: list[str] = None, capitalize: bool = False) -> str`

Operates on a string and makes the camel case version of the input string.
This filter has two optional arguments: **sub_strings** - list of substrings
to be replaced with their camel cased versions, and **capitalize** boolean
argument to capitalize the result (default value is False).
Examples of usages: `a_string|to_camel_case`, `a_string|to_camel_case(capitalize=True)`,
`a_string|to_camel_case(sub_strings=[substring_1, substring_2])`.

### to_snake_case

`to_snake_case(value: str, sub_strings: list[str] = None) -> str`

Operates on a string and makes the snake case version of the input string.
This filter has an optional argument: **sub_strings** - list of substrings
to be replaced with their snake cased versions.
Examples of usages: `a_string|to_snake_case`,
`a_string|to_snake_case(sub_strings=[substring_1, substring_2])`.

### type

`type(value: Any) -> Any`

Operates on a single value or a list of objects, where the items have
**type** property. Returns the **type** properties of the given input(s).
Examples of usages: `object_with_type_prop|type`, `list_of_objects|type`.
This filter is equivalent to `map(attribute='type')`.

### type_converter

`type_converter(value: str|CXXExposedType, attribute: str = None, error: bool = True) -> TypeConverter`

Operates on a single object or a list of objects, where the items must be
of type **str** or a special cxx type provided by CppBind (the type provides
access to several cxx related properties: **cxx** section described [here](type_converter_snippets.md#available-variables)).
This filter helps to look up a converter for the given cxx type/type_name:
`cxx.base_types|type_converter`, `'std::string'|type_converter`.
When the desired converter is not found, CppBind throws a specific exception.
But this default behavior can be changed with the optional **error** parameter:
`cxx_type|type_converter(error=False)`, which will return **None** if no
converter is found. Also, it's possible to use **attribute** parameter for applying
the filter to a specific attribute of the input object(s):
`cxx.args|type_converter(attribute='type')`. Attributes can also be chained with
multiple dots: `cxx|type_converter(attribute='prop1.prop2')`.

### type_info

`type_converter(value: str|CXXExposedType, attribute: str = None, error: bool = True) -> TypeInfo`

Operates on a single object or a list of objects, where the items must be
of type **str** or a special cxx type provided by CppBind (the type provides
access to several cxx related properties: **cxx** section described [here](type_converter_snippets.md#available-variables)).
This filter helps to look up a type information for the given cxx type/type_name:
`cxx.base_types|type_info`, `'std::sring'|type_info`.
When the desired info is not found, CppBind throws a specific exception.
But this default behavior can be changed with the optional **error** parameter:
`cxx_type|type_info(error=False)`, which will return **None** if no
type info is found. Also, it's possible to use **attribute** parameter for applying
the filter to a specific attribute of the input object(s):
`cxx.args|type_info(attribute='type')`. Attributes can also be chained with
multiple dots: `cxx|type_info(attribute='prop1.prop2')`.

### unique_snippets

`unique_snippets(value: str|list[str]) -> set[str]`

Operates on a string or a list of strings and filters unique code snippets after
splitting the input by special **marker** provided by CppBind. **marker** is used
to control which fragments of a snippet must be unique.

### zip

`zip(*inputs: Iterable) -> Generator[types.SimpleNamespace]`

Operates on two or more iterable arguments and generates a series of namespaces
containing indices and series of tuples containing elements from each iterable.
The items can be accessed by **_idx** property, where idx is an index(1-based) of the item.
For example, the result of `[a1, a2]|zip([b1, b2])` will be a generator which
will result to the following list: `[namespace(_1=a1, _2=b1), namespace(_1=a2, _2=b2)]`.

## CppBind jinja tests

Here is the set of custom jinja tests provided by CppBind:

- [contains](#contains)
- [has_api](#has_api)
- [match_regex](#match_regex)
- [startswith](#startswith)

### contains

`contains(value: Iterable, item: Any) -> bool`

This test works just like python **in** operator: checks whether the input iterable
object contains the provided item: `input_list.contains(item)`.
For example, this test can also be used in conjunction with **select** jinja filter
in order to select only the items satisfying the test:
`list_of_strings|select('contains', string_value)`.

### match_regex

`match_regex(value: str, *patterns: str) -> bool`

Checks whether the given input string matches the provided regex pattern (or one
of the provided patterns): `input_string.match_regex(pattern)`.
An example of a usage with a filter with multiple patterns:
`list_of_strings|select('match_regex', pattern1, pattern2)`.

### startswith

`startswith(value: str, prefix: str) -> bool`

This test works just like python **startswith** function: checks whether the input
string starts with the provided prefix string: `input_string.startswith(prefix)`.
This test also can be used with `select/reject` and other filters.

