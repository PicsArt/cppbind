package com.examples.globs

import com.examples.enums.*
import com.examples.globs.complex.*
import com.examples.globs.custom_args.*
import com.examples.globs.primitives.*
import com.examples.simple.*

fun use() {
// [simple-usage-example-start]
var mulInt = mul(5, 4)
assert(mulInt == 20)

var mulInt1 = mul(5, 4, 3)
assert(mulInt1 == 60)

var res = concat("Hello ", "Johnny")
assert(res == "Hello Johnny" )
// [simple-usage-example-end]

// [glob-func-examples-start]
res = concat("Hello ", "Johnny ", "Jane")
assert(res == "Hello Johnny Jane")

// [custom-arg-examples-start]
val greeting = greet("Johnny", "Florida")
assert(greeting == "Hello Johnny from Florida")
// [custom-arg-examples-end]

val maxInt = max(2, 5)
assert(maxInt == 5)
val maxString = max("d", "a")
assert(maxString == "d")

val prj1 = Project("My first project")
val prj2 = Project("My second project")
val pairPrjPrj = makePair(prj1, prj2)
assert(pairPrjPrj.first.title == prj1.title)
assert(pairPrjPrj.second.title == prj2.title)

val root1 = Root("/path/to/root/")
val pairRootPrj = makePair(root1, prj1)
assert(pairRootPrj.first.path == root1.path)
assert(pairRootPrj.second.title == prj1.title)
// [glob-func-examples-end]

// other test cases for global functions

var optProj = optionalFDPtr()
assert(optProj == null)
optProj = optionalFDPtr(prj1)
assert(optProj?.title == prj1.title)

// just calling function with no return value and arguments
doNothing()

// [non-complex-defaults-usage-start]
assert(optionalColor() == Color.Red)
assert(optionalColor(Color.Blue) == Color.Blue)
assert(optionalInt() == 5)
assert(optionalInt(1) == 1)
assert(optionalString() == "abc")
assert(optionalString("def") == "def")
// [non-complex-defaults-usage-end]

// complex default values tests
// [complex-defaults-usage-start]
assert(multipleMixedDefaultValues() == "DefaultTask1DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC")) == "ABC1DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC"), 2) == "ABC2DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC"), r=Root("Path") ) == "ABC1Path")
assert(multipleMixedDefaultValues(Task("ABC"), 2, Root("Path") ) == "ABC2Path")
// [complex-defaults-usage-end]

val merged1 = merge(listOf(1, 2), listOf(3, 4))
assert(merged1 == listOf(1, 2, 3, 4))

val merged2 = merge(listOf("first", "second"), listOf("third"))
assert(merged2 == listOf("first", "second", "third"))

val sum1 = sum(listOf(1, 2, 0, 0), listOf(3, 4, 0, 0))
assert(sum1 == listOf(4, 6, 0, 0))

val sum2 = sum(listOf(5F, 6F, 0F, 0F), listOf(7F, 8F, 0F, 0F))
assert(sum2 == listOf(12F, 14F, 0F, 0F))

var getVecColor = getVectorColor(listOf(Color.Red))
assert(getVecColor[0] == Color.Red)

}

class GlobsApp {

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
