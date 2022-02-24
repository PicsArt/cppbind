import XCTest
import Wrapper

func runInheritanceExamples() {
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
    assert(gf.parallelogram is Square)
    assert(gf.parallelogram.equals(p: square))
    gf.parallelogram = rhombus
    assert(gf.parallelogram is RhombusFigure)
    assert(gf.parallelogram.equals(p: rhombus))
    gf.nullableParallelogram = nil
    assert(gf.nullableParallelogram == nil)

    let mv = MyVehicle(v: bicycle)
    mv.vehicle = bicycle
    assert(mv.vehicle!.type() == "bicycle")
    assert(mv.vehicle is Bicycle)

    let mb = MyBicycle(b: bicycle)
    assert(mb.bicycle.type() == "bicycle")

    // mixed multiple inheritance with interface and class
    let dt = DateTime(d: 15, mo: 1, y: 2015, h: 15, mi: 15, s: 15)
    assert(dt.datetime == "15:1:2015 15:15:15")

    // test multiple inheritance in case some bases have API, others no
    let animal = AnimalImpl()
    assert(AnimalUsage.getAnimalTypeName(animal: animal) == "animal")

    let aquaticAnimal = AquaticAnimal()
    assert(AnimalUsage.getAquaticAnimalTypeName(animal: aquaticAnimal) == "aquatic")

    let frog = Frog()
    assert(AnimalUsage.getAnimalTypeName(animal: frog) == "frog")
    assert(AnimalUsage.getAquaticAnimalTypeName(animal: frog) == "frog")

    // test polymorphism
    var animalUsageObj = AnimalUsage()
    assert(animalUsageObj.getFrog().typeName() == "frog")
    assert(animalUsageObj.getAquaticAnimal().typeName() == "frog")
    assert(animalUsageObj.getAnimal().typeName() == "frog")

    // test object downcasting
    let frogObj = animalUsageObj.getFrog()
    let aquaticAnimalObj = animalUsageObj.getAquaticAnimal()
    let animalObj = animalUsageObj.getAnimal()
    assert(aquaticAnimalObj is Frog)
    assert(animalObj is Frog)
    assert(frogObj.equals(a: aquaticAnimalObj) && frogObj.equals(a: animalObj))

    // test no downcasting when descendants=[] for Frog
    let littleFrogObj = LittleFrog()
    animalUsageObj = AnimalUsage(littleFrog: littleFrogObj)
    assert(!(animalUsageObj.getLittleFrog() is LittleFrog))

    let dateEvent = MyDate(d: 12, m: 12, y: 2021)
    let dateTimeEvent = DateTime(d: 11, mo: 12, y: 2021, h: 12, mi: 12, s: 12)
    let myCalendar = MyCalendar(events: [dateEvent])
    myCalendar.addEvent(e: dateTimeEvent)
    let events = myCalendar.events
    assert(!(events[0] is DateTime))
    assert(events[1] is DateTime)

    // testing multiple inheritance without single root
    var symbolUsageObj = SymbolUsage()
    let digitObj = Digit()
    let textObj = Text()
    let signObj = SignImpl()

    // test virtual methods
    assert(symbolUsageObj.getTextType(t: digitObj) == "digit")
    assert(symbolUsageObj.getTextType(t: textObj) == "text")
    assert(symbolUsageObj.getSignType(s: digitObj) == "digit")
    assert(symbolUsageObj.getSignType(s: signObj) == "sign")
    assert(digitObj.typeName() == "digit")
    assert(textObj.typeName() == "text")
    assert(signObj.typeName() == "sign")

    symbolUsageObj = SymbolUsage(d: digitObj)
    assert(symbolUsageObj.getTextPtr().typeName() == "digit")
    assert(symbolUsageObj.getSignPtr().typeName() == "digit")

    // test members
    assert(symbolUsageObj.getTextId(t: digitObj) == 2)
    assert(symbolUsageObj.getTextId(t: textObj) == 2)
    assert(symbolUsageObj.getSignId(s: digitObj) == 1)
    assert(symbolUsageObj.getSignId(s: signObj) == 1)

    // test return object correct casting
    assert(symbolUsageObj.getTextId(t: symbolUsageObj.getTextPtr()) == 2)
    assert(symbolUsageObj.getSignId(s: symbolUsageObj.getSignPtr()) == 1)
}

#if os(Linux)
runInheritanceExamples()
#elseif os(OSX)
class InheritanceTests: XCTestCase {

    func testRun() throws {
        runInheritanceExamples()
    }
}
#endif
