package com.examples.factories

import com.examples.forward_decl.teacher.*

fun use() {

// [factories-usage-start]
val school1 = School()
val teacher = Teacher()
school1.addTeacher(teacher)
assert(school1.teachers.size == 1)
val school2 = School(listOf(teacher))
assert(school2.teachers.size == 1)
// [factories-usage-end]

}

class FactoriesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }

}
