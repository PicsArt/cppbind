from inheritance import Bicycle, Rectangle, Rhombus, Square

# [simple-inheritance-usage]
bicycle = Bicycle(1)
assert bicycle.number_of_seats == 1
# [simple-inheritance-usage]


# [multi-inheritance-usage]
rectangle = Rectangle(length=4.0, width=2.0)
assert rectangle.area == 8.0
assert rectangle.length == 4.0
assert rectangle.perimeter() == 12.0

rhombus = Rhombus(diagonal1=5.0, diagonal2=6.0)
assert rhombus.area == 15.0

square = Square(side=5.0)
assert square.area == 25.0
assert square.length == 5.0
assert square.perimeter() == 20
# [multi-inheritance-usage]
