/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/22/2022-13:29.
 * Please do not change it manually.
 */

package com.examples.exceptions

import com.examples.cppbind.*
import com.examples.cppbind.exception_helpers.*

open class SimpleBaseException
internal constructor(obj: CppBindObject) : AutoCloseable, Exception() {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(err_num: Int): Long {
            val id = jConstructor(err_num)
            return id
        }

        @JvmStatic
        private external fun jConstructor(err_num: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::SimpleBaseException"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): SimpleBaseException {
            val idType = jGettypebyid(id)
            when (idType) {
                SimpleChildException.cppbindCxxTypeName -> return SimpleChildException(CppBindObject(id, owner))
                else -> return SimpleBaseException(CppBindObject(id, owner))
            }
        }
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
    
    constructor(err_num: Int): this(CppBindObject(construct_helper(err_num), true)) {
    }
    
    open fun errNum(): Int {
        val result = jErrnum(cppbindObjId)
        
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
        other as SimpleBaseException
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
    private external fun jErrnum(id: Long): Int
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class SimpleChildException
internal constructor(obj: CppBindObject) : SimpleBaseException(obj) {
    companion object {
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(err_num: Int): Long {
            val id = jConstructor(err_num)
            return id
        }

        @JvmStatic
        private external fun jConstructor(err_num: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::SimpleChildException"
    }
    
    
    /**
     * comments
     * 
     */
    constructor(err_num: Int): this(CppBindObject(construct_helper(err_num), true)) {
    }
    
    /**
     * comments
     * 
     */
    open override fun errNum(): Int {
        val result = jErrnum(cppbindObjId)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jErrnum(id: Long): Int
}

private external fun jGettypebyid(id: Long): String
