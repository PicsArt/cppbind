import XCTest
import Wrapper

func runSimpleExamples() {
// [task-usage-start]
let task = Task(title: "My Task")
assert(task.title == "My Task")
// [task-usage-end]

// [project-usage-start]
let title = "My Project"
let prj = Project(title: title)
assert(prj.title == title)

let task1 = Task(title: "My Task")
prj.addTask(task: task1)
assert(prj.tasks().count == 1)
assert(prj.tasks()[0].title == task1.title)
// [project-usage-end]

// [root-usage]
let path = "/path/to/root"
let root = Root(path: path)
assert(root.path == path)
// [root-usage]

// test for checking how const& return type is handled by pybind
let holder = Holder()
assert(holder.task.title == "Initial title")
holder.task.setTitle(title: "My First Task Edited")
assert(holder.task.title == "My First Task Edited")
}

#if os(Linux)
runSimpleExamples()
#elseif os(OSX)
class SimpleTests: XCTestCase {

    func testRun() throws {
        runSimpleExamples()
    }
}
#endif
