from examples_lib.inheritance import (
    Bicycle,
    Rectangle,
    RhombusFigure,
    Square,
    GeometricFigure,
    MyVehicle,
    DateTime,
    AnimalUsage,
    Animal,
    AquaticAnimal,
    Frog
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

# test multiple inheritance in case some bases have API, others no
animal = Animal()
assert AnimalUsage.get_animal_type_name(animal) == "animal"

aquaticAnimal = AquaticAnimal()
assert AnimalUsage.get_aquatic_animal_type_name(aquaticAnimal) == "aquatic"

frog = Frog()
assert AnimalUsage.get_animal_type_name(frog) == "frog"
assert AnimalUsage.get_aquatic_animal_type_name(frog) == "frog"

# currently we have an seg fault issue in this example
# animal_usage_obj = AnimalUsage()
# assert animal_usage_obj.get_frog().type_name() == "frog"
# assert animal_usage_obj.get_aquatic_animal().type_name() == "frog"
# assert animal_usage_obj.get_animal().type_name() == "frog"
