package com.examples.misc

open class BufferInt
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        /**
         * comments
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
     * comments
     *
     */
    constructor(): this(construct_helper()) {
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
