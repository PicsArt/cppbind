from simple import Root, Project
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