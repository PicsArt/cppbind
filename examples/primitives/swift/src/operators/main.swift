import Wrapper

// [operators-usage]
let counter1 = Counter(count: 1)
let counter2 = Counter(count: 2)
let counter = counter1 + counter2
assert(counter.count == 3)
assert(counter2 > counter1)
counter1 += counter2
assert(counter1.count == 3)
assert(counter1 > counter2)
// [operators-usage]
