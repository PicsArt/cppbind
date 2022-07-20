package com.examples.basic_types

fun use() {

// testing 'short'
assert(add(10, 20).compareTo(30) == 0)

val arr : List<Short> = listOf(10, 20, 30)
val resultList : List<Short> = listOf(20, 30, 40)
assert(add(arr, 10) == resultList)

val p1 : Pair<Short, Short> = Pair(1, 2)
val p2 : Pair<Short, Short> = Pair(-1, -2)
val resultPair : Pair<Short, Short> = Pair(0, 0)
assert(add(p1, p2) == resultPair)

}

class BasicTypesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }

}
