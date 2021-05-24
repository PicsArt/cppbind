package com.examples.containers

import com.examples.containers.*

class ContainersApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [map-usage]
            val mapusages = MapExamples()
            val item1 = MapItem(5)
            mapusages.addStringMap(mapOf("a" to "1"))
            mapusages.addIntMap(mapOf(1 to 1))
            mapusages.addMixedMap(mapOf("a" to item1))
            val intMap = mapusages.getIntMap()
            assert(intMap[1] == 1)
            val strMap = mapusages.getStringMap()
            assert(strMap["a"] == "1")
            val mixedMap = mapusages.getMixedMap()
            assert(mixedMap["a"]?.value == item1.value)
            // [map-usage]

            // [vector-usage]
            val vectorusages = VectorExamples()

            vectorusages.addIntVector(listOf(1, 2, 3))
            val intVec = vectorusages.getIntVector()
            assert(intVec.size == 3)
            assert(intVec[1] == 2)


            vectorusages.addStringVector(listOf("a", "b"))
            val strVec = vectorusages.getStringVector()
            assert(strVec.size == 2)
            assert(strVec[1] == "b")

            val item2 = VectorItem(5)
            val item3 = VectorItem(1)
            vectorusages.addObjVector(listOf(item2, item3))
            val objVec = vectorusages.getObjVector()
            assert(objVec.size == 2)
            assert(objVec[1].value == 1)
            // [vector-usage]

       }

    }
}