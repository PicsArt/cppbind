from optionals.optionals_pygen import Optionals
from enums.color_pygen import Color

# [optionals-usage]
op = Optionals()
assert op.optional_ptr_with_nullptr_default() is None
assert op.optional_int_with_default() == 5
assert op.optional_string_with_default() == "abc"
assert op.optional_char_with_default() == ","
assert op.optional_ptr_with_null_default() is None
assert op.optional_enum_with_default() == Color.Red
# [optionals-usage]
