package com.examples.inheritance

import alias.*


interface IParallelogram {
    fun getObjId(): Long
    
    open val area: Double
        get() {
            val result = ParallelogramHelper.jArea(getObjId())
            
            return result
        }
    
    open fun perimeter(): Double {
        val result = ParallelogramHelper.jPerimeter(getObjId())
        
        return result
    }
}

class ParallelogramHelper {
    companion object {
        
        @JvmStatic
        external fun jArea(id: Long): Double

        @JvmStatic
        external fun jPerimeter(id: Long): Double
    }
}

open class Parallelogram
internal constructor(_id: Long) : IParallelogram, AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
    }

    protected var id = _id
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
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