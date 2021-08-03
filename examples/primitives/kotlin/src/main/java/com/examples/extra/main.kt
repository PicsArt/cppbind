package com.examples.extra

import com.examples.extra.*

class ExtraApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [object-usage]
            val objUsage = ObjectUsage()
            assert(objUsage.className() == "iegen::ObjectUsage")
            assert(objUsage.equals(objUsage) == true)
            assert(objUsage.bytesCount().toInt() == 8)
            assert(objUsage.toString().endsWith("iegen::ObjectUsage>"))
            // [object-usage]

       }
    }

}
