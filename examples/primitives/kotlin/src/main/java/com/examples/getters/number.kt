/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/22/2022-09:26.
 * Please do not change it manually.
 */

package com.examples.getters

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class NumberInt
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(n: Int): Long {
            val id = jConstructor(n)
            return id
        }

        @JvmStatic
        private external fun jConstructor(n: Int): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(n: Int): this(construct_helper(n), true) {
    }
    
    var num: Int
        get() {
            val result = jNum(id)
            
            return result
        }
        set(value) {
            
            jSetnum(id, value)
        }
        
    
    fun toInt(): Int {
        val result = jToint(id)
        
        return result
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
    private external fun jToint(id: Long): Int
    private external fun jNum(id: Long): Int
    private external fun jSetnum(id: Long, value: Int): Unit
    private external fun jFinalize(id: Long): Unit
}

open class NumberDouble
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(n: Double): Long {
            val id = jConstructor(n)
            return id
        }

        @JvmStatic
        private external fun jConstructor(n: Double): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(n: Double): this(construct_helper(n), true) {
    }
    
    var num: Double
        get() {
            val result = jNum(id)
            
            return result
        }
        set(value) {
            
            jSetnum(id, value)
        }
        
    
    fun toInt(): Int {
        val result = jToint(id)
        
        return result
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
    private external fun jToint(id: Long): Int
    private external fun jNum(id: Long): Double
    private external fun jSetnum(id: Long, value: Double): Unit
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
