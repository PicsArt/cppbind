package com.examples.macros

fun use() {
// [macros-usage-start]
assert(mulD(2.0, 5.0) == 10.0)
assert(mulL(4L, 5L) == 20L)
// [macros-usage-end]

}

class MacrosApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
