/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/12/2022-06:48.
 * Please do not change it manually.
 */

package com.examples.overloads

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

/**
 * An example with overloaded methods.
 */
open class Utils
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
            val result = jSum1(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jSum1(first: Float, second: Float, vararg extraObjs: Any?): Float

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
            val result = jMinus1(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jMinus1(first: Float, second: Float, vararg extraObjs: Any?): Float
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Utils"
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
    
    /**
     * Concatenate with two strings.
     */
    fun concatenate(first: String, second: String): String {
        val result = jConcatenate(cppbindObjId, first, second)
        
        return result
    }

    /**
     * Concatenate with three strings.
     */
    fun concatenate(first: String, second: String, third: String): String {
        val result = jConcatenate1(cppbindObjId, first, second, third)
        
        return result
    }

    @JvmName("sum2")
    fun sum(first: List<Int>, second: List<Int>): List<Int> {
        val kotlintojdkfirst = IntArray(first.size) 
        var indexFirst = 0
        for (valueFirst in first) {
            
            kotlintojdkfirst[indexFirst] = valueFirst
            ++indexFirst
        }
        val kotlintojdksecond = IntArray(second.size) 
        var indexSecond = 0
        for (valueSecond in second) {
            
            kotlintojdksecond[indexSecond] = valueSecond
            ++indexSecond
        }
        val result = jSum2(cppbindObjId, kotlintojdkfirst, kotlintojdksecond, first, second)
        val jdktokotlinresult: MutableList<Int> = mutableListOf()
        for (valueResult in result) {
            
            jdktokotlinresult.add(valueResult)
        }
        return jdktokotlinresult
    }

    @JvmName("sum3")
    fun sum(first: List<Float>, second: List<Float>): List<Float> {
        val kotlintojdkfirst = FloatArray(first.size) 
        var indexFirst = 0
        for (valueFirst in first) {
            
            kotlintojdkfirst[indexFirst] = valueFirst
            ++indexFirst
        }
        val kotlintojdksecond = FloatArray(second.size) 
        var indexSecond = 0
        for (valueSecond in second) {
            
            kotlintojdksecond[indexSecond] = valueSecond
            ++indexSecond
        }
        val result = jSum3(cppbindObjId, kotlintojdkfirst, kotlintojdksecond, first, second)
        val jdktokotlinresult: MutableList<Float> = mutableListOf()
        for (valueResult in result) {
            
            jdktokotlinresult.add(valueResult)
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
        other as Utils
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
    private external fun jConcatenate(id: Long, first: String, second: String, vararg extraObjs: Any?): String
    private external fun jConcatenate1(id: Long, first: String, second: String, third: String, vararg extraObjs: Any?): String
    private external fun jSum2(id: Long, first: IntArray, second: IntArray, vararg extraObjs: Any?): IntArray
    private external fun jSum3(id: Long, first: FloatArray, second: FloatArray, vararg extraObjs: Any?): FloatArray
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
