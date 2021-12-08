/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-17:14.
 * Please do not change it manually.
 */

package com.examples.containers

import com.examples.exception_helpers.*
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*

/**
 * comments
 * 
 */
open class VectorItem
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(_value: Int): Long {
            val id = jConstructor(_value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(_value: Int): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    /**
     * comments
     * 
     */
    constructor(_value: Int): this(construct_helper(_value)) {
    }
    
    /**
     * comments
     * 
     */
    var value: Int
        get() {
            val result = jValue(id)
            
            return result
        }
        set(value) {
            
            jSetvalue(id, value)
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
    private external fun jSetvalue(id: Long, value: Int): Unit
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class VectorExamples
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    /**
     * comments
     * 
     */
    constructor(): this(construct_helper()) {
    }
    
    /**
     * comments
     * 
     */
    fun addIntVector(v: List<Int>): Unit {
        
        val kotlintojdkv = IntArray(v.size) 
        var index_v = 0
        for (value_v in v) {
            
            kotlintojdkv[index_v] = value_v
            ++index_v
        }
        val result = jAddintvector(id, kotlintojdkv)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addObjVector(v: List<VectorItem>): Unit {
        
        val kotlintojdkv = LongArray(v.size) 
        var index_v = 0
        for (value_v in v) {
            val kotlintojdkvalue_v = value_v.id
            kotlintojdkv[index_v] = kotlintojdkvalue_v
            ++index_v
        }
        val result = jAddobjvector(id, kotlintojdkv)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addStringVector(v: List<String>): Unit {
        
        val kotlintojdkv = ObjectArray(v.size) { Any() }
        var index_v = 0
        for (value_v in v) {
            
            kotlintojdkv[index_v] = value_v
            ++index_v
        }
        val result = jAddstringvector(id, kotlintojdkv)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getStringVector(): List<String> {
        val result = jGetstringvector(id)
        val jdktokotlinresult: MutableList<String> = mutableListOf()
        for (value_result in result) {
            @Suppress("UNCHECKED_CAST") val actual_value_result = value_result as String
            
            jdktokotlinresult.add(actual_value_result)
        }
        return jdktokotlinresult
    }

    /**
     * comments
     * 
     */
    fun getObjVector(): List<VectorItem> {
        val result = jGetobjvector(id)
        val jdktokotlinresult: MutableList<VectorItem> = mutableListOf()
        for (value_result in result) {
            val jdktokotlinvalue_result = VectorItem(value_result)
            jdktokotlinresult.add(jdktokotlinvalue_result)
        }
        return jdktokotlinresult
    }

    /**
     * comments
     * 
     */
    fun getIntVector(): List<Int> {
        val result = jGetintvector(id)
        val jdktokotlinresult: MutableList<Int> = mutableListOf()
        for (value_result in result) {
            
            jdktokotlinresult.add(value_result)
        }
        return jdktokotlinresult
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
    private external fun jAddintvector(id: Long, v: IntArray): Unit
    private external fun jAddobjvector(id: Long, v: LongArray): Unit
    private external fun jAddstringvector(id: Long, v: ObjectArray): Unit
    private external fun jGetstringvector(id: Long): ObjectArray
    private external fun jGetobjvector(id: Long): LongArray
    private external fun jGetintvector(id: Long): IntArray
    private external fun jFinalize(id: Long): Unit
}