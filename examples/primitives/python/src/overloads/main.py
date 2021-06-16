from overloads import pretty_print
from .utils_pygen import Utils
from getters import Numberint

# [overload-usage]
assert Utils.sum(1, 2) == 3
assert Utils.sum(2.0, 3.0) == 6.0

utils = Utils()
assert utils.concatenate("1", "2") == "12"
assert utils.concatenate("a", "b", "c") == "abc"
# [overload-usage]

# [implicit-cast-example]
n1 = Numberint(1)
n2 = Numberint(2)
assert utils.sum(n1, n2) == 3
# [implicit-cast-example]

try:
    Utils.sum("1", "1")
except TypeError:
    pass

# test for dir actions with absolute path(abs against iegen working dir)
pretty_print('{"first_name": "John", "last_name": "Doe"}')
