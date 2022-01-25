/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/25/2022-15:23.
 * Please do not change it manually.
 */

package com.examples.misc

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class WithExternalAPIComments
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(s: String): Long {
            val id = jConstructor(s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(s: String): Long

        fun retInt(n: Int): Int {
            val result = jRetint(n)
            
            return result
        }
        @JvmStatic
        private external fun jRetint(n: Int): Int

        fun max(arg0: Int, arg1: Int): Int {
            val result = jMaxInt(arg0, arg1)
            
            return result
        }
        @JvmStatic
        private external fun jMaxInt(arg0: Int, arg1: Int): Int

        fun max(arg0: String, arg1: String): String {
            val result = jMaxString(arg0, arg1)
            
            return result
        }
        @JvmStatic
        private external fun jMaxString(arg0: String, arg1: String): String
    }
    
    protected var objId = _id
    protected val owner = _owner
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(s: String): this(construct_helper(s), true) {
    }
    
    var str: String
        get() {
            val result = jStr(id)
            
            return result
        }
        set(value) {
            
            jSetstr(id, value)
        }

    override fun close() {
        if (owner && objId != 0L) {
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
    private external fun jStr(id: Long): String
    private external fun jSetstr(id: Long, value: String): Unit
    private external fun jFinalize(id: Long): Unit
}

open class AdderInt
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        fun add(a: Int, b: Int): Int {
            val result = jAdd(a, b)
            
            return result
        }
        @JvmStatic
        private external fun jAdd(a: Int, b: Int): Int
    }
    
    protected var objId = _id
    protected val owner = _owner
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }

    override fun close() {
        if (owner && objId != 0L) {
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

open class AdderDouble
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        fun add(a: Double, b: Double): Double {
            val result = jAdd(a, b)
            
            return result
        }
        @JvmStatic
        private external fun jAdd(a: Double, b: Double): Double
    }
    
    protected var objId = _id
    protected val owner = _owner
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }

    override fun close() {
        if (owner && objId != 0L) {
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

enum class color(val value: Int) {
    RED(0),
    GREEN(1),
    BLUE(2);

    companion object {
        private val values = values()
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }
}
