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
    ElementsString,
    ElementsInt,
    ElementsEmpty,
    Vector,
    TupleTwoInt,
    TupleThreeInt,
    TupleDoubleInt,
    IntsTuple,
    MyTupleDouble,
    MyTupleInt,
    get_tuple_first_element_int_double,
    get_tuple_first_element_int_int, Array4Int, Array4Float
)
from examples_lib.templates.stack import RootsStack

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
assert stack_prj.top().title == prj.title
assert stack_prj_copy.top().title == prj.title

# [stack-usage-examples]
stack_prj.push(item=prj)
stack_usage = StackUsage()
res = stack_usage.first_item_of_specialized_stack(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_specialized_stack_with_typedef_arg(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_template_stack(p=stack_prj)
assert res.title == prj.title

# specialized stack usage
stack_root = RootsStack()
root_home = Root("/home")
stack_root.push(root_home)
assert (stack_root.top().path == root_home.path)
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
assert merged1 == [1, 2, 3, 4]

merged2 = TemplateMethods.merge(["first", "second"], ["third"])
assert merged2 == ["first", "second", "third"]
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
assert wrapper_pair.value[1] == "second"
wrapper_pair.value = ("third", "fourth")
assert wrapper_pair.value[0] == "third"
assert wrapper_pair.value[1] == "fourth"
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
array_float = ArrayFloat2([1.0, 2.0])
array_float_copy = ArrayFloat2(array_float)
assert array_float == array_float_copy
assert array_float[0] == 1.0
array_float_sum = array_float + array_float_copy
assert array_float_sum.data() == [2.0, 4.0]

array_int = ArrayInt2([1, 2])
array_int_copy = ArrayInt2(array_int)
assert array_int == array_int_copy
assert array_int[0] == 1
array_int_sum = array_int + array_int_copy
assert array_int_sum.data() == [2, 4]

# template specialization example
array4_int = Array4Int([1, 2, 3, 4])
assert(array4_int[0] == 1)
assert(array4_int[3] == 4)

array4_float = Array4Float([1.0, 2.0, 3.0, 4.0])
assert(array4_float[0] == 1.0)
assert(array4_float[3] == 4.0)
# [array-examples-end]

# [template-instance-examples-start]
vec_int = VectorInt()
vec_int.push_back(1)
assert vec_int[0] == 1
vec_int_copy = VectorInt(vec_int)
assert vec_int == vec_int_copy
vec_int_sum = vec_int + vec_int_copy
assert vec_int_sum[0] == 2

vec_string = StringsVector()
vec_string.push_back("a")
assert vec_string[0] == "a"
vec_string_copy = StringsVector(vec_string)
assert vec_string == vec_string_copy
vec_string_sum = vec_string + vec_string_copy
assert vec_string_sum[0] == "aa"

vec_double = Vector()
vec_double.push_back(1.0)
assert vec_double[0] == 1.0
vec_double_copy = Vector(vec_double)
assert vec_double == vec_double_copy
vec_double_sum = vec_double + vec_double_copy
assert vec_double_sum[0] == 2.0
# [template-instance-examples-end]

# [variadic-examples-start]

elems_int = ElementsInt.create(1, 2)
holder_int = elems_int.holder

assert len(holder_int) == 2
assert holder_int[0] == 1
assert holder_int[1] == 2

elems_string = ElementsString.create("a", "b", "c")
holder_string = elems_string.holder

assert len(holder_string) == 3
assert holder_string[0] == "a"
assert holder_string[2] == "c"

elems_empty = ElementsEmpty.create()
assert len(elems_empty.holder) == 0

# [variadic-examples-end]

# [tuple-examples-start]
tuple_double_int = TupleDoubleInt(1, 1.0)
assert tuple_double_int.tail == 1
assert tuple_double_int.rest.tail == 1.0

tuple_three_int = TupleThreeInt(1, 2, 3)
assert tuple_three_int.tail == 1
assert tuple_three_int.rest.tail == 2
assert tuple_three_int.rest.rest.tail == 3

tuple_two_int = TupleTwoInt(1, 2)
assert tuple_two_int.tail == 1
assert tuple_two_int.rest.tail == 2
# [tuple-examples-end]

# tuple other usage examples
ints_tuple = IntsTuple(1, 2, 3)
assert ints_tuple.tail == 1
assert ints_tuple.rest.tail == 2
assert ints_tuple.rest.rest.tail == 3

my_tuple_double = MyTupleDouble(1.0, 5.0)
assert my_tuple_double.tail == 1.0
assert my_tuple_double.rest.tail == 5.0

my_tuple_int = MyTupleInt(1, 2)
assert my_tuple_int.tail == 1
assert my_tuple_int.rest.tail == 2

assert get_tuple_first_element_int_double(tuple_double_int) == 1
assert get_tuple_first_element_int_int(tuple_two_int) == 1

# check array as an arg and return value
assert get_first_element_int(array_int) == 1
assert get_last_element_int2(array_int) == 2

arrayMultiplied = multiply_elements(array_int, 2)
assert arrayMultiplied.data() == [2, 4]

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
