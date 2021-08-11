/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 08/09/2021-11:36.
 * Please do not change it manually.
 */

package com.examples.misc

import alias.*
import exceptionUtils.*

import com.examples.exception_helpers.*import java.awt.geom.Point2D

/**
 * comments
 * 
 */
open class SizeUsage
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        /**
         * comments
         * 
         */
        fun multiplyBy(size: Point2D.Float, n: Int): Point2D.Float {
            val width_size = size.getX().toFloat()
            val height_size = size.getY().toFloat()
            val kotlin_to_jdk_size = FloatArray(2)
            kotlin_to_jdk_size.set(0, width_size)
            kotlin_to_jdk_size.set(1, height_size)
            val result = jMultiplyby(kotlin_to_jdk_size, n)
            val width_result = result[0]
            val height_result = result[1]
            val jdk_to_kotlin_result = Point2D.Float(width_result, height_result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jMultiplyby(size: FloatArray, n: Int): FloatArray

        /**
         * comments
         * 
         */
        fun doubleSizeF(resolution: Point2D.Float): Point2D.Float {
            val width_resolution = resolution.getX().toFloat()
            val height_resolution = resolution.getY().toFloat()
            val kotlin_to_jdk_resolution = FloatArray(2)
            kotlin_to_jdk_resolution.set(0, width_resolution)
            kotlin_to_jdk_resolution.set(1, height_resolution)
            val result = jDoublesizef(kotlin_to_jdk_resolution)
            val width_result = result[0]
            val height_result = result[1]
            val jdk_to_kotlin_result = Point2D.Float(width_result, height_result)
            return jdk_to_kotlin_result
        }
        @JvmStatic
        private external fun jDoublesizef(resolution: FloatArray): FloatArray
    }
    
    protected var id = _id
    
    open fun getObjId(): Long {
        if (id == 0L) {
            throw RuntimeException("Object is not allocated")
        }
        return id;
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
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class BufferUsage
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
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
    
    constructor(): this(construct_helper()) {
    }
    
    fun usage1(b: BufferInt): String {
        val kotlin_to_jdk_b = b.getObjId()
        val result = jUsage1(getObjId(), kotlin_to_jdk_b)
        
        return result
    }

    fun usage2(): BufferInt {
        val result = jUsage2(getObjId())
        val jdk_to_kotlin_result = BufferInt(result)
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
    private external fun jUsage1(id: Long, b: Long): String
    private external fun jUsage2(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}