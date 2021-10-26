/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/26/2021-07:50.
 * Please do not change it manually.
 */

package com.examples.simple

import alias.*
import com.examples.exception_helpers.*
import exceptionUtils.*

open class Path
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(_value: String): Long {
            val id = jConstructor(_value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(_value: String): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId;
        }
    
    constructor(_value: String): this(construct_helper(_value)) {
    }
    
    val value: String
        get() {
            val result = jValue(id)
            
            return result
        }
    
    override fun toString(): String {
        val result = jTostring(id)
        
        return result
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
    private external fun jTostring(id: Long): String
    private external fun jValue(id: Long): String
    private external fun jFinalize(id: Long): Unit
}