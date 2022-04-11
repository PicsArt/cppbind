from examples_lib.simple import Root
from examples_lib.simple.task import PyTask


class TaskRoot(PyTask, Root):

    def __init__(self, title: str, path: str):
        # pybind requires to explicitly call init otherwise throws TypeError
        # https://pybind11.readthedocs.io/en/stable/advanced/classes.html?highlight=metaclass#overriding-virtual-functions-in-python
        PyTask.__init__(self, title)
        Root.__init__(self, path)

    def set_path(self, new_path):
        self.path = new_path

    def update_title(self, new_title):
        self.set_title(new_title)


class ExtendedTaskRoot(TaskRoot):

    def __init__(self, title: str, path: str = '/home'):
        super().__init__(title, path)
        self._subtasks = []

    def get_path(self):
        return self.path

    def add_subtask(self, task: PyTask):
        self._subtasks.append(task)

    @property
    def subtasks(self):
        return self._subtasks
