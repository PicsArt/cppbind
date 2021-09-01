/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/01/2021-10:40.
 * Please do not change it manually.
 */

package com.examples.getters

import alias.*
import com.examples.exception_helpers.*
import exceptionUtils.*

open class NumberInt
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
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(n: Int): this(construct_helper(n)) {
    }
    
    var num: Int
        get() {
            val result = jNum(getObjId())
            
            return result
        }
        set(value) {
            
            jSetnum(getObjId(), value)
        }
        
    
    fun toInt(): Int {
        val result = jToint(getObjId())
        
        return result
    }

    override fun close() {
        if (id != 0L) {
            jFinalize(id)
            id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jToint(id: Long): Int
    private external fun jNum(id: Long): Int
    private external fun jSetnum(id: Long, value: Int): Unit
    private external fun jFinalize(id: Long): Unit
}

open class NumberDouble
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(n: Double): Long {
            val id = jConstructor(n)
            return id
        }

        @JvmStatic
        private external fun jConstructor(n: Double): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(n: Double): this(construct_helper(n)) {
    }
    
    var num: Double
        get() {
            val result = jNum(getObjId())
            
            return result
        }
        set(value) {
            
            jSetnum(getObjId(), value)
        }
        
    
    fun toInt(): Int {
        val result = jToint(getObjId())
        
        return result
    }

    override fun close() {
        if (id != 0L) {
            jFinalize(id)
            id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jToint(id: Long): Int
    private external fun jNum(id: Long): Double
    private external fun jSetnum(id: Long, value: Double): Unit
    private external fun jFinalize(id: Long): Unit
}