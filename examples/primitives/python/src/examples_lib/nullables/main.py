from examples_lib.nullables import NumberInt, NumberDouble, Utils

# [nullables-usage]
n1 = NumberInt(1)
n2 = NumberInt(2)

res1 = Utils.max(n1, n2)
assert res1.value == n2.value

res1 = Utils.max(None, None)
assert res1 is None

d1 = NumberDouble(1.0)
d2 = NumberDouble(2.0)

res2 = Utils.max(d1, d2)
assert res2.value == d2.value

res2 = Utils.max(None, d2)
assert res2 is None

# negative examples
try:
    Utils.check_nonnull_arg(None)
except ValueError as e:
    assert str(e) == "Utils.check_nonnull_arg's number argument cannot be None."

try:
    Utils.check_nonnull_return()
except ValueError as e:
    assert str(e) == "Utils.check_nonnull_return's return value cannot be None."

# nullable getter/setter
utils = Utils(d1)
assert utils.nullable.value == d1.value
utils.nullable = None


# negative examples
try:
    assert utils.non_null
except ValueError as e:
    assert str(e) == "Utils.non_null's return value cannot be None."

try:
    utils.non_null = None
except ValueError as e:
    assert str(e) == "Utils.non_null's value argument cannot be None."


# nullable property getter/setter
assert utils.num_double is None
utils.num_double = d2
assert utils.num_double.value == d2.value


# negative examples
try:
    utils.num_int = None
except ValueError as e:
    assert str(e) == "Utils.num_int's value argument cannot be None."

# [nullables-usage]
