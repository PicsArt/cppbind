/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/24/2022-12:47.
 * Please do not change it manually.
 */

package com.examples.misc

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*
import java.awt.geom.Point2D

/**
 * comments
 * 
 */
open class SizeUsage
internal constructor(obj: IEGenObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * comments
         * 
         */
        fun multiplyBy(size: Point2D.Float, n: Int): Point2D.Float {
            val width_size = size.getX().toFloat()
            val height_size = size.getY().toFloat()
            val kotlintojdksize = FloatArray(2)
            kotlintojdksize.set(0, width_size)
            kotlintojdksize.set(1, height_size)
            val result = jMultiplyby(kotlintojdksize, n)
            val width_result = result[0]
            val height_result = result[1]
            val jdktokotlinresult = Point2D.Float(width_result, height_result)
            return jdktokotlinresult
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
            val kotlintojdkresolution = FloatArray(2)
            kotlintojdkresolution.set(0, width_resolution)
            kotlintojdkresolution.set(1, height_resolution)
            val result = jDoublesizef(kotlintojdkresolution)
            val width_result = result[0]
            val height_result = result[1]
            val jdktokotlinresult = Point2D.Float(width_result, height_result)
            return jdktokotlinresult
        }
        @JvmStatic
        private external fun jDoublesizef(resolution: FloatArray): FloatArray
    }
    
    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }

    override fun close() {
        if (owner && objId != 0L) {
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
    private external fun jFinalize(id: Long): Unit
}

/**
 * comments
 * 
 */
open class BufferUsage
internal constructor(obj: IEGenObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(): this(IEGenObject(construct_helper(), true)) {
    }
    
    fun usage1(b: BufferInt): String {
        val kotlintojdkb = b.getObjId()
        val result = jUsage1(id, kotlintojdkb)
        
        return result
    }

    fun usage2(): BufferInt {
        val result = jUsage2(id)
        val jdktokotlinresult = BufferInt(result)
        return jdktokotlinresult
    }

    override fun close() {
        if (owner && objId != 0L) {
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
    private external fun jUsage1(id: Long, b: Long): String
    private external fun jUsage2(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
