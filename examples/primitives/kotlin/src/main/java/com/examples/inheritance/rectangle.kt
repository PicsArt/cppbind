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


interface IRectangle : IParallelogram {
    
    open override val area: Double
        get() {
            val result = IRectangleHelper.jArea(id)
            
            return result
        }

    val length: Double
        get() {
            val result = IRectangleHelper.jLength(id)
            
            return result
        }

    val width: Double
        get() {
            val result = IRectangleHelper.jWidth(id)
            
            return result
        }
    
}


class IRectangleHelper {
    companion object {
        @JvmStatic
        external fun jArea(id: Long): Double
        @JvmStatic
        external fun jLength(id: Long): Double
        @JvmStatic
        external fun jWidth(id: Long): Double
    }
}


open class RectangleImpl
internal constructor(obj : IEGenObject) : IRectangle {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(length: Double, width: Double): Long {
            val id = jConstructor(length, width)
            return id
        }

        @JvmStatic
        private external fun jConstructor(length: Double, width: Double): Long
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
    
    constructor(length: Double, width: Double): this(IEGenObject(construct_helper(length, width), true)) {
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
