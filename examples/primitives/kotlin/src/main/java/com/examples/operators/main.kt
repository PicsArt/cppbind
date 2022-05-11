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
