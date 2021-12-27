package com.examples.overloads

import com.examples.overloads.Utils
import com.examples.overloads.Employee

fun use() {
// [overload-usage]
assert(Utils.sum(1, 2) == 3)
assert(Utils.sum(2.0f, 3.0f) == 5.0f)
val utils = Utils()
assert(utils.concatenate("1", "2") == "12")
assert(utils.concatenate("a", "b", "c") == "abc")
assert(Utils.minus(3, 2) == 1)
assert(Utils.minus(7.0f, 3.0f) == 4.0f)

// constructor overloading
val john = "John Doe"
val john_email = "john@email.com"
val jane = "Jane Doe"
val jane_email = "jane@email.com"

val e1 = Employee(john)
assert(e1.name == john)

val e3 = Employee(20, john_email)
assert(e3.email == john_email)
assert(e3.age == 20)

// [overload-usage]

e3.setData(jane, 21, jane_email)
assert(e3.email == jane_email)
assert(e3.age == 21)
assert(e3.name == jane)

e3.setData(age=22)
assert(e3.age == 22)

// TODO: uncomment after adding defaults support for kotlin
// example with default value
/*val e4 = Employee(20)
assert(e4.email == "")

// method overloading, with default values
e4.setData(jane, 21)
assert(e4.email == "")
assert(e4.age == 21)
assert(e4.name == jane)*/

}

class OverloadsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }

    }
}
