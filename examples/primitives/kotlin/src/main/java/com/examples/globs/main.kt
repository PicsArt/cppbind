package com.examples.globs

import com.examples.enums.*
import com.examples.globs.complex.*
import com.examples.globs.custom_args.*
import com.examples.globs.primitives.*
import com.examples.simple.*

fun use() {
// [simple-usage-example]
var mulInt = mul(5, 4)
assert(mulInt == 20)

var mulInt1 = mul(5, 4, 3)
assert(mulInt1 == 60)

var res = concat("Hello ", "Johnny")
assert(res == "Hello Johnny" )
// [simple-usage-example]

// [glob-func-examples]
res = concat("Hello ", "Johnny ", "Jane")
assert(res == "Hello Johnny Jane")

// [custom-arg-examples]
val greeting = greet("Johnny", "Florida")
assert(greeting == "Hello Johnny from Florida")
// [custom-arg-examples]

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
// [glob-func-examples]

// other test cases for global functions

var optProj = optionalFDPtr()
assert(optProj == null)
optProj = optionalFDPtr(prj1)
assert(optProj?.title == prj1.title)

// just calling function with no return value and arguments
doNothing()

// [non-complex-defaults-usage]
assert(optionalColor() == Color.Red)
assert(optionalColor(Color.Blue) == Color.Blue)
assert(optionalInt() == 5)
assert(optionalInt(1) == 1)
assert(optionalString() == "abc")
assert(optionalString("def") == "def")
// [non-complex-defaults-usage]

// complex default values tests
// [complex-defaults-usage]
assert(multipleMixedDefaultValues() == "DefaultTask1DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC")) == "ABC1DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC"), 2) == "ABC2DefaultRoot")
assert(multipleMixedDefaultValues(Task("ABC"), r=Root("Path") ) == "ABC1Path")
assert(multipleMixedDefaultValues(Task("ABC"), 2, Root("Path") ) == "ABC2Path")
// [complex-defaults-usage]

}

class GlobsApp {

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
