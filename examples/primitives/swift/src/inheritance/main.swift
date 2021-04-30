import Wrapper

let rectangle = Rectangle(length: 4.0, width: 2.0)
assert(rectangle.area == 8.0)
assert(rectangle.length == 4.0)
print(rectangle.perimeter())
assert(rectangle.perimeter() == 12.0)

let rhombus = Rhombus(diagonal1: 5.0, diagonal2: 6.0)
assert(rhombus.area == 15.0)

let square = Square(side: 5.0)
assert(square.area == 25.0)
assert(square.length == 5.0)
assert(square.perimeter() == 20.0)