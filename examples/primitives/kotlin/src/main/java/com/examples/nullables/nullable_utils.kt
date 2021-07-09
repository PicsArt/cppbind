/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/02/2021-08:55.
 * Please do not change it manually.
 */

package com.examples.nullables

import alias.*
import com.examples.simple.Task

open class NumberInt
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(val_: Int): Long {
            val id = jConstructor(val_)
            return id
        }

        @JvmStatic
        private external fun jConstructor(val_: Int): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(val_: Int): this(construct_helper(val_)) {
        //jSet_this(id, this)
    }
    
    val value: Int
        get() {
            val result = jValue(getObjId())
            
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
    private external fun jValue(id: Long): Int
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}

open class NumberDouble
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(val_: Double): Long {
            val id = jConstructor(val_)
            return id
        }

        @JvmStatic
        private external fun jConstructor(val_: Double): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(val_: Double): this(construct_helper(val_)) {
        //jSet_this(id, this)
    }
    
    val value: Double
        get() {
            val result = jValue(getObjId())
            
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
    private external fun jValue(id: Long): Double
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}

/**
 * An example with nullable arguments.
 */
open class Utils
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        protected fun construct_helper(num: NumberDouble?): Long {val kotlin_to_jdk_num = num?.getObjId() ?: 0L
            val id = jConstructor(kotlin_to_jdk_num)
            return id
        }

        @JvmStatic
        private external fun jConstructor(num: Long): Long

        fun max(first: NumberDouble?, second: NumberDouble): NumberDouble? {
            val kotlin_to_jdk_first = first?.getObjId() ?: 0L
            val kotlin_to_jdk_second = second.getObjId()
            val result = jMax(kotlin_to_jdk_first, kotlin_to_jdk_second)
            val jdk_to_kotlin_result = if (result == 0L) null else NumberDouble(result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jMax(first: Long, second: Long): Long

        fun max(first: NumberInt?, second: NumberInt?): NumberInt? {
            val kotlin_to_jdk_first = first?.getObjId() ?: 0L
            val kotlin_to_jdk_second = second?.getObjId() ?: 0L
            val result = jMax_1(kotlin_to_jdk_first, kotlin_to_jdk_second)
            val jdk_to_kotlin_result = if (result == 0L) null else NumberInt(result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jMax_1(first: Long, second: Long): Long

        fun checkNonnullArg(number: NumberDouble): Unit {
            val kotlin_to_jdk_number = number.getObjId()
            val result = jChecknonnullarg(kotlin_to_jdk_number)
            
            return result
        }
        @JvmStatic
        private external fun jChecknonnullarg(number: Long): Unit

        fun checkNonnullReturn(): NumberDouble {
            val result = jChecknonnullreturn()
            val jdk_to_kotlin_result = NumberDouble(result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jChecknonnullreturn(): Long
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
    }
    
    constructor(num: NumberDouble?): this(construct_helper(num)) {
        //jSet_this(id, this)
    }
    
    var nullable: NumberDouble?
        get() {
            val result = jNullable(getObjId())
            val jdk_to_kotlin_result = if (result == 0L) null else NumberDouble(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value?.getObjId() ?: 0L
            jSetnullable(getObjId(), kotlin_to_jdk_value)
        }

    var nonNull: NumberDouble
        get() {
            val result = jNonnull(getObjId())
            val jdk_to_kotlin_result = NumberDouble(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value.getObjId()
            jSetnonnull(getObjId(), kotlin_to_jdk_value)
        }

    var numDouble: NumberDouble?
        get() {
            val result = jNumdouble(getObjId())
            val jdk_to_kotlin_result = if (result == 0L) null else NumberDouble(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value?.getObjId() ?: 0L
            jSetnumdouble(getObjId(), kotlin_to_jdk_value)
        }
        

    var numInt: NumberInt
        get() {
            val result = jNumint(getObjId())
            val jdk_to_kotlin_result = NumberInt(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value.getObjId()
            jSetnumint(getObjId(), kotlin_to_jdk_value)
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
    



    private external fun jNullable(id: Long): Long
    private external fun jSetnullable(id: Long, value: Long): Unit
    private external fun jNonnull(id: Long): Long
    private external fun jSetnonnull(id: Long, value: Long): Unit
    private external fun jNumdouble(id: Long): Long
    private external fun jSetnumdouble(id: Long, value: Long): Unit
    private external fun jNumint(id: Long): Long
    private external fun jSetnumint(id: Long, value: Long): Unit
    private external fun jSet_this(id: Long, self: Any): Unit
    private external fun jFinalize(id: Long): Unit
}