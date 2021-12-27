from examples_lib.overloads import pretty_print, Employee, Utils
from examples_lib.getters import NumberInt

# [overload-usage]
assert Utils.sum(1, 2) == 3
assert Utils.sum(2.0, 3.0) == 5.0

utils = Utils()
assert utils.concatenate("1", "2") == "12"
assert utils.concatenate("a", "b", "c") == "abc"

assert Utils.minus(3, 2) == 1
assert Utils.minus(7.0, 3.0) == 4.0

# constructor overloading
john = 'John Doe'
john_email = 'john@email.com'
jane = 'Jane Doe'
jane_email = 'jane@email.com'

e1 = Employee(john)
assert e1.name == john
e2 = Employee(name=jane)
assert e2.name == jane

e3 = Employee(20, john_email)
assert e3.email == john_email
assert e3.age == 20

# [overload-usage]

# [implicit-cast-example]
n1 = NumberInt(1)
n2 = NumberInt(2)
assert utils.sum(n1, n2) == 3
# [implicit-cast-example]

try:
    Utils.sum("1", "1")
except TypeError:
    pass

# test for dir actions with absolute path(abs against iegen working dir)
pretty_print('{"first_name": "John", "last_name": "Doe"}')

# other use cases tests
e3.set_data(jane, age=21, email=jane_email)
assert e3.email == jane_email
assert e3.age == 21
assert e3.name == jane

e3.set_data(age=22)
assert e3.age == 22

# example with default value
e4 = Employee(20)
assert e4.email == ''

# method overloading, with default values
e4.set_data(jane, 21)
assert e4.email == ''
assert e4.age == 21
assert e4.name == jane
