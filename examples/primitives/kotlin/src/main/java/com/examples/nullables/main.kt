package com.examples.nullables

import com.examples.simple.Task
import com.examples.nullables.Project

fun use() {
// [nullables-usage]
val title = "My Project"
val prj = Project(title)
prj.addTask(null)
assert(prj.tasks().size == 0)
assert(prj.getFirstTask() == null)
// [nullables-usage]
}

class NullablesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
