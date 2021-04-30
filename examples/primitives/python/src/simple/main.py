from project_pygen import Project
from task_pygen import Task
from simple.root_pygen import Root

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
# create a new root instance
path = '/path/to/root/'
root = Root(path)
assert root.path == path
# [root-usage]
