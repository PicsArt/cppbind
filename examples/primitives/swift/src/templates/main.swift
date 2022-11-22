import XCTest
import Wrapper

func runTemplateExamples() {

// [stack-examples-start]
let stackPrj = StackPrj()
assert(stackPrj.empty())
let prj = Project(title: "My Project")
stackPrj.push(item: prj)
assert(!stackPrj.empty())
assert(stackPrj.top().title == prj.title)
stackPrj.pop()
assert(stackPrj.empty())

let stackNumber = StackNumInt()
let num1 = NumberInt(n: 1)
let num2 = NumberInt(n: 2)
stackNumber.push(item: num1)
stackNumber.push(item: num2)
assert(stackNumber.top().num == num2.num)
stackNumber.pop()
assert(stackNumber.top().num == num1.num)

stackPrj.push(item: prj)
let stackPrjCopy = StackPrj(stack: stackPrj)
assert(stackPrj.top() == stackPrjCopy.top())
// [stack-examples-end]

//other test cases
assert(stackPrj.top().title == prj.title)
assert(stackPrjCopy.top().title == prj.title)

// [stack-usage-examples]
stackPrj.push(item: prj)
let stackUsage = StackUsage()
var res = stackUsage.firstItemOfSpecializedStack(p: stackPrj)
assert(res.title == prj.title)
assert(res == prj)

res = stackUsage.firstItemOfSpecializedStackWithTypedefArg(p: stackPrj)
assert(res.title == prj.title)
assert(res == prj)

res = stackUsage.firstItemOfTemplateStack(p: stackPrj)
assert(res.title == prj.title)
assert(res == prj)
// [stack-usage-examples]

// [template-funcs-examples-start]
let tm = TemplateMethods()
let maxInt = tm.max(a: 2, b: 5)
assert(maxInt == 5)
let maxString = tm.max(a: "d", b: "a")
assert(maxString == "d")

let prj1 = Project(title: "My first project")
let prj2 = Project(title: "My second project")
let pairPrjPrj = tm.makePair(a: prj1, b: prj2)
assert(Mirror(reflecting: pairPrjPrj).children.count == 2)
assert(pairPrjPrj.0.title == prj1.title)
assert(pairPrjPrj.1.title == prj2.title)

let root1 = Root(path: "/path/to/root/")
let pairRootPrj = tm.makePair(a: root1, b: prj1)
assert(Mirror(reflecting: pairRootPrj).children.count == 2)
assert(pairRootPrj.0.path == root1.path)
assert(pairRootPrj.1.title == prj1.title)

let merged1 = TemplateMethods.merge(first: [1, 2], second: [3, 4])
assert(merged1 == [1, 2, 3, 4])

let merged2 = TemplateMethods.merge(first: ["first", "second"], second: ["third"])
assert(merged2 == ["first", "second", "third"])

// [template-funcs-examples-end]

// [addressable-examples]
let path = "/path/to/root/"
let name = "root_name"
let root = Root(path: path)
let addressableRoot = AddressableImplRoot(parent: root, name: name)
assert(addressableRoot.absPath() == path + name)
let component = Component(parent: root, name: name)
// assert(component is IAddressableRoot)
assert(component.absPath() == path + name)
// [addressable-examples]

// [wrapper-examples]
let wrapperPair = WrapperPairStrings(value: ("first", "second"))
assert(wrapperPair.value.0 == "first")
assert(wrapperPair.value.1 == "second")
wrapperPair.value = ("third", "fourth")
assert(wrapperPair.value.0 == "third")
assert(wrapperPair.value.1 == "fourth")
// [wrapper-examples]


// [pair-examples]
let student = Student(stName: "John Doe")
let employee = Employee(name: "Jane Doe")
let pair1 = PairStudent(first: "student", second: student)
let pair2 = PairEmployee(first: "employee", second: employee)
assert(pair1.second.name == student.name)
assert(pair2.second.name == employee.name)
// [pair-examples]

// [array-examples-start]
let arrayFloat = ArrayFloat2(array: [1.0, 2.0])
let arrayFloatCopy = ArrayFloat2(array: arrayFloat)
assert(arrayFloat == arrayFloatCopy)
assert(arrayFloat[0] == 1.0)
let arrayFloatSum = arrayFloat + arrayFloatCopy
assert(arrayFloatSum.data() == [2.0, 4.0])

let arrayInt = ArrayInt2(array: [1, 2])
let arrayIntCopy = ArrayInt2(array: arrayInt)
assert(arrayInt == arrayIntCopy)
assert(arrayInt[0] == 1)
let arrayIntSum = arrayInt + arrayIntCopy
assert(arrayIntSum.data() == [2, 4])
// [array-examples-end]

// [template-instance-examples-start]
let vecInt = VectorInt()
vecInt.pushBack(value: 1)
assert(vecInt[0] == 1)
let vecIntCopy = VectorInt(vec: vecInt)
assert(vecInt == vecIntCopy)
let vecIntSum = vecInt + vecIntCopy
assert(vecIntSum[0] == 2)

let vecString = StringsVector()
vecString.pushBack(value: "a")
assert(vecString[0] == "a")
let vecStringCopy = StringsVector(vec: vecString)
assert(vecString == vecStringCopy)
let vecStringSum = vecString + vecStringCopy
assert(vecStringSum[0] == "aa")

let vecDouble = Vector()
vecDouble.pushBack(value: 1.0)
assert(vecDouble[0] == 1.0)
let vecDoubleCopy = Vector(vec: vecDouble)
assert(vecDouble == vecDoubleCopy)
let vecDoubleSum = vecDouble + vecDoubleCopy
assert(vecDoubleSum[0] == 2.0)

// [template-instance-examples-end]

// [variadic-examples-start]
let elemsInt = ElementsInt.create(ts1: 1, ts2: 2)
let holderInt = elemsInt.holder

assert(holderInt.count == 2)
assert(holderInt[0] == 1)
assert(holderInt[1] == 2)

let elemsString = ElementsString.create(ts1: "a", ts2: "b", ts3: "c")
let holderString = elemsString.holder

assert(holderString.count == 3)
assert(holderString[0] == "a")
assert(holderString[2] == "c")

let elemsEmpty = ElementsEmpty.create()
assert(elemsEmpty.holder.count == 0)
// [variadic-examples-end]

// check array as an arg and return letue
assert(getFirstElement(a: arrayInt) == 1)
assert(getLastElement(a: arrayInt) == 2)
let arrayMultiplied = multiplyElements(a: arrayInt, num: 2)
assert(arrayMultiplied.data() == [2, 4])

// check templated constructor
var valueObj = TemplateValue(value: 1)
assert(valueObj.add_value(other: 2) == 3)
valueObj = TemplateValue(value: "a")
assert(valueObj.add_value(other: "b") == "ab")

// check type derived from a template
let myStack = MyStackProject()
assert(myStack.empty())
myStack.push(item: prj)
assert(!myStack.empty())
assert(myStack.top().title == prj.title)
myStack.pop()
assert(myStack.empty())

}


#if os(Linux)
runTemplateExamples()
#elseif os(OSX)
class TemplatesTests: XCTestCase {

    func testRun() throws {
        runTemplateExamples()
    }
}
#endif
