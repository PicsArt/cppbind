/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:28.
 * Please do not change it manually.
 */

package com.examples.containers

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

/**
 * comments
 * 
 */
open class MapItem
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
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
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
open class MapExamples
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
    fun addStringPair(info: Pair<String, String>): Unit {
        val first_info = info.first
        val second_info = info.second


        val kotlintojdkinfo = Pair<String, String>(first_info, second_info)
        val result = jAddstringpair(id, kotlintojdkinfo)
        
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
        val result = jAddintmap(id, kotlintojdkinfo)
        
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
        val result = jAddstringmap(id, kotlintojdkinfo)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getStringMap(): Map<String, String> {
        val result = jGetstringmap(id)
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
        val result = jGetintmap(id)
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
            
            val kotlintojdkvalue_info = value_info.id
            tmp_key_kotlintojdkinfo[index_info] = key_info
            tmp_val_kotlintojdkinfo[index_info] = kotlintojdkvalue_info
            ++index_info
        }
        val result = jAddmixedmap(id, kotlintojdkinfo)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getMixedMap(): Map<String, MapItem> {
        val result = jGetmixedmap(id)
        val jdktokotlinresult = HashMap<String, MapItem>()
        for (i_result in 0..result.first.size - 1) {
            @Suppress("UNCHECKED_CAST") val elem1_result = result.first.get(i_result) as String
            val elem2_result = result.second.get(i_result)
            
            val jdktokotlinelem2_result = MapItem(elem2_result)
            jdktokotlinresult.put(elem1_result, jdktokotlinelem2_result)
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
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
    }

    ///// External wrapper functions ////////////
    private external fun jAddstringpair(id: Long, info: Pair<String, String>): Unit
    private external fun jAddintmap(id: Long, info: Pair<IntArray, IntArray>): Unit
    private external fun jAddstringmap(id: Long, info: Pair<ObjectArray, ObjectArray>): Unit
    private external fun jGetstringmap(id: Long): Pair<ObjectArray, ObjectArray>
    private external fun jGetintmap(id: Long): Pair<IntArray, IntArray>
    private external fun jAddmixedmap(id: Long, info: Pair<ObjectArray, LongArray>): Unit
    private external fun jGetmixedmap(id: Long): Pair<ObjectArray, LongArray>
    private external fun jFinalize(id: Long): Unit
}
