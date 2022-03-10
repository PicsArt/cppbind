from examples_lib.enums import Color
from examples_lib.globs import *
from examples_lib.simple import Project, Root
from examples_lib.simple.task import PyTask as Task

# [simple-usage-example]
mulInt = mul(5, 4)
assert mulInt == 20

mulInt = mul_three(5, 4, 3)
assert mulInt == 60

res = concat("Hello ", "Johnny")
assert res == "Hello Johnny"
# [simple-usage-example]

# [glob-func-examples]
res = concat1("Hello ", "Johnny ", "Jane")
assert res == "Hello Johnny Jane"

maxInt = max_int(2, 5)
assert maxInt == 5
maxString = max_str("d", "a")
assert maxString == "d"

prj1 = Project("My first project")
prj2 = Project("My second project")
pairPrjPrj = make_pair_project_project(prj1, prj2)
assert pairPrjPrj[0].title == prj1.title
assert pairPrjPrj[1].title == prj2.title

root1 = Root("/path/to/root/")
pairRootPrj = make_pair_root_project(root1, prj1)
assert pairRootPrj[0].path == root1.path
assert pairRootPrj[1].title == prj1.title
# [glob-func-examples]


color = optional_color()
assert color == Color.Red
color = optional_color(Color.Blue)
assert color == Color.Blue

int_val = optional_int()
assert int_val == 5
int_val = optional_int(8)
assert int_val == 8

optProj = optional_f_d_ptr()
assert optProj is None
optProj = optional_f_d_ptr(prj1)
assert optProj.title == prj1.title

# just calling function with no return value and arguments
do_nothing()

# [non-complex-defaults-usage]
assert optional_color() == Color.Red
assert optional_color(Color.Blue) == Color.Blue
assert optional_int() == 5
assert optional_int(1) == 1
assert optional_string() == 'abc'
assert optional_string('def') == 'def'
# [non-complex-defaults-usage]

# complex default values tests
# [complex-defaults-usage]
assert multiple_mixed_default_values() == "DefaultTask1DefaultRoot"
assert multiple_mixed_default_values(Task("ABC")) == "ABC1DefaultRoot"
assert multiple_mixed_default_values(Task("ABC"), i=2) == "ABC2DefaultRoot"
assert multiple_mixed_default_values(Task("ABC"), r=Root("Path")) == "ABC1Path"
assert multiple_mixed_default_values(Task("ABC"), i=2, r=Root("Path")) == "ABC2Path"
# [complex-defaults-usage]
