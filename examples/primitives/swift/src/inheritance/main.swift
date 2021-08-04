import Wrapper

// [simple-inheritance-usage]
let bicycle = Bicycle(numberOfSeats: 1)
assert(bicycle.numberOfSeats == 1)
// [simple-inheritance-usage]

// [multi-inheritance-usage]
let rectangle = Rectangle_impl(length: 4.0, width: 2.0)
assert(rectangle.area == 8.0)
assert(rectangle.length == 4.0)
print(rectangle.perimeter())
assert(rectangle.perimeter() == 12.0)

let rhombus = Rhombus_impl(diagonal1: 5.0, diagonal2: 6.0)
assert(rhombus.area == 15.0)

let square = Square(side: 5.0)
assert(square.area == 25.0)
assert(square.length == 5.0)
assert(square.perimeter() == 20.0)
// [multi-inheritance-usage]


// other test cases
let gf = GeometricFigure(p: square)
assert(gf.parallelogram.cself == square.cself)
gf.parallelogram = rhombus
assert(gf.parallelogram.cself == rhombus.cself)

let mv = MyVehicle(v: bicycle)
mv.vehicle = bicycle
