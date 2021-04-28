package com.examples.inheritance

import alias.*


/**
 * 
 */
interface IRhombus : IParallelogram {
    
    
}

class RhombusHelper {
    companion object {
        
    }
}
open class Rhombus
internal constructor(_id: Long) : IRhombus, AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        /**
         * 
         */
        protected fun construct_helper(diagonal1: Double, diagonal2: Double): Long {
            
            
            
            val id = jConstructor(diagonal1, diagonal2)
            return id
        }
        @JvmStatic
        private external fun jConstructor(diagonal1: Double, diagonal2: Double): Long
    }
    protected var id = _id
    override fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * 
     */
    constructor(diagonal1: Double, diagonal2: Double) : this(construct_helper(diagonal1, diagonal2)) {
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
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}