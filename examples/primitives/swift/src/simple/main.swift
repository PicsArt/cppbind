import Wrapper

// [task-usage]
let task = Task(title: "My Task")
assert(task.title == "My Task")
// [task-usage]

// [project-usage]
let title = "My Project"
let prj = Project(title: title)
assert(prj.title == title)

let task1 = Task(title: "My Task")
prj.addTask(task: task1)
assert(prj.tasks().count == 1)
assert(prj.tasks()[0].title == task1.title)
// [project-usage]

// [root-usage]
let path = "/path/to/root"
let root = Root(_path: path)
assert(root.path == path)
// [root-usage]
