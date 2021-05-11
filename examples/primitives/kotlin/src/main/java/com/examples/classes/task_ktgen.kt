package com.examples.classes

import alias.*



/**
 * comments
 * 
 */
open class Task
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(title: String): Long {
            
            
            val id = jConstructor(title)
            return id
        }
        @JvmStatic
        private external fun jConstructor(title: String): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * comments
     * 
     */
    constructor(title: String): this(construct_helper(title)) {
      //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    val title: String
          get() {
            val result = jTitle(getObjId())
            
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
    private external fun jTitle(id: Long): String
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}