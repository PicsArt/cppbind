package com.examples.exceptions

import com.examples.exceptions.*
import com.examples.exception_helpers.*
import com.examples.iegen.exceptionUtils.*


fun logger(errMsg: String) : Unit {
    println("Log uncaught exception with user defined logger: ${errMsg}")
}

fun genUncaughtExceptions() {
    ExceptionHandler.setUncaughtExceptionHandler({errMsg -> logger(errMsg)})
    NoThrowExc.noop()
    // check throwing constructor
    NoThrowExc(true);
    ExceptionHandler.unsetUncaughtExceptionHandler()
}

class ExceptionsApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [exceptions-usage]

            try {
                ThrowExc.getByKey(mapOf(1 to 1), 0)
            } catch (e: StdOutOfRange) {
                assert(e.what().contains("map::at"))
            } catch (e: Exception) {
                assert(false)
            }

            // assert everything is ok for returned pointer value when an exception is raised
            try {
              ThrowExc.throwsWithReturnValuePtr()
            } catch (e: StdInvalidArgument) {
                assert(e.what() == "return value error")
            } catch (e: Exception) {
              assert(false)
            }

            // assert everything is ok for returned string value when an exception is raised
            try {
                ThrowExc.throwsWithReturnValueString()
            } catch (e: StdInvalidArgument) {
                assert(e.what() == "return value error")
            } catch (e: Exception) {
                assert(false)
            }

            // checking throwing constructor
            try {
                ThrowExc(true)
                assert(false)
            } catch (e: StdInvalidArgument) {
                assert(e.what() == "inv_arg")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.returnInteger(true)
                assert(false)
            } catch (e: StdOutOfRange) {
                assert(e.what() == "error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("simple_child")
            } catch (e: SimpleChildException) {
                assert(e.errNum() == 100)
            } catch (e: Exception) {
                assert(false)
            }

            // [exceptions-usage]

            genUncaughtExceptions()

            // check non-throwing constructor
            NoThrowExc()

            try {
                MiscExc.raiseErrorByType("system")
            } catch (e: SystemError) {
                assert(e.what() == "system error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("file")
            } catch (e: FileError) {
                assert(e.what() == "file error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
               MiscExc.raiseErrorByType("file")
            } catch (e: SystemError) {
                assert(e.what() == "file error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("runtime")
            } catch (e: StdRuntimeError) {
                assert(e.what() == "runtime error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                val n = MiscExc.returnInteger(false)
                assert(n.value == 1)
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("runtime")
            } catch (e: StdException) {
                assert(e.what() == "runtime error")
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("simple_base")
            } catch (e: SimpleBaseException) {
                assert(e.errNum() == 200)
            } catch (e: Exception) {
                assert(false)
            }

            try {
                MiscExc.raiseErrorByType("")
            } catch (e: StdException) {
                assert(e.what() == "std::exception")
            } catch (e: Exception) {
                assert(false)
            }

            // checking properties
            val obj1 = NoThrowExc()
            assert(obj1.prop == "prop")
            obj1.prop = "new_prop"
            assert(obj1.prop == "new_prop")

            val obj2 = ThrowExc()
            try {
                obj2.prop
                assert(false)
            } catch (e: StdInvalidArgument) {
                assert(e.what() == "inv_arg")
            } catch(e: Exception) {
                assert(false)
            }

            try {
                obj2.prop = "new_prop"
                assert(false)
            } catch (e: StdOutOfRange) {
                assert(e.what() == "out_of_range")
            } catch(e: Exception) {
                assert(false)
            }
       }
    }

}
