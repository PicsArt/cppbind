import Wrapper

// [external-yaml-usage]
assert(WithExternalAPIComments.retInt(n: 1) == 1)

let obj = WithExternalAPIComments(s: "ab")
assert(obj.str == "ab")

obj.str = "cd"
assert(obj.str == "cd")

let maxInt : Int = WithExternalAPIComments.max(arg0: 2, arg1: 3)
assert(maxInt == 3)

let maxStr : String = WithExternalAPIComments.max(arg0: "2", arg1: "3")
assert(maxStr == "3")
assert(AdderInt.add(a: 1, b: 2) == 3)
assert(AdderDouble.add(a: 1.5, b: 2.5) == 4.0)
assert(color.RED.rawValue == 0)
// [external-yaml-usage]
