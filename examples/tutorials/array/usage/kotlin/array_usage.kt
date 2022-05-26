package array_usage

import array.*
import cppbind.exception_helpers.*


class ArrayUsageApp {

    companion object {

        init {
            System.loadLibrary("wrapper_jni")
        }

        @JvmStatic
        fun main(args: Array<String>) {

            val array = Array()

            assert(array.empty)

            array.push_back(0)
            array.push_back(1)
            array.push_back(2)

            assert(!array.empty)
            assert(array.size == 3)
            assert(array.front() == 0)
            assert(array.back() == 2)
            assert(array[1] == 1)

            try {
                array.at(5)
                assert(false)
            } catch (e: StdOutOfRange) {
            } catch (e: Exception) {
                assert(false)
            }

        }

    }
}
