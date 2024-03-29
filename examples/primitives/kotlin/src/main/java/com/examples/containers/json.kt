/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/18/2022-11:01.
 * Please do not change it manually.
 */

package com.examples.containers

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

open class JsonExamples
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::JsonExamples"
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
    
    constructor(): this(CppBindObject(constructHelper(), true)) {
    }
    
    fun setJson(j: String): Unit {
        val result = jSetjson(cppbindObjId, j)
        
        return result
    }

    fun getJson(): String {
        val result = jGetjson(cppbindObjId)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun getSimpleJsonExample(): String {
        val result = jGetsimplejsonexample(cppbindObjId)
        
        return result
    }

    fun setJsonMatrix(jm: List<List<String>>): Unit {
        val kotlintojdkjm = ObjectArray(jm.size) { Any() }
        var indexJm = 0
        for (valueJm in jm) {
            val kotlintojdkvalueJm = ObjectArray(valueJm.size) { Any() }
            var indexValuejm = 0
            for (valueValuejm in valueJm) {
                
                kotlintojdkvalueJm[indexValuejm] = valueValuejm
                ++indexValuejm
            }
            kotlintojdkjm[indexJm] = kotlintojdkvalueJm
            ++indexJm
        }
        val result = jSetjsonmatrix(cppbindObjId, kotlintojdkjm, jm)
        
        return result
    }

    fun getJsonMatrix(): List<List<String>> {
        val result = jGetjsonmatrix(cppbindObjId)
        val jdktokotlinresult: MutableList<List<String>> = mutableListOf()
        for (valueResult in result) {
            @Suppress("UNCHECKED_CAST") val actualValueresult = valueResult as ObjectArray
            val jdktokotlinactualValueresult: MutableList<String> = mutableListOf()
            for (valueActualvalueresult in actualValueresult) {
                @Suppress("UNCHECKED_CAST") val actualValueactualvalueresult = valueActualvalueresult as String
                
                jdktokotlinactualValueresult.add(actualValueactualvalueresult)
            }
            jdktokotlinresult.add(jdktokotlinactualValueresult)
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
        other as JsonExamples
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jSetjson(id: Long, j: String, vararg extraObjs: Any?): Unit
    private external fun jGetjson(id: Long): String
    private external fun jGetsimplejsonexample(id: Long): String
    private external fun jSetjsonmatrix(id: Long, jm: ObjectArray, vararg extraObjs: Any?): Unit
    private external fun jGetjsonmatrix(id: Long): ObjectArray
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
