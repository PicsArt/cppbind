/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/14/2022-11:59.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*


interface ITime : IBase {
    
    val time: String
        get() {
            val result = ITimeHelper.jTime(id)
            
            return result
        }
    
    open override fun value(): String {
        val result = ITimeHelper.jValue(id)
        
        return result
    }
}


class ITimeHelper {
    companion object {
        @JvmStatic
        external fun jValue(id: Long): String
        @JvmStatic
        external fun jTime(id: Long): String
    }
}


open class TimeImpl
internal constructor(_id: Long, _owner: Boolean = false) : ITime {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(h: Int, m: Int, s: Int): Long {
            val id = jConstructor(h, m, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(h: Int, m: Int, s: Int): Long
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
    
    constructor(h: Int, m: Int, s: Int): this(construct_helper(h, m, s), true) {
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

open class DateTime
internal constructor(_id: Long, _owner: Boolean = false) : ITime, Date(_id, _owner) {
    companion object {
        
        protected fun construct_helper(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int): Long {
            val id = jConstructor(d, mo, y, h, mi, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int): Long
    }
    
    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(d: Int, mo: Int, y: Int, h: Int, mi: Int, s: Int): this(construct_helper(d, mo, y, h, mi, s), true) {
    }
    
    val datetime: String
        get() {
            val result = jDatetime(id)
            
            return result
        }
    
    open override fun value(): String {
        val result = jValue(id)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): String
    private external fun jDatetime(id: Long): String
}
