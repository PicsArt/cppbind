/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/24/2022-12:47.
 * Please do not change it manually.
 */

package com.examples.forward_decl.teacher

import com.examples.forward_decl.student.Student
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class Teacher
internal constructor(obj: IEGenObject) : AutoCloseable {
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
    
    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(IEGenObject(construct_helper(), true)) {
    }
    
    fun addStudent(s: Student): Unit {
        val kotlintojdks = s.id
        val result = jAddstudent(id, kotlintojdks)
        
        return result
    }

    fun students(): List<Student> {
        val result = jStudents(id)
        val jdktokotlinresult: MutableList<Student> = mutableListOf()
        for (value_result in result) {
            val jdktokotlinvalue_result = Student(IEGenObject(value_result, true))
            jdktokotlinresult.add(jdktokotlinvalue_result)
        }
        return jdktokotlinresult
    }

    override fun close() {
        if (owner && objId != 0L) {
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

private external fun jGettypebyid(id: Long): String
