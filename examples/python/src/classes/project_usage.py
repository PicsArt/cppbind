from project_pygen import Project
from task_pygen import Task


def create_project():
    # [[project-usage]]
    # create a new project
    title = 'My Project'
    prj = Project(title=title)
    assert prj.title == title
    # add tasks to it
    task1 = Task('First Task')
    prj.add_task(task1)
    task2 = Task('Second Task')
    prj.add_task(task2)
    assert prj.tasks() == [task1, task2]
    # [[project-usage]]
