package com.examples.overloads

import com.examples.overloads.Utils

fun use() {
// [overload-usage]
assert(Utils.Companion.sum(1, 2) == 3)
assert(Utils.Companion.sum(2.0f, 3.0f) == 6.0f)
val utils = Utils()
assert(utils.concatenate("1", "2") == "12")
assert(utils.concatenate("a", "b", "c") == "abc")
// [overload-usage]
}

class OverloadsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }

    }
}
