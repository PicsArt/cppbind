from optionals.optionals_pygen import Optionals
from enums.color_pygen import Color
from simple.task import PyTask

# [optionals-usage]
op = Optionals()

# default value assertions
assert op.optional_ptr_with_nullptr_default() is None
assert op.optional_f_d_ptr_with_nullptr_default() is None
assert op.optional_int_with_default() == 5
assert op.optional_string_with_default() == "abc"
assert op.optional_char_with_default() == ","
assert op.optional_shared_ptr_with_nullptr_default() is None
assert op.optional_enum_with_default() == Color.Red

# non default value assertions
task = PyTask('my task')
assert op.optional_ptr_with_nullptr_default(task) == task
assert op.optional_enum_with_default(Color.Blue) == Color.Blue
# [optionals-usage]
