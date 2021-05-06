package com.examples.forward_decl

import alias.*


/**
 * comments
 * 
 */
open class Student
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
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
    
    constructor() : this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    fun addTeacher(t: Teacher): Unit {
        val kotlin_to_jdk_t = t.getObjId()
        val result = jAddteacher(getObjId(), kotlin_to_jdk_t)
        
        return result
    }

    fun teachers(): List<Teacher> {
        val result = jTeachers(getObjId())
        val jdk_to_kotlin_result: MutableList<Teacher> = mutableListOf()
        for (value in result) {
            val jdk_to_kotlin_value = Teacher(value)
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
    private external fun jAddteacher(id: Long, t: Long): Unit
    private external fun jTeachers(id: Long): LongArray
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}