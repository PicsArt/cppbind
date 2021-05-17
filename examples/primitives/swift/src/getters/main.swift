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
assert(person.fullName == "John Doe")
assert(person.age == 30)
assert(person.email == "john.doe@mail.com")
person.age = 25
assert(person.age == 25)
person.fullName = "Jane Doe"
assert(person.fullName == "Jane Doe")
// [person-usage]