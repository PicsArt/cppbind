/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/29/2021-08:52.
 * Please do not change it manually.
 */

package com.examples.simple

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*

/**
 * Class holding project information.
 */
open class Project
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * Project constructor.
         */
        protected fun construct_helper(title: String): Long {
            val id = jConstructor(title)
            return id
        }

        @JvmStatic
        private external fun jConstructor(title: String): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    /**
     * Project constructor.
     */
    constructor(title: String): this(construct_helper(title)) {
        //jSet_this(id, this)
    }
    
    /**
     * Get project´s title.
     */
    val title: String
        get() {
            val result = jTitle(getObjId())
            
            return result
        }
    
    /**
     * Add a task to project.
     */
    fun addTask(task: Task): Unit {
        val kotlin_to_jdk_task = task.getObjId()
        val result = jAddtask(getObjId(), kotlin_to_jdk_task)
        
        return result
    }

    /**
     * Get project´s tasks.
     */
    fun tasks(): List<Task> {
        val result = jTasks(getObjId())
        val jdk_to_kotlin_result: MutableList<Task> = mutableListOf()
        for (value_result in result) {
            val jdk_to_kotlin_value_result = Task(value_result)
            jdk_to_kotlin_result.add(jdk_to_kotlin_value_result)
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
    private external fun jTitle(id: Long): String
    private external fun jAddtask(id: Long, task: Long): Unit
    private external fun jTasks(id: Long): LongArray
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}