package com.examples.forward_decl

import com.examples.forward_decl.teacher.Teacher
import com.examples.forward_decl.student.Student

fun use() {
// [forward-decl-usage]
val student1 = Student("John Doe")
val student2 = Student("Jane Doe")
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

// overloaded constructor test cases
val student3 = Student(listOf(teacher1))
val student4 = Student(listOf(teacher1, teacher2))

assert(student3.teachers().size == 1)
assert(student4.teachers().size == 2)

// deallocate memory
teacher1.close()
teacher2.close()
student1.close()
student2.close()
student3.close()
student4.close()
}

class ForwardDeclsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
        }

    }
}
