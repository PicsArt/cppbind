/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 11/22/2022-06:34.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

open class Date
internal constructor(obj: CppBindObject) : IBase, AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(d: Int, m: Int, y: Int): Long {
            val id = jConstructor(d, m, y)
            return id
        }

        @JvmStatic
        private external fun jConstructor(d: Int, m: Int, y: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Date"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): Date {
            val idType = jGettypebyid(id)
            val obj : Date
            when (idType) {
                DateTime.cppbindCxxTypeName -> obj = DateTime(CppBindObject(id, owner))
                else -> obj = Date(CppBindObject(id, owner))
            }
            return obj
        }
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    override val cppbindObjId: Long
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
    
    constructor(d: Int, m: Int, y: Int): this(CppBindObject(constructHelper(d, m, y), true)) {
    }
    
    val date: String
        get() {
            val result = jDate(cppbindObjId)
            
            return result
        }
    
    open fun value(): String {
        val result = jValue(cppbindObjId)
        
        return result
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
        other as Date
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
    private external fun jValue(id: Long): String
    private external fun jDate(id: Long): String
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
