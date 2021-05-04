package com.examples.templates

import alias.*
import com.examples.simple.*


/**
 * comments
 * 
 */
open class TemplateFunctions
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * comments
         * 
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
     * comments
     * 
     */
    constructor() : this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    open fun max(arg0: Int, arg1: Int): Int {
        val result = jMaxInt(getObjId(), arg0, arg1)
        
        return result
    }

    /**
     * comments
     * 
     */
    open fun max(arg0: String, arg1: String): String {
        val result = jMaxString(getObjId(), arg0, arg1)
        
        return result
    }

    /**
     * comments
     * 
     */
    open fun makePair(arg0: Project, arg1: Project): Pair<Project, Project> {
        val kotlin_to_jdk_arg0 = arg0.getObjId()
        val kotlin_to_jdk_arg1 = arg1.getObjId()
        val result = jMakepairProjectProject(getObjId(), kotlin_to_jdk_arg0, kotlin_to_jdk_arg1)
        val first  = result.first
        val second  = result.second
        val jdk_to_kotlin_first = Project(first)
        val jdk_to_kotlin_second = Project(second)
        val jdk_to_kotlin_result = Pair<Project, Project>(jdk_to_kotlin_first, jdk_to_kotlin_second)
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    open fun makePair(arg0: Task, arg1: Project): Pair<Task, Project> {
        val kotlin_to_jdk_arg0 = arg0.getObjId()
        val kotlin_to_jdk_arg1 = arg1.getObjId()
        val result = jMakepairTaskProject(getObjId(), kotlin_to_jdk_arg0, kotlin_to_jdk_arg1)
        val first  = result.first
        val second  = result.second
        val jdk_to_kotlin_first = Task(first)
        val jdk_to_kotlin_second = Project(second)
        val jdk_to_kotlin_result = Pair<Task, Project>(jdk_to_kotlin_first, jdk_to_kotlin_second)
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
    private external fun jMaxInt(id: Long, arg0: Int, arg1: Int): Int
    private external fun jMaxString(id: Long, arg0: String, arg1: String): String
    private external fun jMakepairProjectProject(id: Long, arg0: Long, arg1: Long): Pair<Long, Long>
    private external fun jMakepairTaskProject(id: Long, arg0: Long, arg1: Long): Pair<Long, Long>
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}