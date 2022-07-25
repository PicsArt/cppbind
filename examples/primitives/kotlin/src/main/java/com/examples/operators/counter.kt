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

package com.examples.operators

import com.examples.cppbind.*
import com.examples.cppbind.exception_helpers.*

/**
 * An example for with overloaded methods.
 */
open class Counter
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * Counter constructor.
         */
        protected fun construct_helper(count: Int): Long {
            val id = jConstructor(count)
            return id
        }

        @JvmStatic
        private external fun jConstructor(count: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Counter"
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
     * Counter constructor.
     */
    constructor(count: Int): this(CppBindObject(construct_helper(count), true)) {
    }
    
    /**
     * Getter for count.
     */
    val count: Int
        get() {
            val result = jCount(cppbindObjId)
            
            return result
        }
    
    /**
     * Plus operator
     */
    operator fun plus(counter: Counter): Counter {
        val kotlintojdkcounter = counter.cppbindObjId
        val result = jPlus(cppbindObjId, kotlintojdkcounter, counter)
        val jdktokotlinresult = Counter(CppBindObject(result, true))
        return jdktokotlinresult
    }

    /**
     * Comparison operator for kotlin
     */
    operator fun compareTo(counter: Counter): Int {
        val kotlintojdkcounter = counter.cppbindObjId
        val result = jCompareto(cppbindObjId, kotlintojdkcounter, counter)
        
        return result
    }

    /**
     * Equality operator
     */
    override fun equals(other: Any?): Boolean {
        other as Counter
        return jEquals(cppbindObjId, other.cppbindObjId, other)
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
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
    private external fun jCount(id: Long): Int
    private external fun jPlus(id: Long, counter: Long, vararg extraObjs: Any?): Long
    private external fun jCompareto(id: Long, counter: Long, vararg extraObjs: Any?): Int
    private external fun jEquals(id: Long, counter: Long, vararg extraObjs: Any?): Boolean
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * A class example to the case when non-operator method is mapped to == operator
 */
open class PositiveCounter
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(count: Int): Long {
            val id = jConstructor(count)
            return id
        }

        @JvmStatic
        private external fun jConstructor(count: Int, vararg extraObjs: Any?): Long

        protected fun construct_helper(counts: List<Int>): Long {
            val kotlintojdkcounts = IntArray(counts.size) 
            var index_counts = 0
            for (value_counts in counts) {
                
                kotlintojdkcounts[index_counts] = value_counts
                ++index_counts
            }
            val id = jConstructor_1(kotlintojdkcounts, counts)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(counts: IntArray, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::PositiveCounter"
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
    
    constructor(count: Int): this(CppBindObject(construct_helper(count), true)) {
    }

    constructor(counts: List<Int>): this(CppBindObject(construct_helper(counts), true)) {
    }
    
    override fun equals(other: Any?): Boolean {
        other as PositiveCounter
        return jEquals(cppbindObjId, other.cppbindObjId, other)
    }

    operator fun get(i: Int): Int {
        val result = jGet(cppbindObjId, i)
        
        return result
    }


    operator fun set(i: Int, value: Int){
        jSet(cppbindObjId, i, value)
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
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
    private external fun jEquals(id: Long, other: Long, vararg extraObjs: Any?): Boolean
    private external fun jGet(id: Long, i: Int, vararg extraObjs: Any?): Int
    private external fun jSet(id: Long, i: Int, value: Int, vararg extraObjs: Any?)
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
