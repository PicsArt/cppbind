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

package com.examples.overloads

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * An example with overloaded methods.
 */
open class Utils
internal constructor(obj: CppBindObject) : AutoCloseable {
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

        /**
         * Sum two ints.
         */
        fun sum(first: Int, second: Int): Int {
            val result = jSum(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jSum(first: Int, second: Int, vararg extraObjs: Any?): Int

        /**
         * Sum two floats.
         */
        fun sum(first: Float, second: Float): Float {
            val result = jSum_1(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jSum_1(first: Float, second: Float, vararg extraObjs: Any?): Float

        /**
         * Sub two ints.
         */
        fun minus(first: Int, second: Int): Int {
            val result = jMinus(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jMinus(first: Int, second: Int, vararg extraObjs: Any?): Int

        /**
         * Sub two floats.
         */
        fun minus(first: Float, second: Float): Float {
            val result = jMinus_1(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jMinus_1(first: Float, second: Float, vararg extraObjs: Any?): Float
        const val cppbindCxxTypeName: String = "cppbind::example::Utils"
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    /**
     * Concatenate with two strings.
     */
    fun concatenate(first: String, second: String): String {
        val result = jConcatenate(id, first, second)
        
        return result
    }

    /**
     * Concatenate with three strings.
     */
    fun concatenate(first: String, second: String, third: String): String {
        val result = jConcatenate_1(id, first, second, third)
        
        return result
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
        other as Utils
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
    private external fun jConcatenate(id: Long, first: String, second: String, vararg extraObjs: Any?): String
    private external fun jConcatenate_1(id: Long, first: String, second: String, third: String, vararg extraObjs: Any?): String
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
