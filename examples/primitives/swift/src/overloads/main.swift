import Wrapper

// [counter - usage]
counter1 = Counter(count: 1)
counter2 = Counter(count: 2)
counter = counter1 + counter2
assert counter.count == 3
assert(counter1 < counter2)
assert(counter1 <= counter2)
assert(counter2 > counter1)
assert(counter2 >= counter1)
// [counter - usage]
