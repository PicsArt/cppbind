/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-15:10.
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
open class MapItem
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
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::MapItem"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val cppbindObjId: Long
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
            val result = jValue(cppbindObjId)
            
            return result
        }
        set(value) {
            
            jSetvalue(cppbindObjId, value, value)
        }
        

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as MapItem
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
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
open class MapExamples
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
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::MapExamples"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val cppbindObjId: Long
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
    fun addStringPair(info: Pair<String, String>): Unit {
        val first_info = info.first
        val second_info = info.second


        val kotlintojdkinfo = Pair<String, String>(first_info, second_info)
        val result = jAddstringpair(cppbindObjId, kotlintojdkinfo, info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addDoublePair(info: Pair<Double, Double>): Unit {
        val first_info = info.first
        val second_info = info.second


        val kotlintojdkinfo = Pair<Double, Double>(first_info, second_info)
        val result = jAdddoublepair(cppbindObjId, kotlintojdkinfo, info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addIntMap(info: Map<Int, Int>): Unit {
        
        val tmp_key_kotlintojdkinfo = IntArray(info.size) 
        val tmp_val_kotlintojdkinfo = IntArray(info.size) 
        val kotlintojdkinfo = Pair<IntArray, IntArray>(tmp_key_kotlintojdkinfo, tmp_val_kotlintojdkinfo)
        var index_info = 0
        for ((key_info, value_info) in info) {
            
            
            tmp_key_kotlintojdkinfo[index_info] = key_info
            tmp_val_kotlintojdkinfo[index_info] = value_info
            ++index_info
        }
        val result = jAddintmap(cppbindObjId, kotlintojdkinfo, info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun addStringMap(info: Map<String, String>): Unit {
        
        val tmp_key_kotlintojdkinfo = ObjectArray(info.size) { Any() }
        val tmp_val_kotlintojdkinfo = ObjectArray(info.size) { Any() }
        val kotlintojdkinfo = Pair<ObjectArray, ObjectArray>(tmp_key_kotlintojdkinfo, tmp_val_kotlintojdkinfo)
        var index_info = 0
        for ((key_info, value_info) in info) {
            
            
            tmp_key_kotlintojdkinfo[index_info] = key_info
            tmp_val_kotlintojdkinfo[index_info] = value_info
            ++index_info
        }
        val result = jAddstringmap(cppbindObjId, kotlintojdkinfo, info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getStringMap(): Map<String, String> {
        val result = jGetstringmap(cppbindObjId)
        val jdktokotlinresult = HashMap<String, String>()
        for (i_result in 0..result.first.size - 1) {
            @Suppress("UNCHECKED_CAST") val elem1_result = result.first.get(i_result) as String
            @Suppress("UNCHECKED_CAST") val elem2_result = result.second.get(i_result) as String
            
            
            jdktokotlinresult.put(elem1_result, elem2_result)
        }
        return jdktokotlinresult
    }

    /**
     * comments
     * 
     */
    fun getIntMap(): Map<Int, Int> {
        val result = jGetintmap(cppbindObjId)
        val jdktokotlinresult = HashMap<Int, Int>()
        for (i_result in 0..result.first.size - 1) {
            val elem1_result = result.first.get(i_result)
            val elem2_result = result.second.get(i_result)
            
            
            jdktokotlinresult.put(elem1_result, elem2_result)
        }
        return jdktokotlinresult
    }

    /**
     * comments
     * 
     */
    fun addMixedMap(info: Map<String, MapItem>): Unit {
        
        val tmp_key_kotlintojdkinfo = ObjectArray(info.size) { Any() }
        val tmp_val_kotlintojdkinfo = LongArray(info.size) 
        val kotlintojdkinfo = Pair<ObjectArray, LongArray>(tmp_key_kotlintojdkinfo, tmp_val_kotlintojdkinfo)
        var index_info = 0
        for ((key_info, value_info) in info) {
            
            val kotlintojdkvalue_info = value_info.cppbindObjId
            tmp_key_kotlintojdkinfo[index_info] = key_info
            tmp_val_kotlintojdkinfo[index_info] = kotlintojdkvalue_info
            ++index_info
        }
        val result = jAddmixedmap(cppbindObjId, kotlintojdkinfo, info)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getMixedMap(): Map<String, MapItem> {
        val result = jGetmixedmap(cppbindObjId)
        val jdktokotlinresult = HashMap<String, MapItem>()
        for (i_result in 0..result.first.size - 1) {
            @Suppress("UNCHECKED_CAST") val elem1_result = result.first.get(i_result) as String
            val elem2_result = result.second.get(i_result)
            
            val jdktokotlinelem2_result = MapItem(CppBindObject(elem2_result, true))
            jdktokotlinresult.put(elem1_result, jdktokotlinelem2_result)
        }
        return jdktokotlinresult
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as MapExamples
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
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
    private external fun jAddstringpair(id: Long, info: Pair<String, String>, vararg extraObjs: Any?): Unit
    private external fun jAdddoublepair(id: Long, info: Pair<Double, Double>, vararg extraObjs: Any?): Unit
    private external fun jAddintmap(id: Long, info: Pair<IntArray, IntArray>, vararg extraObjs: Any?): Unit
    private external fun jAddstringmap(id: Long, info: Pair<ObjectArray, ObjectArray>, vararg extraObjs: Any?): Unit
    private external fun jGetstringmap(id: Long): Pair<ObjectArray, ObjectArray>
    private external fun jGetintmap(id: Long): Pair<IntArray, IntArray>
    private external fun jAddmixedmap(id: Long, info: Pair<ObjectArray, LongArray>, vararg extraObjs: Any?): Unit
    private external fun jGetmixedmap(id: Long): Pair<ObjectArray, LongArray>
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
