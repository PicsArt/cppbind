package com.picsart.example_lib.utils

import alias.*



/**
 * comments
 * 
 */
open class Example
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
         * 
         */
        protected fun construct_helper(x: Int, name: String): Long {
            
            
            
            val id = jConstructor(x, name)
            return id
        }
        @JvmStatic
        private external fun jConstructor(x: Int, name: String): Long


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
    constructor(x: Int, name: String): this(construct_helper(x, name)) {
      //jSet_this(id, this)
    }
    
    
    enum class Type(val value: Int){
      A(0),
      B(1),
      C(2);

      companion object {
        private val values = values();
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
      }
    }

    /**
     * comments
     * 
     */
    fun f(t: Type, i: Int, test: String): Type {
        
        val kotlin_to_jdk_t = t.value
        
        
        val result = jF(getObjId(), kotlin_to_jdk_t, i, test)
        val jdk_to_kotlin_result = Type.getByValue(result)!!
        return jdk_to_kotlin_result
    }

    /**
     * comments
     * 
     */
    fun get_attribute(test: String): Int {
        
        
        val result = jGet_attribute(getObjId(), test)
        
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
    private external fun jF(id: Long, t: Int, i: Int, test: String): Int
    private external fun jGet_attribute(id: Long, test: String): Int
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}