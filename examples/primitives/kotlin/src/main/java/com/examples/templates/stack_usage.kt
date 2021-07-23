/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/22/2021-12:38.
 * Please do not change it manually.
 */

package com.examples.templates

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*import com.examples.simple.Project

open class StackUsage
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
    
    constructor(): this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    fun firstItemOfSpecializedStack(p: StackProject): Project {
        val kotlin_to_jdk_p = p.getObjId()
        val err = ErrorObj()
        val result = jFirstitemofspecializedstack(getObjId(), kotlin_to_jdk_p, err)
        if (err.typeId != 0) {
            when (err.typeId) {
                1 -> {
                    val excObj = StdException(err.ptrId)
                    ExceptionHandler.handleUncaughtException(excObj.what())
                }
                else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        val jdk_to_kotlin_result = Project(result)
        return jdk_to_kotlin_result
    }

    open fun firstItemOfTemplateStack(arg0: StackProject): Project {
        val kotlin_to_jdk_arg0 = arg0.getObjId()
        val err = ErrorObj()
        val result = jFirstitemoftemplatestackProject(getObjId(), kotlin_to_jdk_arg0, err)
        if (err.typeId != 0) {
            when (err.typeId) {
                1 -> {
                    val excObj = StdException(err.ptrId)
                    ExceptionHandler.handleUncaughtException(excObj.what())
                }
                else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        val jdk_to_kotlin_result = Project(result)
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
    private external fun jFirstitemofspecializedstack(id: Long, p: Long, __err_obj__: ErrorObj): Long
    private external fun jFirstitemoftemplatestackProject(id: Long, arg0: Long, __err_obj__: ErrorObj): Long
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}