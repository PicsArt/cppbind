from examples_lib.operators import pretty_print
from examples_lib.operators.counter_pygen import Counter, PositiveCounter
from examples_lib.operators.intarray_pygen import IntArray


# [counter-usage]
counter1 = Counter(1)
counter2 = Counter(2)
counter = counter1 + counter2
assert counter.count == 3
assert counter1 < counter2
assert counter2 > counter1
counter1 += counter2
assert counter1.count == 3
# [counter-usage]

# checking == operator
c1 = Counter(1)
c2 = Counter(1)
assert c1 == c2
c3 = Counter(2)
assert not c1 == c3

# checking a method mapped to the "__eq__" operator
pc1 = PositiveCounter(5)
pc2 = PositiveCounter(5)
assert pc1 == pc2
pc3 = PositiveCounter(6)
assert not pc1 == pc3

# [subscript-operator-usage]
intArr = IntArray()
assert (intArr[0] == 0)
assert (intArr[9] == 9)
assert (intArr["9"] == 9)
assert (intArr[9.0] == 9)
intArr[9] = 10
assert (intArr[9] == 10)
assert (intArr["9"] == 10)
assert (intArr[9.0] == 10)
# [subscript-operator-usage]


# test for dir actions with relative path
pretty_print('{"first_name": "John", "last_name": "Doe"}')
