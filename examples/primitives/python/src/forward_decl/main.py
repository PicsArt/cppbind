from forward_decl.student_pygen import Student
from forward_decl.teacher_pygen import Teacher

# [forward-decl-usage]
student1 = Student()
student2 = Student()
teacher1 = Teacher()
teacher2 = Teacher()

# teacher1 has 2 students
student1.add_teacher(teacher1)
teacher1.add_student(student1)
student2.add_teacher(teacher1)
teacher1.add_student(student2)

# teacher2 has 1 student
student2.add_teacher(teacher2)
teacher2.add_student(student2)

assert len(teacher1.students()) == 2
assert len(teacher2.students()) == 1

assert len(student1.teachers()) == 1
assert len(student2.teachers()) == 2
# [forward-decl-usage]
