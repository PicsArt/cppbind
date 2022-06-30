package com.examples.hashing

fun use() {
// [hashing-usage-example-start]
// custom hashCode, equals and toString
val obj11 = Object1(1)
val obj12 = Object1(1)
val obj13 = Object1(2)

assert(obj11.toString() == "Object1 1")
assert(obj12.toString() == "Object1 1")
assert(obj13.toString() == "Object1 2")

// obj11 and obj12 have the same value so they are equal and have the same hash
assert(obj11 == obj12)
assert(obj11.hashCode() == obj12.hashCode())

val map1: HashMap<Object1, String> = hashMapOf(
  obj11 to "Object 11",
  obj13 to "Object 13"
)

assert(map1.size == 2)
assert(map1[obj11] == "Object 11")
assert(map1[obj13] == "Object 13")

// default __hash__, __eq__ and __str__
val obj21 = Object2()
val obj22 = Object2()
assert(obj21 != obj22)

val map2: HashMap<Object2, String> = hashMapOf(
  obj21 to "Object 21",
  obj22 to "Object 22"
)

assert(map2[obj21] != map2[obj22])
// underlying C++ object type name used in toString
assert(obj21.toString().endsWith("cppbind::example::Object2>"))
// [hashing-usage-example-end]

// test cases
// custom hash, equals and toString for shared_ref: False
assert(obj11.hashCode() == obj12.hashCode())
assert(obj11.hashCode() == 1)
assert(obj11 == obj12)
assert(obj11 != obj13)
assert(obj11.toString() == "Object1 1")
assert(obj13.toString() == "Object1 2")

// custom hash, equals and toString for shared_ref: True
val obj31 = Object3(1)
val obj32 = Object3(1)
val obj33 = Object3(2)
assert(obj31.hashCode() == obj32.hashCode())
assert(obj31.hashCode() == 1)
assert(obj31 == obj32)
assert(obj31 != obj33)
assert(obj31.toString() == "Object3 1")
assert(obj33.toString() == "Object3 2")

// default hash, equals and toString for shared_ref: False
assert(obj21 != obj22)
assert(obj21.hashCode() != obj22.hashCode())
assert(obj21 == obj21)
assert(obj21.hashCode() == obj21.hashCode())
println(obj21)
assert(obj21.toString().endsWith("cppbind::example::Object2>"))

// default hash, equals and toString for shared_ref: True
val obj41 = Object4()
val obj42 = Object4()
assert(obj41 != obj42)
assert(obj41 == obj41)

// derived types examples
val derived_obj11 = ExtendedObject1(1)
val derived_obj12 = ExtendedObject1(1)
val derived_obj13 = ExtendedObject1(2)
assert(derived_obj11.hashCode() == derived_obj12.hashCode())
assert(derived_obj11.hashCode() == 2)
assert(derived_obj11.toString() == "Object1 1")
assert(derived_obj13.toString() == "Object1 2")
assert(derived_obj11 == derived_obj12)
assert(derived_obj11 != derived_obj13)

val derived_obj21 = ExtendedObject2()
val derived_obj22 = ExtendedObject2()
assert(derived_obj21 != derived_obj22)
assert(derived_obj21 == derived_obj21)
println(derived_obj21.hashCode())
println(derived_obj21.toString())
assert(derived_obj21.toString().endsWith("cppbind::example::ExtendedObject2>"))

val derived_obj31 = ExtendedObject3()
val derived_obj32 = ExtendedObject3()
val derived_obj33 = ExtendedObject3(1)
assert(derived_obj31.hashCode() == derived_obj32.hashCode())
assert(derived_obj31.hashCode() == 0)
assert(derived_obj31 == derived_obj32)
assert(derived_obj31 != derived_obj33)
assert(derived_obj31.toString() == "Object3 0")
assert(derived_obj33.toString() == "Object3 1")

val derived_obj41 = ExtendedObject4()
val derived_obj42 = ExtendedObject4()
assert(derived_obj41 != derived_obj42)
assert(derived_obj41 == derived_obj41)
println(derived_obj41.hashCode())
println(derived_obj41.toString())
assert(derived_obj41.toString().endsWith("cppbind::example::ExtendedObject4>"))
}

class HashingApp {

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
