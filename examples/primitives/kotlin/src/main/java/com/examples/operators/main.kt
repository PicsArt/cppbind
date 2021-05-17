package com.examples.operators

import com.examples.operators.Counter

class OperatorsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [counter-usage]
            var counter1 = Counter(1)
            var counter2 = Counter(2)
            var counter = counter1 + counter2
            assert(counter.count == 3)
            assert(counter1 < counter2)
            assert(counter1 <= counter2)
            assert(counter2 > counter1)
            assert(counter2 >= counter1)
            // [counter-usage]

       }

    }
}
