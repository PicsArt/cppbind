import Wrapper

// [project-usage]
//create a project
let title = "My Project";
let prj = Project(title: title);
assert(prj.title == title);

// add a task to it
let task1 = Task(title: "My Task");
prj.addTask(task: task1);
assert(prj.tasks().count == 1);
assert(prj.tasks()[0].title == task1.title);
// [project-usage]