from examples_lib.operators import pretty_print
from examples_lib.operators.counter_pygen import Counter
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
