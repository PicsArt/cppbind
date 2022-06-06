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

package com.examples.templates

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * This is a template class example.
 * For templates user must explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */
open class WrapperPairStrings
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: Pair<String, String>): Long {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<String, String>(first_value, second_value)
            val id = jConstructor(kotlintojdkvalue, value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: Pair<String, String>, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Wrapper<std::pair<std::string, std::string>>"
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
    
    constructor(value: Pair<String, String>): this(CppBindObject(construct_helper(value), true)) {
    }
    
    var value: Pair<String, String>
        get() {
            val result = jValue(id)
            val first_result = result.first
            val second_result = result.second


            val jdktokotlinresult = Pair<String, String>(first_result, second_result)
            return jdktokotlinresult
        }
        set(value) {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<String, String>(first_value, second_value)
            jSetvalue(id, kotlintojdkvalue, value)
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
        other as WrapperPairStrings
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
    private external fun jValue(id: Long): Pair<String, String>
    private external fun jSetvalue(id: Long, value: Pair<String, String>, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * This is a template class example.
 * For templates user must explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */
open class WrapperPairIntInt
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: Pair<Int, Int>): Long {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<Int, Int>(first_value, second_value)
            val id = jConstructor(kotlintojdkvalue, value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: Pair<Int, Int>, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Wrapper<std::pair<int, int>>"
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
    
    constructor(value: Pair<Int, Int>): this(CppBindObject(construct_helper(value), true)) {
    }
    
    var value: Pair<Int, Int>
        get() {
            val result = jValue(id)
            val first_result = result.first
            val second_result = result.second


            val jdktokotlinresult = Pair<Int, Int>(first_result, second_result)
            return jdktokotlinresult
        }
        set(value) {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<Int, Int>(first_value, second_value)
            jSetvalue(id, kotlintojdkvalue, value)
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
        other as WrapperPairIntInt
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
    private external fun jValue(id: Long): Pair<Int, Int>
    private external fun jSetvalue(id: Long, value: Pair<Int, Int>, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * This is a template class example.
 * For templates user must explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */
open class WrapperString
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: String): Long {
            val id = jConstructor(value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Wrapper<std::string>"
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
    
    constructor(value: String): this(CppBindObject(construct_helper(value), true)) {
    }
    
    var value: String
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
        other as WrapperString
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
    private external fun jValue(id: Long): String
    private external fun jSetvalue(id: Long, value: String, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
