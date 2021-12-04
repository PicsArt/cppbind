/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

package com.examples.forward_decl.teacher

import com.examples.exception_helpers.*
import com.examples.forward_decl.student.Student
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*

open class Teacher
internal constructor(_id: Long) : AutoCloseable {
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
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(construct_helper()) {
    }
    
    fun addStudent(s: Student): Unit {
        val kotlin_to_jdk_s = s.id
        val result = jAddstudent(id, kotlin_to_jdk_s)
        
        return result
    }

    fun students(): List<Student> {
        val result = jStudents(id)
        val jdk_to_kotlin_result: MutableList<Student> = mutableListOf()
        for (value_result in result) {
            val jdk_to_kotlin_value_result = Student(value_result)
            jdk_to_kotlin_result.add(jdk_to_kotlin_value_result)
        }
        return jdk_to_kotlin_result
    }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jAddstudent(id: Long, s: Long): Unit
    private external fun jStudents(id: Long): LongArray
    private external fun jFinalize(id: Long): Unit
}