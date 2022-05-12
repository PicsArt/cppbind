/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:29.
 * Please do not change it manually.
 */

package com.examples.overloads

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

open class Employee
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(name: String): Long {
            val id = jConstructor(name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String): Long

        protected fun construct_helper(age: Int, email: String): Long {
            val id = jConstructor_1(age, email)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(age: Int, email: String): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Employee"
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
    
    constructor(name: String): this(CppBindObject(construct_helper(name), true)) {
    }

    constructor(age: Int, email: String = ""): this(CppBindObject(construct_helper(age, email), true)) {
    }
    
    val name: String
        get() {
            val result = jName(id)
            
            return result
        }

    val email: String
        get() {
            val result = jEmail(id)
            
            return result
        }

    val age: Int
        get() {
            val result = jAge(id)
            
            return result
        }
    
    fun setData(name: String, age: Int, email: String = ""): Unit {
        val result = jSetdata(id, name, age, email)
        
        return result
    }

    fun setData(age: Int): Unit {
        val result = jSetdata_1(id, age)
        
        return result
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
    private external fun jSetdata(id: Long, name: String, age: Int, email: String): Unit
    private external fun jSetdata_1(id: Long, age: Int): Unit
    private external fun jName(id: Long): String
    private external fun jEmail(id: Long): String
    private external fun jAge(id: Long): Int
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
