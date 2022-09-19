from examples_lib.stl_types.std_optional_pygen import *
from examples_lib.enums.color_pygen import Color
from examples_lib.enums.frame_pygen import Frame

# check for Int
assert(mul_int(None, 2) is None)
assert(mul_int(100, 2) == 200)

# check for Float
assert(mul_float(2.0, 2.0) == 4)

# check for Double
assert(mul_double(None, 3.0) is None)
assert(mul_double(50.0, 3.0) == 150.0)

# check for Short
assert(mul_short(None, 2) is None)
assert(mul_short(200, 2) == 400)

# check for Long
assert(mul_long(None, 2) is None)
assert(mul_long(500, 2) == 1000)

# check for unsigned int
assert(mul_unsigned_int(3, 4) == 12)
#
# check for unsigned long
assert(mul_unsigned_long(100, 2) == 200)

# check for long long
assert(mul_long_long(100, 100) == 10000)

# check for unsigned char
assert(mul_unsigned_char(2, 2) == 4)

# check for bool
assert(reverse_bool(True) is False)

# check for char
assert(char_to_upper('b') == 'B')

# check for string
assert(concat_string("Bob", " Hello") == "Bob Hello")

# check for std::optional<std::vector<std::string>>
assert(concat(["Bob"], " Hello") == ["Bob Hello"])
assert(concat(None, " Hello") is None)

# check for std::vector<std::optional<std::string>>
assert(concat2(["Bob"], " Hello") == ["Bob Hello"])
assert(concat2([None], " Hello") == [None])

# check for enum
assert(same_color(Color.Red) == Color.Red)
assert(same_color(None) is None)

# check for object
frameUsageObj = FrameUsage()
frame = Frame()
frame.background_color = Color.Red
assert(frameUsageObj.same_frame(frame).background_color == Color.Red)
assert(frameUsageObj.same_frame(None) is None)

# check for template
assert(same_template_optional_int(5) == 5)
assert(same_template_optional_int(None) is None)
assert(same_template_optional_string("Hello") == "Hello")
assert(same_template_optional_string(None) is None)

# check for Pair
assert(same_pair((1,1)) == (1,1))
assert(same_pair(None) is None)

# check for Map
assert(same_map({1:1}).get(1) == 1)
assert(same_map(None) is None)

