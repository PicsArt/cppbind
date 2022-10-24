package com.examples.stl_types
import com.examples.enums.Color
import com.examples.enums.Frame

fun use() {
// [counter-usage-start]

// check for Int
var optInt : Int? = null
assert(mul(optInt, 2) == null)
optInt = 100
assert(mul(optInt, 2) == 200)

// check for Float
assert(mul(2.0f, 2.0f) == 4f)

// check for Double
var optDouble : Double? = null
assert(mul(optDouble, 3.0) == null)
optDouble = 50.0
assert(mul(optDouble, 3.0) == 150.0)

// check for Short
var optShort : Short? = null
assert(mul(optShort, 2) == null)
optShort = 200
assert(mul(optShort, 2) == 400.toShort())

// check for Long
assert(mulLong(null, 2) == null)
assert(mulLong(500, 2) == 1000L)

// check for unsigned int
assert(mulUnsignedInt(3, 4) == 12L)

// check for unsigned long
assert(mulUnsignedLong(100, 2) == 200L)

// check for long long
assert(mulLongLong(100, 100) == 10000L)

// check for unsigned char
assert(mulUnsignedChar(2u, 2u)!!.compareTo(4u) == 0)

// check for bool
assert(reverseBool(true) == false)

// check for char
assert(charToUpper('b') == 'B')

// check for string
assert(concatString("Bob", " Hello") == "Bob Hello")

// check for std::optional<std::vector<std::string>>
assert(concat(listOf("Bob"), " Hello") == listOf("Bob Hello"))
assert(concat(null, " Hello") == null)

// check for std::vector<std::optional<std::string>>
assert(concat2(listOf("Bob"), " Hello") == listOf("Bob Hello"))
assert(concat2(listOf(null), " Hello") == listOf(null))

// check for enum
assert(sameColor(Color.Red)!!.value == 1)
assert(sameColor(null) == null)

// check for object
val frameUsageObj = FrameUsage()
val frame = Frame()
frame.backgroundColor = Color.Red
assert(frameUsageObj.sameFrame(frame)!!.backgroundColor == Color.Red)
assert(frameUsageObj.sameFrame(null) == null)

// check for template
var optIntTemplate : Int? = null
assert(same_template(optIntTemplate) == null)
var optStringTemplate : String? = null
assert(same_template(optStringTemplate) == null)
assert(same_template(5) == 5)
assert(same_template("Hello") == "Hello")

// check for Pair
assert(samePair(Pair(1,1)) == Pair(1,1))
assert(samePair(null) == null)

// check for Map
assert(sameMap(mapOf<Int, Int>(1 to 1))!!.get(1) == 1)
assert(sameMap(null) == null)

// check for std::span
val l1 = listOf(1,2,3,4)
val l2 = listOf(5,6)
assert(sumSpan(listOf(1,2,3)) == 6)
assert(getSpan(l1) == l1)
assert(getSpan2(listOf(5,6,7,8,9)) == l2)

}

class StlTypesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
