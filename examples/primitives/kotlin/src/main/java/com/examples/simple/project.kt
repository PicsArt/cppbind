/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/23/2021-09:57.
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
            val err = ErrorObj()
            val result = jTitle(getObjId(), err)
            if (err.typeId != 0) {
                when (err.typeId) {
                    1 -> {
                        val excObj = StdException(err.ptrId)
                        ExceptionHandler.handleUncaughtException(excObj.what())
                    }
                    else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
                }
            }
            
            return result
        }
    
    /**
     * Add a task to project.
     */
    fun addTask(task: Task): Unit {
        val kotlin_to_jdk_task = task.getObjId()
        val err = ErrorObj()
        val result = jAddtask(getObjId(), kotlin_to_jdk_task, err)
        if (err.typeId != 0) {
            when (err.typeId) {
                1 -> {
                    val excObj = StdException(err.ptrId)
                    ExceptionHandler.handleUncaughtException(excObj.what())
                }
                else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        
        return result
    }

    /**
     * Get project´s tasks.
     */
    fun tasks(): List<Task> {
        val err = ErrorObj()
        val result = jTasks(getObjId(), err)
        if (err.typeId != 0) {
            when (err.typeId) {
                1 -> {
                    val excObj = StdException(err.ptrId)
                    ExceptionHandler.handleUncaughtException(excObj.what())
                }
                else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
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
    private external fun jTitle(id: Long, __err_obj__: ErrorObj): String
    private external fun jAddtask(id: Long, task: Long, __err_obj__: ErrorObj): Unit
    private external fun jTasks(id: Long, __err_obj__: ErrorObj): LongArray
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}