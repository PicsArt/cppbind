/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/26/2021-07:50.
 * Please do not change it manually.
 */

package com.examples.exceptions

import alias.*
import com.examples.exception_helpers.*
import exceptionUtils.*

open class Integer
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(n: Int): Long {
            val id = jConstructor(n)
            return id
        }

        @JvmStatic
        private external fun jConstructor(n: Int): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId;
        }
    
    constructor(n: Int): this(construct_helper(n)) {
    }
    
    /**
     * value getter
     */
    val value: Int
        get() {
            val result = jValue(id)
            
            return result
        }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): Int
    private external fun jFinalize(id: Long): Unit
}

open class MiscExc
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        fun returnInteger(do_throw: Boolean): Integer {
            val result = jReturninteger(do_throw)
            val jdk_to_kotlin_result = Integer(result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jReturninteger(do_throw: Boolean): Long

        fun raiseErrorByType(err_type: String): Unit {
            val result = jRaiseerrorbytype(err_type)
            
            return result
        }
        @JvmStatic
        private external fun jRaiseerrorbytype(err_type: String): Unit
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId;
        }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }
    private external fun jFinalize(id: Long): Unit
}