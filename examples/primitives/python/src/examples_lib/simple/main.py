from examples_lib.simple import pretty_print
from examples_lib.simple import Root, Project, Path, Holder
from examples_lib.simple.task import PyTask as Task

# [task-usage]
task = Task("My Task")
assert task.title == "My Task"
# [task-usage]

# [project-usage]
title = 'My Project'
prj = Project(title=title)
assert prj.title == title

task1 = Task('First Task')
prj.add_task(task1)
task2 = Task('Second Task')
prj.add_task(task2)

assert prj.tasks() == [task1, task2]
# [project-usage]

# [root-usage]
path = '/path/to/root/'
root = Root(path)
assert root.path == path
# [root-usage]

# [implicit-cast-example]
path_obj = Path('/some/path')
root_from_obj = Root(path_obj)
assert root_from_obj.path == path_obj.value
another_path_obj = path_obj = Path('/some/other/path')
root_from_obj.path = another_path_obj
assert root_from_obj.path == another_path_obj.value
root_from_obj.set_path(path_obj)
assert root_from_obj.path == path_obj.value
# [implicit-cast-example]


# test for checking how const& return type is handled by pybind
holder = Holder()
assert holder.task.title == "Initial title"
holder.task.set_title("My First Task Edited")
assert holder.task.title == "My First Task Edited"

# test for dir actions with current path
pretty_print('{"first_name": "John", "last_name": "Doe"}')
