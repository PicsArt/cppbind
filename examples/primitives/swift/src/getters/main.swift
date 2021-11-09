import Wrapper

// [number-usage]
let intNum = NumberInt(n: 5)
let doubleNum = NumberDouble(n: 1.0)
assert(intNum.num == 5)
intNum.num = 2
assert(intNum.num == 2)
assert(doubleNum.num == 1.0)
// [number-usage]

// [person-usage]
let person = Person(name: "John Doe", email: "john.doe@mail.com", age: 30)
assert(person.name == "John Doe")
assert(person.age == 30)
assert(person.email == "john.doe@mail.com")
person.age = 25
assert(person.age == 25)
person.name = "Jane Doe"
assert(person.name == "Jane Doe")
// [person-usage]

// [template-get-usage]
let apple1 = Apple()
let apple2 = Apple()
let papple1 = Pineapple()
let papple2 = Pineapple()
let fruits = Fruits(fruits: [apple1, apple2, papple1, papple2])

assert(fruits.apples.count == 2)
assert(fruits.pineapple.count == 2)
var applesPineapples = fruits.applesWithPineapples
assert(applesPineapples.count == 4)
fruits.applesWithPineapples = [papple1, papple2, apple1, apple2]
applesPineapples = fruits.applesWithPineapples
assert(applesPineapples[0].type == FruitType.Pineapple)
assert(applesPineapples[3].type == FruitType.Apple)

// [template-get-usage]