package com.examples.enums

import com.examples.enums.*

fun use() {

// [color-usage]
assert(Color.Red.value == 1)
assert(Color.Blue.value == 20)

assert(Color.Blue.toString() == "20")

val frame = Frame()
frame.backgroundColor = Color.Red
assert(frame.backgroundColor == Color.Red)
// [color-usage]

assert(ColorShade.ShadeLight.value == 1)
assert(ColorShade.ShadeDark.value == 2)

frame.backgroundColorShade = ColorShade.ShadeDark
assert(frame.backgroundColorShade == ColorShade.ShadeDark)

// checking const ref enum case
assert(frame.getNextColor(Color.Red) == Color.Green)

// checking `enum_case_names` variable
assert(getNextLogLevel(LogLevel.DEBUG) == LogLevel.log_info_level)

}

class EnumsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            use()

        }

    }
}
