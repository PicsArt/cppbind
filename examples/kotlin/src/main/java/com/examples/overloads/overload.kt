package com.examples.overloads

import alias.*



/**
 * An example for with overloaded methods.
 */
open class OverloadedFunctions
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * Overload constructor
         * 
         */
        protected fun construct_helper(): Long {
            
            val id = jConstructor()
            return id
        }
        @JvmStatic
        private external fun jConstructor(): Long


    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * Overload constructor
     * 
     */
    constructor(): this(construct_helper()) {
      //jSet_this(id, this)
    }
    
    
    /**
     * Concatenate with two strings.
     * 
     */
    fun concatenate(first: String, second: String): String {
        
        
        
        val result = jConcatenate(getObjId(), first, second)
        
        return result
    }

    /**
     * Concatenate with three strings.
     * 
     */
    fun concatenate(first: String, second: String, third: String): String {
        
        
        
        
        val result = jConcatenate_1(getObjId(), first, second, third)
        
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
    private external fun jConcatenate(id: Long, first: String, second: String): String
    private external fun jConcatenate_1(id: Long, first: String, second: String, third: String): String
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}