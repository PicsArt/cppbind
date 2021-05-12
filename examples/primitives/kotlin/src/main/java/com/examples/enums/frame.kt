package com.examples.enums

import alias.*



/**
 * 
 */
open class Frame
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        /**
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
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    /**
     */
    constructor(): this(construct_helper()) {
        //jSet_this(id, this)
    }
    
    /**
     */
    var backgroundColor: Color
        get() {
            val result = jBackgroundcolor(getObjId())
            val jdk_to_kotlin_result = Color.getByValue(result)!!
            return jdk_to_kotlin_result
        }
        
        
        set(value) {
            val kotlin_to_jdk_value = value.value
            jSetbackgroundcolor(getObjId(), kotlin_to_jdk_value)
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
    private external fun jBackgroundcolor(id: Long): Int
    private external fun jSetbackgroundcolor(id: Long, value : Int): Unit
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}