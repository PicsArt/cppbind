package com.examples.overloads

import com.examples.overloads.Utils

class OverloadsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [overload-usage]
            assert(Utils.Companion.sum(1, 2) == 3)
            assert(Utils.Companion.sum(2.0f, 3.0f) == 6.0f)
            // [overload-usage]

       }

    }
}
