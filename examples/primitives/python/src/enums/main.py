from .color_pygen import Color
from .frame_pygen import Frame

# [color-usage]
assert Color.Red.rawValue == 1
assert Color.Blue.rawValue == 20
frame = Frame()
frame.backgroundColor = Color.Red
assert frame.backgroundColor == Color.Red

# [color-usage]
