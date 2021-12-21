/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:28.
 * Please do not change it manually.
 */

package com.examples.templates

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

/**
 * comments
 * 
 */
open class WrapperPairStrings
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: Pair<String, String>): Long {val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<String, String>(first_value, second_value)
            val id = jConstructor(kotlintojdkvalue)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: Pair<String, String>): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(value: Pair<String, String>): this(construct_helper(value)) {
    }
    
    var value: Pair<String, String>
        get() {
            val result = jValue(id)
            val first_result = result.first
            val second_result = result.second


            val jdktokotlinresult = Pair<String, String>(first_result, second_result)
            return jdktokotlinresult
        }
        set(value) {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<String, String>(first_value, second_value)
            jSetvalue(id, kotlintojdkvalue)
        }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): Pair<String, String>
    private external fun jSetvalue(id: Long, value: Pair<String, String>): Unit
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class WrapperPairIntInt
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: Pair<Int, Int>): Long {val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<Int, Int>(first_value, second_value)
            val id = jConstructor(kotlintojdkvalue)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: Pair<Int, Int>): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(value: Pair<Int, Int>): this(construct_helper(value)) {
    }
    
    var value: Pair<Int, Int>
        get() {
            val result = jValue(id)
            val first_result = result.first
            val second_result = result.second


            val jdktokotlinresult = Pair<Int, Int>(first_result, second_result)
            return jdktokotlinresult
        }
        set(value) {
            val first_value = value.first
            val second_value = value.second


            val kotlintojdkvalue = Pair<Int, Int>(first_value, second_value)
            jSetvalue(id, kotlintojdkvalue)
        }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): Pair<Int, Int>
    private external fun jSetvalue(id: Long, value: Pair<Int, Int>): Unit
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class WrapperString
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(value: String): Long {
            val id = jConstructor(value)
            return id
        }

        @JvmStatic
        private external fun jConstructor(value: String): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(value: String): this(construct_helper(value)) {
    }
    
    var value: String
        get() {
            val result = jValue(id)
            
            return result
        }
        set(value) {
            
            jSetvalue(id, value)
        }

    override fun close() {
        if (objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        // temporary fix until kotlin ownership will be supported
        // github issues:
        // https://github.com/PicsArt/iegen/issues/349
        // https://github.com/PicsArt/iegen/issues/348
        // close()
    }

    ///// External wrapper functions ////////////
    private external fun jValue(id: Long): String
    private external fun jSetvalue(id: Long, value: String): Unit
    private external fun jFinalize(id: Long): Unit
}