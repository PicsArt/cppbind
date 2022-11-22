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
    ArrayInt2,
    ArrayFloat2,
    get_first_element_int,
    get_last_element_int2,
    multiply_elements,
    VectorInt,
    StringsVector,
    Vector,
    ElementsString,
    ElementsInt,
    ElementsEmpty
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

stack_prj.push(prj)
stack_prj_copy = StackPrj(stack_prj)
assert stack_prj.top() == stack_prj_copy.top()
# [stack-examples-end]

# other test cases
assert(stack_prj.top().title == prj.title)
assert(stack_prj_copy.top().title == prj.title)

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

merged1 = TemplateMethods.merge([1, 2], [3, 4])
assert(merged1 == [1, 2, 3, 4])

merged2 = TemplateMethods.merge(["first", "second"], ["third"])
assert(merged2 == ["first", "second", "third"])
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

# [array-examples-start]
arrayFloat = ArrayFloat2([1.0, 2.0])
arrayFloatCopy = ArrayFloat2(arrayFloat)
assert(arrayFloat == arrayFloatCopy)
assert(arrayFloat[0] == 1.0)
arrayFloatSum = arrayFloat + arrayFloatCopy
assert(arrayFloatSum.data() == [2.0, 4.0])

arrayInt = ArrayInt2([1, 2])
arrayIntCopy = ArrayInt2(arrayInt)
assert(arrayInt == arrayIntCopy)
assert(arrayInt[0] == 1)
arrayIntSum = arrayInt + arrayIntCopy
assert(arrayIntSum.data() == [2, 4])
# [array-examples-end]

# [template-instance-examples-start]
vec_int = VectorInt()
vec_int.push_back(1)
assert(vec_int[0] == 1)
vec_int_copy = VectorInt(vec_int)
assert(vec_int == vec_int_copy)
vec_int_sum = vec_int + vec_int_copy
assert(vec_int_sum[0] == 2)

vec_string = StringsVector()
vec_string.push_back("a")
assert(vec_string[0] == "a")
vec_string_copy = StringsVector(vec_string)
assert(vec_string == vec_string_copy)
vec_string_sum = vec_string + vec_string_copy
assert(vec_string_sum[0] == "aa")

vec_double = Vector()
vec_double.push_back(1.0)
assert(vec_double[0] == 1.0)
vec_double_copy = Vector(vec_double)
assert(vec_double == vec_double_copy)
vec_double_sum = vec_double + vec_double_copy
assert(vec_double_sum[0] == 2.0)
# [template-instance-examples-end]

# [variadic-examples-start]

elemsInt = ElementsInt.create(1, 2)
holderInt = elemsInt.holder

assert(len(holderInt) == 2)
assert(holderInt[0] == 1)
assert(holderInt[1] == 2)

elemsString = ElementsString.create("a", "b", "c")
holderString = elemsString.holder

assert(len(holderString) == 3)
assert(holderString[0] == "a")
assert(holderString[2] == "c")

elemsEmpty = ElementsEmpty.create()
assert(len(elemsEmpty.holder) == 0)

# [variadic-examples-end]

# check array as an arg and return value
assert(get_first_element_int(arrayInt) == 1)
assert(get_last_element_int2(arrayInt) == 2)

arrayMultiplied = multiply_elements(arrayInt, 2)
assert(arrayMultiplied.data() == [2, 4])

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