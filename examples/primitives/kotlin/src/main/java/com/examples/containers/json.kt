/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 05/04/2022-08:43.
 * Please do not change it manually.
 */

package com.examples.containers

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class JsonExamples
internal constructor(obj: IEGenObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val iegenCxxTypeName: String = "iegen::example::JsonExamples"
    }
    
    protected var iegObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (iegObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return iegObj.id
        }
    
    constructor(): this(IEGenObject(construct_helper(), true)) {
    }
    
    fun setJson(j: String): Unit {
        val result = jSetjson(id, j)
        
        return result
    }

    fun getJson(): String {
        val result = jGetjson(id)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getSimpleJsonExample(): String {
        val result = jGetsimplejsonexample(id)
        
        return result
    }

    fun setJsonMatrix(jm: List<List<String>>): Unit {
        val kotlintojdkjm = ObjectArray(jm.size) { Any() }
        var index_jm = 0
        for (value_jm in jm) {
            val kotlintojdkvalue_jm = ObjectArray(value_jm.size) { Any() }
            var index_value_jm = 0
            for (value_value_jm in value_jm) {
                
                kotlintojdkvalue_jm[index_value_jm] = value_value_jm
                ++index_value_jm
            }
            kotlintojdkjm[index_jm] = kotlintojdkvalue_jm
            ++index_jm
        }
        val result = jSetjsonmatrix(id, kotlintojdkjm)
        
        return result
    }

    fun getJsonMatrix(): List<List<String>> {
        val result = jGetjsonmatrix(id)
        val jdktokotlinresult: MutableList<List<String>> = mutableListOf()
        for (value_result in result) {
            @Suppress("UNCHECKED_CAST") val actual_value_result = value_result as ObjectArray
            val jdktokotlinactual_value_result: MutableList<String> = mutableListOf()
            for (value_actual_value_result in actual_value_result) {
                @Suppress("UNCHECKED_CAST") val actual_value_actual_value_result = value_actual_value_result as String
                
                jdktokotlinactual_value_result.add(actual_value_actual_value_result)
            }
            jdktokotlinresult.add(jdktokotlinactual_value_result)
        }
        return jdktokotlinresult
    }

    override fun close() {
        if (iegObj.owner && iegObj.id != 0L) {
            jFinalize(iegObj.id)
            iegObj.id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jSetjson(id: Long, j: String): Unit
    private external fun jGetjson(id: Long): String
    private external fun jGetsimplejsonexample(id: Long): String
    private external fun jSetjsonmatrix(id: Long, jm: ObjectArray): Unit
    private external fun jGetjsonmatrix(id: Long): ObjectArray
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
