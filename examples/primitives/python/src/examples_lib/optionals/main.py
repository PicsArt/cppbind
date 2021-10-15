from examples_lib.optionals.optionals_pygen import Optionals
from examples_lib.enums.color_pygen import Color
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
assert op.optional_ref_with_default_complex_value().title == "MyTask"
assert op.optional_by_val_with_default_complex_value().title == "MyTask"

# non default value assertions
task = PyTask('my task')
assert op.optional_string_view_with_default("test") == "test"
assert op.optional_ptr_with_nullptr_default(task) == task
assert op.optional_enum_with_default(Color.Blue) == Color.Blue
assert op.optional_bool_with_default(False) is False
assert op.optional_char_with_default(':') == ':'
assert op.optional_long_with_default(8) == 8
assert op.optional_float_with_default(5.0) == 5.0
# [optionals-usage]
