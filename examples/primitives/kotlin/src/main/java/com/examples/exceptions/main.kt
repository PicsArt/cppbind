package com.examples.exceptions

import com.examples.exceptions.*
import com.examples.exception_helpers.*
import exceptionUtils.*


fun logger(errMsg: String) : Unit {
    println("Log uncaught exception with user defined logger: ${errMsg}")
}

fun genUncaughtExceptions() {
    ExceptionHandler.setUncaughtExceptionHandler({errMsg -> logger(errMsg)})
    Exc.noop()
    ExceptionHandler.unsetUncaughtExceptionHandler()
}

class ExceptionsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [exceptions-usage]

            try {
                Exc.getByKey(mapOf(1 to 1), 0)
            } catch (e: StdOutOfRange) {
                assert(e.what() == "map::at")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                val n = Exc.returnInteger(false)
                assert(n.value == 1)
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.returnInteger(true)
                assert(false)
            } catch (e: StdOutOfRange) {
                assert(e.what() == "error")
            } catch (e: Exception) {
                assert(false)
            }

            genUncaughtExceptions()

            try {
                Exc.raiseErrorByType("system")
            } catch (e: SystemError) {
                assert(e.what() == "system error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("file")
            } catch (e: FileError) {
                assert(e.what() == "file error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
               Exc.raiseErrorByType("file")
            } catch (e: SystemError) {
                assert(e.what() == "file error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("runtime")
            } catch (e: StdRuntimeError) {
                assert(e.what() == "runtime error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("runtime")
            } catch (e: StdException) {
                assert(e.what() == "runtime error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("simple_child")
            } catch (e: SimpleChildException) {
                assert(e.errNum() == 100)
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("simple_base")
            } catch (e: SimpleBaseException) {
                assert(e.errNum() == 200)
            } catch (e: Exception) {
                assert(false)
            }

            try {
                Exc.raiseErrorByType("")
            } catch (e: StdException) {
                assert(e.what() == "std::exception")
            } catch (e: Exception) {
                assert(false)
            }

            // [exceptions-usage]

       }
    }

}
