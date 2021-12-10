package com.examples.globs

import com.examples.simple.*

fun use() {
// [glob-func-examples]
val res = concat("Hello ", "Johnny")
assert(res == "Hello Johnny" )

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

}

class GlobsApp {

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
