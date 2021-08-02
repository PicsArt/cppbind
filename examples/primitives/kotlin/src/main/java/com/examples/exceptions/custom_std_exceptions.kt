/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/30/2021-08:58.
 * Please do not change it manually.
 */

package com.examples.exceptions

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*

open class SystemError
internal constructor(_id: Long) : StdException(_id) {
    companion object {
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(message: String): Long {
            val id = jConstructor(message)
            return id
        }

        @JvmStatic
        private external fun jConstructor(message: String): Long
    }
    
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    /**
     * comments
     * 
     */
    constructor(message: String): this(construct_helper(message)) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    open override fun what(): String {
        val result = jWhat(getObjId())
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jWhat(id: Long): String
}

open class FileError
internal constructor(_id: Long) : SystemError(_id) {
    companion object {
        
        protected fun construct_helper(message: String): Long {
            val id = jConstructor(message)
            return id
        }

        @JvmStatic
        private external fun jConstructor(message: String): Long
    }
    
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(message: String): this(construct_helper(message)) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    open override fun what(): String {
        val result = jWhat(getObjId())
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jWhat(id: Long): String
}