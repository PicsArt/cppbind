import Wrapper

// [color-usage]
assert(Color.Red.rawValue == 1)
assert(Color.Blue.rawValue == 20)

assert(String(describing: Color.Blue) == "20")

let frame = Frame()
frame.backgroundColor = Color.Red
assert(frame.backgroundColor == Color.Red)

// [color-usage]