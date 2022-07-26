from examples_lib.factories import School
from examples_lib.forward_decl import Teacher

# [factories-usage-start]

school1 = School()
teacher = Teacher()
school1.add_teacher(teacher)
assert len(school1.teachers) == 1
school2 = School([teacher])
assert len(school2.teachers) == 1
# [factories-usage-end]
