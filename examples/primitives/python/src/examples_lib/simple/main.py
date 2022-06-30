from examples_lib.simple import Root, Project, Path, Holder
from examples_lib.simple import pretty_print
from examples_lib.simple.extended_task import TaskRoot, ExtendedTaskRoot
from examples_lib.simple.task import PyTask as Task

# [task-usage-start]
task = Task("My Task")
assert task.title == "My Task"
# [task-usage-end]

# [project-usage-start]
title = 'My Project'
prj = Project(title=title)
assert prj.title == title

task1 = Task('First Task')
prj.add_task(task1)
task2 = Task('Second Task')
prj.add_task(task2)

assert prj.tasks() == [task1, task2]
# [project-usage-end]

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

# [extended-types-examples]
task_root = TaskRoot('My Task', '/home')
assert task_root.title == 'My Task'
assert task_root.path == '/home'
task_root.update_title('Updated Task')
task_root.path = '/tmp'
assert task_root.title == 'Updated Task'
assert task_root.path == '/tmp'

extended_task_root = ExtendedTaskRoot('My Another Task')
assert extended_task_root.title == 'My Another Task'
assert extended_task_root.path == '/home'

extended_task_root.add_subtask(task)
assert extended_task_root.subtasks[0] == task
# [extended-types-examples]
