from examples_lib.forward_decl.student_pygen import Student
from examples_lib.forward_decl.teacher_pygen import Teacher

# [forward-decl-usage]
student1 = Student(st_name='John Doe')
student2 = Student('Jane Doe')
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


# overloaded constructor test cases
student3 = Student([teacher1])
student4 = Student(teachers=[teacher1, teacher2])

assert len(student3.teachers()) == 1
assert len(student4.teachers()) == 2
