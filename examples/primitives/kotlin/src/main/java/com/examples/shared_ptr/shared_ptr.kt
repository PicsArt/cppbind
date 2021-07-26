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

package com.examples.shared_ptr

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*

/**
 * comments
 * 
 */
open class Car
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(cost: Int): Long {
            val id = jConstructor(cost)
            return id
        }

        @JvmStatic
        private external fun jConstructor(cost: Int): Long
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
    constructor(cost: Int): this(construct_helper(cost)) {
        //jSet_this(id, this)
    }
    
    /**
     * value getter
     */
    val cost: Int
        get() {
            val err = ErrorObj()
            val result = jCost(getObjId(), err)
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
     * comments
     * 
     */
    fun setCostWithCarSharedPtr(sp: Car): Unit {
        val kotlin_to_jdk_sp = sp.getObjId()
        val err = ErrorObj()
        val result = jSetcostwithcarsharedptr(getObjId(), kotlin_to_jdk_sp, err)
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
     * comments
     * 
     */
    fun getNewCarSharedPtr(): Car {
        val err = ErrorObj()
        val result = jGetnewcarsharedptr(getObjId(), err)
        if (err.typeId != 0) {
            when (err.typeId) {
                1 -> {
                    val excObj = StdException(err.ptrId)
                    ExceptionHandler.handleUncaughtException(excObj.what())
                }
                else -> ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        val jdk_to_kotlin_result = Car(result)
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
    private external fun jCost(id: Long, __err_obj__: ErrorObj): Int
    private external fun jSetcostwithcarsharedptr(id: Long, sp: Long, __err_obj__: ErrorObj): Unit
    private external fun jGetnewcarsharedptr(id: Long, __err_obj__: ErrorObj): Long
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}