import XCTest
import Wrapper

class TemplatesTests: XCTestCase {

    func test() throws {
        // [glob-func-examples]
        let res = concat(str1: "Hello ", str2: "Johnny")
        assert(res == "Hello Johnny" )

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

        let root1 = Root(_path: "/path/to/root/")
        let pairRootPrj = makePair(arg0: root1, arg1: prj1)
        assert(Mirror(reflecting: pairRootPrj).children.count == 2)
        assert(pairRootPrj.0.path == root1.path)
        assert(pairRootPrj.1.title == prj1.title)
        // [glob-func-examples]
    }
}
