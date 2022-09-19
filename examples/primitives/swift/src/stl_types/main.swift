import XCTest
import Wrapper

func runStlTypesExamples() {

    // check for Int
    var optInt : Int?
    assert(mul(a:optInt, b:2) == nil)
    optInt = 100
    assert(mul(a:optInt, b:2) == 200)

    // check for Float
    var optFloat : Float? = 5
    assert(mul(a:optFloat, b:2.0) == 10.0)
    optFloat = nil
    assert(mul(a:optFloat, b:2.0) == nil)

    // check for Double
    var optDouble : Double? = 50.0
    assert(mul(a:optDouble, b:3.0) == 150.0)
    optDouble = nil
    assert(mul(a:optDouble, b:2.0) == nil)

    // check for Short
    var optShort : CShort? = 10
    assert(mul(a:optShort, b:4) == 40)
    optShort = nil
    assert(mul(a:optShort, b:4) == nil)

    // check for Long
    var optLong : CLong? = 100
    assert(mulLong(a:optLong, b:4) == 400)
    optLong = nil
    assert(mulLong(a:optLong, b:4) == nil)

    // check for Bool
    assert(reverseBool(a: true) == false)

    // check for unsigned int
    assert(mulUnsignedInt(a:3, b:4) == 12)

    // check for unsigned long
    assert(mulUnsignedLong(a:200, b:2) == 400)

    // check for long long
    assert(mulLongLong(a:10, b:10) == 100)

    // check for unsigned char
    assert(mulUnsignedChar(a:2, b:2) == 4)

    // check for char
    assert(charToUpper(a:"b") == "B")

    // check for string
    assert(concatString(first: "A", second: "B") == "AB")

    // check for std::optional<std::vector<std::string>>
    assert(concat(v: ["Hello"], s:" Bob") == ["Hello Bob"])
    assert(concat(v: nil, s:" Bob") == nil)

    // check for std::vector<std::optional<std::string>>
    assert(concat2(v: ["Hello"], s:" Bob") == ["Hello Bob"])
    assert(concat2(v: [nil], s:" Bob") == [nil])

    // check for enum
    assert(sameColor(color: nil) == nil)
    assert(sameColor(color: Color.Red)!.rawValue == 1)

    // check for object
    let frameUsageObj = FrameUsage()
    let frame = Frame()
    frame.backgroundColor = Color.Red
    assert(frameUsageObj.sameFrame(frame: frame)!.backgroundColor == Color.Red)

    // check for template
    optInt = nil
    assert(same_template(a:optInt) == nil)
    optInt = 5
    assert(same_template(a:optInt) == 5)
    assert(same_template(a:"Hello") == "Hello")

    // check for Pair
    assert(samePair(pair: (1, 2))! == (1,2))
    assert(samePair(pair: nil) == nil)

    // check for Map
    assert(sameMap(map: [1:2, 2:3])! == [1:2, 2:3])
    assert(sameMap(map: nil) == nil)

}

#if os(Linux)
runStlTypesExamples()
#elseif os(OSX)
class MiscTests: XCTestCase {

    func testRun() throws {
        runStlTypesExamples()
    }
}
#endif
