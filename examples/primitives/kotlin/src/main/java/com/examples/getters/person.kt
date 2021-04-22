package com.examples.getters

import alias.*



/**
 * This class contains a private string field and getter/setter methods for it.
 */
open class Person
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(name: String): Long {
            
            
            val id = jConstructor(name)
            return id
        }
        @JvmStatic
        private external fun jConstructor(name: String): Long
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
    constructor(name: String): this(construct_helper(name)) {
      //jSet_this(id, this)
    }
    
    /**
     * fullname getter
     */
    var fullName: String
          get() {
            val result = jFullname(getObjId())
            
            return result
          }
          
          
          set(value) {
            
            jSetfullname(getObjId(), value)
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
    private external fun jFullname(id: Long): String
    private external fun jSetfullname(id: Long, value : String): Void
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}