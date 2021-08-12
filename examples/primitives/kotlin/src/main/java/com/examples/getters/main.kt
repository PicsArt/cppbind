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
val apple1 = Apple()
val apple2 = Apple()
val papple1 = Pineapple()
val papple2 = Pineapple()
val fruits = Fruits(listOf(apple1, apple2, papple1, papple2))

assert(fruits.apples.size == 2)
assert(fruits.pineapple.size == 2)
var applesPineapples = fruits.applesWithPineapples
assert(applesPineapples.size == 4)
fruits.applesWithPineapples = listOf(papple1, papple2, apple1, apple2)
applesPineapples = fruits.applesWithPineapples
assert(applesPineapples[0].type == FruitType.Pineapple)
assert(applesPineapples[3].type == FruitType.Apple)

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
