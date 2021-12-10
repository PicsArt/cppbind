/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-13:05.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.exception_helpers.*
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*


interface IRhombusFigure : IParallelogram {
    
    
}



open class RhombusFigureImpl
internal constructor(_id: Long) : IRhombusFigure {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(diagonal1: Double, diagonal2: Double): Long {
            val id = jConstructor(diagonal1, diagonal2)
            return id
        }

        @JvmStatic
        private external fun jConstructor(diagonal1: Double, diagonal2: Double): Long
    }

    protected var objId = _id
    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(diagonal1: Double, diagonal2: Double): this(construct_helper(diagonal1, diagonal2)) {
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
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
    }
    
    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
}