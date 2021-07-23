package com.examples.optionals

import com.examples.optionals.Optionals
import com.examples.enums.Color
import com.examples.simple.Task


fun use() {
// [optionals-usage]
val op = Optionals()

// default value assertions
assert(op.optionalPtrWithNullptrDefault() == null)
assert(op.optionalFDPtrWithNullptrDefault() == null)
assert(op.optionalIntWithDefault() == 5)
assert(op.optionalLongWithDefault() == 7L)
assert(op.optionalDoubleWithDefault() == 9.0)
assert(op.optionalFloatWithDefault() == 11.0F)
assert(op.optionalBoolWithDefault() == true)
assert(op.optionalStringWithDefault() == "abc")
assert(op.optionalCharWithDefault() == ',')
assert(op.optionalCharPointerWithDefault() == "def")
assert(op.optionalSharedPtrWithNullptrDefault() == null)
assert(op.optionalEnumWithDefault() == Color.Red)

// non default value assertions
val task = Task("my task")
assert(op.optionalPtrWithNullptrDefault(task)!!.getObjId() == task.getObjId())
assert(op.optionalEnumWithDefault(Color.Blue) == Color.Blue)
assert(op.optionalBoolWithDefault(false) == false)
assert(op.optionalCharWithDefault(':') == ':')
assert(op.optionalLongWithDefault(8L) == 8L)
assert(op.optionalFloatWithDefault(5.0F) == 5.0F)
assert(op.optionalCharPointerWithDefault("val") == "val")
// [optionals-usage]
}

class OptionalsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }

    }
}
