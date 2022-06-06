/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-05:25.
 * Please do not change it manually.
 */

package com.examples.containers

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * comments
 * 
 */
open class VectorItem
internal constructor(obj: CppBindObject) : AutoCloseable {
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
        private external fun jConstructor(_value: Int, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::VectorItem"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    /**
     * comments
     * 
     */
    constructor(_value: Int): this(CppBindObject(construct_helper(_value), true)) {
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
            
            jSetvalue(id, value, value)
        }
        

    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as VectorItem
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
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
    private external fun jSetvalue(id: Long, value: Int, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * comments
 * 
 */
open class VectorExamples
internal constructor(obj: CppBindObject) : AutoCloseable {
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
        const val cppbindCxxTypeName: String = "cppbind::example::VectorExamples"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    /**
     * comments
     * 
     */
    constructor(): this(CppBindObject(construct_helper(), true)) {
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
        val result = jAddintvector(id, kotlintojdkv, v)
        
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
        val result = jAddobjvector(id, kotlintojdkv, v)
        
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
        val result = jAddstringvector(id, kotlintojdkv, v)
        
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
            val jdktokotlinvalue_result = VectorItem(CppBindObject(value_result))
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

    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as VectorExamples
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jAddintvector(id: Long, v: IntArray, vararg extraObjs: Any?): Unit
    private external fun jAddobjvector(id: Long, v: LongArray, vararg extraObjs: Any?): Unit
    private external fun jAddstringvector(id: Long, v: ObjectArray, vararg extraObjs: Any?): Unit
    private external fun jGetstringvector(id: Long): ObjectArray
    private external fun jGetobjvector(id: Long): LongArray
    private external fun jGetintvector(id: Long): IntArray
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
