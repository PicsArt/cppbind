from examples_lib.forward_decl.student_pygen import Student
from examples_lib.getters import NumberInt
from examples_lib.overloads.employee_pygen import Employee
from examples_lib.simple import Project, Root
from examples_lib.templates import (
    AddressableRoot,
    Component,
    StackPrj,
    StackNumInt,
    StackUsage,
    TemplateMethods,
    WrapperPairStrings,
    PairEmployee,
    PairStudent,
    TemplateValue,
    MyStackProject,
)

# [stack-examples-start]
stack_prj = StackPrj()
assert stack_prj.empty()
prj = Project(title="My Project")
stack_prj.push(item=prj)
assert stack_prj.empty() is False
assert stack_prj.top().title == prj.title
stack_prj.pop()
assert stack_prj.empty() is True

stackNumber = StackNumInt()
num1 = NumberInt(1)
num2 = NumberInt(2)
stackNumber.push(num1)
stackNumber.push(num2)
assert stackNumber.top().num == num2.num
stackNumber.pop()
assert stackNumber.top().num == num1.num
# [stack-examples-end]

# [stack-usage-examples]
stack_prj.push(item=prj)
stack_usage = StackUsage()
res = stack_usage.first_item_of_specialized_stack(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_specialized_stack_with_typedef_arg(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_template_stack(p=stack_prj)
assert res.title == prj.title
# [stack-usage-examples]

# [template-funcs-examples-start]
tm = TemplateMethods()
max_int = tm.max(a=2, b=5)
assert max_int == 5
max_string = tm.max(a="d", b="a")
assert max_string == "d"

prj1 = Project(title="My first project")
prj2 = Project(title="My second project")
pair_prj_prj = tm.make_pair(a=prj1, b=prj2)
assert len(pair_prj_prj) == 2
assert pair_prj_prj[0].title == prj1.title
assert pair_prj_prj[1].title == prj2.title

root1 = Root("/path/to/root/")
pair_root_prj = tm.make_pair(a=root1, b=prj1)
assert len(pair_root_prj) == 2
assert pair_root_prj[0].path == root1.path
assert pair_root_prj[1].title == prj1.title
# [template-funcs-examples-end]

# [addressable-examples]
path = "/path/to/root/"
name = "root_name"
root = Root(_path=path)
addressable_root = AddressableRoot(parent=root, name=name)
assert addressable_root.abs_path() == path + name
component = Component(parent=root, name=name)
assert isinstance(component, AddressableRoot)
assert component.abs_path() == path + name
# [addressable-examples]


# [wrapper-examples]
wrapper_pair = WrapperPairStrings(("first", "second"))
assert wrapper_pair.value[0] == "first"
assert (wrapper_pair.value[1] == "second")
wrapper_pair.value = ("third", "fourth")
assert (wrapper_pair.value[0] == "third")
assert (wrapper_pair.value[1] == "fourth")
# [wrapper-examples]

# [pair-examples]
student = Student(st_name="John Doe")
employee = Employee(name="Jane Doe")
pair1 = PairStudent(first="student", second=student)
pair2 = PairEmployee(first="employee", second=employee)
assert pair1.second.name == student.name
pair1.second.name = "updated name"
assert pair1.second == student
assert student.name == "updated name"
assert pair2.second.name == employee.name
# [pair-examples]

# check templated constructor
value_obj = TemplateValue(1)
assert value_obj.add_value(2) == 3
value_obj = TemplateValue("a")
assert value_obj.add_value("b") == "ab"

# check type derived from a template
my_stack = MyStackProject()
assert my_stack.empty()
my_stack.push(prj)
assert my_stack.empty() is False
assert my_stack.top().title == prj.title
my_stack.pop()
assert my_stack.empty()