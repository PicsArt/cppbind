from examples_lib.enums.color_pygen import Color
from examples_lib.enums.color_pygen import ColorShade
from examples_lib.enums.frame_pygen import Frame
from examples_lib.enums.logging_pygen import LogLevel, get_next_log_level


# [color-usage]
assert Color.Red.value == 1
assert Color.Blue.value == 20
assert Color.Green.value == 2

assert int(Color.Blue) == 20
assert str(Color.Blue) == '20'

red = Color(1)
assert red == Color.Red
assert isinstance(Color.Red, Color)

frame = Frame()
frame.background_color = Color.Red
assert frame.background_color == Color.Red
# [color-usage]

assert ColorShade.ShadeLight.value == 1
assert ColorShade.ShadeDark.value == 2
frame.background_color_shade = ColorShade.ShadeDark
assert frame.background_color_shade == ColorShade.ShadeDark

# checking const ref enum case
assert frame.get_next_color(Color.Red) == Color.Green

# checking `enum_case_names` variable
assert(get_next_log_level(LogLevel.DEBUG) == LogLevel.log_info_level)
