package com.examples.forward_decl

import alias.*



/**
 * comments
 * 
 */
open class Teacher
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        /**
         */
        protected fun construct_helper(): Long {
            
            val id = jConstructor()
            return id
        }
        @JvmStatic
        private external fun jConstructor(): Long


    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     */
    constructor() : this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    
    /**
     */
    fun addStudent(s: Student): Unit {
        
        val kotlin_to_jdk_s = s.getObjId()
        val result = jAddstudent(getObjId(), kotlin_to_jdk_s)
        
        return result
    }

    /**
     */
    fun students(): List<Student> {
        
        val result = jStudents(getObjId())
        val jdk_to_kotlin_result: MutableList<Student> = mutableListOf()
        for (value in result) {
            val jdk_to_kotlin_value = Student(value)
            jdk_to_kotlin_result.add(jdk_to_kotlin_value)
        }
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
    private external fun jAddstudent(id: Long, s: Long): Unit
    private external fun jStudents(id: Long): LongArray
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}