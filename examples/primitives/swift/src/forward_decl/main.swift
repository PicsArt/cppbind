import Wrapper

// [forward-decl-usage]
let student1 = Student()
let student2 = Student()
let teacher1 = Teacher()
let teacher2 = Teacher()

// teacher1 has 2 students
student1.addTeacher(t: teacher1)
teacher1.addStudent(s: student1)
student2.addTeacher(t: teacher1)
teacher1.addStudent(s: student2)

// teacher2 has 1 student
student2.addTeacher(t: teacher2)
teacher2.addStudent(s: student2)

assert(teacher1.students().count == 2)
assert(teacher2.students().count == 1)

assert(student1.teachers().count == 1)
assert(student2.teachers().count == 2)
// [forward-decl-usage]