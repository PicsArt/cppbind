import XCTest
import Wrapper

func runGlobalsExamples() {
    // [glob-func-examples]
    var res = concat(str1: "Hello ", str2: "Johnny")
    assert(res == "Hello Johnny")
    res = concat(str1: "Hello ", str2: "Johnny ", str3: "Jane")
    assert(res == "Hello Johnny Jane")

    let maxInt = max(arg0: 2, arg1: 5)
    assert(maxInt == 5)
    let maxString = max(arg0: "d", arg1: "a")
    assert(maxString == "d")

    let prj1 = Project(title: "My first project")
    let prj2 = Project(title: "My second project")
    let pairPrjPrj = makePair(arg0: prj1, arg1: prj2)
    assert(Mirror(reflecting: pairPrjPrj).children.count == 2)
    assert(pairPrjPrj.0.title == prj1.title)
    assert(pairPrjPrj.1.title == prj2.title)

    let root1 = Root(path: "/path/to/root/")
    let pairRootPrj = makePair(arg0: root1, arg1: prj1)
    assert(Mirror(reflecting: pairRootPrj).children.count == 2)
    assert(pairRootPrj.0.path == root1.path)
    assert(pairRootPrj.1.title == prj1.title)
    // [glob-func-examples]

    var color = optionalColor()
    assert(color == Color.Red)
    color = optionalColor(c: Color.Blue)
    assert(color == Color.Blue)

    var intVal = optionalInt()
    assert(intVal == 5)
    intVal = optionalInt(i: 8)
    assert(intVal == 8)

    var optProj = optionalFDPtr()
    assert(optProj == nil)
    optProj = optionalFDPtr(project: prj1)
    assert(optProj?.title == prj1.title)

    // just calling function with no return value and arguments
    doNothing()

}


#if os(Linux)
runGlobalsExamples()
#elseif os(OSX)
class GlobsTests: XCTestCase {

    func testRun() throws {
        runGlobalsExamples()
    }
}
#endif
