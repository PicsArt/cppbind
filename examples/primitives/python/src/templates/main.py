from templates.stack_pygen import StackProject, StackTask
from templates.stack_usage_pygen import StackUsage
from templates.template_functions_pygen import TemplateMethods
from templates.addressable_pygen import AddressableRoot
from templates.component_pygen import Component
from simple.project_pygen import Project
from simple.root_pygen import Root
from simple.task_pygen import Task

# [stack-examples]
stack_prj = StackProject()
assert stack_prj.empty()
prj = Project(title="My Project")
stack_prj.push(item=prj)
assert stack_prj.empty() is False
assert stack_prj.top().title == prj.title
stack_prj.pop()
assert stack_prj.empty() is True
# [stack-examples]

# [stack-usage-examples]
stack_prj.push(item=prj)
stack_usage = StackUsage()
res = stack_usage.first_item_of_specialized(p=stack_prj)
assert res.title == prj.title

res = stack_usage.first_item_of_template(arg0=stack_prj)
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

task1 = Task(title="My Task")
pair_task_prj = tm.make_pair(arg0=task1, arg1=prj1)
assert len(pair_task_prj) == 2
assert pair_task_prj[0].title == task1.title
assert pair_task_prj[1].title == prj1.title

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
