from enums.color_pygen import Color
from enums.frame_pygen import Frame

# [color-usage]
assert Color.Red.value == 1
assert Color.Blue.value == 20
assert Color.Green.value == 2
frame = Frame()
frame.background_color = Color.Red
assert frame.background_color == Color.Red
# [color-usage]
