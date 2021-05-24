from .utils_pygen import Utils

# [overload-usage]
assert Utils.sum(1, 2) == 3
assert Utils.sum(2.0, 3.0) == 6.0

utils = Utils()
assert utils.concatenate("1", "2") == "12"
assert utils.concatenate("a", "b", "c") == "abc"
# [overload-usage]

try:
    Utils.sum("1", "1")
except TypeError:
    pass
