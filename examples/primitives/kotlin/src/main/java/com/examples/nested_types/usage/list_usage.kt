/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/04/2022-11:09.
 * Please do not change it manually.
 */

package com.examples.nested_types.usage

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*
import com.examples.nested_types.List

/**
 * A dummy test example using nested types.
 */
open class ListWrapper
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(construct_helper(), true) {
    }
    
    val back: List.Item
        get() {
            val result = jBack(id)
            val jdktokotlinresult = List.Item(result)
            return jdktokotlinresult
        }
    
    fun push_back(item: List.Item): Unit {
        val kotlintojdkitem = item.id
        val result = jPush_back(id, kotlintojdkitem)
        
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
    private external fun jPush_back(id: Long, item: Long): Unit
    private external fun jBack(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}