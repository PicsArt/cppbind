package com.examples.overloads

import alias.*



/**
 * An example for with overloaded methods.
 */
open class Utils
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * Concatenate with two strings.
         * 
         */
        fun sum(first: Int, second: Int): Int {
            
            
            
            
            val result = jSum(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jSum(first: Int, second: Int): Int

        /**
         * Concatenate with three strings.
         * 
         */
        fun sum(first: Float, second: Float): Float {
            
            
            
            
            val result = jSum_1(first, second)
            
            return result
        }
        @JvmStatic
        private external fun jSum_1(first: Float, second: Float): Float
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
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