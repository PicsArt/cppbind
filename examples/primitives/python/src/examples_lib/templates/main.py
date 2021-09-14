from examples_lib.getters import Numberint
from examples_lib.simple import Project, Root
from examples_lib.templates.addressable_pygen import AddressableRoot
from examples_lib.templates.component_pygen import Component
from examples_lib.templates.stack_pygen import StackPrj, StackNumInt
from examples_lib.templates.stack_usage_pygen import StackUsage
from examples_lib.templates.template_methods_pygen import TemplateMethods
from examples_lib.templates.wrapper_pygen import WrapperPairStrings

# [stack-examples]
stack_prj = StackPrj()
assert stack_prj.empty()
prj = Project(title="My Project")
stack_prj.push(item=prj)
assert stack_prj.empty() is False
assert stack_prj.top().title == prj.title
stack_prj.pop()
assert stack_prj.empty() is True

stackNumber = StackNumInt()
num1 = Numberint(1)
num2 = Numberint(2)
stackNumber.push(num1)
stackNumber.push(num2)
assert stackNumber.top().num == num2.num
stackNumber.pop()
assert stackNumber.top().num == num1.num
# [stack-examples]

# [stack-usage-examples]
stack_prj.push(item=prj)
stack_usage = StackUsage()
res = stack_usage.first_item_of_specialized_stack(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_template_stack(arg0=stack_prj)
assert res.title == prj.title
# [stack-usage-examples]

# [template-funcs-examples]
tm = TemplateMethods()
max_int = tm.max(arg0=2, arg1=5)
assert max_int == 5
max_string = tm.max(arg0="d", arg1="a")
assert max_string == "d"

prj1 = Project(title="My first project")
prj2 = Project(title="My second project")
pair_prj_prj = tm.make_pair(arg0=prj1, arg1=prj2)
assert len(pair_prj_prj) == 2
assert pair_prj_prj[0].title == prj1.title
assert pair_prj_prj[1].title == prj2.title

root1 = Root("/path/to/root/")
pair_root_prj = tm.make_pair(arg0=root1, arg1=prj1)
assert len(pair_root_prj) == 2
assert pair_root_prj[0].path == root1.path
assert pair_root_prj[1].title == prj1.title
# [template-funcs-examples]

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
