from examples_lib.misc.yaml_example_pygen import WithExternalAPIComments, Adderfloat, Adderint, color
from examples_lib.misc.size_buffer_pygen import SizeUsage, BufferUsage
from buffer import SizeF, Buffer


# [external-yaml-usage]
assert WithExternalAPIComments.ret_int(1) == 1

obj = WithExternalAPIComments("ab")
assert (obj.str == "ab")

assert WithExternalAPIComments.max(2, 3) == 3
assert WithExternalAPIComments.max("2", "3") == "3"

assert Adderint.add(1, 2) == 3
assert Adderfloat.add(1.5, 2.5) == 4.0

assert color.RED.name == "RED" and color.RED.value == 0
# [external-yaml-usage]

# [size-usage]
size = SizeF(10, 20)
result_size = SizeUsage.multiply_by(size, 5)
assert result_size.width == 50.0 and result_size.height == 100.0
result_size = SizeUsage.double_size_f(size)
assert result_size.width == 20.0 and result_size.height == 40.0
result_size = SizeUsage.double_size_f()
assert result_size.width != result_size.width  # is nan
assert result_size.height != result_size.height  # is nan

# [size-usage]

# [buffer-usage]
buffer_usage = BufferUsage()
buffer_ = Buffer()
assert buffer_usage.usage1(buffer_) == "buffer print"
# [buffer-usage]
