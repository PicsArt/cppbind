package com.examples.operators

import com.examples.operators.Counter
import com.examples.operators.IntArrayImpl

fun use() {
// [counter-usage]
var counter1 = Counter(1)
var counter2 = Counter(2)
var counter = counter1 + counter2
assert(counter.count == 3)
counter += counter1
assert(counter.count == 4)
assert(counter1 < counter2)
assert(counter1 <= counter2)
assert(counter2 > counter1)
assert(counter2 >= counter1)
// [counter-usage]

// checking == operator
val c1 = Counter(1)
val c2 = Counter(1)
assert(c1 == c2)
val c3 = Counter(2)
assert(!(c1 == c3))

// checking a method mapped to the "equals" operator
val pc1 = PositiveCounter(5)
val pc2 = PositiveCounter(5)
assert(pc1 == pc2)
val pc3 = PositiveCounter(6)
assert(!(pc1 == pc3))

// checking subscript operator with get and set
val counts = listOf(1, 3, 5, 10)
val multiCounter = PositiveCounter(counts)
for (i in 0..3) {
    assert(multiCounter[i] == counts[i])
}
multiCounter[0] = 10
assert(multiCounter[0] == 10)

// [subscript-operator-usage]
var intArr = IntArrayImpl()
assert(intArr[0] == 0)
assert(intArr[9] == 9)
assert(intArr["9"] == 9)
assert(intArr[9.0] == 9)
intArr[9] = 10
assert(intArr[9] == 10)
assert(intArr["9"] == 10)
assert(intArr[9.0] == 10)
// [subscript-operator-usage]
}

class OperatorsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
