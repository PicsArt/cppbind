from simple import pretty_print
from simple import Root, Project, Path
from simple.task import PyTask as Task

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

# [path-usage]
path_obj = Path('/some/path')
root_from_obj = Root(path_obj)
root.path = path_obj
# [path-usage]

# test for dir actions with current path
pretty_print('{"first_name": "John", "last_name": "Doe"}')
