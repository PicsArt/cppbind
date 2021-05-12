package com.examples.simple

import com.examples.simple.Project
import com.examples.simple.Task
import com.examples.simple.Root

fun use() {
// [task-usage]
val task = Task("My Task")
assert(task.title == "My Task")
// [task-usage]

// [project-usage]
val title = "My Project"
val prj = Project(title)
assert(prj.title == title)
val task1 = Task("My Task")
prj.addTask(task1)
assert(prj.tasks().size == 1)
assert(prj.tasks()[0].title == task1.title)
// [project-usage]

assert(prj.tasks()[0].getObjId() == task1.getObjId())

// [root-usage]
// create a new project
val path = "/path/to/root"
val root = Root(path)
assert(root.path == path)
// [root-usage]

}

class SimpleApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
           use()
        }

    }
}
