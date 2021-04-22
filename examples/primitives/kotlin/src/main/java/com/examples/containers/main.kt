package com.examples.containers

import com.examples.containers.*

class ContainersApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [map-usage]
            println("---------------------------------------")
            println("Containers!")
            val containers = MapUsages()
            val item1 = MapItem(5)
            containers.addStringMap(mapOf("a" to "1"))
            containers.addIntMap(mapOf(1 to 1))
            containers.addMixedMap(mapOf("a" to item1))
            val intMap = containers.getIntMap()
            assert(intMap[1] == 1)
            val strMap = containers.getStringMap()
            assert(strMap["a"] == "1")
            val mixedMap = containers.getMixedMap()
            assert(mixedMap["a"] == item1)
            // [map-usage]

       }

    }
}
