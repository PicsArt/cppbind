/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/23/2021-14:20.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*


interface IBase : AutoCloseable {
    val id: Long
    
    
    open fun value(): String {
        val result = IBaseHelper.jValue(id)
        
        return result
    }
}


class IBaseHelper {
    companion object {
        @JvmStatic
        external fun jValue(id: Long): String
    }
}


open class BaseImpl
internal constructor(_id: Long, _owner: Boolean = false) : IBase {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
    }

    protected var objId = _id
    protected val owner = _owner
    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
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
    private external fun jFinalize(id: Long): Unit
}
