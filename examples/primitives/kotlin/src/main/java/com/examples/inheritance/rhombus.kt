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

package com.examples.inheritance

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*


interface IRhombusFigure : IParallelogram {
    
    
}



open class RhombusFigureImpl
internal constructor(obj : IEGenObject) : IRhombusFigure {
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

    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(diagonal1: Double, diagonal2: Double): this(IEGenObject(construct_helper(diagonal1, diagonal2), true)) {
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

private external fun jGettypebyid(id: Long): String
