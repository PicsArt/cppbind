from .utils_pygen import Utils

# [overload-usage]
assert Utils.sum(1, 2) == 3
assert Utils.sum(2.0, 3.0) == 6.0
# [overload-usage]

try:
    Utils.sum("1", "1")
except TypeError:
    pass
