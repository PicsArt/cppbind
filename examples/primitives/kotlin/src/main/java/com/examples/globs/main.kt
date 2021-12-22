package com.examples.globs

import com.examples.simple.*
import com.examples.enums.*

fun use() {
// [glob-func-examples]
var res = concat("Hello ", "Johnny")
assert(res == "Hello Johnny" )
res = concat("Hello ", "Johnny ", "Jane")
assert(res == "Hello Johnny Jane")


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
var color = optionalColor()
assert(color == Color.Red)
color = optionalColor(Color.Blue)
assert(color == Color.Blue)

var intVal = optionalInt()
assert(intVal == 5)
intVal = optionalInt(8)
assert(intVal == 8)

var optProj = optionalFDPtr()
assert(optProj == null)
optProj = optionalFDPtr(prj1)
assert(optProj?.title == prj1.title)

// just calling function with no return value and arguments
doNothing()


}

class GlobsApp {

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
