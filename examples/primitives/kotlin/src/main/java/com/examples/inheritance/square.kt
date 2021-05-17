package com.examples.inheritance

import alias.*


class Square
internal constructor(_id: Long) : IRhombus, IRectangle, AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(side: Double): Long {
            val id = jConstructor(side)
            return id
        }

        @JvmStatic
        private external fun jConstructor(side: Double): Long

    }
    
    protected var id = _id
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(side: Double): this(construct_helper(side)) {
        //jSet_this(id, this)
    }
    
    override val area: Double
        get() {
            val result = jArea(getObjId())
            
            return result
        }
    
    override fun perimeter(): Double {
        val result = jPerimeter(getObjId())
        
        return result
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
    private external fun jArea(id: Long): Double
    private external fun jPerimeter(id: Long): Double
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}