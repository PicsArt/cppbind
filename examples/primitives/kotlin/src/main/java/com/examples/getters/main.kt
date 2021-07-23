package com.examples.getters

import com.examples.getters.*

fun use() {
// [number-usage]
val intNum = NumberInt(5)
val doubleNum = NumberDouble(1.0)
assert(intNum.num == 5)
intNum.num = 2
assert(intNum.num == 2)
assert(doubleNum.num == 1.0)
// [number-usage]

// [person-usage]
val person = Person("John Doe", "john.doe@mail.com", 30)
assert(person.fullName == "John Doe")
assert(person.age == 30)
assert(person.email == "john.doe@mail.com")
person.age = 25
assert(person.age == 25)
person.fullName = "Jane Doe"
assert(person.fullName == "Jane Doe")
// [person-usage]


// [template-get-usage]
val oneTypeGetter = OneTypeTemplateGetter(7)
assert(oneTypeGetter.simpleItem.value == 7)
assert(oneTypeGetter.simpleItemWithType.value == 7)
val value: Int = 8
val simpleItem = SimpleItem(value)
oneTypeGetter.simpleItem = simpleItem
assert(oneTypeGetter.simpleItem.value == 8)

val manyTypeGetter = ManyTypeTemplateGetter(5)
val fooBar1 = manyTypeGetter.fooBar
val fooBar2 = manyTypeGetter.fooBarPair
val barBar = manyTypeGetter.barBarPair
assert(fooBar1.first.value == 5)
assert(fooBar1.second.value == 5)
assert(fooBar2.first.value == 5)
assert(fooBar2.second.value == 5)
assert(barBar.first.value == 5)
assert(barBar.second.value == 5)

// [template-get-usage]

}

class GettersApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
