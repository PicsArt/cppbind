package com.examples.templates

import com.examples.templates.*
import com.examples.templates.stack.RootsStack
import com.examples.simple.*
import com.examples.forward_decl.student.Student
import com.examples.overloads.Employee
import com.examples.getters.NumberInt

fun use() {
// [stack-examples-start]
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

stackPrj.push(prj)
val stackPrjCopy = StackPrj(stackPrj)
assert(stackPrj.top() == stackPrjCopy.top())

// specialized stack usage
val stackRoot = RootsStack()
val rootHome = Root("/home")
stackRoot.push(rootHome)
assert(stackRoot.top().path == rootHome.path)

// [stack-examples-end]

//other test cases
assert(stackPrj.top().title == prj.title)
assert(stackPrjCopy.top().title == prj.title)

// [stack-usage-examples]
stackPrj.push(prj)
var stackUsage = StackUsage()
var res = stackUsage.firstItemOfSpecializedStack(stackPrj)
assert(res.title == prj.title)
assert(res == prj)

res = stackUsage.firstItemOfSpecializedStackWithTypedefArg(stackPrj)
assert(res.title == prj.title)
assert(res == prj)

res = stackUsage.firstItemOfTemplateStack(stackPrj)
assert(res.title == prj.title)
assert(res == prj)
// [stack-usage-examples]

// [template-funcs-examples-start]
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

val merged1 = TemplateMethods.merge(listOf(1, 2), listOf(3, 4))
assert(merged1 == listOf(1, 2, 3, 4))

val merged2 = TemplateMethods.merge(listOf("first", "second"), listOf("third"))
assert(merged2 == listOf("first", "second", "third"))
// [template-funcs-examples-end]

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

// [array-examples-start]
val arrayFloat = ArrayFloat2(listOf(1.0F, 2.0F))
val arrayFloatCopy = ArrayFloat2(arrayFloat)
assert(arrayFloat == arrayFloatCopy)
assert(arrayFloat[0] == 1.0F)
val arrayFloatSum = arrayFloat + arrayFloatCopy
assert(arrayFloatSum.data() == listOf(2.0F, 4.0F))

val arrayInt = ArrayInt2(listOf(1, 2))
val arrayIntCopy = ArrayInt2(arrayInt)
assert(arrayInt == arrayIntCopy)
assert(arrayInt[0] == 1)
val arrayIntSum = arrayInt + arrayIntCopy
assert(arrayIntSum.data() == listOf(2, 4))

// template specialization example
val array4Int = Array4Int(listOf(1, 2, 3, 4))
assert(array4Int[0] == 1)
assert(array4Int[3] == 4)

val array4Float = Array4Float(listOf(1.0F, 2.0F, 3.0F, 4.0F))
assert(array4Float[0] == 1.0F)
assert(array4Float[3] == 4.0F)

// [array-examples-end]

// [template-instance-examples-start]
val vecInt = VectorInt()
vecInt.pushBack(1)
assert(vecInt[0] == 1)
val vecIntCopy = VectorInt(vecInt)
assert(vecInt == vecIntCopy)
val vecIntSum = vecInt + vecIntCopy
assert(vecIntSum[0] == 2)

val vecString = StringsVector()
vecString.pushBack("a")
assert(vecString[0] == "a")
val vecStringCopy = StringsVector(vecString)
assert(vecString == vecStringCopy)
val vecStringSum = vecString + vecStringCopy
assert(vecStringSum[0] == "aa")

val vecDouble = Vector()
vecDouble.pushBack(1.0)
assert(vecDouble[0] == 1.0)
val vecDoubleCopy = Vector(vecDouble)
assert(vecDouble == vecDoubleCopy)
val vecDoubleSum = vecDouble + vecDoubleCopy
assert(vecDoubleSum[0] == 2.0)

// [template-instance-examples-end]

// [variadic-examples-start]
val elemsInt = ElementsInt.create(1, 2)
val holderInt = elemsInt.holder

assert(holderInt.size == 2)
assert(holderInt[0] == 1)
assert(holderInt[1] == 2)

val elemsString = ElementsString.create("a", "b", "c")
val holderString = elemsString.holder

assert(holderString.size == 3)
assert(holderString[0] == "a")
assert(holderString[2] == "c")

val elemsEmpty = ElementsEmpty.create()
assert(elemsEmpty.holder.size == 0)
// [variadic-examples-end]


// [tuple-examples-start]
val tupleDoubleInt = TupleDoubleInt(1, 2.0)
assert(tupleDoubleInt.tail == 1)
assert(tupleDoubleInt.rest.tail == 2.0)

val tupleThreeInt = TupleThreeInt(1, 2, 3)
assert(tupleThreeInt.tail == 1)
assert(tupleThreeInt.rest.tail == 2)
assert(tupleThreeInt.rest.rest.tail == 3)

val tupleTwoInt = TupleTwoInt(1, 2)
assert(tupleTwoInt.tail == 1)
assert(tupleTwoInt.rest.tail == 2)
// [tuple-examples-end]

// tuple other usage examples
val intsTuple = IntsTuple(1, 2, 3)
assert(intsTuple.tail == 1)
assert(intsTuple.rest.tail == 2)
assert(intsTuple.rest.rest.tail == 3)

val myTupleDouble = MyTupleDouble(1.0, 5.0)
assert(myTupleDouble.tail == 1.0)
assert(myTupleDouble.rest.tail == 5.0)

val myTupleInt = MyTupleInt(1, 2)
assert(myTupleInt.tail == 1)
assert(myTupleInt.rest.tail == 2)

assert(getTupleFirstElement(tupleDoubleInt) == 1)
assert(getTupleFirstElement(tupleTwoInt) == 1)

// check array as an arg and return value
assert(getFirstElement(arrayInt) == 1)
assert(getLastElement(arrayInt) == 2)
val arrayMultiplied = multiplyElements(arrayInt, 2)
assert(arrayMultiplied.data() == listOf(2, 4))

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
