import Wrapper

// [stack-examples]
let stackPrj = StackProject()
assert(stackPrj.empty())
let prj = Project(title: "My Project")
stackPrj.push(item: prj)
assert(!stackPrj.empty())
assert(stackPrj.top().title == prj.title)
stackPrj.pop()
assert(stackPrj.empty())
// [stack-examples]

// [stack-usage-examples]
stackPrj.push(item: prj)
let stackUsage = StackUsage()
var res = stackUsage.firstItemOfSpecializedStack(p: stackPrj)
assert(res.title == prj.title)
assert(res.cself == prj.cself)

res = stackUsage.firstItemOfTemplateStack(arg0: stackPrj)
assert(res.title == prj.title)
assert(res.cself == prj.cself)
// [stack-usage-examples]

// [template-funcs-examples]
let tm = TemplateMethods()
let maxInt = tm.max(arg0: 2, arg1: 5)
assert(maxInt == 5)
let maxString = tm.max(arg0: "d", arg1: "a")
assert(maxString == "d")

let prj1 = Project(title: "My first project")
let prj2 = Project(title: "My second project")
let pairPrjPrj = tm.makePair(arg0: prj1, arg1: prj2)
assert(Mirror(reflecting: pairPrjPrj).children.count == 2)
assert(pairPrjPrj.0.title == prj1.title)
assert(pairPrjPrj.1.title == prj2.title)

let root1 = Root(_path: "/path/to/root/")
let pairRootPrj = tm.makePair(arg0: root1, arg1: prj1)
assert(Mirror(reflecting: pairRootPrj).children.count == 2)
assert(pairRootPrj.0.path == root1.path)
assert(pairRootPrj.1.title == prj1.title)

// [template-funcs-examples]

// [addressable-examples]
let path = "/path/to/root/"
let name = "root_name"
let root = Root(_path: path)
let addressableRoot = Addressable_implRoot(parent: root, name: name)
assert(addressableRoot.absPath() == path + name)
let component = Component(parent: root, name: name)
// assert(component is IAddressableRoot)
assert(component.absPath() == path + name)
// [addressable-examples]
