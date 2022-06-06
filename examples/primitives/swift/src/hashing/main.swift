import XCTest
import Wrapper

func runObjectsExamples() {

// [hashing-usage-example]
let obj11 = Object1(value: 1)
let obj12 = Object1(value: 1)
let obj13 = Object1(value: 2)

assert(String(describing: obj11) == "Object1 1")
assert(String(describing: obj12) == "Object1 1")
assert(String(describing: obj13) == "Object1 2")

/// obj11 and obj12 have the same value so they are equal and have the same hash
assert(obj11 == obj12)
var hasher = Hasher()
hasher.combine(obj11)
var hashVal1 = hasher.finalize()

hasher = Hasher()
hasher.combine(obj12)
var hashVal2 = hasher.finalize()
assert(hashVal1 == hashVal2)

let d1: [Object1 : String] = [
  obj11: "Object 11",
  obj13: "Object 13"
]

assert(d1.count == 2)
assert(d1[obj11] == "Object 11")
assert(d1[obj13] == "Object 13")

// [hashing-usage-example]


// test cases

// custom hash, equals and toString for shared_ref: False
hasher = Hasher()
hasher.combine(obj13)
var hashVal3 = hasher.finalize()

assert(hashVal1 != hashVal3)

// custom hash, equals and toString for shared_ref: True
let obj21 = Object3(value: 1)
let obj22 = Object3(value: 1)
let obj23 = Object3(value: 2)

hasher = Hasher()
hasher.combine(obj21)
hashVal1 = hasher.finalize()

hasher = Hasher()
hasher.combine(obj22)
hashVal2 = hasher.finalize()

hasher = Hasher()
hasher.combine(obj23)
hashVal3 = hasher.finalize()

assert(hashVal1 == hashVal2)
assert(hashVal1 != hashVal3)



// derived types examples
let derived_obj11 = ExtendedObject1(value: 1)
let derived_obj12 = ExtendedObject1(value: 1)
let derived_obj13 = ExtendedObject1(value: 2)
hasher = Hasher()
hasher.combine(derived_obj11)
hashVal1 = hasher.finalize()

hasher = Hasher()
hasher.combine(derived_obj12)
hashVal2 = hasher.finalize()

hasher = Hasher()
hasher.combine(derived_obj13)
hashVal3 = hasher.finalize()

assert(hashVal1 == hashVal2)
assert(hashVal1 != hashVal3)
assert(String(describing: derived_obj11) == "Object1 1")
assert(String(describing: derived_obj13) == "Object1 2")
assert(derived_obj11 == derived_obj12)
assert(derived_obj11 != derived_obj13)

let derived_obj21 = ExtendedObject3()
let derived_obj22 = ExtendedObject3()
let derived_obj23 = ExtendedObject3(value: 1)
hasher = Hasher()
hasher.combine(derived_obj21)
hashVal1 = hasher.finalize()

hasher = Hasher()
hasher.combine(derived_obj22)
hashVal2 = hasher.finalize()

hasher = Hasher()
hasher.combine(derived_obj23)
hashVal3 = hasher.finalize()

assert(hashVal1 == hashVal2)
assert(hashVal1 != hashVal3)
assert(String(describing: derived_obj21) == "Object3 0")
assert(String(describing: derived_obj23) == "Object3 1")
assert(derived_obj21 == derived_obj22)
assert(derived_obj21 != derived_obj23)

}


#if os(Linux)
runObjectsExamples()
#elseif os(OSX)
class GlobsTests: XCTestCase {

    func testRun() throws {
        runObjectsExamples()
    }
}
#endif
