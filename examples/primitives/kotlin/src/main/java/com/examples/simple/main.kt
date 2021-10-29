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

// test for checking how const& return type is handled by pybind
val holder = Holder()
assert(holder.task.title == "My First Task Edited")
holder.task.setTitle("My First Task Edited")
assert(holder.task.title == "My First Task Edited")

}

class SimpleApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
           use()
        }

    }
}
