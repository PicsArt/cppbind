from example_lib.array.array import Array

array = Array()

assert array.empty is True

array.push_back(0)
array.push_back(1)
array.push_back(2)

assert array.empty is False
assert array.size == 3
assert array.front() == 0
assert array.back() == 2
assert array[1] == 1

try:
    array.at(5)
    assert False
except IndexError:
    pass
except Exception:
    assert False
