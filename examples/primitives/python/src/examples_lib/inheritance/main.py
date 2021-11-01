from examples_lib.inheritance import (
    Bicycle,
    Rectangle,
    RhombusFigure,
    Square,
    GeometricFigure,
    MyVehicle,
    DateTime,
    Mammal,
    Dog
)

# [simple-inheritance-usage]
bicycle = Bicycle(1)
assert bicycle.number_of_seats == 1
# [simple-inheritance-usage]


# [multi-inheritance-usage]
rectangle = Rectangle(length=4.0, width=2.0)
assert rectangle.area == 8.0
assert rectangle.length == 4.0
assert rectangle.perimeter() == 12.0

rhombus = RhombusFigure(diagonal1=5.0, diagonal2=6.0)
assert rhombus.area == 15.0

square = Square(side=5.0)
assert square.area == 25.0
assert square.length == 5.0
assert square.perimeter() == 20
# [multi-inheritance-usage]

# other test cases
gf = GeometricFigure(square)
assert gf.parallelogram == square
gf.parallelogram = rhombus
assert gf.parallelogram == rhombus

mv = MyVehicle(bicycle)
mv.vehicle = bicycle

# mixed multiple inheritance with interface and class
dt = DateTime(15, 1, 2015, 15, 15, 15)
assert dt.datetime == "15:1:2015 15:15:15"

# test inheritance when root base has no api
mammal = Mammal()
assert mammal.sound_type() == "default mammal sound"
dog = Dog()
assert dog.sound_type() == "barking"
