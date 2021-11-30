import XCTest
import Wrapper

class TemplatesTests: XCTestCase {

    func test() throws {

        // [stack-examples]
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
        // [stack-examples]

        // [stack-usage-examples]
        stackPrj.push(item: prj)
        let stackUsage = StackUsage()
        var res = stackUsage.firstItemOfSpecializedStack(p: stackPrj)
        assert(res.title == prj.title)
        assert(res.cself.ptr == prj.cself.ptr)

        res = stackUsage.firstItemOfTemplateStack(arg0: stackPrj)
        assert(res.title == prj.title)
        assert(res.cself.ptr == prj.cself.ptr)
        // [stack-usage-examples]

        // [template-funcs-examples]
        let tm = TemplateMethods()
        let maxInt = tm.max(arg0: 2, arg1: 5)
        assert(maxInt == 5)
        let maxString = tm.max(arg0: "d", arg1: "a")
        assert(maxString == "d")

        let prj1 = Project(title: "My first project")
        let prj2 = Project(title: "My second project")
        let pairPrjPrj = tm.makePair(arg0: prj1, arg1: prj2)
        assert(Mirror(reflecting: pairPrjPrj).children.count == 2)
        assert(pairPrjPrj.0.title == prj1.title)
        assert(pairPrjPrj.1.title == prj2.title)

        let root1 = Root(_path: "/path/to/root/")
        let pairRootPrj = tm.makePair(arg0: root1, arg1: prj1)
        assert(Mirror(reflecting: pairRootPrj).children.count == 2)
        assert(pairRootPrj.0.path == root1.path)
        assert(pairRootPrj.1.title == prj1.title)

        // [template-funcs-examples]

        // [addressable-examples]
        let path = "/path/to/root/"
        let name = "root_name"
        let root = Root(_path: path)
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
        let student = Student(st_name: "John Doe")
        let employee = Employee(name: "Jane Doe")
        let pair1 = PairStudent(first: "student", second: student)
        let pair2 = PairEmployee(first: "employee", second: employee)
        assert(pair1.second.name == student.name)
        assert(pair2.second.name == employee.name)
        // [pair-examples]

        // [template-downcast-example]
        let containerHolder = ContainerHolder(container: stackPrj)
        assert(containerHolder.container is StackPrj)
        // [template-downcast-example]
    }
}
