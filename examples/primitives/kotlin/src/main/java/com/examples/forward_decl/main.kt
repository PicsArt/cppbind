package com.examples.forward_decl

import com.examples.forward_decl.*

class ForwardDeclsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [forward-decl-usage]
            val student1 = Student()
            val student2 = Student()
            val teacher1 = Teacher()
            val teacher2 = Teacher()

            // teacher1 has 2 students
            student1.addTeacher(teacher1)
            teacher1.addStudent(student1)
            student2.addTeacher(teacher1)
            teacher1.addStudent(student2)

            // teacher2 has 1 student
            student2.addTeacher(teacher2)
            teacher2.addStudent(student2)

            assert(teacher1.students().size == 2)
            assert(teacher2.students().size == 1)

            assert(student1.teachers().size == 1)
            assert(student2.teachers().size == 2)
            // [forward-decl-usage]
        }

    }
}
