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

package com.examples.exceptions

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class SimpleBaseException
internal constructor(obj: IEGenObject) : AutoCloseable, Exception() {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(err_num: Int): Long {
            val id = jConstructor(err_num)
            return id
        }

        @JvmStatic
        private external fun jConstructor(err_num: Int): Long
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
    
    constructor(err_num: Int): this(IEGenObject(construct_helper(err_num), true)) {
    }
    
    open fun errNum(): Int {
        val result = jErrnum(id)
        
        return result
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
    private external fun jErrnum(id: Long): Int
    private external fun jFinalize(id: Long): Unit
}

open class SimpleChildException
internal constructor(obj: IEGenObject) : SimpleBaseException(obj) {
    companion object {
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(err_num: Int): Long {
            val id = jConstructor(err_num)
            return id
        }

        @JvmStatic
        private external fun jConstructor(err_num: Int): Long
    }
    
    
    /**
     * comments
     * 
     */
    constructor(err_num: Int): this(IEGenObject(construct_helper(err_num), true)) {
    }
    
    /**
     * comments
     * 
     */
    open override fun errNum(): Int {
        val result = jErrnum(id)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jErrnum(id: Long): Int
}

private external fun jGettypebyid(id: Long): String
