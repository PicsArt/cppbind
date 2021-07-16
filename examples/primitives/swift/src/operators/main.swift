import Wrapper

let counter1 = Counter(count: 10)
assert(counter1.count == 10)

let counter2 = Counter(count: 20)
let counter3 = counter1 + counter2
assert(counter3.count == counter1.count + counter2.count)
assert(counter1.compareTo(counter: counter1) == 0)
assert(counter1.compareTo(counter: counter2) == -1)
assert(counter2.compareTo(counter: counter1) == 1)

let isGreater = counter2 > counter1
assert(isGreater == true)

let oldCount = counter3.count
counter3 += counter1
assert(counter3.count == oldCount + counter1.count)
