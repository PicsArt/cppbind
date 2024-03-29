from examples_lib.getters.fruits_pygen import *
from examples_lib.getters.person_pygen import *
from examples_lib.getters.number_pygen import *

# [number-usage]
intNum = NumberInt(5)
doubleNum = NumberDouble(1.0)
assert (intNum.num == 5)
intNum.num = 2
assert (intNum.num == 2)
assert (doubleNum.num == 1.0)
# [number-usage]

# [person-usage]
person = Person("John Doe", "john.doe@mail.com", 30)
assert (person.name == "John Doe")
assert (person.age == 30)
assert (person.email == "john.doe@mail.com")
person.age = 25
assert (person.age == 25)
person.name = "Jane Doe"
assert (person.name == "Jane Doe")
# [person-usage]


# [template-get-usage-start]
apple1 = Apple()
apple2 = Apple()
papple1 = Pineapple()
papple2 = Pineapple()
fruits = Fruits([apple1, apple2, papple1, papple2])

assert len(fruits.apples) == 2
assert len(fruits.pineapple) == 2
apples_pineapples = fruits.apples_with_pineapples
assert len(apples_pineapples) == 4
fruits.apples_with_pineapples = [papple1, papple2, apple1, apple2]
apples_pineapples = fruits.apples_with_pineapples
assert apples_pineapples[0].type == FruitType.Pineapple
assert apples_pineapples[3].type == FruitType.Apple
# [template-get-usage-end]
