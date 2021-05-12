from classes import Root, Project
from classes.task import PyTask as Task

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
