from examples_lib.enums.color_pygen import Color
from examples_lib.enums.color_pygen import ColorShade
from examples_lib.optionals.optionals_pygen import Optionals
from examples_lib.simple import Root
from examples_lib.simple.task import PyTask

# [optionals-usage]
op = Optionals()

# default value assertions
assert op.optional_ptr_with_nullptr_default() is None
assert op.optional_ptr_with_null_default() is None
assert op.optional_int_with_default() == 5
assert op.optional_long_with_default() == 7
assert op.optional_double_with_default() == 9.0
assert op.optional_float_with_default() == 11.0
assert op.optional_bool_with_default() is True
assert op.optional_string_with_default() == "abc"
assert op.optional_string_view_with_default() == "abc"
assert op.optional_char_with_default() == ","
assert op.optional_shared_ptr_with_nullptr_default() is None
assert op.optional_enum_with_default() == Color.Red
assert op.optional_enum_with_default_and_field_prefix() == ColorShade.ShadeLight

# To check that optional enum values that are present in enum field excluded list are ignored
try:
    op.optional_enum_with_internal_default()
    assert False, "Default enum values that are present in enum field exclude list are not being ignored"
except TypeError:
    pass

assert op.single_complex_default_value().title == "MyTask"
assert op.single_complex_default_value().title == "MyTask"

# non default value assertions
task = PyTask('my task')
assert op.optional_string_view_with_default("test") == "test"
assert op.optional_ptr_with_nullptr_default(task) == task
assert op.optional_enum_with_default(Color.Blue) == Color.Blue
assert op.optional_enum_with_default_and_field_prefix(ColorShade.ShadeDark) == ColorShade.ShadeDark
assert op.optional_enum_with_internal_default(ColorShade.ShadeLight) == ColorShade.ShadeLight
assert op.optional_bool_with_default(False) is False
assert op.optional_char_with_default(':') == ':'
assert op.optional_long_with_default(8) == 8
assert op.optional_float_with_default(5.0) == 5.0
# [optionals-usage]

# multiple default values with complex and non - complex values
assert op.multiple_mixed_default_values() == "DefaultTask1DefaultRoot"
assert op.multiple_mixed_default_values(PyTask("ABC")) == "ABC1DefaultRoot"
assert op.multiple_mixed_default_values(PyTask("ABC"), i=2) == "ABC2DefaultRoot"
assert op.multiple_mixed_default_values(PyTask("ABC"), r=Root("Path")) == "ABC1Path"
assert op.multiple_mixed_default_values(PyTask("ABC"), i=2, r=Root("Path")) == "ABC2Path"
