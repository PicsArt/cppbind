package com.examples.classes

import com.examples.classes.Project
import com.examples.classes.Task

fun createProject() {

    // [[project-usage]]
    // create a new project
    val title = "My Project"
    val prj = Project(title)
    assert(prj.title == title)
    // add tasks to it
    val task1 = Task("My Task")
    prj.addTask(task1)
    assert(prj.tasks()[0].getObjId() == task1.getObjId())
    // [[project-usage]]
}