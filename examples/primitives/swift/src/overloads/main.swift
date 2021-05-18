import Wrapper

// [overload-usage]
assert(Utils.sum(first: 1, second: 2) == 3)
assert(Utils.sum(first: 2.0, second: 3.0) == 6.0)

utils = Utils()
assert(utils.concatenate(first: "1", second: "2") == "12")
assert(utils.concatenate(first: "a", second: "b", third: "c") == "abc")
// [overload-usage]
