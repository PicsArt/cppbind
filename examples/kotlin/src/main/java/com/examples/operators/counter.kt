package com.examples.operators

import alias.*



/**
 * An example for with overloaded methods.
 * 
 */
open class Counter
    internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
          System.loadLibrary("wrapper_jni");
        }
        /**
         * Counter constructor.
         */
        protected fun construct_helper(count: Int): Long {
            
            
            val id = jConstructor(count)
            return id
        }
        @JvmStatic
        private external fun jConstructor(count: Int): Long




    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if(id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     * Counter constructor.
     */
    constructor(count: Int): this(construct_helper(count)) {
      //jSet_this(id, this)
    }
    
    /**
     * Getter for count.
     */
    val count: Int
          get() {
            val result = jCount(getObjId())
            
            return result
          }
          
    
    /**
     * Plus operator
     */
    operator fun plus(counter: Counter): Counter {
        
        val kotlin_to_jdk_counter = counter.getObjId()
        val result = jPlus(getObjId(), kotlin_to_jdk_counter)
        val jdk_to_kotlin_result = Counter(result)
        return jdk_to_kotlin_result
    }

    /**
     * Comparison operator for kotlin
     */
    operator fun compareTo(counter: Counter): Int {
        
        val kotlin_to_jdk_counter = counter.getObjId()
        val result = jCompareto(getObjId(), kotlin_to_jdk_counter)
        
        return result
    }

    /**
     * 
     */
    fun gt(counter: Counter): Boolean {
        
        val kotlin_to_jdk_counter = counter.getObjId()
        val result = jGt(getObjId(), kotlin_to_jdk_counter)
        
        return result
    }

    /**
     * 
     */
    fun add(counter: Counter): Counter {
        
        val kotlin_to_jdk_counter = counter.getObjId()
        val result = jAdd(getObjId(), kotlin_to_jdk_counter)
        val jdk_to_kotlin_result = Counter(result)
        return jdk_to_kotlin_result
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
    private external fun jCount(id: Long): Int
    private external fun jPlus(id: Long, counter: Long): Long
    private external fun jCompareto(id: Long, counter: Long): Int
    private external fun jGt(id: Long, counter: Long): Boolean
    private external fun jAdd(id: Long, counter: Long): Long
    private external fun jSet_this(id: Long, self: Any): Void
    private external fun jFinalize(id: Long): Void
}