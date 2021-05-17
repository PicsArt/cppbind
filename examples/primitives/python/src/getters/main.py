from getters.many_type_template_getter_pygen import *
from getters.one_type_template_getter_pygen import *
from getters.person_pygen import *
from getters.number_pygen import *

# [number-usage]
intNum = Numberint(5)
doubleNum = Numberfloat(1.0)
assert (intNum.num == 5)
intNum.num = 2
assert (intNum.num == 2)
assert (doubleNum.num == 1.0)
# [number-usage]

# [person-usage]
person = Person("John Doe", "john.doe@mail.com", 30)
assert (person.full_name == "John Doe")
assert (person.age == 30)
assert (person.email == "john.doe@mail.com")
person.age = 25
assert (person.age == 25)
person.full_name = "Jane Doe"
assert (person.full_name == "Jane Doe")
# [person-usage]


# [one-template-get-usage]
one_getter = OneTypeTemplateGetter()
assert one_getter.simple_item.value == 0
assert one_getter.simple_item_with_type.value == 0

many_type_getter = ManyTypeTemplateGetter()
foo_bar1 = many_type_getter.foo_bar
foo_bar2 = many_type_getter.foo_bar_pair
bar_bar = many_type_getter.bar_bar_pair
assert isinstance(foo_bar1[0], Foo)
assert isinstance(foo_bar1[1], Bar)
assert foo_bar2[0].value == 0
assert foo_bar2[1].value == 0
assert isinstance(bar_bar[0], Bar)
assert isinstance(bar_bar[1], Bar)

# [one-template-get-usage]
