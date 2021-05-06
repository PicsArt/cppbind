package com.examples.simple

import alias.*


/**
 * comments
 * 
 */
open class Root
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(_path: String): Long {
            val id = jConstructor(_path)
            return id
        }

        @JvmStatic
        private external fun jConstructor(_path: String): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    /**
     * comments
     * 
     */
    constructor(_path: String) : this(construct_helper(_path)) {
        //jSet_this(id, this)
    }
    
    /**
     * comments
     * 
     */
    val path: String
        get() {
            val result = jPath(getObjId())
            
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
    private external fun jPath(id: Long): String
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}