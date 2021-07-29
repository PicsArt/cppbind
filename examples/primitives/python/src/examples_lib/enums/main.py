from examples_lib.enums.color_pygen import Color
from examples_lib.enums.frame_pygen import Frame


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
