import XCTest
import Wrapper

func runGlobalsExamples() {

// [simple-usage-example-start]
var mulInt = mul(first:5, second: 4)
assert(mulInt == 20)

mulInt = mul(first:5, second: 4, third: 3)
assert(mulInt == 60)

var res = concat(str1: "Hello ", str2: "Johnny")
assert(res == "Hello Johnny")
// [simple-usage-example-end]

// [glob-func-examples-start]
res = concat(str1: "Hello ", str2: "Johnny ", str3: "Jane")
assert(res == "Hello Johnny Jane")

// [custom-arg-examples-start]
let greeting = greet(person: "Johnny", from: "Florida")
assert(greeting == "Hello Johnny from Florida")
// [custom-arg-examples-end]

let maxInt = max(a: 2, b: 5)
assert(maxInt == 5)
let maxString = max(a: "d", b: "a")
assert(maxString == "d")

let prj1 = Project(title: "My first project")
let prj2 = Project(title: "My second project")
let pairPrjPrj = makePair(a: prj1, b: prj2)
assert(Mirror(reflecting: pairPrjPrj).children.count == 2)
assert(pairPrjPrj.0.title == prj1.title)
assert(pairPrjPrj.1.title == prj2.title)

let root1 = Root(path: "/path/to/root/")
let pairRootPrj = makePair(a: root1, b: prj1)
assert(Mirror(reflecting: pairRootPrj).children.count == 2)
assert(pairRootPrj.0.path == root1.path)
assert(pairRootPrj.1.title == prj1.title)
// [glob-func-examples-end]

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

// [non-complex-defaults-usage-start]
assert(optionalColor() == Color.Red)
assert(optionalColor(c: Color.Blue) == Color.Blue)
assert(optionalInt() == 5)
assert(optionalInt(i: 1) == 1)
assert(optionalString() == "abc")
assert(optionalString(optionalStr: "def") == "def")
// [non-complex-defaults-usage-end]

// complex default values tests
// [complex-defaults-usage-start]
assert(multipleMixedDefaultValues() == "DefaultTask1DefaultRoot")
assert(multipleMixedDefaultValues(task: Task(title: "ABC")) == "ABC1DefaultRoot")
assert(multipleMixedDefaultValues(task: Task(title: "ABC"), i: 2) == "ABC2DefaultRoot")
assert(multipleMixedDefaultValues(task: Task(title: "ABC"), r: Root(path: "Path") ) == "ABC1Path")
assert(multipleMixedDefaultValues(task: Task(title: "ABC"), i: 2, r: Root(path: "Path") ) == "ABC2Path")
// [complex-defaults-usage-end]
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
