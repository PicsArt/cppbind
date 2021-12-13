from examples_lib.globs.utils_pygen import concat, make_pair_root_project, make_pair_project_project, max_int, max_str
from examples_lib.simple import Project, Root

prj1 = Project("My first project")

# [glob-func-examples]
res = concat("Hello ", "Johnny")
assert res == "Hello Johnny"

maxInt = max_int(2, 5)
assert maxInt == 5
maxString = max_str("d", "a")
assert maxString == "d"

prj1 = Project("My first project")
prj2 = Project("My second project")
pairPrjPrj = make_pair_project_project(prj1, prj2)
assert pairPrjPrj[0].title == prj1.title
assert pairPrjPrj[1].title == prj2.title

root1 = Root("/path/to/root/")
pairRootPrj = make_pair_root_project(root1, prj1)
assert pairRootPrj[0].path == root1.path
assert pairRootPrj[1].title == prj1.title
# [glob-func-examples]
