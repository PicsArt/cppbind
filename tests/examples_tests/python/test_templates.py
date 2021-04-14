import unittest
from templates.stack_pygen import StackTask, StackProject
from templates.component_pygen import Component, AddressableRoot
from classes.project_pygen import Project
from classes.task_pygen import Task
from classes.root_pygen import Root
from templates.template_functions_pygen import TemplateFunctions


class TestOverloadedFunctions(unittest.TestCase):

    def setUp(self) -> None:
        self.st_prj = StackProject()
        self.st_task = StackTask()

    def test_stack_functionality(self):
        prj1 = Project('Project 1')
        task1 = Task('T1')
        prj1.add_task(task1)
        prj2 = Project('Project 2')
        task2 = Task('T2')
        task3 = Task('T3')
        prj2.add_task(task2)
        prj2.add_task(task3)
        self.assertTrue(self.st_prj.empty())

        self.st_prj.push(prj1)
        self.st_prj.push(prj2)
        self.assertFalse(self.st_prj.empty())
        top1 = self.st_prj.top()
        self.assertEquals(top1, prj2)
        self.assertEquals(top1.tasks(), [task2, task3])
        self.st_prj.pop()
        self.st_prj.pop()
        self.assertTrue(self.st_prj.empty())

    def test_stack_negative(self):
        prj1 = Project('Project 1')
        with self.assertRaises(TypeError) as ctx:
            self.st_task.push(prj1)
        self.assertTrue('incompatible function arguments' in str(ctx.exception))


class TestComponent(unittest.TestCase):

    def setUp(self) -> None:
        self.root = Root('/pat/to/root/')
        self.name = 'component'
        self.component = Component(self.root, self.name)

    def test_component_path(self):
        self.assertEquals(self.component.abs_path(), self.root.path + self.name)
        self.assertIsInstance(self.component, AddressableRoot)


class TestTemplateFunctions(unittest.TestCase):

    def setUp(self) -> None:
        self.tf = TemplateFunctions()
        self.prj1 = Project('P1')
        self.prj2 = Project('P2')
        self.task = Project('T1')

    def test_max(self):
        self.assertEquals(self.tf.max(5, 1), 5)
        self.assertEquals(self.tf.max('za', 'az'), 'za')

    def test_make_pair(self):
        pair1 = self.tf.make_pair(self.prj1, self.prj2)
        self.assertEquals(pair1[0].title, self.prj1.title)
        self.assertEquals(pair1[1].title, self.prj2.title)
        pair2 = self.tf.make_pair(self.task, self.prj1)
        self.assertEquals(pair2[0].title, self.task.title)
        self.assertEquals(pair2[1].title, self.prj1.title)

    def test_max_negative(self):
        with self.assertRaises(TypeError) as ctx:
            # call with wrong types
            self.tf.max(5.0, 1.0)
        self.assertTrue('incompatible function arguments' in str(ctx.exception))

    def test_make_pair_negative(self):
        with self.assertRaises(TypeError) as ctx:
            # call with wrong types
            self.tf.make_pair(1, 2)
        self.assertTrue('incompatible function arguments' in str(ctx.exception))


if __name__ == '__main__':
    unittest.main()
