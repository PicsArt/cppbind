/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/25/2021-10:22.
 * Please do not change it manually.
 */

package com.examples.templates

import alias.*
import com.examples.exception_helpers.*
import com.examples.forward_decl.student.Student
import com.examples.overloads.Employee
import exceptionUtils.*

open class PairEmployee
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(first: String, second: Employee): Long {val kotlin_to_jdk_second = second.getObjId()
            val id = jConstructor(first, kotlin_to_jdk_second)
            return id
        }

        @JvmStatic
        private external fun jConstructor(first: String, second: Long): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id
    }
    
    constructor(first: String, second: Employee): this(construct_helper(first, second)) {
    }
    
    val first: String
        get() {
            val result = jFirst(getObjId())
            
            return result
        }

    val second: Employee
        get() {
            val result = jSecond(getObjId())
            val jdk_to_kotlin_result = Employee(result)
            return jdk_to_kotlin_result
        }

    override fun close() {
        if (id != 0L) {
            jFinalize(id)
            id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jFirst(id: Long): String
    private external fun jSecond(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}

open class PairStudent
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(first: String, second: Student): Long {val kotlin_to_jdk_second = second.getObjId()
            val id = jConstructor(first, kotlin_to_jdk_second)
            return id
        }

        @JvmStatic
        private external fun jConstructor(first: String, second: Long): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id
    }
    
    constructor(first: String, second: Student): this(construct_helper(first, second)) {
    }
    
    val first: String
        get() {
            val result = jFirst(getObjId())
            
            return result
        }

    val second: Student
        get() {
            val result = jSecond(getObjId())
            val jdk_to_kotlin_result = Student(result)
            return jdk_to_kotlin_result
        }

    override fun close() {
        if (id != 0L) {
            jFinalize(id)
            id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jFirst(id: Long): String
    private external fun jSecond(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}