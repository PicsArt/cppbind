import Wrapper

// [simple-inheritance-usage]
let bicycle = Bicycle(numberOfSeats: 1)
assert(bicycle.numberOfSeats == 1)
// [simple-inheritance-usage]

// [multi-inheritance-usage]
let rectangle = RectangleImpl(length: 4.0, width: 2.0)
assert(rectangle.area == 8.0)
assert(rectangle.length == 4.0)
assert(rectangle.perimeter() == 12.0)

let rhombus = RhombusFigureImpl(diagonal1: 5.0, diagonal2: 6.0)
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


// mixed multiple inheritance with interface and class
let dt = DateTime(d: 15, mo: 1, y: 2015, h: 15, mi: 15, s: 15)
assert(dt.datetime == "15:1:2015 15:15:15")