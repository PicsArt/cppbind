package com.examples.enums

import com.examples.enums.*

class EnumsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [color-usage]
            // create a new project
            assert(Color.Red.value == 1)
            assert(Color.Blue.value == 20)
            val frame = Frame()
            frame.backgroundColor = Color.Red
            assert(frame.backgroundColor == Color.Red)

            // [color-usage]

        }

    }
}
