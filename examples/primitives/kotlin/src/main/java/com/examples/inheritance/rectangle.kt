package com.examples.inheritance

import alias.*


interface IRectangle : IParallelogram {
    
    open override val area: Double
        get() {
            val result = RectangleHelper.jArea(getObjId())
            
            return result
        }

    val length: Double
        get() {
            val result = RectangleHelper.jLength(getObjId())
            
            return result
        }

    val width: Double
        get() {
            val result = RectangleHelper.jWidth(getObjId())
            
            return result
        }
    
    open override fun perimeter(): Double {
        val result = RectangleHelper.jPerimeter(getObjId())
        
        return result
    }
}

class RectangleHelper {
    companion object {
        
        @JvmStatic
        external fun jArea(id: Long): Double
        @JvmStatic
        external fun jPerimeter(id: Long): Double

        @JvmStatic
        external fun jLength(id: Long): Double

        @JvmStatic
        external fun jWidth(id: Long): Double
    }
}

open class Rectangle
internal constructor(_id: Long) : IRectangle, AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(length: Double, width: Double): Long {
            val id = jConstructor(length, width)
            return id
        }

        @JvmStatic
        private external fun jConstructor(length: Double, width: Double): Long

    }

    protected var id = _id
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(length: Double, width: Double): this(construct_helper(length, width)) {
        //jSet_this(id, this)
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
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}