/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.exception_helpers.*
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*

open class GeometricFigure
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(p: IParallelogram): Long {val kotlin_to_jdk_p = p.id
            val id = jConstructor(kotlin_to_jdk_p)
            return id
        }

        @JvmStatic
        private external fun jConstructor(p: Long): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(p: IParallelogram): this(construct_helper(p)) {
    }
    
    var parallelogram: IParallelogram
        get() {
            val result = jParallelogram(id)
            val jdk_to_kotlin_result = ParallelogramImpl(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value.id
            jSetparallelogram(id, kotlin_to_jdk_value)
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
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jParallelogram(id: Long): Long
    private external fun jSetparallelogram(id: Long, value: Long): Unit
    private external fun jFinalize(id: Long): Unit
}

open class MyVehicle
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(v: Vehicle): Long {val kotlin_to_jdk_v = v.id
            val id = jConstructor(kotlin_to_jdk_v)
            return id
        }

        @JvmStatic
        private external fun jConstructor(v: Long): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(v: Vehicle): this(construct_helper(v)) {
    }
    
    var vehicle: Vehicle
        get() {
            val result = jVehicle(id)
            val jdk_to_kotlin_result = Vehicle(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value.id
            jSetvehicle(id, kotlin_to_jdk_value)
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
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jVehicle(id: Long): Long
    private external fun jSetvehicle(id: Long, value: Long): Unit
    private external fun jFinalize(id: Long): Unit
}

open class MyBicycle
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(b: Bicycle): Long {val kotlin_to_jdk_b = b.id
            val id = jConstructor(kotlin_to_jdk_b)
            return id
        }

        @JvmStatic
        private external fun jConstructor(b: Long): Long
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(b: Bicycle): this(construct_helper(b)) {
    }
    
    var bicycle: Bicycle
        get() {
            val result = jBicycle(id)
            val jdk_to_kotlin_result = Bicycle(result)
            return jdk_to_kotlin_result
        }
        set(value) {
            val kotlin_to_jdk_value = value.id
            jSetbicycle(id, kotlin_to_jdk_value)
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
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jBicycle(id: Long): Long
    private external fun jSetbicycle(id: Long, value: Long): Unit
    private external fun jFinalize(id: Long): Unit
}