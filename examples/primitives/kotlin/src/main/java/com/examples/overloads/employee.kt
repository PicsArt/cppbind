/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/18/2022-11:02.
 * Please do not change it manually.
 */

package com.examples.overloads

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

open class Employee
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(name: String): Long {
            val id = jConstructor(name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String, vararg extraObjs: Any?): Long

        protected fun constructHelper(age: Int, email: String): Long {
            val id = jConstructor1(age, email)
            return id
        }

        @JvmStatic
        private external fun jConstructor1(age: Int, email: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Employee"
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
    
    constructor(name: String): this(CppBindObject(constructHelper(name), true)) {
    }

    constructor(age: Int, email: String = ""): this(CppBindObject(constructHelper(age, email), true)) {
    }
    
    val name: String
        get() {
            val result = jName(cppbindObjId)
            
            return result
        }

    val email: String
        get() {
            val result = jEmail(cppbindObjId)
            
            return result
        }

    val age: Int
        get() {
            val result = jAge(cppbindObjId)
            
            return result
        }
    
    fun setData(name: String, age: Int, email: String = ""): Unit {
        val result = jSetdata(cppbindObjId, name, age, email)
        
        return result
    }

    fun setData(age: Int): Unit {
        val result = jSetdata1(cppbindObjId, age)
        
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
        other as Employee
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
    private external fun jSetdata(id: Long, name: String, age: Int, email: String, vararg extraObjs: Any?): Unit
    private external fun jSetdata1(id: Long, age: Int, vararg extraObjs: Any?): Unit
    private external fun jName(id: Long): String
    private external fun jEmail(id: Long): String
    private external fun jAge(id: Long): Int
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
