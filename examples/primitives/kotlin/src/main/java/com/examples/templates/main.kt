package com.examples.templates

import com.examples.templates.*
import com.examples.simple.*
import com.examples.forward_decl.student.Student
import com.examples.overloads.Employee
import com.examples.getters.NumberInt

fun use() {
// [stack-examples]
var stackPrj = StackPrj()
assert(stackPrj.empty())
val prj = Project("My Project")
stackPrj.push(prj)
assert(!stackPrj.empty())
assert(stackPrj.top().title == prj.title)
stackPrj.pop()
assert(stackPrj.empty())

val stackNumber = StackNumInt()
val num1 = NumberInt(1)
val num2 = NumberInt(2)
stackNumber.push(num1)
stackNumber.push(num2)
assert(stackNumber.top().num == num2.num)
stackNumber.pop()
assert(stackNumber.top().num == num1.num)
// [stack-examples]

// [stack-usage-examples]
stackPrj.push(prj)
var stackUsage = StackUsage()
var res = stackUsage.firstItemOfSpecializedStack(stackPrj)
assert(res.title == prj.title)
assert(res.equals(prj))

res = stackUsage.firstItemOfSpecializedStackWithTypedefArg(stackPrj)
assert(res.title == prj.title)
assert(res.equals(prj))

res = stackUsage.firstItemOfTemplateStack(stackPrj)
assert(res.title == prj.title)
assert(res.equals(prj))
// [stack-usage-examples]

// [template-funcs-examples]
val tm = TemplateMethods()
val maxInt = tm.max(2, 5)
assert(maxInt == 5)
val maxString = tm.max("d", "a")
assert(maxString == "d")

val prj1 = Project("My first project")
val prj2 = Project("My second project")
var pairPrjPrj = tm.makePair(prj1, prj2)
assert(pairPrjPrj.first.title == prj1.title)
assert(pairPrjPrj.second.title == prj2.title)

val root1 = Root("/path/to/root/")
var pairRootPrj = tm.makePair(root1, prj1)
assert(pairRootPrj.first.path == root1.path)
assert(pairRootPrj.second.title == prj1.title)

// [template-funcs-examples]

// [addressable-examples]
val path = "/path/to/root/"
val name = "root_name"
val root = Root(path)
val addressableRoot = AddressableImplRoot(root, name)
assert(addressableRoot.absPath() == path + name)
val component = Component(root, name)
assert(component.absPath() == path + name)
// [addressable-examples]

// [wrapper-examples]
val wrapperPair = WrapperPairStrings(Pair<String, String>("first", "second"))
assert(wrapperPair.value.first == "first")
assert(wrapperPair.value.second == "second")
wrapperPair.value = Pair<String, String>("third", "fourth")
assert(wrapperPair.value.first == "third")
assert(wrapperPair.value.second == "fourth")
// [wrapper-examples]

// [pair-examples]

val student = Student("John Doe")
val employee = Employee("Jane Doe")
var pair1 = PairStudent("student", student)
var pair2 = PairEmployee("employee", employee)
assert(pair1.second.name == student.name)
assert(pair2.second.name == employee.name)
// [pair-examples]

component.close()
addressableRoot.close()

// check templated constructor
var valueObj = TemplateValue(1)
assert(valueObj.add_value(2) == 3)
valueObj = TemplateValue("a")
assert(valueObj.add_value("b") == "ab")
valueObj.close()

// check type derived from a template
val myStack = MyStackProject()
assert(myStack.empty())
myStack.push(prj)
assert(!myStack.empty())
assert(myStack.top().title == prj.title)
myStack.pop()
assert(myStack.empty())

}

class TemplatesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
