package com.examples.classes

import com.examples.classes.Project
import com.examples.classes.Task
import com.examples.classes.Root

class ClassesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [project-usage]
            // create a new project
            val title = "My Project"
            val prj = Project(title)
            assert(prj.title == title)
            // add tasks to it
            val task1 = Task("My Task")
            prj.addTask(task1)
            assert(prj.tasks()[0].getObjId() == task1.getObjId())
            // [project-usage]

            // [root-usage]
            // create a new project
            val path = "/path/to/root"
            val root = Root(path)
            assert(root.path == path)
            // [root-usage]

        }

    }
}
