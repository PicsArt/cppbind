import Wrapper

// [object-usage]
let objUsage = ObjectUsage()
assert(objUsage.className() == "iegen::ObjectUsage")
assert(objUsage.equals(other: objUsage) == true)
assert(objUsage.bytesCount() == 8)
assert(objUsage.toString().hasSuffix("iegen::ObjectUsage>"))
// [object-usage]
