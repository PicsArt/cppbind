from classes.task_pygen import Task


def create_task():
    # [[task-usage]]
    # create a new task
    title = 'My Task'
    root = Task(title)
    assert root.title == title
    # [[task-usage]]
