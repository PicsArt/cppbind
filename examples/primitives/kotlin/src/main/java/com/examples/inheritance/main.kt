package com.examples.inheritance

import com.examples.inheritance.*
import com.examples.simple.Task
import com.examples.simple.Root

fun use() {
// [simple-inheritance-usage]
val bicycle = Bicycle(1)
assert(bicycle.numberOfSeats == 1)
// [simple-inheritance-usage]

// [multi-inheritance-usage]
val rectangle = RectangleImpl(4.0, 2.0)
assert(rectangle.area == 8.0)
assert(rectangle.length == 4.0)
assert(rectangle.perimeter() == 12.0)

val rhombus = RhombusFigureImpl(5.0, 6.0)
assert(rhombus.area == 15.0)

val square = Square(5.0)
assert(square.area == 25.0)
assert(square.length == 5.0)
assert(square.perimeter() == 20.0)
// [multi-inheritance-usage]


// other test cases
val gf = GeometricFigure(square)
assert(gf.parallelogram is Square)
assert(gf.parallelogram.equals(square))
gf.parallelogram = rhombus
assert(gf.parallelogram is IRhombusFigure)
assert(gf.parallelogram.equals(rhombus))
gf.nullableParallelogram = null
assert(gf.nullableParallelogram == null)

val mv = MyVehicle(bicycle)
mv.vehicle = bicycle
assert(mv.vehicle!!.type() == "bicycle")
assert(mv.vehicle is Bicycle)

// const shared_ptr tests
val mb = MyBicycle(bicycle)
mb.bicycle = bicycle
val myNewBicycle = Bicycle(2)
mb.bicycle = myNewBicycle
assert(myNewBicycle.numberOfSeats == mb.bicycle.numberOfSeats)

// mixed multiple inheritance with interface and class
val dt = DateTime(15, 1, 2015, 15, 15, 15)
assert(dt.datetime == "15:1:2015 15:15:15")

// delete instances
square.close()
gf.close()
mv.close()
rhombus.close()
bicycle.close()
rectangle.close()

// test multiple inheritance in case some bases have API, others no
val animal = AnimalImpl()
assert(AnimalUsage.getAnimalTypeName(animal) == "animal")

val aquaticAnimal = AquaticAnimal()
assert(AnimalUsage.getAquaticAnimalTypeName(aquaticAnimal) == "aquatic")

val frog = Frog()
assert(AnimalUsage.getAnimalTypeName(frog) == "frog")
assert(AnimalUsage.getAquaticAnimalTypeName(frog) == "frog")

var animalUsageObj = AnimalUsage()
assert(animalUsageObj.getFrog().typeName() == "frog")
assert(animalUsageObj.getAquaticAnimal().typeName() == "frog")
assert(animalUsageObj.getAnimal().typeName() == "frog")

// test object downcasting
val frogObj = animalUsageObj.getFrog()
val aquaticAnimalObj = animalUsageObj.getAquaticAnimal()
val animalObj = animalUsageObj.getAnimal()
assert(aquaticAnimalObj is Frog)
assert(animalObj is Frog)
assert(frogObj.equals(aquaticAnimalObj) && frogObj.equals(animalObj))

// test no downcasting when descendants=[] for Frog
val littleFrogObj = LittleFrog()
animalUsageObj = AnimalUsage(littleFrogObj)
assert(!(animalUsageObj.getLittleFrog() is LittleFrog))

val dateEvent = Date(2, 12, 2021)
val dateTimeEvent = DateTime(11, 12, 2021, 12, 12, 12)
val myCalendar = MyCalendar(listOf(dateEvent))
myCalendar.addEvent(dateTimeEvent)
val events = myCalendar.events
assert(!(events[0] is DateTime))
assert(events[1] is DateTime)

}

class InheritanceApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
